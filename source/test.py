prog = ""
pos = 0

def isDelimiter():
    global pos
    x = prog[pos]
    if x == ',' or x == ';' or x == '(' or x == ')' or x == '[' or x == ']' or x == '{' or x == '}':
        pos += 1
        return True
    return False

def isOperator():
    global pos
    if prog[pos] == '+' or prog[pos] == '-' or prog[pos] == '*' or prog[pos] == '/' or prog[pos] == '%' or prog[pos] == '=' or prog[pos] == '&' or prog[pos] == '|':
        pos += 1
        return True
    if prog[pos] == '<' or prog[pos] == '>' or prog[pos] == '!':
        if prog[pos + 1] == '=':
            pos += 1
        return True
    else:
        return False

def isReservedWord():
    # 匹配是否为if、int、for、while、do、return、break、continue、else、switch、case、default、char、double、float、long、short、void、struct、typedef、static、register、auto、const、signed、unsigned、sizeof、printf、scanf、main、include、define、NULL、FILE、EOF、stdin、stdout、stderr、getchar、putchar、gets、puts、fopen、fclose、fread、fwrite、fseek、ftell、malloc、calloc、realloc、free、exit、abs、fabs、sqrt、sin、cos、tan、exp、log、log10、pow、ceil、floor、strcmp、strcpy
    

def grammar():
    if isDelimiter():
        pass

len = 0

prog = input()
len = len(prog)
grammar()
