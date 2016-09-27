class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> ans;
        
        vector<int> v;
    
        recur(ans,candidates,v, target,0);
    
        return ans;
    }
private:
    void recur(vector<vector<int>>& ans, vector<int>& candidates,vector<int>& res, int target, int start){
        if(target<0)
            return;
        if(target==0)
            ans.push_back(res);
            
        for(int i = start; i < (candidates.size()); i++){
            if(i>start && candidates[i]==candidates[i-1])
                continue;
            res.push_back(candidates[i]);
            recur(ans,candidates,res,target-candidates[i],i+1);
            res.pop_back();
        }
    }
};