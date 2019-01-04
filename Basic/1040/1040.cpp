/*
要想知道构成多少个PAT，那么遍历字符串后对于每一A，
它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。   
P.. A T..

然后把对于每一个A的结果相加即可~~辣么就简单啦，只需要先遍历字符串数一数有多少个T~~然后每遇到一个T呢~
countt–;

每遇到一个P呢，countp++;然后一遇到字母A呢就countt * countp~~~把这个结果累加到result中~~~~最后输出结果就好啦~~对了别忘记要对10000000007取余哦~~~~

本题考察动态规划。主要算法为：一次遍历字符串，按顺序统计p、pa、pat数量，最后输出pat。 

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    // string s;
    // cin >> s;
    // int len = s.length();
    // int result = 0; 
    // int countp = 0;
    // int countt = 0;
    // for (int i = 0; i < len; i++) {
    //     if (s[i] == 'T')
    //         countt++;
    // }
    // for (int i = 0; i < len; i++) {
    //     if (s[i] == 'P') {
    //         countp++;
    //     }
    //     if (s[i] == 'T') {
    //         countt--;
    //     }
    //     if (s[i] == 'A') {
    //         result = (result + (countp * countt) % 1000000007) % 1000000007;
    //     }
    // }
    // cout << result;

    string a;
    cin >> a;
    int p = 0, pa = 0, pat = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'P') {
            p++;
        } else if (a[i] == 'A') {
            pa += p;
        } else if (a[i] == 'T') {
            pat += pa;
            pat = pat % 1000000007;
        }
    }
    cout << pat;
    return 0;
}