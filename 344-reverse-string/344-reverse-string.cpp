class Solution {
public:
    void recursion_helper(vector<char> &s, int start, int end){
            if(start >= end) return;
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            recursion_helper(s, start+1, end-1);
    }
    
    void reverseString(vector<char>& s) {
        recursion_helper(s, 0, s.size()-1);
    }
};

// Runtime: 24 ms, faster than 50.40% of C++ online submissions for Reverse String.
// Memory Usage: 23.3 MB, less than 39.26% of C++ online submissions for Reverse String.