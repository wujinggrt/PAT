#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Person {
    int32_t h;
    int32_t m;
    int32_t s;
    int32_t lasting;
    int32_t total;

    Person(int32_t ah, int32_t am, int32_t as, int32_t al)
        : h{ah}, m{am}, s{as}, lasting{al * 60} {
        total = h * 3600 + m * 60 + s;
    }
};

struct Window {
    int32_t total;

    Window(int32_t t) : total{t} {}
};

auto cmp_person = [] (Person& l, Person& r) {
    return l.total > r.total;
};

auto cmp_window = [] (Window& l, Window& r) {
    return l.total > r.total;
};

using window_queue = priority_queue<
                                    Window, 
                                    vector<Window>, 
                                    decltype(cmp_window)>;

using person_queue = priority_queue<
                                    Person, 
                                    vector<Person>, 
                                    decltype(cmp_person)>;

int main() {
    const int32_t start_time = 8 * 3600;
    const int32_t end_time = 17 * 3600 + 1;
    person_queue persons(cmp_person);
    window_queue windows(cmp_window);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        windows.push(Window{start_time});
    }
    int h, m, s, l;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d%d", &h, &m, &s, &l);
        persons.push(Person{h, m, s, l});
    }
    int32_t cnt = 0;
    int32_t wait_total = 0;
    while (!persons.empty()) {
        // choosing person
        auto p = persons.top();
        persons.pop();
        if (p.total >= end_time) {
            break;
        }
        ++cnt;
        // choosing window
        auto w = windows.top();
        windows.pop();
        if (p.total < w.total) {
            wait_total += w.total - p.total;
            w.total += p.lasting;
        } else {
            // 在窗口空闲的时候来的
            w.total = p.total + p.lasting;
        }
        windows.push(w);
    }
    printf("%.1f\n", wait_total / (cnt * 60.));
}