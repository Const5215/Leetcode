class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mx)
                mx = arr[i];
            if (mx <= i)
                res++;
        }
        return res;
    }
};