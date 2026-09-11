#include<bits/stdc++.h>
using namespace std;

// Stack implementation using array
class Stack{
    public:
    int size;       // Maximum capacity of stack
    int top;        // Index of top element
    int *arr;       // Array to store elements

    // Constructor
    Stack(int size){
        this->size = size;
        top = -1;               // Stack is initially empty
        arr = new int[size];    // Allocate array
    }

    // Check if stack is empty
    bool isEmpty(){
        return top == -1;
    }

    // Add element to top of stack (Push)
    void add(int data){

        // Check for stack overflow
        if(top >= size-1){
            cout<<"Stack is full, adding more element will lead to stack overflow."<<endl;
            return;
        }

        top++;
        arr[top] = data;

        cout<<"Added "<<data<<" at index "<<top<<endl;
    }

    // Remove top element from stack (Pop)
    void remove(){

        // Check for stack underflow
        if(isEmpty()){
            cout<<"Stack is empty, removing element further will lead to stack underflow."<<endl;
            return;
        }

        cout<<"Removed "<<arr[top]<<" from index "<<top<<endl;

        top--;
    }

    // Return top element without removing it
    int peek(){
        return arr[top];
    }

    // Print stack from top to bottom
    void print(){

        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack elements are : ";

            // Traverse from top to bottom
            for(int i = top; i >= 0; i--){
                cout<<arr[i]<<" ";
            }

            cout<<endl;
        }
    }
};

int main() {

    // Create stack with capacity 5
    Stack st(5);

    st.print();

    // Push elements
    st.add(10);
    st.add(20);
    st.add(30);
    st.add(40);
    st.add(50);

    // Overflow condition
    st.add(60);
    st.add(70);
    st.add(80);

    st.print();

    // Pop top element
    st.remove();

    st.print();

    // Get top element
    int topElement = st.peek();
    cout<<"Top element is : "<<topElement<<endl;

    return 0;
}