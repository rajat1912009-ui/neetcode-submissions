class Solution {
public:
    bool isAnagram(string s, string t) {
       //Initial length check
       if(s.length() != t.length())
       {
        return false;
       }

       //declare a fixed size array hash
       int count[26] = {0};

       //filling/emptying buckets
       for(int i = 0; i < s.length(); i++)
       {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
        }

        //final bucket empty check, if all buckets empty, is a valid anagram
        for(int i = 0; i < 26; i++)
        {
            if (count[i] != 0) {
                return false;
            }
            
        } return true;
    }
};
