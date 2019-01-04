#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), std::greater<int>());
    int rows = sqrt(n) + 1;
    int cols = 0; 
    // 从[1, sqrt(n) + 1]开始，因为sqrt返回double，赋值int截断，所以 + 1，对时间复杂度影响不大。
    // 用i来遍历这个区间，进行浮点数除法，然后赋值给整型，判断是否发生截断。没有的话就是能够整除i
    // 然后可以得到这个数。i == 1的时候也会停止。
    for (int i = rows; i >= 1; --i) {
        int v = static_cast<double>(n) / i;
        if (v * i == n) {
            cols = v;
            rows = i;
            break;
        } else if ((v + 1) * i == n) {
            cols = v;
            rows = i + 1;
            break;
        }
    }
    if (rows < cols) {
        swap(rows, cols);
    }
    vector<vector<int>> matrix(rows, vector<int>(cols));
    // 1前走，0不动，-1反向
    int go_right = 1;
    int go_down = 0;
    /* 
    4个方向的转变顺序：
    0 right -> down 
    1 down -> left
    2 left -> up
    3 up -> right 
    */
    int change_direction_clockwise = 0;
    int down_bound = rows - 1;
    int right_bound = cols - 1;
    int left_bound = 0;
    int up_bound = 1;
    // asign value -> check -> update i, j
    for (int i = 0, j = 0, count = 0; 
        i < rows && j < cols && count < n; 
        ++count) {
        matrix[i][j] = vec[count];
        switch (change_direction_clockwise) {
            case 0: 
                // set to go down instead of going right
                if (j == right_bound) {
                    go_right = 0;
                    go_down = 1;
                    --right_bound;
                    ++change_direction_clockwise = 1;
                }
                break;
            case 1:
                // set to go left instead of going down
                if (i == down_bound) {
                    go_right = -1;
                    go_down = 0;
                    --down_bound;
                    ++change_direction_clockwise = 2;
                }
                break;
            case 2:
                // set to go up instead of going left
                if (j == left_bound) {
                    go_right = 0;
                    go_down = -1;
                    ++left_bound;
                    ++change_direction_clockwise = 3;
                }
                break;
            case 3:
                // set to go right instead of going up
                if (i == up_bound) {
                    go_right = 1;
                    go_down = 0;
                    ++up_bound;
                    ++change_direction_clockwise = 0;
                }
                break;
        }
        switch (go_right) {
            case 1:
                ++j;
                break;
            case 0:
                break;
            case -1:
                --j;
                break;
        }
        switch (go_down) {
            case 1:
                ++i;
                break;
            case 0:
                break;
            case -1:
                --i;
                break;
        }
    }
    for (const auto& vec: matrix) {
        cout << vec[0];
        for (int i = 1; i < vec.size(); ++i) {
            cout << " " << vec[i];
        }
        cout << '\n';
    }
    return 0;
}