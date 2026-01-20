from collections import deque
graf = {}
graf['S'] = ['A', 'B', 'E', 'D']
graf['A'] = ['S']
graf['B'] = ['S', 'C', 'D']
graf['C'] = ['B', 'J']
graf['D'] = ['B', 'G', 'S']
graf['E'] = ['S', 'G']
graf['F'] = ['G', 'H']
graf['G'] = ['E', 'D', 'F', 'H', 'J']
graf['H'] = ['F', 'G', 'I']
graf['I'] = ['H', 'J']
graf['J'] = ['I' , 'G', 'C']
def shortest(st, end):
    poisk = deque()
    poisk.append([st])
    visited = set([st])
    while poisk:
        path = poisk.popleft()
        eta_room = path[-1]
        
        if eta_room == end:
            return path
        
        for sosedn in graf[eta_room]:
            if sosedn not in visited:
                visited.add(sosedn)
                new_path = path + [sosedn]
                poisk.append(new_path)
    
    return None
start_room = 'S'
end_room = 'I'
result = shortest(start_room, end_room)

if result:
    print("our way:")
    print(" -> ".join(result))
    print("length: " + str(len(result) - 1) + " rooms") #тут 4 решения, которые зависят от порядка заполнения графа
else:
    print("no way")