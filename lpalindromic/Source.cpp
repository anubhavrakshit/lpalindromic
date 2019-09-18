#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void SubStrings(string s, string choosen, vector<string>& v_str) {

	if (!s.length()) {
		return;
	}

	choosen += s[0];
	s = s.erase(0, 1);
	v_str.push_back(choosen);

	return SubStrings(s, choosen, v_str);
}

bool isPalindrome(string s) {
	int b = 0;
	int e  = s.length() - 1;
	
	while (e > b) {
		if (s[b++] != s[e--]) {
			return false;
		}
		
	}
	return true;
}
int main()
{
	vector<string> v_str1;
	vector<string> v_str2;
	string str1("forgeeksskeegfor");
	string str2("anubhavforgeeksskeegfor");
	int max_len = INT32_MIN;

	string tmp_str = str1;
	while (tmp_str.length()) {
		SubStrings(tmp_str, string(""), v_str1);
		tmp_str.erase(0, 1);
	}

	tmp_str = str2;
	while (tmp_str.length()) {
		SubStrings(tmp_str, string(""), v_str2);
		tmp_str.erase(0, 1);
	}

	for (string& s1 : v_str1) {
		for (string& s2 : v_str2) {
			int len = s1.length() + s2.length();
			// do not need to check smaller combinations
			if (len > max_len && isPalindrome(s1 + s2)) {
				max_len = std::max(max_len, len);
					cout << "max_len = " << max_len << s1 + s2 << endl;
			}
		}
		
	}
	
	return 0;
}
