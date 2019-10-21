#include <iostream>
using namespace std;
int main()
{
    int a, b, sum;
    cout << "Enter the two numbers you want to add: ";
    cin >> a >> b;
    sum = (a + b);
    cout << "The addition of " << a << " and " << b << "are: " << sum;

    return 0;
}
#include<iostream>
#include "NODE1.cpp"
#include<conio.h>
using namespace std;
									//D_List class
class D_List
{
	Node *prevNode;
	Node *nextNode;
	Node *headNode;
	Node *tailNode;
	Node *currentNode;
	Node *previousNode;
	int size;
	public:
									//constructor
	D_List()
	{
		headNode=0;
		tailNode=0;
		currentNode=0;
		size=0;
	}
									//insert functions
	void insert(int n) 
	{
		if(currentNode!=0)
		{
									//insert at end
			if(currentNode->getnextnode()==0)
			{
			Node *newNode=new Node();
			currentNode->setnextNode(newNode);
			newNode->setprevNode(headNode);
			currentNode=newNode;
			currentNode->setValue(n);
			currentNode->setnextNode(0);
			size++;		
			}
		else
									//insert at
			{
				Node *newNode=new Node();
				newNode->setnextNode(currentNode->getnextnode());
				currentNode->setnextNode(newNode);
				currentNode->getnextnode()->setprevNode(newNode);
				newNode->setprevNode(currentNode);
				currentNode=newNode;
				currentNode->setValue(n);
				size++;
			}
		}
		else
									//insert first time
		{
			Node *newNode=new Node();
			headNode=newNode;
			currentNode=newNode;
			currentNode->setValue(n);
			currentNode->setprevNode(0);
			currentNode->setnextNode(0);
			size++;
		}	
	}
									//start function
									//move to first node
	void start()
	{
		currentNode=headNode;
	}
									//end function
	void end()
	{
		Node *ptr=headNode;
		while(ptr!=NULL)
		{
			if(ptr->getnextnode()==0)
			{
				currentNode=ptr;
				tailNode=currentNode;
				break;
			}
			else
			{
				ptr=ptr->getnextnode();
			}
		}	
	}
									//move farward
	void MoveNext()
	{
		currentNode=currentNode->getnextnode();
	}
									//move backward
	void MovePrev()
	{
		currentNode=currentNode->getprevnode();
	}
									//display function
	void display()
	{
		int a;
		cout<<"......IF YOU WANT TO MOVE FARWARD PRESS 1 OR IF BACKWARD PRESS 2......"<<endl;
		cin>>a;
		if(a==1)
		{
			cout<<"......THE ELEMENTS OF THE LIST ARE......"<<endl;
			Node *ptr=headNode;
			while(ptr!=NULL)
			{
				cout<<"......THE VALUE IS  "<<ptr->getValue()<<"  AT ADDRESS  "<<ptr->getnextnode()<<"......"<<endl;
				ptr=ptr->getnextnode();
			}	
		}
		else if(a==2)
		{
			cout<<"......THE ELEMENTS OF THE LIST ARE......"<<endl;
			end();
			Node *ptr=tailNode;
			while(ptr!=NULL)
			{
			cout<<"......THE VALUE IS "<<ptr->getValue()<<"  AT ADDRESS  "<<ptr->getprevnode()<<"......"<<endl;
			ptr=ptr->getprevnode();
			}
		}
		else
		{
			cout<<"invalid input damag na kharab kar"<<endl;
		}
	}
										//get size function
	int getsize()
	{
		return size;
	}
										//delete function
	void deleteNode()
	{
		currentNode->getprevnode()->setnextNode(currentNode->getnextnode());
		currentNode->getnextnode()->setprevNode(currentNode->getprevnode());
		delete currentNode;
		currentNode=currentNode->getnextnode();
		size--;
	}
										//insert at Begin
	void insertAtBegin(int n) 
	{
	this->start();
	Node* newNode = new Node();
	headNode->setprevNode(newNode);
	newNode->setnextNode(headNode);
	newNode->setprevNode(0);
	headNode = newNode;
	currentNode = headNode;
	currentNode->setValue(n);
	size++;
	}
										//insert at end
	void insertAtEnd(int n) 
	{
	this->end();
	Node* newNode = new Node();
	currentNode->setnextNode(newNode);
	newNode->setnextNode(0);
	newNode->setprevNode(currentNode);
	currentNode = newNode;
	currentNode->setValue(n);
	size++;
	}
										//search position
	void search(int a)
   {
	int position=0;
	int p=0;
	Node *ptrr=headNode;
		while (ptrr->getnextnode()!= NULL)
		{
			if(a==ptrr->getValue())
			{
				cout<<"......THE VALUE IS  "<<ptrr->getValue()<<"  AT POSITION  "<<"......"<<position<<endl;
				p++;
				break;
			}
			else
			{
				ptrr = ptrr->getnextnode();	
				position++;
			}
		}
		if(p==0)
		{
			cout<<"......VALUE IS NOT FOUND IN THE LIST......"<<endl;
		}
	}
										//insert after node
	void insertAfter(int n,int m)
	{
		int position=0;
		Node *ptrr=headNode;
		while (ptrr->getnextnode()!= NULL)
		{
			if(n==ptrr->getValue())
			{
				cout<<"......THE VALUE  "<<m<<"  IS INSERTED AFTER  "<<n<<"......"<<endl;
				currentNode=ptrr;
				Node *newNode=new Node();
				newNode->setprevNode(currentNode);
				newNode->setnextNode(currentNode->getnextnode());
				currentNode->setnextNode(newNode);
				currentNode->getnextnode()->setprevNode(newNode);
				currentNode=newNode;
				currentNode->setValue(m);
				size++;
				break;
			}
			else
			{
				ptrr = ptrr->getnextnode();	
				position++;
			}
		}
	}
											//sum of the list members
	void sumList()
	{
		int sum=0;
		Node *pt=headNode;
		while(pt!=NULL)
		{
			sum=sum+(pt->getValue());
			pt=pt->getnextnode();
		}
		cout<<"......THE SUM OF THE LIST MEMBERS IS "<<" "<<sum<<"......"<<endl;
	}
											//update the value
	void update(int a,int b)
   {
	int pos=0;
	int p=0;
	Node *ptr=headNode;
		while (ptr->getnextnode()!= NULL)
		{
			if(a==ptr->getValue())
			{
				ptr->setValue(b);
				cout<<"......THE VALUE   "<<a<<"  IS REPLACED BY  "<<ptr->getValue()<<"......"<<endl;
				p++;
				break;
			}
			else
			{
				ptr = ptr->getnextnode();	
				pos++;
			}
		}
	if(p==0)
		{
			cout<<"......VALUE IS NOT FOUND IN THE LIST......"<<endl;
		}
	}
												//insert at positon
		void insertAtpos(int n,int m)
	{
		int position=1;
		Node *ptrr=headNode;
		while (ptrr->getnextnode()!= NULL)
		{
			if(n-1==position)
			{
				currentNode=ptrr;
				Node *newNode=new Node();
				newNode->setprevNode(currentNode);
				newNode->setnextNode(currentNode->getnextnode());
				currentNode->setnextNode(newNode);
				currentNode->getnextnode()->setprevNode(newNode);
				currentNode=newNode;
				currentNode->setValue(m);
				size++;
				cout<<"......THE POSITION YOU ENTER IS "<<n<<"  AND VALUE IS INSERTED  "<<currentNode->getValue()<<"......"<<endl;
				break;
			}
			else
			{
				ptrr = ptrr->getnextnode();	
				position++;
			}
		}
	}
											//delete node
	void deleteTheNode(int n)
	{
		int position=1;
		Node *ptrr=headNode;
		while (ptrr->getnextnode()!= NULL)
		{
			if(n==ptrr->getValue())
			{
				currentNode=ptrr;
				currentNode->getprevnode()->setnextNode(currentNode->getnextnode());
				currentNode->getnextnode()->setprevNode(currentNode->getprevnode());
				delete currentNode;
				currentNode=currentNode->getnextnode();
				cout<<".......THE NODE  "<<n<<"  IS DELETED SUCCESSFULLY......."<<endl;
				size--;
				break;
			}
			else
			{
				ptrr = ptrr->getnextnode();	
				position++;
			}
		}
	}
											//deleteNodeAt
	void deleteTheNodeAt(int n)
	{
		int position=1;
		Node *ptrr=headNode;
		while (ptrr!= NULL)
		{
			if(n==position)
			{
				currentNode=ptrr;
				currentNode->getprevnode()->setnextNode(currentNode->getnextnode());
				currentNode->getnextnode()->setprevNode(currentNode->getprevnode());
				delete currentNode;
				currentNode=currentNode->getnextnode();
				cout<<".......THE NODE  "<<n<<"  IS DELETED SUCCESSFULLY......."<<endl;
				size--;
				break;
			}
			else
			{
				ptrr = ptrr->getnextnode();	
				position++;
			}
		}
	}
};
