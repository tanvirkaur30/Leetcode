class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>nge;
        for(int i =2*n-1;i>=0;i--){// imagine the array is doubled
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();   //modulo operator is used to traverse the original array
            }
            if(i<n){
                nge.push_back(st.empty()?-1:st.top());
            }
            st.push(nums[i%n]);
        }
        reverse(nge.begin(),nge.end());// because we are traversing from the back 
        return nge;
    }
};