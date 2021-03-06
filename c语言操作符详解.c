#define _CRT_SECURE_NO_WARNINGS 1


// 算术操作符： + - * / %
// 1.除了%操作符之外，其它操作符可以作用于整数和浮点数
// 2.对于 / 操作符如果两个操作符都为整数，执行整数除法(结果只保留整数)。只要有浮点数执行浮点数除法（结果有小数。真实值）。
// 3.% 操作符的两个操作数必须为整数，返回的是整数之后的余数。
#include <stdio.h>

//int main()
//{
//	double a = 5.0 / 2.0; // 商2余1
//	printf("a=%lf\n", a);
//	return 0;
//}


// 移位操作符:  右移操作符 >>   左移操作符 <<
// 移位操作符，移动的是二进制位。
// 右移操作符有两种：1.算术右移。把二进制位向右移动，右边舍去，左边补上原本的符号位。2.逻辑移位：右边直接丢弃，左边补零。
// 左移操作符：把二进制为向左移，左边丢弃，右边补零。

//int main()
//{
//	int a = 16;
//	int b = a >> 1;
//	// 16 的二进制位是 00000000000000000000000000010000
//	// 移位就是移二进制位
//	// 右移操作符有两种：1.算术右移。把二进制位向右移动，右边舍去，左边补上原本的符号位。2.逻辑移位：右边直接丢弃，左边补零。
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	int a = -1;
//	// 二进制的整数表示形式有原码、反码、补码三种形式
//	// 在计算机内部存放形式为补码。
//	// 正数的三种形式都相同。负数才不同
//	// 负数的原码符号位不变其余各位相反，得到反码。反码加一得到补码。
//	int b = a >> 1;
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	int a = 16;
//	int b = a << 1;
//	// 左移操作符：把二进制为向左移，左边丢弃，右边补零。
//	printf("%d\n", b);
//	return 0;
//}


// 位操作符：
// & 按位与  按二进制位，两个数的二进制位，都为1才输出1。否之为0
// | 按位或  按二进制位，两个数的二进制位，有一个为1，则输出1。全为0，才为0
// ^ 按位异或 按二进制位，两个数的二进制位，相同，输出0。不同，输出1。
// 注：它们操作的数必须为整数。
//int main()
//{
//	//int a = 3;
//	//int b = 5;
//	//int c = a & b;  // 把a和b 按位与的结果赋给c
//	//// a的二进制位：0000000000000000000000000000000011
//	//// b的二进制为：0000000000000000000000000000000101
//	////   a&b的结果：0000000000000000000000000000000001
//	//printf("%d\n", c);
//
//	int a = 3;
//	int b = 5;
//	//int c = a | b;  // 按位或
//	//printf("%d\n", c);
//
//	int c = a ^ b;  // 按位异或
//	printf("%d\n", c);
//	return 0;
//}

// 交换两个int变量的值，不能使用第三个变量。
//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("before:a=%d b=%d\n", a, b);
//	// 加减法
//	//a = a + b; // 有缺陷，因为整型占8字节，若a+b的和大于8字节，则不能很好存储，导致计算出现错误
//	//b = a - b;
//	//a = a - b;
//	//printf("after:a=%d b=%d\n", a, b);
//
//	// 异或法。此法不会有溢出问题。
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("after:a=%d b=%d\n", a, b);
//	return 0;
//}

// 编写代码实现一个整数存储在内存中的二进制1的个数
//int main()
//{
//	int a = 3;        此法不能算负数
//	int count = 0;
//	while (a)
//	{
//		if (a % 2 == 1)
//		{
//			count++;
//		}
//		a /= 2;
//	}
//	printf("count=%d\n", count);
//	return 0;
//}
// 优化一下。
//int main()
//{
//	int a = -1;
//	int count = 0;
//	// 整型32个比特位
//	// 把一个整数 按位与 1 若最后一位是1，则为1。最后一位为0，则为0
//	// 然后获取到最后一位是否为1后，在把整数右移。进行按位与
//	/*for (int i = 0; i < 32; i++)
//	{
//		if (((a>>i) & 1) == 1)
//		{
//			count++;
//		}
//	}*/
//	// 继续优化
//	while (a)
//	{
//		count++;
//		a = a & (a - 1);
//	}
//	printf("count=%d\n", count);
//	return 0;
//}

// 赋值操作符。

// a=a+2 等价与  a+=2。同理，a=a>>1  等价与 a>>=1  其余用法相同

