#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//ѧ�����
typedef struct _STU {
    char arrStudentNumber[10];
    char arrStudentName[10];
    int iStudentScore;
    struct _STU *pNext;
} STUDENTNODE;

//���������ͷ��β
STUDENTNODE *g_pHead = NULL;
STUDENTNODE *g_pEnd = NULL;


//��ӡָ��(����)
void printOrder();

//���һ��ѧ����Ϣ,�˴������ָ�붼��һ�������Ǵ���ָ��
void addStudentMessage(char *arrStudentNumber, char arrStudentName[10], int iStudentScore);

int main() {
    int nOrder = -1;//���岢��ʼ��ָ�����
    char arrStudentNumber[10] = {0};//�˴���'\0'��0��һ����
    char arrStudentName[10] = {'\0'};
    int iStudentScore = -1;

    printOrder();
    cin >> nOrder;
    switch (nOrder) {
        case 1://���һ��ѧ����Ϣ
            cout << "������ѧ��:" << endl;
            cin >> arrStudentNumber;

            cout << "����������:" << endl;
            cin >> arrStudentName;

            cout << "���������:" << endl;
            cin >> iStudentScore;
            addStudentMessage(arrStudentNumber,  arrStudentName, iStudentScore);
            break;

        default:
            cout << "�����ָ���" << endl;
            break;
    }


    system("pause");
    return 0;
}

//��ӡָ��(����)
void printOrder() {
    cout << "ѧ����Ϣ����ϵͳ" << endl;
    cout << "��ϵͳ����ָ�����£�" << endl;
    cout << "1������һ��ѧ����Ϣ" << endl;
    cout << "2������ָ��ѧ����Ϣ(����/ѧ��) " << endl;
    cout << "3���޸�ָ��ѧ����Ϣ " << endl;
    cout << "4������ҵ������Ϣ���ļ���(����Ϊѧ��) " << endl;
    cout << "5����ȡ�ļ��е�ҵ����Ϣ " << endl;
    cout << "6��ɾ��ָ��ѧ����Ϣ " << endl;
    cout << "7���ָ�ɾ����ѧ������Ϣ " << endl;
    cout << "9����ʾ����ѧ������Ϣ " << endl;
    cout << "0���˳�ϵͳ " << endl;
}

//���һ��ѧ����Ϣ,�˴������ָ�붼��һ�������Ǵ���ָ��
void addStudentMessage(char *arrStudentNumber, char arrStudentName[10], int iStudentScore) {
    //��һ���������ĺϷ���
    if (NULL == arrStudentName || NULL == arrStudentNumber || iStudentScore < 0) {
        cout << "���������Ϣ����" << endl;
        return;
    }
    //�߼�
    //����һ�����
    STUDENTNODE *pTemp = (STUDENTNODE *) malloc(sizeof(STUDENTNODE));
    //����Ա����ʼֵ,ע���ַ�����ֵ��Ҫ��������
    strcpy(pTemp->arrStudentNumber, arrStudentNumber);
    strcpy(pTemp->arrStudentName, arrStudentName);
    pTemp->iStudentScore = iStudentScore;
    pTemp->pNext = NULL;

    g_pHead = pTemp;
    g_pEnd = pTemp;

    //����������
    if (NULL == g_pHead || NULL == g_pEnd) {
        g_pHead = pTemp;
        //g_pEnd = pTemp;
    } else {
        g_pEnd->pNext = pTemp;
        //g_pEnd=pTemp;
    }
    g_pEnd = pTemp;
}



