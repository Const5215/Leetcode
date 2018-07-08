class Node {
private:
    int l, r;
    Node* left, *right;
public:
    bool tracked;
    Node(int ll, int rr, bool t) : left(NULL), right(NULL), l(ll), r(rr), tracked(t) {}
    static void remove(Node* &node) {
        if (!node) return;
        remove(node->left), remove(node->right);
        delete node;
        node = NULL;
    }
    
    bool setTracking(int ll, int rr, bool tracking) {
        if (ll <= l && rr >= r) {
            remove(left), remove(right);
            return tracked = tracking;
        }
        int mid = l + (r - l) / 2;
        if (!left || !right) left = new Node(l, mid, tracked), right = new Node(mid, r, tracked);
        bool ltracked = ll < mid ? left->setTracking(ll, rr, tracking) : left->tracked;
        bool rtracked = rr > mid ? right->setTracking(ll, rr, tracking) : right->tracked;
        return tracked = ltracked && rtracked;
    }
    
    bool getTracking(int ll, int rr) {
        if (!left && !right) return tracked;
        if (ll <= l && rr >= r) return tracked;
        int mid = l + (r - l) / 2;
        bool ltracked = ll < mid ? left->getTracking(ll, rr) : true;
        bool rtracked = rr > mid ? right->getTracking(ll, rr) : true;
        return ltracked && rtracked;
    }
};


class RangeModule {
public:
    
    Node root;
    RangeModule() : root(0, 1000000000, false) {
    }
    
    void addRange(int left, int right) {
        root.setTracking(left, right, true);
    }
    
    bool queryRange(int left, int right) {
        return root.getTracking(left, right);
    }
    
    void removeRange(int left, int right) {
        root.setTracking(left, right, false);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
