inline int lb(int x) {
    return (x&(-x));
}
class NumArray {
public:
    NumArray(vector<int> nums) {
        this->t.assign(nums.size()+1,0);
        for (int i = 1; i <= nums.size(); i++) {
            for (int now = i; now <= nums.size(); now += lb(now))
                this->t[now] += nums[i-1];
        }
        
    }
    int sum(int x) {
        int res = 0;
        for (;x;x-=lb(x))
            res += this->t[x];
        return res;
    }
    void update(int i, int val) {
        i++;
        int delta = val-sum(i)+sum(i-1);
        for (int j = i; j < this->t.size(); j+=lb(j))
            this->t[j] += delta;
    }
    
    int sumRange(int i, int j) {
        i++;j++;
        return sum(j)-sum(i-1);
    }
    
private:
    vector<long long> t;
};