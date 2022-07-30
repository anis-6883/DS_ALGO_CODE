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

void insertAfterElement(Node* &tail, int element, int data)
{
	// Empty List
	if(tail == NULL)
	{
		Node* new_node = new Node(data);
		tail = new_node;
		new_node -> next = new_node;
	}
	else
	{
		// Non-Empty List (Assume Element is Present in List)
		Node* curr = tail;

		while(curr -> data != element)
			curr = curr -> next;

		Node* new_node = new Node(data);
		new_node -> next = curr -> next;
		curr -> next = new_node;
	}
}

void deleteElement(Node* &tail, int element)
{
	if(tail == NULL)
	{
		cout << "List is Empty!" << endl;
		return;
	}
	
	// Non-Empty List (Assume Element is Present in List)
	Node* prev = tail;
	Node* curr = prev -> next;

	while(curr -> data != element) {
		prev = curr;
		curr = curr -> next;
	}

	prev -> next = curr -> next;

	// 1 Node Linked List
	if(curr == prev)
		tail = NULL;
		
	// >=2 Node linked list
	else if(tail == curr )
		tail = prev;

	curr -> next = NULL;
	delete curr;
}

void display(Node* tail)
{
	if(tail == NULL)
	{
		cout << "List is Empty!" << endl;
		return;
	}
	Node* temp = tail;

	do{
		cout << tail -> data << " ";
		tail = tail -> next;
	}
	while(tail != temp);
	cout << endl;
}

int main()
{
	Node* tail = NULL;

	display(tail);
	
	insertAfterElement(tail, 0, 3);
	insertAfterElement(tail, 3, 5);
	insertAfterElement(tail, 5, 7);
	insertAfterElement(tail, 7, 9);

	display(tail); // 3 5 7 9

	insertAfterElement(tail, 5, 8);

	display(tail); // 3 5 8 7 9

	// Delete By Element
	deleteElement(tail, 7);
	deleteElement(tail, 9);

	display(tail); // 3 5 8
	
	return 0;
}