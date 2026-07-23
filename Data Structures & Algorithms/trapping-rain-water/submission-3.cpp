class Solution {
public:
    int trap(vector<int>& height) {
    int totalarea = 0;
    int left = 0;
    int right = height.size() - 1;
    int left_max = 0;
    int right_max = 0;

    while(left < right) {

    left_max = std::max(left_max, height[left]);
    right_max = std::max(right_max, height[right]);

    if(left_max < right_max) {
    int waterarea = left_max - height[left];
    totalarea += waterarea;
    left++;
    } else {
        int waterarea = right_max - height[right];
        totalarea += waterarea;
        right--;
    }
    }
    return totalarea;


    }

};
