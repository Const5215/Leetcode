class Solution {
public:
    bool canTransform(string start, string end) {
        int n=start.size();
        assert(n == end.size());
        int lcnt = 0, rcnt = 0;
        for(int i=0;i<n;i++){
            if(start[i] == 'L') ++lcnt;
            else if(start[i] == 'R') ++rcnt;
            if(end[i] == 'L') --lcnt;
            else if(end[i] == 'R') --rcnt;
        }
        if(lcnt || rcnt) return false;
        
        int i=0,j=0;
        while(j < n && i < n){
            while(j < n && end[j] == 'X') ++j;
            while(i < n && start[i] == 'X') ++i;
            if(i==n&&j==n) break;
            if(i==n || j==n || start[i] != end[j]) return false;
            if(start[i] == 'R' && i > j) return false;
            else if(start[i] == 'L' && i < j) return false;
            ++i; ++j;
        }
        
        return true;
    }
};