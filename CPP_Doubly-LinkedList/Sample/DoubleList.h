//Header file for Double_list class

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "DoubleNode.h" //Import double_node class

template <class T> //Generic template for the Double_node class
class Double_list
{
  private:
    Double_node<T> *list_head;//Node pointer pointing to the first node (or NULL if list is empty) 
    Double_node<T> *list_tail;//Node pointer pointing to the last node (or NULL if list is empty)   
    int list_size;//Number of items(nodes) contain within the list                               
  public:
    Double_list();//Default constuctor 
    Double_list(const Double_list& dl);//Copy constructor

    int size() const;//Return list_size
    bool empty() const;//Return true if list_size equal to 0, else return false
    T front() const;//Return the item stored inside the node the list_head pointer's pointing to
    T back() const;//Return the item stored inside the node the list_tail pointer's pointing to
    Double_node<T> *head() const;//Return list_head
    Double_node<T> *tail() const;//Return list_Tail
    int count(T obj) const;//Return the number of nodes storing a value equal to the argument

    void swap(Double_list *list);//Swap the contents of this list with the argument list 
    Double_list& operator = (const Double_list& rhs);//Copy the argument list to this list
    void push_front(T obj);//Add a node storing the argument to the front of the list
    void push_back(T obj);//Add a node storing the argument to the back of the list
    T pop_front();//Remove a node from the front of the list and return the data it stores
    T pop_back();//Remove a node from the back of the list and return the data it stores
    int erase(T obj);//Delete the first node (from the front) storing a value equal to the argument and return 1 if an object is found and deleted, else return 0

    void print_list();//Print the node's data inside the list from front to back
    void set_head(Double_node<T> *list_head);//Set list_head to the input list_head
    void set_tail(Double_node<T> *list_tail);//Set list_tail to the input list_tail
    void set_size(int list_size);//Set list_size to the input list_size

    ~Double_list();//Destructor              
};

// #include "DoubleListImp.h" //Import the implementation file

#endif