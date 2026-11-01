class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0, maxFreq = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            maxFreq = max(maxFreq, ++count[s[right] - 'A']);
            // window size - most frequent char = replacements needed
            if ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};