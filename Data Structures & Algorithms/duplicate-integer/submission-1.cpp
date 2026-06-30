class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> hash;

        for(int i = 0; i < nums.size(); i++)
        {
            if (hash.insert(nums[i]).second == false)
            {
                return true;
            } 
        }
        
    return false;
    }
};