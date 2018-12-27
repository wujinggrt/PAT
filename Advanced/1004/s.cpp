#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    if (n == 0) {
        return 0;
    }
    // 0号不用，方便对齐树的id
    vector<vector<int>> children(n + 1);
    for (int i = 0; i < m; ++i) {
        int id;
        int k;
        cin >> id >> k;
        children[id] = vector<int>(k, 0);
        for (int j = 0; j < k; ++j) {
            cin >> children[id][j];
        }
    }
    /*
     层序遍历
     保存当前一层的node index，保存区间为[front, cur_rear)
     然后可以得出下一层的孩子数量，也就是下一层。
     没有孩子，cnt++，又孩子则增加rear。
    */
    vector<int> level_traverse_order(n);
    // store the id of node as level traverse order
    level_traverse_order[0] = 1;
    int first = 1;
    // 从root，也就是第一个开始
    // 一个[front, rear)就是一层
    int front = 0;
    int rear = 1;
    while(front < rear) {
        int cur_rear = rear;
        int cnt = 0;
        while(front < cur_rear) {
            // 如果有子节点，也就是这个id在children非空
            if (children[level_traverse_order[front]].empty()) {
                cnt++;
            } else {
                // update rear
                for (int i = 0; i < children[level_traverse_order[front]].size(); ++i) {
                    level_traverse_order[rear] = children[level_traverse_order[front]][i];
                    ++rear;
                }              
            }
            ++front;
        }
        if (first) {
            first = 0;
        } else {
            cout << " ";
        }
        cout << cnt;
    }
}