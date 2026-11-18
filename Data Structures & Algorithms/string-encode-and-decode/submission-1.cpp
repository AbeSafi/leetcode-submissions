class Solution {
public:
	string encode(vector<string>& strs) {
		string encoded_string = "";
		
		for (string str : strs) {
			int i = 0;
			string buffer = "";

			while (i < str.length()) {
				buffer += str[i];
				
				if (buffer.length() >= 8 && i < str.length() - 1) {
					encoded_string += 'r' + to_string((int)buffer.length());
					encoded_string += buffer;
					buffer = "";
				}
				
				++i;
			}
			
			if (buffer.length() > 0) {
				encoded_string += 'r' + to_string((int)buffer.length());
				encoded_string += buffer;
				buffer = "";
			}
			
			encoded_string += 'w';
		}
		
		return encoded_string;
	}
	
	vector<string> decode(string s) {
		vector<string> decoded_result;
		string buffer = "";
		int i = 0;
		
		while (i < s.length()) {
			if (s[i] == 'w') {
				decoded_result.push_back(buffer);
				buffer = "";
				++i;
			}
			else if (s[i] == 'r') {
                ++i;
				int amount = (s[i] - '0');
                ++i;
				for (int k = 0; k < amount; ++k) {
                    buffer += s[i++];
                }
			}
		} 
		
		return decoded_result;
	}
};