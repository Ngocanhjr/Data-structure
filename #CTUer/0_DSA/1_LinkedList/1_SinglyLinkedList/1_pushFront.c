#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// nếu bạn muốn thay đổi giá trị của một biến con trỏ thông qua hàm
// thì bạn cần phải sử dụng con trỏ cấp hai hoặc tham chiếu tới con trỏ.
/*
   Các bước để thêm node vào đầu DSLK :

   Cấp phát động một node mới
   Cho node mới lưu địa chỉ của node head (trỏ tới head)
   Cập nhật head thành node mới tạo
*/
struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

void print(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next; // duyet head chuyen sang node ke tiep
    }
}

// Thêm node vào đầu DSLK đơn quản lý bằng node head
void themNodeDau(node **head, int x)
{
    // 1 Cap phat dong node moi
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    // 2 Cho node moi tro vao head
    newNode->next = (*head); // (giai tham chieu)  ->  *head = dia chi cua node head trong dslk
    // 3. Cap nhat head => newNode
    (*head) = newNode; // thay doi head = newNode
}

// Thêm node vào đầu DSLK đơn quản lý bằng node head cách 2
/*
    viết hàm trả về con trỏ,
    để sau khi thay đổi head trong hàm thêm node vào đầu
    thì trong hàm main khi gọi hàm bạn sẽ gán lại hàm đó cho head.
*/

node *themNodeDau2(node *head, int x)
{
    // cap phat dong node moi
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    // 2 cho newNode tro vao head
    newNode->next = head;
    // 3. cap nhat head = newNode
    head = newNode;
    return head;
}

int main()
{
    node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        // themNodeDau(&head, i);
        head = themNodeDau2(head, i);
    }
    print(head);
}