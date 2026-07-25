class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charSet;
        int left = 0;
        int right = 0;
        int maxlength = 0;
        //iterate the window hahhhaa
        for(right = 0; right < s.size(); right++) {
            //while we move, shrink if we encounter a duplicate
            while(charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxlength = std::max(maxlength, right - left + 1);


        }
        return maxlength;
    }
};
