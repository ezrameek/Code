/*
 * 添加联系人(addPerson):
 * - 设计联系人结构体
 * - 设计通讯录结构体
 * - main函数中创建通讯录
 * - 封装添加联系人函数
 * - 测试添加联系人功能
 *
 * 显示联系人(showPerson)：
 * - 封装显示联系人函数
 * - 测试显示联系人功能
 *
 * 删除联系人(deletPerson)：
 * - 封装检测联系人是否存在
 * - 封裝删除联系人函数
 * - 测试删除联系人功能
 *
 * 查找联系人(findPerson):
 * - 封裝查找联系人函数
 * - 测试查找指定联系人
 *
 * 修改联系人(editPerson):
 * - 封装修改联系人函数
 * - 测试修改联系人功能
 *
 * 清空联系人(clearPerson):
 * - 封装清空联系人函数
 * - 测试清空联系人
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// 联系人结构体
struct Person
{
    char m_Name[30];
    char m_Sex; // M -> 男 / W -> 女
    int m_Age;
    char m_Phone[11];
};
// 通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX];
    int m_Size;
};

void showMenu();
void addPerson(struct Addressbooks *abs);
void showPerson(struct Addressbooks *abs);
int isExist(struct Addressbooks *abs, char *name);
void deletPerson(struct Addressbooks *abs);
void findPerson(struct Addressbooks *abs);
void editPerson(struct Addressbooks *abs);
void clearPerson(struct Addressbooks *abs);

int main()
{
    // 创建通讯录结构体变量
    struct Addressbooks abs;
    abs.m_Size = 0;

    int select = 0; // 创建用户选择输入的变量

    while (1)
    {
        // 菜单调用
        system("clear");
        showMenu();

        printf("请输入数字：");
        scanf("%d", &select);

        switch (select)
        {
        case 1: // 显示功能
            showPerson(&abs);
            break;
        case 2: // 添加功能
            addPerson(&abs);
            break;
        case 3: // 删除功能
            deletPerson(&abs);
            break;
        case 4: // 修改功能
            editPerson(&abs);
            break;
        case 5: // 查询功能
            findPerson(&abs);
            break;
        case 6: // 清空功能
            clearPerson(&abs);
            break;
        case 0: // 退出
            printf("欢迎下次使用！\n");
            // system("clear");
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}

void showMenu()
{
    printf("                          ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("                                   欢迎进入通讯录\n");
    printf(
        "                          ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
    printf("	             【1】显示功能       |	     【2】增加功能     "
           "\n\n");
    printf("	             【3】删除功能       |	     【4】修改功能     "
           "\n\n");
    printf("	             【5】查询功能       |           【6】清空功能  "
           "\n\n");
    printf("	             【7】待定功能       |	     【8】待定功能     "
           "\n\n");
    printf("	             【0】退出功能       |	      \n\n");
    printf("-------------------------------------------------------------------"
           "-------------\n");
}
// 添加联系人
void addPerson(struct Addressbooks *abs)
{
    // 判断通讯录是否已满
    if (abs->m_Size >= MAX)
    {
        printf("通讯录已满，无法添加！\n");
        return;
    }
    else
    {
        // 添加具体联系人
        char name[32];
        printf("请输入姓名: ");
        scanf("%s", name);
        getchar();
        strcpy(abs->personArray[abs->m_Size].m_Name,
               name); // 分配给数组，只能复制到它(strcpy)

        char sex;
        printf("请输入性别: ");
        scanf("%c", &sex);
        getchar();
        abs->personArray[abs->m_Size].m_Sex = sex;

        int age;
        printf("请输入年龄: ");
        scanf("%d", &age);
        getchar();
        abs->personArray[abs->m_Size].m_Age = age;

        char phone[11];
        printf("请输入电话号码: ");
        scanf("%s", phone);
        getchar();
        strcpy(abs->personArray[abs->m_Size].m_Phone, phone);

        abs->m_Size++;
        printf("添加成功！输入任意键继续...");
        getchar();
        system("clear");
    }
}
void showPerson(struct Addressbooks *abs)
{
    // 判断通讯录中是否有人
    if (abs->m_Size == 0)
    {
        printf("通讯录中没有联系人！\n");
    }
    else
    {
        printf("编号\t姓名\t性别\t年龄\t电话号码\n");
        for (int i = 0; i < abs->m_Size; i++)
        {
            printf("%d\t%s\t%c\t%d\t%s\n", i + 1, abs->personArray[i].m_Name,
                   abs->personArray[i].m_Sex, abs->personArray[i].m_Age,
                   abs->personArray[i].m_Phone);
        }
    }
    printf("按任意键继续...\n");
    getchar();
    getchar();
}
// 判断是否存在联系人
int isExist(struct Addressbooks *abs, char name[])
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (strcmp(abs->personArray[i].m_Name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}
// 删除联系人
void deletPerson(struct Addressbooks *abs)
{
    char name[30];
    printf("请输入姓名: ");
    scanf("%s", name);
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        printf("删除成功！\n");
    }
    else
    {
        printf("查无此人！\n");
    }
    printf("按任意键继续...");
    getchar();
    getchar();
    printf("Hello, world!");
}
// 查找联系人
void findPerson(struct Addressbooks *abs)
{
    char name[30];
    printf("请输入姓名: ");
    scanf("%s", name);
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        printf("编号\t姓名\t性别\t年龄\t电话号码\n");
        printf("%d\t%s\t%c\t%d\t%s\n", ret + 1, abs->personArray[ret].m_Name,
               abs->personArray[ret].m_Sex, abs->personArray[ret].m_Age,
               abs->personArray[ret].m_Phone);
    }
    else
    {
        printf("查无此人！\n");
    }
    printf("按任意键继续...");
    getchar();
    getchar();
}
// 修改联系人
void editPerson(struct Addressbooks *abs)
{
    int id;
    printf("请输入编号: ");
    scanf("%d", &id);
    if (id - 1 >= 0)
    {
        // 添加具体联系人
        char name[30];
        printf("请输入姓名: ");
        scanf("%s", name);
        getchar();
        strcpy(abs->personArray[id - 1].m_Name,
               name); // 分配给数组，只能复制到它(strcpy)

        char sex;
        printf("请输入性别: ");
        scanf("%c", &sex);
        getchar();
        abs->personArray[id - 1].m_Sex = sex;

        int age;
        printf("请输入年龄: ");
        scanf("%d", &age);
        getchar();
        abs->personArray[id - 1].m_Age = age;

        char phone[11];
        printf("请输入电话号码: ");
        scanf("%s", phone);
        getchar();
        strcpy(abs->personArray[id - 1].m_Phone, phone);

        printf("修改成功！\n");
    }
    else
    {
        printf("查无此人！\n");
    }
    printf("按任意键继续...");
    getchar();
}
// 清空联系人
void clearPerson(struct Addressbooks *abs)
{
    abs->m_Size = 0;
    printf("是否清空通讯录(y/n): ");
    if (getchar() == 'Y' || getchar() == 'y')
    {
        printf("通讯录已清空！\n");
    }
    printf("按任意键继续...");
    getchar();
    getchar();
}
