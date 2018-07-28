class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> task(profit.size());
        for (int i = 0; i < task.size(); i++)
            task[i] = {difficulty[i], profit[i]};
        sort(task.begin(), task.end());
        sort(worker.begin(), worker.end());
        int p = 0, mx = 0, res = 0;
        for (int i = 0; i < worker.size(); i++) {
            while(p < task.size() && worker[i] >= task[p].first) {
                mx = max(mx, task[p].second);
                p++;
            }
            res += mx;
        }
        return res;
    }
};