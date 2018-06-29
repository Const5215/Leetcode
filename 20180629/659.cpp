class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> m;
        for (int x : nums)
            m[x]++;
        int a = 0, b = 0, c = 0;
        //a:2left b:1left c:avaliable
        map<int,int>::iterator bef = m.begin(), it = m.begin();
        a = it->second;it++;
        while(it != m.end()) {
            if (it->first != bef->first+1) {
                if (a+b != 0)
                    return false;
                a = it->second;
                b = 0;
                c = 0;
            }
            else {
                if (a+b > it->second)
                    return false;
                int tmp = it->second-a-b;
                int na = c > tmp ? 0: tmp-c;
                int nb = a;
                int nc = it->second-na-nb;
                a = na;
                b = nb;
                c = nc;
            }
            bef = it;
            it++;
        }
        if (a+b != 0)
            return false;
        return true;
    }
};