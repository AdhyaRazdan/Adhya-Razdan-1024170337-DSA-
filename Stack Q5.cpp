#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char c : postfix) {
        // If operand, push to stack
        if (isdigit(c)) {
            st.push(c - '0'); // convert char → int
        }
        else {
            // Operator: pop two operands
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < val2; i++) result *= val1;
                    st.push(result);
                    break;
                }
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    cout << "Evaluation Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
