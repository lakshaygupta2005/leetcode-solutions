```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        // Map of closing brackets to their corresponding opening brackets
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (closeToOpen.count(c))   //map.count(c) returns 1 if the key c exists in map.
            {
                // Check if the top of the stack has the matching opening bracket
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop(); // Valid match found, remove the opening bracket
                } else {
                    return false; // Mismatch or stack is empty — invalid
                }
            } 
            else 
            {
                // It's an opening bracket, so push it onto the stack
                stack.push(c);
            }
        }

        // If the stack is empty, all brackets were matched correctly
        return stack.empty();
    }
};
```