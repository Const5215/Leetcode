class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size();
        while((r-l)/3 > 0) {
            int d = (r-l)/3;
            int mid1 = A[l+d];
            int mid2 = A[l+2*d];
            if (mid1 > mid2)
                r = l+2*d;
            else
                l = l+d;
        }
        return A[l] > A[l+1] ? l: l+1;
    }
};