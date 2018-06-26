class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int, vector<int>> loc;
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
            for (int x : nums[i]) {
                loc[x].push_back(i);
                s.insert(x);
            }
        vector<int> vis(nums.size());
        int cnt = 0;
        set<int>::iterator i = s.begin(),j = s.begin(); 
        while(cnt < nums.size()) {
            for (int x : loc[(*j)]) {
                    vis[x]++;
                    if (vis[x] == 1)
                        cnt++;
                }
            if (cnt < nums.size())
                j++;
        }
        vector<int> res(2);
        int len = INT_MAX;
        res[0] = *i, res[1] = *j;
        len = (*j)-(*i);
        
        while(j != s.end()) {
            for (int x : loc[(*i)]) {
                vis[x]--;
                if (vis[x] == 0)
                    cnt--;
            }
            i++;
            while(j != s.end() && cnt < nums.size()) {
                j++;
                if (j == s.end())
                    break;
                for (int x : loc[(*j)]) {
                    vis[x]++;
                    if (vis[x] == 1)
                        cnt++;
                }                
            }
            if (j != s.end() && ((*j)-(*i) < len)) {
                len = (*j)-(*i);
                res[0] = *i, res[1] = *j;
            }
        }
        return res;
    }
};