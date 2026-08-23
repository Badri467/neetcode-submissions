class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;

        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target) r=m-1;
            else l=m+1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int flag=-1;
        for(int i=0;i<matrix.size();i++){
            flag=search(matrix[i],target);
            if(flag!=-1)
            return true;
        }
        return false;
    }
};
