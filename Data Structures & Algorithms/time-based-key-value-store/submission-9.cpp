class TimeMap {
    private:
            //we gonna do this with a vector<timestamp, value> inside a hash map with keys
            unordered_map<string, vector<pair<int, string>>> store = {};

            public:
                TimeMap() {}

                    void set(string key, string value, int timestamp) {
                        store[key].push_back({timestamp, value});
                            }
                                //now that our declaration of class is done, we need to design adding the elements
                                    
                                        string get(string key, int timestamp) {
                                            if(store.find(key) == store.end()) {
                                                    return "";
                                                        } 
                                                            //standard binary search to find latest timestamp letter
                                                                const auto& list = store[key];
                                                                    int left = 0;
                                                                        int right = list.size() - 1;
                                                                            string res = "";

                                                                                while(left <= right) {
                                                                                        int mid = left + (right - left) / 2;
                                                                                            
                                                                                                    if(list[mid].first <= timestamp) {
                                                                                                    //if mid is a valid timestamp

                                                                                                            res = list[mid].second;

                                                                                                                    left = mid + 1;            
                                                                                                                            }  else {
                                                                                                                                            right = mid - 1;
                                                                                                                                                        }
                                                                                                                                                                }
                                                                                                                                                                    
                                                                                                                                                                    return res;
                                                                                                                                                                        }  
                                                                                                                                                                        };
                                                                                                                                                                        
