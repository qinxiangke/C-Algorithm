/*************************************************************************
 > File Name: arr_queue.h
 > Author:  qinxk
 > Mail:    798469745@qq.com
 > Time:    20-03-22
 > Desc:    
 ************************************************************************/

#ifndef _ARR_QUEUE_H
#define _ARR_QUEUE_H

#define SIZE_QUEUE 16

typedef struct _t_array_queue{
    unsigned int head;  /*the head of the queue*/
    unsigned int tail;  /*the tail of the queue*/
    unsigned int array[SIZE_QUEUE];
		unsigned int num;
}t_array_queue;

#endif

