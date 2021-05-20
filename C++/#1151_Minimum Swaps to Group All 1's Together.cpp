class Solution {
public:
    int minSwaps(vector<int>& data) {
        int count=0;
        for(auto m : data) if(m) count++;
        if(count==data.size()) return 0;
        int maxCount=0, windowCount=0;
        for(int i=0; i<count; i++) if(data[i]) windowCount++;
        maxCount = windowCount;
        int low = 0, high = count;
        while(high<data.size()){
            if(data[low]) windowCount--;
            if(data[high]) windowCount++;
            maxCount = max(maxCount, windowCount);
            low++, high++;
        }
        return count-maxCount;
    }
};