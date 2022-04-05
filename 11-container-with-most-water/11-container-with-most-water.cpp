class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int max_area=0;
        while(i<j){
            if(height[i]<height[j]){
                max_area=max(max_area,(j-i)*height[i]);
                i++;
            }
            else{
                max_area=max(max_area,(j-i)*height[j]);
                j--;
            }
        }
        return max_area;
        
        
    }
};