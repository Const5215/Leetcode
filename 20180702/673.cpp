class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> rec;//{len,cnt}
        for (int i = 0; i < nums.size(); i++) {
            int nowlen = 0;
            int nowcnt = 1;
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i] && rec[j].first >= nowlen) {
                    if (rec[j].first == nowlen)
                        nowcnt+=rec[j].second;
                    else {
                        nowlen = rec[j].first;
                        nowcnt = rec[j].second;
                    }
                }
            nowlen++;
            rec.push_back({nowlen,nowcnt});
        }
        int mx = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (rec[i].first == mx)
                res += rec[i].second;
            else if (rec[i].first > mx) {
                mx = rec[i].first;
                res = rec[i].second;
            }
        }
        return res;
    }
};