#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//学生结点
typedef struct _STU {
    char arrStudentNumber[10];
    char arrStudentName[10];
    int iStudentScore;
    struct _STU *pNext;
} STUDENTNODE;

//声明链表的头和尾
STUDENTNODE *g_pHead = NULL;
STUDENTNODE *g_pEnd = NULL;


//打印指令(声明)
void printOrder();

//添加一个学生信息,此处数组和指针都是一样，都是代表指针
void addStudentMessage(char *arrStudentNumber, char arrStudentName[10], int iStudentScore);

int main() {
    int nOrder = -1;//定义并初始化指令变量
    char arrStudentNumber[10] = {0};//此处的'\0'和0是一样的
    char arrStudentName[10] = {'\0'};
    int iStudentScore = -1;

    printOrder();
    cin >> nOrder;
    switch (nOrder) {
        case 1://添加一个学生信息
            cout << "请输入学号:" << endl;
            cin >> arrStudentNumber;

            cout << "请输入姓名:" << endl;
            cin >> arrStudentName;

            cout << "请输入分数:" << endl;
            cin >> iStudentScore;
            addStudentMessage(arrStudentNumber,  arrStudentName, iStudentScore);
            break;

        default:
            cout << "输入的指令不对" << endl;
            break;
    }


    system("pause");
    return 0;
}

//打印指令(定义)
void printOrder() {
    cout << "学生信息管理系统" << endl;
    cout << "本系统操作指令如下：" << endl;
    cout << "1、增加一个学生信息" << endl;
    cout << "2、查找指定学生信息(姓名/学号) " << endl;
    cout << "3、修改指定学生信息 " << endl;
    cout << "4、保存业主的信息到文件中(这里为学生) " << endl;
    cout << "5、读取文件中的业主信息 " << endl;
    cout << "6、删除指定学生信息 " << endl;
    cout << "7、恢复删除的学生的信息 " << endl;
    cout << "9、显示所有学生的信息 " << endl;
    cout << "0、退出系统 " << endl;
}

//添加一个学生信息,此处数组和指针都是一样，都是代表指针
void addStudentMessage(char *arrStudentNumber, char arrStudentName[10], int iStudentScore) {
    //第一步，参数的合法性
    if (NULL == arrStudentName || NULL == arrStudentNumber || iStudentScore < 0) {
        cout << "您输入的信息有误" << endl;
        return;
    }
    //逻辑
    //创建一个结点
    STUDENTNODE *pTemp = (STUDENTNODE *) malloc(sizeof(STUDENTNODE));
    //结点成员赋初始值,注意字符串赋值需要拷贝函数
    strcpy(pTemp->arrStudentNumber, arrStudentNumber);
    strcpy(pTemp->arrStudentName, arrStudentName);
    pTemp->iStudentScore = iStudentScore;
    pTemp->pNext = NULL;

    g_pHead = pTemp;
    g_pEnd = pTemp;

    //接在链表上
    if (NULL == g_pHead || NULL == g_pEnd) {
        g_pHead = pTemp;
        //g_pEnd = pTemp;
    } else {
        g_pEnd->pNext = pTemp;
        //g_pEnd=pTemp;
    }
    g_pEnd = pTemp;
}



