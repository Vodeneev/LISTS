#include"iostream"
#include "Iterator.h"
using namespace std;

class List
{
	Node* head;
	int size;
public:
	List(int n) {
		head = new Node; // ���������� ������ ��� ���� ���������
		size = n;
		Node* tmp = head; // ������� ��������� ��� ����
		for (int i = 0; i < n; i++) {
			Node* tmp2 = new Node; // ������� �����-�� ���������
			tmp->next = tmp2; // ������� ��� ��������
			tmp = tmp2; // ������� �� tmp2
		}
	}
	void insert(int data, Node* prev) {
		Node* a = new Node; // ������� ��������� �
		a->data = data; // �������� ���� ������
		Node* b = prev->next; // � b �� ��������� ����� ����������
		prev->next = a; // ��������� � a
		a->next = b; // a ��������� �� ���������
	}
	int Size() {
		return size;
	}
	Node* Head() {
		return head;
	}
	Iterator begin() {
		Iterator i(head);
		return i;
	}
	Iterator end() {
		int k = 0;
		Iterator i(head);
		while (k != size) {
			++i;
			k++;
		}
		return i;
	}
	void Delete(Node* i) {
		if (i == head) {
			head = head->next;
		}
		else {
			Node* k = head;
			while (i != k->next) {
				k = k->next;
			}
			k->next = i->next;
		}
		size--;
	}
	int& Getelem(Node* i) { // ��� ������ �������� �����
		return i->data;
	}
	int search(int k) {
		int i = 0;
		Node* a = head;
		Node* b = head;
		while (i < k) {
			a = a->next;
			i++;
		}
		while (a->next != NULL) {
			a = a->next;
			b = b->next;
		}
		return b->data;
	}
	int medium() {
		Node* a = head;
		Node* b = head->next;
		while (b->next != NULL) {
			a = a->next;
			b = b->next;
			if (b->next != NULL)
				b = b->next;
			else
				break;
		}
		return a->data;
	}
	friend istream& operator>>(istream& in, List& v)
	{
		Node* a = v.Head();
		while (a->next != NULL) {
			in >> a->data;
			a = a->next;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, List& v)
	{
		Node* a = v.Head();
		while (a->next != NULL) {
			out << a->data << ' ';
			a = a->next;
		}
		return out;
	}
	~List() {
		while (head != NULL) {
			Node* a = head->next;
			delete head;
			head = a;
		}
	}
};

