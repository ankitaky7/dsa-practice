class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        map<char, char> mpp1; // s -> t
        map<char, char> mpp2; // t -> s

        for (int i = 0; i < s.size(); i++) {

            // agar dono characters pehli baar aa rahe hain
            if (mpp1.find(s[i]) == mpp1.end() &&
                mpp2.find(t[i]) == mpp2.end()) {

                mpp1[s[i]] = t[i];
                mpp2[t[i]] = s[i];
            }
            else {
                // agar mapping mismatch hui
                if (mpp1[s[i]] != t[i] || mpp2[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
