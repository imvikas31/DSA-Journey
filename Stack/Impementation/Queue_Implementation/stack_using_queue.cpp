#include<bits/stdc++.h>
using namespace std;

// Stack implementation using a single queue
class StackUsingQueue{
    public:
    queue<int>q;    // Queue used to store stack elements
    int size;       // Maximum stack capacity
    int top;        // Index of top element

    // Constructor
    StackUsingQueue(int size){
        this->size = size;
        top = -1;   // Stack is initially empty
    }

    // Check whether stack is empty
    bool isEmpty(){
        if(top == -1 || q.empty()){
            return true;
        }
        return false;
    }

    // Add element to stack
    void add(int data){

        // Check for stack overflow
        if(top >= size-1){
            cout<<"Stack full, adding further will lead to overflow"<<endl;
            return;
        }

        top++;
        q.push(data);

        cout<<"Added element "<<data<<" at index "<<top<<endl;

        // Move previous elements behind the new top element
        for(int i = 0; i < top; i++){
            q.push(q.front());
            q.pop();
        }
    }

    // Remove top element from stack
    void pop(){

        // Check for stack underflow
        if(isEmpty()){
            cout<<"Stack is empty, removing further will lead to underflow"<<endl;
        }
        else{
            cout<<"Removing "<<q.front()<<" from index "<<top<<endl;

            q.pop();
            top--;
        }
    }

    // Return top element without removing it
    int peek(){
        return q.front();
    }

    // Print stack elements from top to bottom
    void print(){

        if(isEmpty()){
            cout<<"Stack is empty, no element to print."<<endl;
            return;
        }
        else{
            cout<<"Stack elements are : ";

            // Use a copy so the original queue remains unchanged
            queue<int> temp = q;

            while(!temp.empty()){
                cout<<temp.front()<<" ";
                temp.pop();
            }

            cout<<endl;
        }
    }
};

int main() {

    // Create stack with capacity 5
    StackUsingQueue sq(5);

    sq.print();

    // Add elements to stack
    sq.add(10);
    sq.add(20);
    sq.add(30);
    sq.add(40);
    sq.add(50);

    // Test overflow condition
    sq.add(60);

    sq.print();

    // Remove top element
    sq.pop();
    sq.print();

    // Get top element
    int topElement = sq.peek();
    cout<<"Top element is : "<<topElement<<endl;

    return 0;
}