class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>umap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int i=0;
        int j=umap[key].size()-1;
        string ans="";
        while(i<=j){
            int m=(i+j)/2;
            int ind=umap[key][m].first;
            if(ind<=timestamp){
            ans=umap[key][m].second;
            i=m+1;
            }
            else
            j=m-1;
        }
        return ans;
    }
};
