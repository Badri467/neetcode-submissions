class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(),0);
        int i=temperatures.size()-1;
        stack<int>st;
        while(i>=0){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty())
            ans[i]=0;
            else
            ans[i]=st.top()-i;
            st.push(i);
            i--;
        }
        return ans;
    }
};
