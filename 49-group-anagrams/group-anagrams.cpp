class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());  // canonical form for anagrams
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& kv : groups) {
            result.push_back(move(kv.second));
        }
        return result;
    }
};
