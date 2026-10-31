class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0; vector<int>lastseen(3,-1);int minindex=0;
        for(int i =0;i<s.size();i++){
           lastseen[s[i]-'a']=i;
           if(lastseen[0]!=-1 && lastseen[1]!=-1 &&  lastseen[2]!=-1){
                minindex=min({lastseen[0],lastseen[1],lastseen[2]});
                 count += (1+minindex);
           }
          
        }
        return count;
    }
};