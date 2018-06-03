bool nxt(const string &a,const string &b) {
    if (a.length() != b.length()) return false;
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            cnt++;
            if (cnt > 1) return false;
        }
    }
    return true;
}

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        bool f = 0;
        for (string x : bank) {
            if (x == end) {
                f = 1;
                break;
            }
        }
        if (f==0) return -1;
        set<string> s;
        unordered_map<string, int> m;
        s.insert(start);
        s.insert(end);
        for (string x : bank)
            s.insert(x);
        vector< vector<int> > map(s.size());
        int cnt = 0;
        for (auto i : s)
            m[i] = cnt++;
        for (auto i = s.begin();i != s.end(); i++){
            auto j = i;
            j++;
            for (; j != s.end(); j++) {
                if (nxt(*i, *j)) {
                    map[m[*i]].push_back(m[*j]);
                    map[m[*j]].push_back(m[*i]);
                }
            }
        }
        vector<int> path(s.size(), INT_MAX);
        vector<bool> vis(s.size());
        queue<int> q;
        q.push(m[start]);
        vis[m[start]] = 1;
        path[m[start]] = 0;
        while(q.size()){
            int now = q.front();
            q.pop();
            for (int nxt : map[now]) {
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    path[nxt] = min(path[nxt], path[now]+1);
                    q.push(nxt);
                }
            }
        }
        return path[m[end]] == INT_MAX?-1:path[m[end]];
    }
};