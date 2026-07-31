class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // stores indices

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove indices that are out of the current window boundary
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Maintain monotonic decreasing order (remove smaller elements from back)
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Add current element's index
            dq.push_back(i);

            // 4. Once we reach a full window size (i >= k - 1), append front element to result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};