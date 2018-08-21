class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        vector<int> num(A.size());
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++) {
                num[i] <<= 1;
                if (A[i][j] == 1)
                    num[i] ++;
            }
        int mx = (1<<A.size())-1,top = (1<<A[0].size())-1, res = 0;
        for (int i = 0; i <= top; i++){
            int tmp = 0;
            for (int j = 0; j < A.size(); j++)
                tmp += max(num[j]^i, top^num[j]^i);
            res = max(res, tmp);
        }
        return res;
    }
};