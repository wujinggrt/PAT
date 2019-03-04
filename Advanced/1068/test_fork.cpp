#include <unistd.h>/*#包含<unistd.h>*/
#include<sys/types.h>//对于此程序而言此头文件types.h用不到

#include <iostream>
using namespace std;

int main(){
    pid_t pid = fork();
    if (pid == 0)     {
        cout << "sub process\n";
    } else {
        cout << "parent process with child:" << pid << "\n";
    }
    exit(0);
}