class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int sum =0;
        int right_ones=0;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                sum+=i;
                right_ones++;
            }
        }
        //moves per position
        vector<int>ans(n);
        int left_sum=0;
        int left_ones=0;
        for(int i=0;i<n;i++){
            int moves = sum+left_sum;
            ans[i]=moves;

            //update the values
            if(boxes[i]=='1'){
                left_ones++;
                right_ones--;
            }
            left_sum+=left_ones;
            sum-=right_ones;
        }
        return ans;
    }
};