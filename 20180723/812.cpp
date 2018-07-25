class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (int i = 0; i < points.size(); i++)
            for (int j = i+1; j < points.size(); j++)
                for (int k = j+1; k < points.size(); k++) {
                    int x_1 = points[j][0]-points[i][0],x_2 = points[k][0]-points[i][0];
                    int y_1 = points[j][1]-points[i][1],y_2 = points[k][1]-points[i][1];
                    res = max(res, abs(x_1*y_2-x_2*y_1)/2.0);
                }
        return res;
    }
};