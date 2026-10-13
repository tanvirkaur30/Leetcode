class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
       int n = heights.size();
       int maxarea = 0;
       for(int i =0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
          int elementindex=st.top();
          int nse = i;
          st.pop();
          int pse = st.empty() ? -1 : st.top();
          maxarea = max(maxarea,heights[elementindex]*(nse-pse-1));
        }
        st.push(i);
       }
       while(!st.empty()){
        int elementindex=st.top();
          int nse = n;
          st.pop();
          int pse =st.empty()?-1: st.top();
          maxarea = max(maxarea,heights[elementindex]*(nse-pse-1));
       }
       return maxarea;
    }
};