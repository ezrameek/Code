/* first.c -- 一个简单的 C 程序 */
/* 
 * #include <stdio.h>
 * - 相当于把 stdio.h 文件中的所有内容都输入该行所在的位置。
 * - 实际上，这是一种“拷贝-粘贴”的操作。
 * #include 
 * - 这行代码是一条 C 预处理器指令。
 * - 通常，C 编译器在编译前会对源代码做一些准备工作，即预处理。
 * stdio.h
 * - 头文件是扩展名为 .h 的文件
 * - 包含了 C 函数声明和宏定义，被多个源文件中引用共享。
 * - 有两种类型的头文件：程序员编写的头文件和编译器自带的头文件。
 * */
#include <stdio.h>
/*
 * 函数的基本形式:
 * returnType functionName(argument)
 * {
 *      satements...
 * }
 * - returnType 为返回值的数据类型，如果无返回值则为 void
 * - functionName 为函数名称，除主函数外默认不执行，除非在主函数中调用
 * - argument 为传入参数
 *   - 如果没有则为空或 void
 *   - 如果有一个参数则为 argument
 *   - 如果有多个参数需用 , 分隔
 * - satements.. 表示该函数的内容，语句需要用 {} 包裹起来，看作一个代码块
 * */
/*
 * main() 是一个特殊的函数：
 * - C 程序一定从 main() 函数开始执行；
 * - 执行到 main() 的返回语句结束程序。
 * 除了 main() 函数，你可以任意命名其他函数。
 * */
int main()
// 所有的C函数都使用花括号标记函数体的开始和结束，不可省略
{
    /*
     * 声明：让编译器告诉计算机开辟一个预留空间等待操作
     * int 是一个关键字，表示 整数类型(数据类型的一种)
     * num 是一个标识符 （identifer），也就一个变量、函数或其他实体的名称。
     * - 命名规则: 可以用小写字母、大写字母、数字和下划线（_）来命名。而且，名称的第1个字符必须是字符或下划线，不能是数字。
     * - C 语言的名称区分大小写，即把一个字母的大写和小写视为两个不同的字符。因此，stars 和 stars、 STARS 都不同。
     * */
    int num;    // 定义一个名为 num 的变量
    /*
     * 赋值表达式语句
     * - 该行代码的意思是“把值 1 赋给变量 num ”
     * 声明时，编译器在计算机内存中为变量 num 预留了空间，
     * 然后在执行这行赋值表达式语句时，把值储存在之前预留的位置。
     * 可以给 num 赋不同的值，这就是 num 之所以被称为变量（variable）的原因。
     * 注意，该赋值表达式语句从右侧把值赋到左侧。
     * 另外，该语句以分号结尾。
     * */
    num = 1;    // 为 num 赋一个值

    /* 
     * printf() 为一个函数，储存在 stdio.h 文件中；
     * 在引用 stdio.h 头文件后可直接调用
     * printf() 的作用是打印输出参数
     * printf => print + f(unction)
     * */
    printf("I an a simple ");   // 使用 printf() 函数
    /*
     * \n 的意思是换行，与 Enter 键效果相同
     * 转义序列: \*
     * */
    printf("computer.\n");
    printf("My favorite number is %d because it is first.\n", num);

    /* 
     * int main(void) 中的 int 表明 main（）函数应返回一个整数。
     * 有返回值的函数要有 return 语句。
     * 该语句以 return 关键字开始，后面是待返回的值，并以分号结尾。
     * 如果遗漏 main（）函数中的 return 语句，程序在运行至最外面的右花括号（｝）时会返回0。
     * - 因此，可以省略 main()函数末尾的 return 语句。
     * - 但是，不要在其他有返回值的函数中漏掉它。
     * */
    return 0;
}
