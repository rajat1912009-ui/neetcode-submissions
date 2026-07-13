class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramgroups;

        for(const std::string& s : strs) {
            //do the juicy frequency shit
            int count[26] = {0};

            //count all letters
            for(char c : s) {
                count[c - 'a']++; 
            }

            //now that we have our unique buckets filled with the characters, lets generate a unique barcode
            std::string key = "";
            for(int i = 0; i <26; i++) {
                //string key made, now to generate code, we use to_string which inputs integers into strings
                key += std::to_string(count[i]) + "#";
            }
            //code generated, lets input the strings s from strs into our anagramgroups map using the unique generated key
            anagramgroups[key].push_back(s);

            //by the time, all of our list should be populated with the anagram sorted words
            //so lets return the value
                   
        }//exit for loop since the map is done

        //the question demands a string vector inside a vector 
        std::vector<std::vector<std::string>> result;

        //letspack the results inside the final result list, we use auto& for the easy type usability

        for(auto& pair : anagramgroups) {

            //the pair.second value in our anagramgroups map is the value of the unique keys we geenrated, aka the anagrams
            result.push_back(pair.second);
        } //boom result, aka our final answer list is done. lets report that.
            return result;
    }
};
//lmao i forgot to close the count letters loop, which i think trapped my entire code into a recurring loop.