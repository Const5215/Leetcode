class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int mx = A[0], pos = 0;
        for (int i = 0;i < A.size()-1; i++)
            if (A[i] > A[i+1]) {
                swap(A[i],A[i+1]);
                i++;
            }
        for (int i = 0;i < A.size()-1; i++)
            if (A[i] > A[i+1])
                return false;
        return true;
    }
};