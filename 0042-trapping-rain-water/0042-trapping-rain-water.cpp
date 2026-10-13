class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0;
        int rightmax=0;
        int l=0;int r =height.size()-1;
        int total=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>leftmax){
                    leftmax=height[l];
                }else total+=leftmax-height[l];

            l++;
            } 
            else {
                if(height[r]>rightmax){
                    rightmax=height[r];
                }else total+=rightmax-height[r];

            r--;
            }   
            }
            return total;
        }
};




/*int l=0;
int r=n-1;
int leftmax =0;
int rightmax =0;
long long total =0;
while(l<r){
    if(height[l]<height[r]){
        if(height[l]>=leftmax){
            leftmax =height[l];
        }else total = total + leftmax -height[l];
        l++;
    }else{
        if(height[r]>=rightmax){
            rightmax =height[r];
        }else total = total + rightmax -height[r];
        r--;
    
    }
}
return total;*/





