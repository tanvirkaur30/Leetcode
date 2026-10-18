class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;          // indices store honge, values decreasing order mein
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // 1. Window se bahar nikla hua index front se hatao
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // 2. Chhote elements back se hatao (ab kabhi max nahi banenge)
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // 3. Current index daalo
            dq.push_back(i);
            // 4. Window poori ban gayi toh front = max
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};