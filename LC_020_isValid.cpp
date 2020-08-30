class Solution {
public:
	bool isValid(string s) {
		stack<char> sta;
		if (s != "") {
			sta.push(s[0]);
			for (auto it = s.begin() + 1; it != s.end(); ++it) {
				if ((sta.size() != 0) && ((sta.top() == '(' &&*it == ')') || (sta.top() == '{'&&*it == '}') || (sta.top() == '['&&*it == ']')))
					sta.pop();
				else
					sta.push(*it);
			}

			if (sta.size() == 0)
				return 1;
			else
				return 0;
		}

		else {
			if (s == "")
				return true;
			else return false;
		}
	}
};
