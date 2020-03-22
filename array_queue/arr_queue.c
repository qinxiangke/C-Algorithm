/*************************************************************************
 > File Name: arr_queue.c
 > Author:  qinxk
 > Mail:    798469745@qq.com
 > Time:    20-03-22
 > Desc:    
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "./arr_queue.h"

/*
return : -1, errors; 1, queue is empty; 0 queue isn't empty
*/
int queue_empty(t_array_queue *pqueue)
{
	int ret = 0;
	if (NULL != pqueue)
	{
		ret = (pqueue->head == pqueue->tail) ? 1 : 0;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

/*
return : -1, errors; 1, queue is full; 0 queue isn't full
*/
int queue_full(t_array_queue *pqueue)
{
	int ret = 0;
	if (NULL != pqueue)
	{
		ret = (pqueue->head == 0 && pqueue->tail == SIZE_QUEUE) ? 1 : 0;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void queue_init(t_array_queue *pqueue)
{
	int i = 0;
	pqueue->head = pqueue->tail = 0;
	pqueue->num = 0;
	for(i = 0; i < SIZE_QUEUE; i++)
	{
		pqueue->array[i] = 0;
	}
}

/*
return: -1, errors; 0, the queue is empty; 1; success
*/
int queue_dump(t_array_queue *pqueue)
{
	int ret = 0;
	if(NULL == pqueue)
	{
		ret = -1;
	}
	else if (queue_empty(pqueue) > 0)
	{
		ret = 0;
	}
	else
	{
		int i = 0;
		printf("\n************start****************\n");
		for(i = 0; i < pqueue->num; i++)
		{
			printf("%d,", pqueue->array[pqueue->head + i]);
		}
		printf("\n************end******************\n");
		ret = 1;
	}
	return ret;
}

/*
* return : -1,errors; 0, queue is empty; 1, success
*/
int queue_out(t_array_queue *pqueue, int *pdata)
{
	int ret = 0;
	if((NULL != pqueue) && (NULL != pdata))
	{
		if(queue_empty(pqueue) > 0)
		{
			ret = 0;
		}
		else
		{
			*pdata = pqueue->array[pqueue->head];
			pqueue->head++;
			pqueue->num--;
			ret = 1;
		}
	}
	else
	{
		ret = -1;
	}
	return ret;
}

/*
return: -1,errors; 0, queue is full, 1:success
*/
int queue_in(t_array_queue *pqueue, int data)
{
	int ret = 0;
	if (NULL != pqueue)
	{
		if(queue_full(pqueue) > 0)
		{
			ret = 0;
		}
		else
		{
			int i = 0;
			/*no space in the queue's tail, 
				but there're space in the queue's head, move the date*/
			if(pqueue->tail == SIZE_QUEUE)
			{
				for(i = pqueue->head; i < pqueue->tail; ++i)
				{
					pqueue->array[i - pqueue->head] = pqueue->array[i];
				}
				/*updata the head and tail*/
				pqueue->tail -= pqueue->head;
				pqueue->head=0;
			}
			pqueue->array[pqueue->tail] = data;
			pqueue->tail++;
			pqueue->num++;
			ret = 1;
		}
	}
	else
	{
		ret = -1;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	t_array_queue hTime;
	int readData = 0;
	int writeData = 0;
  queue_init(&hTime);
	if ((ret = queue_empty(&hTime)) <= 0)
	{
		printf("errors!! or the queue isn't empty: ret=%d\n",ret);
	}
	else 
	{
    while('\n' != (writeData = getchar()))
		{
		  ret = queue_in(&hTime,writeData);
		}

		if (ret > 0)
		{
		}
		else
		{
			printf("queue in errors!! or the queue is full: ret=%d\n", ret);
			ret = queue_out(&hTime,&readData);
			if(ret > 0)
			{
				printf("readData=%d\n", readData);
			}
			else
			{
				printf("queue out errors!! or the queue is empty: ret=%d\n", ret);
			}
			ret = queue_in(&hTime, 88);
			if (ret > 0)
			{
				if ((ret = queue_dump(&hTime)) <= 0)
				{
					printf("queue dump errors!! or the queue is empty: ret=%d\n", ret);
				}
				else
				{
		
				}
			}
			else
			{
				printf("queue in errors!! or the queue is full: ret=%d\n", ret);
			}
		}		
	}
	return ret;
}
