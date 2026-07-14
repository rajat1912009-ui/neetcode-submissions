class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //declare our inital hash map first
        std::unordered_map<int, int> map;


        //fill the map
        for(int num : nums) {
            map[num]++;
        }

        //declare our inverted array
        vector<vector<int>> frequencylist(nums.size() + 1);

        //fill the inverted array, the already sorted indices are the descending order sort
        for(const auto& pair : map) {
            //get the first valye of the map(key)

            int num = pair.first;
            
            //get the second value of the hash map(frequency)
            int freq = pair.second;

            frequencylist[freq].push_back(num);

        }//exit the loop safely

        vector<int> result;
        
        for(int i = frequencylist.size() - 1; i >= 0; i--) {
            for(int num : frequencylist[i]) {
                
                result.push_back(num);
                if(result.size() == k) {
                    return result;
                }
            }
            
        }
        //result done
        return result;

    }
};
