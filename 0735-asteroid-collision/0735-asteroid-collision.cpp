/*class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int>st;
       for(int i =0;i<asteroids.size();i++){
        if(asteroids[i]<0){
           while(!st.empty() && st.top()<abs(asteroids[i]) && st.top()>0){
            st.pop();
           }
           if(!st.empty() && st.top()==abs(asteroids[i])){
            st.pop();
           }
           else if(st.empty() || st.top()<0){
            st.push(asteroids[i]);
           }
        }
        else st.push(asteroids[i]);
       }
       vector<int>ans;
       int n =st.size();
       for(int i =0;i<n;i++){
        ans.push_back(st.top());
        st.pop();
       }*/
       class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } 
            else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back(); //if list is not empty or asteroids are equal destroy them both// 
                }
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);//if list means all right going asteroids are destroyed and we will store negative asteroids in the list
                }
            }
        }
        vector<int> ans(st.begin(), st.end());//store list elements in vector 
        return ans;
    }
};