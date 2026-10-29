class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string res="";
        for(int i =0;i<strs[0].size();i++){
            for(string s : strs){
                if(i==s.size() || s[i]!=strs[0][i]) return res;
            }
            res+=strs[0][i];
        }
        return res;
    }
};