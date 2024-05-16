// 127. Word Ladder
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()){
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [currentWord, currentDepth] = q.front();
            q.pop();
            for(int i = 0; i<=currentWord.size(); i++){
                string newWord = currentWord;
                for(char c = 'a'; c<='z'; c++){
                    newWord[i] = c;
                    if(newWord == currentWord){
                        continue;
                    }

                    if(newWord == endWord){
                        return currentDepth+1;
                    }

                    if(wordSet.find(newWord)!=wordSet.end()){
                        q.push({newWord, currentDepth+1});
                        wordSet.erase(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
