class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                if (temp != "") {
                    if (res == "")
                        res = temp;
                    else
                        res = temp + " " + res;
                    temp = "";
                }
            }
        }

        // last word handle
        if (temp != "") {
            if (res == "")
                res = temp;
            else
                res = temp + " " + res;
        }
        return res;
    }
};