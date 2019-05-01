#include <unordered_map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Person {
	string id;
	// 如果为 -1，那么就使用 dead 代替，肯定大于四位数所有 id
	string f;
	string m;
	vector<string> children;
	int num;
	int area;
};

struct Root {
	string id;
	int num_people;
	double num, area;
};

int main() {
	int n;
	cin >> n;
	unordered_map<string, int> name_index;
	// 如果人名没有出现过，那么就 push_back
	vector<Person> people(n);
	vector<string> ids;
	auto track_id = [&] (const string& s) {
		auto iter = name_index.find(s);
		if (iter == end(name_index) && s != "-1") {
			ids.push_back(s);
			name_index[s] = ids.size() - 1;
		}
	};
	// 确定有多少人的 id 出现
	// 数据输入以及 id 保存
	for (auto& person: people) {
		cin >> person.id >> person.f >> person.m;
		track_id(person.id);
		track_id(person.f);
		track_id(person.m);
		int k;
		cin >> k;
		person.children = vector<string>(k);
		for (auto& e: person.children) {
			cin >> e;
			track_id(e);
		}
		cin >> person.num >> person.area;
	}
	vector<int> parent(ids.size());
	iota(begin(parent), end(parent), 0);
	function<int(int)> find_root = [&] (int i) {
		int root = parent[i];
		while (root != parent[root]) {
			root = parent[root];
		}
		while (root != parent[i]) {
			int tmp = parent[i];
			parent[i] = root;
			i = tmp;
		}
		return root;
	};
	function<void(int, int)> union_set = [&] (int i, int j) {
		int root_i = find_root(i);
		int root_j = find_root(j);
		if (root_i != root_j) {
			// 一个人自己的 id 和父母的 id
			// 但是还有 child
			if (ids[root_i] < ids[root_j]) {
				parent[root_j] = root_i;
			} else {
				parent[root_i] = root_j;
			}
		}
	};
	// 并查集操作
	for (auto& person: people) {
		if (person.f != "-1") {
			union_set(name_index[person.id], name_index[person.f]);
		}
		if (person.m != "-1") {
			union_set(name_index[person.id], name_index[person.m]);
		}
		for (auto& s: person.children) {
			union_set(name_index[person.id], name_index[s]);
		}
	}
	unordered_map<int, Root> family;
	// 更新人数，root id
	for (int i = 0; i < parent.size(); ++i) {
		int root = find_root(i);
		family[root].id = ids[root];
		family[root].num_people++;
	}
	// 更新资产
	for (auto& person: people) {
		int root = find_root(name_index[person.id]);
		auto iter = family.find(root);
		iter->second.num += person.num;
		iter->second.area += person.area;
	}
	vector<Root*> sorted_root;
	for (auto& entry: family) {
		entry.second.num /= entry.second.num_people;
		entry.second.area /= entry.second.num_people;
		sorted_root.push_back(&(entry.second));
	}
	sort(begin(sorted_root), end(sorted_root), [] (auto l, auto r) {
		if (l->area != r->area) {
			return l->area > r->area;
		} else {
			return l->id < r->id;
		}
	});
	cout << family.size() << "\n";
	for (auto p: sorted_root) {
		printf("%s %d %.3f %.3f\n", p->id.c_str(), p->num_people, p->num, p->area);
	}
}