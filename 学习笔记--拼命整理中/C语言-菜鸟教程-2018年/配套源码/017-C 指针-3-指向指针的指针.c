#include <stdio.h>
 
int main ()
{
   int  V;
   int  *Pt1;
   int  **Pt2;
 
   V = 100;
 
   /* ��ȡ V �ĵ�ַ */
   Pt1 = &V;
 
   /* ʹ������� & ��ȡ Pt1 �ĵ�ַ */
   Pt2 = &Pt1;
 
   /* ʹ�� pptr ��ȡֵ */
   printf("var = %d\n", V );
   printf("Pt1 = %p\n", Pt1 );
   printf("*Pt1 = %d\n", *Pt1 );
    printf("Pt2 = %p\n", Pt2 );
   printf("**Pt2 = %d\n", **Pt2);
 
   return 0;
}
