class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0; i<num.size(); i++) {
            while(!s.empty() && k > 0 && (s.top() - '0') > (num[i] - '0')) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k > 0) {
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string res = "";
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        while(res.size() > 1 && res[0] == '0'){
            res.erase(res.begin());
        }
        return res;
    }
};