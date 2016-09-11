#include <algorithm>
class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size()<3)
        return target;
    
    int size = nums.size();
    int sum_of_three = nums[0]+nums[1]+nums[2];
    int closet = sum_of_three>target?sum_of_three-target:target-sum_of_three;
    
    if(closet==0)
        return sum_of_three;
    
    sort(nums.begin(),nums.end());
    
    for(int i = 0; i < size-1; i++){
        int n1 = nums[i];
        
        int l = i + 1;
        int r = size-1;
        
        while(l<r){
            int n2 = nums[l];
            int n3 = nums[r];
            int sum = n1+n2+n3;
            
            if(sum==target)
                return sum;
            else if(sum>target){
                if((sum-target)<closet){
                    closet = sum-target;
                    sum_of_three = sum;
                }
                r--;
            }
            else{
                if((target-sum)<closet){
                    closet = target-sum;
                    sum_of_three = sum;
                }
                l++;
            }
        }
    }
    return sum_of_three;
}
};