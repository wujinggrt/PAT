#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    unordered_set<char> erasing;
    for (auto c: s2) {
        erasing.insert(c);
    }
    for (auto c: s1) {
        if (erasing.find(c) == end(erasing)) {
            cout << c;
        }
    }
    cout << "\n";
}