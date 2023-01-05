#include <stdio.h>
#include <string.h>

/**
 * C语言没有单独的字符串类型，字符串被当做字符数组
 * 字符串“Hello”是当作数组{'H', 'e', 'l', 'l', 'o'}，字符串是以\0结尾的，所以实际数组是{'H', 'e', 'l', 'l', 'o', '\0'}
 * @return
 */
int main() {

  char localString[10] = {'H', 'e', 'l', 'l', 'o', '\0'};
  // 等价于
  char str[10] = "Hello";

  char greeting[50] = "Hello, ""how are you ""today!";
  // 等价于
  char greeting1[50] = "Hello, how are you today!";
  // 等价于
  char greeting2[50] = "Hello, "
                      "how are you "
                      "today!";

  printf("%s\n", "hello world");

  /* ----------- 字符串变量的声明 ----------- */
  // 写法一
  char s[14] = "Hello, world!";
  // 写法二
  const char* s1 = "Hello, world!"; // 指针指向的是字符串，在C语言内部被当做常量，不能修改字符串本身
  // 数组的字符长度可以让编译器自动计算，所以声明时可以忽略长度
  char s2[] = "Hello, world!";// 编译器会将数组s2的长度指定为14
  s2[0] = 'h';
  // 字符数组的长度可以大于实际字符长度
  char s3[50] = "Hello";

  // 字符指针可以指向另一个字符串，字符数组变量不能指向另一个字符串
  // 字符数组的变量名跟所指向的数组是绑定的，不能指向另一个地址，数组变量是一个不能修改的左值

  char s4[10];
  strcpy(s4, "abc");

  printf("%s\n", s4);

  /* ----------- strlen() ----------- */

  // strlen()返回字符数组的长度，不包含末尾的空字符串'\0'
  char* str1 = "hello";
  printf("str1 length is %ld\n", strlen(str1));

  char s5[50] = "hello";
  printf("%ld\n", strlen(s5));
  printf("%ld\n", sizeof (s5));

  /* ----------- strcpy() ----------- */
  char* s6; // 字符串指针
  char* s7;
  s6 = "hello world!";
  //s7 = s6; // s6和s7两个指针都指向同一字符串
  //strcpy(s7, s6);
  // 数组的变量名是一个固定的地址值，不能修改
  char s8[10];
  strcpy(s8, "abcd"); // 返回值是一个指针，指向第一个参数

  char* s9 = "beast";
  char s10[40] = "Be the best that you can be.";
  char* ps;
  // 代表从第7位开始拷贝
  ps = strcpy(s10 + 7, s9);
  puts(s10);
  puts(ps);
  // strcpy()函数有风险，因为它不检测目标字符串长度，是否足够容纳源字符的副本，可能导致写入溢出

  /* ----------- strncpy() ----------- */
  /* char *strncpy(char *dst, const char *src, size_t n) */
  // 第3个参数n定义了复制的最大字符数n，如果到了最大字符数时还没有复制完就会停止，不过要注意此时是没有'\0'结尾的
  char* s11 = "hello world!";
  char s12[10];
  stpncpy(s12, s11, 5);
  s12[5] = '\0';
  puts(s12);

  /* ----------- strcat() ----------- */
  // 字符串拼接，将第二个字符串作为副本拼接到第一个字符串后面
  char ss1[10] = "hello";
  char ss2[5] = "world";
  //strcat(ss1, ss2);
  puts(ss1);

  /* ----------- strncat() ----------- */
  char ss3[10] = "Monday";
  char ss4[8] = "Tuesday";

  strncat(ss3, ss4, 3);
  puts(ss3); // "MondayTue"

  /* ----------- strcmp() ----------- */
  // 比较两个字符串，一个个字符进行比较
  // s1 = Happy New Year
  // s2 = Happy New Year
  // s3 = Happy Holidays

  strcmp(s1, s2); // 0
  strcmp(s1, s3); // 大于 0
  strcmp(s3, s1); // 小于 0

  /* ----------- strncmp() ----------- */
  // 只比较到指定位置

  /* ----------- sprintf()，snprintf() ----------- */
  // 用于将数据写入字符串
  char first[6] = "hello";
  char last[6] = "world";
  char all[40];

  sprintf(all, "%s %s", first, last); // 返回值是写入变量的字符数量，不计入尾部的空字符'\0'
  printf("%s\n", all);

  char all1[40];
  snprintf(all1, 12, "%s %s", "hello", "world"); // 写入的字符最长不超过12，包含'\0'

  /* ----------- 字符数组 ----------- */
  char weekdays[7][10] = {
      "Monday",
      "Tuesday",
      "Wednesday",
      "Thursday",
      "Friday",
      "Saturday",
      "Sunday"
  }; // 第一维的长度编译器可以自动计算，所以可以省略

  for (int i = 0; i < 7; i++) {
    printf("%s\n", weekdays[i]);
  }

  return 0;
}

char* strcpy_bak(char* dest, const char* source) {
  char* ptr = dest;
  while (*dest++ = *source++); // 依次将source的每个字符赋值给dest，然后向下移动一位，直到遇到\0
  return ptr;
}