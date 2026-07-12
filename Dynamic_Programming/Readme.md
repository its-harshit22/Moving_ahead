# 📘 Dynamic Programming (DP)

Welcome to my **Dynamic Programming** repository! 🚀

This repository is designed to help understand how a recursive solution gradually evolves into an optimized Dynamic Programming solution.

For **every DP problem**, I include **all four approaches in a single file** so that the progression is easy to follow.

---

## 📂 Code Structure

Each file contains the following implementations:

### 1️⃣ Recursion
- Solve the problem using pure recursion.
- Easy to understand but contains overlapping subproblems.
- **Time Complexity:** Usually Exponential (e.g., `O(2^N)`)

---

### 2️⃣ Memoization (Top-Down DP)
- Optimizes recursion by storing previously computed results.
- Eliminates repeated calculations.
- Uses recursion + DP array.

---

### 3️⃣ Tabulation (Bottom-Up DP)
- Converts the recursive solution into an iterative one.
- Removes recursion overhead.
- Builds the DP table from the base case.

---

### 4️⃣ Space Optimization
- Reduces extra memory usage.
- Stores only the states that are actually required.
- Usually converts `O(N)` space into `O(1)` whenever possible.

---

## 📖 Learning Flow

```
Recursion
     │
     ▼
Memoization
     │
     ▼
Tabulation
     │
     ▼
Space Optimization
```

This progression is followed for every problem in this repository.

---

## 📁 File Organization

Example:

```
01_FrogJump.cpp
├── Recursion
├── Memoization
├── Tabulation
└── Space Optimization
```

Every file follows the same structure for consistency and easier revision.

---

## 🎯 Goal

The aim of this repository is not only to solve problems but also to understand:

- ✔️ How recursion works
- ✔️ How overlapping subproblems are identified
- ✔️ How recursion is converted into Dynamic Programming
- ✔️ How to optimize both time and space complexity

---

## 🧠 Topics Covered

- Fibonacci DP
- Frog Jump
- House Robber
- Grid DP
- Subsequences
- Knapsack
- Longest Increasing Subsequence (LIS)
- Longest Common Subsequence (LCS)
- DP on Strings
- DP on Stocks
- Partition DP
- DP on Trees
- Digit DP
- and many more...

---

## 📚 Reference

This repository is created while learning **Dynamic Programming** from **Striver's A2Z DSA Course**.

---

⭐ If this repository helps you, consider giving it a star!

Happy Coding! 🚀
