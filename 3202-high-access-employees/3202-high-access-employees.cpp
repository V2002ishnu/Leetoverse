class Solution {
public:
    // typedef pair<int,string> pp;
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        // vector<pp> v;
        unordered_map<string,vector<int>> mp;
        // int n = a.size();/
        
        for(auto &it : a){
            string x = it[0];
            string y = it[1];
            int num = stoi(y);
            mp[x].push_back(num);
        }
        for(auto &it : mp){
            sort(it.second.begin(),it.second.end());
        }
        vector<string> ans;
        for(auto &it : mp){
            vector<int> &v = it.second;
            for(int i=2;i<v.size();i++){
                if(v[i] - v[i-2] < 100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};