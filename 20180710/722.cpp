class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool c = 0, l = 0, f = 0;
        vector<string> res;
        string ths = "";
        for (int i = 0; i < source.size(); i++) {
            for (int j = 0; j < source[i].size(); j++) {
                if (c) {
                    if (!l && !f && j && source[i][j-1] == '*' && source[i][j] == '/') {
                        c = 0;
                    }
                    else
                        f = 0;
                }
                else {
                    if (j < source[i].size()-1 && source[i][j] == '/' && source[i][j+1] == '/') {
                        l = 1;
                        c = 1;
                        j++;
                    }
                    else if (j < source[i].size()-1 && source[i][j] == '/' && source[i][j+1] == '*') {
                        c = 1;
                        j++;
                        f = 1;
                    }
                    else 
                        ths += source[i][j];
                }
            }
            if (l) {
                c = 0; l = 0;
            }
            if (!c && ths != "") {
                res.push_back(ths);
                ths = "";
            }
        }
        return res;
    }
};