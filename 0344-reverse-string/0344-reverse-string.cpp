class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right= s.size()-1;
        while(left<=right){
            char ch = s[left];
            s[left]=s[right];
            s[right]=ch;
            left++;
            right--;
        }
    }
};