//iterative approach
#include <map>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 0;

        int low = 0, high = nums.size();

        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
        
    }
};



//recursive approach
#include <map>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 1;
        //fisrt int for difference, second int for index
        map<int,int> m;
        
        search(nums,0,nums.size()-1,target,m);
        
        if(m.begin() -> first ==0){
            return m.begin()->second;
        }
        else{
            cout << (m.begin())->second << endl;
            cout << (m.begin())->first << endl;
            int number = nums[(m.begin())->second];
            if(number < target)
                return ((m.begin())->second) + 1;
            else
                return (m.begin()->second);
        }
        
        
    }
private:
    void search(vector<int>& nums, int b, int e, int target, map<int,int>& m){
        if(e<b)
            return;
        
        int mid = (b+e)/2;
        if(nums[mid]==target){
            m.insert(make_pair(0,mid));
            return;
        }
        else if(nums[mid]>target){
            m.insert(make_pair(nums[mid]-target,mid));
            search(nums,b,mid-1,target,m);
        }
        else{
            m.insert(make_pair(target-nums[mid],mid));
            search(nums,mid+1,e,target,m);
        }
    }
};