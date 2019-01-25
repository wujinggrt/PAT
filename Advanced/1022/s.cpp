#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, set<string>> titles;
    unordered_map<string, set<string>> authors;
    unordered_map<string, set<string>> keywords;
    unordered_map<string, set<string>> publishers;
    unordered_map<string, set<string>> years;
    // clear the \n
    cin.get();
    for (int32_t i = 0; i < n; ++i) {
        string id;
        getline(cin, id);
        string title;
        getline(cin, title);
        titles[title].insert(id);
        string author;
        getline(cin, author);
        authors[author].insert(id);
        string keyword;
        while (true) {
            cin >> keyword;
            keywords[keyword].insert(id);
            auto c = cin.get();
            if (c == '\n') {
                break;
            }
        }
        string publisher;
        getline(cin, publisher);
        publishers[publisher].insert(id);
        string year;
        getline(cin, year);
        years[year].insert(id);
    }
    int32_t m;
    cin >> m;
    for (int32_t i = 0; i < m; ++i) {
        int32_t method;
        scanf("%d: ", &method);
        string item;
        getline(cin, item);
        cout << method << ": "s + item << "\n";
        auto query = [&] (const auto& container) -> void {
            auto it = container.find(item);
            if (it == end(container)) {
                printf("Not Found\n");
            } else {
                for (auto& e: it->second) {
                    cout << e << "\n";
                }
            }
        };
        switch (method) {
            case 1:
                query(titles);
                break;
            case 2:
                query(authors);
                break;
            case 3:
                query(keywords);
                break;
            case 4:
                query(publishers);
                break;
            case 5:
                query(years);
                break;
        }
    }
}