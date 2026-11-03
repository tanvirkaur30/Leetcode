class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>maxf(26,0);
     int l=0;int r =0;int maxfreq=0;int maxlen =0;
     while(r<s.size()){
        maxf[s[r]-'A']++;
        maxfreq=max(maxfreq,maxf[s[r]-'A']);
        while((r-l+1)-maxfreq >k){
            maxfreq=0;
            maxf[s[l]-'A']--;
            l++;
            for(int i =0;i<26;i++ ){
                maxfreq=max(maxfreq,maxf[i]);
            }
        }
        if((r-l+1)-maxfreq <=k){
            maxlen = max(maxlen,r-l+1 );
        }
        r++;
     }
     return maxlen ;
    }
};