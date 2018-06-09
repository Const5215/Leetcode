class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        for (int l = (int)sqrt(area); l <= area; l++) {
            if (area%l == 0) {
                res.push_back(l);
                res.push_back(area/l);
                if (res[0] < res[1])
                    swap(res[0], res[1]);
                break;
            }
        }
        return res;
    }
};