
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;//store ans 
        int n = nums.size();
        for(int i =0;i<n ;i++){
// any iteration represents the end of the current window so for ineligible indices we check the condition i-k+1 an dremove them from front because we are pushing the indices and front indices are out of window 
            if(!dq.empty() && dq.front()<i-k+1){
                dq.pop_front();
            }
//remove the elements from back that are smaller than the current element int he array as the smaller ones cannot be the maximum for the window 
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            //push indices into deque
            dq.push_back(i);
// Once we reach index (k - 1), we have completed our first window of size k. From this point onward, the front of deque ALWAYS holds the maximum element index for current window.
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
