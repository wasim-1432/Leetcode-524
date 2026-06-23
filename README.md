# 📝 Longest Word in Dictionary through Deleting

> 🚀 Solution to **LeetCode 524 - Longest Word in Dictionary through Deleting** using **C++**.

![LeetCode](https://img.shields.io/badge/LeetCode-524-orange?style=for-the-badge&logo=leetcode)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus)
![Status](https://img.shields.io/badge/Status-Accepted-success?style=for-the-badge)

---

## 📌 Problem Statement

Given a string `s` and a dictionary of strings, return the **longest word** in the dictionary that can be obtained by deleting some characters from `s`.

### ✅ Rules
- If multiple words have the same maximum length, return the **lexicographically smallest** one.
- If no valid word exists, return an empty string.

---

## 💡 Approach

The solution follows these steps:

1. 📚 Sort the dictionary in lexicographical order.
2. 🔍 For every word in the dictionary:
   - Check whether it is a **subsequence** of the given string.
   - Use `string::find()` with a starting index to maintain the correct character order.
3. 🏆 Keep updating the answer whenever a longer valid word is found.

---

## ⚙️ Algorithm

- Sort the dictionary.
- Initialize an empty answer string.
- For every word:
  - Start searching characters from the previous matched position.
  - If every character is found in order, it is a valid subsequence.
  - Update the answer if its length is greater than the current answer.
- Return the final answer.

---

## ⏱️ Time Complexity

| Operation | Complexity |
|-----------|------------|
| Sorting Dictionary | **O(n log n)** |
| Subsequence Checking | **O(n × m)** *(approximately)* |

> Where:
> - **n** = Number of words
> - **m** = Average length of each word

---

## 💾 Space Complexity

```text
O(1)
```

(Excluding the dictionary storage.)

---

## 🧠 Key Concepts Used

- ✅ Sorting
- ✅ Strings
- ✅ Greedy
- ✅ Subsequence Checking
- ✅ `string::find()`

---

## 🖥️ C++ Solution

```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        sort(dictionary.begin(), dictionary.end());

        string ans = "";

        for(int i = 0; i < dictionary.size(); i++)
        {
            int idx = 0;
            bool found = true;

            for(int j = 0; j < dictionary[i].size(); j++)
            {
                size_t pos = s.find(dictionary[i][j], idx);

                if(pos == string::npos)
                {
                    found = false;
                    break;
                }

                idx = pos + 1;
            }

            if(found && ans.size() < dictionary[i].size())
            {
                ans = dictionary[i];
            }
        }

        return ans;
    }
};
```

---

## 📈 Result

✅ **Accepted**

- ⚡ Runtime: **3 ms**
- 🚀 Beats **97.91%** of C++ submissions
- 💾 Memory: **20.20 MB**
- 📊 Beats **64.63%** of C++ submissions

---

## 🎯 What I Learned

- How to efficiently check whether a string is a **subsequence**.
- Proper use of `string::find()` with a starting index.
- Handling **lexicographical ordering** using sorting.
- Writing clean and optimized C++ code for interview-style problems.

---

## 🔗 Problem Link

👉 https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

---

## ⭐ If you found this repository helpful

Give it a ⭐ and feel free to explore my other LeetCode solutions!

Happy Coding! 🚀💻
