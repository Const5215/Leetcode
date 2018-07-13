class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        if (it != letters.end())
            return *it;
        else 
            return letters[0];
    }
};