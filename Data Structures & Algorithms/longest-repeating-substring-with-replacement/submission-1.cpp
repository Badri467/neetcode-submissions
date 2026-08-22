class Solution {
public:
    int characterReplacement(string s, int k) {
        int ch[256]={0};
        int l=0,r=0;
        int ans=0;
        int freq=0;

        while(r<s.size()){
            ch[s[r]]++;
            freq=max(freq,ch[s[r]]);
            while((r-l+1-freq)>k){
                ch[s[l]]--;
                l++;
            }
            
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};
