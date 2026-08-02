class Solution {
	public:
	int countMinReversals(string s) {
		stack<char> st;
		int operation = 0;
		if ((int)s.size() & 1)return -1;
			
		for (char ch: s) {
			if (ch == '}') {
				if (st.empty()) {
					operation++;
					st.push('{');
				}
				else if (st.top() == '{') {
					st.pop();
				}
			}
			else {
				st.push(ch);
			}
			
		}
		while (!st.empty()) {
			operation++;
			st.pop();
			if (!st.empty()) {
				st.pop();
			}
		}
		return operation;
	}
};
