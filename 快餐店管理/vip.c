#define _CRT_SECURE_NO_WARNINGS 1
#include"vip.h"

#define MAX_MEMBERS 1000  //��������Ա����

//����ṹ�壬������Ա������ID���绰�����䡢�Ա�
int memberCount = 1;

Member members[MAX_MEMBERS] = {
    {"������",123456789,55,"male"},
};
//��¼��Ա����


void addMember() {
    if (memberCount >= MAX_MEMBERS) {
        printf("��Ա�����Ѵﵽ���ޣ�\n");
        return;
    }
    //��ӻ�Ա
    Member newMember;
    printf("�������Ա����: ");
    scanf("%49s", newMember.name);
    printf("�������Ա�绰: ");
    scanf("%14lf", &newMember.phone);
    printf("�������Ա����: ");
    scanf("%d", &newMember.age);
    printf("�������Ա�Ա����磺Male �� Female��: ");
    scanf("%9s", newMember.gender);

    members[memberCount] = newMember;
    memberCount++;
    printf("��Ա��ӳɹ���\n");
}

//��ʾ��Ա�б�
void displayMembers() {
    printf("��Ա�б�:\n");
    printf("%d\n", memberCount);
    for (int i = 0; i < memberCount; i++) {
        printf("����: %s\t�绰: %.0lf\t����: %d\t�Ա�: %s\n",
            members[i].name, members[i].phone, members[i].age, members[i].gender);
    }
}

//���һ�Ա
int findMember() {
    double phoneToFind;
    
    scanf("%19lf", &phoneToFind);
    if (phoneToFind == 0) return 0;

    for (int i = 0; i < memberCount; i++) {
        if (members[i].phone = phoneToFind) {
            printf("�ҵ���Ա: ����: %s, �绰: %.0lf, ����: %d, �Ա�: %s\n",
                members[i].name, members[i].phone, members[i].age, members[i].gender);
            return 1;
        }
    }
    printf("δ�ҵ���Ա��\n");
    return 0;
}

void VIP() {
    int choice;
    do {
        printf("\n��Ա��Ϣ����ϵͳ\n");
        printf("1. ��ӻ�Ա\n");
        printf("2. ��ʾ��Ա�б�\n");
        printf("3. ���һ�Ա\n");
        printf("4. �˳�ϵͳ\n");
        printf("��ѡ�����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addMember();
            break;
        case 2:
            displayMembers();
            break;
        case 3:
            findMember();
            break;
        case 4:
            printf("��лʹ�û�Ա��Ϣ����ϵͳ��\n");
            break;
        default:
            printf("��Ч��ѡ�����������룡\n");
        }
    } while (choice != 4);

}