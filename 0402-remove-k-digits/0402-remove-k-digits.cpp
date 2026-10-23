class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==0) return "0";
        int n = num.size();
        stack<char>st;
        for(int i =0;i<n ;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string result = "";
        while(!st.empty()){
           result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        int i = 0;
        while(i<result.size() && result[i]=='0'){
           i++;
        }
        result = result.substr(i);
        return result=result.empty()? "0": result ;
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



// if(k==num.size()) return "0";
//         int n = num.size();
//         stack<char>st;
//         for(int i=0;i<n;i++){
//             while(!st.empty() && k>0 && st.top()>num[i]){
//                 st.pop();
//                 k--;
//             }
//             st.push(num[i]);
//         }
//         while(k > 0 && !st.empty()) {
//         st.pop();  
//          k--;
//        }
//         string res="";
//         while(!st.empty()){
//             res+=st.top();
//             st.pop();
//         }
//         reverse(res.begin(),res.end());
//         int i=0;
//         while(i<res.size() && res[i]=='0') i++;
//         res=res.substr(i);
//         return res.empty() ? "0": res;