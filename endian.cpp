#include <iostream>
using namespace std;

int main() {
	unsigned short i = 0X1234;
	unsigned char *p = (unsigned char *)&i;
	if (*p == 0X12) {
		cout << "Big endian\n";
	} else {
		cout << "Little endian\n";
	}
}
