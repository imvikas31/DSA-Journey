#include<bits/stdc++.h>
using namespace std;

void moveNegative(int arr[],int size){
    int i = 0;
    int j = 0;

    while(j < size){
        if(arr[j] < 0){
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    
}

int main() {
    int arr[6] = {-11,2,-3,0,-5,-1};
    moveNegative(arr,6);

    for(int i = 0;i<6;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}