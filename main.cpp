#include <iostream>
using namespace std;
#include "DLList.cpp"


int printMenu() {
    int choice;
    cout << endl;
    cout << "1: Add an item to the list in the front." << endl;
    cout << "2: Add an item to the list in the back." << endl;
    cout << "3: Delete an item from the list." << endl;
    cout << "4: Print the list." << endl;
    cout << "5: Search the list for a given item" << endl;
    cout << "6: Return the number of the items in the list" << endl;
    cout << "7: Iterator the list." << endl;
    cout << "8: Quit" << endl;
    cin >> choice;
    return choice;
}


void insertListItemAtFront(DLList<int>&dl) {
    int num;
    cout << "\nEnter the number to insert at the front: "; 
    cin >> num;
    dl.insertItemFront(num);
    cout <<"\nThe number has been inserted at the front.";

}

void insertListItemAtBack(DLList<int>&dl) {
    int num;
    cout << "\nEnter the number to insert at the end: ";
    cin >> num;
    dl.insertItemBack(num);
    cout <<"\nThe number has been inserted at the end.";

}

void deleteListItem(DLList<int> &dl) {
    int num;
    cout <<"\nEnter the number to delete: ";
    cin >> num;
    if(dl.searchItem(num)) {
        dl.deleteItem(num);
        cout <<"\nThe number has been deleted." << endl;
    }
    else {
        cout <<"\nThe number is not in the list" << endl;
    }
}

void searchListItem(DLList<int> &dl) {
    int num;
    cout <<"\nEnter the number to search for: ";
    cin >> num;

    if(dl.searchItem(num)) {
        cout <<"\nThe number is in the list." << endl;
    }
    else {
        cout <<"\nThe number is not in the list." << endl;
    }
}

void iterateList(DLList<int>& dl) {
    char direction;
    cout << "Iteration started. Use 'f' to move forward, 'b' to move backward, 'q' to quit iteration." << endl;

    // Assume we start by moving forward
    cout << "Enter direction ('f' for forward, 'b' for backward): ";
    cin >> direction;

    if (direction == 'f') {
        dl.startWalking();
    } 
    else if (direction == 'b') {
        dl.startWalkingBackwards();
    }

    while (direction != 'q') { // Continue until 'q' is entered
        if (dl.isPointerNull()) {
            // If the iteration has reached an end or the beginning
            if (direction == 'f') {
                cout << "You've reached the end. You can only iterate backwards now." << endl;
                direction = 'b'; // Force change direction to backward
                dl.startWalkingBackwards(); // Prepare for walking backwards
            } 
            else if (direction == 'b') {
                cout << "You've reached the beginning. You can only iterate forwards now." << endl;
                direction = 'f'; // Force change direction to forward
                dl.startWalking(); // Prepare for walking forwards
            }
        } 
        else {
            // Print current item
            cout << "Current Item: " << dl.getDataNode() << endl;
            cout << "Enter next action ('f' for forward, 'b' for backward, 'q' to quit): ";
            cin >> direction;

            if (direction == 'f') {
                dl.walkPointer();
            } 
            else if (direction == 'b') {
                dl.walkPointerBackwards();
            }
        }
    }

    cout << "Quitting iteration." << endl;
}





int main() {
    DLList<int> dl;
    int choice;

    cout << "\nPlease enter the number of your choice." << endl;
    choice = printMenu();
    while(choice != 8) { // Update to 8 for the quit option

        switch(choice) {
            case 1: insertListItemAtFront(dl);
                break;
            case 2: insertListItemAtBack(dl);
                break;
            case 3: deleteListItem(dl);
                break;
            case 4: dl.printList();
                break;
            case 5: searchListItem(dl);
                break;
            case 6: cout << "\nThe list contains " << dl.getLength() << " items." << endl;
                break;
            case 7: iterateList(dl); // New case for printing using iterator
                break;
            default: cout << "\nThe number you entered is incorrect. Please choose the correct in choices and re-enter." << endl;
                break;
        }
        choice = printMenu();
    }

    DLList<int> dl2(dl); // Demonstrating the copy constructor
    cout << "\nPrinting a new list with the same values as the old list \n";
    dl2.printList();
    cout << "Exiting the program. Goodbye!" << endl;
}
