class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     //im so goddamn tired lets get this over with
     //we can treat the whole 2d matrix like a 1d array for our pointers
     //how do we access their values then since 1d pointers break?
     //column = mid / 2 (how many rows skipped,
     //row = mid % 2 (modulo), itadakimasu (how many gaps to be filled after fullfilling)
     int m = matrix.size(), n = matrix[0].size();
     int low = 0, high = (m * n) - 1;
    
     while(low <= high) {

        //now we have a loop, we need to declare our mid value
        int mid = low + (high - low) / 2;

        //return the value of the 2d index of low/high
        int row = mid / n;
        int column = mid % n;

        //valueeeee
        int val = matrix[row][column];

        //finally algorithm
        if(val == target) {
            return true;
        } else if( val < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
            }
     }

     //tbh if it hasnt succeeded yet, no shit in the matrix
     return false;   
    }
};
