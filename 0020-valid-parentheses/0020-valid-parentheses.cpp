class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            // Opening brackets
            if (ch == '[' || ch == '{' || ch == '(') {
                st.push(ch);
            }
            // Closing brackets
            else {
                // If stack is empty, there is no opening bracket to match
                if (st.empty()) {
                    return false;
                }
                // Check matching pair
                if ((ch == ']' && st.top() != '[') ||
                    (ch == '}' && st.top() != '{') ||
                    (ch == ')' && st.top() != '(')) {
                    return false;
                }
                // Matching opening bracket found
                st.pop();
            }
        }
        // Valid only if no unmatched opening brackets remain
        return st.empty();
    }
};