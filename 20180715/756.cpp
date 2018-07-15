class Solution {
public:
    bool find(string now, string nxt, int pos, map<string, set<char>> &m) {
        if (now.size() == 1)
            return true;
        if (pos == now.size()-1)
            return find(nxt, "", 0, m);
        for (char x : m[now.substr(pos,2)])
            if (find(now, nxt+x, pos+1, m))
                return true;
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, set<char>> m;
        for (string now : allowed)
            m[now.substr(0,2)].insert(now[2]);
        return find(bottom, "", 0, m);
    }
};