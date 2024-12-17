class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
         for(int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        
    }
};