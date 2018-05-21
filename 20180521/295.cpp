class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (this->s.size() != this->l.size()) {
            if (*this->s.rbegin() <= num)
                this->l.insert(num);
            else {
                this->l.insert(*this->s.rbegin());
                this->s.erase(this->s.find(*this->s.rbegin()));
                this->s.insert(num);
            }
        }else {
            if (this->l.size() == 0 || *this->l.begin() >= num)
                this->s.insert(num);
            else {
                this->s.insert(*this->l.begin());
                this->l.erase(this->l.begin());
                this->l.insert(num);
            }
        }
    }
    
    double findMedian() {
        if (this->s.size() != this->l.size())
            return (double)*this->s.rbegin();
        else 
            return (double)(*this->s.rbegin()+*this->l.begin())/2;
    }
private:
    multiset<int> s,l;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */