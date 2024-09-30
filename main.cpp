#include "Question1.h"
#include "Question2.h"
#include <iostream>
using namespace std;

int main() {
    try {
        // PART 1 
  
        // Create a Single_Linked_List of strings
        Single_Linked_List<string> myList;

        // Check if the list is empty
        if (myList.empty())
            cout << "The list is currently empty." << endl;

        // Pushing elements to the front of the list
        myList.push_front("Sam");
        cout << "\nUpdated List: " << endl;
        myList.printList();

        myList.push_front("James");

        cout << "\nUpdated List: " << endl;
        myList.printList();

        // Pushing elements to the back of the list
        myList.push_back("Sara");
        cout << "\nUpdated List: " << endl;
        myList.printList();

        myList.push_back("Alice");
        cout << "\nUpdated List: " << endl;
        myList.printList();

        // Removing the element at the front of the list
        myList.pop_front();
        cout << "\nUpdated List: " << endl;
        myList.printList();

        // Removing the element at the back of the list
        myList.pop_back();
        cout << "\nUpdated List: " << endl;
        myList.printList();

        // Inserting elements at specific positions
        myList.insert(1, "Henry");
        myList.insert(1, "Theo");

        cout << "\nUpdated List: " << endl;
        myList.printList();

        // Trying to insert an element out of bounds
        // myList.insert(5, "Olivia");

        cout << "\nUpdated List: " << endl;
        myList.printList();

        // Removing an element
        if (myList.remove(1))
            cout << "Given element removed successfully.";
        else
            cout << "Unable to remove provided element";

        cout << "\nUpdated List: " << endl;
        myList.printList();

        // Accessing Front and Back element
        cout << "\nFirst element: " << myList.front() << endl;
        cout << "Last element: " << myList.back() << endl;
        
        // Finding an element
        int saraIndex = myList.find("Sara");
        cout << "Sara is at index " << saraIndex << endl;

        // PART 2
        // Create a stack
        
        Vector_Based_Stack myStack;

        // Check if the list is empty
        if (myStack.empty())
            cout << "\nThe stack is currently empty." << endl;

        // Push elements on to the stack
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        myStack.push(40);
        myStack.push(50);
        myStack.push(60);

        cout << "\nUpdated Stack: " << endl;
        myStack.printStack();

        // Pop top element
        myStack.pop();

        cout << "\nUpdated Stack: " << endl;
        myStack.printStack();

        // Access top element

        cout << "\nTop Element: " << myStack.top() << endl;

        // Print the size of the stack
        cout << "\nThe size of the stack is " << myStack.size() << endl;

        // Print the average of the stack
        float avg = myStack.findAverage();

        cout << "The average of the stack is " << avg << endl;

    }

    catch (const out_of_range& e) {
        cerr << "\nError: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "\nAn exception occurred: " << e.what() << endl;
    }

    return 0;
}