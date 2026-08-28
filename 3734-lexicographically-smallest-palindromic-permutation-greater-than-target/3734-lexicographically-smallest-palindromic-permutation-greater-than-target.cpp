class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26);
        for (char c : s)
            cnt[c - 'a']++;

        // Check if a palindrome can be formed
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        int len = n / 2;

        // Characters available in the first half
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        string targetHalf = target.substr(0, len);

        int bestPos = -1;
        int bestChar = -1;

        vector<int> rem = half;

        // Find the rightmost position where we can make
        // the half strictly larger than targetHalf.
        for (int i = 0; i < len; i++) {
            int x = targetHalf[i] - 'a';

            // Smallest available character greater than target[i]
            for (int c = x + 1; c < 26; c++) {
                if (rem[c] > 0) {
                    bestPos = i;
                    bestChar = c;
                    break;
                }
            }

            // Continue matching targetHalf
            if (rem[x] == 0)
                break;

            rem[x]--;
        }

        string ans = "";

        // Construct candidate by increasing at bestPos
        if (bestPos != -1) {
            rem = half;

            for (int i = 0; i < bestPos; i++)
                rem[targetHalf[i] - 'a']--;

            rem[bestChar]--;

            string h = targetHalf.substr(0, bestPos);
            h += char('a' + bestChar);

            // Smallest possible suffix
            for (int c = 0; c < 26; c++)
                h += string(rem[c], char('a' + c));

            string p = h;

            if (n % 2)
                p += mid;

            p += string(h.rbegin(), h.rend());

            ans = p;
        }

        // Also check whether targetHalf itself can be constructed.
        // If yes, the middle character may make the palindrome > target.
        rem = half;
        bool possible = true;

        for (char c : targetHalf) {
            if (rem[c - 'a'] == 0) {
                possible = false;
                break;
            }
            rem[c - 'a']--;
        }

        if (possible) {
            string h = targetHalf;
            string p = h;

            if (n % 2)
                p += mid;

            p += string(h.rbegin(), h.rend());

            if (p > target) {
                if (ans.empty() || p < ans)
                    ans = p;
            }
        }

        return ans;
    }
};