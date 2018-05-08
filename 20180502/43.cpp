class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> a,b;
        for (int i = num1.size()-1; i >= 0; i--) a.push_back(num1[i]-'0');
        for (int i = num2.size()-1; i >= 0; i--) b.push_back(num2[i]-'0');
        vector<int> res(num1.size()+num2.size(),0);
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++)
                res[i+j] += a[i]*b[j];
        for (int i = 0 ; i < res.size() - 1; i++) {
            res[i+1] += res[i]/10;
            res[i] = res[i]%10;
        }
        int p = res.size()-1;
        string ans = "";
        while(p && res[p] == 0) p--;
        for(;p >= 0; p--) {
            ans = ans + (char)('0'+res[p]);
        }
        return ans;
    }
};