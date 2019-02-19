#include <memory>
#include <iostream>
using namespace std;

struct A {
    A() {
        cout << __func__ << "\n";
    }

    ~A() {
        cout << __func__ << "\n";
    }
};

int main(){
    unique_ptr<A> up1 = make_unique<A>();
    cout << __LINE__ << "\n";
    unique_ptr<A> up2(std::move(up1));
    cout << __LINE__ << "\n";
    cout << (up1 == nullptr) << "\n";
    cout << __LINE__ << "\n";
    unique_ptr<A> up3 = nullptr;
    cout << __LINE__ << "\n";
    up3 = std::move(up2); 
    cout << __LINE__ << "\n";
}