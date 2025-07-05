#include <stdio.h>

int main() {
    printf("Hello, world!");
}

for (mọi giá trị V có thể gán cho Xi) {
    <thử cho Xi = V> if (Xi là phần tử cuối cùng của cấu hình) {
<thông báo cấu hình tìm được>
    }
    else {
<ghi nhận việc cho Xi nhận giá trị V (nếu cần)>
        Try(i + 1)  //Gọi đệ quy để tiếp tục chọn (Xi + 1)
        <Nếu cần, bỏ ghi nhận việc thử Xi = V, để thử giá trị khác>
    }
}