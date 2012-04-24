#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;


struct word
{
   char *w;      // a pointer to a word
   word *next;   // node pointer to next node
};

class stack
{
  public:

    //constructor: sets the nodes to NULL
    stack(); 
    
    //stack destructor: deallocates the stack
    ~stack(); 

    //Push function to add a word to the stack
    int push(char *word);

    //pop function to remove the last word from the stack
    int pop();
    
    //to check if the stack is empty or not
    int isEmpty();

    //returns a pointer to copy of the word on top of the stack
    word *gettop();

   private:
    word *head;  //pointer to first node
    word *temp;  //a temorary pointer
};


class queue
{
  public:

    //queue constructor: sets the nodes to NULL
    queue();

    //queue constructor: deallocates the queue
    ~queue(); 

    //to add a word to the queue
    int enqueue(char *word);

    //function to remove the first word from the queue
    int dequeue();

   //to check if the stack is empty or not
    int isEmpty(); 

    //returns a pointer to a copy of the word that was first inserted into the queue
    word *getfront();

  private:
    word *rear;  //pointer to the last added node
    word *temp;  //a temorary pointer
};

