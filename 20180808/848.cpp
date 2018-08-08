class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for (int i = shifts.size()-1; i >= 0 ; i--) {
            if (i != shifts.size()-1)
                shifts[i] += shifts[i+1];
            shifts[i] %= 26;
        }
        for (int i = 0; i < S.size(); i++)
            S[i] = (S[i]+shifts[i]) > 'z' ? S[i]+shifts[i]-26: S[i]+shifts[i];
        return S;
    }
};