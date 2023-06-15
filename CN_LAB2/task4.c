#include <stdio.h>
 
/* function to show bytes in memory, from location start to start+n*/
void print_bytes(char *start, int n)
{
    int i;
    printf("Bytes in memory for this large number are ");
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}
 
int main()
{
   long long int num;
   printf("Input a large number\n");
   scanf("%lld", &num);
   print_bytes((char *)&num, sizeof(num));
   char *c = (char*) &num;
   if (*c == 0x00)
   {
    printf ("Underlying architecture is little endian. \n");
   }
   else
   {
     printf ("Underlying architecture is big endian. \n");
   }
   return 0;
}