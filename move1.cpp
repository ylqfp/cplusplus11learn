#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct A {
	string s;
	A() : s("test"){}
	A(const A& o) : s(o.s) { cout<<"Move not use.\n"; }
	A(A&& o) noexcept : s(move(o.s)) {}
};

A f(A a) {
	return a;
}

int main() {
	cout << "Trying to move A" <<endl;
	A a1 = f(A());
	A a2 = move(a1);
	return 0;
}
