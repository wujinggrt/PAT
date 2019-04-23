#include <cmath>
#include <cstdio>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Node {
    int parent = -1;
    int left = -1;
    int right = -1;
};

int main(){
    int n;
    cin >> n;
    vector<Node> tree(n);
    for (int i = 0; i < n; ++i) {
        string left, right;
        cin >> left >> right;
        if (left != "-") {
            tree[i].left = stoi(left);
            tree[tree[i].left].parent = i;
        }
        if (right != "-") {
            tree[i].right = stoi(right);
            tree[tree[i].right].parent = i;
        }
    }
    int root = 0;
    while (tree[root].parent != -1) {
        root = tree[root].parent;
    }
    int maxn = -1, ans;
    function<void(int, int)> traverse = [&] (int root, int index) {
        if (index > maxn) {
            maxn = index;
            ans = root;
        }
        if (tree[root].left != -1) {
            traverse(tree[root].left, index * 2);
        }
        if (tree[root].right != -1) {
            traverse(tree[root].right, index * 2 + 1);
        }
    };
    traverse(root, 1);
    if (maxn == n) {
        printf("YES %d\n", ans);
    } else {
        printf("NO %d\n", root);
    }
}