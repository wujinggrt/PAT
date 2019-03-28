#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> val;
vector<node> tree;
int index = 0;
struct node{
	int val;
	int left; 
	int right;
};
 
bool cmp(int a, int b){
	return a<b;
}
bool inOrder(node& root){
	if(root.left != -1){
		inOrder( tree[root.left] );
	}
	root.val = val[index++];
	if(root.right != -1){
		inOrder(tree[root.right]);
	}
}
 
bool  levelOrder(node root){
	queue<node> que;
	que.push(root);
	bool isFirst = true;
	while(!que.empty()){
	   node t = que.front();
	   if(isFirst){
	   	   cout<<t.val;
	   	   isFirst = false;
	   }else{
	   		cout<<" "<<t.val;
	   }
	   if(t.left != -1){
	   	  que.push(tree[t.left]);
	   }
	   if(t.right!=-1){
	   	   que.push(tree[t.right]);
	   }
	   que.pop();	   
	}
	cout<<endl;
}
 
 
int main(){
	int n, i;
	scanf("%d",&n);
	tree.resize(n);
	for(i=0; i<n; i++){
		scanf("%d%d",&tree[i].left,&tree[i].right);		
	}
	val.resize(n);
	for(i=0; i<n; i++){
		scanf("%d",&val[i]);
	}
	sort(val.begin(), val.end(), cmp);
	inOrder(tree[0]);
	levelOrder(tree[0]);
	return 0;
}