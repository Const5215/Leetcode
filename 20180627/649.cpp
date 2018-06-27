class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        for (int i = 0; i < senate.size(); i++)
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        while(r.size() && d.size()) {
            if (r.front() < d.front())
                r.push(r.front()+senate.size());
            else
                d.push(d.front()+senate.size());
            r.pop();d.pop();
        }
        return r.size()? "Radiant": "Dire";
    }
};