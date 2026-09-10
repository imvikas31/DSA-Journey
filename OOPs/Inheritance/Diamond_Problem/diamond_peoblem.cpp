#include <bits/stdc++.h>
using namespace std;


// ============================================================
// Diamond Problem
// ============================================================
//
//                  People
//                 /      \
//                ↓        ↓
//            Teacher   Researcher
//                \        /
//                 \      /
//                  ↓    ↓
//                Professor
//
// Both Teacher and Researcher inherit from People.
// Professor inherits from both Teacher and Researcher.
//
// Therefore, Professor has two paths to People:
//
// Professor → Teacher → People
// Professor → Researcher → People
//
// This creates ambiguity when accessing People members.
// ============================================================


class People {
public:

    void walk() {
        cout << "People walks" << endl;
    }
};


// Teacher inherits from People.
class Teacher : public People {
};


// Researcher also inherits from People.
class Researcher : public People {
};


// Professor inherits from both Teacher and Researcher.
class Professor : public Teacher, public Researcher {
};


// ============================================================
// 1. Resolution using Scope Resolution
// ============================================================
//
// We can explicitly tell the compiler which path to follow.
//
// P1.Teacher::walk()
//      ↓
// Professor → Teacher → People → walk()
//
// P1.Researcher::walk()
//      ↓
// Professor → Researcher → People → walk()
//
// This resolves the ambiguity, but Professor still contains
// TWO separate People base objects.
// ============================================================


// ============================================================
// 2. Resolution using Virtual Inheritance
// ============================================================
//
// Teacher and Researcher virtually inherit People:
//
// class Teacher : virtual public People
// class Researcher : virtual public People
//
// This makes People a shared virtual base class.
//
// Professor then contains only ONE People object.
//
// ============================================================

class VirtualTeacher : virtual public People {
};

class VirtualResearcher : virtual public People {
};

class VirtualProfessor : public VirtualTeacher, public VirtualResearcher {
};


int main() {

    // --------------------------------------------------------
    // Scope Resolution
    // --------------------------------------------------------

    Professor P1;

    // Explicitly choose the Teacher → People path.
    P1.Teacher::walk();

    // Explicitly choose the Researcher → People path.
    P1.Researcher::walk();


    // --------------------------------------------------------
    // Virtual Inheritance
    // --------------------------------------------------------

    VirtualProfessor P2;

    // Only one People base exists inside P2.
    // Therefore, there is no ambiguity.
    P2.walk();


    return 0;
}