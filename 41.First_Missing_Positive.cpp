class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        // Place each number in its correct position if possible
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the smallest positive integer missing in the array
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all integers are present, the missing integer is n+1
        return n + 1;
    }
};