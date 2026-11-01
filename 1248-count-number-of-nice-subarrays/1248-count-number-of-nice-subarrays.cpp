class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
private:
    // subarrays jinme odd numbers <= k hain
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int left = 0, odd = 0, res = 0;
        for (int right = 0; right < nums.size(); right++) {
            odd += nums[right] & 1;
            while (odd > k) {
                odd -= nums[left] & 1;
                left++;
            }
            res += right - left + 1;// right pe end hone wale valid subarrays
        }
        return res;
    }
};