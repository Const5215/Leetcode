class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> prevcall;
        int last = 0;
        string tmp;
        for (string ths : logs) {
            istringstream iss(ths);
            int s,t;
            iss>>s;
            iss.ignore(1);
            getline(iss, tmp, ':');
            iss>>t;
            if (tmp[0] == 's') {
                if (prevcall.size())
                    res[prevcall.top()] += t-last;
                prevcall.push(s);
                last = t;
            }
            else {
                res[prevcall.top()] += t-last+1;
                prevcall.pop();
                last = t+1;
            }
        }
        return res;
    }
};