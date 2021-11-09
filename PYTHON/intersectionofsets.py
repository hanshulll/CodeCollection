def intersection_of_sets(sc1, sc2):
    result = []
    for i in sc1:
        if i in sc2:
            result.append(i)
    return result
sc1 = {"green", "blue"}
sc2 = {"blue", "yellow"}
print("Original set elements:")
print(sc1)
print(sc2)
print("\nIntersection of two said sets:")
print(intersection_of_sets(sc1, sc2))
