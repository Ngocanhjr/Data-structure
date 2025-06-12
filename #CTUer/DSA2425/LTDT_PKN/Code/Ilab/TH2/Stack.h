
#define MAX_SIZE 100
typedef int ElementType;

//--------------------Stack------------------------
typedef struct {
    ElementType data[MAX_SIZE];
    int top_idx;
} Stack;

// init empty stack
void make_null_stack(Stack* pS) {
    pS->top_idx = -1;
}

// Check stack is empty>
int is_empty_stack(Stack* pS) {
    return pS->top_idx == -1;
}
// add element x to stack
void push(Stack* pS, ElementType x) {
    pS->top_idx++;
    pS->data[pS->top_idx] = x;
}

// delete element x fromt stack
void pop(Stack* pS) {
    pS->top_idx--;
}

// Retrieve top element
ElementType top(Stack* pS) {
    return pS->data[pS->top_idx];
}
