class Solution {
public:
    int convert(string ths) {
        return ((ths[0]-'0')*10+(ths[1]-'0'))*60+(ths[3]-'0')*10+(ths[4]-'0');
    }
    int findMinDifference(vector<string>& timePoints) {
        int res = 1440;
        if (timePoints.size() > 1440)
            return 0;
        for (int i = 0; i < timePoints.size(); i++)
            for (int j = i+1; j < timePoints.size(); j++) {
                int a = convert(timePoints[i]), b = convert(timePoints[j]);
                if (a < b) swap(a,b);
                res = min(res, min(a-b, b-a+1440));
            }
        return res;
    }
};