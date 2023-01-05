#include <stdio.h>
#include <string.h>


int sum(int* arr, int len);
int sum2(int* start, int* end);

int main() {

  int scores[100];
  scores[0] = 13;
  scores[99] = 42;
  scores[100] = 51;// 引用不存在的数组成员（数组越界），不会报错

  int a[5] = {22, 37, 3490, 18, 95}; // 使用大括号赋值时，必须在声明时赋值，否则会报错
  //a = {22, 37, 3490, 18, 95};
  // 如果大括号赋值少于数组的成员变量，那么未赋值的成员自动初始化为0

  int b[5] = {22, 37, 3490};
  // 等同于
  int c[5] = {22, 37, 3490, 0, 0};

  // 将数组中每一个成员都设置为0
  int d[100] = {0};

  // 数组初始化时，可以指定为哪些位置的成员赋值。
  int e[15] = {[2] = 29, [9] = 7, [14] = 48};

  // 指定位置的赋值与顺序赋值，可以结合使用。
  int f[15] = {1, [5] = 10, 11, [10] = 20, 21};

  // C语言允许省略数组成员数量
  int g[] = {22, 37, 3490};
  // 等同于
  int h[3] = {22, 37, 3490};
  // 省略成员数量时，数组长度将是最大的+1
  int i[] = {[1] = 15, [9] = 10}; //长度是10

  printf("array i size is %zd\n", sizeof(i) / sizeof(i[0]));

  /* ------ 多维数组 ------ */
  int board[10][10];

  int board_a[2][5] = {
      {0, 1, 2, 3, 4},
      {5, 6, 7, 8, 9}
  };

  /* ------ 变长数组 ------ */
  int n = 1;
  int arr[n]; //只有在运行时才能确定数组的长度
  // 任何长度需要运行时才能决定的，都是变长数组
  int j = 10;
  int a1[j];
  int a2[j + 5];
  // 变长数组也可以用于多维的
  int m = 4;
  int k[m][n];

  /* ------ 数组的地址 ------ */
  int l[5] = {11, 22, 33, 44, 55};
  int* p = &l[0]; // 由于数组的起始地址是常用操作，所以等同于int* p = l;
  printf("%d\n", *p);  // Prints "11"
  printf("array sum is %d\n", sum(l, 5));

  int o[4][2];
  *(o[0]); //取出a[0][0]的值，o[0]本身就是一个指针，指向二维数组的第一个成员
  //等同于
  **o;

  // 注意，数组名指向的地址是不可更改的。编译时，编译器为数组自动分配了内存地址，这个地址与数组名是绑定的
  int ints[100];
  // ints = NULL; // 报错

  /* ------ 数组指针的加减法 ------ */
  int q[5] = {11, 22, 33, 44, 55};
  // 通过指针的移动遍历数组，a + i每轮循环都会指向下一个成员的地址，
  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(q + i));
  }
  printf("q[1] == *(q + 1) is %d\n", q[1] == *(q + 1));

  int* pq = q;

  while (*pq != 55) {
    printf("%d\n", *pq);
    pq++;
  }

  int arr2[5] = {20, 10, 5, 39, 4};
  printf("%i\n", sum2(arr2, arr2 + 5));

  int arr3[5] = {20, 10, 5, 39, 88};

  int* arr3_p = arr3;

  while (*arr3_p != 88)
    arr3_p++;

  printf("arr3 size is %ld\n", arr3_p - arr3);

  // 对于多维数组
  int arr4[4][2];
  arr4 + 1; //指针指向arr4[1][0]
  arr4[0] + 1; //指针指向arr4[0][1]

  // 同一数组的两个成员相减时，返回他们的距离
  int* a_p1 = &a[0];
  int* a_p2 = &a[3];

  printf("a_p2 - a_p1 = %ld\n", a_p2 - a_p1);

  /* ------ 数组的复制 ------ */

  int* arr_a;
  int arr_b[3] = {1, 2, 3};
  arr_a = arr_b; // 这仅仅是让arr_a指向同一个数组

  //memccpy(arr_a, arr_b, sizeof (arr_b));

  return 0;
}

/**
 * 通过数组指针对成员求和
 * @param arr
 * @param len
 * @return
 */
int sum(int* arr, int len) {
  int i;
  int total = 0;

  // 假定数组有 10 个成员
  for (i = 0; i < len; i++) {
    total += arr[i];
  }
  return total;
}

int sum2(int* start, int* end) {
  int total = 0;

  while (start < end) {
    total += *start;
    start++;
  }

  return total;
}