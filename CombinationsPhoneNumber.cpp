// 17. Letter Combinations of a Phone Number
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> result;
        string currentCombination;

        backtrack(digits, 0, digitToLetters, currentCombination, result);
        return result;
    }

    void backtrack(string& digits, int index, unordered_map<char, string>& digitToLetters,
    string& currentCombination, vector<string>& result){
        if(index == digits.size()){
            result.push_back(currentCombination);
            return;
        }

        char currentDigit = digits[index];
        const string& letters = digitToLetters.at(currentDigit);
        for(char letter:letters){
            currentCombination.push_back(letter);
            backtrack(digits, index+1, digitToLetters, currentCombination, result);
            currentCombination.pop_back();
        }
    }
};
