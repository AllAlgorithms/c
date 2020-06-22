#ifndef QUEUE_H
#define QUEUE_H

#define EQUEUEFULL 1

typedef void *(*fn_node_data_init) (void);
typedef void (*fn_node_data_destroy) (void *data);

struct queue {
	unsigned int max_size;
	unsigned int size;
	struct queue_node *head;
	struct queue_node *tail;
};

struct queue_node {
	void *data;
	struct queue_node *next;
};

/*
 * Create a new queue object
 */
struct queue *queue_init(const unsigned int max_size); 

/*
 * Destroy an existing queue object
 * 
 * fn_node_data_destroy is a pointer to a function which is supposed to destroy the data (optional)
 */
void queue_destroy(struct queue *queue, fn_node_data_destroy fn);

/*
 * Create a new queue node
 * 
 * fn_node_data_init is a pointer to a function which is supposed to initialize the data and return
 * a pointer to it (optional)
 * If fn_node_data_init is emitted the node data is the data pointed to by the pointer data argument
 */
struct queue_node *queue_node_init(void *data, fn_node_data_init fn);

/*
 * Destroy a queue node
 */
void queue_node_destroy(struct queue_node *node, fn_node_data_destroy fn);

/*
 * Add queue node to queue
 */
int queue_enqueue(struct queue *queue, struct queue_node *node);

/*
 * Get next node from queue
 */
struct queue_node *queue_dequeue(struct queue *queue);

#endif /* QUEUE_H */
