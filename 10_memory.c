#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int x = 10;
  void* p = &x; // 先确定内存块，稍后再确认写入的数据类型
  // void类型可以指向任意类型的数据，但不能解读数据
  int* q = p;

  // printf("p point val is %s", *p);// 报错，不能直接读取void指针指向的值

  /* ------- malloc() ------- */
  int* z = malloc(sizeof(int)); //将返回的void指针强制转换为了int指针，malloc分配有可能失败，失败了就返回NULL
  *z = 12;
  printf("z is %d\n", *z);

  int* y = malloc(sizeof(long));
  // 分配失败
  if (y == NULL) { //NULL的值是0
  }
  if (y) {
  }
  //malloc最常用的场景就是为数组和自定义结构分配内存
  int* o = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; ++i) {
    o[i] = i * 5;
  }

  char* r = malloc(4);
  strcpy(r, "abc");
  printf("r is %s\n", r);
  free(r);

  /* ------- calloc() ------- */
  // 第一个参数是某种数据类型值的数量，第二个参数是数据类型的单位长度
  // calloc会对内存进行初始化，全量赋值为0
  int* s = calloc(10, sizeof(int));
  // 相当于 malloc() + memset()

  /* ------- realloc() ------- */
  // 用于修改已经分配的内存块大小
  int* t;
  t = malloc(10 * sizeof(int));
  t = realloc(t, 200 * sizeof(int));// 手动分配的好处，可以在运行时调整数组的长度
  realloc(t, 0); // 释放掉内存块
  t = realloc(NULL, 10 * sizeof(int)); // 相当于新建一个指针

  /* ------- memcpy() ------- */
  char u[] = "Goats!";
  char v[100];
  memcpy(v, u, sizeof(u));

  printf("v is %s\n", v);

  char w[] = "Home Sweet Home";
  printf("%s\n", (char *) memmove(w, &w[5], 10));// 将x的5号位置开始的10个字节,移动到0号位置

  // 比较
  int res = memcmp("abc", "acd", 3);
  printf("res is %d\n", res);

  return 0;
}

void* my_memcpy(void* dest, void* source, int byte_count) {
  char* s = source;
  char* d = dest;

  while (byte_count--) {
    *d++ = *s++;
  }

  return dest;
}