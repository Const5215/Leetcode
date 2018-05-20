class Solution {
public:
    string numberToWords(int num) {
        vector<pair<int,string>> m;
        string res = "";
        m.push_back(make_pair(90,"Ninety"));
        m.push_back(make_pair(80,"Eighty"));
        m.push_back(make_pair(70,"Seventy"));
        m.push_back(make_pair(60,"Sixty"));
        m.push_back(make_pair(50,"Fifty"));
        m.push_back(make_pair(40,"Forty"));
        m.push_back(make_pair(30,"Thirty"));
        m.push_back(make_pair(20,"Twenty"));
        m.push_back(make_pair(19,"Nineteen"));
        m.push_back(make_pair(18,"Eighteen"));
        m.push_back(make_pair(17,"Seventeen"));
        m.push_back(make_pair(16,"Sixteen"));
        m.push_back(make_pair(15,"Fifteen"));
        m.push_back(make_pair(14,"Fourteen"));
        m.push_back(make_pair(13,"Thirteen"));
        m.push_back(make_pair(12,"Twelve"));
        m.push_back(make_pair(11,"Eleven"));
        m.push_back(make_pair(10,"Ten"));
        m.push_back(make_pair(9,"Nine"));
        m.push_back(make_pair(8,"Eight"));
        m.push_back(make_pair(7,"Seven"));
        m.push_back(make_pair(6,"Six"));
        m.push_back(make_pair(5,"Five"));
        m.push_back(make_pair(4,"Four"));
        m.push_back(make_pair(3,"Three"));
        m.push_back(make_pair(2,"Two"));
        m.push_back(make_pair(1,"One"));

        string pow3[] = {""," Thousand"," Million"," Billion"};
        int cnt = -1;
        for(;num;num /= 1000) {
            cnt++;
            string ths = "";
            int now = num % 1000;
            if (now >= 100) ths += m[27-now/100].second + " Hundred";
            now %= 100;
            while(now) {
                for (auto it : m) {
                    if (now >= it.first) {
                        ths += (ths.size()?" ":"") + it.second;
                        now -= it.first;
                        break;
                    }
                }
            }
            if (ths != "")
                res = ths + pow3[cnt] + (res.size()?" ":"") + res;
        }
        if (res == "") res = "Zero";
        return res;
    }
};