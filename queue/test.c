#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void *node_data_init(void);
void node_data_destroy(void *data);

struct node_data {
	char name[20];
	char sex;
	int age;
};


int
main(void)
{
	printf("Testing queue...\n");

	struct queue *queue;
	struct queue_node *node;

	queue = queue_init(10);	

	int i;
	for (i = 0; i < 5; ++i) {
		node = queue_node_init((void *) i, NULL);
		queue_enqueue(queue, node);
	}
	for (i = 0; i < 5; ++i) {
		node = queue_node_init(NULL, &node_data_init);
		queue_enqueue(queue, node);
	}

	for (i = 0; i < 5; ++i) {
		node = queue_dequeue(queue);
		printf(">> %d\n", (int) node->data);
		queue_node_destroy(node, NULL);
	}
	for (i = 0; i < 5; ++i) {
		node = queue_dequeue(queue);
		struct node_data *data = (struct node_data *) node->data;
		printf(">> %s, %c, %d\n", data->name, data->sex, data->age);
		queue_node_destroy(node, &node_data_destroy);
	};

	queue_destroy(queue, NULL);

	return 0;
}

void *
node_data_init(void)
{
	struct node_data *data = (struct node_data *) malloc(sizeof(struct node_data));
	
	strcpy(data->name, "nobody");
	data->sex = 'M';
	data->age = 20;

	return (void *) data;	
}

void
node_data_destroy(void *data)
{
	free((struct node_data *) data);
}
