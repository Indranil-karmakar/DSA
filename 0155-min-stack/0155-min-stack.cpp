class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = INT_MAX;
    }

    void push(int value) {
        long long val = value;

        // First element
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else {
            if (val >= mini) {
                st.push(val);
            }
            else {
                // Store encoded value
                st.push(2 * val - mini);

                // Update minimum
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        // Encoded value means minimum needs restoration
        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {
        long long x = st.top();

        // If encoded, actual top is current minimum
        if (x < mini) {
            return mini;
        }

        return x;
    }

    int getMin() {
        return mini;
    }
};