class ExamRoom {
public:
    set<int> s;
    int mx = 0;
    ExamRoom(int N) {
        mx = N;
    }
    
    int seat() {
        if (s.size() == 0) {
            s.insert(0);
            return 0;
        }
        else {
            pair<int,int> pos = {*s.begin(),0};
            for (auto it = s.begin();it != s.end(); it++) {
                auto nxt = it;nxt++;
                if (nxt != s.end()) {
                    int v = ((*nxt)-(*it))/2;
                    if (v > pos.first)
                        pos = {v, ((*nxt)+(*it))/2};
                }
            }
            int v = (mx-1-(*s.rbegin()));
            if (v > pos.first)
                pos = {v, mx-1};
            s.insert(pos.second);
            return pos.second;
        }
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */