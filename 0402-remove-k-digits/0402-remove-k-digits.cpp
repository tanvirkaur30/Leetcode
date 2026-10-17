class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        stack<char> st;
        int n = num.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while(i < res.size() && res[i] == '0') i++;
        res = res.substr(i);
        return res.empty() ? "0" : res;
    }
};




//  string st;
//         for (char digit : num) {
//             // Remove larger previous digits
//             while (!st.empty() && k > 0 && st.back() > digit) {
//                 st.pop_back();
//                 k--;
//             }
//             st.push_back(digit);
//         }
//         // If k digits are still left, remove from the end
//         while (k > 0) {
//             st.pop_back();
//             k--;
//         }
//         // Remove leading zeros
//         int i = 0;
//         while (i < st.size() && st[i] == '0') {
//             i++;
//         }
//         st = st.substr(i);
//         // If everything was removed
//         return st.empty() ? "0" : st;