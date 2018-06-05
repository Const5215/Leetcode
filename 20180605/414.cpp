class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a = INT_MIN,b = INT_MIN,c = INT_MIN;
        a--;b--;c--;
        for (int x : nums) {
            if (a <= x) {
                if (a == x) continue;
                c = b;
                b = a;
                a = x;
            }
            else if (b <= x) {
                if (b == x) continue;
                c = b;
                b = x;
            }
            else if (c <= x) {
                if (c == x) continue;
                c = x;
            }
        }
        if (c >= INT_MIN) return (int)c;
        return (int)a;
    }
};