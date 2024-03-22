import os


def readTokens(recv):
    storedValues = []
    tempvalue = 0;

    for index in range(0,len(recv)):
        #if a value is encountered...
        if recv[index] != '+' and recv[index] != '-' and recv[index] != '*' and recv[index] != '/': 
            storedValues.append(int(recv[index]))

        #if a function is encountered...
        elif type(recv[index]) == type("+"):
            tempvalue = storedValues[len(storedValues)-1]
            storedValues.pop(len(storedValues)-1)
            #apply the functionality
            if recv[index] == "+": storedValues[len(storedValues)-1] += tempvalue
            elif recv[index] == "-": storedValues[len(storedValues)-1] -= tempvalue
            elif recv[index] == "*": storedValues[len(storedValues)-1] *= tempvalue
            elif recv[index] == "/": storedValues[len(storedValues)-1] /= tempvalue
            elif recv[index] == "%": storedValues[len(storedValues)-1] %= tempvalue
    return storedValues

f = open("input_RPN.txt" , 'r')
tokens = [0]

while len(tokens) != 0:
    tokens = f.readline().split()
    print(readTokens(tokens))

