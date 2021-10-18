#libraries
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer

Doc1 = "Shared Computer Resources"
Doc2 = "Computer Services"
Doc3 = "Digital Shared Components" 
Doc4 = "Computer Resources Shared Components" 

#split
bagOfWordsA = Doc1.split(' ')
bagOfWordsB = Doc2.split(' ')
bagOfWordsC = Doc3.split(' ')
bagOfWordsD = Doc4.split(' ')

#get bag of words
print("Bag of Words in A: ", bagOfWordsA)
print("Bag of Words in B: ", bagOfWordsB)
print("Bag of Words in C: ", bagOfWordsC)
print("Bag of Words in D: ", bagOfWordsD)

#get unique words
uniqueWords1 = set(bagOfWordsA).union(set(bagOfWordsB))
uniqueWords2 = set(uniqueWords1).union(set(bagOfWordsC))

uniqueWordsf = set(uniqueWords2).union(set(bagOfWordsD)) 
print("\nUnique words: ", uniqueWordsf)


numOfWordsA = dict.fromkeys(uniqueWordsf, 0)  #assign 0 to all the words in uniqueWordsf
numOfWordsB = dict.fromkeys(uniqueWordsf, 0)
numOfWordsC = dict.fromkeys(uniqueWordsf, 0)
numOfWordsD = dict.fromkeys(uniqueWordsf, 0)
print("\nNo of Words in A (all 0): ", numOfWordsA)  

for word in bagOfWordsA:
    numOfWordsA[word] +=1
print("\nNo of Words in A: ", numOfWordsA)

for word in bagOfWordsB:
    numOfWordsB[word] +=1
print("No of Words in B: ", numOfWordsB)

for word in bagOfWordsC:
    numOfWordsC[word] +=1
print("No of Words in C: ", numOfWordsC)

for word in bagOfWordsD:
    numOfWordsD[word] +=1
print("No of Words in D: ", numOfWordsD)
