#include <iostream>
using namespace std;
//reverse a string using stack

char str[]="DataStructure";
int top=-1;

void pop(){
    if (top==-1){
        cout<<"Underflow";
    }
    else{
        cout<<str[top];
        top--;
    }
}    
int main(){
    top=sizeof(str)/sizeof(str[0])-1;
    cout<<"Reversed string is ";
    while(top!=-1){
        pop();
    }
    cout<<endl;
    return 0;
}
