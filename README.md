# 🧩 CubeMind – 3×3 Rubik's Cube Solver

A C++ Rubik's Cube solver built using **Data Structures and Algorithms (DSA)**, with a focus on search algorithms, heuristic evaluation, backtracking, and optimization.

The goal of this project is to explore how classic algorithms can solve complex puzzle states without using AI or external cube-solving libraries.

## 🚀 Project Overview

CubeMind is a 3×3 Rubik's Cube solver that represents the cube using a 3D vector and searches for solutions using different search strategies.

The primary solver uses **Iterative Deepening A* (IDA*)**, combining depth-first search with heuristic evaluation.

## 🛠️ Technologies Used

- C++
- STL (Standard Template Library)
- 3D Vectors
- Recursion and Backtracking
- Hash Tables

## 🧠 Algorithms Implemented / Explored

| Algorithm | Purpose |
|---|---|
| Breadth-First Search (BFS) | Explores cube states level by level |
| Bidirectional BFS | Searches from initial and goal states |
| Depth-First Search (DFS) | Explores possible move sequences |
| IDA* Search | Main heuristic-based search approach |
| Backtracking | Explores and reverses possible moves |
| Heuristic Evaluation | Estimates the remaining distance to the solved state |

## 📦 Data Structures Used

- `vector` – Represents the Rubik's Cube using a 3D structure.
- `queue` – Supports BFS.
- `unordered_map` – Stores previously explored states and search information.
- `unordered_set` – Tracks visited states.
- `string` – Represents cube states and move sequences.
- Recursion Stack – Manages DFS and IDA* exploration.
- `enum` – Represents cube faces and colors.

## 🎯 Features

- 3×3 Rubik's Cube representation.
- Six-face rotation system.
- Clockwise, counterclockwise, and double-turn moves.
- Inverse move generation.
- Cube state serialization.
- Solved-state verification.
- Heuristic-based search.
- Transposition table for reducing repeated exploration.
- Scramble and solution testing.

## 💻 Getting Started

### Prerequisites

- C++ compiler (GCC / MinGW)
- C++17 or later
- VS Code (recommended, optional)

### Compilation

```bash
g++ -std=c++17 -O2 code.cpp -o CubeMind
```

### Run

**Windows:**

```bash
.\CubeMind.exe
```

**Linux / macOS:**

```bash
./CubeMind
```

## 📊 Performance Testing

The solver has been tested with different scramble lengths.

| Test | Scramble length | Result |
|---|---:|---|
| Test 1 | 1 move | Solved |
| Test 2 | 6 moves | Solved |
| Benchmark | 10 moves | Reached node limit |

### Previous 10-Move Benchmark

- Number of runs: 5
- Node limit per run: 1,000,000
- Total nodes explored: 5,000,000
- All five runs reached the node limit.

*Execution times depend on the hardware, compiler, and execution environment.*

## 🔧 Future Improvements

- Improve heuristic evaluation.
- Optimize IDA* threshold selection.
- Implement apply-and-undo move operations.
- Improve move pruning.
- Implement Pattern Database heuristics.
- Optimize state representation and hashing.
- Improve performance on longer scrambles (25–30 moves).

## 🎓 Project Objective

This project is primarily developed as a DSA learning project to understand the practical application of:

- Graph search algorithms
- Heuristic search
- Recursion and backtracking
- State-space exploration
- Hashing and optimization

## 👨‍💻 Author

**Pratyush Pal**

GitHub: [@pratyushpal67-afk](https://github.com/pratyushpal67-afk)

---

⭐ If you find this project interesting, consider giving the repository a star!

**Repository:** [CubeMind](https://github.com/pratyushpal67-afk/CubeMind)