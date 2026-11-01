class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

        int need[128] = {0};
        for (char c : t) need[c]++;

        int missing = t.size();          // t ke kitne chars abhi bhi window mein kam hain
        int left = 0, start = 0, minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (need[s[right]]-- > 0) missing--;

            while (missing == 0) {       // window valid hai, ab shrink kar
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                if (++need[s[left]] > 0) missing++;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};