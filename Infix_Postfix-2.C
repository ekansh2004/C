#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char stk[10];
int top = -1;
char pfix[20];
int pfixIndex;

int evalStk[20];
int topES = -1;

void push(char b) {
    if (top < 10) {
        top++;
        stk[top] = b;
    } else {
        printf("\nStack overflow");
    }
}

char pop() {
    char pop_val;
    if (top == -1) {
        printf("\nStack underflow");
    } else {
        pop_val = stk[top];
        top--;
    }

    return pop_val;
}

int prio(char opr) {
    if (opr == '+' || opr == '-') {
        return 1;
    } else if (opr == '*' || opr == '/') {
        return 2;
    } else if (opr == '^') {
        return 3;
    } else {
        return 0;
    }
}

void oprFunc(char opr) {
    int prioNew = prio(opr);
    int prioStk;
    char popped;

    if (top == -1 || stk[top] == '(') {
        push(opr);
    } else {
        prioStk = prio(stk[top]);
        if (prioNew > prioStk) {
            push(opr);
        } else {
            popped = pop();
            push(opr);
            pfix[pfixIndex] = popped;
            pfixIndex++;
        }
    }
}

void pushES(int b) {
    if (topES < 20) {
        topES++;
        evalStk[topES] = b;
    } else {
        printf("\nStack overflow");
    }
}


int popES() {
    int pop_val;
    if (topES == -1) {
        printf("\nStack underflow");
    } else {
        pop_val = evalStk[topES];
        topES--;
    }

    return pop_val;
}

void postfix_eval(){
    int i,t,n1,n2;
    char c;
    i = 0;

    while(pfix[i] != '\0'){
        if(pfix[i] >= '0' && pfix[i] <= '9'){
            c = pfix[i];
            t = atoi(&c);
            pushES(t);
        }
        else{
            n2 = popES();
            n1 = popES();

            switch(pfix[i]){
            case '+':
                pushES(n1 + n2);
                break;
            case '-':
                pushES(n1 - n2);
                break;
            case '*':
                pushES(n1 * n2);
                break;
            case '/':
                pushES(n1 / n2);
                break;
            case '^':
                pushES(pow(n1, n2));
                break;
            default:
                return;
            }
        }
        i++;
    }
    t = popES();
    printf("\nResult of postfix expression = %d",t);
}

int conv(){
    char inp[20];
    int i = 0;
    char popped;

    printf("\nEnter an expression = ");
    scanf("%s", inp);

    while (inp[i] != '\0') {
        if ((inp[i] == '+') ||
            (inp[i] == '-') ||
            (inp[i] == '*') ||
            (inp[i] == '/') ||
            (inp[i] == '^')) {
            oprFunc(inp[i]);
        } else if (inp[i] == '(') {
            push(inp[i]);
        } else if (inp[i] == ')') {
            while (top != -1 && stk[top] != '(') {
                pfix[pfixIndex] = pop();
                pfixIndex++;
            }
            if (top != -1 && stk[top] == '(') {
                pop();
            } else {
                printf("\nUnbalanced brackets.");
                return 0;
            }
        } else {
            pfix[pfixIndex] = inp[i];
            pfixIndex++;
        }
        i++;
    }

    while (top != -1) {
        pfix[pfixIndex] = pop();
        pfixIndex++;
    }

    printf("\nPostfix expression is = ");
    for (i = 0; i < pfixIndex; i++) {
        printf("%c", pfix[i]);
    }
}

int main() {
    int c = conv();
    if(c == 0 || c == 1){
        return 0;
    }
    postfix_eval();

    return 0;
}
