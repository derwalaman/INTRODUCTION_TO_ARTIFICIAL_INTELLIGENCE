import heapq
from collections import deque, defaultdict

# -------------------------------
# Graph (Weighted, Undirected)
# -------------------------------
graph = {
    'A': [('B', 2), ('D', 1)],
    'B': [('A', 2), ('C', 3), ('E', 2)],
    'C': [('B', 3), ('F', 4)],
    'D': [('A', 1), ('E', 5)],
    'E': [('D', 5), ('B', 2), ('F', 1)],
    'F': [('E', 1), ('C', 4)]
}

# ------------------------------------------
# Uniform Cost Search (Dijkstra-like)
# ------------------------------------------
def uniform_cost_search(start, goal):
    visited = set()
    pq = []
    heapq.heappush(pq, (0, start, [start]))  # (cost, node, path)
    explored_nodes = 0

    while pq:
        cost, node, path = heapq.heappop(pq)
        explored_nodes += 1

        if node == goal:
            return path, cost, explored_nodes

        if node in visited:
            continue
        visited.add(node)

        for neighbor, weight in graph.get(node, []):
            if neighbor not in visited:
                heapq.heappush(pq, (cost + weight, neighbor, path + [neighbor]))

    return None, float('inf'), explored_nodes

# ------------------------------------------
# Iterative Deepening Search (with cost)
# ------------------------------------------
def dls(node, goal, limit, visited, path, cost, total_cost, explored):
    explored[0] += 1

    if node == goal:
        total_cost[0] = cost
        return True

    if limit <= 0:
        return False

    visited.add(node)
    for neighbor, weight in graph.get(node, []):
        if neighbor not in visited:
            path.append(neighbor)
            if dls(neighbor, goal, limit - 1, visited, path, cost + weight, total_cost, explored):
                return True
            path.pop()
    visited.remove(node)
    return False

def iterative_deepening_search(start, goal, max_depth=10):
    for depth in range(max_depth + 1):
        visited = set()
        path = [start]
        total_cost = [0]
        explored = [0]
        if dls(start, goal, depth, visited, path, 0, total_cost, explored):
            return path, total_cost[0], explored[0]
    return None, float('inf'), explored[0]

# ------------------------------------------
# Agent Execution and Comparison
# ------------------------------------------
def run_agent(name, start, goal):
    print("=" * 25)
    print(f"Agent: {name} | Start: {start} | Goal: {goal}\n")

    # UCS
    ucs_path, ucs_cost, ucs_explored = uniform_cost_search(start, goal)
    print("🔵 Uniform Cost Search (UCS):")
    print(f"Path: {' → '.join(ucs_path)}")
    print(f"Cost: {ucs_cost}")
    print(f"Nodes Explored: {ucs_explored}\n")

    # IDS
    ids_path, ids_cost, ids_explored = iterative_deepening_search(start, goal)
    print("🟠 Iterative Deepening Search (IDS):")
    print(f"Path: {' → '.join(ids_path)}")
    print(f"Cost: {ids_cost}")
    print(f"Nodes Explored: {ids_explored}")
    print("=" * 25)

run_agent("Agent 1", "A", "F")
run_agent("Agent 2", "D", "C")