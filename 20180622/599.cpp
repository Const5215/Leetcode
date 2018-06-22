class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int k = list1.size()+list2.size()-1;
        for (int i = 0;res.size() == 0 && i < k; i++)
            for (int j = 0; j <= i; j++) {
                if (j >= list1.size() || (i-j) >= list2.size())
                    continue;
                if (list1[j] == list2[i-j])
                    res.push_back(list1[j]);
            }
        return res;
    }
};