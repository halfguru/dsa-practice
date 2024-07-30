/*Given a string s containing just the characters '(', ')', '{', '}', '[' and
  ']', determine if the input string is valid.

  An input string is valid if:

  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
  Every close bracket has a corresponding open bracket of the same type.
 */

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    std::stack<char> myStack;

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        myStack.push(')');
      } else if (s[i] == '{') {
        myStack.push('}');
      } else if (s[i] == '[') {
        myStack.push(']');
      } else if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']')) {
        if (myStack.empty() || myStack.top() != s[i]) {
          return false;
        }
        myStack.pop();
      }
    }

    if (myStack.empty()) {
      return true;
    }

    return false;
  }
};
