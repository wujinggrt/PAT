#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<string,vector<string> > mpTitle,mpAuthor,mpKey,mpPub,mpYear;
 
void query(unordered_map<string,vector<string>>& mp,string& str){
	if(mp.find(str)==mp.end()) {
        printf("Not Found\n");
    } 
	else{
        sort(begin(mp[str]), end(mp[str]));
		for(auto it=mp[str].begin();it!=mp[str].end();it++){
            cout << *it << "\n";
			// printf("%s\n",it->c_str());
		}
	}   
}
 
int main() {
	int n,m,type;
	string id, title,author,key,pub,year;
	scanf("%d",&n);
    char c = cin.get(); //接收掉id后面的换行
	for(int i=0;i<n;i++)
	{
        getline(cin, id);
		getline(cin,title);
		mpTitle[title].push_back(id);
		getline(cin, author);
		mpAuthor[author].push_back(id);
		while(cin >> key){
			mpKey[key].push_back(id);
			c = getchar();
			if(c == '\n') break;
		}
		getline(cin,pub);
		mpPub[pub].push_back(id);
		getline(cin,year);
		mpYear[year].push_back(id);
	}
	string temp;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d: ",&type); //查询类型
		getline(cin,temp);	//欲查询字符串
		cout<<type<<": "<<temp<<endl;
		// if(type==1) query(mpTitle,temp);
        if (type == 1) {
            auto it = mpTitle.find(temp);
            if (it == end(mpTitle) || it->second.size() == 0) {
                printf("Not Found\n");
            } else {
                for (auto& e: it->second) {
                    cout << e << "\n";
                }
            }
        }
		else if(type==2) query(mpAuthor,temp);
		else if(type==3) query(mpKey,temp);
		else if(type==4) query(mpPub,temp);
		else query(mpYear,temp);
	}
	return 0;
}

// --------------------- 
// 作者：LoveGqqqqq 
// 来源：CSDN 
// 原文：https://blog.csdn.net/qiangluo0221/article/details/79576076 
// 版权声明：本文为博主原创文章，转载请附上博文链接！