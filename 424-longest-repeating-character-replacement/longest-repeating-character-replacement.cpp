class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxlength = 0, maxFreq = 0;
        int hash[26] = {0};

        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            if ((r - l + 1) - maxFreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxlength = max(maxlength, r - l + 1);
            r++;
        }
        return maxlength;
    }
};
