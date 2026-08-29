class Solution {
public:

    vector<int> nextSmallerEl(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> NSE(n);

        for (int i = n - 1; i >= 0; i--) {

            // Next smaller or equal element
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            NSE[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return NSE;
    }


    vector<int> prevSmallerEl(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> PSE(n);

        for (int i = 0; i < n; i++) {

            // Previous strictly smaller element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            PSE[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return PSE;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> PSE = prevSmallerEl(arr);
        vector<int> NSE = nextSmallerEl(arr);

        long long ans = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {

            long long left = i - PSE[i];
            long long right = NSE[i] - i;

            long long contribution =
                (left * right * arr[i]) % mod;

            ans = (ans + contribution) % mod;
        }

        return ans;
    }
};