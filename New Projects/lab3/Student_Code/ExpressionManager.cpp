#include "ExpressionManager.h"
#include <cstring>
#include <cctype>
#include <cstdlib>

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
}

bool parenChecker(string first, string second) {
    if (first == "(")
}
