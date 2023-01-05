#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct person{
  char* name;
  int age;
};

typedef struct cell_phone {
  int cell_no;
  float minutes_of_charge;
} phone; //phone 就是 struct cell_phone 的别名

struct turtle {
  char* name;
  char* species;
  int age;
};

void happy(struct turtle t) {
  t.age = t.age + 1;
  // 函数内部得到的是struct副本，所以外部传入的数据不会受影响
}

void happy1(struct turtle* t) {
  (*t).age = (*t).age + 1;
  // (*t) 不能写成*t，因为.的优先级更高
  t->age = t->age + 1;
}

/**
 * struct的嵌套
 */
struct species {
  char* name;
  int kinds;
};

struct fish {
  char* name;
  int age;
  struct species breed;
};

struct node {
  int data;
  struct node* next;
};

/**
 * 位字段
 */
struct {
  unsigned int ab:1; //指定属性只占用一个二进制位
  unsigned int cd:1;
  unsigned int ef:1;
  unsigned int gh:1;
} synth;

/**
 * 弹性数组成员，在分配内存的时候再指定数组成员数
 * 规则：
 *  弹性成员的数组，必须是 struct 结构的最后一个属性
 *  除了弹性数组成员，struct 结构必须至少还有一个其他属性
 */
struct vstring {
  int len;
  char chars[];
};

int main() {
  struct person p1; // 编译时为p1分配内存
  // 逐一对属性赋值
  p1.name = "chaka";
  p1.age = 20;
  // 一次性为所有属性赋值
  struct person p2 = {"chaka1", "26"};
  // 指定属性进行赋值
  struct person p3 = {.name="chaka2", .age = 27};

  struct book {} b1; // 数据类型声明语句和变量可以是一条语句

  struct {} b2; // struct 声明了匿名函数
  // 声明变量的同时对变量进行赋值
  struct {
    char title[500];
    char name[100];
    float value;
  } c1 = {"","", 1.0f},
    c2 = {"","", 1.0f};

  phone p = {1231872, 10.0f};

  //指针变量也可以指向struct结构
  struct books {
    char title[500];
    char author[100];
    float value;
  }* b3;
  // b3是一个指针，指向的数据是struct books类型的实例
  // struct 也可以作为一个数组成员

  struct books numbers[100];
  strcpy(numbers[0].title, "pwd");
  numbers[0].value = 10.0f;

  struct foo {
    int a; //4字节
    char* b; //8字节
    char c; //1字节
  };

  printf("struct foo size is %ld\n", sizeof(struct foo));
  // 输出结果是24，会取占用内存最大的属性大小再乘以属性个数，b是8个字节，其它两个属性会添加空位与之对齐

  struct ball {
    char c;
    int a;
    char* b;
  };
  printf("struct ball size is %ld\n", sizeof(struct ball));

  /* ----------- struct的复制 ----------- */
  struct cat {
    char name[30];
    short age;
    char* address;
  } a, b;

  strcpy(a.name, "Hula");
  a.age = 3;
  a.address = "china";

  b = a; // 赋值给另一个变量，这时会生成一个全新的副本，系统会分配一块新的内存
  b.name[0] = 'M';
  b.address = "canada";
  printf("a name %s\n", a.name);
  printf("b name %s\n", b.name);
  // 变量b是变量a的副本，修改b的name不影响a
  printf("a address %s\n", a.address);
  printf("b address %s\n", b.address);

  /* ----------- struct指针 ----------- */
  struct turtle myTurtle = {"MyTurtle", "sea turtle", 99};
  happy(myTurtle);
  printf("Age is %i\n", myTurtle.age);
  happy1(&myTurtle);
  printf("Age is %i\n", myTurtle.age);

  /* ----------- struct的嵌套 ----------- */
  struct fish shark = {"shark", 9, {"Selachimorpha", 500}};

  struct species myBreed = {"Selachimorpha", 500};
  struct fish shark1 = {"shark", 9, myBreed};

  struct fish shark2 = {
      .name = "shark",
      .age = 1,
      .breed = {"Selachimorpha", 500}
  };

  struct fish shark3 = {
      .name = "shark",
      .age = 1,
      .breed.name = "Selachimorpha",
      .breed.kinds = 500
  };

  printf("Shark's species is %s", shark.breed.name);

  /* ----------- 位字段 ----------- */
  synth.ab = 1;
  synth.cd = 0;

  /* ----------- 弹性数组成员 ----------- */
  struct vstring* vs = malloc(sizeof(struct vstring) + 10 * sizeof(char));
  vs->len = 10;

  return 0;
}