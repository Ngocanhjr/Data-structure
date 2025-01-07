// #include "acoderlib.h"
#include "pcoderlib.h"

int main()
{
    List source;
    makeNull(&source);
    printf("_____________________SOURCE___________________\n");
    source = read();
    print(source);
    /*
    Test len function _ARRAY
    */
    // int len = source.size;
    // printf("%d", len);

    /*
    Test len function function _LINKED LIST
    */
    // int len = length(source);
    // printf("%d", len);
    printf("_____________________KEY___________________\n");
    printf("Enter key\n");
    List key = read();
    print(key);
    printf("_____________________CODE___________________\n");
    List result = coder(source, key);
    print(result);
    printf("_____________________DE_CODE___________________\n");
    result = deCoder(result, key);
    print(result);
}