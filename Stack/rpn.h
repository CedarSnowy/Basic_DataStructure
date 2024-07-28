#include "stack.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define N_OPTR 9 //运算符总数
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //运算符集合
//加、减、乘、除、乘方、阶乘、左括号、右括号、起始符与终止符

const char pri[N_OPTR][N_OPTR] = { //运算符优先等级 [栈顶] [当前]
   /*              |-------------------- 当 前 运 算 符 --------------------| */
   /*              +      -      *      /      ^      !      (      )      \0 */
   /* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
   /* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
   /* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
   /* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
   /* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
   /* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
   /* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
   /* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
   /* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};

Operator optr2rank ( char op ) { //由运算符转译出编号
   switch ( op ) {
      case '+' : return ADD; //加
      case '-' : return SUB; //减
      case '*' : return MUL; //乘
      case '/' : return DIV; //除
      case '^' : return POW; //乘方
      case '!' : return FAC; //阶乘
      case '(' : return L_P; //左括号
      case ')' : return R_P; //右括号
      case '\0': return EOE; //起始符与终止符
      default  : exit ( -1 ); //未知运算符
   }
}

char priority ( char op1, char op2 ) //比较两个运算符之间的优先级
{ return pri[optr2rank ( op1 ) ][optr2rank ( op2 ) ]; }

void readNumber ( char*& p, Stack<double>& stk ) { //将起始于p的子串解析为数值，并存入操作数栈
   stk.push ( ( double ) ( *p - '0' ) ); //当前数位对应的数值进栈
   while ( isdigit ( * ( ++p ) ) ) //若有后续数字（多位整数），则
      stk.push ( stk.pop() * 10 + ( *p - '0' ) ); //追加之（可能上溢）
   if ( '.' == *p ) { //若还有小数部分
      double fraction = 1; //则
      while ( isdigit ( * ( ++p ) ) ) //逐位
         stk.push ( stk.pop() + ( *p - '0' ) * ( fraction /= 10 ) ); //加入（可能下溢）
   }
}

void append ( char* rpn, double opnd ) { //将操作数接至RPN末尾
   char buf[64];
   if ( ( int ) opnd < opnd ) sprintf ( buf, "%6.2f \0", opnd ); //浮点格式，或
   else                       sprintf ( buf, "%d \0", ( int ) opnd ); //整数格式
   strcat ( rpn, buf ); //RPN加长
}

void append ( char* rpn, char optr ) { //将运算符接至RPN末尾
   int n = strlen ( rpn ); //RPN当前长度（以'\0'结尾，长度n + 1）
   sprintf ( rpn + n, "%c \0", optr ); //接入指定的运算符
}

double calcu ( double a, char op, double b ) { //执行二元运算
   switch ( op ) {
      case '+' : return a + b;
      case '-' : return a - b;
      case '*' : return a * b;
      case '/' : if ( 0==b ) exit ( -1 ); return a/b; //注意：如此判浮点数为零可能不安全
      case '^' : return pow ( a, b );
      default  : exit ( -1 );
   }
}

__int64 facI ( int n ) { __int64 f = 1; while ( n > 1 ) f *= n--; return f; } //阶乘运算（迭代版）

double calcu ( char op, double b ) { //执行一元运算
   switch ( op ) {
      case '!' : return ( double ) facI ( ( int ) b ); //目前仅有阶乘，可照此方式添加
      default  : exit ( -1 );
   }
}



double evalute(char* S,char* RPN)
{
    Stack<double> opnd; Stack<char> optr;
    char *expr = S;
    optr.push('\0');
    while(!optr.empty())
    {
        if(isdigit(*S))
        {
            readNumber(S, opnd);
            append(RPN, opnd.top());
        }
        else
        {
            switch (priority(optr.top(),*S))
            {
            case '<':
                optr.push(*S);
                S++;
                break;
            case '=':
                optr.pop();
                S++;
                break;
            case '>':
                char opt = optr.pop();
                append(RPN, opt);
                if('!' == opt)
                {
                    double opnd1 = opnd.pop();
                    opnd.push((opt, opnd1));
                }
                else
                {
                    double opnd2 = opnd.pop();
                    double opnd1 = opnd.pop();
                    opnd.push(calcu(opnd1, opt, opnd2));
                }
                break;
            }
        }
    }
    return opnd.pop();
}