/*************************************************************************
 > File Name: list_queue.c
 > Author:  qinxk
 > Mail:    798469745@qq.com
 > Time:    20-03-22
 > Desc:    
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list_queue.h"

t_list_queue *list_queue_create()
{
	t_list_queue *queue = NULL;
	queue = (t_list_queue *)malloc(sizeof(t_list_queue));
	if (NULL != queue)
	{
		queue->num = 0;
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		perror("malloc errors!\n");
	}
	return queue;
}

void list_queue_destroy(t_list_queue *queue)
{
	if(NULL == queue || LIST_QUEUE_EMPTY(queue))
	{
		return;
	}
	int data = 0;
	while(!LIST_QUEUE_EMPTY(queue))
	{
		(void)list_queue_out(queue,&data);
	}
	free(queue);
}

int list_queue_in(t_list_queue *queue, int data)
{
	int ret = 0;
	t_node_queue *pnode = NULL;
	pnode = (t_node_queue*)malloc(sizeof(t_node_queue));
	if(NULL != pnode)
	{
		pnode->data = data;
		pnode->next = NULL; 
		if (queue->head == NULL)
		{
			queue->head = pnode;
		}
		else
		{
			queue->tail->next = pnode;
		}
		queue->tail = pnode;
		queue->num++;
		ret = 1;
	}
	else
	{
		perror("malloc errors!\n");
	}
	return ret;
}

int list_queue_out(t_list_queue *queue, int *data)
{
	int ret = 0;
	t_node_queue *ptmp = NULL;
	if(NULL != queue && NULL != data)
	{
		if(LIST_QUEUE_EMPTY(queue))
		{
			ret = 0;
		}
		else
		{
			*data = queue->head->data;
			ptmp = queue->head;
			queue->head=queue->head->next;
			queue->num--;
			if(queue->head == NULL)
			{
				queue->tail = NULL;
			}
			free(ptmp);
			ret = 1;
		}
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void list_queue_dump(t_list_queue *queue)
{
	if(NULL == queue && LIST_QUEUE_EMPTY(queue))
	{
		return;
	}
	t_node_queue *ptmp = queue->head;
	printf("\r\n----dump queue num = %d--------",queue->num);
	while(NULL!=ptmp)
	{
		printf("%d,", ptmp->data);
		ptmp=ptmp->next;
	}
	printf("\r\n---------------------------------\r\n");
	return;
}

int main(int argc, char *argv[])
{
	int i = 0;
	int data = 0;
	int ret = 0;
	t_list_queue *queue;

	queue = list_queue_create();
	if (queue == NULL)
	{
		printf("\r\nlist queue create falied..");
		return 0;
	}

	for (i = 0; i < 5; i++)
	{
		(void)list_queue_in(queue,i);
	}
	list_queue_dump(queue);

  ret = list_queue_out(queue,&data);
	if(ret < 1)
	{
		printf("\r\nlist queue dequeue %d falied.",data);
	}
	printf("\r\nlist queue dequeue %d",data);
	list_queue_dump(queue);


  ret = list_queue_out(queue,&data);
	if(ret < 1)
	{
		printf("\r\nlist queue dequeue %d failed.",data);
	}
  printf("\r\nlist queue dequeue %d",data);
	list_queue_dump(queue);

	printf("\r\nlist queue enqueue %d",data);
	(void)list_queue_in(queue,data);
	list_queue_dump(queue);

  list_queue_destroy(queue);
	return 0;
}
