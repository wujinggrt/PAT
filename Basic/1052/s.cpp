#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> get_contents();

vector<string> get_contents() {
    vector<string> ret;
    ret.reserve(15);
    string values = "";
    char c;
    while (cin.get(c)) {
        if (c == '\n') {
            break;
        } else if (c == '[') {
            while (c != ']') {
                cin.get(c);
                if (c == ']') {
                    break;
                }
                values += c;
            }
            ret.push_back(values);
            values = "";
        }
    }
    ret.shrink_to_fit();
    return ret;
}

int main() {
    vector<string> hands = get_contents();
    vector<string> eyes = get_contents();
    vector<string> mouses = get_contents();

    string values = "";
    int k;
    cin >> k;
    string invalid{"Are you kidding me? @\\/@"};
    if (k == 0) {
        cout << '\n';
    } else { 
        for (int i = 0; i < k; ++i) {
            values = string(5, ' ');
            int left_hand = 0;
            int left_eye = 0;
            int mouse = 0;
            int right_eye = 0;
            int right_hand = 0;
            cin >> left_hand;
            cin >> left_eye;
            cin >> mouse;
            cin >> right_eye;
            cin >> right_hand;
            if (
                left_hand > hands.size() || 
                left_hand <= 0 || 
                left_eye > eyes.size() ||
                left_eye <= 0 ||
                mouse > mouses.size() || 
                mouse <= 0 || 
                right_eye > eyes.size() ||
                right_eye <= 0 ||
                right_hand > hands.size() ||
                right_hand <= 0
            ) {
                cout << invalid << '\n';
            } else {
                cout << 
                    hands[left_hand - 1] << 
                    '(' <<
                    eyes[left_eye - 1] <<
                    mouses[mouse - 1] <<
                    eyes[right_eye - 1] <<
                    ')' << 
                    hands[right_hand - 1] << '\n';
            }
        }
    }
    return 0;
}