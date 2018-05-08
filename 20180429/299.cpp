class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> x(10,0),y(10,0);
        for (char i : secret)
            x[i-'0']++;
        int a = 0, b = 0;
        for (int i = 0; i < secret.size(); i++) {
            y[guess[i]-'0']++;
            if (secret[i] == guess[i]) a++;
        }
        for (int i = 0; i <= 9; i++)
            b += min(x[i],y[i]);
        b -= a;
        string res = to_string(a);
        res = res + 'A';
        res = res + to_string(b);
        res = res + 'B';
        return res;
    }
};