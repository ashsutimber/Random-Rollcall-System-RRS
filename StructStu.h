// StructStu.h
#pragma once
#include<Windows.h>
#include<shellapi.h>
// ����ѧ����Ϣ�ṹ��
struct stuinfo {
    char name[256];
    int countQuedao;
    int countqingjia;
    char isPresent[20];
};

// ��������ڵ�ṹ��
struct node {
    stuinfo stuData;
    struct node* next;
};

// �������ͱ���
typedef struct node linknode;
typedef linknode* linklist;
