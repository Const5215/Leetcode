class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> d,orig;
        while(N) {
            d.push_back(N%10);
            N = N/10;
        }
        reverse(d.begin(), d.end());
        int  p = 0;
        while(p < d.size()-1 && d[p] <= d[p+1])
            p++;
        if (p < d.size()-1)
            d[p]--;
        for (int i = p+1; i < d.size(); i++)
            d[i] = 9;
        for (int j = p-1; j >= 0; j--)
            if (d[j] > d[j+1]) {
                d[j]--;
                d[j+1] = 9;
            }
        int res = 0;
        for (int i = 0; i < d.size(); i++) {
            res *= 10;
            res += d[i];
        }
        return res;    
    }
};