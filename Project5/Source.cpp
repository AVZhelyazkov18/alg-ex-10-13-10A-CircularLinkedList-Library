#include <iostream>
using namespace std;

struct NODE {
	int data;
	NODE* next;
};

NODE* insertNode(NODE* head, int n) {
	NODE* newNode = new NODE;
	newNode->data = n;
	newNode->next = head;
	head = newNode;
	return head;
}

NODE* prepend(NODE* head, int n) {
	NODE* newNode = new NODE;
	newNode->data = n;
	newNode->next = head;
	head = newNode;
	return head;
}

NODE* append(NODE* head, int n) {
	NODE* newNode = new NODE;
	newNode->data = n;
	newNode->next = NULL;
	NODE* temp = head;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = newNode;
			head = temp;
			return head;
		}
	}
	head = temp;
	return head;
}

NODE* insertAfter(NODE* head, int num, int n) {
	if (head == NULL)
	{
		return 0;
	}
	if (head->data == num)
	{
		NODE* newNode = new NODE;
		newNode->data = n;
		newNode->next = head->next;
		head->next = newNode;
		return newNode;
	}
	else
	{
		return insertAfter(head->next, num, n);
	}
}

void displayList(NODE* head) {
	NODE* temp = head;
	while (temp) {
		cout << temp->next;
		temp = temp->next;
	}
	cout << endl;
}

void deleteNode(NODE* &head, int del) {
	NODE* temp = head;
	while (temp != NULL) {
		if (temp->data == del) {
			temp->data = NULL;
			head = temp;
		} else {
			temp = temp->next;
		}
	}
}

void deleteList(NODE* &head) {
	head = NULL;
}

int main() {
	NODE* tail = NULL;
	tail = insertNode(tail, 30);
	tail = prepend(tail, 20);
	tail = prepend(tail, 10);
	tail = append(tail, 40);
	tail = append(tail, 60);
	tail = insertAfter(tail, 50, 40);
	cout << "The circular linked list created is as follows:" << endl;
	int key = 60;
	displayList(tail);
	deleteNode(tail, key);
	cout << "The corcular list after deleting " << key << " is:" << endl;
	displayList(tail);
	deleteList(tail);
}