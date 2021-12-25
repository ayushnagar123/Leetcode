class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> k;
        queue<char> q;
        int ans = 0;
        for(auto c: s){
            if(k.find(c)!=k.end()){
                while(k.size()!=0 && q.front()!=c){
                    k.erase(q.front());
                    q.pop();
                }
                q.pop();
            }
            k.insert(c);
            q.push(c);
            if(ans < q.size()){
                ans = q.size();
            }
        }
        return ans;
    }
};

// Runtime: 20 ms, faster than 51.35% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 11 MB, less than 19.73% of C++ online submissions for Longest Substring Without Repeating Characters.
