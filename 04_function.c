#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * 函数原型
 * 一般每个源码文件的头部，都会给出当前脚本使用所有函数的原型
 * @param n
 * @return
 */
extern int plus_one (int n);

unsigned long Fibonacci(unsigned n) {
  if (n > 2)
    return Fibonacci(n - 1) + Fibonacci(n - 2);
  else
    return 1;
}

/**
 * 参数的传值引用
 * 如果函数的参数是一个变量，那么调用时传入的是值的拷贝，而不是变量的本身
 * @param a
 */
void increment(int a) {
  a++;
}

/**
 * 交换
 */
void Swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * 函数本身就是内存里的代码，c语言允许通过指针获取函数
 * @param a
 */
void print(int a) {
  printf("%d\n", a);
}

/**
 * 一个函数的参数或返回值是一个函数，可以写成如下这样
 * @param myfunc
 * @return
 */
int compute(int (*myfunc)(int), int, int);

void counter(void) {
  static int count = 1;  // 只初始化一次
  // static 修饰的变量初始化赋值只能是常量，不可以是变量
  printf("%d\n", count);
  count++;
}

/**
 * static可以用来修饰函数本身，表示该函数只能在当前文件中使用
 * @param num
 * @return
 */
static int Twice(int num) {
  int result = num * 2;
  return(result);
}

/**
 * static 仅用于告诉编译器，数组长度至少为3
 * @param a
 * @param n
 * @return
 */
int sum_array(int a[static 3], int n) {
  // ...
}

/**
 *
 * @param p
 */
void f(const int* p) {
  // ...
  // *p = 1; 当const int* p时，表示p指针指向的值不可修改
  int x = 13;
  p = &x;
}

/**
 * 平均数
 * @param i
 * @param ...
 * @return
 */
double average(int i, ...) {
  double total = 0;
  va_list ap; // 用来定一个一个可变参数对象
  va_start(ap, i); // 用来初始化可变参数对象
  for (int j = 1; j <= i; ++j) {
    total += va_arg(ap, double); // 用来取出当前那个可变参数
  }
  va_end(ap); // 用来清理可变参数
  return total / i;
}

/**
 * C语言规定，main()是程序的入口函数,及所有程序都一定要包含一个main()函数
 * main(void) 表示main函数默认返回0
 * @return
 */
int main(void) {

  int a = plus_one(13);
  unsigned long j = Fibonacci(10);
  printf("Fibonacci result %ld\n", j);

  int i = 10;
  increment(i);
  printf("i is %d\n", i);

  int b = 2;
  Swap(&a, &b);
  printf("a is %d, b is %d\n", a, b);

  /* ------- 函数指针 ------- */

  void (*print_ptr)(int) = &print;
  (*print_ptr)(10); // 通过函数指针调用函数

  // c语言还规定，函数名本身就是指向函数代码的指针，通过函数名就可以获取函数地址
  printf("%d\n", print == &print);
  printf("%d\n", print_ptr == &print);

  // 对于函数来说，以下5种写法的效果是一致的
  print(10);
  (*print)(10);
  (&print)(10);
  (*print_ptr)(10);
  print_ptr(10);

  /* ------- exit() ------- */

  atexit((&printf)("something wrong!\n"));

  // 程序运行成功
  // 等同于 exit(0);
  //exit(EXIT_SUCCESS);

  // 程序异常中止
  // 等同于 exit(1);
  //exit(EXIT_FAILURE);

  /* ------- 函数说明符 ------- */

  // 1、extern 说明符，extern告诉编译器当前文件不包含该函数的定义。
  // 2、static 说明符，默认情况下，每次函数调用都会对内部变量进行初始化，static表示该变量只初始化一次
  // 3、const 说明符，表示函数内部不得修改该参数变量

  counter();
  counter();
  counter();
  counter();

  /* ------- 可变参数 ------- */
  printf("average %5f", average(1,2,3,4,5));

}

/**
 * C 语言标准规定，函数只能声明在源码文件的顶层，不能声明在其他函数内部。
 * 函数不要返回内部变量的指针，以为此时函数已经结束了，内部变量就消失了
 * @param n
 * @return
 */
int plus_one(int n) {
  return n + 1;
}