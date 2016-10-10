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
  string temp;
  ss >> temp;

  if (temp == "NULL") {
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

bool isParen(string s) {
  if (s == "(" || s == "[" || s == "{" || s == "}" || s == "]" || s == ")") {
    return true;
  }
  else {
    return false;
  }
}

string Operators = "+-*/%";
bool is_operator(string s) {
  return Operators.find(s) != string::npos;
}

bool is_number (const string& s) {
  return (strspn(s.c_str(), "0123456789") == s.size());
}

int precendence(string op) {
  if (op == "+" || op == "-") {
    return 1;
  }
  else if (op == "*" || op == "/" || op == "%") {
    return 2;
  }
  else if (op == ")" || op == "]" || op == "}") {
    return 3;
  }
  else {
    return 0;
  }
}

bool isInvalid(string exp) {
  stringstream ss(exp);
  string temp;
  int numCount = 0;
  int opCount = 0;
  int parenCount = 0;

  while (ss >> temp) {
    if (is_number(temp)) {
      numCount++;
    }
    else if (is_operator(temp)) {
      opCount++;
    }
    else if (isParen(temp)) {
      parenCount++;
    }
  }
  if (numCount - opCount == 1) {
    return false;
  }
  else {
    return true;
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
  string temp;
  string right;
  string left;
  string newExp;

  if (!isBalanced(postfixExpression)) {
    return "invalid";
  }

  if (isInvalid(postfixExpression)) {
    return "invalid";
  }

  while (ss >> temp) {
    if (temp == "NULL") {
      return "invalid";
    }
    if (mystack.empty()) {}
    if (is_number(temp)) {
      mystack.push(temp);
    }
    else if (is_operator(temp)) {
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
        newExp = "( " + left + " " + temp + " " + right + " " + ")";
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


void trim (string& s) {
  size_t p = s.find_first_not_of(" \t");
  s.erase(0, p);

  p = s.find_last_not_of(" \t");
  if (string::npos != p) {
    s.erase(p + 1);
  }
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
  stack <string> mystack;
  stringstream ss(infixExpression);
  stringstream os;
  string temp;

  if (!isBalanced(infixExpression)) {
    return "invalid";
  }
  if (isInvalid(infixExpression)) {
    return "invalid";
  }

  while (ss >> temp) {
    if (is_number(temp)) {
      os << temp << " ";
    }
    else if (is_operator(temp)) {
      if (mystack.empty()) {
        mystack.push(temp);
      }
      else if (isParen(mystack.top())) {
        mystack.push(temp);
      }
      else if (precendence(temp) > precendence(mystack.top())) {
        mystack.push(temp);
      }
      else {
        while (!mystack.empty() && (precendence(temp)) <= precendence(mystack.top())) {
          string topItem = mystack.top();
          os << topItem << " ";
          mystack.pop();
        }
        mystack.push(temp);
      }
    }
    else if (isOpening(temp)) {
      mystack.push(temp);
    }
    else if (isClosing(temp)) {
      while (!parenChecker(mystack.top(), temp)) {
        string topItem = mystack.top();
        os << topItem << " ";
        mystack.pop();
      }
      mystack.pop();
    }
    else {
      return "invalid";
    }
  }
  while (!mystack.empty()) {
    string topItem = mystack.top();
    os << topItem << " ";
    mystack.pop();
  }
  string output;
  output = os.str();
  trim(output);
  return output;
}

int ExpressionManager::eval_op(string op) {
  stringstream evalstream;
  stack <string> mystack;
  int answer;
  string right = mystack.top();
  mystack.pop();
  string left = mystack.top();
  mystack.pop();

  int R = atoi(right.c_str());
  int L = atoi(left.c_str());

  if (op == "+") {
    answer = L + R;
  }
  if (op == "-") {
    answer = L - R;
  }
  if (op == "*") {
    answer = L * R;
  }
  if (op == "/") {
    if (R == 0 || L == 0) {
      return 0;
    }
    else {
      answer = L / R;
    }
  }
  return answer;
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
  stringstream ps(postfixExpression);
  stack <string> mystack;
  string temp;
  string right;
  string left;
  int answer;

  while (!mystack.empty()) {
    mystack.pop();
  }
  if (isInvalid(postfixExpression)) {
    return "invalid";
  }
  while (ps >> temp) {
    if (is_number(temp)) {
      mystack.push(temp);
    }
    else if (is_operator(temp)) {
      if (mystack.empty()) {
        return "invalid";
      }
      right = mystack.top();
      mystack.pop();
      if (mystack.empty()) {
        return "invalid";
      }
      left = mystack.top();
      mystack.pop();

      int R = atoi(right.c_str());
      int L = atoi(left.c_str());

      if (temp == "+") {
        answer = L + R;
      }
      if (temp == "-") {
        answer = L - R;
      }
      if (temp == "*") {
        answer = L * R;
      }
      if (temp == "/") {
        if (R == 0) {
          answer = 0;
          return "invalid";
        }
        else {
          answer = L / R;
        }
      }
      if (temp == "%") {
        answer = L % R;
      }
      stringstream os;
      os << answer;
      mystack.push(os.str());
    }
    else {
      return "invalid";
    }
  }
  string finalExp = mystack.top();
  return finalExp;
}
