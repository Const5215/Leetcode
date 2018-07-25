class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int p = 0;
        vector<pair<char, int>> ths;
        char x;int cnt;
        while(p < S.size()) {
            x = S[p];
            cnt = 1;
            while(p < S.size()-1 && S[p] == S[p+1]) {
                cnt++;
                p++;
            }
            ths.push_back({x, cnt});
            p++;
        }
        int res = 0;
        for (string word : words) {
            vector<pair<char, int>> tmp;
            bool f = 1;
            p = 0;
            while(p < word.size()) {
                x = word[p];
                cnt = 1;
                while(p < word.size()-1 && word[p] == word[p+1]) {
                    cnt++;
                    p++;
                }
                tmp.push_back({x, cnt});
                p++;
            }
            if (tmp.size() != ths.size())
                f = 0;
            else {
                for (int i = 0; i < tmp.size(); i++) {
                    if (tmp[i].first != ths[i].first) {
                        f = 0;
                        break;
                    }
                    else if (ths[i].second >= 3){
                        if (ths[i].second < tmp[i].second) {
                            f = 0;
                            break;
                        }
                    }
                    else {
                        if (ths[i].second != tmp[i].second) {
                            f = 0;
                            break;
                        }
                    }
                }
            }
            if (f)
                res++;
        }
        return res;
    }
};