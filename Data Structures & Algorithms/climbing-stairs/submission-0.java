class Solution {
        public int solve(int n,int[] al){
            if(n==0) return 1;
            if(n<0) return 0;
            if(al[n]!=-1) return al[n];
            return al[n]=solve(n-1,al)+solve(n-2,al);

        }
    public int climbStairs(int n) {
        int[] arr=new int[n+1];
         Arrays.fill(arr,-1);
        return solve(n,arr);
    }
}
