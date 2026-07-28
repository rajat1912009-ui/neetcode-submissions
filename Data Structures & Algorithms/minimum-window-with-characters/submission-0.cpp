class Solution {
public:
    string minWindow(string s, string t) {
            if (t.empty() || s.empty()) return "";

                    unordered_map<char, int> countT, window;
                            for (char c : t) {
                                        countT[c]++;
                                                }

                                                        int have = 0, need = countT.size();
                                                                int resLen = INT_MAX;
                                                                        pair<int, int> res = {-1, -1};

                                                                                int l = 0;
                                                                                        for (int r = 0; r < s.length(); r++) {
                                                                                                    char c = s[r];
                                                                                                                window[c]++;

                                                                                                                            if (countT.count(c) && window[c] == countT[c]) {
                                                                                                                                            have++;
                                                                                                                                                        }

                                                                                                                                                                    // Shrink window from the left while it remains valid
                                                                                                                                                                                while (have == need) {
                                                                                                                                                                                                // Update result if this window is smaller
                                                                                                                                                                                                                if ((r - l + 1) < resLen) {
                                                                                                                                                                                                                                    resLen = r - l + 1;
                                                                                                                                                                                                                                                        res = {l, r};
                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                        // Pop from left of window
                                                                                                                                                                                                                                                                                                        window[s[l]]--;
                                                                                                                                                                                                                                                                                                                        if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                                                                                                                                                                                                                                                                                                                                            have--;
                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                            l++;
                                                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                                                                                        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                            };

