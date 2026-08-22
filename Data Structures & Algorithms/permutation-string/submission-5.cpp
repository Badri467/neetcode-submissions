class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ch1[26]={0};
        int ch2[26]={0};

        if(s1.size() > s2.size())
        return false;

        int l=0,r=0;
        for(char x:s1){
            ch1[x-'a']++;
        }

        while(r<s2.size()){
            ch2[s2[r]-'a']++;
            if(r-l+1>s1.size()){
            ch2[s2[l]-'a']--;
            l++;
            }
            int flag=1;
            for(int i=0;i<26;i++){
                if(ch1[i]!=ch2[i])
                flag=0;
            }
            if(flag)
            return true;
            r++;
        }
        return false;
    }
};
