class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int x : asteroids) {
            bool f = 1;
            while(f && s.size() && s.top() > 0 && x < 0) {
                if (s.top () >= -x)
                    f = 0;
                if (s.top() <= -x)
                    s.pop();
            }
            if (f)
                s.push(x);
        }
        int sz = s.size();
        vector<int> res(sz);
        for (int i = sz-1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};