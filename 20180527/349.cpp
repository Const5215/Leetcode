class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(), nums1.end()), b(nums2.begin(), nums2.end());
        vector<int> res;
        for (auto it : a)
            if (b.find(it) != b.end())
                res.push_back(it);
        return res;
    }
};