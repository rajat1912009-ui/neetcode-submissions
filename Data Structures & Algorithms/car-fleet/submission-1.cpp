#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int, double>> cars(n);
        
        // Calculate time needed for each car
        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }
        
        // Sort by position descending (cars closest to target first)
        std::sort(cars.rbegin(), cars.rend());
        
        std::stack<double> st;
        for (const auto& car : cars) {
            st.push(car.second);
            // If behind car takes less/equal time than lead car, it merges!
            if (st.size() >= 2) {
                double currTime = st.top();
                st.pop();
                double leadTime = st.top();
                if (currTime > leadTime) {
                    st.push(currTime); // Forms a new fleet
                }
            }
        }
        
        return st.size();
    }
};