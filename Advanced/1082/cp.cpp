#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char num[10][5] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main() {
    char str[15];
    scanf("%s", str);
    int len = strlen(str);
    int left = 0, right = len - 1;
    if(str[0] == '-') {
        printf("Fu");
        left++;
    }
    if (left == right) {
        printf("%s\n", num[str[left] - '0']);
        return 0;
    }
    // 每四位来处理, + 4既是有5位数字或者以上
    // 从尾部（right）减，
    // e.g. 100800, 10 0800
    while(left + 4 <= right) {
        right -= 4;
    }
    while(left < len) {
        bool flag = false;
        bool isPrint = false;
        for (; left <= right; ++left) {
            // 如果一直0，那么一直++，不打印这个ling
            // 记录起来到flag，给下一次print的时候给打印它的信息
            // ling 后面肯定是一个数，如100800 中的 ling ba Bai
            // 这个ling一直推迟到有数输出才会先输出它
            if(str[left] == '0') {
                flag = true;
            } else {
                // 0 只能打印一次，不能有 yi ling ling 的情况
                if(flag) {
                    printf(" ling");
                    flag = false;
                }
                // 第一次不输出，也就是首位没空格
                if(left > 0) {
                    printf(" ");
                }
                // 位置，如果遇到了0
                printf("%s", num[str[left] - '0']);
                // 只有非0才会输出
                isPrint = true;
                // 当等于的时候，由外层loop输出，因为马上就要退出本次循环了
                if(left != right) {
                    // right - left，还有多少数字猜到right
                    // 100800中最左边的1是0,因为-1.right == left则退出了
                    printf(" %s", wei[right - left - 1]);
                }
            }
        }
        // 处理第前面的已经处理完了，每4位处理一次
        // isPrint代表前面有数字，0的话也要输出100800，如yi Shi Wan中的Wan
        if(isPrint && right != len - 1) {
            printf(" %s", wei[(len - 1 - right) / 4 + 2]);
        }
        right += 4;
    }
    cout << "\n";
    return 0;
}
