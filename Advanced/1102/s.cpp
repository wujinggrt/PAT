#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

struct Node {
    int parent = -1;
    // -1 代表没有 child
    int left;
    int right;
};

int main() {
    int n;
    cin >> n;
    vector<Node> record(n);
    for (int i = 0; i < n; ++i) {
        string left;
        string right;
        cin >> left >> right;
        if (left != "-") {
            int left_index = stoi(left);
            record[i].left = left_index;
            record[left_index].parent = i;
        } else {
            record[i].left = -1;
        }
        if (right != "-") {
            int right_index = stoi(right);
            record[i].right = right_index;
            record[right_index].parent = i;
        } else {
            record[i].right = -1;
        }
    }
    // 找到parent
    int root = find_if(begin(record), end(record), [] (auto& e) {
        return e.parent == -1;
    }) - begin(record);
    bool first = true;
    function<void(int)> level = [&] (int root) {
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << node;
            q.pop();
            if (record[node].right != -1) {
                q.push(record[node].right);
            }
            if (record[node].left != -1) {
                q.push(record[node].left);
            }
        }
    };
    level(root);
    cout << "\n";
    first = true;
    function<void(int)> inorder = [&] (int index) {
        if (record[index].right != -1) {
            inorder(record[index].right);
        }
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << index;
        if (record[index].left != -1) {
            inorder(record[index].left);
        }
    };
    inorder(root);
}