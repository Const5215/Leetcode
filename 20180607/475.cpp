class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int p = 0, r = 0;
        for (int now : houses){
            while (p != heaters.size()-1 && abs(now-heaters[p]) >= abs(now-heaters[p+1])) p++;
            r = max(r, abs(now-heaters[p]));
        }
        return r;
    }
};