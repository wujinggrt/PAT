#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>
using namespace std;

struct Node {
    int32_t id;
    int32_t weight;
    vector<shared_ptr<Node>> children;

    explicit Node(int32_t _id = 0, int32_t _weight = 0) : id(_id), weight(_weight) {
    }
};

int main(){
    int32_t n;
    int32_t m;
    int32_t s;
    cin >> n >> m >> s;
    vector<shared_ptr<Node>> nodes(n);
    for (int32_t id = 0; id < n; ++id) {
        int32_t weight;
        cin >> weight;
        nodes[id] = make_shared<Node>(id, weight);
    }
    for (int32_t i = 0; i < m; ++i) {
        int32_t id;
        int32_t children_count;
        cin >> id >> children_count;
        for (int32_t j = 0; j < children_count; ++j) {
            int32_t child;
            cin >> child;
            nodes[id]->children.push_back(nodes[child]);
        }
    }
    auto root = nodes.front();
    nodes.clear();
    nodes.shrink_to_fit();
    vector<vector<int32_t>> track;
    vector<int32_t> tmp_track;

    function<void(Node*, int)> dfs = [&](Node* node, int total_weight) {
        if (node == nullptr) {
            return;
        }
        int32_t tmp_weight = total_weight + node->weight;
        tmp_track.push_back(node->weight);
        // 如果大于，那就不要在dfs下去了，剪枝
        // 注意是要到leaf。
        if (tmp_weight == s && node->children.empty())  {
            track.push_back(tmp_track);
            tmp_track.pop_back();
            return ;
        } else if (tmp_weight > s) {
            tmp_track.pop_back();
            return ;
        }
        for (const auto& child: node->children) {
            dfs(child.get(), tmp_weight);
        }
        tmp_track.pop_back();
    };
    
    dfs(root.get(), 0);
    sort(begin(track), end(track), greater<vector<int32_t>>());
    for (const auto& t: track) {
        bool first = true;
        for (const auto& e: t) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << e;
        }
        cout << "\n";
    }
}