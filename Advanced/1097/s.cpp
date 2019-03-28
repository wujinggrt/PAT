#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

struct Node {
    string addr;
    int val;
    string next;
};

int main() {
    string start;
    int n;
    cin >> start >> n;
    unordered_map<string, Node> addr_node;
    addr_node["-1"] = Node{"-1", 0, "-1"};
    for (int i = 0; i < n; ++i) {
        Node node;
        cin >> node.addr >> node.val >> node .next;
        addr_node[node.addr] = node;
    }
    unordered_set<int> records;
    string cur = start;
    string remove_head = "-1";
    string remove_rear = "-1";
    vector<string> retain;
    retain.push_back(start);
    vector<string> remove_node;
    int i = 0;
    for (; i < n; ++i) {
        if (cur != "-1") {
            auto next = addr_node[cur].next;
            records.insert(abs(addr_node[cur].val)); // 添加当前的 node 的值

            auto absolute = abs(addr_node[next].val); // 绝对值
            auto iter = records.find(absolute);

            // 如果下一个是重复的，跳过，知道遇到不重复的
            while (iter != end(records) && next != "-1") {
                // 更改当前的 next
                addr_node[cur].next = addr_node[next].next;
                remove_node.push_back(next);
                next = addr_node[next].next;
                
                absolute = abs(addr_node[next].val);
                iter = records.find(absolute);
            }
            cout << addr_node[cur].addr << " " << addr_node[cur].val << " " << addr_node[cur].next << "\n";
            cur = next;
        } else {
            break;
        }
    }
    for (int i = 1; i < remove_node.size(); ++i) {
        auto addr = remove_node[i - 1];
        auto addr_next = remove_node[i];
        cout << addr << " " << addr_node[addr].val << " " << addr_next << "\n";
    }
    if (!remove_node.empty()) {
        cout << remove_node.back() << " " << addr_node[remove_node.back()].val << " -1\n";
    }
}