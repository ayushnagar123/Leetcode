class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};


// Runtime: 4 ms, faster than 94.16% of C++ online submissions for Palindrome Number.
// Memory Usage: 5.7 MB, less than 91.06% of C++ online submissions for Palindrome Number.