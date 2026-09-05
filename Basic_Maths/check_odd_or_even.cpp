#include<bits/stdc++.h>
using namespace std;

//Approach 1 : Using Modulo Operator (%) -->>
void checkEvenOdd(int num){
    if(num%2 == 0){
        cout<<num<<" is "<<"Even"<<endl;
    }else{
        cout<<num<<" is "<<"Odd"<<endl;
    }
}

//Approach 1 : Using BitWise operator -->>
// last bit of even number is always 0.
// if we do bitwise AND (&) of any number with 1 if it given 1 then it is odd if it given 0 then it is even
void checkEvenOddUsingBit(int num){
    if((num & 1) == 0){
        cout<<num<<" is "<<"Odd"<<endl;
    }else{
        cout<<num<<" is "<<"Even"<<endl;
    }
}

int main() {

    int num;
    cout<<"Enter a number : ";
    cin>>num;

    checkEvenOdd(num);
    checkEvenOddUsingBit(num);

    
    return 0;
}