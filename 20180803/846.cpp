class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size()%W != 0)
            return false;
        int k = hand.size()/W;
        map<int, int> m;
        for (int x : hand)
            m[x]++;
        while(k--) {
            int now = m.begin()->first;
            auto it = m.begin();
            for (int i = 0; i < W; i++) {
                if (it == m.end() || it->first != now)
                    return false;
                auto nxt = it;nxt++;
                it->second--;
                if (it->second == 0)
                    m.erase(it);
                now++;it = nxt;
            }
        }
        return true;
    }
};