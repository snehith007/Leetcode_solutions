class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=0,r=0;
        vector<int>array;
        int n = nums1.size();
        int m = nums2.size();

        while(l<n && r<m){
            if(nums1[l] < nums2[r]){
                array.push_back(nums1[l]);
                l++;
            }
            else{
                array.push_back(nums2[r]);
                r++;
            }
        }
        while(l<n){
            array.push_back(nums1[l]);
            l++;
        }
        while(r<m){
            array.push_back(nums2[r]);
            r++;
        }
        int size = array.size();
        if(size % 2 == 0){
            return(array[size/2] + array[size/2 -1]) /2.0;
        }
        else{
            return(array[size /2]);
        }

       
        
    }
};