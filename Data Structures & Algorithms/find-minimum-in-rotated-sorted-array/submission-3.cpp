class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while(low < high) {

           int mid = low + (high - low) / 2;
        
        
        if(nums[mid] > nums[high]) {
            low = mid + 1;
        } else{
            high = mid;
        }


        }
return nums[low];
//learnings and fixes, no need for global int tracking when using binary search since the essence of binary search is to scan and halve and halve till you get a single optimal answer
//also track high and mid instead of low, you can just return low or high(since low == hihg at the end ) to get the minimum element
//i assume this can be teversed to find the maximum element
    }
};
