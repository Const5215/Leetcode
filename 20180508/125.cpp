class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while(r > l) {
            while(r > l && isalpha(s[l]) == false && isdigit(s[l]) == false) l++;
            while(r > l && isalpha(s[r]) == false && isdigit(s[r]) == false) r--;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;r--;
        }
        return true;
    }
};