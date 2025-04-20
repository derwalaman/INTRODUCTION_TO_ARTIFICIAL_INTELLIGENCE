# Assignment 1: BFS and DFS Pathfinding Algorithms

🎓 **Subject:** Introduction to Artificial Intelligence  
🧑‍💻 **Author:** Aman Derwal  
📝 **Assignment Title:** Implementation of Breadth-First Search (BFS) and Depth-First Search (DFS)

---

## 📌 Aim

Write a program to:
- Implement the **Breadth-First Search (BFS)** algorithm to find a path from a start node to a goal node.
- Implement the **Depth-First Search (DFS)** algorithm to find a path from a start node to a goal node.

---

## 🧠 Problem Statement

- **Input:**
  - A graph represented using an adjacency list.
  - Start node and goal node.

- **Output:**
  - The path from start to goal node (if it exists).
  - The traversal order for BFS and DFS.

---

## 🧪 Tasks Performed

1. ✅ Wrote a function to perform **BFS** on a graph.
2. ✅ Wrote a function to perform **DFS** on a graph.
3. ✅ Compared BFS and DFS results to highlight differences in traversal and pathfinding.

---

## 🛠 Languages Used

- 💻 C++ (Using STL containers)
- 🐍 Python (Using collections and recursion)

---

## 📂 File Structure

DFS_BFS/ 
    │ 
    ├── main.cpp # C++ implementation 
    ├── main.py # Python implementation 
    └── README.md # This file

---

## 📈 Sample Graph Used
```bash
Graph (Adjacency List): 0: [1, 2] 
                        1: [0, 3, 4] 
                        2: [0, 5] 
                        3: [1] 
                        4: [1, 5] 
                        5: [2, 4]
```

- **Start Node:** 0  
- **Goal Node:** 5  

---

## 🚀 Sample Output

### ✅ BFS
```bash 
BFS Traversal Order: 0 1 2 3 4 5
Path from start to goal: 0 → 2 → 5
```

### ✅ DFS
```bash
DFS Traversal Order: 0 1 3 4 5
Path from start to goal: 0 → 1 → 4 → 5
```


---

## 🔍 BFS vs DFS: Key Differences

| Aspect         | BFS                                     | DFS                                       |
|----------------|-----------------------------------------|-------------------------------------------|
| Data Structure | Queue (FIFO)                            | Stack / Recursion (LIFO)                  |
| Goal           | Finds shortest path in unweighted graph | May not find shortest path                |
| Traversal      | Level by level                          | Depth-wise (explores as deep as possible) |

---