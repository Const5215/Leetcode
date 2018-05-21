class NumArray {
public:
    NumArray(vector<int> nums) {
        pre.push_back(0);
        for (int i = 0; i < nums.size(); i++)
            pre.push_back(pre[i]+nums[i]);
    }
    
    int sumRange(int i, int j) {
        return (int)(pre[j+1]-pre[i]);
    }
private:
    vector<long long> pre;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */