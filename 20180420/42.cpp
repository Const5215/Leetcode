class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> L(height.size()), R(height.size());
        for (int i = 1; i < height.size(); i++)
            L[i] = max(L[i-1], height[i-1]);
        for (int i = height.size()-2 ; i >=0; i--)
            R[i] = max(R[i+1],height[i+1]);
        int res = 0;
        for (int i = 0; i < height.size(); i++)
            res += min(L[i], R[i]) > height[i] ? min(L[i], R[i])-height[i]: 0;
        return res;
    }
};