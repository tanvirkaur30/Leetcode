class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;int rsum=0;
        for(int i=0;i<k;i++){//calculate the sum of the 1st window from the beginning means from left
            lsum=lsum+cardPoints[i];
        }
        int maxsum=lsum;//assume it is lsum is the maxsum
        int rightindex = cardPoints.size()-1;
        for(int i =k-1;i>=0;i--){
            lsum=lsum-cardPoints[i];
            rsum=rsum+cardPoints[rightindex];
            rightindex--;
            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum ;
    }
};