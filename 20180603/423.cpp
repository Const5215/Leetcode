class Solution {
public:
    string originalDigits(string s) {
        vector<int> letter(26);
        for (char x : s) letter[x-'a']++;
        vector<int> nums(10);
        nums[0] = letter['z'-'a'];
        nums[2] = letter['w'-'a'];
        nums[4] = letter['u'-'a'];
        nums[6] = letter['x'-'a'];
        nums[8] = letter['g'-'a'];
        nums[1] = letter['o'-'a']-nums[2]-nums[4]-nums[0];
        nums[3] = letter['h'-'a']-nums[8];
        nums[5] = letter['f'-'a']-nums[4];
        nums[7] = letter['s'-'a']-nums[6];
        nums[9] = letter['i'-'a']-nums[5]-nums[6]-nums[8];
        string res = "";
        for (int i = 0; i < 10; i ++)
            for (int j = 0; j < nums[i]; j++)
                res = res + (char)('0'+i);
        return res;
    }
};