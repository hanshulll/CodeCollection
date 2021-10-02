#Construction of a minimal NFA accepting a set of strings over {a, b} in
#which each string of the language starts with ‘ab’.

def stateX(n):
  if(len(n)==0):
    print("string not accepted")
  else:
    if (n[0]=='a'):
      stateY(n[1:])
    elif (n[0]=='b'):
      print("string not accepted")
      
def stateY(n):
  if(len(n)==0):
    print("string not accepted")
  else:
    if (n[0]=='a'):
      print("string not accepted")
    elif (n[0]=='b'):
      stateZ(n[1:])

def stateZ(n):
  if(len(n)==0):
    print("string accepted")
  else:
    if (n[0]=='a'):
      stateZ(n[1:])
    elif (n[0]=='b'):
      stateZ(n[1:])

#driver code
n=input()
stateX(n)
