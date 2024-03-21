#include <iostream>
using namespace std;

#ifndef DLLIST_H
#define DLLIST_H

template <class T>
struct Node {
    T info;
    Node<T> *prev;
    Node<T> *next;
};

template <class T>
class DLList {
private:
    Node<T> *first;
    Node<T> *last;
    int length;
    Node<T> *start;
    Node<T> *p;
public:

    DLList(); //Constructor
    ~DLList(); //Destructor
    DLList(const DLList<T> &cList); // Copy constructor

    int getLength(); // returning length
    bool isEmpty(); // checking if the list is empty
    void insertItemFront(T item); //Inserting Item in the front
    void  insertItemBack(T item); // Inserting Items in the back
    void deleteItem(T item); //deleting the in the list
    bool searchItem(T item); //Searching the item
    void printList(); //Printing the whole list
    void destroy(); // deleting the whole list
    void copy(const DLList<T> &cList); // copying the list
    const DLList<T> & operator=(const DLList<T> &cList);

    T getDataNode();
    void startWalking();
    void walkPointer();
    bool isPointerNull();

    void printUsingIterator();

    void startWalkingBackwards();
    void walkPointerBackwards();


};
#endif 