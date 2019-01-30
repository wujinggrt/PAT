#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include <iostream>
using namespace std;

const int maxn=1001;

bool isSymmetry(const string& in,int start,int end){
	if(start<0) return false;
	while(start<end) {
		if(in[start++]!=in[end--]) return false;
	}
	return true;
}
int main(){
	string in;
    getline(cin, in);
	int length=in.size();
	int len=0,max=-1;
	//从左到右遍历字符串，每次只需要考虑加入这个字符是否能组成更长的回文串
	for(int i=0;i<length;i++){
		if(isSymmetry(in,i-len-1,i)){
			len+=2;
			//if(len>max) max=len;
		}
		else if(isSymmetry(in,i-len,i)){
			len+=1;
			//if(len>max) max=len;
		}
	}
	printf("%d",len);
	return 0;
}
