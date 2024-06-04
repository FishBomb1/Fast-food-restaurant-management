#define _CRT_SECURE_NO_WARNINGS 1
#include"vip.h"

#define MAX_MEMBERS 1000  //定义最大会员数量

//定义结构体，包含会员姓名、ID、电话、年龄、性别
int memberCount = 1;

Member members[MAX_MEMBERS] = {
    {"徐卫林",123456789,55,"male"},
};
//记录会员数量


void addMember() {
    if (memberCount >= MAX_MEMBERS) {
        printf("会员数量已达到上限！\n");
        return;
    }
    //添加会员
    Member newMember;
    printf("请输入会员姓名: ");
    scanf("%49s", newMember.name);
    printf("请输入会员电话: ");
    scanf("%14lf", &newMember.phone);
    printf("请输入会员年龄: ");
    scanf("%d", &newMember.age);
    printf("请输入会员性别（例如：Male 或 Female）: ");
    scanf("%9s", newMember.gender);

    members[memberCount] = newMember;
    memberCount++;
    printf("会员添加成功！\n");
}

//显示会员列表
void displayMembers() {
    printf("会员列表:\n");
    printf("%d\n", memberCount);
    for (int i = 0; i < memberCount; i++) {
        printf("姓名: %s\t电话: %.0lf\t年龄: %d\t性别: %s\n",
            members[i].name, members[i].phone, members[i].age, members[i].gender);
    }
}

//查找会员
int findMember() {
    double phoneToFind;
    
    scanf("%19lf", &phoneToFind);
    if (phoneToFind == 0) return 0;

    for (int i = 0; i < memberCount; i++) {
        if (members[i].phone = phoneToFind) {
            printf("找到会员: 姓名: %s, 电话: %.0lf, 年龄: %d, 性别: %s\n",
                members[i].name, members[i].phone, members[i].age, members[i].gender);
            return 1;
        }
    }
    printf("未找到会员！\n");
    return 0;
}

void VIP() {
    int choice;
    do {
        printf("\n会员信息管理系统\n");
        printf("1. 添加会员\n");
        printf("2. 显示会员列表\n");
        printf("3. 查找会员\n");
        printf("4. 退出系统\n");
        printf("请选择操作: ");
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
            printf("感谢使用会员信息管理系统！\n");
            break;
        default:
            printf("无效的选择，请重新输入！\n");
        }
    } while (choice != 4);

}