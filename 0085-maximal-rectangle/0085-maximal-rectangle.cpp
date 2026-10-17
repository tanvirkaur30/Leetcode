class Solution {
public:
    int largesthist(vector<int> &heights){
        stack<int> st;int maxarea=0;int n =heights.size();
       for(int i =0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int elementindex=st.top();
            st.pop();
            int nse = i;
            int pse = st.empty()?-1:st.top();
            maxarea=max(maxarea,heights[elementindex]*(nse-pse-1));
        }
        st.push(i);
       }
       while(!st.empty() ){
            int elementindex=st.top();
            st.pop();
            int nse = n;
            int pse = st.empty()?-1:st.top();
            maxarea=max(maxarea,heights[elementindex]*(nse-pse-1));
        }
        return maxarea;
    }
   
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int n=matrix.size();int m=matrix[0].size();vector<vector<int>>ps(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum =0;
            for(int i=0;i<n;i++){
                sum=sum+(matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum =0;
                ps[i][j]=sum;
            }
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,largesthist(ps[i]));
        }
        return maxarea;
    }
};