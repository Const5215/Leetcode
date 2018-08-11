class Solution {
public:
    int pos = 0;
    int find(const string& now) {
        int res = 0, mark = pos;
        while(pos < now.size() && now[pos] == '(') {
            pos++;
            res += find(now);
        }
        if (mark == pos)
            res++;
        else if (mark+2 <= pos)
            res *= 2;
        pos++;
        return res;
    }
    int scoreOfParentheses(string S) {
        int res = 0;
        while(pos < S.size()) {
            pos++;
            res += find(S);
        }
        return res;
    }
};