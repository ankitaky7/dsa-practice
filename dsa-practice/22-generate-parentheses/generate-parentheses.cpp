class Solution {
public:
    vector<string> ans;
    string str;
    void backtrack(int openN, int closeN, int n) {
        // valid case / base case
        if (openN == closeN && openN == n) {
            ans.push_back(str);
            return;
        }

        if (openN < n) {
            str.push_back('(');
            backtrack(openN + 1, closeN, n);
            str.pop_back();
        }

        if (closeN < openN) {
            str.push_back(')');
            backtrack(openN, closeN + 1, n);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return ans;
    }
};