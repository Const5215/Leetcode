class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size());
        queue<int> q;q.push(0);vis[0] = 1;
        while(q.size()) {
            int now = q.front();q.pop();
            for (int nxt : rooms[now]) {
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
        for (int i = 0; i < rooms.size(); i++)
            if (!vis[i])
                return false;
        return true;
    }
};