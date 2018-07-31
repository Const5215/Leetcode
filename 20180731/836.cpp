class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int xl = max(rec1[0], rec2[0]), xr = min(rec1[2], rec2[2]);
        int yl = max(rec1[1], rec2[1]), yr = min(rec1[3], rec2[3]);
        return (xr > xl && yr > yl);
    }
};