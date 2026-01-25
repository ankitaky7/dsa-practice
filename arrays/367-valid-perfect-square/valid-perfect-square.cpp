class Solution {
public:
    bool isPerfectSquare(int num) {
        long long sq, mid;
        int low = 0; 
        int high = num;
        while(low <= high){
            mid = (low + high) / 2;
            sq = mid * mid;
            if(num == sq) return true;
            else if(sq < num) low = mid + 1;
            else high = mid - 1; 
        }
        return false;
    }
};