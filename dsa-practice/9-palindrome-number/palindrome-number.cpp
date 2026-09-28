class Solution {
public:
    bool isPalindrome(int x) {
        int originalVal = x;
        long long reverse = 0;
        while (x > 0) {
            int lastDigit = x % 10;
            // reverse
            reverse = (reverse * 10) + lastDigit;
            x = x / 10;
        }
        if (reverse == originalVal)
            return true;
        return false;
    }
};