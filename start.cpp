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
///merge kar lain
#include<iostream> 
#include <list> 
using namespace std; 
   
// a directed graph class 
class DiGraph 
{ 
    int V;    // No. of vertices 
   
    // Pointer to an array containing adjacency lists 
    list<int> *adjList;    
public: 
    DiGraph(int V);  // Constructor 
   
    // add an edge from vertex v to w
    void addEdge(int v, int w);  
   
    // BFS traversal sequence starting with s ->starting node 
    void BFS(int s);   
}; 
   
DiGraph::DiGraph(int V) 
{ 
    this->V = V; 
    adjList = new list<int>[V]; 
}
 void DiGraph::addEdge(int v, int w) 
{ 
    adjList[v].push_back(w); // Add w to v’s list. 
} 
   
void DiGraph::BFS(int s) 
{ 
    // initially none of the vertices is visited
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
   
    // queue to hold BFS traversal sequence 
    list<int> queue; 
   
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
   
    // iterator 'i' to get all adjacent vertices 
    list<int>::iterator i; 
   
    while(!queue.empty()) 
    { 
        // dequeue the vertex 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
   
        // get all adjacent vertices of popped vertex and process each if not already visited 
        for (i = adjList[s].begin(); i != adjList[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
}
// main program 
int main() 
{ 
    // create a graph 
    DiGraph dg(5); 
    dg.addEdge(0, 1); 
    dg.addEdge(0, 2); 
    dg.addEdge(0, 3);
    dg.addEdge(1, 2); 
    dg.addEdge(2, 4);
    dg.addEdge(3, 3); 
    dg.addEdge(4, 4);
   
    cout << "Breadth First Traversal for given graph (with 0 as starting node): "<<endl;
    dg.BFS(0); 
   
    return 0; 
}
