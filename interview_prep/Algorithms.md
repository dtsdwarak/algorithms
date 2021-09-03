# Algorithms

This page mentions specific algorithms for each section of DS problems. (This is part of [@dtsdwarak's CS Prep Guide](./README.md))

> Algorithm References
> 1. https://www.geeksforgeeks.org/fundamentals-of-algorithms/ - List of Algorithms/Problems
> 2. https://tutorialspoint.dev/ - List of Algorithms/Problems
> 3. [2017 Book to Competitive Programming](https://www.dropbox.com/s/xiu5yx6r7rckux3/2017_Book_GuideToCompetitiveProgramming.pdf?dl=0)
> 4. [An awesome list for competitve programming - Codeforces Blog Entry](https://codeforces.com/blog/entry/23054)
> 5. [Popular DS/Algo Implementation References - Codeforces Blog Entry](https://discuss.codechef.com/t/data-structures-and-algorithms/6599)

## Arrays

1. Kadane's Algorithm

## Stacks/Queues

1. Next Greater Element - I, II
2. Parentheses
3. Minimum Cost Tree From Leaf Values
4. Score of Parentheses
5. Validate Stack Sequences

> References
> 1. [GeeksForGeeks - Stack](https://www.youtube.com/playlist?list=PLqM7alHXFySF7Lap-wi5qlaD8OEBx9RMV)
> 2. [GeeksforGeeks - Queue](https://www.youtube.com/playlist?list=PLqM7alHXFySG6wgjVeEat_ouTIi0IBQ6D)
> 3. [Aditya Verma - Stack](https://www.youtube.com/playlist?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd)

## String

### Pattern Matching

1.	Naive Pattern Searching - [Abdul Bari](https://youtu.be/V5-7GzOfADQ)
2.	KMP Algorithm - [Abdul Bari](https://youtu.be/V5-7GzOfADQ), [Back to Back SWE](https://youtu.be/BXCEFAzhxGY), [Tushar Roy](https://youtu.be/GTJr8OvyEVQ), [GeeksForGeeks](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
3.	Rabin-Karp Algorithm - [Tushar Roy](https://www.youtube.com/watch?v=H4VrKHVG5qI)
4.	A Naive Pattern Searching Question
5.	Finite Automata
6.	Efficient Construction of Finite Automata
7.	Boyer Moore Algorithm – Bad Character Heuristic
8.	Suffix Array
9.	Anagram Substring Search (Or Search for all permutations)
10.	Pattern Searching using a Trie of all Suffixes
11.	Aho-Corasick Algorithm for Pattern Searching
12.	kasai’s Algorithm for  Construction of LCP array from Suffix Array
13.	Z algorithm (Linear time pattern searching Algorithm)
14.	Program to wish Women’s Day 

### Other String Algorithms

1. Manacher’s Algorithm – Linear Time Longest Palindromic Substring – Part 1, Part 2, Part 3, Part 4
2. Longest Even Length Substring such that Sum of First and Second Half is same
3. Print all possible strings that can be made by placing spaces

> References 
> 1. https://www.geeksforgeeks.org/fundamentals-of-algorithms/#PatternSearching
> 2. https://www.geeksforgeeks.org/fundamentals-of-algorithms/#OtherStringAlgorithms

## Hashing

1. https://medium.com/@codingfreak/hashing-problems-in-data-structures-c41b77a5119a

## Bit Manipulation

1. Bit Hacks — Part 1 (Basic)
2. Bit Hacks — Part 2 (Playing with k’th bit)
3. Bit Hacks — Part 3 (Playing with rightmost set bit of a number)
4. Bit Hacks — Part 4 (Playing with letters of English alphabet)
5. Bit Hacks — Part 5 (Find absolute value of an integer without branching)
6. Bit Hacks — Part 6 (Random Problems)
7. Brian Kernighan’s Algorithm to count set bits in an integer
8. Compute parity of a number using lookup table
9. Count set bits using lookup table
10. Find the minimum or maximum of two integers without using branching
11. Multiply 16-bit integers using 8-bit multiplier
12. Round up to the next highest power of 2
13. Round up to the previous power of 2
14. Swap individual bits at given position in an integer
15. Check if given number is power of 4 or not
16. Reverse Bits of a given Integer
17. Find odd occurring element in an array in single traversal
18. Find two odd occurring element in an array without using any extra space
19. Swap two bits at given position in an integer
20. Add binary representation of two integers
21. Swap Adjacent Bits of a Number
22. Print all distinct Subsets of a given Set
23. Perform Division of two numbers without using division operator (/)
24. Check if adjacent bits are set in binary representation of a given number
25. Conditionally negate a value without branching
26. Find two duplicate elements in an limited range array (using XOR)
27. Find missing number and duplicate elements in an array
28. Check if given number is power of 8 or not
29. Circular shift on binary representation of an integer by k positions
30. Solve given set of problems without using multiplication or division operators
31. Reverse Bits of an integer using lookup table
32. Generate binary numbers between 1 to N
33. Efficiently implement power function | Recursive and Iterative
34. Find square of a number without using multiplication and division operator
35. Generate power set of a given set
36. Find all odd occurring elements in an array having limited range of elements

> References   
> https://medium.com/techie-delight/bit-manipulation-interview-questions-and-practice-problems-27c0e71412e7

## Dynamic Programming

> References
> 1. [Grokking Dynamic Programming Patterns for Coding Interviews](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews)
> 2. Following is reference from [@ asutosh97/educative-io-contents](https://github.com/asutosh97/educative-io-contents/blob/master/Grokking%20Dynamic%20Programming%20Patterns%20for%20Coding%20Interviews.md)
> 3. Also, refer to [Adithya Verma's Dynamic Programming Playlist](https://www.youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go)
> 3.1. Code samples for the problems provided - [@Lord-Lava/Dynamic-Programming-Problems](https://github.com/Lord-Lava/Dynamic-Programming-Problems)

### Pattern 1: 0/1 Knapsack

1. [0/1 Knapsack Problem](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
2. [Equal Subset Sum Partition](https://www.geeksforgeeks.org/partition-problem-dp-18/)
3. [Subset Sum](https://www.geeksforgeeks.org/subset-sum-problem-dp-25/)
4. [Minimum Subset Sum Difference](https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/)
5. [Count of subset sum](https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/)
6. [Target Sum (Leetcode)](https://leetcode.com/problems/target-sum/solution/)

### Pattern 2: Unbounded Knapsack

1. [Unbounded Knapsack](https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/)
2. [Rod Cutting](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)
3. [Coin Change](https://www.geeksforgeeks.org/coin-change-dp-7/)
4. [Minimum Coin Change](https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/)
5. [Maximum Ribbon Cut](https://www.geeksforgeeks.org/maximum-number-segments-lengths-b-c/)

### Pattern 3: Fibonacci Numbers

1. [Fibonacci Number](https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/)
2. [Staircase](https://www.geeksforgeeks.org/count-ways-reach-nth-stair/)
3. [Number divisors](https://www.geeksforgeeks.org/total-number-divisors-given-number/) - // TODO
4. [Minimum jumps to reach end](https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/)
5. Minimum jumps with fee - // TODO
6. [House Thief](https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/)

### Pattern 4: Palindromic Subsequence

1. [Longest Pallindromic Subsequence](https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/)
2. [Longest Pallindromic Substring](https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/)
3. [Count of Pallindromic Substrings](https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/)
4. [Minimum deletions to make a string pallindrome](https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/)
5. [Pallindromic Partitioning](https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/)

### Pattern 5: Longest Common Substring

1. [Longest Common Substring](https://www.geeksforgeeks.org/longest-common-substring-dp-29/)
2. [Longest Common Subsequence](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/)
3. [Minimum Deletions and Insertions to Transform a String into another](https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/)
4. [Longest Increasing Subsequence](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/)
5. [Maximum Sum Increasing Subsequence](https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/)
6. [Shortest Common Supersequence](https://www.geeksforgeeks.org/shortest-common-supersequence/)
7. [Minimum deletions to make sequence sorted](https://www.geeksforgeeks.org/minimum-number-deletions-make-sorted-sequence/)
8. [Longest repeating subsequence](https://www.geeksforgeeks.org/longest-repeating-subsequence/)
9. Subsequence Pattern Matching  - // TODO
10. [Longest Bitonic Subsequence](https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/)
11. [Longest Alternating Subsequence](https://www.geeksforgeeks.org/longest-alternating-subsequence/)
12. [Edit Distance](https://www.geeksforgeeks.org/edit-distance-dp-5/)
13. [String Interleaving](https://www.geeksforgeeks.org/find-if-a-string-is-interleaved-of-two-other-strings-dp-33/)

### Pattern 6: Longest Increasing Subsequence

### Pattern 7: Kadane's Algorithm

### Pattern 8: Matrix Chain Multiplication

### Pattern 9: DP on Trees

### Pattern 10: DP on Grid

### Patter 11: Others
---

# Leetcode Interview Question List

1. [Preparing with Leetcode](https://www.reddit.com/r/cscareerquestions/comments/6luszf/a_leetcode_grinding_guide/)
2. [xiaoguan's Leetcode Diary](https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/leetcode-diary.html)
3. [twchen's Leetcode Problem Solutions](https://twchen.gitbook.io/leetcode/array)

## Google Interview Questions

1. [2020 Google Interview Questions](https://leetcode.com/list/52657ph7/)
2. [60 LeetCode problems to solve for coding interiew](https://docs.google.com/spreadsheets/d/1Y98QKaYPazWImEt1nA_ocpGNJ-yQjH1FAsVQhUQ7OTw/edit#gid=0)
