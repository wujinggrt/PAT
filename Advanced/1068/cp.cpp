#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> dp(10010, 0);
    vector<int> w(10010, 0);
    vector<vector<int>> choice(10010, vector<int>(110, 0));
    for(int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    sort(begin(w) + 1, begin(w) + n + 1, std::greater<int>());
    for(int i = 1; i <= n; i++) {
        // 倒序，先从右边来
        // j >= w[i], 剩余的空间至少能够容纳
        for(int j = m; j >= w[i]; j--) {
            // 如果小于, 拿掉w[i]
            // dp保存着大小
            if(dp[j] <= dp[j - w[i]] + w[i]) {
                choice[i][j] = true;
                // take i
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
            arr.push_back(w[index]);
            // weight减少那么多，容量减少，然后在查看那个容量v中，选择了哪一个，所以用index--来遍历这个容量
            v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
int a[102000];
int n,m;
using namespace std;
std::vector<int> v;
void show(){
    int flag=0;
    for(int i=0;i<v.size();i++){
        if(!flag){
            flag=1;
            printf("%d",v[i]);
        }
        else{
            printf(" %d",v[i]);
        }
    }
    printf("\n");
}
int ok=0;
void dfs(int index,int sum){
    if(ok) return;
    if(sum==m){
        ok=1;
        show();
        return;
    }
    if(sum>m){
        return;
    }
    // 从下一个开始全部的搜索。比如：
    // dfs(1, 0);
    // 那么接下来就会从2, 3, 4, 5, ..., n来dfs。每次dfs都会加上当前的点
    // 也就是深度搜索进行全部case的遍历。
    for(int i=index;i<n;i++){
        v.push_back(a[i]);
        // to near next
        dfs(i+1,sum+a[i]);
        v.erase(v.end()-1);//删掉最后那个元素
    }
}
int main(){
    cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<m){//所有coin都不夠
        printf("No Solution\n");
        return 0;
    }
    sort(a,a+n);//从小到大排序
    dfs(0,0);//从第一个开始找
    if(!ok){
        printf("No Solution\n");
    }
    return 0;
}