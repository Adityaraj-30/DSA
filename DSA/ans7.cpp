//Ques7 - Implement a stack using Linked representation

#include <iostream>

using namespace std;

class Node{
	public: int data;
			Node* next;
};

class Stack{
	private:Node* head;
	public:Stack()
			{
				head=NULL;
			}
			void push(int data);
			int pop();
			void display();
};

void Stack::push(int data)
{
	Node* new_node=new Node();
	if(!new_node)
	{
		cout<<"OVERFLOW"<<endl;
		return;
	}
	new_node->data=data;
	new_node->next=head;
	head=new_node;
}

int Stack::pop()
{
	if(head==NULL)
	{
		cout<<"UNDERFLOW"<<endl;
		return -999;
	}
	Node* temp=head;
	head=temp->next;
	int t=temp->data;
	delete temp;
	return t;
}

void Stack::display()
{
	if(head==NULL)
		cout<<"UNDERFLOW"<<endl;
	else
	{
		Node* temp=head;
		cout<<"STACK:";
		while(temp!=NULL){
			cout<<temp->data<<"  ";
			temp=temp->next;
		}
		cout<<endl;
	}
}

int main()
{
	Stack ob;
	int ch=0;
	while(1>0)
	{
		cout<<"\n------Enter the choice------\n1) To push in stack\n2) To pop from stack\n3) To print stack\n4) To Exit Program"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:{
				cout<<"Enter number to be pushed in stack"<<endl;
				int v;
				cin>>v;
				ob.push(v);
				break;
			}
			case 2:{
				ob.pop();
				break;
			}
			case 3:{
				ob.display();
				break;
			}
			case 4:exit(0);
					break;
			default:cout<<"Wrong,choice enterred"<<endl;		
		}
	}
	return 0;
}