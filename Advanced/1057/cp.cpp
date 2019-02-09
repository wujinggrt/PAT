#include<cstdio>
#include<cstdlib>
#include<stack>
#define MAX 100005
 
using namespace std;
 
//树状数组里A[i]的值，表示i出现的次数
// 使用array是为了能够使用 key 来random access，提高效率，省去查找
int TreeArray[MAX];
 
int lowbit(int n)
{
    // 取最低位为1的数，比如4：0100 & 1100 = 0100, 4。如果是奇数，那么全部都是1了，但是总能找到最近的偶数
    // 比如：1 & -1 = 1， n += 1 -> n = 2, n & -n = 2。如此可以快速遍历树？
    // 取符号就是，反码 + 1，除了最低位还原，其他位都反，所以其他都是0
    // 最低位都是一样的，不论补码前后
    // return (n % 2 == 0 ? 0 : 1); 超时版本
	return n & (-n);
}

void update(int n,int num)
{
	while(n < MAX)
	{
        printf("In while:%d\n", n);
        // 出现的次数
		TreeArray[n] += num; 
        // +1 or + 0 ?取决于n的奇（+1）偶（+0）
		n+=lowbit(n);
	}
    printf("End while\n\n");
}

int GetSum(int n)
{
	int sum=0;
	while(n>0)
	{
		sum+=TreeArray[n];
		n-=lowbit(n);
	}
	return sum;
}
 
int BinSearch(int target)//对栈中间元素进行二分查找，GetSum(mid)返回的值
{                        //表示0~mid之间元素的个数，如果等于target，则mid
	int left=0,right=MAX;//就是要求的结果
	int mid;
	while(left<=right)
	{
		mid=left+(right-left)/2;
		int sum=GetSum(mid);
		if(sum>target)
			right=mid-1;
		else if(sum<target)
			left=mid+1;
		else if(sum==target)
			right=mid-1;
	}
	return left;
}
 
int main(int argc,char *argv[])
{
	stack<int> s;
	char str[20];
	int i,n;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		switch(str[1])
		{
			case 'o':
				if(s.empty())
					printf("Invalid\n");
				else
				{
					int key=s.top();
					s.pop();
					printf("%d\n",key);
                    // -1就是
					update(key,-1);
				}
				break;
			case 'u':
				int key;
				scanf("%d",&key);
				s.push(key);
				update(key,1);
				break;
			case 'e':
				if(s.empty())
					printf("Invalid\n");
				else
				{
					int midvalue=BinSearch((s.size()+1)/2);
					printf("%d\n",midvalue);
				}
				break;
		}
	}
 
	return 0;
}
