#include "alistlib.h"

int main() {
   	
List L = {{3, 4, 5, 7}, 4};
popAt(1, &L);
print(L);
}