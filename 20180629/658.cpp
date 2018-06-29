class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int p = 0;
        while(p+k < arr.size() && abs(arr[p]-x) >= abs(arr[p+k]-x))
            p++;
        while(p && abs(arr[p-1]-x) == abs(arr[p+k-1]-x))
            p--;
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(arr[p+i]);
        return res;
    }
};