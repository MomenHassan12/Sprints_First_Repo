#include"Balanced_Parentheses.h"

int8_t isBalancedParanthethes(uint8_t *expression) {
    // create a stack to hold opening parentheses

    ST_stack_t stack;
    stack.top = -1;
    uint8_t popped_char;

    // iterate over the expression string
    for (uint8_t i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '{' || expression[i] == '(') {
            // if we find an opening parenthesis, push it onto the stack
            push(&stack, expression[i]);
        } else if (expression[i] == '}' || expression[i] == ')') {
            // if we find a closing parenthesis, check if it matches the top of the stack
            if (stack.top == -1) {
                // if the stack is empty, the parentheses are not balanced
                return -1;
            }
             pop(&stack,&popped_char );
            if ((expression[i] == '}' && popped_char != '{') ||
                (expression[i] == ')' && popped_char != '(')) {
                // if the closing parenthesis does not match the top of the stack, the parentheses are not balanced
                return -1;
            }
        }
    }

    // check if there are any opening parentheses left in the stack
    if (stack.top != -1) {
        // if there are, the parentheses are not balanced
        return -1;
    } else if (popped_char == '\0') {
        // if there are no parentheses in the expression, return -2
        return -2;
    }

    // if we reach here, the parentheses are balanced
    return 0;
}

