//#include <stdio.h>
// 
//const int MAX = 3;
// 
//int main ()
//{
//   int  var[] = {10, 100, 200};
//   int  i, *ptr;
// 
//   /* ָ���е������ַ */
//   ptr = var;
//   for ( i = 0; i < MAX; i++)
//   {
// 
//      printf("�洢��ַ��var[%d] = %p\n", i, ptr );
//      printf("�洢ֵ��var[%d] = %d\n", i, *ptr );
// 
//      /* ָ����һ��λ�� */
//      ptr++;
//   }
//   return 0;
//}

#include <stdio.h>
 
const int MAX = 3;
 
int main ()
{
   int  var[] = {10, 100, 200};
   int  i, *ptr;
 
   /* ָ�������һ��Ԫ�صĵ�ַ */
   ptr = &var[MAX-1];
   for ( i = MAX; i > 0; i--)
   {
 
      printf("�洢��ַ��var[%d] = %p\n", i-1, ptr );
      printf("�洢ֵ��var[%d] = %d\n", i-1, *ptr );
 
      /* ָ����һ��λ�� */
      ptr--;
   }
   return 0;
}
