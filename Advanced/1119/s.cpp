#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> pre(n);
    for (auto& num: pre) {
        cin >> num;
    }
    vector<int> post{istream_iterator<int>(cin), istream_iterator<int>()};
    bool is_unique = true;
    vector<int> inorder;
    function<void(int, int, int, int)> 
        process_inorder = [&] (int pre_left, int pre_right, int post_left, int post_right) {
            // end
            if (pre_left == pre_right) {
                inorder.push_back(pre[pre_left]);
            } else if (pre[pre_left] == post[post_right]) { // root
                int right_root_preorder = pre_left + 1;
                // postRight is the root of right-subtree,
                // find the root pos in preorder,
                // then solve it recursively.
                while (right_root_preorder <= pre_right &&
                       pre[right_root_preorder] != post[post_right - 1]) {
					++right_root_preorder;
                }
                // left subtree exist, process it.
                if (right_root_preorder - pre_left > 1) {
                    // i - preLeft - 1 indicate the size of left-subtree
                    process_inorder(pre_left + 1, 
                                    right_root_preorder - 1, 
                                    post_left, 
                                    post_left + (right_root_preorder - pre_left - 1) - 1);
                } else { // 左子树不存在
                    is_unique = false;
                }
                inorder.push_back(post[post_right]);
                process_inorder(right_root_preorder, 
                                pre_right,
                                post_left + (right_root_preorder - pre_left - 1),
                                post_right - 1);
            }
    };
    process_inorder(0, n - 1, 0, n - 1);
    cout << (is_unique ? "Yes\n" : "No\n");
    cout << inorder.front();
    for (int i = 1; i < inorder.size(); ++i) {
        cout << " " << inorder[i];
    }
    cout << "\n";
}