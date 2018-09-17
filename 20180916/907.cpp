class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int md = 1000000007;
        vector<long long> l(A.size()), r(A.size());
        stack<pair<int,int>> s;
        s.push({0,-1});
        for (int i = 0; i < A.size(); i++) {
            while(s.top().first >= A[i]) s.pop();
            l[i] = s.top().second;
            s.push({A[i],i});
        }
        while(s.size()) s.pop();        
        s.push({0,A.size()});
        for (int i = A.size()-1; i >= 0; i--) {
            while(s.top().first > A[i]) s.pop();
            r[i] = s.top().second;
            s.push({A[i],i});
        }
        long long t = 0, res = 0;
        for (int i = 0; i < A.size(); i++) {
            t = (long long)(i-l[i])*(r[i]-i);
            t %= md;t *= A[i];t %= md;
            res += t; res %= md;
        }
        return (int)res;
    }
};