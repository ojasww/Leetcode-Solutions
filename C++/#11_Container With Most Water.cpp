class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size()-1;
        int result = 0;
        while(lo<hi){
            int h = min(height[lo], height[hi]);
            result = max(result, h*(hi-lo));
            while(lo<hi && height[lo] <= h) lo++;
            while(lo<hi && height[hi] <= h) hi--;
        }
        return result;
    }
};