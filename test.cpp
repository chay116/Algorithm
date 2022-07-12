#include <iostream>

using namespace std;
int main() {
	initializer_list<double> a = {1, 2, 3, 'a'};
	cout << a.begin() <<  a.end() << endl;
	for (auto as : a) {
		cout << as;
	}
	cout << endl;
}