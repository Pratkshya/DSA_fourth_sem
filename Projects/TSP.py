from itertools import permutations

def calculate_distance(route, graph):
    """Calculate total distance for a given route"""
    distance = 0
    for i in range(len(route) - 1):
        distance += graph[route[i]][route[i+1]]
    distance += graph[route[-1]][route[0]]  # Return to start
    return distance

def tsp_brute_force(graph):
    """Finds the shortest route using brute force"""
    cities = list(graph.keys())
    min_distance = float('inf')
    best_route = None

    for perm in permutations(cities):
        distance = calculate_distance(perm, graph)
        if distance < min_distance:
            min_distance = distance
            best_route = perm

    return best_route, min_distance

# Example graph (Adjacency Matrix)
graph = {
    'A': {'A': 0, 'B': 10, 'C': 15, 'D': 20},
    'B': {'A': 10, 'B': 0, 'C': 35, 'D': 25},
    'C': {'A': 15, 'B': 35, 'C': 0, 'D': 30},
    'D': {'A': 20, 'B': 25, 'C': 30, 'D': 0}
}

best_route, min_distance = tsp_brute_force(graph)
print("Best Route:", best_route)
print("Minimum Distance:", min_distance)
