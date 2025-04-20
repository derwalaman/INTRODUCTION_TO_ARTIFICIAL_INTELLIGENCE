# 🚚 Assignment 2: Optimal Delivery Pathfinding using UCS and IDS

### 👨‍🏫 Subject: Introduction to Artificial Intelligence  
### 🎓 Author: Aman Derwal  
### 📘 Assignment 2 – Weighted Graph Search Algorithms  
---

## 🧠 Aim

To implement **Uniform Cost Search (UCS)** and **Iterative Deepening Search (IDS)** for delivery agents navigating through a weighted graph representing a city map. The objective is to find the **least-cost path** from start to goal for each agent and compare the two algorithms based on:

- ✅ **Optimality**: Does it find the lowest-cost path?
- 🧮 **Exploration Cost**: How many nodes are explored?
- 💾 **Memory Usage**: How much memory does it use?

---

## 🗺️ Problem Statement

- Each **node** represents a **city or location**
- Each **edge** has a **weight** (distance, time, toll, etc.)
- Multiple **agents** have a start and goal location
- Find the most efficient route for each agent using:
  - 🔵 **UCS (Uniform Cost Search)**
  - 🟠 **IDS (Iterative Deepening Search)**

---

## 🛠️ Requirements

### ✅ Input:
- Weighted graph (as adjacency list)
- Multiple agents with:
  - Start node
  - Goal node

### ✅ Output:
- Path found by UCS and IDS
- Total cost of the path
- Number of nodes explored

---

## 🧪 Sample Graph Used
```bash
A-----B-----C
|     |     |
|     |     |
D-----E-----F

graph = {
    'A': [('B', 2), ('D', 1)],
    'B': [('A', 2), ('C', 3), ('E', 2)],
    'C': [('B', 3), ('F', 4)],
    'D': [('A', 1), ('E', 5)],
    'E': [('D', 5), ('B', 2), ('F', 1)],
    'F': [('E', 1), ('C', 4)] 
}
```
---

## 🔍 Sample Output
```bash
Agent: Agent 1 | Start: A | Goal: F

🔵 Uniform Cost Search (UCS):   
                Path: A → B → E → F 
                Cost: 5 Nodes Explored: 6

🟠 Iterative Deepening Search (IDS):  
                Path: A → B → C → F 
                Cost: 9 Nodes Explored: 4

*********************************************
Agent: Agent 2 | Start: D | Goal: C

🔵 Uniform Cost Search (UCS): 
                Path: D → A → B → C 
                Cost: 6 Nodes Explored: 6

🟠 Iterative Deepening Search (IDS): 
                Path: D → A → B → C 
                Cost: 6 Nodes Explored: 4
```


---

## ⚖️ Comparison Summary

| Metric               | UCS                                | IDS                              |
|----------------------|------------------------------------|----------------------------------|
| **Optimality**       | ✅ Always optimal                  | ❌ May miss optimal (Agent 1)     |
| **Exploration Cost** | ❌ Explores more nodes             | ✅ Often fewer nodes              |
| **Memory Usage**     | ❌ High (uses priority queue)      | ✅ Low (DFS stack-based)          |

---

## 📂 Files Included

| File Name             | Description                           |
|-----------------------|---------------------------------------|
| `assignment2.cpp`     | C++ implementation with UCS & IDS     |
| `assignment2.py`      | Python implementation with same logic |
| `README.md`           | This documentation file               |

---

## 💡 Conclusion

- **UCS** is best when optimal path cost is required.
- **IDS** can be more efficient in memory and nodes explored.
- Choosing the right algorithm depends on your application needs.

---

## ✨ Future Scope

- Visualize paths on a map using Next.js frontend.
- Compare with A*, Greedy, Dijkstra, etc.
- Track real-time agent movement.

---

