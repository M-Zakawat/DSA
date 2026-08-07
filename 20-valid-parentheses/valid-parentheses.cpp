class Solution {
public:
    bool isValid(string s) {
        vector<char> st;  // use vector as stack

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            } else {
                if (st.empty()) return false;
                char top = st.back();
                st.pop_back();

                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }

        return st.empty();
    }
};
