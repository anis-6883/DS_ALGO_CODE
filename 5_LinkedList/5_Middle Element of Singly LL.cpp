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

int getLength(Node* head)
{
	Node* temp = head;
	int length = 0;
	
	while(temp != NULL)
	{
		length++;
		temp = temp -> next;
	}
	
	return length;
}

Node* middleElement(Node* head)
{
	int mid = getLength(head) / 2;
	Node* temp = head;

	while(mid--)
		temp = temp -> next;

	return temp;
}

int main()
{
	Node* new_node = new Node(5);
	Node* head = new_node;
	Node* tail = new_node;

	// Insert At Ending...
	insertAtTail(tail, head, 10);
	insertAtTail(tail, head, 15);
	insertAtTail(tail, head, 20);
	insertAtTail(tail, head, 25);

	cout << "Middle Element: " << middleElement(head) -> data << endl; // 15
	return 0;
}