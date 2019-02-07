#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

struct Node {
    int32_t key;    
    string address;
    string next;
};

int main() {
    int32_t n;
    string head;
    cin >> n >> head;
    unordered_map<string, Node> linked_list;
    linked_list.reserve(n);
    for (int32_t i = 0; i < n; ++i) {
        Node node;
        cin >> node.address >> node.key >> node.next;
        linked_list[node.address] = node;
    }
    // 方便计算，加入-1作为尾节点
    linked_list["-1"] = Node{INT32_MAX, "-1", "-1"};
    vector<Node*> nodes;
    nodes.reserve(n + 1);
    // traverse
    string addr = head;
    auto iter = linked_list.find(addr);
    while (iter != end(linked_list) && iter->second.address != "-1") {
        nodes.push_back(&iter->second);
        auto iter_next = linked_list.find(iter->second.next);
        if (iter_next != end(linked_list)) {
            iter = iter_next;
        } else {
            break;
        }
    }
    nodes.push_back(&linked_list["-1"]);
    // vector
    sort(begin(nodes), end(nodes), [] (auto& lhs, auto& rhs) {
        return lhs->key < rhs->key;
    });
    printf("%lu %s\n", nodes.size() - 1, nodes.front()->address.c_str());
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        printf("%s %d %s\n", nodes[i]->address.c_str(), nodes[i]->key, nodes[i + 1]->address.c_str());
    }
}