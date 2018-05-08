class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        while(rowIndex--) {
            vector<int> nxt;
            nxt.push_back(0);
            for (int i = 1;i < res.size(); i++)
                nxt.push_back(res[i]+res[i-1]);
            nxt.push_back(1);
            res = nxt;
        }
        vector<int> ans(res.begin()+1,res.end());
        return ans;
    }
};