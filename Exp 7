#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    int i, V1, V2, result;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit((unsigned char)exp[i])) {
            push(exp[i] - '0');
        } else {
            if (top < 1) {
                printf("Invalid expression!\n");
                return 1;
            }

            V2 = pop();
            V1 = pop();

            switch (exp[i]) {
                case '+': result = V1 + V2; break;
                case '-': result = V1 - V2; break;
                case '*': result = V1 * V2; break;
                case '/':
                    if (V2 == 0) {
                        printf("Division by zero!\n");
                        return 1;
                    }
                    result = V1 / V2;
                    break;
                default:
                    printf("Invalid operator!\n");
                    return 1;
            }
            push(result);
        }
    }

    if (top != 0) {
        printf("Invalid expression!\n");
        return 1;
    }

    printf("Result = %d\n", pop());
    return 0;
}
