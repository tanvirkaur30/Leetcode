class Solution {
public:
    vector<int>NSE(vector<int>& arr){
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();//store n in nse if no next smaller exists
            st.push(i);//push index 
        }
        return nse;
    }
    vector<int>PSE(vector<int>& arr){
        int n = arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){//use > not >= in one of the functions to  avoid counting same subarrays//
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();//store -1 in pse if no previous smaller exists
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
       int mod = int(1e9 + 7);
       vector<int>pse = PSE(arr);
       vector<int>nse = NSE(arr);
       long long  total = 0;
       for(int i =0;i<arr.size();i++){
        int left = i-pse[i];//calculate no. of subarrays in which current element is minimum
        int right = nse[i]-i;
        total = (total + (left * 1LL * right * arr[i]) % mod) % mod;
       }
       return total;
    }
};