#include <algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0)
            return;
        //find the first index i that is not
        //in descending order and find
        //the smallest one in descending order that is 
        //bigger than the nums[i]
        for(int i = nums.size() - 1; i >= 1; i--){
            if(nums[i]>nums[i-1]){
                for(int j = nums.size()-1; j >= i; j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        smallest_per(i,nums.size()-1,nums);
                        return;
                    }
                }
            }
        }
        
        return smallest_per(0,nums.size()-1,nums);
        
    }
private:
    void swap(int& n1, int& n2){
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    
    void smallest_per(int b, int e,vector<int>& nums){
        while(b<=e){
            swap(nums[b],nums[e]);
            b++;
            e--;
        }
    }
};