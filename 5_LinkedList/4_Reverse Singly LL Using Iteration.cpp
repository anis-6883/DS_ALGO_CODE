#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;

	Node(int data)
	{
		this -> data = data;
		this -> next = NULL;
	}
};

void insertAtTail(Node* &tail, Node* &head, int data)
{
	if(tail == NULL)
	{
		Node* new_node = new Node(data);
		head = new_node;
		tail = new_node;
	}
	else
	{
		Node* new_node = new Node(data);
		tail -> next = new_node;
		tail = new_node;
	}
}

void display(Node* &head)
{
	Node* temp = head;

	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

void reverseLinkedList(Node* &head, Node* &tail)
{
	tail = head;
	Node* prev = NULL;
	Node* curr = head;
	Node* forward;

	while(curr != NULL)
	{
		forward = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forward;
	}

	head = prev;
}

int main()
{
	Node* new_node = new Node(5);
	Node* head = new_node;
	Node* tail = new_node;

	// Insert At Ending...
	insertAtTail(tail, head, 10);
	insertAtTail(tail, head, 15);

	// Display Linked List...
	display(head); // 5 10 15

	reverseLinkedList(head, tail);

	// Display Linked List...
	display(head); // 15 10 5
	
	return 0;
}