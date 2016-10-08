#include "ExpressionManager.h"
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

ExpressionManager::ExpressionManager(){}
ExpressionManager::~ExpressionManager(){}

bool ExpressionManager::isOpening(string paren) {
    if (paren == "(" || paren == "[" || paren == "{") {
        return true;
    }
    else {
        return false;
    }
}

bool ExpressionManager::isClosing(string paren) {
    if (paren == ")" || paren == "]" || paren == "}") {
        return true;
    }
    else {
        return false;
    }
}

bool ExpressionManager::isEmpty(stringstream ss) {
    if (ss == "NULL") {
        return true;
    }
    else {
        return false;
    }
    return false;
}

bool parenChecker(string first, string second) {
    if (first == "(" && second == ")") {
        return true;
    }
    else if (first == "[" && second == "]") {
        return true;
    }
    else if (first == "{" && second == "}") {
        return true;
    }
    else {
        return false;
    }
}



/*
  * Checks whether an expression is balanced on its parentheses
  *
  * - The given expression will have a space between every number or operator
  *
  * @return true if expression is balanced
  * @return false otherwise
  */
bool ExpressionManager::isBalanced(string expression) {
    stack <string> mystack;
    stringstream ss(expression);
    string temp;
    while (ss >> temp) {
        if (isOpening(temp)) {
            mystack.push(temp);
        }
        else if (isClosing(temp)) {
            if (mystack.empty()) {
                return false;
                break;
            }
            else {
                string top = mystack.top();
                if (parenChecker(top, temp)) {
                    mystack.pop();
                }
                else {
                    return false;
                    break;
                }
            }
        }
    }
    if (!mystack.empty()) {
        return false;
    }
    else {
        return true;
    }
}

/**
 * Converts a postfix expression into an infix expression
 * and returns the infix expression.
 *
 * - The given postfix expression will have a space between every number or operator.
 * - The returned infix expression must have a space between every number or operator.
 * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
 * - Check lab requirements for what will be considered invalid.
 *
 * return the string "invalid" if postfixExpression is not a valid postfix expression.
 * otherwise, return the correct infix expression as a string.
 */
string ExpressionManager::postfixToInfix(string postfixExpression) {
    stack <string> mystack;
    stringstream ss(postfixExpression);
    string curr;
    string right;
    string left;
    string newExp;

    if (!isBalanced(postfixExpression)) {
        return "invalid";
    }

    if (isInvalid(postfixExpression)) {
        return "invalid";
    }
    while (ss >> curr) {
        if (curr == "NULL") {
            return "invalid";
        }
        if (mystack.empty()) { }
        if (is_number(curr)) {
            mystack.push(curr);
        }
        else if (is_operator(curr)) {
            if (mystack.empty()) {
                return "invalid";
            }
            else {
                right = mystack.top();
                mystack.pop();
                if (mystack.empty()) {
                    return "invalid";
                }
                left = mystack.top();
                mystack.pop();
                newExp = "( " + left + " " + curr + " " + right + " " + ")";
                mystack.push(newExp);
            }
        }
        else {
            return "invalid";
        }
    }
    if (mystack.empty()) {
      return "invalid";
    }
    newExp = mystack.top();
    return newExp;
}

/*
 * Converts an infix expression into a postfix expression
 * and returns the postfix expression
 *
 * - The given infix expression will have a space between every number or operator.
 * - The returned postfix expression must have a space between every number or operator.
 * - Check lab requirements for what will be considered invalid.
 *
 * return the string "invalid" if infixExpression is not a valid infix expression.
 * otherwise, return the correct postfix expression as a string.
 */
string ExpressionManager::infixToPostfix(string infixExpression) {

    return infixExpression;
}

int ExpressionManager::eval_op(string op) {
    int temp = 0;

    return temp;
}
//virtual int eval(string expression);

/*
 * Evaluates a postfix expression returns the result as a string
 *
 * - The given postfix expression will have a space between every number or operator.
 * - Check lab requirements for what will be considered invalid.
 *
 * return the string "invalid" if postfixExpression is not a valid postfix Expression
 * otherwise, return the correct evaluation as a string
 */
string ExpressionManager::postfixEvaluate(string postfixExpression) {

    return postfixExpression;
}
