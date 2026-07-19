class Solution {
public:
    bool isPalindrome(string s) {
        //declare left and right pointers
        int left = 0;
        int right = s.length() - 1;

        //ignore all non alphabetic and numeric ascii and move on
        while(left < right) {
            while(left < right && !std::isalnum(s[left])) {
                left++;
            }

        //ignore all non alphabetic and numeric ascii and move on
        while(left < right && !std::isalnum(s[right])) {
            right--;
        }

        //compare the lower case of the left and right pointers
        if(std::tolower(s[left]) != std::tolower(s[right])) {
           
           //return false if they are not equal i.e. they are not a palindrome
            return false;
        }

        //if they are equal, move on to the centre
        left++;
        right--;

        }
        //if the main loop finished cleanly, meaning it is a valid palindrome
        return true;
    }
};
