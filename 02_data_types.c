#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * 字符类型
 * 整数类型
 *
 * @return
 */
int main() {

  // c语言规定字符常量必须放在单引号里，对应一个字节(byte)，每个字符对应一个整数(由ASCII码确定)
  // 字符类型在不同计算机的默认范围是不一样的，一些默认系统默认为-128~127，另外一种是0~255
  char c = 'B';
  // 只要在字符类型范围内，数字和字符可以相互转换
  char d = 66;
  // 两个字符变量可以进行运算
  char e = 'C';

  printf("%d\n" , c + e);// 输出10进制数

  // 单引号也是一个字符
  char t = '\'';

  char x = '\102'; //八进制
  char y = '\x42'; //十六进制

  /* ----------------- 整数类型 ------------------*/

  // 不同计算机的int类型的大小是不一样的,16位、32位、64位
  int a;
  // signed unsigned
  signed int b; //等同于int b
  unsigned int f; // 不带符号位，只表示非负整数

  /* ----------------- 整数的子类型 ------------------*/

  short int g; // 一般占用2字节
  long int h; // 至少为4个字节
  long long int i; // 至少为8个字节

  /* ----------------- 整数类型的极限值 ------------------*/
  printf("signed char min %d\n", SCHAR_MIN);
  printf("signed char max %d\n", SCHAR_MAX);

  printf("signed short min %d\n", SHRT_MIN);
  printf("signed short max %d\n", SHRT_MAX);

  /* ----------------- 整数的进制 ------------------*/
  printf("8 进制 %d\n", 012);
  printf("16 进制 %d\n", 0x1A2B);
  printf("2 进制 %d\n", 0b0101); //不标准

  /*
   * printf()的相关进制
   * %d，十进制
   * %o，八进制
   * %x，十六进制
   */
  x = 100;
  printf("dec = %d\n", x); // 100
  printf("octal = %o\n", x); // 144
  printf("hex = %x\n", x); // 64
  printf("octal = %#o\n", x); // 0144
  printf("hex = %#x\n", x); // 0x64
  printf("hex = %#X\n", x); // 0X64

  /* ----------------- 浮点数类型 ------------------*/

  /*
   * 浮点数在内存中是以指数的方式存储
   * https://mp.weixin.qq.com/s/AqrIQwHUZv5wpVexPK_nKA
   */
  float z = 10.5; // float类型占用4个字节
  double zz = 10.5; // 占用8个字节，至少提供13位有效数字
  long double zzz = 10.5; // 通常占用16个字节

  printf("%d\n", 0.1 + 0.2 == 0.3);

  /* ----------------- 布尔类型 ------------------*/
  int xx = 1;
  if (xx) {
    printf("xx is true!\n");
  }

  _Bool isNormal;
  isNormal = 1;
  if (isNormal) {
    printf("isNormal is true!\n");
  }

  bool flag = false;

  /* ----------------- 字面量的类型 ------------------*/

  // 指的是代码中直接出现的值
  int va = 123; //va就是变量，123就是字面量
  // 编译时，字节面量写入内存
  // 编译器会指定字面量的类型 int > long int > unsigned long > long long > unsigned long long
  double da = 1.23; // 小数被指定为double类型

  /* ----------------- 字面量后缀 ------------------*/

  /*
   * 当希望字面量为指定类型时，可以采用添加后缀的方式
   */

  int lx = 123L; // 此时编译器就会将其指定为Long类型，八进制和十六进制均可
  int ux = 123U; // unsigned int
  int ulx = 123LU; // unsigned long， U和L的组合顺序无所谓


  /* ----------------- 溢出 ------------------*/

  unsigned char xi = 255; // 编译器不会对溢出报错
  xi = xi + 1;

  printf("%d\n", xi); // 0 二进制11111111，加1后100000000

  unsigned int ui = UINT_MAX;  // 4,294,967,295
  ui++;
  printf("ui = %u\n", ui); // 0
  ui--;
  printf("ui = %u\n", ui); // 4,294,967,295

  // for (unsigned int i = n; i >= 0; --i) 无符号的循环，会一直满足条件

  unsigned int ii = 5;
  unsigned int ji = 7;

  if (ii - ji < 0) // 错误，因为ii和ji都是unsigned int，所以结果也是这个类型，相减后不可能小于0
    printf("negative\n");
  else
    printf("positive\n");

  /* ----------------- sizeof运算符 ------------------*/

  // 参数为数据类型
  int xxx = sizeof(int);

  // 参数为变量
  int size_i;
  printf("%zd\n", sizeof(i));

  // 参数为数值
  sizeof(3.14);

  /* ----------------- 类型的自动转换 ------------------*/
  //（1）浮点数赋值给整数变量
  int ci = 3.14; //C语言会直接丢弃小数部分
  // (2) 整数赋值给浮点数变量
  float cy = 12 * 2; // 变量cy的值不是24，而是24.0
  // (3) 窄类型赋值给宽类型
  char cc = 10;
  int cci = cc + cy;
  //（4）宽类型赋值给窄类型，系统会自动截取掉多余的二进制位
  int width = 321;
  char ch = i; // ch 的值是 65 （321 - 256）

  /* ----------------- 混合类型的运算 ------------------*/
  // 不同的整数类型混合运算时，宽度较小的类型会提升为宽度较大的类型
  int aaa = -5;
  if (aaa < sizeof(int)) //sizeof(int) 是 unsigned int类型，signed int 会自动转换为 无符号，
    printf("aaa min sizeof\n");

  /* ----------------- 整数类型的运算 ------------------*/
  unsigned char aaaa = 66;

  // 宽度小于int的类型，运算结果会自动提升到int
  if ((-aaaa) < 0) // -aaaa 不是 unsigned char，会自动提升到int类型
    printf("negative\n");
  else
    printf("positive\n");


  /* ----------------- 函数 ------------------*/

  char m = 42;
  unsigned short n = 43;
//  long long int mn = dostuff(m, n);

  /* ----------------- 类型的显示转换 ------------------*/

  (unsigned char) ch;

  long int yy = (long int) 10 + 12;

  /* ----------------- 可移植类型 ------------------*/

  // c语言在不同的计算机上，占用的字节宽度是不同的，无法提前知道他们是多少个字节

  // (1) 精确宽度类型(exact-width integer type)，保证某个整数类型的宽度是确定的。
  /*
   * int8_t 8位有符号整数
   * int16_t
   * int32_t
   * uint8_t
   * uint16_t
   */

  int32_t x32 = 45933945;
  printf("x32 = %d\n", x32);

  // (2) 最小宽度类型（minimum width type），保证某个整数类型的最小长度。
  /*
   * int_least8_t 可以容纳8位有符号整数
   * uint_least8_t
   */

  //（3）最快的最小宽度类型（fast minimum width type），可以使整数计算达到最快的类型。

  /*
   *int_fast8_t
   */

  //（4）可以保存指针的整数类型。

  /*
   * intptr_t：可以存储指针（内存地址）的有符号整数类型。
   * uintptr_t：可以存储指针的无符号整数类型。
   */

  //（5）最大宽度整数类型，用于存放最大的整数。

  /*
   * intmax_t：可以存储任何有效的有符号整数的类型。
   * uintmax_t：可以存放任何有效的无符号整数的类型。
   * 宽度比long long和unsigned long更大。
   */

  return 0;

}