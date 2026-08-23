class Solution {
public:
    vector<int> nse(vector<int>&heights){
        vector<int>right(heights.size(),heights.size());
        stack<int>st;
        
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(!st.empty())
            right[i]=st.top();
            st.push(i);
        }
        return right;
    }
    vector<int> pse(vector<int>&heights){
        vector<int>left(heights.size(),-1);
        stack<int>st;
        
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(!st.empty())
            left[i]=st.top();
            st.push(i);
        }
        return left;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left;
        vector<int>right;
        left=pse(heights);
        right=nse(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,(right[i]-left[i]-1)*heights[i]);
        }
        return maxi;
    }
};
