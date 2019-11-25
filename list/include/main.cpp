#include"List.h"

int main() {
	List a(5);
	Iterator i = a.begin();
	cin >> a;
	cout << a;
	cout << endl;
	cout << endl;
	cout << a.medium();
	cout << a.search(2);
}