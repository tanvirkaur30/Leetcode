class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        // Traverse the array twice
        for(int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            // Remove elements that cannot be the answer
            while(!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }
            // Stack top is the next greater element
            if(!st.empty()) {
                ans[idx] = st.top();
            }
            // Add current element for future elements
            st.push(nums[idx]);
        }

        return ans;
    }
};