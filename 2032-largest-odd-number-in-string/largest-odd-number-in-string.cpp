class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int idx = -1;
        string ans;
        for(int i=n-1;i>=0;i--){
            if((((num[i] - '0') % 2) == 0)) {
                continue;
            }else {
                idx = i;
                break;
            }
        }
        if(idx != -1){
        for(int i=0;i<=idx;i++){
            ans.push_back(num[i]);
        }
        }
        if(ans.size() == 0) return "";
        return ans;
    }
};