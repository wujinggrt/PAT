#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
using namespace std;

struct Billionaire {
    int32_t age;
    int32_t net_worth;
    string name;
};

int main() {
    int32_t n;
    int32_t k;
    scanf("%d %d", &n, &k);
    vector<Billionaire> billionaires(n);
    for (auto& person: billionaires) {
        person.name.resize(8);
        scanf("%s %d %d", &person.name[0], &person.age, &person.net_worth);
    }
    auto cmp = [] (const auto& lhs, const auto& rhs) {
        return lhs.age < rhs.age;
    };
    auto cmp_worth = [] (const auto& lhs, const auto& rhs) {
        if (lhs.net_worth == rhs.net_worth) {
            if (lhs.age == rhs.age) {
                return lhs.name < rhs.name;
            } else {
                return lhs.age < rhs.age;
            }
        } else {
            return lhs.net_worth > rhs.net_worth;
        }
    };
    sort(begin(billionaires), end(billionaires), cmp_worth);
    auto printer = [] (const auto& person) {
        printf("%s %d %d\n", person.name.c_str(), person.age, person.net_worth);
    };
    for (int32_t i = 1; i <= k; ++i) {
        int32_t m;
        int32_t lower;
        int32_t upper;
        scanf("%d %d %d", &m, &lower, &upper);
        printf("Case #%d:\n", i);
        int32_t output_count = 0;
        for (const auto& person: billionaires) {
            if (person.age >= lower && person.age <= upper) {
                printer(person);
                ++output_count;
                if (output_count >= m) {
                    break;
                }
            }
        }
        if (output_count == 0) {
            cout << "None\n";
        }
        // auto iter_lower = lower_bound(begin(billionaires), end(billionaires), Billionaire{lower, 0, ""}, cmp);
        // auto iter_upper = upper_bound(begin(billionaires), end(billionaires), Billionaire{upper, 0, ""}, cmp);
        // vector<Billionaire> certain_ages(iter_upper - iter_lower);
        // copy(iter_lower, iter_upper, begin(certain_ages));
        // sort(begin(certain_ages), end(certain_ages), cmp_worth);
        // if (certain_ages.empty()) {
        //     cout << "None\n";
        // } else {
        //     // for (auto& p: certain_ages) {
        //     //     printer(p);
        //     // }
        //     for (int32_t j = 0; j < m && j < certain_ages.size(); ++j) {
        //         printf("%s %d %d\n", certain_ages[j].name.c_str(), certain_ages[j].age, certain_ages[j].net_worth);
        //     }
        // }
    }
}