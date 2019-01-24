#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#define INF 99999999
using namespace std;
struct station{
    int tour,bike; 
    station(){}
    station(int bike):bike(bike){
        tour=INF;
    }
};
struct edge{
    int to,length;
    edge(int a, int b):to(a),length(b){}
};
vector<edge>G[510];
station st[510];
// visited ？
int v[510];
vector<int>path;
vector<int>anspath;
int Sum=INF,sum=0;
int Bring=INF,bring=0;
int Take=INF,take=0;
int Cmax,N,Sp,M;
void dfs(int a){
    // sum 代表总的路径长度？
    if(sum>Sum)return ;
    if(a==Sp){
        // 当为终点时判断是否为最优解 
        // 最短路径 || 
        //              最短了路径 且 Bring最小 
        //                                      Bring相等，Take最小
        if(Sum>sum||(Sum==sum&&(Bring>bring||(Bring==bring&&Take>take)))){
            Sum=sum;
            Bring=bring;
            Take=take;
            anspath=path;
        }
        return ;
    }
    // 矩阵据说也能过 
    // 也就是visit的for
    for(int i=0;i<G[a].size();i++){
        int to=G[a][i].to,length=G[a][i].length;
        int tempbring=bring,temptake=take,tempsum=sum;//保存值，便于回溯 
        //如果不是距离最短直接跳过 
        // if !v[to] 这个to没有被visited
        // tour 为到PBMC的目前的最短距离？
        // 如果不能够更短，那就没有必要进行遍历了，直接下一个
        // 满足条件，则更具情况处理
        // 所有的值都在末端，a == Sp 处进行保存
        // 这儿只管处理数据和遍历所有情况
        if(!v[to]&&st[to].tour>=st[a].tour+length){
            v[to]=1;                         
            take+=st[to].bike;
            if(take<0)bring-=take,take=0;
            sum+=length;
            st[to].tour=st[a].tour+length;
            path.push_back(to);                    
            dfs(to);                              
            //回溯 
            v[to]=0;                                
            bring=tempbring;
            take=temptake;
            sum=tempsum;
            path.pop_back();
        }
    }
}

int main(){
    scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
    Cmax/=2;
    int bike;
    st[0]=station(0);
    st[0].tour=0;
    for(int i=1;i<=N;i++){
        scanf("%d",&bike);
        st[i]=station(bike-Cmax); //bike为正则需带回，为负则需调配 
    }
    int a,b,c;
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(edge(b,c));
        G[b].push_back(edge(a,c));
    }
    dfs(0);
    printf("%d 0",Bring);
    for(int i=0;i<anspath.size();i++){
        printf("->%d",anspath[i]);
    } 
    printf(" %d",Take);
    return 0;
}