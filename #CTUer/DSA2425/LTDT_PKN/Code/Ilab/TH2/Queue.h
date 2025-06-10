#define MAX_SIZE 100
typedef int ElementType;
typedef struct {
    ElementType data[MAX_SIZE];
    int front, rear;
} Queue;
/* Khởi tạo hàng đợi rỗng */
void make_null_queue(Queue* pQ) {
    pQ->front = 0;
    pQ->rear = -1;
}
/* Đưa phần tử u vào cuối hàng đợi */
void enqueue(Queue* pQ, ElementType u) {
    pQ->rear++;
    pQ->data[pQ->rear] = u;
}
/* Xem phần tử đầu hàng đợi */
ElementType front(Queue* pQ) {
    return pQ->data[pQ->front];
}
/* Xoá bỏ phần bỏ đầu hàng đợi */
void dequeue(Queue* pQ) {
    pQ->front++;
}
/* Kiểm tra hàng đợi rỗng */
int empty(Queue* pQ) {
    return pQ->front > pQ->rear;
}