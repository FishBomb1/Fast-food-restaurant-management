#pragma once
#include"common.h"

typedef struct {
    char name[50];
    double phone;
    int age;
    char gender[10]; // �����Ա����9���ַ������磺"Male" �� "Female"��
} Member;

void addMember();
void displayMembers();
int findMember();
void VIP();
