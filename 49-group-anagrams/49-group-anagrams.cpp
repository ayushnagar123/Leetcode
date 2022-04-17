class Solution {
public:
    string sortString(string s1) {
        sort(s1.begin(), s1.end());
        return s1;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        map<string, vector<string>> mp;

        int i, j;
        for(i=0; i<strs.size(); i++) {
            mp[sortString(strs[i])].push_back(strs[i]);
        }
        
        for(auto p:mp) {
            groups.push_back(p.second);
        }
        return groups;
    }
};