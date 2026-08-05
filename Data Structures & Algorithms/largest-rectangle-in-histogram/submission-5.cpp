class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {

            int currentheight = (i == n) ? 0 : heights[i];

            while(!st.empty() && currentheight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

            int width = st.empty() ? i : (i - st.top() - 1);

            maxarea = std::max(maxarea,h * width );
            }
            st.push(i);
        }
        return maxarea;
    }
};
