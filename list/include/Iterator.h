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
	Iterator operator++() { // �����, ������ ++ � ����� ���������, ������ ��������, �� ������ ������
		i = i->next;// ����� i �� ����� ���������� � ����������, � � ��� ��� ����� ����� ����������
		return *this;
	}
	Iterator operator++(int) {
		Node* a = i;
		i = i->next;
		return Iterator(a);
	}
	int& operator*(){ // ��� ������ �������� �����
		return i->data;
	}
	bool operator!=(Iterator a) {
		return i != a.i;
	}
	bool operator==(Iterator a) {
		return i == a.i;
	}
};

