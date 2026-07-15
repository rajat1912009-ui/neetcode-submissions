class Solution {
public:

    string encode(vector<string>& strs) {
        //Lets make our encode
        //first we read the length of each string, and then we encode it 


        //Make our encoded string
        string encoded_string = "";
        //write the encode logic
        for(string& str : strs ) {
            //encode the entire string
            encoded_string += std::to_string(str.size()) + "#" + str;
        } 
        //encoded _string done, return it
        return encoded_string;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;


        //For the decoder, take the input encode string vector
        //and decode it, we use a while loop 
        while( i < s.length()) {
            
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            //god do i hate syntax
            //our j now cleanly stopping at the next # in the s

            string length_str = s.substr(i, j - i); // grab our length of word in s, currently a string
            int length = std::stoi(length_str); //now the integer length

            i = j + 1 + length; //move past the # and word

            //extract the word
            string word = s.substr(j + 1, length);
            
            //embed into result
            result.push_back(word);
            }
            //freedomm~ ~ ~
            return result;
            
        }
 
};
