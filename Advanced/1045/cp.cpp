#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int like[201]={0};
int given[10001]={0};
int len[201][10001]={0};
 
int LCS(int row,int col)
{
	int i,j;
	for(i = 1; i <= row; i++){
		for(j = 1; j <= col; j++){
            // 左上角？
			int max_entry = max({len[i - 1][j - 1], len[i][j - 1], len[i-1][j]});
            //如果相等，则将最大值+1
			if(like[i]==given[j]){				
				len[i][j] = max_entry+1;
			} else {
				len[i][j] = max_entry;
			}
		}
	}
	return len[row][col];
}
 
 
int main()
{
	int n,m,l;
	cin>>n>>m;
	int i;
	for(i=0;i<m;i++)cin>>like[i+1];
	cin>>l;
	for(i=0;i<l;i++)cin>>given[i+1];
 
	cout<<LCS(m,l)<<endl;
	return 0;
}
