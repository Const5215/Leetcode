bool cmp(const string &a ,const string &b) {
    int cnt = a.length()+b.length();
    int i = 0,j = 0;
    for (int k = 1; k <= cnt; k++) {
        if (a[i] != b[j]) return a[i] < b[j];
        i++;j++;
        if (i == a.length()) i = 0;
        if (j == b.length()) j = 0;
    }
    return 0;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> tmp;
        for (int x : nums){
            string now = to_string(x);
            tmp.push_back(now);
        }
        sort(tmp.begin(),tmp.end(),cmp);
        string res = "";
        for (int i = tmp.size()-1; i >= 0; i--) res = res + tmp[i];
        if (res[0] == '0') return "0";
        else return res;
    }
};
