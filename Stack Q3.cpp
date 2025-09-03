#include <iostream>
using namespace std;
int a[5];
int top=-1;
int n=sizeof(a)/sizeof(a[0]);
void push(char c){
    if (top==n-1){
        cout<<"Stack Overflow\n";
    }
    else{
        a[++top]=c;
    }
}

char pop(){
    if (top==-1){
        return '\0';
    }
    else{
        return a[top--];
    }
}

bool isEmpty(){
    return (top==-1);
}

bool isBalanced(string expr){
    for (int i=0;i<expr.length();i++){
        char ch=expr[i];
        if (ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(isEmpty()){
                return false;
            }
            char topChar=pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                    return false;
                }
        }
    }
    return isEmpty();
}
int main(){
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "\nBalanced\n";
    else
        cout << "\nNot Balanced\n";

    return 0;
}
