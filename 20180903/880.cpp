class Solution {
public:
    string decodeAtIndex(string S, int K) {
        stack<string> s;stack<long long> n;
        string now_s = "";
        char tail;
        long long nowlen = 0;
        for (char x : S) {
            if (isdigit(x)) {
                s.push(now_s);
                n.push(nowlen);
                nowlen *= (x-'0');
                if (nowlen >= K) break;
                now_s="";
            }
            else {
                now_s += x;
                tail = x;
                nowlen++;
                if (nowlen >= K) break;
            }
        }
        string res = "";
        if (nowlen == K) 
            return res+tail;
        while(!s.empty()) {
            now_s = s.top();nowlen = n.top();s.pop();n.pop();
            K %= nowlen;
            if (K == 0) {
                while(s.size() && now_s == "") {
                    now_s = s.top();
                    s.pop();
                }
                return res+now_s.back();
            }
            if (K > nowlen-now_s.size()) {
                K -= nowlen-now_s.size();
                return res+now_s[K-1];
            }         
        }
    }
};