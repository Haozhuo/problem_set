class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        int counter = 0;
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
                counter++;
            }else{
                i++;
            }
        }
        
        return (nums.size()-counter);
    }
private:
    void swap(int& n1,int& n2){
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
};