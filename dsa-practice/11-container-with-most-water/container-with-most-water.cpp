class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxWater = INT_MIN;
        while (left < right) {
            int currLength = min(height[left], height[right]);
            int width = right - left;
            int area = currLength * width;
            maxWater = max(maxWater, area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxWater;
    }
};