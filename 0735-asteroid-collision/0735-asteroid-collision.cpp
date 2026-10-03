class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {

            while (!st.empty() && st.back() > 0 && a < 0) {

                if (st.back() < -a) {
                    // Stack asteroid explodes
                    st.pop_back();
                }
                else if (st.back() == -a) {
                    // Both explode
                    st.pop_back();
                    a = 0;
                    break;
                }
                else {
                    // Current asteroid explodes
                    a = 0;
                    break;
                }
            }

            if (a != 0)
                st.push_back(a);
        }

        return st;
    }
};