class Solution {
public:
    int maxArea(vector<int>& heights) {
        int largestarea = 0;

        //declare our two pointers
        int tower1 = 0;
        int tower2 = heights.size() - 1;

        //now we need to check the area every time we move to the next optimal tower, so lets declare a for loop
            while(tower1 < tower2) {
            //find the area of whatever tower we are on
            int area = (tower2 - tower1) * std::min(heights[tower1], heights[tower2]);
            largestarea = std::max(largestarea, area);

            if(heights[tower1] < heights[tower2]) {
                tower1++;
            } else {
                tower2--;
            }
        //according to my heavy calculations, it should be done be now
        }
        return largestarea;
    }
};
