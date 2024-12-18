#include<stdio.h>
#define MAX 5

struct circularQueue
{
  int front;
  int rear;
  int data[MAX];
};
typedef struct circularQueue CQ;

void enqueue(CQ *Q, int element)
{
  if (Q->front == (Q->rear + 1)%MAX)
  {
    printf("Queue is full\n");
  }
  else
  {
     Q->data[Q->rear] = element;
     Q->rear = (Q->rear+1)%MAX;
     printf("%d element was ENQUEUED.\n", element);
  }
}

int dequeue(CQ *Q)
{
  if(Q->front == Q->rear){
    printf("\nQueue is EMPTY\n");
    return -1;
  }
  else{
    int element = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX;
    return element;
  }
}

int main()
{
  int choice, element;
  CQ Q = {0,0};
  do
  {
    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.EXIT\n");
    printf("Choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
        printf("\nElement to be enqueued: ");
        scanf("%d", &element);
        enqueue(&Q, element);
        break;

      case 2:
        element = dequeue(&Q);
        if(element != -1)
        {
          printf("\n%d was dequeued\n",element);
        }
        break;
      case 3:
      printf("\nEXITING SCREEN...\n\n");
      default:
        break;
    }
  } while (choice != 3);
  return 0;

}