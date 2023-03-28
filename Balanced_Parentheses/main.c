#include <stdio.h>
#include <stdlib.h>
#include "Balanced_Parentheses.h"
  int main() {

    int8_t result;

    printf("Test Case 1: {(2+3)}\n");
    uint8_t *expression= "{(3+2)}";
    result = isBalancedParanthethes(expression);
    if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 2 {((2+3)}\n");
     expression= "{((2+3)}";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 3 [(2+3)]\n");
     expression= "[(2+3)]";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 4 {(2+3)/((3+3)*(15-10))}\n");
     expression= "{(2+3)/((3+3)*(15-10))}";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 5 (2+3)/((3+3)*(15-10))\n");
     expression= "(2+3)/((3+3)*(15-10))";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 6 {{2+3)/((3+3)*(15-10)))\n");
     expression= "{{2+3)/((3+3)*(15-10)))";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 7 {(2+3(/((3+3)*(15-10))}\n");
     expression= "{(2+3(/((3+3)*(15-10))}";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 8 {(2+3)/((3+3(*)15-10))}\n");
     expression= "[(2+3)]";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 9 })2+3)/((3+3)*(15-10))}\n");
     expression= "})2+3)/((3+3)*(15-10))}";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");


    printf("Test Case 10 {(2+3)/(<3+3>*(15-10))}\n");
     expression= "{(2+3)/(<3+3>*(15-10))}";
    result = isBalancedParanthethes(expression);
        if (result == -2) {
            printf("Error: Expression contains neither of parantheses\n");
        } else if (result == -1) {
            printf("Error: Expression contains unbalanced parantheses\n");
        } else {
            printf("Success: Expression contains balanced parantheses\n");
        }
        printf("\n");





  }
