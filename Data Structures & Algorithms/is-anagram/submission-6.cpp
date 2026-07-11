class Solution {
public:

    bool isAnagram(string s, string t) {

        static bool speedup = []() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        return 0;
    }();

    
       //Initial length check
       if(s.length() != t.length())
       {
        return false;
       }

       //declare a fixed size array hash
       char count[26] = {0};

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
