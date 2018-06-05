class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<int> a,b,c;
        for (char x : num1)
            a.push(x-'0');
        for (char x : num2)
            b.push(x-'0');
        int n = 0;
        while(a.size() && b.size()) {
            c.push((a.top()+b.top()+n)%10);
            n = (a.top()+b.top()+n)/10;
            a.pop();b.pop();
        }
        while(a.size()) {
            c.push((a.top()+n)%10);
            n = (a.top()+n)/10;
            a.pop();
        }
        while(b.size()) {
            c.push((b.top()+n)%10);
            n = (b.top()+n)/10;
            b.pop();
        }
        if (n)
            c.push(1);
        string res = "";
        for(;c.size();c.pop())
            res =  res + (char)(c.top()+'0');
        return res;
    }
};