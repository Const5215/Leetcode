class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int, int> m;
        int r = 0, mx = 0;
        for (int i = 0; i < tree.size(); i++) {
            m[tree[i]]++;
            while (m.size() > 2) {
                m[tree[r]]--;
                if (m[tree[r]] == 0) m.erase(tree[r]);
                r++;
            } 
            mx = max(mx, i-r+1);
        }
        return mx;
    }
};