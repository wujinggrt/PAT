#include <string>
#include <stack>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> record;
    vector<int> preorder;
    vector<int> inorder;
    for (int i = 0; i < 2 * n; ++i) {
        string s;
        int no;
        cin >> s;
        if (s[1] == 'u') { // Push
            cin >> no;
            preorder.push_back(no);
            record.push(no);
        } else {
            no = record.top();
            inorder.push_back(no);
            record.pop();
        }
    }
    /**
     * @param left, right为中序遍历的左右边界, left, root, right。
     * 利用这两个参数来判断树的位置的有效性。然后每次找到root在中序遍历中的位置，
     * 在拆分成两部分。直到拆分完，也就是left > right。
     * 
     * left > right的情况是，上次为left == right，right为的root的位置-1之后（或者是left为root + 1），
     * 传入给下次自然就left > right了。
     * 
     * @root_pos_preorder 根的位置
     * */
    function<void(int, int, int)> postorder = [&] (int left, int right, int root_pos_preorder) {
        if (left > right) {
            return;
        }
        // 找到中序的位子，比如
        // pre: 1 2 3 4 5 6
        // in: 3 2 4 1 6 5
        // 找到1的位置，然后就可以拆分为左右部分（子树）
        auto root_pos_inorder = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (preorder[root_pos_preorder] == inorder[i]) {
                root_pos_inorder = i;
                break;
            }
        }
        // 左子树的root就是root_pos_preorder + 1
        postorder(left, root_pos_inorder - 1, root_pos_preorder + 1);//递归左子树
        // 右子树在中序遍历是最后一个，但是在先序遍历root,left,right，则在left之后就出现。
        // 所以，由root_pos_inorder - left + 1 代表左子树和根个数，
        // 在加上root_pos_preorder表示偏移
        // 右子树的root为(root_pos_preorder + root_pos_inorder - left + 1)
        // 也就是左子树的数量
        postorder(root_pos_inorder + 1, right, (root_pos_preorder + root_pos_inorder - left + 1));//递归右子树
        //输出根结点
        if (root_pos_preorder == 0) {
            cout << preorder[root_pos_preorder] << "\n"; // 最后一个
        } else {
            cout << preorder[root_pos_preorder] << ' ';
        }
    };
    postorder(0, preorder.size() - 1, 0);
}