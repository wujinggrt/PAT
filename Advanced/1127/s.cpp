#include <string>
#include <functional>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n);
    for (auto& node: inorder) {
        cin >> node;
    }
    vector<int> postorder{istream_iterator<int>(cin), istream_iterator<int>()};
    Node root;
}
