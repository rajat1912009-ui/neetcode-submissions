class Solution {
public:
    int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

//we check if the 2 halves from mid are sorted, and if yes, does target exist in it

    while(low <= high) {
        int mid = low + (high - low) / 2;


        if(nums[mid] == target) {
            return mid;
        }
//left sort check
        if(nums[low] <= nums[mid]) {
        //left is sorted, is target in left?
        if(nums[low] <= target && target <= nums[mid]) {
            //if true, search left
            high = mid - 1;
            } else {
            //if not true search right
            low = mid + 1;
        }        
    }
    //RIGHT MUST be sorted if this fails
    else {
        if(nums[mid] <= target && target <= nums[high]) {
            //check right
            low = mid + 1;
            } else {
            //otherwise search left
            high = mid - 1;
                }
            }
        }
    //if it all failed, it just doesnt exist twin
    return -1;

    }
};
