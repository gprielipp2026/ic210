#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node
{
  T data;
  Node* next;
  Node* prev;
};

template <class T>
struct DLL
{
  int length;
  Node<T>* head;
  Node<T>* tail;
};

/* Node */
template <class T>
void add2back(T data, Node<T>*& node);
template <class T>
istream& operator>>(istream& in, Node<T>*& node);
template <class T>
ostream& operator<<(ostream& out, Node<T>* node);

/* DLL */
// add a node to the back
template <class T>
void add2back(T data, DLL<T>& dll);
template <class T>
istream& operator>>(istream& in, DLL<T>& dll);
template <class T>
ostream& operator<<(ostream& out, DLL<T> dll);
template <class T>
void delete_dll(DLL<T>& dll);


// the definitions
template <class T>
void add2back(T data, Node<T>*& node)
{
  Node<T>* back = new Node<T>;
  back->data = data;

  // creating a double linked list
  // add to the tail (that's what node is)
  // link tail to new back, back to current tail
  // then set the new tail to back
  back->prev = node;
  back->next = nullptr;
  if(node != nullptr)
    node->next = back;
  node = back;


}

template <class T>
istream& operator>>(istream& in, Node<T>*& node)
{
  T data;
  in >> data;

  add2back(data, node);

  return in;
}

template <class T>
ostream& operator<<(ostream& out, Node<T>* node)
{
  out << node->data;
  return out;
}

// add a node to the back
template <class T>
void add2back(T data, DLL<T>& dll)
{
  // add the new node to the back (the tail)
  add2back(data, dll.tail);
  
  dll.length++;

  // if it's the first iteration, the head and tail will line up
  if(dll.head == nullptr)
  {
    dll.head = dll.tail;
  }

}
  
template <class T>
istream& operator>>(istream& in, DLL<T>& dll)
{
  // add the new node to the back (the tail)
  if(in >> dll.tail)
    dll.length++;

  // if it's the first iteration, the head and tail will line up
  if(dll.head == nullptr)
  {
    dll.head = dll.tail;
  }

  return in;
}

template <class T>
ostream& operator<<(ostream& out, DLL<T> dll)
{
  // loop through each node and print it out
  Node<T>* temp = dll.head;
  for(int i = 0; i < dll.length; i++)
  {
    if(temp == nullptr)
    {
      cerr << i << ":\t" << temp << endl;
      exit(1);
    }
    out << temp << " ";
    temp = temp->next;
  }
  return out;  
}

template <class T>
void delete_dll(DLL<T>& dll)
{
  // loop through each node and delete it
  Node<T>* temp = dll.head;
  while(temp != nullptr)
  {
    temp = dll.head->next;
    delete dll.head;
    dll.head = temp;
  }
  dll.head = nullptr;
  dll.tail = nullptr;
  dll.length = 0;
}

