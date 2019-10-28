#include <stdlib.h>
#include "queue.h"

struct queue *
queue_init(const unsigned int max_size)
{
	struct queue *queue = (struct queue *) malloc(sizeof(*queue));

	if (queue) {
		queue->max_size = max_size;
		queue->size = 0;
		queue->head = queue->tail = NULL;

		return queue;
	}
	return NULL;
}

void
queue_destroy(struct queue *queue, fn_node_data_destroy fn)
{
	struct queue_node *node = queue->head;
	struct queue_node **node_next = &node->next;

	while (node != NULL) {
		if (fn != NULL) {
			fn(node->data);
		}
		free(node);
		node = *node_next;
		node_next = &node->next;
	}
}

struct queue_node *
queue_node_init(void *data, fn_node_data_init fn)
{
	struct queue_node *node = (struct queue_node *) malloc(sizeof(*node));
	
	if (node) {
		if (fn != NULL) {
			node->data = fn();
		} else {
			node->data = data;
		}
		node->next = NULL;

		return node;
	}
	return NULL;
}

void
queue_node_destroy(struct queue_node *node, fn_node_data_destroy fn)
{
	if (fn != NULL) {
		fn(node->data);
	}
	free(node);
}

int
queue_enqueue(struct queue *queue, struct queue_node *node)
{
	if (queue->size == queue->max_size) {
		return -EQUEUEFULL;
	}
	if (queue->head == NULL && queue->tail == NULL) {
		queue->head = queue->tail = node;
	} else {
		queue->tail->next = node;
		queue->tail = node;
	}
	queue->size++;

	return 0;
}

struct queue_node *
queue_dequeue(struct queue *queue)
{
	struct queue_node *node;

	if (queue->size == 0) {
		return NULL;
	}
	node = queue->head;
	queue->head = queue->head->next;
	queue->size--;

	return node;
}
