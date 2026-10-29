#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<string> validExpressions;
    int minimumRemoved;

    void recurse(string &s, int index, int leftCount, int rightCount,
                 string &expr, int removedCount) {

        // Base Case: End of string
        if (index == s.length()) {
            if (leftCount == rightCount) {

                // check minimum removal condition
                if (removedCount == minimumRemoved) {
                    validExpressions.insert(expr);
                }
                if (removedCount < minimumRemoved){
                    validExpressions.clear();
                    minimumRemoved = removedCount;  
                    validExpressions.insert(expr);               
                }
                 
            }
            return;
        }

        char current = s[index];

        // If character is a letter
        if (current != '(' && current != ')') {

            expr.push_back(current);
            recurse(s, index + 1, leftCount, rightCount, expr, removedCount);
            expr.pop_back();
        }
        else {

            // Option 1: Remove the parenthesis
            recurse(s, index + 1, leftCount, rightCount, expr, removedCount + 1);

            // Option 2: Keep the parenthesis
            expr.push_back(current);

            if (current == '(') {

                recurse(s, index + 1, leftCount + 1, rightCount, expr, removedCount);

            } 
            else if (rightCount < leftCount) {

                recurse(s, index + 1, leftCount, rightCount + 1, expr, removedCount);
            }

            expr.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {

        minimumRemoved = INT_MAX;
        validExpressions.clear();

        string expr;

        recurse(s, 0, 0, 0, expr, 0);

        return vector<string>(validExpressions.begin(), validExpressions.end());
    }
};