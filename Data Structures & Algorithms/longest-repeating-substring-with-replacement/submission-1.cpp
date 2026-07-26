#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0); // Frequency array for 'A'-'Z'
        int left = 0;
        int maxCount = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            // 1. Add current character to frequency map
            count[s[right] - 'A']++;
            
            // 2. Track the most frequent character seen in the current window
            maxCount = std::max(maxCount, count[s[right] - 'A']);

            // 3. Window size is (right - left + 1).
            // If replacements needed (window_size - maxCount) > k, shrink window!
            while ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // 4. Update max length seen so far
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};