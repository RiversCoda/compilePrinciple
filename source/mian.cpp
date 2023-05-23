#include <bits/stdc++.h>

using namespace std;
string prog;
int pos = 0;
int len;

// 1 means reserved word
// 2 means normal word
// 3 means constant
// 4 means operator
// 5 means delimiter
// 6 means wrong word
// 7 means real number
// 8 means file

unordered_set<string> reservedWords = {
    "if", "int", "for", "while", "do", "return", "break", "continue",
    "else", "switch", "case", "default", "char", "double", "float", "long",
    "short", "void", "struct", "typedef", "static", "register", "auto",
    "const", "signed", "unsigned", "sizeof"};

bool isReservedWord()
{

    int rtn = 0;
    int num = 0;
    // 取当前位置之后的一个单词，直到遇到空格、标点符号或字符串结束为止
    string word;
    while (pos < prog.size() && isalpha(prog[pos]))
    {
        word += prog[pos++];
        num ++;
        if (reservedWords.count(word) > 0) // 每增加一位都判断， 使其支持错误单词截取正确部分
        {
            rtn = 1;
        }
    }
    if ( rtn == 0 )
    {
        pos -= num;
    }
    if(rtn == 1)
    {
        cout << "(1, \"" << word << "\")" << endl;
    }

    return rtn;
}

bool isNormalWord()
{
    int rtn = 0;
    string word;
    if (!isalpha(prog[pos]))
    {
        return false;
    }
    while (pos < prog.size() && isalpha(prog[pos]) || isdigit(prog[pos]) || prog[pos] == '_')
    {
        word += prog[pos++];
    }
    if (word.length() > 0)
    {
        cout << "(2, \"" << word << "\")" << endl;
        rtn = 1;
    }
    return rtn;
}

bool isOperator()
{
    if (prog[pos] == '+' || prog[pos] == '-')
    {
        if(!isdigit(prog[pos+1]))
        {
            cout << "(4, \"" << prog[pos] << "\")" << endl;
            pos++;
            return true;
        }
        else
        {
            return false;//+或-后面有数字的情况下，前往实数识别
        }
    }
    if (prog[pos] == '*' || prog[pos] == '/' || prog[pos] == '%' || prog[pos] == '=' || prog[pos] == '&' || prog[pos] == '|')
    {
        cout << "(4, \"" << prog[pos] << "\")" << endl;
        pos++;
        return true;
    }
    if (prog[pos] == '<' || prog[pos] == '>' || prog[pos] == '!')
    {
        cout << "(4, \"" << prog[pos] << "\")" << endl;
        if (prog[pos + 1] == '=')
        {
            pos++;
        }
        pos++;
        return true;
    }
    else
        return false;
}

bool isDelimiter()
{
    char x = prog[pos];
    if (x == ',' || x == ';' || x == '(' || x == ')' || x == '[' || x == ']' || x == '{' || x == '}')
    {
        pos++;
        cout << "(5, \"" << x << "\")" << endl;
        return true;
    }
    return false;
}

bool isRealNumber() //( +|-|ε ) dd*(.dd* | ε)( e ( +|-|ε ) dd*|ε)
{
    int rtn = 0;
    string word;
    if (prog[pos] == '+' || prog[pos] == '-')
    {
        word += prog[pos++];
    }
    while (pos < prog.size() && isdigit(prog[pos]))
    {
        word += prog[pos++];
    }
    if (prog[pos] == '.')
    {
        word += prog[pos++];
        while (pos < prog.size() && isdigit(prog[pos]))
        {
            word += prog[pos++];
        }
    }
    if (prog[pos] == 'e' || prog[pos] == 'E')
    {
        word += prog[pos++];
        if (prog[pos] == '+' || prog[pos] == '-')
        {
            word += prog[pos++];
        }
        while (pos < prog.size() && isdigit(prog[pos]))
        {
            word += prog[pos++];
        }
    }
    if (word.length() > 0)
    {
        cout << "(7, \"" << word << "\")" << endl;
        rtn = 1;
    }
    return rtn;
}

// 识别带路径文件
bool isFile()
{
    int num = 0;
    if( prog[pos] == '/' && !isalpha(prog[pos+1]))
    {
        return false;
    }
    if (prog[pos] == '/' || prog[pos] == '\\')
    {
        num++;
        pos++;
        while (pos < prog.size() && isalpha(prog[pos]) || isdigit(prog[pos]) || prog[pos] == '.' || prog[pos] == '/' || prog[pos] == '\\')
        {
            num++;
            pos++;
        }
        if (num > 1)
        {
            cout << "(8, \"" << prog.substr(pos - num, num) << "\")" << endl;
        }
        return true;
    }
}

int main()
{
    freopen("test4.txt", "r", stdin);
    freopen("result4.txt", "w", stdout);
    while(cin >> prog)
    {
        pos = 0;
        len = prog.size();
        while (pos < len)
        {
            if (isFile())
            {

            }
            else if (isDelimiter())
            {

            }
            else if (isOperator())
            {

            }
            else if (isReservedWord())
            {

            }
            else if (isNormalWord())
            {

            }
            else if (isRealNumber())
            {

            }
            else
            {
                cout <<  "(6, \"" << prog[pos] << "\")" << endl;
                pos++;
            }
        }
    }
}
