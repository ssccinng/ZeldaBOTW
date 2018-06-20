#include <string>
#include <iostream>
#include <sstream>

using namespace std;
template <typename T1, typename T2>
string dirc(T1 a, T2 b) {
	ostringstream A;
	A << a << b;
	return A.str();
}