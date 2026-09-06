#include<bits/stdc++.h>
using namespace std;
// if number of set bits in the bits of any number is 1 then that is power of 2.
// how to fint set bit??
// num & (num-1) gives 0 then the given number has set bitsand it is power of 2.
bool isPowerOf2(int num){
    if((num & (num-1)) == 0){
        return true;
    }
    return false;

}
int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;

    bool result = isPowerOf2(num);
    if(result == true){
        cout<<"True";
    }else{
        cout<<"False";
    }
    
    return 0;
}
