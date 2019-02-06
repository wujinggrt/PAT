#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &m, &n, &k);
    int num;
    vector<int> st;
    while(k-- > 0) {
        st.clear();
        // j记录当前出现过的最大数
        int j = 1;                      
        bool flag = true;
        for(int i = 0; i < n; i++) {
            scanf("%d", &num);
            while(j <= num) {
                st.push_back(j++);
            }
            if(st.size() > m) {
                flag = false;
            }
            // 从1开始pop栈，直到遇到要输出的数
            // 若下一个数比当前栈顶小，则出栈
            // 预期的是一个一个的pop
            // 也就是，如果有一个乱序了，比如：7 5 6 4
            // 7: pop 7
            // 5: 不pop
            // 6: pop 6
            // 4: 不pop
            while(st.back() == num && !st.empty()) {       
                st.pop_back();
            }
        }
        if(!flag) printf("NO FLag");
        else if(!st.empty()) printf("NO NonEmpty");
        else printf("YES");
        printf("\n");
    }
    return 0;
}