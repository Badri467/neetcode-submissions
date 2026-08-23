class Solution {
public:
    int solve(vector<int>&piles,int h,int rate){
       
        for(int i=0;i<piles.size();i++){
            
            h-=ceil((double)piles[i]/(double)rate);;
            if(h<0)
            return 0;
        }
        return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(solve(piles,h,m)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};
