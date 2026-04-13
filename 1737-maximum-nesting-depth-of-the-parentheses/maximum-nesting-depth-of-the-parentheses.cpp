class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int depth = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                depth++;
            }else if(s[i] == ')')
            depth--;
        maxi = max(maxi ,depth);
        }
        return maxi;
    }
};