#include <string>
#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    cin >> a >> b;
    auto result = a + b;
    string s = to_string(result);
    string buffer = "";
    for (int i = s.size() - 1, count = 0; i >= 0; --i) {
        if (count == 3) {
            buffer += ",";
            count = 0;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            buffer += s[i];
            ++count;
        }
    }
    if (result < 0) {
        cout << '-';
    }
    int i = buffer.size() - 1;
    if (buffer.back() == ',') {
        --i;
    }
    for (; i >= 0; --i) {
        cout << buffer[i];
    }
    cout << '\n';
}