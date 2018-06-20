int gcd(int a,int b) {
    return a%b==0?b:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
class Solution {
public:
    string fractionAddition(string expression) {
        istringstream iss(expression);
        vector<pair<int,int>> frac;
        int a,b;
        while (iss>>a) {
            iss.ignore(1);
            iss>>b;
            frac.push_back({a,b});
        }
        int d = 1;
        for (auto it: frac)
            d = lcm(d,it.second);
        int n = 0;
        for (auto it: frac)
            n += it.first*d/it.second;
        bool f = 0;
        if (n < 0) {
            f = 1;
            n = -n;
        }
        int x = gcd(n,d);
        n /= x;d /= x;
        string res = f?"-":"";
        res += to_string(n);
        res += "/";
        res += to_string(d);
        return res;
    }
};