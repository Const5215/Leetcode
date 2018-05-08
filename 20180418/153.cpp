class Solution {
public:
    int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
        
        while (num[start]>num[end]) {
            int mid = (start+end)/2;
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return num[start];
    }
};