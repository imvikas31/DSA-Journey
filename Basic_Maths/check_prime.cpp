#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int num){
    if(num == 1 ){
        return false;
    }

    for(int i = 2;i<num;i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;

    bool res = checkPrime(num);
    if(res ==  true){
        cout<<num<<" is prime"<<endl;
    }else{
         cout<<num<<" is not a prime"<<endl;
    }

    
    return 0;
}