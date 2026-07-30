class Solution {
        public:
            bool isValid(std::string s) {
                    std::stack<char> st;
                            std::unordered_map<char, char> mp = {
                                        {')', '('},
                                                    {'}', '{'},
                                                                {']', '['}
                                                                        };

                                                                                for (char c : s) {
                                                                                            if (mp.count(c)) {
                                                                                                            if (st.empty() || st.top() != mp[c]) {
                                                                                                                                return false;
                                                                                                                                                }
                                                                                                                                                                st.pop();
                                                                                                                                                                            } else {
                                                                                                                                                                                            st.push(c);
                                                                                                                                                                                                        }
                                                                                                                                                                                                                }

                                                                                                                                                                                                                        return st.empty();
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                            };