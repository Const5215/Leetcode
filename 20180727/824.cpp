class Solution {
public:
    string toGoatLatin(string S) {
        string res = "", now;
        istringstream iss(S);
        string enda = "";
        while(iss>>now) {
            if (res != "")
                res += " ";
            enda += 'a';
            char head = now[0];
            if (tolower(head) != 'a' && tolower(head) != 'e' && tolower(head) != 'i' && tolower(head) != 'o' && tolower(head) != 'u') {
                now = now.substr(1) + head;
            }
            now += "ma" + enda;
            res += now;
        }
        return res;
    }
};