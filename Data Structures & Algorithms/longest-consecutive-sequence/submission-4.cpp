class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set numSet(nums.begin(), nums.end());
        int Longeststreak = 0;


        //check if the number is the start of the loop
        for(int num : nums) {
            if(numSet.find(num - 1) == numSet.end()) {
                //n - 1 doesnt exist, meaning n is the first number of the sequence
                int currentnum = num;
                int currentstreak = 1;
            
            //increment the next elements of the sequence using a while loop
            //i wanted to add an edge case for duplicates but since hash_sets already drops duplicate numbers while storing data i can just ignore it
                while(numSet.find(currentnum + 1) != numSet.end()) {
                currentnum += 1;
                currentstreak += 1;                   
            }
            //current streak is maximized, push to Longeststreak

            Longeststreak = std::max(Longeststreak, currentstreak);
                }
        //boom done,
            }
            return Longeststreak;
}
};
