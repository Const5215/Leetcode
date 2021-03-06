class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        for(int i = 2;i*i <= num; i++)
            if(num%i == 0)
                sum += i + (i == num/i ? 0 : num/i);
        return sum == num && num != 1;
    }
};