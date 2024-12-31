#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DANH_MUC 100
//#define MAX_TEN_DANH_MUC 100

// C?u trúc m?t danh m?c
typedef struct {
    int maDanhMuc;
    char tenDanhMuc[50];
//    char tenDanhMuc[MAX_TEN_DANH_MUC];
} DanhMuc;
