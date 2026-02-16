class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;

        for(char c : word){
            if(c >= 'A' && c <= 'Z')
                upper++;
        }

        if(upper == word.size()) return true;        // USA
        if(upper == 0) return true;                  // leetcode
        if(upper == 1 && word[0] >= 'A' && word[0] <= 'Z') return true; // Google

        return false;
    }
};
