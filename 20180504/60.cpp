class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        vector<int> frac(9);
        vector<bool> used(n);
        string res = "";
        frac[0] = 1;
        for (int i = 1; i <= 8; i++) frac[i] = frac[i-1] * i;
        for (int i = n-1; i >= 0 ; i--) {
            int ths = k/frac[i];
            k = k % frac[i];
            int cnt = 0,j;
            for (j = 0; cnt <= ths && j < n; j++) {
                if (used[j] == 0) cnt++;
            }
            used[--j] = 1;
            res = res + (char)(j+'1');
        }
        return res;
    }
};