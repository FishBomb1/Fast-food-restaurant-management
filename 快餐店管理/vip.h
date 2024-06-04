#pragma once
#include"common.h"

typedef struct {
    char name[50];
    double phone;
    int age;
    char gender[10]; // 假设性别最多9个字符（例如："Male" 或 "Female"）
} Member;

void addMember();
void displayMembers();
int findMember();
void VIP();
