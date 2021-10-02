# Question Link: https://leetcode.com/problems/valid-parentheses/
'''
Description:

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
'''

def isValid(self, s: str) -> bool:
        stack = []
        match = {"(" : ")", 
                 "[" : "]", 
                 "{" : "}" }
        
        for i in s:
            if stack == []:
                stack.append(i)
                
            else:
                if i == match.get(stack[-1]) :
                    stack.pop()
                else:
                    stack.append(i)
                    
        if stack == []:
            return True
        return False
