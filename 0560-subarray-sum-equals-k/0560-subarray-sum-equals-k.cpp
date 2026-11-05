class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count =0;int presum=0;
        mp[0]=1;//to know taht a sum of 0 occurred before start of the array 
        for(int i =0; i<nums.size(); i++){
            presum+=nums[i];
            int remove = presum-k;
            count+=mp[remove];
            mp[presum]++;
        }
         return count;
    }
};