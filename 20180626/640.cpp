class Solution {
public:
    string solveEquation(string equation) {
        istringstream iss(equation);
        int a = 0,b = 0,inv = 1;//ax+b
        char nxt = iss.peek();
        while(nxt != -1) {
            int tmp;
            if (nxt == '+'){
                iss.ignore(1);
                nxt = iss.peek();
            }
            if (nxt == 'x')
                tmp = 1;
            else {
                if (nxt == '-') {
                    iss.ignore(1);
                    nxt = iss.peek();
                    if (nxt == 'x')
                        tmp = -1;
                    else {
                        iss>>tmp;
                        tmp = -tmp;
                        nxt = iss.peek();
                    }
                }
                else {
                    iss>>tmp;
                    nxt = iss.peek();
                }
            }
            if (nxt == 'x') {
                a += tmp*inv;
                iss.ignore(1);
            }
            else {
                if (nxt == '+')
                    iss.ignore(1);
                b -= tmp*inv;
            }
            nxt = iss.peek();
            if (nxt == '=') {
                inv = -1;
                iss.ignore(1);
                nxt = iss.peek();
            }
        }
        if (a == 0)
            return b == 0? "Infinite solutions": "No solution";
        return "x="+to_string(b/a);
    }
};