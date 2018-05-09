class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int lowest_id  = -1, sum = 0, lowest = INT_MAX;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i]-cost[i];
            if (sum < lowest) {
                lowest_id = (i+1)%gas.size();
                lowest = sum;
            }
        }
        int ths = 0;
        for (int i = 0; i < gas.size(); i++) {
            int now = (i+lowest_id)%gas.size();
            ths += gas[now]-cost[now];
            if (ths < 0) return -1;
        }
        return lowest_id;
    }
};