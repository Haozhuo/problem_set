#include <iostream>
using namespace std;
class Solution {
public:
    //first approach
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        
        return i+1;
    }

    //second approach
    int removeDuplicates2(vector<int>& nums) {
       if(nums.size()==0)
        return 0;
    
    vector<int>::iterator p = nums.begin();
    vector<int>::iterator q = nums.begin();
    q++;
    
    for(;q!=nums.end();){
        if(*p==*q){
            q=nums.erase(q);
        }else{
            p++;
            q++;
        }
    }
    
    return nums.size();
    }
};