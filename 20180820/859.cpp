class Solution {
public:
    bool buddyStrings(string A, string B) {
        int pos = -1;
        if (A.size() != B.size())
            return false;
        for (int i = 0; i < A.size(); i++)
            if (A[i] != B[i]) {
                if (pos == -1) {
                    pos = i;
                }
                else if (pos == -2) {
                    return false;
                }
                else {
                    if (A[pos] == B[i] && B[pos] == A[i])
                        pos = -2;
                    else
                        return false;
                }
            }
        if (pos == -2)
            return true;
        if (pos == -1) {
            vector<bool> vis(26);
            for (int i = 0; i < A.size(); i++)
                if (vis[A[i]-'a'])
                    return true;
                else 
                    vis[A[i]-'a'] = true;
        }
        return false;
    }
};