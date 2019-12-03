#include"iostream"
#include "Iterator.h"
using namespace std;

class List
{
	Node<int>* head;
	int size;
public:
	List(int n) {
		head = new Node<int>; // ���������� ������ ��� ���� ���������
		size = n;
		Node<int>* tmp = head; // ������� ��������� ��� ����
		for (int i = 0; i < n; i++) {
			Node<int>* tmp2 = new Node<int>; // ������� �����-�� ���������
			tmp->next = tmp2; // ������� ��� ��������
			tmp = tmp2; // ������� �� tmp2
		}
	}
	List(List& a) {
		size = a.Size();
		Node<int>* i = new Node<int>;
		head = i;
		Node<int>* k = a.head;
		i->data = k->data;
		while (k->next != NULL) {
			this->insert(k->next->data, i);
			k = k->next;
			i = i->next;
		}
	}
	void insert(int data, Node<int>* prev) {
		Node<int>* a = new Node<int>; // ������� ��������� �
		a->data = data; // �������� ���� ������
		Node<int>* b = prev->next; // � b �� ��������� ����� ����������
		prev->next = a; // ��������� � a
		a->next = b; // a ��������� �� ���������
		size++;
	}
	int Size() {
		return size;
	}
	Node<int>* Head() {
		return head;
	}
	Iterator begin() {
		Iterator i(head);
		return i;
	}
	Iterator end() {
		return NULL;
	}
	void Delete(Node<int>* i) {
		i = i->next;
		size--;
	}
	void pop_front() {
		head = head->next;
		size--;
	}
	void insert_front(int _data) {
		Node<int>* a = new Node<int>;
		a->data = _data;
		Node<int>* b = head;
		head = a;
		a->next = b;
		size++;
	}
	int& Getelem(Node<int>* i) { // ��� ������ �������� �����
		return i->data;
	}
	int search(int k) {
		int i = 0;
		Node<int>* a = head;
		Node<int>* b = head;
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
		Node<int>* a = head;
		Node<int>* b = head->next;
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
		Node<int>* a = v.Head();
		while (a->next != NULL) {
			in >> a->data;
			a = a->next;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, List& v)
	{
		Node<int>* a = v.Head();
		while (a->next != NULL) {
			out << a->data << ' ';
			a = a->next;
		}
		return out;
	}
	~List() {
		while (head != NULL) {
			Node<int>* a = head->next;
			delete head;
			head = a;
		}
	}
};

