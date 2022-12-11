#include "main.h"

/**
 * q_is_empty - helper func checks if a queue is empty
 * @queue: ptr to the queue struct
 * Return: 1 if full, 0 else
 */
int q_is_empty(queue_t *queue)
{
	if (queue->front == -1)
		return (1);
	return (0);
}

/**
 * q_is_full - checks if a queue is full
 * @queue: ptr to the queue struct
 * @return 1 if full, 0 else
 * Return: 1 if full, 0 else
 */
int q_is_full(queue_t *queue)
{
	if (queue->rear == (QUEUE_SIZE - 1))
		return (1);
	return (0);
}

/**
 * Enqueue - Enqueue an id_name_t item
 * @queue: ptr to the queue struct
 * @id: string ptr
 * @name: string ptr
 * @return id_name_t or NULL
 * Return: id_name_t
 */
id_name_t *Enqueue(queue_t *queue, char *id, char *name)
{
	id_name_t *node;
	int rear;

	if (!queue || !id || !name || q_is_full(queue))
		return (NULL);
	/* alloc node */
	node = malloc(sizeof(id_name_t));
	if (!node)
		return (NULL);
	/* node attribs */
	node->id = id, node->name = name;
	/* enqueue */
	rear = queue->rear + 1;
	queue->head[rear] = node;
	if (q_is_empty(queue))
		queue->front = queue->front + 1;
	return (node);
}

/**
 * Dequeue - Dequeue an id_name_t item
 * @queue: ptr to the queue struct
 * @return id_name_t or NULL
 * Return: id_name_t or NULL
 */
id_name_t *Dequeue(queue_t *queue)
{
	id_name_t *node;
	int front;

	if (!queue || q_is_empty(queue))
		return (NULL);
	front = queue->front;
	/* grab front item */
	node = queue->head[front];
	if (!node)
		return (NULL);
	/* push queue fron index */
	++front;
	if (front != queue->rear)
		queue->front = front;
	else
		queue->front = -1, queue->rear = -1;
	return (node);
}

/**
 * Q_Peek - Peek an id_name_t item
 * @queue: ptr to the queue struct
 * @return id_name_t or NULL
 * Return: id_name_t or NULL
 */
id_name_t *Q_Peek(queue_t *queue)
{
	id_name_t *node;
	int front;

	if (!queue || q_is_empty(queue))
		return (NULL);
	/* grab front item */
	node = queue->head[front];
	if (!node)
		return (NULL);
	return (node);
}

/**
 * Q_Free - free's up a malloc'd queue
 * @queue: ptr to the queue struct
 * @return void
 * Return: void
 */
void Q_Free(queue_t *queue)
{
	id_name_t *node;

	while (!q_is_empty(queue))
	{
		node = Dequeue(queue);
		free(node);
	}

	free(queue->head);

}
