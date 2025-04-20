from collections import deque, defaultdict

def bfs(graph, start, goal):
    visited = set()
    q = deque([[start]])
    visited.add(start)

    print("BFS Traversal Order:", end=" ")

    while q:
        path = q.popleft()
        node = path[-1]
        print(node, end=" ")

        if node == goal:
            return path
        
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                new_path = list(path)
                new_path.append(neighbor)
                q.append(new_path)
        
    return []

def dfs_util(graph, node, goal, visited, path):
    visited.add(node)
    path.append(node)
    print(node, end=" ")

    if node == goal:
        return True

    for neighbor in graph[node]:
        if neighbor not in visited:
            if dfs_util(graph, neighbor, goal, visited, path):
                return True

    path.pop()  # Backtrack
    return False

def dfs(graph, start, goal):
    visited = set()
    path = []
    print("DFS Traversal Order:", end=" ")
    dfs_util(graph, start, goal, visited, path)
    return path

def print_path(path):
    if not path:
        print("\nNo path found.")
    else:
        print("\nPath from start to goal:", ' → '.join(map(str, path)))

if __name__ == "__main__":
    graph = defaultdict(list)
    graph[0] = [1, 2]
    graph[1] = [0, 3, 4]
    graph[2] = [0, 5]
    graph[3] = [1]
    graph[4] = [1, 5]
    graph[5] = [2, 4]

    start = 0
    goal = 5

    # BFS
    bfs_path = bfs(graph, start, goal)
    print_path(bfs_path)

    print("\n" + "-" * 30)

    # DFS
    dfs_path = dfs(graph, start, goal)
    print_path(dfs_path)