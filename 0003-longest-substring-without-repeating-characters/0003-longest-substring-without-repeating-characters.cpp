class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int l=0;int r=0; int len =0;int maxlen =0;
        vector<int>hash(256,-1);
        while(r<s.size()){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            hash[s[r]]=r;
            len = r-l+1;
            maxlen =max(len,maxlen); 
            r++;
        }
        return maxlen;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int>hash(256,-1);
//         int l=0;
//         int r =0;
//         int n = s.size(); int maxlen=0 ; int len = 0;
//         while(r<n){
//             if(hash[s[r]]!=-1){
//                 if(hash[s[r]]>=l){
//                     l=hash[s[r]]+1;
//                 }
//             }      
//             hash[s[r]]=r;
//             len = r-l+1;
//             maxlen = max(maxlen,len);
//             r++;
//         }
//         return maxlen ;
//     }
// };