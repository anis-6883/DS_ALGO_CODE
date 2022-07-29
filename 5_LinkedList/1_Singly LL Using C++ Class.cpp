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

int getLength(Node* &head)
{
	int len = 0;
	Node* temp = head;

	while(temp != NULL)
	{
		temp = temp -> next;
		len++;
	}
	return len;
}

void insertAtHead(Node* &head, int data)
{
	Node* new_node = new Node(data);
	new_node -> next = head;
	head = new_node;
}

void insertAtTail(Node* &tail, int data)
{
	Node* new_node = new Node(data);
	tail -> next = new_node;
	tail = new_node;
}

void insertAtPos(Node* &head, Node* &tail, int pos, int data)
{
	// validate the position
	if(pos > getLength(head) + 1 || pos < 0)
	{
		cout << pos << " -- Invalid Position!" << endl;
		return;
	}
	
	// insert at head
	if(pos == 1)
	{
		insertAtHead(head, data);
		return;
	}

	Node* temp = head;
	int counter = 1;

	while(counter < pos-1)
	{
		temp = temp -> next;
		counter++;
	}

	// insert at tail
	if(temp -> next == NULL)
	{
		insertAtTail(tail, data);
		return;
	}

	Node* new_node = new Node(data);
	new_node -> next = temp -> next;
	temp -> next = new_node;
}

void deleteAtHead(Node* &head)
{
	Node* temp = head;
	head = head -> next;
	delete temp; // memory free
}

void deleteAtTail(Node* &head, Node* &tail)
{
	Node* temp = head;
	Node* prev = NULL;

	while(temp -> next != NULL)
	{
		prev = temp;
		temp = temp -> next;
	}

	prev -> next = NULL;
	tail = prev;
	delete temp;
}

void deleteAtPos(Node* &head, Node* &tail, int pos)
{
	// delete at head
	if(pos == 1)
	{
		deleteAtHead(head);
		return;
	}

	Node* prev = NULL;
	Node* curr = head;
	int counter = 1;

	while(counter < pos)
	{
		prev = curr;
		curr = curr -> next;
		counter++;
	}

	// delete at tail
	if(curr -> next == NULL)
		tail = prev;
	
	prev -> next = curr -> next; 
	delete curr;
}

void display(Node* &head)
{
	Node* temp = head;

	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node* new_node = new Node(5);
	Node* head = new_node;
	Node* tail = new_node;

	// Insert At Beginning...
	insertAtHead(head, -10);
	insertAtHead(head, -15);

	// Display Linked List...
	display(head); // -15 -10 5

	// Insert At Ending...
	insertAtTail(tail, 10);
	insertAtTail(tail, 15);

	// Display Linked List...
	display(head); // -15 -10 5 10 15

	// Insert At Position...
	insertAtPos(head, tail, 3, -5);
	insertAtPos(head, tail, 1, -20);
	insertAtPos(head, tail, 8, 20);
	insertAtPos(head, tail, -1, 20);
	insertAtPos(head, tail, 10, 25);

	// Display Linked List...
	display(head); // -20 -15 -10 -5 5 10 15 20

	// Delete At Beginning...
	deleteAtHead(head);
	
	// Display Linked List...
	display(head); // -15 -10 -5 5 10 15 20

	// Delete At Ending...
	deleteAtTail(head, tail);

	// Display Linked List...
	display(head); // -15 -10 -5 5 10 15

	deleteAtPos(head, tail, 3);
	deleteAtPos(head, tail, 3);

	// Display Linked List...
	display(head); // -15 -10 10 15

	cout << "Head -> " << head->data << endl; // -15
	cout << "Tail -> " << tail->data << endl; // 15
	
	return 0;
}

