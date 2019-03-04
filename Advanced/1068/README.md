# Find More Coins

整体，效率上dfs > bag.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k≥1 such that A[i]=B[i] for all i<k, and A[k] < B[k].

这条信息代表着，如果排序后，直接输出，必然最小。

01背包问题：

[参考了](https://blog.csdn.net/liuchuo/article/details/52278809)

[01背包，知乎](https://zhuanlan.zhihu.com/p/30959069)

[ref](https://blog.csdn.net/xyt8023y/article/details/47255241)

f(i, j)前i个coin中，选出面值不大于j的最大面值的和。第i个面值c[i]。

则对于第i个coin，面对两种情况：

1. 放入第i个，`f(i - 1, j - c[i]) +c[i]`
2. 不放入，则`f(i - 1, j)`

有递推式：

`f(i, j) = max{f(i - 1, j), f(i - 1, j - c[i])+c[i]}`

到最后，如果f(n, m) != m，则说明不存在这样的case。

sort降序是为了找到最小的序列，使用回溯来output。

有一个记录是否选择的表，大小和选后的f(i, j)值一样。也就是如果选择了第i个coin，并且此时`selected[i][cur_value] = true`。这样一个二维数组记录着某一个entry是否选择。

在最后的`total_value[n][m] == m`的case，则可以通过n,m来回溯。为了回溯的过程中是最小序列，则需要是coin的面值降序排列。回溯过程思路：

从selected[n][m]开始判断是否选择了，如果没有的话，那么**当前第n个coin并没有被选择**，则向前面一个，**第i - 1个coin查看是否被选择**，也就是`n--`，在这个面值为m的区域内，知道找到选择的。那么面值m更新，`m -= value[selected_index]`。然后继续从前面一个coin来查找，selected_index--，知道最后的值为0，也就是恰好完成。

```C++
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
 
#define MAXTOTAL	10001
#define MAXAMOUNT	101
 
int f[MAXTOTAL][MAXAMOUNT];			//f[n][m]表示 前n个数中 得出的 最接近m 的值
bool has[MAXTOTAL][MAXAMOUNT];		//has[n][m]表示在前n个数中得出最接近m的值时 是否用到c[n]
int* c = NULL;
 
int calcClosestSum(int n,int m)
{
	memset(f,0,sizeof(int)*MAXTOTAL*MAXAMOUNT);
	memset(has,false,sizeof(bool)*MAXTOTAL*MAXAMOUNT);
	int i,j;
	int sec; // 表示放入c[i]后的值
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(j-c[i]<0) sec=0; // 如果不满足小于等于j，则说明放入后是非法值，可以设其为0，表示面值无效。
			else sec = f[i-1][j-c[i]]+c[i]; // 正常情况下计算放入c[i]的值。
			if(f[i-1][j] > sec)
			{
				f[i][j]=f[i-1][j];
			}else
			{
				f[i][j]=sec;
				has[i][j]=true;		//用到c[i]了 设has[i][j]为true
			}
		}
	}
	return f[n][m];
}
 
bool cmp(const int& A,const int& B)
{
	return A>B;
}
 
int main()
{
   int n,m;
   cin>>n>>m;
   c = new int[n+1];
   memset(c,0,sizeof(int)*(n+1));
 
   int i;
   for(i=0;i<n;i++)
   {
		cin>>c[i+1];
   }
   sort(&c[1],&c[n+1],cmp);		//从大到小排序
 
   int res = calcClosestSum(n,m);
   if(res==m)					//有解
   {
		vector<int> v;
		while(m)
		{
			while(!has[n][m])
				n--;
			v.push_back(c[n]);
			m = m - c[n];
			n--;
		}
		for(i=0;i<v.size()-1;i++)
			cout<<v[i]<<' ';
		cout<<v[i]<<endl;
   }else						//无解
	   cout<<"No Solution"<<endl;
   return 0;
}
```

#### dfs + 剪枝

[dfs](https://blog.csdn.net/qq_38677814/article/details/80935893)

把硬币面额排序，然后对每一个进行dfs。也就是想象所有的硬币都是相联通的。

那么就从1开始。

    // 从下一个开始全部的搜索。比如：
    // dfs(1, 0);
    // 那么接下来就会从剩余（也就是+1）的2, 3, 4, 5, ..., n来dfs。每次dfs都会加上当前的点
    // 也就是深度搜索进行全部case的遍历。
    dfs(i + 1, sum + coins[i]);

整理下：先按照升序排序，然后dfs，从第一个开始，每个走一步，这样的dfs(i + 1, sum + coins[i])