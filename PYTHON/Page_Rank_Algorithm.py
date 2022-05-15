#github-username: sairam-kakarla
"""
Page Rank Algorithm
Author:[Lakshmi Sairam Kakarla]
Description:[Implementation of the Page Rank proposed by Larry Page and Sergey Brin]
"""
import time

import tabulate

def generateOutlinkVector(adjMatrix: list) -> list:
    """Takes the adjacency matrix of a network as arguments and returns the vector
    containing the number of outlinks each node has.
    The node i's outlink can be accessed by indexing with i.
    """
    outlinkVector = [sum(i) for i in adjMatrix]
    return outlinkVector


def nextIteration(pagerankvector: list, outlinkvector: list, adjMatrix: list, dampingfactor: float) -> list:
    """Takes the page rank vector and adjacency matrix of network of pages and returns the
    page rank performing one iteration of the page rank algorithm."""
    nodeCount = len(adjMatrix)
    newpageRankVector = [1 - dampingfactor] * nodeCount

    for col in range(nodeCount):
        # adjMatrix[row][col] is 1 if there is a link from node row to node col.
        for row in range(nodeCount):
            if adjMatrix[row][col] > 0:
                newpageRankVector[col] += adjMatrix[row][col]*dampingfactor * (pagerankvector[row] / outlinkvector[row])
    return newpageRankVector


def generatePageRanks(adjMatrix:list,iterations:int,dampingfactor:float)->list:
    outlinkVector = generateOutlinkVector(adjMatrix)
    # Initialise the page rank of each node as 1/#Node
    pagerankVector = [1/len(adjMatrix)]*len(adjMatrix)
    outlinkVector=generateOutlinkVector(adjMatrix)
    for i in range(iterations):
        pagerankVector=nextIteration(pagerankVector,outlinkVector,adjMatrix,dampingfactor)
    return pagerankVector


# Adjacency Matrix representation of the network of web pages
if __name__=="__main__":
    matrixNSL = [[0, 0, 1, 0, 0, 0, 0],
                 [0, 0, 1, 0, 0, 0, 0],
                 [1, 0, 0, 1, 0, 0, 0],
                 [0, 0, 0, 0, 1, 0, 0],
                 [0, 0, 0, 0, 0, 0, 1],
                 [0, 0, 0, 0, 0, 0, 1],
                 [0, 0, 0, 1, 1, 0, 0]]

    matrixSL = [[0, 0, 1, 0, 0, 0, 0],
                [0, 1, 1, 0, 0, 0, 0],
                [1, 0, 1, 1, 0, 0, 0],
                [0, 0, 0, 1, 1, 0, 0],
                [0, 0, 0, 0, 0, 0, 1],
                [0, 0, 0, 0, 0, 1, 1],
                [0, 0, 0, 1, 1, 0, 1]]

    matrixQ3 = [[0, 0, 1, 0, 0, 0, 0],
                [0, 1, 1, 0, 0, 0, 0],
                [1, 0, 1, 2, 0, 0, 0],
                [0, 0, 0, 1, 1, 0, 0],
                [0, 0, 0, 0, 0, 0, 1],
                [0, 0, 0, 0, 0, 1, 1],
                [0, 0, 0, 2, 1, 0, 1]]
    adjMatrix = matrixQ3
    iterations=25
    dampingfactor=0.85
    startT=time.time()
    pageRank=generatePageRanks(adjMatrix,iterations,dampingfactor)
    endT=time.time()
    print("[%d] iterations in [%.4f] ms"%(iterations,(endT-startT)*1000))
    print(tabulate.tabulate([["D"+str(i),pageRank[i]] for i in range(len(pageRank))],headers=["Node","Page Rank"],tablefmt="fancy_grid",floatfmt=".4f"))

