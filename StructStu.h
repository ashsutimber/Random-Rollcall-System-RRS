// StructStu.h
#pragma once
#include<Windows.h>
#include<shellapi.h>
// 定义学生信息结构体
struct stuinfo {
    char name[256];
    int countQuedao;
    int countqingjia;
    char isPresent[20];
};

// 定义链表节点结构体
struct node {
    stuinfo stuData;
    struct node* next;
};

// 定义类型别名
typedef struct node linknode;
typedef linknode* linklist;
