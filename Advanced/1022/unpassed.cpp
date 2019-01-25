#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Book {
    string id;
    string title;
    string author;
    string keywords;
    string publisher;
    string publish_year;
};

int main() {
    int32_t n;
    cin >> n;
    vector<Book> books(n);
    cin.get();
    for (auto& e: books) {
        getline(cin, e.id);
        getline(cin, e.title);
        getline(cin, e.author);
        getline(cin, e.keywords);
        getline(cin, e.publisher);
        getline(cin, e.publish_year);
    }
    sort(begin(books), end(books), [] (auto& l, auto& r) {
        return l.id < r.id;
    });
    int32_t m;
    cin >> m;
    for (int32_t i = 0; i < m; ++i) {
        int32_t indicator;
        scanf("%d: ", &indicator);
        string item;
        getline(cin, item);
        cout << indicator << ": "s + item << "\n";
        vector<string> ids;
        auto it = begin(books);
        if (indicator == 1) {
            while (it != end(books)) {
                it = find_if(it, end(books), [&] (auto& e) {
                    return e.title == item;
                });
                if (it != end(books)) {
                    ids.push_back(it->id);
                    ++it;
                } else {
                    break;
                }
            }
        } else if (indicator == 2) {
            while (it != end(books)) {
                it = find_if(it, end(books), [&] (auto& e) {
                    return e.author == item;
                });
                if (it != end(books)) {
                    ids.push_back(it->id);
                    ++it;
                } else {
                    break;
                }
            }
        } else if (indicator == 3) {
            while (it != end(books)) {
                it = find_if(it, end(books), [&] (auto& e) {
                    auto pos = it->keywords.find(item);
                    if (pos == string::npos) {
                        return false;
                    } else {
                        return true;
                    }
                });
                if (it != end(books)) {
                    ids.push_back(it->id);
                    ++it;
                } else {
                    break;
                }
            }
        } else if (indicator == 4) {
            while (it != end(books)) {
                it = find_if(it, end(books), [&] (auto& e) {
                    return e.publisher == item;
                });
                if (it != end(books)) {
                    ids.push_back(it->id);
                    ++it;
                } else {
                    break;
                }
            }
        } else if (indicator == 5) {
            while (it != end(books)) {
                it = find_if(it, end(books), [&] (auto& e) {
                    return e.publish_year == item;
                });
                if (it != end(books)) {
                    ids.push_back(it->id);
                    ++it;
                } else {
                    break;
                }
            }
        }
        if (ids.empty()) {
            cout << "Not Found\n";
        } else {
            for (auto& e: ids) {
                cout << e << "\n";
            }
        }
    }
}