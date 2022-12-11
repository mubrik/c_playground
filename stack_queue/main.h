#include<stdio.h>
#include<stdlib.h>

/* stack ops */
#define STACK_SIZE 1024

/**
 * id_name_t - basic struct, holds a struct of string id name
 * @id: id
 * @name: name
 */
typedef struct id_name
{
	char *id;
	char *name;
} id_name_t;

/**
 * stk_t - Holds info about a stack
 * @top: top index of stack
 * @head: head ptr of stack
 */
typedef struct stk
{
	int top;
	id_name_t **head;
} stk_t;

int is_empty(int top);
int is_full(int top);
id_name_t *Peek(stk_t *stk);
id_name_t *Push(stk_t *stk, char *id, char *name);
id_name_t *Pop(stk_t *stk);
void Free(stk_t *stk);
int test_stack(void);

#define QUEUE_SIZE 1024

/**
 * queue_t - Holds info about a queue
 * @front: top index of queue
 * @rear: rear index of queue
 * @head: head ptr of queue
 */
typedef struct queue
{
	int front;
	int rear;
	id_name_t **head;
} queue_t;

int q_is_empty(queue_t *queue);
int q_is_full(queue_t *queue);
id_name_t *Enqueue(queue_t *queue, char *id, char *name);
id_name_t *Dequeue(queue_t *queue);
id_name_t *Q_Peek(queue_t *queue);
void Q_Free(queue_t *queue);
int test_queue(void);
