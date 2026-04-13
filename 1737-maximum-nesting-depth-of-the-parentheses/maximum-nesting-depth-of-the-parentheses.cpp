class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 0;
        int maxi = INT_MIN;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
                cnt++;
            }
            else if(s[i] == ')'){
                st.pop();
                cnt--;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};