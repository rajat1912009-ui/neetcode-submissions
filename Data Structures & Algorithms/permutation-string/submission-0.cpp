class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
            int n1 = s1.length();
                    int n2 = s2.length();

                            // Edge case: s1 cannot fit inside s2 if it's longer
                                    if (n1 > n2) return false;

                                            // Our 26-element frequency arrays
                                                    std::vector<int> key(26, 0);
                                                            std::vector<int> window(26, 0);

                                                                    // 1. Build frequency map for 's1' (key) and the first window of 's2'
                                                                            for (int i = 0; i < n1; i++) {
                                                                                        key[s1[i] - 'a']++;
                                                                                                    window[s2[i] - 'a']++;
                                                                                                            }

                                                                                                                    // Check if the very first window is already a match
                                                                                                                            if (key == window) return true;

                                                                                                                                    // 2. Slide the fixed-size window across 's2'
                                                                                                                                            for (int i = n1; i < n2; i++) {
                                                                                                                                                        // Add the new character coming into the window
                                                                                                                                                                    window[s2[i] - 'a']++;

                                                                                                                                                                                // Remove the old character falling out of the window
                                                                                                                                                                                            window[s2[i - n1] - 'a']--;

                                                                                                                                                                                                        // Compare vectors directly (C++ compares all 26 elements in O(1))
                                                                                                                                                                                                                    if (key == window) return true;
                                                                                                                                                                                                                            }

                                                                                                                                                                                                                                    return false;
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                        };

