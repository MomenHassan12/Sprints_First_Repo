#include"Stack.h"
/* Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t *stack)
{

  for (int i = 0; i < STACK_SIZE; i++) {
        stack->elements[i] = 0;
    }
    stack->top = -1;
}
/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t *stack, uint8_t data)
{
    if (isFull(stack)) {
        return -1;
    }
    stack->elements[++stack->top] = data;
    return 0;
}
/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t *stack, uint8_t *data)
{
        if (isEmpty(stack)) {
        return -2;
    }
    *data = stack->elements[stack->top--];
    return 0;
}
/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t printStack(ST_stack_t *stack)
{
      if (isEmpty(stack)) {
        return -2;
    }
    if (isFull(stack)) {
        return -1;
    }
    printf("Stack contents:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->elements[i]);
    }
    return 0;
}

/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
        if (isEmpty(stack)) {
        return -2;
    }
    *topData = stack->elements[stack->top];
    return 0;
}

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t *stack)
{
    if (stack->top == STACK_SIZE - 1) {
        return -1;
    } else {
        return 0;
    }
}
/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t *stack)
{
        if (stack->top == -1) {
        return -2;
    } else {
        return 0;
    }
}

