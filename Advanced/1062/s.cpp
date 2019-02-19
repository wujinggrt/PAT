#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct People {
    int32_t virtue;
    int32_t talent;
    string id;
};

int main() {
    int32_t n;
    int32_t l;
    int32_t h;
    cin >> n >> l >> h;
    vector<People> peoples(n);
    for (auto& person: peoples) {
        cin >> person.id >> person.virtue >> person.talent;
    }
    peoples.erase(remove_if(begin(peoples), end(peoples), [=] (const auto& person) {
                      return person.virtue < l || person.talent < l;
                  }), 
                  end(peoples));
    vector<People> sages;
    vector<People> noblemen;
    vector<People> foolmen;
    vector<People> others;
    for (const auto& person: peoples) {
        if (person.talent >= h && person.virtue >= h) {
            sages.push_back(person);
        } else if (person.talent < h && person.virtue >= h) {
            noblemen.push_back(person);
        } else if (person.virtue >= person.talent){
            foolmen.push_back(person);
        } else {
            others.push_back(person);
        }
    }
    auto cmp = [=] (const auto& lhs, const auto& rhs) {
        if ((lhs.virtue + lhs.talent) == (rhs.virtue + rhs.talent)) {
            if (lhs.virtue != rhs.virtue) {
                return lhs.virtue > rhs.virtue;
            } else {
                return lhs.id < rhs.id;
            }
        } else {
            return (lhs.virtue + lhs.talent) > (rhs.virtue + rhs.talent);
        }
    };
    sort(begin(sages), end(sages), cmp);
    sort(begin(noblemen), end(noblemen), cmp);
    sort(begin(foolmen), end(foolmen), cmp);
    sort(begin(others), end(others), cmp);
    cout << (sages.size() + noblemen.size() + foolmen.size() + others.size()) << "\n";
    for (const auto& person: sages) {
        printf("%s %d %d\n", person.id.c_str(), person.virtue, person.talent);
    }
    for (const auto& person: noblemen) {
        printf("%s %d %d\n", person.id.c_str(), person.virtue, person.talent);
    }
    for (const auto& person: foolmen) {
        printf("%s %d %d\n", person.id.c_str(), person.virtue, person.talent);
    }
    for (const auto& person: others) {
        printf("%s %d %d\n", person.id.c_str(), person.virtue, person.talent);
    }
}