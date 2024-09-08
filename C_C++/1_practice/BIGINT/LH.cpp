#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *digits; // Pointer to store digits
    int length;   // Length of the number
    int isNegative; // cho biết số nguyên có âm hay ko
} BigInteger;

void read(BigInteger *number, char x) {
    char c[1000];
    printf("Enter number %c: ", x);
    fgets(c, 1005, stdin);
    c[strlen(c) - 1] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng

    // Kiểm tra dấu âm
    if (c[0] == '-') {
        number->isNegative = 1;
        number->digits = (char *)malloc(strlen(c)); // Cấp phát động một vùng nhớ
        strcpy(number->digits, c + 1); // Bỏ dấu âm và sao chép phần còn lại
    } else {
        number->isNegative = 0;
        number->digits = (char *)malloc(strlen(c) + 1); // Cấp phát động một vùng nhớ
        strcpy(number->digits, c);
    }

    number->length = strlen(number->digits); // Lưu độ dài của xâu
}

void display(BigInteger num) {
    if (num.isNegative) {
        printf("-");//nếu độ dài của số lớn mà âm thì in ra '-'
    }
    printf("%s", num.digits);
}


//lât ngược xâu
void reverse(char *num, int length) {
    int l = 0, r = length - 1;
    while (l < r) {
        char tmp = num[l];
        num[l] = num[r];
        num[r] = tmp;
        l++;
        r--;
    }
}

int compareDigits(char *a, char *b, int lenA, int lenB) {
    if (lenA != lenB) {
        return lenA - lenB; // So sánh độ dài chuỗi
    }
    return strcmp(a, b); // So sánh trực tiếp chuỗi nếu cùng độ dài
}

BigInteger subtract(BigInteger a, BigInteger b) {
    BigInteger result;
    int maxLength = (a.length > b.length) ? a.length : b.length;
    result.digits = (char *)malloc(maxLength + 1);
    result.length = 0;

    reverse(a.digits, a.length);
    reverse(b.digits, b.length);

    int borrow = 0;
    for (int i = 0; i < maxLength; i++) {
        int digitA = (i < a.length) ? a.digits[i] - '0' : 0;
        int digitB = (i < b.length) ? b.digits[i] - '0' : 0;

        int diff = digitA - digitB - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.digits[result.length++] = diff + '0';
    }

    // Loại bỏ các số 0 thừa khi mà xâu trước có chỉ số lớn hơn chỉ số xâu sau
    while (result.length > 1 && result.digits[result.length - 1] == '0') {
        result.length--;
    }

    result.digits[result.length] = '\0';

    reverse(result.digits, result.length);

    return result;
}

BigInteger add(BigInteger a, BigInteger b) {
    BigInteger result;
    int maxLength = (a.length > b.length) ? a.length : b.length;
    result.digits = (char *)malloc(maxLength + 2); // +1 cho ký tự nhớ và +1 cho ký tự kết thúc
    result.length = 0;

    reverse(a.digits, a.length);
    reverse(b.digits, b.length);

    int memory = 0;
    for (int i = 0; i < maxLength; i++) {
        int digitA = (i < a.length) ? a.digits[i] - '0' : 0;
        int digitB = (i < b.length) ? b.digits[i] - '0' : 0;//==0 khi mà xâu sau có độ dài nhỏ hơn xâu trước
        int sum = digitA + digitB + memory;
        result.digits[result.length++] = (sum % 10) + '0';
        memory = sum / 10;
    }

    if (memory) {
        result.digits[result.length++] = memory + '0';
    }

    result.digits[result.length] = '\0';//chỉ số kết thúc xâu

    reverse(result.digits, result.length);

    return result;
}

BigInteger sum(BigInteger a, BigInteger b) {
    BigInteger result;

    if (a.isNegative == b.isNegative) {
        // Nếu cả hai số đều cùng dấu: ++ hoặc --;
        result = add(a, b);
        result.isNegative = a.isNegative; // Giữ nguyên dấu của a và b
    } else {
        // Nếu hai số có dấu khác nhau, thực hiện phép trừ
        if (compareDigits(a.digits, b.digits, a.length, b.length) >= 0) {
            result = subtract(a, b);
            result.isNegative = a.isNegative; // Kết quả có dấu của số lớn hơn
        } else {
            result = subtract(b, a);
            result.isNegative = b.isNegative; // Kết quả có dấu của số lớn hơn
        }
    }

    return result;
}

int main() {
    BigInteger a, b, result;
    read(&a, 'a');
    read(&b, 'b');

    result = sum(a, b);

    printf("a+b=  ");
    display(result);
    printf("\n");

    // Giải phóng bộ nhớ
    free(a.digits);
    free(b.digits);
    free(result.digits);


    return 0;
}
