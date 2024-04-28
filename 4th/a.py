#Justin Barrett 
#1001924415

import os

def spread(noof):
    string = ""
    for index in range(0,noof):
        string += "\t"
    return string

def readTokens(recv):
    noof = 0
    output = ""
    output += str(noof) + "\t"
    flagslash = False
    flagquote = False
    flagLongComment = False
    flagShortComment = False

    for index in range(0, len(recv)):

        output += recv[index]

        if recv[index] == "{" and flagslash == False and flagquote == False and flagShortComment == False and flagLongComment == False: 
            noof+=1
        
        elif recv[index] == "}" and flagslash == False and flagquote == False and flagShortComment == False and flagLongComment == False: 
            noof-=1
            if noof <= -1: return "(unexpected character \'}\')"
        
        # handles quotes
        elif recv[index] == "\"" and flagslash == False and flagShortComment == False and flagLongComment == False:
            flagquote = not flagquote
        
        # handles comments
        elif recv[index] == "/" and flagquote == False and flagShortComment == False and flagLongComment == False:
            if index+1 < len(recv) and recv[index+1] == "/":
                flagShortComment = True
            elif index+1 < len(recv) and recv[index+1] == "*":
                flagLongComment = True
                
        # handles long comments
        elif recv[index] == "*" and flagquote == False:
            if index+1 < len(recv) and recv[index+1] == "/":
                flagLongComment = False
        
        #handles \ character
        elif recv[index] == "\\": 
            flagslash = not flagslash
        
        #handles new lines
        elif recv[index] == "\n":
            flagShortComment = False
            output += str(noof) + "\t"

        else:
            flagslash = False
    return output


f = open("input.txt" , 'r')
tokens = f.read()
print(readTokens(tokens))

