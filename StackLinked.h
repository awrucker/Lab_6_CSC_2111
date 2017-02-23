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

template < class T >
T* StackLinked<T>::peek()
{
   T* item = NULL;
   //DO THIS
   if(sze != 0)
	   item = top->getItem();
   
   return item;
   
}

template < class T >
void StackLinked<T>::push(T* item)
{
   NextNode<T>* newNode = new NextNode<T>(item);
   newNode->setNext(top);
   top = newNode;
   sze++;
}

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
