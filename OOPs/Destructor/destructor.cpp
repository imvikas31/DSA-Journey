#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    int id;

    Student(string name, int id){
        this->name = name;
        this->id = id;
        cout<<"Student created."<<endl;
    }

    ~Student(){
        cout<<"Student destroyed."<<endl;
    }
};

int main() {
    {
    Student s1("Vikas Singh",112);  // local object , it will be destroyed automatically by calling its constructor.
    cout<<"Name of student s1 : "<<s1.name<<endl;
    cout<<"ID of student s1 : "<<s1.id<<endl;
    } // here scope of s1 objects ends, so the s1 objects will destructor automatically that destroys the object.
   



    cout<<endl;
    Student* s2 = new Student("Saurabh",113);  // memory allocated on heap(dynamic allocation), its should be destroyed manually using delete keyword
    cout<<"Name of student s2 : "<<s2->name<<endl;
    cout<<"ID of student s2 : "<<s2->id<<endl;

    // manually destroying the Object on heap.
    delete[] s2;

    // s2 object on heap memory is destroyed but the pointer on stact that points that object on the heap still exists and now its is called as dangling pointer

    // cout<<s2->name; 
    //is undefined behavior.
    // It might:
    // print garbage,
    // appear to work accidentally,
    // crash,
    // or behave unpredictably.
    
    return 0;
}