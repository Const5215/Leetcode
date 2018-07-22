class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string table[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for (auto word : words) {
            string trans = "";
            for (char c : word)
                trans += table[c-'a'];
            s.insert(trans);
        }
        return s.size();
    }
};