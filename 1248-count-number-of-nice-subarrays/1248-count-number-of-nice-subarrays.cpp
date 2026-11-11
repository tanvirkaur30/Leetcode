
class Solution {
public:
    int atmostk(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int l = 0, r = 0;
        int count = 0, odd = 0;
        while(r < nums.size()) {
            odd += nums[r] % 2;
           while(odd > k) {
                odd -= nums[l] % 2;
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k-1);
    }
};









// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         return atMost(nums, k) - atMost(nums, k - 1);
//     }
// private:
//     // subarrays jinme odd numbers <= k hain
//     int atMost(vector<int>& nums, int k) {
//         if (k < 0) return 0;
//         int left = 0, odd = 0, res = 0;
//         for (int right = 0; right < nums.size(); right++) {
//             odd += nums[right] & 1;
//             while (odd > k) {
//                 odd -= nums[left] & 1;
//                 left++;
//             }
//             res += right - left + 1;// right pe end hone wale valid subarrays
//         }
//         return res;
//     }
// };