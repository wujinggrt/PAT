#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int32_t> vec{1, 2, 3, 4};
    vec.data()[0] = 0;
    for (const auto& e: vec) {
        cout << e << " ";
    }
    cout << "\n";
    string s{"Hello!"};
    auto ptr = s.data();
    cout << s << "\n";
}