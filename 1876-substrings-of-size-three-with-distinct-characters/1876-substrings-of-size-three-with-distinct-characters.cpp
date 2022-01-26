class Solution {
public:
    int countGoodSubstrings(string s) {
        queue<char> q;
        map<char, int> k;
        int i = 0;
        int ans = 0;
        char front;
        for(auto c: s){
            q.push(c);
            if(i>=3){
                front = q.front();
                q.pop();
                k[front]--;
                if(k[front]==0){
                    k.erase(front);
                }
            }
            if(k.find(c)!=k.end()){
                k[c]++;
            }
            else{
                k[c] = 1;
            }
            if(k.size()==3){
                ans++;
            }
            i++;
        }
        return ans;
    }
};

// Runtime: 4 ms, faster than 36.63% of C++ online submissions for Substrings of Size Three with Distinct Characters.
// Memory Usage: 6.9 MB, less than 12.49% of C++ online submissions for Substrings of Size Three with Distinct Characters.
