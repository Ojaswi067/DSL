/*
Name : Ojaswi Shinde
Roll No : 65
PRN No : F23112078
Class : SE-II(R-Batch)

//Problem Statement D26

/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.
*/


#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a given expression is well-parenthesized
bool isWellParenthesized(const string& expression) {
    stack<char> delimiterStack;

    // Iterate over each character in the expression
    for (char c : expression) {
        // If the character is an opening delimiter, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            delimiterStack.push(c);
        }
        // If the character is a closing delimiter, check if the stack is empty or the top of the stack does not match
        else if (c == ')' || c == '}' || c == ']') {
            if (delimiterStack.empty()) {
                return false; // Unbalanced expression
            }

            char openingDelimiter = delimiterStack.top();
            delimiterStack.pop();

            // Check if the opening and closing delimiters match
            if ((c == ')' && openingDelimiter != '(') ||
                (c == '}' && openingDelimiter != '{') ||
                (c == ']' && openingDelimiter != '[')) {
                return false; // Unbalanced expression
            }
        }
    }

    // If the stack is empty after iterating over the entire expression, it is well-parenthesized
    return delimiterStack.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << std::endl;
    } else {
        cout << "The expression is not well-parenthesized." << std::endl;
    }

    return 0;
}
