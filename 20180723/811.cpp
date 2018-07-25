class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m;
        for (string domain : cpdomains) {
            int cnt;string now;
            istringstream iss(domain);
            iss>>cnt;
            iss>>now;
            while(now != "") {
                m[now] += cnt;
                int pos = now.find('.');
                if (pos != -1)
                    now = now.substr(pos+1);
                else
                    now = "";
            }
        }
        vector<string> res;
        for (auto it : m)
            res.push_back(to_string(it.second)+" "+it.first);
        return res;
    }
};