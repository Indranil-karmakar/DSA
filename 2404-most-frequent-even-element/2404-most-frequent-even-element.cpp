class Solution {
public:
    int mostFrequentEven(vector<int>& arr) {
        unordered_map<int, int> mp; 
        int maxcount = 0;
        int ans = -1;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] % 2 == 0) {
                mp[arr[i]]++;
            }
            
        }
        for(auto it : mp) {
            int num = it.first;
            int freq = it.second;
            if(freq > maxcount) {
                maxcount = freq;
                ans = num;
            }
            else if(freq == maxcount && num < ans) {
                ans = num;
            }
        }
        return ans;

    }
};