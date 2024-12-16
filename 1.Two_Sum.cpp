class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;

        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int ans = target - num;
            if(map.find(ans) != map.end()){
                return{map[ans],i};
            }
            map[num] =i;

        }
        return{-1,-1};

        
        
    }
};