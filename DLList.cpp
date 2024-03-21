#include "DLList.h"

template <class T>
DLList<T>::DLList() {
    first = NULL;
    last = NULL;
    length = 0;
}
template <class T>
DLList<T>::~DLList() {
    destroy();
}

template <class T>
DLList<T>::DLList(const DLList<T> &cList) {
    copy(cList);
}

template <class T>
int DLList<T>::getLength() {
    return length;
}

template <class T>
bool DLList<T>::isEmpty() {
    return first==NULL;
}

template <class T>
void DLList<T>::insertItemFront(T item) {
    length++;

    Node<T> *temp = new Node<T>;
    temp->info = item;

    if(first==NULL) {
        temp->next = NULL;
        temp->prev = NULL;
        first = temp;
        last = temp;
    }

    else {
        Node<T> *q = first;

        temp->next = q; // Connect temp to the current first node
        temp->prev = NULL; // Since it's the new first node, prev should be NULL
        q->prev = temp; // Update the previous pointer of the current first node
        first = temp; // Update the first pointer
    }
}

template <class T>
void DLList<T>::insertItemBack(T item) { 
    length++;

    Node<T>* temp = new Node<T>;
    temp->info = item;

    if(last == NULL) {
        //If the list is empty
        temp->next = NULL;
        temp->prev = NULL;
        first = temp;
        last = temp;
    }
    
    else {
        //if the list is not empty insertng at the end
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}


template <class T>
void DLList<T>::deleteItem(T item) {
    if (first == NULL) {
        cout << "The list is empty.\n";
    } 
    else {
        Node<T> *p = first;
        Node<T> *trail = NULL;

        // Special case: item is at the beginning
        if (item == first->info) {
            first = first->next; // Move first to next node
            delete p; // Delete old first node
            length--;
            if (first != NULL) { // If list is not empty, update prev of new first node
                first->prev = NULL;
            } 
            else {
                last = NULL; // If list is empty, update last pointer
            }
        } 
        else {
            // Search for the item (p points to the item, trail lags behind)
            while (p != NULL && p->info != item) {
                trail = p;
                p = p->next;
            }

            // Item found and it's not the last item
            if (p != NULL) {
                trail->next = p->next; // Link previous node to next node
                if (p->next != NULL) {
                    p->next->prev = trail; // Update prev of next node, if it exists
                } 
                else {
                    last = trail; // If deleting last node, update last pointer
                }
                delete p; // Delete the node
                length--;
            } 
            else {
                cout << "The item is not on the list.\n";
            }
        }
    }
}


template <class T>
bool DLList<T>::searchItem(T item) {
    Node<T> *p = first;
    while(p != NULL) {
        if(p->info ==item) {
            return true;
        }
        p = p->next;
    }
    return false;
}

template <class T>
void DLList<T>::printList() {
    if(first == NULL) {
        cout << "The list is empty.\n";
    }
    else {
        Node<T> *p = first;
        while(p != NULL) {
            cout << p->info << endl;
            p = p->next;
        }
    }
}

template <class T>
void DLList<T>::destroy() {
    Node<T> *p;
    while (first != NULL) {
        p = first;
        first = first->next;
        if (first != NULL) {
            first->prev = NULL; // Explicitly sever the backward link
        }
        delete p;
    }
    last = NULL;
    length = 0;
}



template <class T>
void DLList<T>::copy(const DLList<T> &cList) {
    if (cList.first == NULL) {
        first = NULL;
        last = NULL;
        length = 0;
    }
    else {
        // Copy the first node
        first = new Node<T>;
        first->info = cList.first->info;
        first->prev = NULL; // First node's prev is always NULL

        Node<T>* newNode = first; // Used for the new list
        Node<T>* originalNode = cList.first->next; // Used to traverse the original list

        // Copy the rest of the nodes
        while (originalNode != NULL) {
            newNode->next = new Node<T>; // Create a new node for newNode->next
            newNode->next->info = originalNode->info;
            newNode->next->prev = newNode; // Set the prev of the new node to newNode

            newNode = newNode->next; // Move to the next node in the new list
            originalNode = originalNode->next; // Move to the next node in the original list
        }

        newNode->next = NULL; // Last node's next is always NULL
        last = newNode; // Update last to the last node created
        length = cList.length; // Copy the length
    }
}

template <class T>
const DLList<T> & DLList<T>::operator=(const DLList<T> &cList) {
    if(this != &cList) {
        
        destroy();
        copy(cList);
    }
    return *this;
}

template <class T>
T DLList<T>::getDataNode() {
    return p->info;
}

template <class T>
void DLList<T>::startWalking() {
    p = first;
}

template <class T>
void DLList<T>::walkPointer() {
    if (p != NULL) {  
        p = p->next;
    }
}

template <class T>
bool DLList<T>::isPointerNull() {
    return p == NULL;
}

template <class T>
void DLList<T>::startWalkingBackwards() {
    if (p == NULL) {
        p = last;
    }
}

template <class T>
void DLList<T>::walkPointerBackwards() {
    if (p != NULL) {
        p = p->prev;
    }
}
