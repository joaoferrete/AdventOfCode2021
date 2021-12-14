#Using model by Patrick L on https://github.com/plan-x64/advent-of-code-2021/blob/main/advent/day12.py

from collections import (defaultdict, deque)

def findPaths(graph):
    paths = deque([['start']])
    AllPaths = []

    while paths:
        cPath = paths.pop()
        atualVertex = cPath[-1]

        if atualVertex == 'end':
            AllPaths.append(cPath)
            

        for i in graph[atualVertex]:
            if i.isupper() or i not in cPath:
                paths.append(cPath + [i])

    return AllPaths



def main():
    graph = defaultdict(set)

    while True:
        try:
            ent = input().split("-")
            graph[ent[0]].add(ent[1])
            graph[ent[1]].add(ent[0])
        except EOFError:
            break
    
    print(graph)

    a = findPaths(graph)

    print("Quantidade: ", len(a))
    #print("Caminhos:\n", a)

main()