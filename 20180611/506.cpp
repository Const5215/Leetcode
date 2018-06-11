bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> ls;
        for (int i = 0; i < nums.size(); i++)
            ls.push_back({nums[i],i});
        sort(ls.begin(), ls.end(),cmp);
        vector<string> res(nums.size());
        if (nums.size() > 0)
            res[ls[0].second] = "Gold Medal";
        if (nums.size() > 1)
            res[ls[1].second] = "Silver Medal";
        if (nums.size() > 2)
            res[ls[2].second] = "Bronze Medal";
        for (int i = 3; i < nums.size(); i++)
            res[ls[i].second] = to_string(i+1);
        return res;
    }
};