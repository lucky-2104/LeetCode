class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> lists(wordList.begin() , wordList.end());

        queue<pair<string, int>> q;
        q.push({beginWord,1});

        lists.erase(beginWord);

        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(int i = 0 ; i < word.size() ;i++)
            {
                char original = word[i];
                for(char s = 'a' ; s <= 'z' ; s++)
                {
                    word[i] = s;
                    if(lists.find(word) != lists.end()){
                        q.push({word,steps+1});
                        lists.erase(word);
                    }
                }
                word[i] = original;

            }
        }

        return 0;
    }
};
