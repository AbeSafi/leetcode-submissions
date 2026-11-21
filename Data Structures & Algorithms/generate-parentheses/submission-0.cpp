class Solution {
private:
vector<string> allParantheses;
string parantheses;

void findAllParantheses(int n, int lAmount, int rAmount) {
    if (rAmount > lAmount || lAmount > n) return;
    if (lAmount == rAmount && lAmount == n) allParantheses.push_back(parantheses);

    parantheses += '(';
    findAllParantheses(n, lAmount+1, rAmount);
    parantheses.pop_back();

    parantheses += ')';
    findAllParantheses(n, lAmount, rAmount+1);
    parantheses.pop_back();
}
    
public:
    vector<string> generateParenthesis(int n) {
        findAllParantheses(n,0,0);
        return allParantheses;
    }
};
