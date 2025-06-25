/* Khai báo CTDL Stack*/

#define MAX_SIZE 100
typedef int ElementType;
typedef struct {
    ElementType data[MAX_SIZE];
    int top_idx;
} Stack;
/* Hàm khởi tạo ngăn xếp rỗng */
void make_null_stack(Stack* pS) {
    pS->top_idx = -1;
}
/* Hàm thêm phần tử u vào đỉnh ngăn xếp */
void push(Stack* pS, ElementType u) {
    pS->top_idx++;
    pS->data[pS->top_idx] = u;
}
/* Hàm xem phần tử trên đỉnh ngăn xếp */
ElementType top(Stack* pS) {
    return pS->data[pS->top_idx];
}
/* Hàm xoá bỏ phần tử trên đỉnh ngăn xếp */
void pop(Stack* pS) {
    pS->top_idx--;
}
/* Hàm kiểm tra ngăn xếp rỗng */
int empty(Stack* pS) {
    return pS->top_idx == -1;
}