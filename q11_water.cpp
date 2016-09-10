int maxArea(vector<int>& height) {
    int b = 0;
    int e = height.size()-1;
    int max_area = 0;
    
    while(b<e){
        max_area = max(max_area,(min(height[b],height[e]))*(e-b));
        if(height[b]<height[e]){
            b++;
        }else if(height[b]==height[e]){
            b++;
        }else{
            e--;
        }
    }
    
    return max_area;
}

//two position approach