

class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool digitAfterE = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // Digit
            if (isdigit(c)) {
                digitSeen = true;

                if (eSeen) {
                    digitAfterE = true;
                }
            }

            // Dot
            else if (c == '.') {
                // Dot cannot appear after e
                // or more than once
                if (dotSeen || eSeen) {
                    return false;
                }

                dotSeen = true;
            }

            // Exponent
            else if (c == 'e' || c == 'E') {
                // Must have a number before e
                // and only one exponent is allowed
                if (eSeen || !digitSeen) {
                    return false;
                }

                eSeen = true;
                digitAfterE = false;
            }

            // Sign
            else if (c == '+' || c == '-') {
                // Sign is allowed only at the beginning
                // or immediately after e/E
                if (i != 0 &&
                    s[i - 1] != 'e' &&
                    s[i - 1] != 'E') {
                    return false;
                }
            }

            // Anything else is invalid
            else {
                return false;
            }
        }

        // Must have a digit overall
        // and if exponent exists, it must have a digit
        return digitSeen && digitAfterE;
    }
};