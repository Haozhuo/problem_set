class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        
        if(nums.size()==0)
            return v;
        
       search(nums,v,0,nums.size()-1,target);
            
        if(v.size()==0){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }else if(v.size()==1){
            v.push_back(*(v.begin()));
            return v;
        }
        else{
            vector<int> ans;
            ans.push_back(v[0]);
            ans.push_back(v[v.size()-1]);
            return ans;
        }
    }
private:
    void search(vector<int>& nums, vector<int>& res, int b, int e, int target){
        if(e < b)
            return;
        
        int mid = (b + e) / 2;
        
        if(nums[mid]==target){
            search(nums,res,b,mid-1,target);
            res.push_back(mid);
            search(nums,res,mid+1,e,target);
        }
        else if(nums[mid] > target)
            search(nums,res,b,mid-1,target);
        else
            search(nums,res,mid+1,e,target);
            
    }


//iterative approach
    vector<int> searchRange2(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        int mid = -1;

        while(start < end){
            mid = (start + end) / 2;
            if(nums[mid]>=target)
                end = mid;
            else
                start = mid + 1;
        }

        int l = start;

        end = nums.size();
        while(start < end){
            mid = (start + end) / 2;
            if(nums[mid]>target)
                end = mid;
            else
                start = mid + 1;
        }

        int r = start;
        
        return l==r?vector<int> {-1,1} ? vector<int> {l,r-1};
    }

};


