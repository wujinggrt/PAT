#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=505;
int capacity,dis,davg;
int n;
struct Gas{
    double price;
    int dis;
    bool operator<(const Gas tmp)const{
        return dis<tmp.dis;
    }
}gas[maxn];
int main()
{
    scanf("%d %d %d %d",&capacity,&dis,&davg,&n);
    for(int i=0;i<n;i++){
        scanf("%lf %d",&gas[i].price,&gas[i].dis);
    }
    sort(gas,gas+n);
    //最后一个设置为目的地，价格为0
    gas[n].price=0;
    gas[n].dis=dis;
    int maxdrive=capacity*davg; //能开的最大距离
    int driveDis;
    int leftdrive=0; //跑到下一个加油站后，还能再跑多少的距离
    int now=0; //车所在的距离
    double sum=0;
    for(int i=0;i<n;){
        // 每一次都应该到达加油站，否则不能跑了
        if(now != gas[i].dis) {
            break; // 能够drive的最大距离，所能够drive到的地方
        }
        // else {
        //     break; //表明一开始出发的地方就没有加油站
        // }
        double minprice=INF;
        int minid=-1;
        for(int j=i+1;j<=n;j++){
            if(now+maxdrive>=gas[j].dis){
                //若找到第一个比当前车站价格小的车站，就不继续往下找了
                if(gas[j].price<gas[i].price){
                    minid=j;
                    minprice=gas[j].price;
                    break;
                }
                //否则，就一直找出其中费用最小的
                if(gas[j].price<minprice){
                    minprice=gas[j].price; // 这一行无用?
                    minid=j;
                }
            }
        }
        if(minid==-1){
            now=gas[i].dis+maxdrive;
            break;
        }
        else{
            if(minprice<gas[i].price){
                //如果有费用比当前车站i更小的车站，那么加油量只需让车能够达到车站即可
                sum+=(
                        static_cast<double>(gas[minid].dis-gas[i].dis) / davg - 
                        static_cast<double>(leftdrive) / davg
                    ) * gas[i].price;
                leftdrive=0;
                i=minid;
                printf("If true:\ni:%d\n", i);
            }
            else{
                //如果没有费用更小的，那么在i处把油加满，达到后面费用最小的那个车站
                // leftdrive的功能在这儿体现
                sum+=(static_cast<double>(capacity)-static_cast<double>(leftdrive)/davg)*gas[i].price;
                leftdrive=maxdrive-(gas[minid].dis-gas[i].dis);
                i=minid;
                printf("Else:\ni:%d\n", i);
            }
            now=gas[minid].dis;
            cout << now << "\n";
        }
    }
    // 到终点
    if(now==dis){
        printf("%.2lf\n",sum);
    }
    else{
        printf("The maximum travel distance = %.2lf\n",(double)now);
    }
    return 0;
}