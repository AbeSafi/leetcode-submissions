class Solution {
private:
    stack<int> numbers;

public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;

        for (string& token : tokens) {
            if (token != "+" && token != "-" 
                && token != "*" && token != "/") {

                numbers.push(stoi(token));
                continue;
            }

            int second = numbers.top();
            numbers.pop();
            int first = numbers.top();
            numbers.pop();
            
            if (token == "+") {
                numbers.push(first+second);
            }
            else if (token == "-") {
                numbers.push(first-second);
            }
            else if (token == "*") {
                numbers.push(first*second);
            }
            else if (token == "/") {
                numbers.push(first/second);
            }
        }

        return numbers.top();
    }
};
