//Header file for Double_node class

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <class T> //Generic template for the Double_node class
class Double_node
{
  private:
    T data;//Generic data type       
    Double_node<T> *next;//Node pointer pointing to the next node 
    Double_node<T> *prev;//Node pointer pointing to the previous node     

  public:
    Double_node(T data);//constructor

    T getData();//Return data
    Double_node<T> *getNext();//Return next
    Double_node<T> *getPrev();//Return prev
    
    void setData(T data);//Set data to the input data
    void setNext(Double_node<T> *next);//Set next to the input next
    void setPrev(Double_node<T> *prev);//Set prev to the input prev

    ~Double_node();//Destructor   
};

// #include "DoubleNodeImp.h" //Import the implementation file

#endif