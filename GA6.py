print ('введите номер задачи на проверку')
task = int(input())

if task == 1:
    n, s, f = map(int, input().split())
    s -= 1; f -= 1
    g = [list(map(int, input().split())) for _ in range(n)]
    
    dist = [float('inf')] * n
    dist[s] = 0
    visited = [False] * n
    
    for _ in range(n):
        a = -1
        for i in range(n):
            if not visited[i] and (a == -1 or dist[i] < dist[a]):
                a = i
        if dist[a] == float('inf'):
            break
        visited[a] = True
        for b in range(n):
            if g[a][b] > -1 and dist[a] + g[a][b] < dist[b]:
                dist[b] = dist[a] + g[a][b]
    
    print(dist[f] if dist[f] != float('inf') else -1)

else:

    n = int(input())
    cost = list(map(int, input().split()))
    m = int(input())
    g = [[] for _ in range(n)]
    
    for _ in range(m):
        a, b = map(int, input().split())
        g[a-1].append(b-1)
        g[b-1].append(a-1)
    
    dist = [float('inf')] * n
    dist[0] = 0
    visited = [False] * n
    
    for _ in range(n):
        a = -1
        for i in range(n):
            if not visited[i] and (a == -1 or dist[i] < dist[a]):
                a = i
        if dist[a] == float('inf'):
            break
        visited[a] = True
        for b in g[a]:
            if dist[a] + cost[a] < dist[b]:
                dist[b] = dist[a] + cost[a]
    
    print(dist[n-1] if dist[n-1] != float('inf') else -1)