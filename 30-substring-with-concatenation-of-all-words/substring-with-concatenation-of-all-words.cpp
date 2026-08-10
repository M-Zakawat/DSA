class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        if (totalLength > s.size()) {
            return result;
        }

        unordered_map<string, int> required;

        for (const string& word : words) {
            required[word]++;
        }

        // Try every possible word alignment.
        for (int offset = 0; offset < wordLength; offset++) {
            int left = offset;
            int usedWords = 0;

            unordered_map<string, int> current;

            for (int right = offset;
                 right + wordLength <= s.size();
                 right += wordLength) {

                string word = s.substr(right, wordLength);

                // Invalid word: reset the window.
                if (!required.count(word)) {
                    current.clear();
                    usedWords = 0;
                    left = right + wordLength;
                    continue;
                }

                current[word]++;
                usedWords++;

                // Remove words from the left if this word is overused.
                while (current[word] > required[word]) {
                    string leftWord = s.substr(left, wordLength);
                    current[leftWord]--;
                    left += wordLength;
                    usedWords--;
                }

                // The window contains exactly all words.
                if (usedWords == wordCount) {
                    result.push_back(left);

                    // Move forward to find overlapping matches.
                    string leftWord = s.substr(left, wordLength);
                    current[leftWord]--;
                    left += wordLength;
                    usedWords--;
                }
            }
        }

        return result;
    }
};