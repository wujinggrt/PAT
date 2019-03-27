#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<algorithm> 
#include<cmath>
using namespace std;
const int maxn=100010;
int maxlevel=0,num=0;
vector<int> tree[maxn];
void DFS(int index,int level);
int main()
{
	int n;
	int father,root;
	double price,rate;
	cin>>n>>price>>rate;
	rate/=100;
	for(int i=0;i<n;i++)
	{
		cin>>father;
		if(father!=-1)
			tree[father].push_back(i);
		else
			root=i;//记录根节点 
	}
	DFS(root,0);
	printf("%.2f %d",price*pow(1+rate,maxlevel),num); 
	return 0;
}
 
void DFS(int index,int level)
{
	if(tree[index].size()==0)
	{
		if(level>maxlevel)
		{
			maxlevel=level;
			num=1;//找到新的最大深度，重置他的数量 
		}
		else if(level==maxlevel)//找到相同最大深度结点，数量+1 
			num++;
	return;
	}
	for(int i=0;i<tree[index].size();i++)//递归的访问每一个子节点 
		DFS(tree[index][i],level+1);
}
 
 
 
 