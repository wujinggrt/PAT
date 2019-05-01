#include <iostream>
#include <vector>
using namespace std;

vector<int> in, pre, post;
bool unique = true;

void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    // end
    if(preLeft == preRight) {
        in.push_back(pre[preLeft]);
        return;
    }
    // root
    if (pre[preLeft] == post[postRight]) {
        int i = preLeft + 1;
        // postRight is the root of right-subtree,
        // find the root pos in preorder,
        // then solve it recursively.
        while (i <= preRight && pre[i] != post[postRight - 1]) i++;
        // if left-subtree exist, then sovle it.
        if (i - preLeft > 1)
            // i - preLeft - 1 indicate the size of left-subtree
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
        else
            unique = false;
        // inorder
        in.push_back(post[postRight]);
        // process the right part.
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    getIn(0, n-1, 0, n-1);
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;
}