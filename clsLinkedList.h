#include <iostream>

using namespace std;

template <class T> class Node {

public:
	T value;
	Node* next;


	static void PrintLinkedList(Node*& head) {
		while (head != NULL)
		{
			cout << head->value << endl;
			head = head->next;
		}
	}

	void InsertAtBeginning(T value) {
		InsertAtBeginning(this, value);
	}

	static void InsertAtBeginning(Node*& head, T value) {
		Node* node = new Node();

		node->value = value;
		node->next = head;
		head = node;
	}

	void InsertAtEnd(T value) {
		InsertAtEnd(this, value);
	}

	static void InsertAtEnd(Node*& head, T value) {
		// head  ->  1 | next  -> (2 | next)    Null
		Node* node = new Node();
		node->value = value;

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
	}

	void InsertAfter(Node* nodeToInsert, T value) {
		InsertAfter(this, nodeToInsert, value);
	}

	static void InsertAfter(Node* mainNode, Node* nodeToInsert, T value) {

		Node* node = FindNode(mainNode, value);

		nodeToInsert->next = node->next;
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
		Node* prev_node = FindPrevNode(head, value);

		if (prev_node->next == NULL) {
			head = current_node->next;
			current_node->next = NULL;
		}
		else
			prev_node->next = current_node->next;
	}

	void DeleteFirstNode() {
		DeleteFirstNode(this);
	}

	static void DeleteFirstNode(Node*& head) {
		Node* current = head;
		head = current->next;
		delete current;
	}

	void DeleteLastNode() {
		DeleteLastNode(this);
	}

	static void DeleteLastNode(Node*& head) {

		Node* last = head;
		Node* prev = NULL;

		while (last->next != NULL) {
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		delete last;
	}
};