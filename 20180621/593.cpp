double len(vector<int>& a, vector<int>& b) {
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<double> p;
        p.push_back(len(p1,p2));
        p.push_back(len(p1,p3));
        p.push_back(len(p1,p4));
        p.push_back(len(p2,p3));
        p.push_back(len(p2,p4));
        p.push_back(len(p3,p4));
        sort(p.begin(),p.end());
        double eps = 1e-8;
        if (abs(p[0]-p[1]) < eps && abs(p[0]-p[2]) < eps && abs(p[0]-p[3]) < eps && abs(p[4]-p[5]) < eps && abs(p[0]-p[4]) > eps)
            return true;
        else
            return false;
    }
};