// 标准库
#include <stdio.h>

// 常量：不可被改变的值

int main() {

  printf("Hello, World!\n");

  // 占位符，%i这里必须是整数
  printf("There are %i apples\n", 3);
  // %s是字符串
  printf("%s will come tonight\n", "Jane");
  // %5代表这个占位符的宽度至少5位，如果不满则在对应的值前面添加空格
  printf("%5d\n", 123); // 输出为 "  123"
  // %-5 左对齐
  printf("%-5d\n", 123); // 输出为 "123  "
  // 输出 "  123.450000"，限制最小的输出宽度
  printf("%12f\n", 123.45);
  // 显示正负数，printf()不对正数显示+
  printf("%+d\n", 15);
  printf("%+d\n", -15);
  // 限定小数位数
  printf("Number is %.2f\n", 0.5);
  // 限定宽度和小数位数
  printf("%6.2f\n", 0.5);
  printf("%*.*f\n", 6, 2, 0.5); //宽度和小数位数，可以用传参代替
  // 输出部分字符串 hello，.5代表前5位字符
  printf("%.5s\n", "hello world");
  return 0;

}