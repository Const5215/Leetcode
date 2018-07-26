class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        for (int res = 1; res <= 2000; res++) {
            bool got = false, valid = true;
            for (int i = 0; i < fronts.size(); i++) {
                if (fronts[i] == res && backs[i] == res) {
                    valid = false;
                    break;
                }
                if (fronts[i] == res || backs[i] == res)
                    got = true;
            }
            if (got && valid)
                return res;
        }
        return 0;
    }
};