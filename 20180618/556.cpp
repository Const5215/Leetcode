class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> b;
        for(; n; n/=10)
            b.push_back(n%10);
        reverse(b.begin(), b.end());
        if(!next_permutation(b.begin(), b.end()))
            return -1;
        long long res = 0;
        for (int i = 0; i < b.size(); i++)
            res = 10*res+b[i];
        return res <= INT_MAX? (int)res : -1;
    }
};