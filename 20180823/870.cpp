class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<pair<int, int>> temp(B.size());
        for (int i = 0; i < B.size(); i++)
            temp[i] = {B[i], i};
        sort(temp.begin(), temp.end());
        sort(A.begin(), A.end());
        vector<int> res(A.size());
        vector<bool> vis(A.size());
        int p=0,q=0;
        for (int i = 0; i < B.size(); i++) {
            while(p < A.size() && A[p] <= temp[i].first) p++;
            if (p < A.size()) {
                res[temp[i].second] = A[p];
                vis[p] = 1;
                p++;
            }
            else {
                while(q < A.size() && vis[q]) q++;
                res[temp[i].second] = A[q];
                q++;
            }
        }
        return res;
    }
};