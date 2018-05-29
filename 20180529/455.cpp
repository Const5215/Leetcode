class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<int> >p(g.begin(),g.end()), q(s.begin(),s.end());
        int res = 0;
        while(p.size() && q.size()) {
            while(q.size() && q.top() < p.top()) q.pop();
            if (p.size() && q.size()) {
                p.pop();
                q.pop();
                res++;
            }
        }
        return res;
    }
};