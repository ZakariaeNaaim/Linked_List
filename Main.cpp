
#include <iostream>
#include "clsDoublyLinkedList.h"

using namespace std;


void main() {


	/*Node<int>* node1 = new Node<int>();
	node1->value = 1;

	Node<int>* node2 = new Node<int>();
	node2->prev = node1;
	node2->value = 2;

	Node<int>* node3 = new Node<int>();
	node3->prev = node2;
	node3->value = 3;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;*/

	Node<int>* head = NULL;

	Node<int>* node2 = new Node<int>();
	node2->value = 99;


	Node<int>::InsertAtBeginning(head,1);
	Node<int>::InsertAtBeginning(head,2);
	Node<int>::InsertAtBeginning(head,3);
	Node<int>::InsertAtBeginning(head,4);
	Node<int>::DeleteFirstNode(head);

	Node<int>::PrintLinkedListReversedWay(head);
	

	/*Node<int>::InsertAtEnd(head, 1);
	Node<int>::InsertAtEnd(head, 2);
	Node<int>::InsertAtEnd(head, 3);
	Node<int>::InsertAtEnd(head, 4);

	Node<int>::DeleteLastNode(head);

	*/

}