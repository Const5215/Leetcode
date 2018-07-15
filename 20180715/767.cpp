class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, char>> q;
        map<char, int> m;
        for (char x : S)
            m[x]++;
        for (auto it : m) {
            if (it.second > (S.size()+1)/2)
                return "";
            q.push({it.second, it.first});
        }
        string res = "";
        queue<pair<int, char>> tmp;
        while(!q.empty() || tmp.size() > 1){
            if(tmp.size() > 1) {
                auto cur = tmp.front();
                tmp.pop();
                if (cur.first != 0)
                    q.push(cur);
            }
            if (!q.empty()) {
                auto cur = q.top();
                q.pop();
                res += cur.second;
                cur.first--;
                tmp.push(cur);
            }
        }
        return res;
    }
};