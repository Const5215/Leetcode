class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> L(dominoes.size()), R(dominoes.size());
        for (int i = 0; i < dominoes.size(); i++)
            if (dominoes[i] == 'L')
                R[i] = 0;
            else if (dominoes[i] == 'R')
                R[i] = 1;
            else
                R[i] = (i > 0 && R[i-1] > 0) ? R[i-1]+1: 0;
        for (int i = dominoes.size()-1; i >= 0; i--)
            if (dominoes[i] == 'R')
                L[i] = 0;
            else if (dominoes[i] == 'L')
                L[i] = 1;
            else
                L[i] = (i < dominoes.size()-1 && L[i+1] > 0) ? L[i+1]+1: 0;
        string res = "";
        for (int i = 0; i < dominoes.size(); i++)
            if (L[i] == 0 && R[i] == 0)
                res += '.';
            else if (L[i] == 0)
                res += 'R';
            else if (R[i] == 0)
                res += 'L';
            else if (L[i] < R[i])
                res += 'L';
            else if (L[i] > R[i])
                res += 'R';
            else
                res += '.';
        return res;
    }
};