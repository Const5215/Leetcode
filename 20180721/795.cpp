class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<int> Lbound(A.size()), Rbound(A.size());
        stack<pair<int,int>> s;
        s.push({INT_MAX,-1});
        for (int i = 0; i < A.size(); i++) {
            while(s.top().first < A[i]) s.pop();
            Lbound[i] = s.top().second+1;
            s.push({A[i], i});
        }
        while(s.size()) s.pop();
        s.push({INT_MAX, A.size()});
        for (int i = A.size()-1; i >= 0; i--) {
            while(s.top().first <= A[i]) s.pop();
            Rbound[i] = s.top().second-1;
            s.push({A[i], i});
        }
        int res = 0;
        for (int i = 0; i < A.size(); i++)
            if (A[i] >= L && A[i] <= R) {
                int l = i-Lbound[i]+1, r= Rbound[i]-i+1;
                res += l*r;
            }
        return res;
    }
};