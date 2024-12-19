class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int arr_sum=0;
        int actual_sum =0;
        int cnt =0;
        for(int i=0;i<arr.size();i++){
            arr_sum+=arr[i];
            actual_sum+=i;
            if(arr_sum == actual_sum) cnt++;
        }
        return cnt;
    }
};