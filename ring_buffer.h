#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <stdint.h>
#include <string.h>
#include <stdio.h>

//Overflow handling
#define OVERFLOW_IGNORE_LATEST		1
#define OVERFLOW_OVERWRITE_OLDEST	2

#define BUFFER_DATA_TYPE	char

//#define HANDLE_OVERFLOW	OVERFLOW_IGNORE_LATEST

#define BUFFER_LENGTH	7

typedef struct {
	BUFFER_DATA_TYPE buffer[BUFFER_LENGTH];
	int head;
	int tail;
	int count;
	uint8_t overflow_handler;
}ring_buffer;


void ring_buffer_init(ring_buffer *rbuff, uint8_t overflow_handler);
uint8_t ring_buffer_empty(ring_buffer *rbuff);
uint8_t ring_buffer_full(ring_buffer *rbuff);
BUFFER_DATA_TYPE ring_buffer_get(ring_buffer *rbuff);
void ring_buffer_put(ring_buffer *rbuff, const BUFFER_DATA_TYPE ch);
uint8_t ring_buffer_flush(ring_buffer *rbuf, uint8_t clear_buffer);
void ring_buffer_print(ring_buffer *rbuff);
void ring_buffer_change_overflow(ring_buffer *rbuff, uint8_t overflow_handler);


#endif
