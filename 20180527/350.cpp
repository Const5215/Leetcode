class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> a(nums1.begin(), nums1.end()), b(nums2.begin(), nums2.end());
        vector<int> res;
        for (int i : a) {
            auto it = b.find(i);
            if (it != b.end()) {
                b.erase(it);
                res.push_back(i);
            }
        }
        return res;
    }
};