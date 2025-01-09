#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DIGITS 1000 // Length of number can input
//nháp
typedef struct
{
    char *numbers; // Pointer to store array of digit
    int length;    // Length of the number
} BigInt;

BigInt read();

void display(BigInt a);

int isNegativeNumber(BigInt a);

void reverse(BigInt &a);

void addSpace(BigInt &a);

void swap(BigInt *a, BigInt *b);

BigInt initAdd(BigInt a, BigInt b);

BigInt add(BigInt a, BigInt b); // handle addition normal logic

BigInt initSubtract(BigInt a, BigInt b);

BigInt subtract(BigInt a, BigInt b);

int main()
{
    BigInt a = read();
    display(a);
    BigInt b = read();
    display(b);
    BigInt ad = initAdd(a, b);
    BigInt sub = initSubtract(a, b);
    printf("----------------------------------\n");
    printf("a + b = %s\n", ad.numbers);
    printf("a - b = %s\n", sub.numbers);
}

int isNegativeNumber(BigInt a)
{
    if (a.numbers[0] == '-')
    {
        return 1;
    }
    return 0;
}

void swap(BigInt *a, BigInt *b)
{
    BigInt temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(BigInt &a)
{
    for (int i = 1; i <= (a.length + 1) / 2; i++)
    {
        char temp = a.numbers[i];
        a.numbers[i] = a.numbers[a.length - i + 1];
        a.numbers[a.length - i + 1] = temp;
    }
}
void addSpace(BigInt &a)
{
    for (int i = a.length + 1; i >= 0; i--)
    {
        // char temp = a.numbers[i];
        a.numbers[i] = a.numbers[i - 1];
    }
    a.numbers[0] = ' ';
    a.numbers[a.length + 2] = '\0';
}
// 0 1 2 3 4 5 6 7
// 1 2 3 4 5 6 \n

BigInt read()
{
    char numberArray[MAX_DIGITS]; // Array store number when input
    printf("Enter new numbers: ");
    scanf("%s", numberArray);
    // fgets(num, MAX_DIGITS, stdin);
    // if (num[strlen(num) - 1] == '\n')
    //     num[strlen(num) - 1] = '\0';
    int sizeOfNumberArray = strlen(numberArray);
    //    printf("%d", sizeOfNumberArray);
    BigInt newBigNumber;
    newBigNumber.length = sizeOfNumberArray;
    newBigNumber.numbers = (char *)malloc(sizeOfNumberArray * sizeof(char));
    strcpy(newBigNumber.numbers, numberArray);
    return newBigNumber;
}

void display(BigInt a)
{
    int len = a.length;
    printf("Number:%*s\n", 12 + len, a.numbers); // format when print (12 is length of "Number:            ")
    //    printf ("Length of number: %d", len);
}

BigInt initAdd(BigInt a, BigInt b)
{
    BigInt result;
    result.numbers = (char *)malloc(sizeof(char) * (a.length > b.length ? a.length + 1 : b.length + 1)); // 1 is store digit when length of result larger then origin a, b number
    // case: a or b is negative
    if ((!isNegativeNumber(a) && isNegativeNumber(b)) || (isNegativeNumber(a) && !isNegativeNumber(b)))
    {
        result = subtract(a, b);
        return result;
    }
    else
    { // case: a and b is positive or negative
        result = add(a, b);
        // case: a and b is negative
        if (isNegativeNumber(a) && isNegativeNumber(b))
        {
            result.numbers[0] = '-';
        }
    }
    return result;
}

BigInt add(BigInt a, BigInt b)
{
    BigInt newNumber;
    newNumber.numbers = (char *)malloc(sizeof(char) * (a.length > b.length ? a.length + 1 : b.length + 1));
    newNumber.numbers[0] = ' '; // store sign of number
    int lenMax = a.length > b.length ? a.length : b.length;
    int carry = 0, idxNewNumber = 1;
    for (int i = a.length - 1, j = b.length - 1; i >= 0 || j >= 0; i--, j--, idxNewNumber++)
    {
        int aDigit = (i >= 0) ? a.numbers[i] - 48 : 0; // -48 convert from ASCII to natural number
        if (a.numbers[i] == '-')
            aDigit = 0;
        int bDigit = (j >= 0) ? b.numbers[j] - 48 : 0;
        if (b.numbers[j] == '-')
            bDigit = 0;
        int sumOfDigit = aDigit + bDigit + carry;
        carry = sumOfDigit > 9 ? 1 : 0;
        newNumber.numbers[idxNewNumber] = sumOfDigit % 10 + 48; //+48 convert from natural number to ascii
    }
    if (carry)
    {
        newNumber.numbers[idxNewNumber] = '1';
        lenMax++;
    }
    // update array number
    newNumber.length = lenMax;
    newNumber.numbers[lenMax + 1] = '\0';
    printf("Sum: \n");
    printf("%s\n", newNumber.numbers);
    reverse(newNumber);
    printf("%s\n", newNumber.numbers);
    return newNumber;
}

BigInt initSubtract(BigInt a, BigInt b)
{
    BigInt result;
    result.numbers = (char *)malloc(sizeof(char) * (a.length > b.length ? a.length + 1 : b.length + 1));
    // Case: a - (-b) = a + b
    if (!isNegativeNumber(a) && isNegativeNumber(b))
    { 
        result = add(a, b);
        result.numbers[0] = ' ';
        return result;
    }
    // case: (-a) - b = -(a + b)
    if (isNegativeNumber(a) && !isNegativeNumber(b))
    {
        result = add(a, b);
        result.numbers[0] = '-';
        return result;
    }
    else //(-a) - (-b) = -a + b = b - a or a - b
    {
        result = subtract(a, b);
    }
    return result;
}
BigInt subtract(BigInt a, BigInt b)
{
    BigInt newNumber;
    newNumber.numbers = (char *)malloc(sizeof(char) * (a.length > b.length ? a.length + 1 : b.length + 1));
    int lenMax = a.length > b.length ? a.length : b.length;
    int borrow = 0, idxNewNumber = 1;
    int isNewNumberNegative = 0;
    int aNegative = 0;
    int bNegative = 0;
    if (isNegativeNumber(a))
    {
        aNegative = 1;
        //        a.length = a.length - 1;
        a.numbers[0] = ' ';
    }
    else
    {
        addSpace(a);
        a.length++;
    }
    if (isNegativeNumber(b))
    {
        bNegative = 1;
        //        b.length = b.length - 1;
        b.numbers[0] = ' ';
    }
    else
    {
        addSpace(b);
        b.length++;
    }
    if (a.length == b.length)
    {
        if (strcmp(a.numbers, b.numbers) == 0)
        {
            strcpy(newNumber.numbers, "0");
            newNumber.length = 1;
            return newNumber;
        }
        if (strcmp(a.numbers, b.numbers) < 0)
        {
            if (!aNegative)
                isNewNumberNegative = 1;
            swap(&a, &b);
        }
        else
        {
            if (aNegative)
            {
                isNewNumberNegative = 1;
            }
        }
    }
    else if (a.length < b.length)
    {
        if (!aNegative)
            isNewNumberNegative = 1;
        swap(&a, &b);
    }
    else
    {
        if (aNegative)
        {
            isNewNumberNegative = 1;
        }
    }

    for (int i = a.length - 1, j = b.length - 1; i >= 0 || j >= 0; i--, j--, idxNewNumber++)
    {
        int aDigit = i >= 0 ? a.numbers[i] - 48 : 0;
        if (a.numbers[i] == ' ')
            aDigit = 0;
        int bDigit = j >= 0 ? b.numbers[j] - 48 : 0;
        if (b.numbers[j] == ' ')
            bDigit = 0;
        int subOfNumber;
        bDigit += borrow;
        if (aDigit < bDigit)
        {
            subOfNumber = (aDigit + 10) - (bDigit);
            borrow = 1;
        }
        else
        {
            subOfNumber = aDigit - bDigit;
            borrow = 0;
        }
        newNumber.numbers[idxNewNumber] = subOfNumber + 48;
    }
    if (isNewNumberNegative)
    {
        newNumber.numbers[0] = '-';
    }
    else
    {
        newNumber.numbers[0] = ' ';
    }
    // update array number
    newNumber.length = lenMax;
    newNumber.numbers[lenMax + 1] = '\0';
    printf("Subtract: \n");
    printf("%s\n", newNumber.numbers);
    reverse(newNumber);
    printf("%s\n", newNumber.numbers);
    return newNumber;
}

/*
(a>b)
(-a) - (-b) = -a + b = b - a => negative
a - b => positive
-a + b => negative
a + (-b) => positive
=> negative
(b > a)
đổi chỗ
(-a) - (-b) = -a + b = b - a => positive
a - b => negative
a + (-b) => negative
-a + b => positive
*/