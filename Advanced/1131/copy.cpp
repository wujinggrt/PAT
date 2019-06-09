#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
const int maxn=10000;
const int Inf=0x7fffffff;
unordered_map<int,unordered_map<int,int>> mp;//存储两站点间的地铁线，如mp[6666][8432]=4，表示6666->8432是4号线
bool vis[maxn];//在DFS中标记结点是否已经被访问过
vector<int> graph[maxn];//邻接表存储地铁线路图
int k,n,m,s,e,minDistance,minTransfer;//地铁线条数，每条地铁的站点数，查询次数，查询的起点和终点，最短距离，最少换乘数
vector<int> path,tmpPath;//path存放最优路径，tmpPath存放临时路径

// 使用前，现在和下一站的 line 是否改变来求出数量
int getTransferCnt(vector<int>& path)
{
    int changeCnt=0;
    int pre=path[0];
    for(int i=1;i+1<path.size();i++){//注意，这里的判定是i+1<path.size()
        int curr=path[i],next=path[i+1];
        if(mp[pre][curr]!=mp[curr][next]) changeCnt++;
        pre=curr;//记得更新
    }
    return changeCnt;
}

void dfs(int s)
{
    vis[s]=true;
    tmpPath.push_back(s);
    if(s==e){
        // 到达了
        int tmpTransfer=getTransferCnt(tmpPath);
        if(tmpPath.size()-1 < minDistance){
            minDistance=tmpPath.size()-1;
            minTransfer=tmpTransfer;
            path=tmpPath;
        }else if(tmpPath.size()-1 == minDistance && tmpTransfer < minTransfer){
            minTransfer=tmpTransfer;
            path=tmpPath;
        }
        return;
    }
    for(auto next:graph[s]){
        if(vis[next] == true) continue;
        dfs(next);
        tmpPath.pop_back();
        vis[next]=false;
    }
}

void printPath(vector<int>& path)
{
    //换乘次数为0时，只需要输出起点和终点，单独输出。这里minTransfer是全局变量，在调用该函数前已经确定
    if(minTransfer==0){
        int a=path[0],b=path[path.size()-1];//also b=path.back();
        printf("Take Line#%d from %04d to %04d.\n",mp[path[0]][path[1]],a,b);//注意，这里线路不能是mp[a][b]，因为站点a、b不一定是相邻的！
        return;
    }
    int start=path[0];//表示当前这条线路的起始站
    int pre=path[0],curr,next;
    for(int i=1;i+1<path.size();i++){
        curr=path[i],next=path[i+1];
        if(mp[pre][curr]!=mp[curr][next]) {
            printf("Take Line#%d from %04d to %04d.\n",mp[pre][curr],start,curr);
            start=curr;//出现换乘，记得更新起始站
        }
        pre=curr;
    }
    //输出最后一次换乘至终点的线路
    printf("Take Line#%d from %04d to %04d.\n",mp[path[path.size()-2]][path[path.size()-1]],start,path[path.size()-1]);
}

int main()
{
    freopen("i.dat","r",stdin);
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int pre,curr;
        scanf("%d%d",&n,&pre);
        for(int j=1;j<n;j++){
            scanf("%d",&curr);
            graph[pre].push_back(curr);
            graph[curr].push_back(pre);
            mp[pre][curr]=mp[curr][pre]=i;
            pre=curr;
        }
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&s,&e);
        //每次查询前千万记得初始化
        memset(vis,false,sizeof(vis));
        path.clear();
        tmpPath.clear();
        minDistance=Inf, minTransfer=Inf;
        dfs(s);
        printf("%d\n",minDistance);
        printPath(path);
    }
    fclose(stdin);
    return 0;
}
