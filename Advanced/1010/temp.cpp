#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "3a";
	cout << stoi(s, nullptr, 16) << "\n";
}
