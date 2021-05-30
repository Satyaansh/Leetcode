class Solution {
public:
    //using Pigeonhole sorting
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;
        int maxVal = nums[0];
        int minVal = nums[0];
        for(int i = 1; i < n; i++){
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        vector<int> maxBucket(n - 1, INT_MIN);
        vector<int> minBucket(n - 1, INT_MAX);
        float delta = (float)(maxVal - minVal)/(float)(n-1);
        for(int i = 0; i < n; i++){
            if(nums[i] == maxVal || nums[i] == minVal)
                continue;
            int index = (float)(floor(nums[i] - minVal))/delta;
            maxBucket[index] = max(maxBucket[index], nums[i]);
            minBucket[index] = min(minBucket[index], nums[i]);
        }
        int preVal = minVal;
        int maxGap = 0;
        for(int i = 0; i < n -  1; i++){
            if(minBucket[i] == INT_MAX)
                continue;
            maxGap = max(maxGap, minBucket[i] - preVal);
            preVal = maxBucket[i];
        }
        maxGap = max(maxGap, maxVal - preVal);
        return maxGap;
    }
};
