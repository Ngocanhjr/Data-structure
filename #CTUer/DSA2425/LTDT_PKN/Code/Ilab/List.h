// Khai báo CTDL List và các phép toán cơ bản
#define MAX_ELEMENTS 100
typedef int ElementType;

typedef struct {
    ElementType data[MAX_ELEMENTS];
    int size;
} List;

// Tạo danh sách rỗng
void make_null(List* pL) {
    pL->size = 0;
}

// Thêm một phần tử vào cuối danh sách
void push_back(List* pL, ElementType x) {
    pL->data[pL->size] = x;
    pL->size++;
}

// Lấy phần tử thứ i, phần tử bắt đầu có vị trí 1
ElementType element_at(List* pL, int i) {
    return pL->data[i - 1];
}

// Trả về số phần tử của danh sách
int count_list(List* pL) {
    return pL->size;
}