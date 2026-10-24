
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 64

typedef struct {
    uint8_t buffer[SIZE];
    int head, tail, count;
} UART_Buffer;

typedef struct {
    UART_Buffer txBuffer, rxBuffer;
} UART_Device;

void initBuffer(UART_Buffer *b) {
    b->head = b->tail = b->count = 0;
}

bool enqueue(UART_Buffer *b, uint8_t data) {
    if (b->count == SIZE) return false;
    b->buffer[b->head] = data;
    b->head = (b->head + 1) % SIZE;
    b->count++;
    return true;
}

bool dequeue(UART_Buffer *b, uint8_t *data) {
    if (b->count == 0) return false;
    *data = b->buffer[b->tail];
    b->tail = (b->tail + 1) % SIZE;
    b->count--;
    return true;
}

void UART_Init(UART_Device *u) {
    initBuffer(&u->txBuffer);
    initBuffer(&u->rxBuffer);
    printf("UART Initialized.\n");
}

void UART_SendByte(UART_Device *u, uint8_t data) {
    if (enqueue(&u->txBuffer, data))
        printf("TX: '%c' enqueued\n", data);
    else
        printf("TX Buffer Full!\n");
}

void UART_ReceiveByte(UART_Device *u, uint8_t data) {
    if (enqueue(&u->rxBuffer, data))
        printf("RX: '%c' received\n", data);
    else
        printf("RX Buffer Full!\n");
}

void UART_ProcessTransmit(UART_Device *u) {
    uint8_t data;
    while (dequeue(&u->txBuffer, &data))
        printf("Transmitted: '%c'\n", data);
}

void UART_ReadReceivedData(UART_Device *u) {
    uint8_t data;
    while (dequeue(&u->rxBuffer, &data))
        printf("Read from RX: '%c'\n", data);
}

int main() {
    UART_Device uart;
    UART_Init(&uart);

    UART_SendByte(&uart, 'H');
    UART_SendByte(&uart, 'E');
    UART_SendByte(&uart, 'L');
    UART_SendByte(&uart, 'L');
    UART_SendByte(&uart, 'O');

    UART_ProcessTransmit(&uart);

    UART_ReceiveByte(&uart, 'O');
    UART_ReceiveByte(&uart, 'K');

    UART_ReadReceivedData(&uart);

    return 0;
}
