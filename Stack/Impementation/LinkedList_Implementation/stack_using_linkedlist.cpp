#include<bits/stdc++.h>
using namespace std;

// Node represents one element of the linked list
class Node{
    public:
    
    int data;       // Stores the value of the node
    Node *next;     // Stores the address of the next node

    // Constructor to initialize a new node
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


// Stack implementation using Linked List
class StackUsingLinkedList{
    public:

    int size;       // Maximum capacity of the stack
    Node* head;     // Points to the top node of the stack
    int top;        // Stores the index of the top element

    // Constructor
    StackUsingLinkedList(int size){
        this->size = size;
        head = NULL;    // Initially stack is empty
        top = -1;       // -1 means no element is present
    }


    // Checks whether the stack is empty
    bool isEmpty(){
        
        // Stack is empty if top is -1
        // OR head is NULL
        if(top == -1 || head == NULL){
            return true;
        }

        return false;
    }


    // Adds an element to the top of the stack
    // This operation is equivalent to PUSH
    void add(int data){

        // Check for stack overflow
        // If top reaches size - 1, stack is full
        if(top >= size-1){
            cout<<"Stack is Full, adding elements further leads to stack overflow."<<endl;
            return;
        }
        
        // Create a new node dynamically
        Node* newNode = new Node(data);

        // Store the current top node
        Node* temp = head;

        // Connect the new node to the current top
        newNode->next = temp;

        // Make the new node the new top
        head = newNode;

        // Increase top index
        top++;

        cout<<"Added element "<<data<<" at index "<<top<<endl;
        
    }


    // Removes the top element from the stack
    // This operation is equivalent to POP
    void remove(){

        // Check for stack underflow
        if(top == -1){
            cout<<"Stack is empty, removing futher leads to stack underflow."<<endl;
            return;
        }

        // Store the current top node
        Node* temp = head;

        cout<<"Removing element "<<temp->data<<" at index "<<top<<endl;

        // Move head to the next node
        // This removes the current top node from the stack
        head = temp->next;

        // Free the memory of the removed node
        delete temp;

        // Decrease top index
        top--;

    }


    // Prints all elements of the stack
    // Elements are printed from TOP to BOTTOM
    void print(){

        // Temporary pointer used for traversal
        Node* temp = head;

        // Check if stack is empty
        if(isEmpty()){
            cout<<"Stack is empty, no elements to print"<<endl;
            return;
        }

        cout<<"Stack elements are : ";

        // Traverse the linked list
        while(temp != NULL){

            // Print current node's data
            cout<<temp->data<<" ";

            // Move to the next node
            temp = temp->next;
        }

        cout<<endl;
    }


    // Returns the top element of the stack
    // This operation is equivalent to PEEK
    int peak(){

        return head->data;
    }
};


int main() {

    // Create a stack with maximum capacity of 5
    StackUsingLinkedList sl(5);

    // Try printing an empty stack
    sl.print();


    // Add elements to the stack
    // Stack follows LIFO:
    // Last In -> First Out
    sl.add(10);
    sl.add(20);
    sl.add(30);
    sl.add(40);
    sl.add(50);

    // This will cause stack overflow
    // because maximum size is 5
    sl.add(60);


    // Print all stack elements
    sl.print();


    // Remove the top element
    // 50 will be removed because it was added last
    sl.remove();


    // Print stack after removal
    sl.print();


    // Get the top element without removing it
    int topElement = sl.peak();

    cout<<"Top element of the stack : "<<topElement<<endl;


    return 0;
}