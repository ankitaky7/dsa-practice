class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int lb = 0, rb = n - 1;
        int w;
        int ht;
        int currWater;
        int maxWater = INT_MIN;
        while(lb < rb){
            w = rb - lb;
            ht = min(height[lb], height[rb]);
            currWater = w * ht;
            maxWater = max(maxWater, currWater);
            height[lb] < height[rb] ? lb++ : rb--;
        }
        return maxWater;
    }
};