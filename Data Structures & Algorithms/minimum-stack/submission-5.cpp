class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(0);
            mini = val;
        } else {
            st.push((long long)val - mini);

            if (val < mini)
                mini = val;
        }
    }

    void pop() {
        long long t = st.top();
        st.pop();

        if (t < 0)
            mini = mini - t;
    }

    int top() {
        long long t = st.top();

        if (t < 0)
            return mini;

        return t + mini;
    }

    int getMin() {
        return mini;
    }
};