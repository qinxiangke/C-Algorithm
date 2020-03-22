/*************************************************************************
 > File Name: list_queue.h
 > Author:  qinxk
 > Mail:    798469745@qq.com
 > Time:    20-03-22
 > Desc:    
 ************************************************************************/

#ifndef _LIST_QUEUE_H
#define _LIST_QUEUE_H

typedef struct node_queue{
	struct node_queue *next;
	int data;
}t_node_queue;

typedef struct _list_queue{
  unsigned int num; /**/
	t_node_queue *head;
	t_node_queue *tail;
}t_list_queue;

#define LIST_QUEUE_EMPTY(queue) ((queue->num)== 0)

int list_queue_out(t_list_queue *queue, int *data);
#endif
