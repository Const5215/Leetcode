class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = INT_MAX;
        for (auto ghost : ghosts) 
            dis = min(dis, abs(ghost[0]-target[0])+abs(ghost[1]-target[1]));
        return dis > (abs(target[0])+abs(target[1]));
    }
};