class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> L(seats.size()), R(seats.size());
        L[0] = (seats[0] == 0 ? 20000: 0);
        R[seats.size()-1] = (seats[seats.size()-1] == 0? 20000: 0);
        for (int i = 1; i < seats.size(); i++)
            L[i] = seats[i] == 1 ? 0: L[i-1]+1;
        for (int i = seats.size()-2; i >= 0; i--)
            R[i] = seats[i] == 1 ? 0: R[i+1]+1;
        int res = 0;
        for (int i = 0; i < seats.size(); i++)
            if (seats[i] == 0)
                res = max(res, min(L[i], R[i]));
        return res;
    }
};