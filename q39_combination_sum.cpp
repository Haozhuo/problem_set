class Solution {
public:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    
    vector<vector<int>> ans;
    
    vector<int> v;
    
    recur(ans,candidates,v, target,0);
    
    return ans;
}
private:
void recur(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& res, int target, int start){
    
    if(target<0)
        return;
    
    if(target==0){
        ans.push_back(res);
    }
    
    //backtracking
    for(int i = start; i <= candidates.size() - 1; i++){
        res.push_back(candidates[i]);
        recur(ans,candidates,res,target-candidates[i],i);
        res.pop_back();
    }
}
};