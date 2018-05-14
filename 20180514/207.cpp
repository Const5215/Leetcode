class Solution {
public:
    bool canFinish(int numcourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ind(numcourses);
        vector<vector<int>> nxt(numcourses);
        queue<int> q;
        for (int i = 0; i < prerequisites.size(); i++) {
            ind[prerequisites[i].first]++;
            nxt[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        for (int i = 0; i < numcourses; i++)
            if (ind[i] == 0) q.push(i);
        int cnt = 0;
        while(q.size()) {
            cnt++;
            int now = q.front();
            q.pop();
            for (int i = 0; i < nxt[now].size(); i++)
                if (--ind[nxt[now][i]] == 0) q.push(nxt[now][i]);
        }
        return cnt == numcourses;
    }
};