#ifndef LIST_H
#define LIST_H

#include <cstdlib>

/*****************************************************
 * List Class
Template Collection Class storing objects in a singly linked list

Supports the get, set, add (through +=), and remove operations

Objects must support '<' and '==' operator as they are compared and stored in increasing
order.

Note the list stores pointers to the objects and stored data is not deallocated
upon destruction
******************************************************/

/*******************************\
 * Class definition
*******************************/

template <class T>
class List
{
  template <class W>
  class Node
  {
    public:
      W* data;
      Node<W>*    next;
  };

  public:
    List();
    ~List();
    List<T>& operator=(const List<T>&);
    bool operator==(const List<T>&);
    int getSize() const;
    T* get(int) const;
    T* set(T*, int);
    T* remove(int);
    T* remove(T*);
    List<T>& operator+=(T*);
    void print() const;

  private:
    Node<T>* head;
    int size;
};

/*******************************\
 * Class implementation
*******************************/

template <class T>
List<T>::List(): head(NULL), size(0) {   }

template <class T>
List<T>::~List()
{
  Node<T>* currNode = head;
  Node<T>* nextNode;

  while(currNode != NULL){
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
List<T>& List<T>::operator=(const List<T>& list)
{
  head = list.head;
  size = list.size;
  return *(this);
}

template <class T>
bool List<T>::operator==(const List<T>& other)
{
  return (head == other.head) && (size == other.size);
}

template <class T>
int List<T>::getSize() const {  return size;  }

//retrieves the element at the ith idex in the list and returns a pointer to it
//returns NULL if the index is out of bounds, or if the list is empty
template <class T>
T* List<T>::get(int i) const
{
  Node<T>* currNode = head;

  if(i < 0 || i >= size || currNode == NULL){
    return NULL;
  }

  int count = 0;
  while(count < i && currNode != NULL){
    currNode = currNode->next;
    ++count;
  }

  if(currNode == NULL){
    throw("Internal list error: Index not found");
    return NULL;
  }
  return currNode->data;
}

//sets the element at the ith idex in the list and returns a pointer to the element
//previously stored there
//adding to the last element (at index = size) is allowed
//throws an excpetion if the index is out of bounds
template <class T>
T* List<T>::set(T* t, int i)
{
  Node<T>* currNode = head;

  if(i < 0 || i > size){
    throw("Index out of bounds!");
    return NULL;
  }

  if(i == size){
    *(this) += t;
    return NULL;
  }

  int count = 0;
  while(count < i && currNode != NULL){
    currNode = currNode->next;
    ++count;
  }

  if(currNode == NULL){
    throw("Internal list error: Index not found");
    return NULL;
  }

  T* tmp = currNode->data;

  currNode->data = t;

  return tmp;
}

//adds the element to the back of the list
template <class T>
List<T>& List<T>::operator+=(T* t)
{
  Node<T>* currNode = head;
  Node<T>* prevNode = NULL;

  Node<T>* tmpNode = new Node<T>();
  tmpNode->data = t;
  tmpNode->next = NULL;

  while(currNode != NULL){
    prevNode = currNode;
    currNode = currNode->next;
  }

  if(prevNode == NULL){
    head = tmpNode;
  }else{
    prevNode->next = tmpNode;
  }

  ++size;

  return *(this);
}

//deletes the element at the ith index in the list, and returns a pointer
//to that element
//returns NULL if the index is out of bounds, or if the list is empty
template <class T>
T* List<T>::remove(int i)
{
  Node<T>* currNode = head;
  Node<T>* prevNode = NULL;
  if(i < 0 || i >= size || currNode == NULL){
    return NULL;
  }

  int count = 0;
  while(count < i && currNode != NULL){
    prevNode = currNode;
    currNode = currNode->next;
    ++count;
  }

  if(currNode == NULL){
    throw("Internal list error: Index not found");
    return NULL;
  }

  T* tmp = currNode->data;

  if(prevNode == NULL){
    head = currNode->next;
  }else{
    prevNode->next = currNode->next;
  }

  delete currNode;

  --size;

  return tmp;
}

//deletes the specified element from the list and returns the pointer of that element
//returns NULL if no such object is found
//objects are compared using the '==' operator
template <class T>
T* List<T>::remove(T* t)
{
  Node<T>* currNode = head;
  Node<T>* prevNode = NULL;

  bool found = false;
  while(!found && currNode != NULL){
    if((*currNode->data) == (*t)){
      found = true;
    }else{
      prevNode = currNode;
      currNode = currNode->next;
    }
  }

  if(!found){
    return NULL;
  }

  T* tmp = currNode->data;

  if(prevNode == NULL){
    head = currNode->next;
  }else{
    prevNode->next = currNode->next;
  }

  delete currNode;

  --size;

  return tmp;
}

//prints the contents of the list
template <class T>
void List<T>::print() const
{
  Node<T>* currNode = head;

  while(currNode != NULL){
    cout << *(currNode->data) << endl;;
    currNode = currNode->next;
  }
}

#endif
