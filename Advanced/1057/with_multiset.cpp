#include<cstdio>
#include<cstdlib>
#include<set>
#include<stack>
#include<functional>
 
using namespace std;
 
stack<int> s;
multiset<int> upper;//大于中位数的数，从小到大排列
multiset<int,greater<int> > lower;//小于中位数的数，从大到小排列
int mid=0;
 
//调整中位数
// 其中，upper == lower or upper + 1 == lower，至少维护这个状态，因为找的是former，或者是median，只需要begin(lower)
// 这样的话，lower.begin()就是我们要找的答案了。使用begin方便我们查找，比end - 1方便得多
void Adjust(int* mid)
{
	if(upper.size()>lower.size())
	{
		lower.insert(*upper.begin());
		upper.erase(upper.begin());
	}
	else if(lower.size()>upper.size()+1)
	{
		upper.insert(*lower.begin());
		lower.erase(lower.begin());
	}
	(*mid)=*lower.begin();
}
 
int main(int argc,char *argv[])
{
	int i,n;
	char str[20];
	scanf("%d",&n);
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
					if(key>*lower.begin())
					{
						upper.erase(upper.find(key));
					}
					else
					{
						lower.erase(lower.find(key));
					}
					if(s.empty())
						mid=0;
					else
						Adjust(&mid);
				}
				break;
			case 'e':
				if(s.empty())
					printf("Invalid\n");
				else
					printf("%d\n",mid);
				break;
			case 'u':
				int key;
				scanf("%d",&key);
				s.push(key);
				if(key>mid)
					upper.insert(key);
				else
					lower.insert(key);
				Adjust(&mid);
				break;
		}
	}
 
	return 0;
}
