#include <unordered_set>
#include <set>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result(0);
        int size = nums.size();
        if(size<3)
            return result;
        //important
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < size - 1; i++){
            //prevent duplicate
            if(i>=0&&nums[i]==nums[i-1])
                continue;
            int n1 = nums[i];
            int l = i + 1;
            int r = size - 1;
            
            while(l<r){
                int n2 = nums[l];
                int n3 = nums[r];
                
                if(n1+n2+n3==0){
                    vector<int> temp;
                    temp.push_back(n1);temp.push_back(n2);temp.push_back(n3);
                    result.push_back(temp);
                    //prevent duplicate(already sorted)
                    while(l<size&&nums[l]==n2)
                        l++;
                    //prevent duplicate(already sorted)
                    while(r>=0&&nums[l]==n3)
                        r--;
                }else if(n1+n2+n3>0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        
        return result;
    
    }
};