from math import inf
from bisect import bisect_left as bLeft, bisect_right as bRight
from collections import defaultdict

def getHealth(seq, first, last, largest):
  h, ls = 0, len(seq)
  for f in range(ls):
    for j in range(1, largest+1):
      if f+j > ls: break
      sub = seq[f:f+j]
      if sub not in subs: break
      if sub not in gMap: continue
      ids, hs = gMap[sub]
      h += hs[bRight(ids, last)]-hs[bLeft(ids, first)]
  return h

howGenes = int(input())
genes = input().rstrip().split()
healths = list(map(int, input().rstrip().split()))
howStrands = int(input())
gMap = defaultdict(lambda: [[], [0]])
subs = set()
for id, gene in enumerate(genes):
  gMap[gene][0].append(id)
  for j in range(1, min(len(gene), 500)+1): subs.add(gene[:j])
for v in gMap.values():
  for i, ix in enumerate(v[0]): v[1].append(v[1][i]+healths[ix])

largest = max(list(map(len, genes)))
hMin, hMax = inf, 0
for _ in range(howStrands):
  firstLastd = input().split()
  first = int(firstLastd[0])
  last = int(firstLastd[1])
  strand = firstLastd[2]
  h = getHealth(strand, first, last, largest)
  hMin, hMax = min(hMin, h), max(hMax, h)
print(hMin, hMax)
