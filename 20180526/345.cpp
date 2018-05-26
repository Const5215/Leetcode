class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length()-1;
        while(r > l) {
            while(r > l && tolower(s[l])!='a' && tolower(s[l])!='e' && tolower(s[l])!='i' && tolower(s[l])!='o' && tolower(s[l])!='u') l++;
            while(r > l && tolower(s[r])!='a' && tolower(s[r])!='e' && tolower(s[r])!='i' && tolower(s[r])!='o' && tolower(s[r])!='u') r--;
            swap(s[l],s[r]);
            l++;r--;
        }
        return s;
    }
};