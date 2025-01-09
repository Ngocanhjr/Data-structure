#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000

// Function to input a large number as a string and convert it to an array of digits
void inputBigInt(char num[], int digits[], int *len) {
    *len = strlen(num);
    for (int i = 0; i < *len; i++) {
        digits[i] = num[*len - i - 1] - '0';  // Store digits in reverse order
    }
}


// Function to print the big integer
void printBigInt(int digits[], int len) {
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", digits[i]);
    }
    printf("\n");
}

// Function to add two large integers
void addBigInt(int a[], int a_len, int b[], int b_len, int result[], int *res_len) {
    int carry = 0, i;
    *res_len = (a_len > b_len) ? a_len : b_len;

    for (i = 0; i < *res_len; i++) {
        int sum = (i < a_len ? a[i] : 0) + (i < b_len ? b[i] : 0) + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        result[i] = carry;
        (*res_len)++;
    }
}
void subtractBigInt(int a[], int a_len, int b[], int b_len, int result[], int *res_len) {
    int borrow = 0, i;
    *res_len = a_len;

    for (i = 0; i < *res_len; i++) {
        int diff = a[i] - (i < b_len ? b[i] : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }

    // Adjust result length by removing leading zeros
    while (*res_len > 1 && result[*res_len - 1] == 0) {
        (*res_len)--;
    }
}
void multiplyBigInt(int a[], int a_len, int b[], int b_len, int result[], int *res_len) {
    int i, j;
    *res_len = a_len + b_len;

    // Initialize result array
    for (i = 0; i < *res_len; i++) {
        result[i] = 0;
    }

    for (i = 0; i < a_len; i++) {
        int carry = 0;
        for (j = 0; j < b_len; j++) {
            int prod = a[i] * b[j] + result[i + j] + carry;
            result[i + j] = prod % 10;
            carry = prod / 10;
        }
        result[i + j] += carry;
    }

    // Adjust result length by removing leading zeros
    while (*res_len > 1 && result[*res_len - 1] == 0) {
        (*res_len)--;
    }
}
void divideBigInt(int a[], int a_len, int divisor, int result[], int *res_len, int *remainder) {
    int i, temp = 0;
    *res_len = a_len;

    for (i = a_len - 1; i >= 0; i--) {
        temp = temp * 10 + a[i];
        result[i] = temp / divisor;
        temp %= divisor;
    }

    while (*res_len > 1 && result[*res_len - 1] == 0) {
        (*res_len)--;
    }

    *remainder = temp;
}
int main() {
    char num1[MAX_DIGITS], num2[MAX_DIGITS];
    int a[MAX_DIGITS], b[MAX_DIGITS], result[MAX_DIGITS];
    int a_len, b_len, res_len;

    // Input two large integers as strings
    printf("Enter the first large integer: ");
    scanf("%s", num1);
    printf("Enter the second large integer: ");
    scanf("%s", num2);

    // Convert them to arrays of digits
    inputBigInt(num1, a, &a_len);
    inputBigInt(num2, b, &b_len);

    // Add the two big integers
    addBigInt(a, a_len, b, b_len, result, &res_len);

    // Print the result
    printf("Sum: ");
    printBigInt(result, res_len);

    subtractBigInt(a, a_len, b, b_len, result, &res_len);

    // Print the result
    printf("Difference: ");
    printBigInt(result, res_len);

    multiplyBigInt(a, a_len, b, b_len, result, &res_len);

    // Print the result
    printf("Product: ");
    printBigInt(result, res_len);

    int divisor, remainder;

    // Input divisor (single-digit for simplicity)
    printf("Enter a single-digit divisor: ");
    scanf("%d", &divisor);

     divideBigInt(a, a_len, divisor, result, &res_len, &remainder);

    // Print the result
    printf("Quotient: ");
    printBigInt(result, res_len);
    printf("Remainder: %d\n", remainder);


    return 0;
}
