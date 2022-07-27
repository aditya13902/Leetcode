/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int siz=mountainArr.length();
        int l=0;
        int r=siz-1;
        int idx=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m==0 || mountainArr.get(m)>mountainArr.get(m-1)){
                idx=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        if(mountainArr.get(idx)==target) return idx;
        l=0;
        r=idx-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(mountainArr.get(m)==target) return m;
            else if(mountainArr.get(m)<target) l=m+1;
            else r=m-1;
        }
        l=idx+1;
        r=siz-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(mountainArr.get(m)==target) return m;
            else if(mountainArr.get(m)>target) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};