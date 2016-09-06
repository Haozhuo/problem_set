#include <iostream>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           int n1 = nums1.size(),n2 = nums2.size();
        int *new_array = new int[n1+n2];
        int index = 0;
        int i = 0, j = 0;
        int total = nums1.size() + nums2.size();
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                new_array[index] = nums1[i];
                i++;
            }else{
                new_array[index] = nums2[j];
                j++;
            }
            
            index++;
        }
        
        if(i==nums1.size()){
            for(;j< nums2.size();j++){
                new_array[index] = nums2[j];
                index++;
            }
            
        }
        
        if(j==nums2.size()){
            for(; i < nums1.size();i++){
                new_array[index] = nums1[i];
                index++;
            }
        }
        
    
        if(total % 2 ==1){
            return static_cast<double>(new_array[total/2]);
        }else{
            if(total ==0)
                return static_cast<double>(0);
            return ((new_array[(total-1)/2] + static_cast<double>(new_array[total/2])) / 2);
        }
        
    }
};