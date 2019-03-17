#include <cstdio>

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Node {
    string address;
    int data;
    string next;
};

int main() {
    string head;
    int n;
    int k;
    cin >> head >> n >> k;
    unordered_map<string, Node> storage;
    for (int i = 0; i < n; ++i) {
        Node node;
        cin >> node.address >> node.data >> node.next;
        storage[node.address] = node;
    }
    vector<decltype(storage)::iterator> nodeIters;
    for (string pos = head; pos != "-1"s;) {
        auto iter = storage.find(pos);
        if (iter == end(storage)) {
            break;
        }
        nodeIters.push_back(iter);
        pos = iter->second.next;
    }
    for (int offset = 0; offset + k <= nodeIters.size(); offset += k) {
        // 这个第k段的最后一个，指向下一个k段的开端
        // int segmentTail = offset + k - 1;
        // string prev = nodeIters[segmentTail]->second.next;
        // string next;
        // reverse
        // for (int i = offset; i <= segmentTail; ++i) {
        //     // 保存下一个的下一个node地址
        //     next = nodeIters[i]->second.next;
        //     // 开始翻转
        //     nodeIters[i]->second.next = prev;
        //     prev = nodeIters[i]->second.address;
        //     // 下一个不用了，到尾了
        //     if (next == "-1"s) {
        //         break;
        //     }
        // }
        reverse(begin(nodeIters) + offset, begin(nodeIters) + offset + k);
    }
    for (int i = 0; i < nodeIters.size() - 1; ++i) {
        printf("%s %d %s\n", nodeIters[i]->second.address.c_str(), nodeIters[i]->second.data, nodeIters[i + 1]->second.address.c_str());
    }
    printf("%s %d %s\n", nodeIters.back()->second.address.c_str(), nodeIters.back()->second.data, "-1");
    // for (int offset = 0; offset < nodeIters.size(); offset += k) {
    //     int segmentTail = offset + k - 1;
    //     // 到达最后没有翻转的一段，顺序执行
    //     if (segmentTail < nodeIters.size()) {
    //         for (int i = segmentTail; i >= offset; --i) {
    //             printf("%s %d %s\n", nodeIters[i]->second.address.c_str(), nodeIters[i]->second.data, nodeIters[i]->second.next.c_str());
    //         }
    //     } else {
    //         // output the remainder part.
    //         for (int i = offset; i < nodeIters.size(); ++i) {
    //             printf("%s %d %s\n", nodeIters[i]->second.address.c_str(), nodeIters[i]->second.data, nodeIters[i]->second.next.c_str());
    //         }
    //     }
    // }
}