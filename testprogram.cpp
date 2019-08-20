/*    c++ program to implement queue using linked list     */

#include<iostream>
#include<process.h>
#include<string.h>
using namespace std;

/*     Declaration of Employee   */

struct Employee
{
	int E_Id;
	char E_Name[20];
	struct Employee *Link;
}*front,*rear;

/*      Declaration of  class Employee queue     */

class Emp_Queue
{
	public:
		Emp_Queue()
		{
			front = NULL;
			rear = NULL;
		}
		
	void Insert(int n,char name[20]);
	void Delete();
	void Display();
	/* ~Emp_Queue();
	*/
};

/*    defination of function to insert element into queue      */

void Emp_Queue::Insert(int n, char name[20])
{
	Employee *temp;
	temp=new (struct Employee);
	temp->E_Id = n;
	strcpy(temp->E_Name ,name);
	temp->Link = NULL;
	if(front == NULL)
	    front = temp;
	else
	   rear->Link = temp;
	rear = temp;    
}

/*     defination of function to delete element from queue     */

void Emp_Queue::Delete()
{
	Employee *temp;
	if( front == NULL )
	   cout<<"\n queue is underflow "<<endl;
    else
    {
    	temp = front;
    	cout<<"Element is deleted : "<<temp->E_Id<<endl;
    	cout<<"Element is deleted : "<<temp->E_Name<<endl;
    	front = front->Link;
    	delete temp;
	}
}

/*     defination of function to display the element from the queue      */

void Emp_Queue::Display()
{
	Employee *T_ptr;
	T_ptr = front;
	if( front == NULL )
	    cout<<"queue is empty "<<endl;
	
	else
	{
		cout<<"queue element "<<endl;
		while(T_ptr != NULL)
		{
			cout<<T_ptr->E_Id<<"  ";
			cout<<T_ptr->E_Name<<"  ";
			T_ptr = T_ptr->Link; 
		}
		cout<<endl;
	}
}

/*     main function : important part of program and contain menu       */

int main()
{
	Emp_Queue Eq;
	int choice,num;
	char emp_name[20];
	while(1)
	{
		cout<<"menu : \n 1 :- Insert element in queue Insert() \n 2 :- Delete element in queue Delete() \n 3 :- Display element in the queue Display() \n 4 :- Exit from the program \n";
		cout<<"Enter your choice from the menu : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: 
			    cout<<"\n enter employee id into queue : ";
			    cin>>num;
			    cout<<"\n enter employee name into queue : ";
			    cin>>emp_name;
			    Eq.Insert(num,emp_name);
			    break;
			
			case 2: 
			    Eq.Delete();
			    break;
			
			case 3: 
			    Eq.Display();
			    break;       
				
			case 4: 
			    exit(0);
				break;
			
			default:
			    cout<<"\n worng choice entered "<<endl; 
		}
		
	}
	
	return 0;
}

