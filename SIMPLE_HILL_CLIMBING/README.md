# 🚀 Assignment 5: Simple Hill Climbing for Grid-Based Pathfinding

## 🎯 Aim

Design and implement a program where a robot navigates a **grid-based map** to reach a goal location using the **Simple Hill Climbing** algorithm. The robot can move in four directions (up, down, left, right), avoiding obstacles and selecting the path that **minimally reduces the heuristic distance** to the goal at every step.

---

## 🧠 Algorithm Used: Simple Hill Climbing

- A **local search** algorithm.
- At each step, evaluates all possible moves.
- Selects the move that **most improves (reduces)** the heuristic value (Manhattan Distance to goal).
- Continues until:
  - Goal is reached ✅
  - No neighboring move improves heuristic ❌ (local maximum or obstacle).

---

## 🧱 Grid Representation

- `0` → Open Path  
- `1` → Obstacle  
- `S` → Start Position  
- `G` → Goal Position  

> The robot **cannot move diagonally** or through obstacles.

---

## 📥 Input

- A fixed 2D grid representing the environment.
- Start and goal positions.

---

## 📤 Output

- The **path taken** by the robot from start to goal (if reached).
- A message if the robot is **stuck in a local maxima** or **blocked**.
- A visualized sequence of steps showing robot traversal.

### ✅ Example Output
```bash
✅ Goal Reached!
Path: (2,0) (2,1) (2,2) (2,3) (2,4) (3,4) (4,4) (4,3)
```
Or in failure case:
```bash
❌ Stuck at local maxima or blocked path.
Path: (2,0) (2,1) (1,1)
```

---

## 🛠️ How It Works

1. The robot starts at the `S` position.
2. From the current position:
   - It evaluates the **Manhattan Distance** for all valid neighbors.
   - Chooses the neighbor with the **lowest heuristic value**.
3. The robot moves to that cell.
4. Repeat until the robot reaches the goal or gets stuck.

---

## 🧮 Heuristic Function

```text
Manhattan Distance = |x1 - x2| + |y1 - y2|
Where:
(x1, y1) = current position
(x2, y2) = goal position
```
---

## 📊 Performance Analysis
Metric       | Description
Optimality   | ❌ Not guaranteed (greedy, may stop at local max)
Speed        | ✅ Very fast (local decision-making only)
Memory Usage | ✅ Efficient (no full graph storage or backtracking)
Completeness | ❌ Not complete (may fail if stuck in dead-end)

---

## 📌 Limitations
 - No backtracking → gets stuck easily in local maxima.

 - Not suitable for complex maps with many obstacles.

 - Can fail even when a valid path exists due to its greedy nature.

---

## 📁 File Structure
```bash 
hill_climbing/
│
├── main.cpp            # C++ implementation of the Simple Hill Climbing algorithm
├── README.md           # Project documentation (you are here)
```