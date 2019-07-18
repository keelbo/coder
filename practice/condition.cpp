#include<iostream>

using namespace std;


int main(){
    int numberOfTests;
    int n;
    cin>>numberOfTests;
    while(numberOfTests--){
        cin>>n;
        if(n==5){
            cout<<"Equal to 5\n";
        }else if(n<4){
            cout<<"Less than 5\n";
        }else{
            cout<<"Greater than 5\n";
        }
    }

    return 0;
}