#include <iostream>
using namespace std;

union A {
	uint16_t i16;
	uint8_t i8;
};

int main() {
	uint16_t i = 0X1234;
	uint8_t *p = (uint8_t *)&i;
	if (*p == 0X12) {
		cout << "Big endian\n";
	} else {
		cout << "Little endian\n";
	}
	A a;
}
