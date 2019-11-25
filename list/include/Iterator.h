#include "iostream"
#pragma once
using namespace std;
struct Node {
	int data = 0;
	Node* next = 0;
};
class Iterator
{
	Node* i;
public:
	Iterator() {
		i = NULL;
	}
	Iterator(Node* a){
		i = a;
	}
	Iterator operator++() { // слева, делает ++ и возвр результат, справа прибавит, но вернет старое
		i = i->next;// через i мы можем обратиться к квадратику, а в нем уже лежит адрес следующего
		return *this;
	}
	Iterator operator++(int) {
		Node* a = i;
		i = i->next;
		return Iterator(a);
	}
	int& operator*(){ // без ссылки вернется копия
		return i->data;
	}
	bool operator!=(Iterator a) {
		return i != a.i;
	}
	bool operator==(Iterator a) {
		return i == a.i;
	}
};

