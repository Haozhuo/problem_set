#include <algorithm>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans(0);
        
        if(nums.size()<4)
            return ans;
        
        sort(nums.begin(),nums.end());
        
        int first = 0;
        int second = 1;
        int size = nums.size();
        
        for(;first < size-2; first++){
            //prevent duplicate
            if(first>0&&nums[first]==nums[first-1])
                continue;
            
            for(second = first + 1;second<size;second++){
                //prevent duplicate
                if(second>first+1&&nums[second]==nums[second-1])
                    continue;
                
                int n1 = nums[first], n2 = nums[second];
                int sum = target - (n1+n2);
                
                int l = second + 1;
                int r = size - 1;
                
                while(l<r){
                    int n3 = nums[l],n4=nums[r];
                    if(n3+n4==sum){
                        ans.push_back(vector<int> ({n1,n2,n3,n4}));
                        //prevent duplicate
                        while(l<size&&nums[l]==n3){
                            l++;
                        }
                        //prevent duplicate
                        while(r>=0&&nums[r]==n4){
                            r--;
                        }
                    }
                    else if(n3+n4>sum){
                        r--;   
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        
        return ans;
    }
};