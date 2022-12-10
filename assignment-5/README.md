# Assigment 5

## New World, New Order

Minimum Spanning Tree
1. Prim's algorithm

    ```
    k[x]: the distance of x from the growing tree
    p[x]: if p[x] = y, it means y is the vertex k[x] comes from

    Until all the vertices have been reached
        Activate the unreached vertex u with shortest distance
        for each of u's neighbors v:
            k[v] = min(k[v], weight(u, v))
            if k[v] updated, p[v] = u
        Mark u as reached, and add (p[u], u) to MST
    ```

    Complexity: $O(m*log(n))$

2. Kruskal's algorithm

    ```
    Sort E on non-decreasing order
    MST = []
    
    for v in V:
        makeset(v)
    
    for (u, v) in E:
        if find(u) != find(v):
            add (u, v) to MST
            union(u, v)
    
    return MST
    ```

    Complexity: $O(m*log(n))$ 