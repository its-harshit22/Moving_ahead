class Solution {
public:

    void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}

void rs(stack<int>& st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    rs(st);
    insertAtBottom(st, top);
}

    void reverseStack(stack<int> &st) {
        rs(st);
    }
};
