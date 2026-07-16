class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         
         vector<int> result = {};
         int n = nums.size();

         //make array 1
         vector<int> rightside(n, 1);
         vector<int> leftside(n, 1);

         //now the snowballs are declared, 
         

         for(int i = n - 2; i >= 0; i--) {
            rightside[i] = rightside[i + 1] * nums[ i + 1];
         }

        for (int i = 1 ; i < n; i++) {
            leftside[i] = leftside[i - 1] * nums[i - 1];
        }

        //now the snowballs are filled


        //make the result
        for(int i = 0; i < n; i++) {
            int resultnum = leftside[i] * rightside[i];
            result.push_back(resultnum);
        }
        return result;
    }
};