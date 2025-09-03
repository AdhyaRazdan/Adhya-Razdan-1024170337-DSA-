#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Function to check if operator is right-associative
bool isRightAssociative(char op) {
    return op == '^';
}

// Function to convert Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        // If operand, add to output
        if (isalnum(c)) {
            postfix += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // If operator
        else {
            while (!st.empty() && precedence(c) <= precedence(st.top()) &&
                  !(isRightAssociative(c) && precedence(c) == precedence(st.top()))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
