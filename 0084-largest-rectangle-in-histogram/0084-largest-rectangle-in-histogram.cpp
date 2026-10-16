class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     stack<int>st;
     int maxarea = 0;
     int n=heights.size();
     for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int elementindex=st.top();
            st.pop();
            int nse = i;
            int pse = st.empty()? -1:st.top();
            maxarea= max(maxarea,heights[elementindex]*(nse-pse-1));
        }
        st.push(i);
     }
     while(!st.empty() ){
            int elementindex=st.top();
            st.pop();
            int nse = n;
            int pse = st.empty()? -1:st.top();
            maxarea= max(maxarea,heights[elementindex]*(nse-pse-1));
        }
        return maxarea;
    }
};










































   /*stack<int> st;
       int n = heights.size();
       int maxarea = 0;
       for(int i =0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
          int elementindex=st.top();//find areaf or the element at this index 
          int nse = i;//current element's index becomes the nse 
          st.pop();
          int pse = st.empty() ? -1 : st.top();//after popping the the top becomes the pse for the element at index elementindex
          maxarea = max(maxarea,heights[elementindex]*(nse-pse-1));
        }
        st.push(i);//push current index in the stack 
       }
       while(!st.empty()){//if after complete pass there are still elements left in the stack 
        int elementindex=st.top();
          int nse = n;//then their nse becomes n because no nse exists after complete traversal 
          st.pop();
          int pse =st.empty()?-1: st.top();
          maxarea = max(maxarea,heights[elementindex]*(nse-pse-1));
       }
       return maxarea;*/