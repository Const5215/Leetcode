class Solution {
public:
    int getnxt(int now, vector<int>& nums) {
        return now+nums[now] >= 0 ? (now+nums[now])%nums.size() : (now+nums[now]+nums.size())%nums.size();
    }
    bool circularArrayLoop(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                continue;
            int slow = i,fast = getnxt(i, nums);
            while(nums[fast]*nums[i] > 0 && nums[getnxt(fast, nums)]*nums[i] > 0) {
                if (slow == fast) {
                    if (slow == getnxt(slow, nums))
                        break;
                    return true;
                }
                slow = getnxt(slow, nums);
                fast = getnxt(getnxt(fast, nums), nums);
            }
            slow = i;
            while(nums[slow]*nums[i] > 0) {
                int tmp = getnxt(slow, nums);
                nums[slow] = 0;
                slow = tmp;
            }
        }
        return false;
    }
};