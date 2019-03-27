#include<cstdio>
#include<queue>
#include<fstream>
using namespace std;
 
struct node{
	int x, y, z;
}Node;
 
int n, m, slice, T;
int pixel[1290][130][61];
bool inq[1290][130][61]={false};
int X[6]={0, 0, 0, 0, 1, -1};
int Y[6]={0, 0, 1, -1, 0, 0};
int Z[6]={1, -1, 0, 0, 0, 0};
 
bool judge(int x, int y, int z){
    // 下标不对
	if(x>=n || x<0 || y>=m || y<0 || z>=slice || z<0) return false;
	if(pixel[x][y][z]==0 || inq[x][y][z]==true) return false;
	return true;
}
 
int BFS(int x, int y, int z){
	int tot=0;
	queue<node> Q;
	Node.x=x, Node.y=y, Node.z=z;
	Q.push(Node);
	inq[x][y][z]=true;
	while(!Q.empty()){
		node top=Q.front();
		Q.pop();
		tot++;
		for(int i=0; i<6; i++){
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			int newz=top.z+Z[i];
			if(judge(newx, newy, newz)==true){
				Node.x=newx, Node.y=newy, Node.z=newz;
				Q.push(Node);
				inq[newx][newy][newz]=true; 
			}
		}
	}
	if(tot>=T) return tot;
	else return 0;
}
 
int main(){
//	freopen("d://in.txt","r",stdin);
	scanf("%d%d%d%d", &n, &m, &slice, &T);
	for(int z=0; z<slice; z++){
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++){
				scanf("%d", &pixel[x][y][z]);
			}
		}
	}
	int ans=0;
	for(int z=0; z<slice; z++){
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++){
				if(pixel[x][y][z]==1 && inq[x][y][z]==false){
					ans+=BFS(x, y, z);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}