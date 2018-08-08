class Solution {
public:
    vector<int> res;
    bool check(string X, string Y, string S) {
        res.clear();
        long long a = 0, b = 0, c = 0;
        if ((X[0] == '0' && X.size() != 1)|| (Y[0] == '0' && Y.size() != 1))
            return false;
        for (int i = 0; i < X.size(); i++) {
            a*=10;a+=X[i]-'0';
            if (a > INT_MAX)
                return false;
        }
        for (int i = 0; i < Y.size(); i++) {
            b*=10;b+=Y[i]-'0';
            if (b > INT_MAX)
                return false;
        }
        string tmp = X+Y;
        res.push_back((int)a);res.push_back((int)b);
        do {
            c = a+b;
            if (c > INT_MAX)
                return false;
            res.push_back((int)c);
            tmp += to_string(c);
            a = b;b = c;
        }while(tmp.size() < S.size());
        
        return tmp == S;
    }
    vector<int> splitIntoFibonacci(string S) {
        for (int i = 2; i < S.size(); i++)
            for (int j = 1; j < i; j++) {
                if (check(S.substr(0,j), S.substr(j, i-j), S))
                    return res;
            }
        res.clear();
        return res;
    }
};