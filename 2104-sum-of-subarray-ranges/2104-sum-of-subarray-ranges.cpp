class Solution {
public:
vector<int>NSE(vector<int>&arr){
    int n =arr.size();
    vector<int>nse(n);
    stack<int>st;
    for(int i =arr.size()-1;i>=0;i--){
    while(!st.empty() && arr[st.top()]>=arr[i]){
        st.pop();
    }
    nse[i]=st.empty()? n:st.top();
    st.push(i);
    }
    return nse;
}
vector<int>PSE(vector<int>&arr){
      int n =arr.size();
    vector<int>pse(n);
    stack<int>st;
    for(int i =0;i<arr.size();i++){
    while(!st.empty() && arr[st.top()]>arr[i]){
        st.pop();
    }
    pse[i]=st.empty()? -1:st.top();
    st.push(i);
    }
    return pse;
}
long long sumofsubarrayminimums(vector<int>&arr){
   vector<int>pse=PSE(arr);
   vector<int>nse=NSE(arr);
   long long total =0;
   for(int i =0;i<arr.size();i++){
       int left = i-pse[i];
       int right = nse[i]-i;
      total= (total+(left*right*1LL*arr[i]));
   }
   return total;
}
vector<int>NGE(vector<int>&arr){
    int n =arr.size();
    vector<int>nge(n);
    stack<int>st;
    for(int i =arr.size()-1;i>=0;i--){
    while(!st.empty() && arr[st.top()]<=arr[i]){
        st.pop();
    }
    nge[i]=st.empty()? n:st.top();
    st.push(i);
    }
    return nge;
}
vector<int>PGE(vector<int>&arr){
      int n =arr.size();
    vector<int>pge(n);
    stack<int>st;
    for(int i =0;i<arr.size();i++){
    while(!st.empty() && arr[st.top()]<arr[i]){
        st.pop();
    }
    pge[i]=st.empty()? -1:st.top();
    st.push(i);
    }
    return pge;
}
long long sumofsubarraymaximums(vector<int>&arr){
   vector<int> pge=PGE(arr);
   vector<int> nge=NGE(arr);
   long long total =0;
   for(int i =0;i<arr.size();i++){
       int left = i-pge[i];
       int right = nge[i]-i;
      total= (total+(left*right*1LL*arr[i]));
   }
   return total;
}
    long long subArrayRanges(vector<int>& nums) {
        long long sumMin=sumofsubarrayminimums(nums);
        long long sumMax=sumofsubarraymaximums(nums);
        return sumMax-sumMin;
    }
};