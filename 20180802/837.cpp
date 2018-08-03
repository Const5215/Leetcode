class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> sum(K + W); // cumulative sum
        sum[0] = 1;
        for (int i = 1; i <= K + W - 1; i++) {
            int t = min(i - 1, K - 1);
            if (i <= W) {
                sum[i] = sum[i - 1] + sum[t] / W;
            } else {
                sum[i] = sum[i - 1] + max((sum[t] - sum[i - W - 1]) / W, 0.0);
            }
        }
        double result = (sum[min(N, K + W - 1)] - sum[K - 1]) / (sum[K + W - 1] - sum[K - 1]);
        return result;
    }
};