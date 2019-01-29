#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    bool former_visited;
    char c;
    string next;
};

int main() {
    string start_former, start_latter;
    int32_t n;
    cin >> start_former >> start_latter >> n;
    unordered_map<string, Node> m;
    m.reserve(n);
    for (int32_t i = 0; i < n; ++i) {
        string start;
        char c;
        string next;
        cin >> start >> c >> next;
        m[start] = Node {false, c, next};
    }
    m[start_former].former_visited = true;
    string next = m[start_former].next;
    // 最后-1这个节点也需要判断是否为visited
    m[next].former_visited = true;
    while (next != "-1"s) {
        next = m[next].next;
        m[next].former_visited = true;
    }
    next = start_latter;
    auto common_pos = "-1"s;
    for (;;) {
        if (m[next].former_visited) {
            common_pos = next;
            break;
        }
        next = m[next].next;
        if (next == "-1"s) {
            break;
        }
    }
    cout << common_pos;
}