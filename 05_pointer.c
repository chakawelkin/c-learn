#include <stdio.h>
#include <stddef.h>

/**
 * 作用是将传参+1，因为传入的是地址，所以不需要有返回值
 * @param p 一个整数指针p
 */
void increment(int* p) {
  *p = *p + 1; // *p就表示指针p指向的那个值
}

int main() {

  /* ------ 指针 ------ */
  int* intPtr; // 表示指向一个int类型值的指针
  int** foo; // foo指向的是一个指针，第二个指针指向的是一个整数

  /* ------ &运算符 ------ */
  int x = 1;
  printf("x's address is %p\n", &x); // %p是内存地址的占位符
  increment(&x);
  printf("increment x is %d\n", x);

  // & 和 * 互为逆运算
  int i = 5;
  if (i == *(&i)) printf("correct\n"); // 正确

  /* ------ 指针变量的初始化 ------ */
  int* p; // 声明一个指针变量，此时会指针变量本身分配一个内存空间，但此时内存空间里的值是随机的
  //*p = 1; // 向随机地址里写一个值，这会带来非预期的结果, 默认访问地址0x0，这个是无权访问的，会异常
  //int* p = NULL; 表示地址为0的内存空间，该地址读写就会报错

  p = &i;
  *p = 6;

  printf("i is %d\n", i);

  /* ------ 指针的运算 ------ */
  short* j;
  j = (short*)0x1234;
  j = j + 1; // 0x1236，指针与整数值的运算，表示指针的移动

  // 1.指针与指针的加法运算
  unsigned short* m;
  unsigned short* k;
  //x = m + k; // 非法

  short* j1;
  short* j2;

  j1 = (short*)0x1234;
  j2 = (short*)0x1236;

  ptrdiff_t dist = j2 - j1;
  printf("%td\n", dist); // 1

  return 0;
}


