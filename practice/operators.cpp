#include <iostream>
using namespace std;

void printAddition(int a, int b){
    cout << (a+b) << '\n';
}

void printSubstraction(int a, int b){
    cout << (a>b? (a-b):(b-a)) << '\n';
}

void printDivision(int a, int b){
    cout << (a>b? (a/b):(b/a)) << '\n';
}

void printMultiplication(int a, int b){
    cout << (a*b) << '\n';
}

int main() {
	int numberOfTests, a, b;
	cin>> numberOfTests;
	for(int i=0; i<numberOfTests; i++){
	    cin>>a>>b;
        printAddition(a,b);
        printSubstraction(a,b);
        printDivision(a,b);
        printMultiplication(a,b);
	}
	return 0;
}











