class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while(l < r) {
            while(l < r && (A[l]&1) == 0) l++;
            while(l < r && (A[r]&1) == 1) r--;
            swap(A[l], A[r]);
        }
        return A;
    }
};