#include <stdio.h>
 
int main ()
{
   /* �ֲ��������� */
   int a = 100;
   int b = 200;
 
   switch(a) {
      case 100: 
         printf("�����ⲿ switch ��һ����\n");
         switch(b) {
            case 200:
               printf("�����ڲ� switch ��һ����\n");
         }
   }
   printf("a ��׼ȷֵ�� %d\n", a );
   printf("b ��׼ȷֵ�� %d\n", b );
 
   return 0;
}
