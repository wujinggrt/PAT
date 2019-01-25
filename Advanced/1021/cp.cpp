/**********************************
*@Author: 3stone
*@ACM: PAT.A1021 Deepest Root
*@Time: 18/8/13
*@IDE: VSCode 2018 + clang++
***********************************/
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;
const int maxn = 10010;
int N;
int farther[maxn];
vector<int> A, B;
set<int> root_set;
vector<int> Adj[maxn];
bool vis[maxn];

int max_dep;

//并查集初始化
void init() {
    for(int i = 1; i <= N; i++)
        farther[i] = i;
}

//寻根
int find_root(int a) {
    int root = a;
    while(root != farther[root])
        root = farther[root];

    // 给a到root之上的相关元素，全部赋值到root
    // check元素，如果这个节点之前只是随着root依附到另外地方的
    // 现在就更新和维护
    while (a != farther[a]) {
        int cur = a;
        a = farther[a];
        farther[cur] = root;
    }
    return root;
}

// 不在一个set，union
void union_set(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if(a != b) 
        farther[b] = a;
}

void dfs_find(int v, int depth) {
    vis[v] = true;
    depth++;
    if(depth > max_dep) {
        A.clear();
        A.push_back(v);
        max_dep = depth;
    } else if(depth == max_dep){
        A.push_back(v);
    }
    for(int i = 0; i < Adj[v].size(); i++){
        if(vis[Adj[v][i]] == false)
            dfs_find(Adj[v][i], depth);
    }
}

int main() {
    int a, b;
    while(scanf("%d", &N) != EOF) {

        if(N == 1) {
            printf("1\n");
            continue;
        }

        for(int i = 1; i <= N; i++)  //清空图
            Adj[i].clear();
        fill(vis, vis + maxn, false);
        init();

        // 创建图的时候就决定了连通分量的个数
        for(int i = 0; i < N-1; i++){
            scanf("%d%d", &a, &b);
            Adj[a].push_back(b);
            Adj[b].push_back(a);
            union_set(a, b);
        }
        //检查是否是连通图（即只有一个集合）
        int set_num = 0;
        for(int i = 1; i <= N; i++){
            if(i == farther[i])
                set_num++;
        }
        if(set_num > 1) {
            printf("Error: %d components\n", set_num);
            continue;
        }

        A.clear();
        max_dep = 0;
        //找到集合A
        dfs_find(1, 0);
        for(int i = 0; i < A.size(); i++) {
            root_set.insert(A[i]);
            cout << A[i] << "\n";
        }
        int temp = A[0];
        fill(vis, vis + maxn, false);
        max_dep = 0;
        A.clear();
        //找到集合B
        dfs_find(temp, 0);
        for(int i = 0; i < A.size(); i++) {
            root_set.insert(A[i]);
            cout << A[i] << "\n";
        }
        for(set<int>::iterator it = root_set.begin(); it != root_set.end(); it++) {
            printf("%d\n", *it);
        }

    }

    return 0;
}