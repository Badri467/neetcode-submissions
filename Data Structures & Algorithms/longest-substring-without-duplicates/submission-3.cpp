class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ch[256]={0};
        int l=0,r=0;
        int ans=0;

        while(r<s.size()){
            ch[s[r]]++;
            while(ch[s[r]]>1){
                ch[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};