// 单目操作符。顾名思义就是这操作符只作用于一个常量/变量/表达式
// ! 逻辑反操作,0为假，非0为真。!0 输出1（真默认为1）。若a不等于0，!a 输出0
// - 负值
// + 正值
// & 取地址
// sizeof 操作数的类型所占内存大小（单位字节）
// ~ 对于一个数的二进制按位取反
// -- 自减，有前置和后置    用法和++类似
// ++ 自增，有前置和后置   ++a是先自增再使用，a++是先使用后自增。可以理解为读取程序代码是从左向右读取。
// *  间接访问操作符（解引用）。作用于地址。例如，*加a的地址，就相当于a
//（类型） （）表示强制类型转换，转换成（）中的类型。
//int main()
//{
//	//int a = 10;
//	//printf("%d\n", !a);   // 逻辑反操作
//	//a = -a; // 负值
//	// printf("%p", &a);  // 取地址
//	//int* p = &a; // 把a的地址赋给p。 *p 等价于 a
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(int*));
//	//printf("%d\n", sizeof(int[10]));  // 数组类型的大小
//
//	int a = 5;
//	short b = 1;
//	printf("%d\n", sizeof(b = a + 5)); //sizeof括号里面的表达式不会运算，只是个摆设，也就是此处b=a+5不会运算
//	printf("%d\n", b);
//	return 0;
//}
//int main()
//{
//	//int a = 0;
//	//printf("%d\n", ~a);  // ~ 按二进制位取反。
//	int a = 11;
//	a = a | (1 << 2);
//	// 要求是把a的二进制位的第三位（从右往左数）改成1
//	// a的二进制位：00000000000000000000000000001011
//	// 	    按位或：00000000000000000000000000000100 这个数字。 只需把1<<2 就可得到
//	// 	      结果：00000000000000000000000000001111
//	a = a | (1 << 2);
//	printf("%d\n", a);
//	// 再把结果改回去00000000000000000000000000001111
//	//   按位与这个数11111111111111111111111111111011  这个数字只需把1<<2,在按位取反~就可得到
//	//           结果00000000000000000000000000001011
//	a = a & (~(1 << 2));
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	
//	int a = 10;
//	printf("%d\n", ++a); // 自增
//	return 0;
//}

//int main()
//{
//	int a = (int)3.14;  // 强制类型转换。
//	return 0;
//}



// 关系操作符 > , >= , < , <= , != , ==


// 逻辑操作符 &&逻辑与  ||逻辑或
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int x = 0;
//	int c = a && b;  // 逻辑与。都为真，才输出真。有一个为假，输出假。
//	int y = a || x;  // 逻辑或。都为假，才输出假。有一个为真，输出真。
//	printf("%d\n", c);
//	printf("%d\n", y);
//
//	return 0;
//}
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;    // 因为a++是先使用，再自增。此时a为0，逻辑与为假，后面代码不执行。故b和d没有自增
//	i = a++ || ++b || d++;  // 因为a++是先使用，再自增。此时a为0，不确定执行后面一个逻辑或是否为真，为真，最后的逻辑或就不会执行了。为假才继续执行
//	printf("%d %d %d %d", a, b, c, d);
//	return 0;
//}

// 总结：逻辑或和逻辑与的运算逻辑很偷懒。在逻辑或的运算中，若第一个就为真，便不会执行后面代码。在逻辑与的运算中，若第一个就为假，也不会继续执行后面代码。


// 条件操作符（也称三目操作符）
// exp1 ? exp2 : exp3   这个表示，如果表达式1（exp1）的结果为真，执行表达式2（exp2），表达式2的结果为整个表达式的结果。
//                                如果表达式1（exp1）的结果为假，执行表达式3（exp3），表达式3的结果为整个表达式的结果。

//int main()
//{
//	//int a = 3;
//	// a > 5 ? printf("哈哈\n") : printf("hehe\n");  
//	
//	int a = 6;
//	int b = 4;
//	int c = a > b ? a : b;  // 求两个数的最大值
//	printf("%d\n", c);
//	return 0;
//}


// 逗号表达式。用逗号隔开的表达式，从左向右依次执行，整个表达式的结果是最后一个表达式的结果。

//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = (a > b, a = b + 10, a, b = a + 1);
//	printf("%d\n", c);
//	return 0;
//}


// 下标引用操作符。[]  对于数组
//int main()
//{
//	int a[10] = { 0 };
//	a[4] = 10;  // 
//	return 0;
//}

