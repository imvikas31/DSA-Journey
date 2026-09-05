#include<bits/stdc++.h>
using namespace std;


// Iterative Approach :
// Time Complexity = O(d) where d = number of digits in the given number
// Space Complexity = O(1) --> No extra space used
int sumOfDigits(int num, int &sum){
    //if the digit is negative then make it positive
    if(num < 0){
        num  = -num;
    }
    while(num != 0){
        
        //fetching last digit
        int digit = num%10;
        //adding the last digit to the final sum of all digits
        sum += digit;
        //removing the last digit that has been processed
        num = num/10;
    }
    return sum;
}


// Recursive Approach :
// Time Complexity = O(d) where d = number of digits in the given number
// Space Complexity = O(d) -->Auxilary space used for recursive calls.

int sumOfDigitsUsingRec(int num, int &sum){
    if(num == 0) return sum;
    if(num < 0) num = -num; //  handling negative integer
   
    //fetch last digit ans add it to sum
    int digit = num%10;

    //add last digit to the sum
    sum += digit;

    //remove last digit make recursive call
    sumOfDigitsUsingRec(num/10,sum);
    return sum;
}

int main() {

    int num;
    cout<<"Enter a number : ";
    cin>>num;

    int sum1 = 0;

    // Iterative Approach :
    int digitSum1 = sumOfDigits(num,sum1);
    cout<<"Sum of all digit of "<<num<<" using iterative approach is : "<<digitSum1<<endl;

    int sum2 = 0;
    int digitSum2 = sumOfDigitsUsingRec(num,sum2);
    cout<<"Sum of all digit of "<<num<<" using recursive approach is : "<<digitSum2<<endl;
    
    return 0;
}
