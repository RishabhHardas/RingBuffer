#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_LENGTH	256

typedef struct {
	char buffer[BUFFER_LENGTH];
	int head;
	int tail;
	int count;
}ring_buffer;


void ring_buffer_init(ring_buffer *rbuff);
uint8_t ring_buffer_empty(ring_buffer *rbuff);
uint8_t ring_buffer_full(ring_buffer *rbuff);
int ring_buffer_get(ring_buffer *rbuff);
void ring_buffer_put(ring_buffer *rbuff, const unsigned char ch);
uint8_t ring_buffer_flush(ring_buffer *rbuf, uint8_t clear_buffer);
void ring_buffer_print(ring_buffer *rbuff);


#endif
