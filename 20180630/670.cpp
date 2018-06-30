bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        while(num) {
            nums.push_back(num % 10);
            num /= 10;
        }
        reverse(nums.begin(), nums.end());
        vector<pair<int, int>> orig, idea;
        for (int i = 0; i < nums.size(); i++)
            orig.push_back({nums[i],i});
        idea = orig;
        sort(idea.begin(), idea.end(), cmp);
        for (int i = 0; i < orig.size(); i++) {
            if (orig[i].first < idea[i].first) {
                int j = i;
                while(idea[j].first == idea[j+1].first) j++;
                swap(nums[i], nums[idea[j].second]);
                break;
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            res = res*10+nums[i];
        return res;
    }
};