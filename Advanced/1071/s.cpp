#include <unordered_map>
#include <cctype>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    unordered_map<string, int> occurence;
    string max_string = "";
    int32_t max_count = 0;
    string buf = "";
    for (auto c: s) {
        if (!buf.empty() &&
            (isspace(c) || !isalnum(c))) {
            occurence[buf]++;
            if (max_count < occurence[buf]) {
                max_count = occurence[buf];
                max_string = buf;
            }
            buf.clear();
        } else if (isalnum(c)) {
            buf.push_back(tolower(c));
        }
    }
    if (!buf.empty()) {
        occurence[buf]++;
        if (max_count < occurence[buf]) {
            max_count = occurence[buf];
            max_string = buf;
        }
    }
    printf("%s %d\n", max_string.c_str(), max_count);
}