#include <iostream>

using namespace std;

template <class T> class Node {

public:
	T value;
	Node* next;
	Node* prev;


	static void PrintLinkedList(Node*& head) {
		while (head != NULL)
		{
			cout << head->value << endl;
			head = head->next;
		}
	}

	static void PrintLinkedListReversedWay(Node*& foot) {
		while (foot != NULL)
		{
			cout << foot->value << endl;
			foot = foot->prev;
		}
	}

	void InsertAtBeginning(T value) {
		InsertAtBeginning(this, value);
	}

	static void InsertAtBeginning(Node*& head, T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL) 
			head->prev = newNode;

		head = newNode;
	}

	void InsertAtEnd(T value) {
		InsertAtEnd(this, value);
	}

	static void InsertAtEnd(Node*& head, T value) {
		/*
			1-Create a new node with the desired value.
			2-Traverse the list to find the last node.
			3-Set the next pointer of the last node to the new node.
			4-Set the previous pointer of the new node to the last node.
		*/
		Node* node = new Node();
		node->value = value;
		node->next = NULL;
			
		if (head == NULL)
		{
			head = node;
			return;
		}

		Node* LastNode = head;

		while (LastNode->next != NULL) {
			LastNode = LastNode->next;
		}
		LastNode->next = node;
		node->prev = LastNode;
	}

	void InsertAfter(Node* nodeToInsert, T value) {
		InsertAfter(this, nodeToInsert, value);
	}

	static void InsertAfter(Node* mainNode, Node* nodeToInsert, T value) {
		 // PREV  VAL  NEXT    PREV VAL NEXT
		Node* node = FindNode(mainNode, value);
		
		nodeToInsert->next = node->next;
		node->next = nodeToInsert;
		nodeToInsert->prev = node;

		if (node->next != NULL) {
			node->next->prev = nodeToInsert;
		}
		node->next = nodeToInsert;
	}

	static Node<int>* FindNode(Node* head, T value) {

		while (head != NULL)
		{
			if (head->value == value)
				return head;

			head = head->next;
		}
		return NULL;
	}

	static Node<int>* FindPrevNode(Node* head, T value) {

		Node* prev_Node = new Node();
		while (head != NULL)
		{
			if (head->value == value)
				return prev_Node;

			prev_Node = head;
			head = head->next;
		}
		return NULL;
	}

	void DeleteNode(T value) {
		DeleteNode(this, value);
	}

	static void DeleteNode(Node*& head, T value) {
		Node* current_node = FindNode(head, value);

		if (current_node->prev == NULL) {
			head = current_node->next;
			current_node->next = NULL;
		}
		else {
			current_node->prev->next = current_node->next;
			current_node->next->prev = current_node->prev;

			delete current_node;
		}
	}

	void DeleteFirstNode() {
		DeleteFirstNode(this);
	}

	static void DeleteFirstNode(Node*& head) {
		if (head == NULL) 
			return;

		Node* temp = head;
		head = head->next;
		if (head != NULL) 
			head->prev = NULL;
		
		delete temp;
	}

	void DeleteLastNode() {
		DeleteLastNode(this);
	}

	static void DeleteLastNode(Node*& head) {
		// prev  val  next    prev val next  null
		Node* last = head;

		while (last->next != NULL) {
			last = last->next;
		}
		head = head->prev;
		head->next = NULL;
		delete last;
	}
};