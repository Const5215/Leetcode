class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string C = A;
        while(C.size() < B.size()*2) C += A;
        int p = C.find(B);
        if (p == -1)
            return -1;
        else {
            return ((p+B.size()-1)/A.size()+1)-(p/A.size());
        }
    }
};