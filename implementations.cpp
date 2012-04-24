#include <cstdlib>
#include <iostream>
#include <string.h>
#include "header.h"
using namespace std;



/*************************************************************************
***                        Stack Constructor                           ***
*************************************************************************/
//constructor: sets the nodes to NULL
stack::stack() 
{
  head = NULL;
  temp = NULL;
}

/*************************************************************************
***                         Stack Destructor                           ***
*************************************************************************/
//stack destructor: deallocates the stack
stack::~stack() 
{
  while(head)
  {  
    temp = head->next;
    delete head;
    head = temp;
  }
}


/*************************************************************************
***                               Push                                 ***
*************************************************************************/
//Push function to add a word to the stack
//Returns 1 for success, 0 for failure.
int stack::push(char *wrd)
{
  if(head)      //if not empty
  {
    temp= new word;                   //allocate 
    temp->w=new char[strlen(wrd)+1];  //new memory   
    strcpy(temp->w,wrd);      //copy data
    temp->next = head;     //insert the
    head = temp;           //new node
    temp =NULL;
    return 1;
  }
  else if(!head)       //if empty
  {
    head= new word;      //allocate new memory for head
    head->w=new char[strlen(wrd)+1];
    strcpy(head->w,wrd);  //copy data
    head->next=NULL;
    return 1;
  }
  else
    return 0;
}

/*************************************************************************
***                               Pop                                  ***
*************************************************************************/
//pop function to remove the last word from the stack
//Returns 1 for success, 0 for failure.
int stack::pop()
{
  if(head)         //if not empty
  {
    temp=head->next;     //set temp to the next node
    delete head;         //delete first node
    head=temp;          //set head to temp
    temp=NULL;
    return 1;
  }
  else
    return 0;
}
    
/*************************************************************************
***                             Is Empty                               ***
*************************************************************************/
//to check if the stack is empty or not
//Returns 1 if the stack is empty, 0 if not.
int stack::isEmpty()
{
  if(head)     //if not empty
    return 0;
  else          //if empty
    return 1;    
}

/*************************************************************************
***                            Get Top                                 ***
*************************************************************************/
//gives the word word on top of the stack
//for success it returns a pointer to copy of the top node. For failure it 
//returns NULL; 
word *stack::gettop()
{
  if(head)          //if not empty
  {
    temp=new word;        //allocate new memory 
    temp->next = NULL;
    temp->w = new char[strlen(head->w)+1];
    strcpy(temp->w,head->w);  //copy data
    return temp;        //return pointer to new memory
  }
  else
    return NULL;
}

/*************************************************************************
***                        Queue Constructor                           ***
*************************************************************************/
//queue constructor: sets the nodes to NULL
queue::queue()
{
  rear = NULL;
  temp = NULL;
}

/*************************************************************************
***                        Queue Destructor                           ***
*************************************************************************/
//queue destructor: deletes the queue
queue::~queue()
{
  if(rear)
  {
    temp = rear->next;      //Turning the CLL 
    rear->next = NULL;      //into a LLL for  
    rear = temp;            //deallocation
    while(rear)
    {
      temp = rear->next;
      delete rear;
      rear = temp;    
    }
  }
}

/*************************************************************************
***                              Enqueue                               ***
*************************************************************************/
//to add a word to the queue
//Returns 1 for success, 0 for failure.
int queue::enqueue(char *wrd)
{
  if(rear)      //if not empty
  {
    temp = new word;                       //allocate 
    temp->w = new char[strlen(wrd)+1];     // memory
    strcpy(temp->w, wrd);        //copy data
    temp->next = rear->next;   //insert the
    rear->next = temp;         //new node
    rear =temp;
    return 1;

  }
  else if(!rear)   //if empty
  {
    rear=new word;                     //allocate
    rear->w=new char[strlen(wrd)+1];   //memory
    strcpy(rear->w,wrd);  //copy data
    rear->next=rear;      //set rear to the new node
    return 1;

  }  
  else
    return 0;
}


/*************************************************************************
***                             Dequeue                                ***
*************************************************************************/
//function to remove the first word from the queue
//Returns 1 for success, 0 for failure.
int queue::dequeue()
{
  if(rear->next==rear)  //if there is only one node 
  {
    delete rear;         //delete the node and
    rear =NULL;          //set it to NULL
    return 1;

  }
  else if(rear)         //otherwise delete the front node
  {
    temp=rear->next->next;  //set temp to the node next to the front node
    delete rear->next;     //delete the front node
    rear->next = temp;    //set the rear to temp
    return 1;
  }
  else
    return 0;
}

/*************************************************************************
***                         Queue Is empty                             ***
*************************************************************************/
//to check if the queue is empty or not
//Returns 1 if the queue is empty, 0 if not.
int queue::isEmpty()
{
  if(rear)       //not empty
    return 0;   
  else         //empty
    return 1;
}


/*************************************************************************
***                            Get Front                               ***
*************************************************************************/
//gives the word at the front of the queue(the first word inserted)
//for success it returns a pointer to a copy of the top node. For failure it 
//returns NULL; 
word *queue::getfront()
{
  if(rear)
  {
    temp=new word;    //creating a new node
    temp->next = NULL;
    temp->w = new char[strlen(rear->w)+1];  //allocating memory
    strcpy(temp->w,rear->next->w);          //copying data
    return temp;
  }
  else
    return NULL;
}
