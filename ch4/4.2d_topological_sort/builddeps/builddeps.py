import sys

sys.setrecursionlimit(100000)

def post_order_dfs(dep, visited, adj_list, res):
    visited.add(dep)
    for f in adj_list[dep]:
        if f in visited: continue
        post_order_dfs(f, visited, adj_list, res)
    res.append(dep)

    
def main():
    n = int(input())
    adj_list = dict()

    for i in range(n):
        line = input().strip()
        [f, dep] = line.split(":")
        if f not in adj_list: 
            adj_list.update({f: list()})
        if len(dep) == 0: continue
        dep = dep[1:].split(" ")

        for d in dep:
            if d not in adj_list:
                adj_list.update({d: list()})
            adj_list[d].append(f)
            
    file = input()
    visited = set()
    res = list()

    post_order_dfs(file, visited, adj_list, res)
    res.reverse()
    print('\n'.join(res))

main()

