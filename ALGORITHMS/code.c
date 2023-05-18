#include <stdio.h>

#include <stdlib.h>

#define MAX 100



// define stack structure

struct stack {

    int top;

    int arr[MAX];

} s;



// initialize stack

void init() {

s.top = -1;

}



// check if stack is empty

int isEmpty() {

    return (s.top == -1);

}



// check if stack is full

int isFull() {

    return (s.top == MAX-1);

}



// push item onto the stack

void push(int item) {

    if (isFull()) {

printf("Stack Overflow\n");

exit(1);

    }

s.arr[++s.top] = item;

}



// pop item from the stack

int pop() {

    if (isEmpty()) {

printf("Stack Underflow\n");

exit(1);

    }

    return s.arr[s.top--];

}



// perform greedy algorithm

void greedy(int n, int coins[], int change) {

    int i, coin;

    int total = 0;



    for (i = 0; i< n; i++) {

        coin = coins[i];

        while (total + coin <= change) {

            push(coin);

            total += coin;

        }

    }



    // print result

printf("Coins used: ");

    while (!isEmpty()) {

printf("%d ", pop());

    }

}



int main() {

    int n, i, coins[MAX];

printf("Enter the number of coins: ");

scanf("%d", &n);

printf("Enter the values of coins: ");

    for (i = 0; i< n; i++) {

scanf("%d", &coins[i]);

    }

printf("Enter the amount to be changed: ");

    int change;

scanf("%d", &change);



    // initialize stack

init();



    // perform greedy algorithm

greedy(n, coins, change);



    return 0;

}
