class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0, j = 0;
        int ans = 0;
        int n = s.size();
        unordered_map<char,int> mp;

        for(int j=0;j<n;j++){
            mp[s[j]]++;

            while(mp[s[j]] > 2){
                mp[s[i]]--;
                if(mp[s[i]] == 0)mp.erase(s[i]);
                i++;
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};