class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0, k = A.size();
        for (int i = 1-k; i < k; i++)
            for (int j = 1-k; j < k; j++) {
                int now = 0;
                for (int x = 0; x < k; x++)
                    for (int y = 0; y < k; y++) {
                        int nx = x + i, ny = y + j;
                        if (A[x][y] && nx >= 0 && ny >= 0 && nx < k && ny < k && B[nx][ny])
                            now++;
                    }
                res = max(res, now);
            }
        return res;
    }
};