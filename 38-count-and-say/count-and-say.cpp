class Solution {
public:
    string countAndSay(int n) {
        string current = "1";

        for (int step = 2; step <= n; step++) {
            string next;

            for (int i = 0; i < current.size();) {
                int j = i;

                // Count consecutive equal digits
                while (j < current.size() && current[j] == current[i]) {
                    j++;
                }

                int count = j - i;
                next += to_string(count);
                next += current[i];

                // Move to the next group
                i = j;
            }

            current = next;
        }

        return current;
    }
};