class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> res(n, 0);
        std::stack<int> st; // Stores indices

        for (int i = 0; i < n; ++i) {
            // Pop indices while current temp is warmer than stack's top temp
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIdx = st.top();
                st.pop();
                res[prevIdx] = i - prevIdx; // Distance = days waited
            }
            st.push(i);
        }

        return res;
    }
};