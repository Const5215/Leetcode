class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> digs;
        for (; N; N/=10)
            digs.push_back(N%10);
        sort(digs.begin(), digs.end());
        do 
        {
            if (digs[0] == 0) continue;
            int now = 0;
            for (int x : digs) {
                now*=10;
                now+=x;
            }
            if ((now&(-now)) == now)
                return true;
        }while(next_permutation(digs.begin(), digs.end()));
        return false;
    }
};