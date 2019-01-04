#include <iostream>
 
using namespace std;
int node[100][100]={0};
int array[100];

int main()
{
    int N,M,ID,K;
    cin>>N>>M;
    int i=0;
    while(i<M)
    {
        cin>>ID>>K;
        int j=0;
        while(j<K)
        {
            cin>>node[ID][j];
            j++;
        }
        i++;
    }
    ::array[0]=1;
    int first=1;
    int front=0,rear=1;
    while(front<rear)
    {
        // tag记录这一层的位子
        int tag=rear;
        int cnt=0;
        // 这一层遍历完，rear也更新到下一层
        while(front<tag)
        {
            int i=0;
            // 从上一层的结点判断，这一层没有孩子结点的node，++cnt
            if(node[::array[front]][0]==0) {
                cnt++;
            }
            else {
                // 增加rear以到这个node的孩子数量
                // 对于所有有child的这一层的node，
                // 增加的也就是下一层的数量
                while(node[::array[front]][i])
                {
                    ::array[rear++]=node[::array[front]][i];
                    i++;
                }
            }
            front++;
        }
        if(first)first=0;
        else cout<<" ";
        cout<<cnt;
    }
    cout<<endl;
    return 0;
}
