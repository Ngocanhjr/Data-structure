#include <stdio.h>
#include <math.h>

typedef struct
{
   int numerator;
   int denominator;
}Fraction;

Fraction read ();
void display (Fraction p);
int gcd (int a, int b);
void reduce (Fraction &p);
//Fraction reduce (Fraction ps);
Fraction add( Fraction ps1, Fraction ps2);
Fraction subtract( Fraction ps1, Fraction ps2);
Fraction multiply( Fraction ps1, Fraction ps2);
Fraction divide( Fraction ps1, Fraction ps2);

int main (){
   printf("----------------------------------------------------\n");
   Fraction p1 = read ();
   Fraction p2 = read ();
   printf("----------------------------------------------------\n");
   printf("First fraction: ");
   display(p1);
   printf("Second fraction: ");
   display(p2);
   printf("----------------------------------------------------\n");
   Fraction ad = add(p1,p2);
   Fraction sub = subtract(p1, p2);
   Fraction multi = multiply(p1, p2);
   Fraction div = divide(p1, p2);
   printf("Add: ");
   display(ad);
   printf("Subtract: ");
   display(sub);
   printf("Multiply: ");
   display(multi);
   printf("Divide: ");
   display(div);
   printf("----------------------------------------------------");
}

int gcd (int a, int b){
   a = abs(a);
   b = abs(b);
   while (b!=0){
      int t = a%b;
      a=b; // gcd(a,b)=(b,a%b);
      b=t;
   }
   return a;
}
void reduce (Fraction &p){
   int tempGcd = gcd (p.numerator, p.denominator);
   p.numerator = p.numerator / tempGcd;
   p.denominator = p.denominator / tempGcd;
}
Fraction read (){
   Fraction ps;
   do {
      printf("Please enter new fraction: ");
      scanf ("%d", &ps.numerator);
      scanf ("%d", &ps.denominator);
      if(ps.denominator == 0){
         printf ("ERROR! Please enter fraction again!\n");
      }
   } while (ps.denominator == 0);
   reduce(ps);
   return ps;
}
void display (Fraction p){
   if(p.denominator < 0) {
      p.numerator = (-p.numerator);
      p.denominator = (-p.denominator);
   }
   if(p.denominator==1){
      printf("%d\n",p.numerator);
   } else{
      printf ("%d/%d\n", p.numerator, p.denominator);
   }
}

Fraction add( Fraction ps1, Fraction ps2){
   Fraction newFraction;
   newFraction.numerator = (ps1.numerator*ps2.denominator + ps2.numerator*ps1.denominator);
   newFraction.denominator = (ps1.denominator*ps2.denominator);
   reduce(newFraction);
   return newFraction;
}
Fraction subtract( Fraction ps1, Fraction ps2){
   Fraction newFraction;
   newFraction.numerator = (ps1.numerator*ps2.denominator - ps2.numerator*ps1.denominator);
   newFraction.denominator = (ps1.denominator*ps2.denominator);
   reduce(newFraction);
   return newFraction;
}
Fraction multiply( Fraction ps1, Fraction ps2){
   Fraction newFraction;
   newFraction.numerator = (ps1.numerator*ps2.numerator);
   newFraction.denominator = (ps1.denominator*ps2.denominator);
   reduce(newFraction);
   return newFraction;
}
Fraction divide( Fraction ps1, Fraction ps2){
   Fraction newFraction;
   newFraction.numerator = (ps1.numerator*ps2.denominator);
   newFraction.denominator = (ps1.denominator*ps2.numerator);
   reduce(newFraction);
   return newFraction;
}