class Solution {
public:
    int longestMountain(vector<int>& A) {
        vector<int> l(A.size()), r(A.size());
        for (int i = 0; i < A.size(); i++)
            l[i] = (i == 0 || A[i-1] >= A[i])? 1: l[i-1]+1;
        for (int i = A.size()-1; i >= 0 ; i--)
            r[i] = (i == A.size()-1 || A[i+1] >= A[i])? 1: r[i+1]+1;
        int res = 0;
        for (int i = 0; i < A.size(); i++)
            if (l[i] > 1 && r[i] > 1)
                res = max(res, l[i]+r[i]-1);
        return res;
    }
};