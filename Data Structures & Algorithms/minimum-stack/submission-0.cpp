class MinStack {
private:
    // pair<value, min_so_far>
    std::vector<std::pair<int, int>> st;

public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push_back({val, val});
        } else {
            // Compare val with the min_so_far of the previous top element
            int current_min = std::min(val, st.back().second);
            st.push_back({val, current_min});
        }
    }
    
    void pop() {
        st.pop_back(); // Removes the top element in O(1)
    }
    
    int top() {
        return st.back().first; // O(1)
    }
    
    int getMin() {
        return st.back().second; // O(1) constant time!
    }
};