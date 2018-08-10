class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int md = 1000000007;
        vector<int> xpts, ypts;
        map<int,int> xloc,yloc;
        for (auto rectangle : rectangles) {
            xpts.push_back(rectangle[0]);
            xpts.push_back(rectangle[2]);
            ypts.push_back(rectangle[1]);
            ypts.push_back(rectangle[3]);
        }
        sort(xpts.begin(), xpts.end());
        sort(ypts.begin(), ypts.end());
        xpts.resize(unique(xpts.begin(), xpts.end())-xpts.begin());
        ypts.resize(unique(ypts.begin(), ypts.end())-ypts.begin());
        
        for (int i = 0; i < xpts.size(); i++)
            xloc[xpts[i]] = i;
        for (int i = 0; i < ypts.size(); i++)
            yloc[ypts[i]] = i;
        vector<vector<pair<bool, pair<int, int>>>> lst(xpts.size());
        for (auto rectangle : rectangles) {
            lst[xloc[rectangle[0]]].push_back({true, {yloc[rectangle[1]], yloc[rectangle[3]]}});
            lst[xloc[rectangle[2]]].push_back({false, {yloc[rectangle[1]], yloc[rectangle[3]]}});
        }
        vector<int> cov(ypts.size());
        long long res = 0;
        
        for (int i = 0; i < xpts.size(); i++) {
            long long xlen = (i == 0? 0: xpts[i]-xpts[i-1]);
            for (int i = 1; i < ypts.size(); i++) {
                if (cov[i] >= 1) {
                    long long ylen = ypts[i]-ypts[i-1];
                    res += (int)(xlen*ylen%md);
                    res %= md;
                }
            }
            for (auto ths : lst[i]) {
                if (ths.first == true) {
                    for (int i = ths.second.first+1; i <= ths.second.second; i++)
                        cov[i]++;
                }
                else {
                    for (int i = ths.second.first+1; i <= ths.second.second; i++)
                        cov[i]--;                    
                }
            }
        }
        return res;
    }
};