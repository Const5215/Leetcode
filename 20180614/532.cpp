class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        map<int,int> m;
        for(int x : nums) {
            m[x]++;
        }
        if (k < 0) return 0;
        int res = 0;
        if (k == 0) {
            for (auto it : m) 
                if (it.second > 1)
                    res++;
            return res;
        }
        map<int,int>::iterator i=m.begin(),j=m.begin();
        j++;
        while(j != m.end()) {
            while(j != m.end() && (*j).first-(*i).first < k) j++;
            if (j != m.end() && (*j).first-(*i).first == k)
                res++;
            i++;
        }
        return res;
    }
};