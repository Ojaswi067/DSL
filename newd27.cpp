#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

// Function to check if a character is an operand
bool isOperand(char ch) {
    return isalpha(ch);
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// Function to evaluate a postfix expression using variable values
int evaluatePostfix(string postfix, map<char, int> &variables) {
    stack<int> st;

    for (char ch : postfix) {
        if (isOperand(ch)) {
            st.push(variables[ch]); // use variable value from the map
        } else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Predefined variable values
    map<char, int> variables;
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char var;
        int val;
        cout << "Enter variable name and value (e.g., a 5): ";
        cin >> var >> val;
        variables[var] = val;
    }

    int result = evaluatePostfix(postfix, variables);
    cout << "Result: " << result << endl;

    return 0;
}
