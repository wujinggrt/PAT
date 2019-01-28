//https://blog.csdn.net/loststephon/article/details/48899253
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;
 
struct players
{
    int arriveTime;
    int startServe;
    int serveTime;
    int waitTime;
    int isVIP;
};
//等待队列中的VIP客户
vector<players >vipPlayers;
//普通客户
vector<players >ordinaryPlayers;
//处理完输出信息的客户
vector<players >total;
struct tables
{
    int VIP;
    int cnt;
    int vacantTime;
};
tables t[101];
 
bool cmpPlayers(players a,players b)
{
    return a.arriveTime<b.arriveTime;
}
 
bool cmpStartServe(players a,players b)
{
    return a.startServe<b.startServe;
}
 
int main()
{
    int N,K,M,i=0;
    cin>>N;
    int hh,mm,ss,wait,vip;
    players temp;
    while(i<N)
    {
        scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&wait,&vip);
        temp.arriveTime=hh*3600+mm*60+ss;
        temp.serveTime=wait*60;
        temp.isVIP=vip;
        i++;
        if(temp.arriveTime>=3600*21)continue;
        if(vip==1)vipPlayers.push_back(temp);
        else ordinaryPlayers.push_back(temp);
    }
    cin>>K>>M;
    // 0 号不要
    for(int j=1;j<=K;j++)
    {
        t[j].VIP=0;
        t[j].vacantTime=8*3600;
        t[j].cnt=0;
    }
    int tag;
    for(int j=0;j<M;j++)
    {
        cin>>tag;
        t[tag].VIP=1;
    }
 
    // if(ordinaryPlayers.size()>0)
    sort(ordinaryPlayers.begin(),ordinaryPlayers.end(),cmpPlayers);
    // if(vipPlayers.size()>0)
    sort(vipPlayers.begin(),vipPlayers.end(),cmpPlayers);
 
    while(ordinaryPlayers.size()>0||vipPlayers.size()>0)
    {
        int minVacant=INT_MAX;
        int minVipVacant=INT_MAX;
        int index;
        int vipIndex;
        // find the min and minVIP in table
        for(int j=1;j<=K;j++)
        {
            if(t[j].vacantTime<minVacant)
            {
                minVacant=t[j].vacantTime;
                index=j;
            }
            if(t[j].VIP==1&&t[j].vacantTime<minVipVacant)
            {
                minVipVacant=t[j].vacantTime;
                vipIndex=j;
            }
        }
        // 遍历完成
        if(t[index].vacantTime>=21*3600)
            break;
        players nextPlayers;
        // 这儿应该使用函数
        // 这儿使用iter指向特定的位子，不用删除，省去效率
        // 找到下一个上场的player，
        // 只剩下一个队列的情况，就是排队等
        if(vipPlayers.size()==0)
        {
            nextPlayers=ordinaryPlayers.front();
            ordinaryPlayers.erase(ordinaryPlayers.begin());
        }
        else if(ordinaryPlayers.size()==0)
        {
            nextPlayers=vipPlayers.front();
            vipPlayers.erase(vipPlayers.begin());
        }
        // 等待的队列两者都有
        else
        {
            // 如果是VIP空缺，看看vips
            if(t[index].VIP==1)
            {
                // VIP在普通用户前到达
                // VIP位子在VIP到达**之后**才空缺，也就是所有位子空，VIP位子最先完成服务
                // 那么优先给VIP用户使用
                if(
                    vipPlayers.front().arriveTime<ordinaryPlayers.front().arriveTime ||
                    t[index].vacantTime>=vipPlayers.front().arriveTime
                ) {
                    nextPlayers=vipPlayers.front();
                    vipPlayers.erase(vipPlayers.begin());
                }
                else
                {
                    nextPlayers=ordinaryPlayers.front();
                    ordinaryPlayers.erase(ordinaryPlayers.begin());
                }
            }
            // 位子为普通位子
            else
            {
                if(vipPlayers.front().arriveTime<ordinaryPlayers.front().arriveTime)
                {
                    nextPlayers=vipPlayers.front();
                    vipPlayers.erase(vipPlayers.begin());
                }
                else
                {
                    nextPlayers=ordinaryPlayers.front();
                    ordinaryPlayers.erase(ordinaryPlayers.begin());
                }
            }
        }
        //控制每个人的时间在两小时之内,超过两小时按两个小时截断
        if(nextPlayers.serveTime>7200)nextPlayers.serveTime=7200;
        //这里需要记清楚：一旦有VIP桌子空闲，等待队列中的VIP客户就会选择VIP桌子，
        //不管是否有普通桌子空闲

        // 如果是vip的turn，那么他会优先选择vip桌子，如果存在这样的桌子的话
        // 否则else，按照普通处理
        if(
            nextPlayers.isVIP==1 && 
            nextPlayers.arriveTime>=t[vipIndex].vacantTime)
        {
            nextPlayers.waitTime=0;
            nextPlayers.startServe=nextPlayers.arriveTime;
            t[vipIndex].vacantTime=nextPlayers.arriveTime+nextPlayers.serveTime;
            t[vipIndex].cnt++;
        }
        else
        {
            if(nextPlayers.arriveTime<=t[index].vacantTime)
            {
                nextPlayers.waitTime=t[index].vacantTime-nextPlayers.arriveTime;
                nextPlayers.startServe=t[index].vacantTime;
                t[index].vacantTime+=nextPlayers.serveTime;
                t[index].cnt++;
            }
            else
            {
                nextPlayers.waitTime=0;
                nextPlayers.startServe=nextPlayers.arriveTime;
                t[index].vacantTime=
                                    nextPlayers.arriveTime + 
                                    nextPlayers.serveTime;
                t[index].cnt++;
            }
        }
        total.push_back(nextPlayers);
    }
    sort(total.begin(),total.end(),cmpStartServe);
    for(int i=0;i<total.size();i++)
    {
        int waitMinutes=total[i].waitTime/60+(total[i].waitTime%60<30?0:1);
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",total[i].arriveTime/3600,
               (total[i].arriveTime%3600)/60,total[i].arriveTime%60,
               total[i].startServe/3600,(total[i].startServe%3600)/60,
               total[i].startServe%60,waitMinutes);
    }
    int first=1;
    for(int i=1;i<=K;i++)
    {
        if(first)first=0;
        else cout<<" ";
        cout<<t[i].cnt;
    }
    return 0;
}
