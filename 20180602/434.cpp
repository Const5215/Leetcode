class Solution {
public:
    int countSegments(string s) {
        istringstream iss(s);
        int cnt = 0;
        string x;
        while(iss>>x) cnt++;
        return cnt;
    }
};