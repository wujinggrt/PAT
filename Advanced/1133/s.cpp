#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    string addr;
    int val;
    string next;
};

int main() {
    unordered_map<string, Node> nodes;
    string start;
    int n, k;
    cin >> start >> n >> k;
    for (; n-- != 0; ) {
        Node node;
        cin >> node.addr >> node.val >> node.next;
        nodes[node.addr] = node;
    }
    vector<string> negative;
    vector<string> normal;
    vector<string> greater_k;
    for (string cur = start; cur != "-1"; cur = nodes[cur].next) {
        if (nodes[cur].val < 0) {
            negative.push_back(cur);
        } else if (nodes[cur].val <= k) {
            normal.push_back(cur);
        } else {
            greater_k.push_back(cur);
        }
    }
    // cout << negative.front() << " " << nodes[negative.front()].val << " ";
    // for_each(begin(negative) + 1, end(negative), [&] (const string& s) {
    //     cout << s << "\n" << s << " " << nodes[s].val << " ";
    // });
    bool first = true;
    for (const auto& s: negative) {
        if (first) {
            first = false;
        } else {
            cout << s << "\n";
        }
        cout << s << " " << nodes[s].val << " ";
    }
    for (const auto& s: normal) {
        if (first) {
            first = false;
        } else {
            cout << s << "\n";
        }
        cout << s << " " << nodes[s].val << " ";
    }
    for (const auto& s: greater_k) {
        if (first) {
            first = false;
        } else {
            cout << s << "\n";
        }
        cout << s << " " << nodes[s].val << " ";
    }
    cout << -1 << endl;
}

