class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        int n = s.size();
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && m[s[i]] < m[s[i + 1]]) {
                ans = ans - m[s[i]];
            } else {
                ans = ans + m[s[i]];
            }
        }
        return ans;
    }
};