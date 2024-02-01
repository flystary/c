#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
} CirularQueue;


void InitQueue(CirularQueue *Q) {
    Q->front = Q->rear = 0;
}

int IsEmpty(CirularQueue *Q) {
    return Q->front == Q->rear;
}

int IsFull(CirularQueue *Q) {
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

int EnQueue(CirularQueue *Q, int x) {
    if (IsFull(Q)) {
        return 0;
    } else {
        Q->data[Q->rear] = x;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}

int DeQueue(CirularQueue *Q, int *x) {
    if (IsEmpty(Q)) {
        return 0;
    } else {
        *x = Q->data[Q->front];
        Q->front = (Q->front +1) % MAXSIZE;
        return 1;
    }
}

int GetFront(CirularQueue *Q, int *x) {
    if (IsEmpty(Q)) {
        return 0;
    } else {
        *x = Q->data[Q->front];
        return 1;
    }
}

int main() {
    CirularQueue Q;
    int x, y;

    InitQueue(&Q);

    int i;
    for (i = 1; i <= 15; i++) {
        if (IsFull(&Q)) {
            printf("队列已满,%d 无法入队\n", i);
            continue;   
        }
        printf("入队元素 %d\n", i);
        EnQueue(&Q, i);
    }

    printf("\n");
    if (GetFront(&Q, &x)) {
        printf("队头元素 %d\n", x);
    } else {
        printf("队列为空, 无法获取队头元素\n");   
    }

    printf("\n");
    while (!IsEmpty(&Q)) {
        if (DeQueue(&Q, &y)) {
            printf("出队元素是 %d\n", y);
        } else {
            printf("队列为空, 无法进行出队操作\n");
        }
    }

    printf("\n");
    if (IsEmpty(&Q)) {
        printf("队列为空\n");
    } else {
        printf("队列不为空\n");
    }
 
    return 0;
}
