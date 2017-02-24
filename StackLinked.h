/*
	Jeremiah Payne & Adam Rucker
	2/23/2017
	Lab 6/ StackLinked Maze Lab
*/	
#if !defined (STACKLINKED_H)
#define STACKLINKED_H

#include "NextNode.h"

template < class T >
class StackLinked
{
   private:
      NextNode<T>* top;
      int sze;  // number of items in the stack

   public:
      StackLinked();
      ~StackLinked();
      bool isEmpty();
      int size();
      void popAll();
      T* pop();
      void push(T* item);
      T* peek();
};

template < class T >
StackLinked<T>::StackLinked()
{
   top = NULL;
   sze = 0;
}

template < class T >
StackLinked<T>::~StackLinked()
{
   popAll();
}

template < class T >
bool StackLinked<T>::isEmpty()
{
   return sze == 0;
}

template < class T >
int StackLinked<T>::size()
{
   return sze;
}

template < class T >
void StackLinked<T>::popAll()
{
   //loop over the stack, deleting the nodes
   //the actual items are not deleted
   if (sze == 0) return;

   NextNode<T>* curr = top;
   NextNode<T>* prev = NULL;
   while (curr != NULL)
   {
      prev = curr;
      curr = curr->getNext();
      prev->setNext(NULL);
      delete prev;
   }
}

//Pre: 	We have a list and we need to get an item from it, but we don't want to remove it 
//Post:	We got the item from the list and are returning it 

template < class T >
T* StackLinked<T>::peek()
{
   T* item = NULL;
   //DO THIS
   if(sze != 0)
	   item = top->getItem();
   
   return item;
   
}

//Pre:	We receive an item of type <T>* 
//Post:	We have a new item added to the stack and increment the size

template < class T >
void StackLinked<T>::push(T* item)
{
   NextNode<T>* newNode = new NextNode<T>(item);
   newNode->setNext(top);
   top = newNode;
   sze++;
}

//Pre:	We get our list 
//Post:	We remove an item from the list and decrement the size

template < class T >
T* StackLinked<T>::pop()
{
	T* item = NULL;
   if (sze == 0) 
	   return item;//I changed from return NULL to return item just for consistancy should not change the outcome.
   
   NextNode<T>* current = top;
   
   item = top->getItem();
   top = current->getNext();
   current->setNext(NULL);
   delete current;
   sze--;
   return item;
}

#endif
