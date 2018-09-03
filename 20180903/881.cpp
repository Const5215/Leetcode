class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int L = 0, R = people.size()-1, res = 0;
        while(R >= L) {
            if (people[L]+people[R] <= limit) {
                L++;R--;res++;
            }
            else {
                R--;res++;
            }
        }
        return res;
    }
};