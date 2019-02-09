#include <cstdio>
#include <iostream>
using namespace std;

struct Hogwarts {
    int32_t galleon;
    int32_t sickle;
    int32_t knut;

    Hogwarts operator+(const Hogwarts& other) const {
        Hogwarts ret;
        ret.galleon = galleon + other.galleon;
        ret.sickle = sickle + other.sickle;
        ret.knut = knut + other.knut;
        return ret;
    }
};

int main() {
    Hogwarts former;
    Hogwarts latter;
    scanf("%d.%d.%d %d.%d.%d", 
          &former.galleon,
          &former.sickle,
          &former.knut,
          &latter.galleon,
          &latter.sickle,
          &latter.knut);
    Hogwarts result = former + latter;
    if (result.knut / 29 >= 1) {
        result.sickle += 1;
    }
    result.knut %= 29;
    if (result.sickle / 17 >= 1) {
        result.galleon += 1;
    }
    result.sickle %= 17;
    printf("%d.%d.%d\n", result.galleon, result.sickle, result.knut);
}