#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> mp;
int main() {
  int m, n, u, v, a;
  scanf("%d %d", &m, &n);
  vector<int> pre(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &pre[i]);
    mp[pre[i]] = true;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    for(int j = 0; j < n; j++) {
      a = pre[j];
      // a belongs to (u, v) or (v, u)
      // 因为 a 也就是寻找的 parent 必定属于
      // u, v 的区间，也就是作为 root, 左子树小于 a，右子树大于 a
      // 的特效
      // 利用道德一个 BST 肯定不满足的特效，左右子树不满足上述关系
      // 肯定就不是合适的 parent
      if ((a >= u && a <= v) || (a >= v && a <= u)) break;
    } 
    if (mp[u] == false && mp[v] == false)
      printf("ERROR: %d and %d are not found.\n", u, v);
    else if (mp[u] == false || mp[v] == false)
      printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
    else if (a == u || a == v)
      printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
    else // a 既不是两者
      printf("LCA of %d and %d is %d.\n", u, v, a);
  }
  return 0;
}
