class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size()-1;

        int l=0,r=0,ans=0;

        while(r<n){
            int far = r;
            for(int i=l;i<=r;i++){
                far = max(far,i+nums[i]);
            }
            l = r+1;
            r= far;
            ans++;
        }
        return ans;
    }
};