#include <iostream>
using namespace std;
//menu driven stack program

int a[5];
int top=-1;
int n=sizeof(a)/sizeof(a[0]);

void push(int value){
    if (top==n-1){
        cout<<"Stack Overflow";
    }
    else{
        cout<<"Enter elements: ";
        cin>>value;
        a[++top]=value;
        cout << value << " pushed";
    }
}

void pop(){
    if (top==-1){
        cout<<"Stack Underflow";
    }
    else{
        cout<<a[top];
        top--;
    }
}

bool isEmpty(){
    return (top==-1);
}
bool isFull(){
    return (top==n-1);
}

void display(){
    for(int i=top;i>=0;i--){
        cout<<a[i]<<" ";
    }
}

void peek(){
    if (isEmpty()){
        cout<<"Stack is empty";
    }
    else{
        cout<<"Top element is "<<a[top];
    }
}

int main(){
    int choice;
    int value;
    do{
        cout<<"\nMENU\n";
        cout<<"1.PUSH\n2.POP\n3.ISEMPTY\n4.ISFULL\n5.DISPLAY\n6.PEEK\n7.EXIT\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch (choice){
            case 1:
            push(value);
            break;
            
            case 2:
            pop();
            break;
            
            case 3:
            if (isEmpty()){
                cout<<"Stack is empty";
            }
            else{
                cout<<"Stack is not empty";
            }
            break;
            
            case 4:
            if (isFull()){
                cout<<"Stack is full";
            }
            else{
                cout<<"Stack is not full";
            }
            break;
            
            case 5:
            display();
            break;
            
            case 6:
            peek();
            break;
            
            case 7:
            cout<<"Exiting...";
            break;
            
            default:
            cout<<"INVALID!!!!";
            break;
        }
    } while (choice != 7);
    return 0;
}
