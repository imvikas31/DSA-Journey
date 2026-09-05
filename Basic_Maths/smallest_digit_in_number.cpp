#include<bits/stdc++.h>
using namespace std;


// Iterative Approach :
// Time Complexity = O(d) where d = number of digits in the given number
// Space Complexity = O(1) --> No extra space used
long long sumOfDigits(long long num){
    long long smallestDigit = INT_MAX;

    // Handle negative integer
    if(num < 0) {
        num = -num;
    }
    
    while(num != 0){
        
        //fetching last digit
        long long digit = num%10;
        //find  minimum of digit and smallestDigit and assign it to smallesDigit
        smallestDigit = min(digit,smallestDigit);
        //removing the last digit that has been processed
        num = num/10;
    }
    return smallestDigit;
}


// Recursive Approach :
// Time Complexity = O(d) where d = number of digits in the given number
// Space Complexity = O(d) -->Auxilary space used for recursive calls.

long long sumOfDigitsUsingRec(long long num, long long &smallestDigit){

    // Handle negative integer
    if(num < 0) {
        num = -num;
    }
    
    if(num == 0) return smallestDigit;
    
   
    //fetch last digit ans add it to sum
    long long digit = num%10;

    //find  minimum of digit and smallestDigit and assign it to smallesDigit
    smallestDigit = min(digit,smallestDigit);

    //remove last digit make recursive call
    sumOfDigitsUsingRec(num/10,smallestDigit);
    return smallestDigit;
}

int main() {

    long long num;
    cout<<"Enter a number : ";
    cin>>num;

    // Iterative Approach :
    int digitSum1 = sumOfDigits(num);
    cout<<"Smallest Digit of From of "<<num<<" using iterative approach is : "<<digitSum1<<endl;

    long long smallestDigit = INT_MAX;
    long long digitSum2 = sumOfDigitsUsingRec(num,smallestDigit);
    cout<<"Smallest Digit of From digit of "<<num<<" using recursive approach is : "<<digitSum2<<endl;
    
    return 0;
}
