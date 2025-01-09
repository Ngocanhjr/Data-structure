#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    1 @-> 2 @-> X
    1: cấu trúc 1 node
    @->: con trỏ
    X: null/ NULL
*/
typedef struct node
{
    int data; // có thể thay thế thành kiểu dữ liệu khác
    node *next;
} node;

/*
Thêm node vào giữa danh sách liên kết:
    Tìm vị trí cur và next
    Trỏ node new vào node next
    Trỏ cur vào node new
*/
/*
Thêm vào đầu mảng:
    Trỏ new vào head (vị trí đầu mảng)
    Gán head = new;
*/
/*
Thêm phần tử vào cuối list
    xác định last (next -> null)
    Trỏ last vào new
*/
/*
Xoá một phần tử ở giữa
    Xác định pre, cur, next
    Trỏ pre vào next
    Giải phóng vùng nhớ dành cho cur (C/C++)
*/
/*
Xoá phần tử ở đầu list
    Xác định next
    Tạo biến temp trỏ vào head
    Trỏ head vào next
    Giải phóng temp    
*/
/*
Xoá phần tử cuối cùng
    Xác định pre và last
    Trỏ pre về null
    Giải phóng last
*/

int main (){
    node *head = (node*)malloc(sizeof(node)); // cấp phát phần tử đầu của node
    head->data = 100;
    head->next = NULL;
    printf("Giá trị của head: %d\n", head);
    printf("dữ liệu node mà head quản lý: %d\n", head->data);
}
/*
Mỗi node trong DSLK được cấp phát động
Mỗi node trong DSLK thực chất là một con trỏ, 
nó là địa chỉ một ô nhớ mà ô nhớ đó được sử dụng để lưu trữ thông tin về một node.
Sử dụng toán tử -> khi bạn cần truy cập vào data và next của một node trong DSLK thông qua con trỏ quản lý node đó
DSLK thực chất là 1 danh sách quản lý các con trỏ kiểu node
*/