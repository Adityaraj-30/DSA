/*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the singly linked list
(ii) Insert an element x at  position in the singly linked list
(iii) Remove an element from the beginning of the singly linked list
(iv) Remove an element from  position in the singly linked list.
(v) Search for an element x in the singly linked list and return its pointer
(vi) Concatenate two singly linked lists
*/

#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};
void insertStart(Node **head, int data)
{
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}
void insert(Node *prev_node, int data)
{
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
int removeStart(Node **head)
{
	Node *temp = *head;
	*head = temp->next;
	int t = temp->data;
	delete temp;
	return t;
}
void remove(Node **head, int data)
{
	Node *temp = *head;
	Node *prev_node = NULL;
	while (temp != NULL && temp->data != data)
	{
		prev_node = temp;
		temp = temp->next;
	}
	prev_node->next = temp->next;
	delete temp;
}
Node *search(Node **head, int data)
{
	Node *temp = *head;
	while (temp != NULL)
	{
		if (temp->data == data)
			return temp;
		temp = temp->next;
	}
	return NULL;
}
Node *concat(Node **head1, Node **head2)
{
	if (*head1 == NULL)
		return *head2;
	else if (*head2 == NULL)
		return *head1;
	else
	{
		Node *temp = *head1;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = *head2;
		return *head1;
	}
}
void display(Node *n)
{
	while (n != NULL)
	{
		cout << n->data << "  ";
		n = n->next;
	}
}

int main()
{
	int ch, runAgain = 1;
	Node *head = NULL;
	while (runAgain == 1)
	{
		cout << "\n------Enter the choice------\n1) To insert data at start of Linked List\n2) To insert data in a position in Linked List\n3) To delete data from start of Linked List\n4) To delete data from a position in Linked List\n5) To search data in Linked List\n6) To concat two Linked Lists" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "\n------Enter data to be enterred at start" << endl;
			int data;
			cin >> data;
			insertStart(&head, data);
			cout << "\n------Linked-List Now:--->" << endl;
			display(head);
			break;
		}
		case 2:
		{
			cout << "\n------Enter the i'th position(starting from 1) where data has to be enterred" << endl;
			int i, count = 0, data;
			cin >> i;
			Node *temp = head;
			Node *prev = NULL;
			while (temp != NULL)
			{
				count++;
				if (i <= count + 1)
				{
					prev = temp;
					cout << "\n------Enter the data--->" << endl;
					cin >> data;
					insert(prev, data);
					cout << "\n------Linked-List Now:--->" << endl;
					display(head);
					break;
				}
				temp = temp->next;
			}
			if (i == 1)
				cout << "You are trying to enter data at start. Please use prior option to insert at start" << endl;
			if (i > count + 1)
				cout << "\n------Linked List size not enough------" << endl;
			break;
		}
		case 3:
		{
			int removedData = removeStart(&head);
			cout << "------Data Removed from start of Linked-List:" << removedData << endl;
			cout << "\n------Linked-List Now:--->" << endl;
			display(head);
			break;
		}
		case 4:
		{
			cout << "\n------Enter the data to be deleted------" << endl;
			int data;
			cin >> data;
			remove(&head, data);
			cout << "\n------Linked-List Now:--->" << endl;
			display(head);
			break;
		}
		case 5:
		{
			cout << "\n------Enter the data to be searched" << endl;
			int data;
			cin >> data;
			Node *temp = search(&head, data);
			if (temp == NULL)
				cout << "------Data not found------" << endl;
			else
				cout << "------Data Found at pointer:--->" << temp << endl;
			break;
		}
		case 6:
		{
			Node *head1 = NULL;
			int data, temporary = 1;
			while (temporary == 1)
			{
				cout << "\n------Enter data to be enterred in second Linked-List------" << endl;
				cin >> data;
				insertStart(&head1, data);
				cout << "To continue enterring data press 1, else press 0" << endl;
				cin >> temporary;
			}
			Node *merged = concat(&head, &head1);
			cout << "\n------Merged Linked-List:--->" << endl;
			display(merged);
			break;
		}
		}
		cout << "\nEnter 1 to continue,0 to exit" << endl;
		cin >> runAgain;
	}
	return 1;
}