class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nummap;


        //find the complement of each indice in nums
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];


        //find out if complement exists in our hash
        if (nummap.find(complement) != nummap.end()) {
            return {nummap[complement], i};

            
        } 
        //if it didnt in our previous loop, indice it in the hash map
        nummap[nums[i]] = i;

        }
        return {};
    }
};
