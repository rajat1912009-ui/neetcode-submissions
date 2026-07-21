class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //master list
        vector<vector<int>> result;

        //sort
        sort(nums.begin(), nums.end());

        //main loop
        for(int maindex = 0; maindex < nums.size() - 2; maindex++) {
            
            if(maindex > 0 && nums[maindex] == nums[maindex - 1]) {
                continue;
            }

            //the main loop will keep iterating, lets declare our pointers
            int low = maindex + 1;
            int high = nums.size() - 1;
            int target = -nums[maindex];

            //Pointers secured, lets start the two pointer search
            while(low < high) {
                int sum = nums[low] + nums[high];

                if(sum == target) {
                    result.push_back({nums[low], nums[high], nums[maindex]});

                    //skip duplicates
                    while(low < high && nums[low] == nums[low + 1]) low++;
                    while(low < high && nums[high] == nums[high - 1]) high--;

                    low++;
                    high--;
                } else if(sum < target){
                    low++;
                } else {
                    high--;
                 }
            }
        } 
        return result;
    }
};
