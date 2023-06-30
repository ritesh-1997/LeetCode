def isValidParenthesis(expression):
    stack = []

    for i in expression:
        if i in ['{','[','(']:
            stack.append(i)
        else:
            if not stack:
                return False
            curr = stack.pop()
            if curr=='[' and i is not ']':
                return False
            if curr=='{' and i is not '}':
                return False
            if curr=='(' and i is not ')':
                return False
    if not stack:
        return True
    else:
        return False




# Main Code

t = int(input().strip())

for i in range(t):
    str = input().strip()
    ans = isValidParenthesis(str)

    if ans:
        print("Balanced")
        
    else:
        print("Not Balanced")
