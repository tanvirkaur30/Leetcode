class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;int r=0;int maxlen =0; unordered_map<int,int>mp;
        while(r<fruits.size()){
           mp[fruits[r]]++;
           if(mp.size()>2){//if size increases more than 2
            while(mp.size()>2){// until its a vlid size remove from left
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
           }
           if(mp.size()<=2){
            maxlen = max(maxlen,r-l+1);
           }
           r++;
        }
        return maxlen ;
    }
};