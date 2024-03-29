#include "ring_buffer.h"



void ring_buffer_init(ring_buffer *rbuff, uint8_t overflow_handler)
{
	rbuff->head = 0;
	rbuff->count = 0;
	rbuff->tail = 0;

	if (overflow_handler == OVERFLOW_IGNORE_LATEST ||
	    overflow_handler == OVERFLOW_OVERWRITE_OLDEST)
		rbuff->overflow_handler = overflow_handler;

	//Can use library functions
	int i = 0;
	for (i = 0; i < BUFFER_LENGTH; i++) {
		rbuff->buffer[i] = 0x00;
	}

}

uint8_t ring_buffer_empty(ring_buffer *rbuff)
{
	return (rbuff->count == 0);
}

uint8_t ring_buffer_full(ring_buffer *rbuff)
{
	return (rbuff->count == BUFFER_LENGTH);
}

BUFFER_DATA_TYPE ring_buffer_get(ring_buffer *rbuff)
{
	int temp;

	if (rbuff->count > 0) {
		temp = rbuff->buffer[rbuff->tail];

		rbuff->tail = rbuff->tail+1;
		if (rbuff->tail >= BUFFER_LENGTH) {
			rbuff->tail = 0;
		}
		rbuff->count--;
	}
	else {
		temp = -1;
	}

	return temp;
}

void ring_buffer_put(ring_buffer *rbuff, const BUFFER_DATA_TYPE ch)
{
	if (rbuff->overflow_handler == OVERFLOW_IGNORE_LATEST) {
		if (rbuff->count < BUFFER_LENGTH) {
			rbuff->buffer[rbuff->head] = ch;
			rbuff->head = rbuff->head+1;
		}
	}
	else {
		rbuff->buffer[rbuff->head] = ch;
		rbuff->head = rbuff->head+1;
	}

	if (rbuff->head >= BUFFER_LENGTH)
		rbuff->head = 0;

	if (rbuff->overflow_handler == OVERFLOW_IGNORE_LATEST) {
		rbuff->count++;
	}
	else {
		if (rbuff->count < BUFFER_LENGTH) {
			rbuff->count = rbuff->count+1;
		}
		else
			rbuff->count = rbuff->count;
	}

}

uint8_t ring_buffer_flush(ring_buffer *rbuff, uint8_t clear_buffer)
{
	rbuff->count = 0;
	rbuff->head = 0;
	rbuff->tail = 0;

	if (clear_buffer) {
		memset(rbuff->buffer, 0, sizeof(rbuff->buffer));
	}
}


void ring_buffer_print(ring_buffer *rbuff)
{
	int itr = 0;

	for (itr=0; itr < BUFFER_LENGTH; itr++) {
		if (rbuff->buffer[itr] != 0) {
			printf("%c", rbuff->buffer[itr]);
		}
	}
}


void ring_buffer_change_overflow(ring_buffer *rbuff, uint8_t overflow_handler)
{
	if (overflow_handler == OVERFLOW_IGNORE_LATEST ||
	    overflow_handler == OVERFLOW_OVERWRITE_OLDEST)
		rbuff->overflow_handler = overflow_handler;
}
