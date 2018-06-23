class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tot = 0, res = 0;
        vector<int> cd(26),cnt(26);
        for (char x : tasks)
            cnt[x-'A']++;
        while(tot < tasks.size()) {
            int ths = -1, ths_cnt = 0;
            for (int i = 0; i < 26; i++)
                if (cnt[i] && cd[i] == 0 && ths_cnt < cnt[i]) {
                    ths = i;
                    ths_cnt = cnt[i];
                }
            for (int i = 0; i < 26; i++)
                if (cd[i]) cd[i]--;
            if (ths != -1) {
                tot++;
                cnt[ths]--;
                cd[ths] = n;
            }
            res++;
        }
        return res;
    }
};