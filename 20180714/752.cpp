class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int,int>> q;
        vector<bool> vis(10000);
        int tnum = stoi(target);
        for (int i = 0; i < deadends.size(); i++)
            vis[stoi(deadends[i])] = 1;
        if (vis[0]!=1){
            q.push({0,0});
            vis[0] = 1;
        }
        while(q.size()) {
            int now = q.front().first, step = q.front().second;
            q.pop();
            if (now == tnum)
                return step;
            int nxt;
            nxt = now%10 == 9?now-9:now+1;
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, step+1});
            }
            nxt = now%10 == 0?now+9:now-1;
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, step+1});
            }
            nxt = now/10%10 == 9?now-90:now+10;
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, step+1});
            }
            nxt = now/10%10 == 0?now+90:now-10;
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, step+1});
            }
            nxt = now/100%10 == 9?now-900:now+100;
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, step+1});
            }
            nxt = now/100%10 == 0?now+900:now-100;
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, step+1});
            }
            nxt = now/1000%10 == 9?now-9000:now+1000;
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, step+1});
            }
            nxt = now/1000%10 == 0?now+9000:now-1000;
            if (!vis[nxt]) {
                vis[nxt] = 1;
                q.push({nxt, step+1});
            }
        }
        return -1;
    }
};