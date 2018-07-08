class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int k = 0;
        bool f = 0;
        while(k < bits.size()) {
            if (bits[k] == 0) {
                k++;
                f = 1;
            }
            else {
                k+=2;
                f = 0;
            }
        }
        return f;
    }
};