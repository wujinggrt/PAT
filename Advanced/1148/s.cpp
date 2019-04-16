#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> states(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> states[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            // 1 is human
            vector<int> id(n + 1, 1); 
            id[i] = id[j] = -1;
            vector<int> lier;
            for (int k = 1; k <= n; ++k) {
                // 已经假设了两个狼人了，就可以验证说谎的人了
                int refer_k = abs(states[k]);
                // k 认为他的身份与实际身份
                if ((states[k] * id[refer_k]) < 0) {
                    // 说谎
                    lier.push_back(k);
                }
            }
            // 一个狼人，一个人 -1 + 1
            if (lier.size() == 2) {
                if (id[lier.front()] + id[lier.back()] == 0) {
                    cout << i << " " << j << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "No Solution\n";
    return 0;
}