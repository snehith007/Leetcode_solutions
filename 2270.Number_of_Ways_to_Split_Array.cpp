class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        /*int n = nums.size();
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        int cnt=0;
        long long value =0;

        for(int i=0;i<n-1;i++){
            value+=nums[i];
            cnt+=(2*value>=sum);
        }
        return cnt;*/
   
        long long leftSum = 0, rightSum = 0;  
        for (int num : nums) {
            rightSum += num;
        }
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            
            leftSum += nums[i];
            rightSum -= nums[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }
        return count;

    }
};