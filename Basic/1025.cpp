#include <cstdio>
#include <memory>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int addr;
    int data;
    int next;
};

int main()
{
    int start, n, k;
    cin >> start >> n >> k;
    map<int, Node> m;
    m[-1] = {-1, 0, 0};
    for (int i = 0; i < n; ++i)
    {
        Node node;
        cin >> node.addr >> node.data >> node.next;
        m[node.addr] = node;
    }
    auto cur = &m[start];

    vector<Node *> ordered;
    ordered.reserve(n);
    while (cur->addr != -1)
    {
        ordered.push_back(cur);
        cur = &m[cur->next];
    }
    int temp = k - 1;
    vector<Node *> reversed;
    while (temp < ordered.size())
    {
        for (int i = temp; i > temp - k; --i)
        {
            reversed.push_back(ordered[i]);
        }
        temp += k;
    }
    for (int i = temp - k + 1; i < ordered.size(); ++i)
    {
        reversed.push_back(ordered[i]);
    }
    for (int i = 0; i < ordered.size() - 1; ++i)
    {
        reversed[i]->next = reversed[i + 1]->addr;
        auto p = reversed[i];
        printf("%05d %d %05d\n", p->addr, p->data, p->next);
    }
    auto p = reversed.back();
    printf("%05d %d %d\n", p->addr, p->data, -1);
    
    return 0;
}