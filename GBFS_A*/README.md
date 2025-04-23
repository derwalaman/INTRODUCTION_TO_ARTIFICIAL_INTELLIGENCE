# Assignment 3: Greedy Best-First Search (GBFS) & A* Search

## 🎯 Aim

Design a program that finds the **shortest path in a weighted graph** using:

- **Greedy Best-First Search (GBFS)**
- **A* Search**

The graph represents a **city map** where:
- Nodes = Locations
- Edges = Roads with distances
- Each node has a **heuristic value** representing estimated cost to the goal.

---

## 🧩 Problem Description

Implement and compare both search algorithms in terms of:

1. 🔍 **Total Path Cost**
2. 📈 **Number of Nodes Expanded**

---

## 🛠️ Steps Involved

### ✅ Step 1: Greedy Best-First Search (GBFS)

- Use a **priority queue** (min-heap) based on heuristic `h(n)`
- Always expand the node with the **lowest heuristic value**
- Stop once the **goal node is reached**

### ✅ Step 2: A* Search

- Use a **priority queue** based on `f(n) = g(n) + h(n)`
  - `g(n)` = cost from start to current node
  - `h(n)` = heuristic estimate from current node to goal
- Always expand the node with the **lowest f(n)**
- Stop when the **goal node is reached**

---

## 🧪 Input Format

- Graph as **adjacency list** with edge weights
- Separate **heuristic values** for each node
- Start and goal nodes

---

## 🧾 Output

For each algorithm:
- 📍 Path from start to goal
- 💰 Total cost of the path
- 🔄 Number of nodes expanded

---

## 📊 Example Output
```bash
Start: A | Goal: F

🟢 Greedy Best-First Search (GBFS): Path: A → C → F Cost: 10 Nodes Expanded: 3

🔵 A* Search: Path: A → B → E → F Cost: 7 Nodes Expanded: 5
```


---

## 🚀 Technologies Used

- Language: C++
- STL: `unordered_map`, `vector`, `priority_queue`, `set`, etc.

---

## 👨‍💻 Author

**Aman Derwal**  
B.Tech CSE – Introduction to Artificial Intelligence Lab  
National Institute of Technology, Delhi

---

## 📁 File Structure
```bash
GBFS_A*
├── main.cpp # C++ implementation of GBFS and A* Search 
└── README.md # You're here!
```
