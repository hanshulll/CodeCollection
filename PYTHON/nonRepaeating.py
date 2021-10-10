#First non-repeating character in a stream of characters
from queue import Queue
def nonRepeating(string):
    global Max_char
    q = Queue()
    count = [0] * Max_char
    
    for i in range(len(string)):
        q.put(string[i])
        count[ord(string[i]) - ord('a')] += 1

        while(not q.empty()):
            if(count[ord(q.queue[0]) - ord('a')] > 1):
                q.get()
            else:
                print(q.queue[0],end = " ")
                break

        if (q.empty()):
            print("#", end = " ")
    print()




Max_char = 26
string = "abbaadc"
nonRepeating(string)    