// 函数调用操作符。()
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//int main()
//{
//	int a = 10;
//	int b = 9;
//	int c = max(a, b);  // max函数求两数最大值。
//	printf("%d\n", c);
//	return 0;
//}

//访问一个结构体的成员  .  
// 结构体名.成员名
// 结构体指针->成员民

//struct 学生    // 使用struct关键字 创建一个结构体类型 struct 学生
//{
//	char 学生姓名[20];
//	int 学生年龄;
//	char 学生编号[20];
//};
//int main()
//{
//	// 使用struct 学生 这个结构体类型，创建了一个结构体对象 s1。 
//	struct 学生 s1 = {"张三",20,"20181415"};  // 初始化学生s1。
//	//printf("%s\n", s1.学生姓名);   // 访问结构体中成员
//	//printf("%d\n", s1.学生年龄);
//	//printf("%s\n", s1.学生编号);
//
//	struct 学生* ps = &s1;  // 创建指针变量ps，存放结构体对象s1的内存地址。
//	printf("%s\n", ps->学生姓名);  // 通过内存地址指向结构体对象的成员，来访问其中的成员
//	printf("%d\n", ps->学生年龄);
//	printf("%s\n", ps->学生编号);
//	return 0;
//}



// 表达式求值。
// 表达式求值的顺序一部分是由操作符的优先级和结合性决定的。同样有些表达式的操作数在求值的过程中可能需要转换成其它类型。

//隐式类型转换
// c语言的整型算术运算总是至少以缺省整型类型的精度来进行的。
// 为了获得这个精度，表达式中字符和短整型操作数在使用之前被转换为普通整形。这种转换成为 整型提升。
//   整型提升规则：按照变量的数据类型的符号位来提升。若是无符号数，直接补0。
// 实例：
//     char a, b, c;
//     ......
//     a = b + c;
//   b和c的值先被提升为普通整型，然后再执行运算。加法运算完成后，结果将被截断（因为a为字符整型），然后再存储于a中。
//int main()
//{
//	char a = 3;
//	// 3 为整数占32比特位。 00000000000000000000000000000011
//	// 但char类型只有8个比特位，便会发生截断，从低位向高位，选一部分放入a中。00000011
//	char b = 127;
//	// 同理，127的二进制位 00000000000000000000000001111111
//	//  发生截断后     01111111    
//	char c = a + b;
//	// a和b相加
//	// 因为a为字符操作数，所以a会发生整型提升，提升为：00000000000000000000000000000011
//	//                                  同理b，提升为：00000000000000000000000001111111
//	//                                     两式相加得：00000000000000000000000010000010
//	//                                     发生截断得：10000010
//	//  因为打印是%d 为整型，故会发生整型提升，提升得：11111111111111111111111110000010
//	//                       然后把补码减一，得到反码：11111111111111111111111110000001
//	//             符号位不变，其余各位取反，得到原码：10000000000000000000000001111110
//	printf("%d\n", c);
//	return 0;
//}

// 实例：
//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)
//		printf("a");
//	if (b == 0xb600)
//		printf("b");
//	if (c == 0xb6000000)
//		printf("c");
//	return 0;
//}

//int main()
//{
//	char a = 1;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(+a));
//	printf("%d\n", sizeof(!a));
//	return 0;
//}

// 算术转换。针对大于等于int类型的数，例如unsigned int、long、double等
// 操作符的操作数属于不同类型，把小的类型转换为大的类型，然后运算。


// 操作符的属性
// 复杂的表达式的求值有三个影响的因素：
//		1.操作符的优先级。 比如乘的优先级大于加
//		2.操作符的结合性。 
//		3.是否控制求值顺序

// a* b + c * d + e * f;
// 这种表达式不能保证哪个乘法先算，是有问题的。

// c + --c;
// 这式子只能保证先自减的运算在+的运算前，但并不能得知，+操作符的左操作数的获取是在右操作数求值之前还是求值之后，所以结果不可预测。

//非法代码。每个编译器的结果都不同。
//int main()
//{
//	int i = 10;
//	i = i-- - --i * (i = -3) * i++ + ++i;
//	printf("%d\n", i);
//	return 0;
//}

//问题代码。
//int main()
//{
//	int i = 1;
//	int ret = (++i) + (++i) + (++i);
//	printf("ret = %d\n", ret);
//	printf("i = %d\n", i);
//	return 0;
//}


