#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Iterative Approach
// T.C = O(d) where d is number of digits
// S.C = O(1) No extra space used

int reverseNum(int num){
    int rev = 0;
    if(num == 0){
        return rev;
    }

    while(num != 0){
        int digit = num%10;
        rev = rev*10+digit;
        num = num/10;
    }
    return rev;
}
// Approach 2 : Recursive Approach
// T.C = o(d) where d is number of digits
// S.C = o(d) Auxilary space due to recursion stack

int reverseNumRec(int num, int &rev){
   
    if(num == 0){
        return rev;
    }

    
    int digit = num%10;
    rev = rev*10+digit;
    return reverseNumRec(num/10,rev);
}

int main() {

    int num;
    cout<<"Enter a number : ";
    cin>>num;

    int revNum1 = reverseNum(num);
    cout<<"Reverse of "<<num<<" iteration is : "<<revNum1<<endl;

    int rev = 0;
    int revNum2 = reverseNumRec(num,rev);
    cout<<"Reverse of "<<num<<" using recursion is : "<<revNum2<<endl;
    
    return 0;
}