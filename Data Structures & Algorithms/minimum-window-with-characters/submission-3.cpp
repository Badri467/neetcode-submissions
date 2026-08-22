class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,st=0;
        int ans=INT_MAX;
        string str="";
        unordered_map<int,int>umap;
        for(char ch: t)
        umap[ch-'a']++;
        int cnt=0;
        while(r<s.size()){
            if(umap[s[r]-'a']>0)
            cnt++;
            umap[s[r]-'a']--;
            while(cnt==t.size()){
                if(r-l+1<ans){
                ans=r-l+1;
                st=l;
                }
                umap[s[l]-'a']++;
                if(umap[s[l]-'a']>0)
                cnt--;
                
                l++;
            }
            r++;
        }
        
        return ans==INT_MAX?"":s.substr(st,ans);
    }
};
