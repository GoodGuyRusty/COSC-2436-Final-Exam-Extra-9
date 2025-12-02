// LeetCode (Medium) | Longest Substring Without Repeating Characters | https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
int n = s.length();
        if (n == 0) {
            return 0;
        }

        unordered_map<char, int> char_counts;
        
        int left = 0;
        int max_length = 0;

        for (int right = 0; right < n; ++right) {
            char current_char = s[right];

            char_counts[current_char]++;

            while (char_counts[current_char] > 1) {
                char left_char = s[left];
                char_counts[left_char]--;

                left++;
            }

            max_length = max(max_length, right - left + 1);
        }

        return max_length;  
    }
};
