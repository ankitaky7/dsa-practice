class Solution {
public:
    #define ed endl;
    int findNumbers(vector<int>& nums) {
        int lastDgt;
        int ans = 0;
        int cnt = 0;
        for (int i= 0; i < nums.size(); i++) {
            int currNum = nums[i];
            cnt = 0;
            while(currNum){
                lastDgt = currNum % 10;
                cnt++;
                currNum = currNum / 10;
            }
            cout << cnt << ed;
        if((cnt % 2) == 0) ans++;
        }
        return ans;
    }
};