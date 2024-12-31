
#include "functions.h"
#include <string.h>

void hienThiMenu() {
    printf("\n======================================\n");
    printf("\n         Product Portfolio Management\n        ");
    printf("\n======================================\n");
    printf("\t1. Show Catalog List\n"); //Hien thi danh sách danh muc
    printf("\t2. Add a new category\n"); //them danh muc moi 
    printf("\t3. Catalog Search\n");//Tim kiem danh muc
    printf("\t4. Save the list to file\n");//Luu danh sacsh vao tep
    printf("\t5. Edit the list\n");//Chinh sua danh sach
    printf("\t0. Exits\n");
    printf("\nSelect: ");
}
void nhapDanhMuc(DanhMuc *dm) {
    printf("Enter the catalog code: "); //Nhap ma danh muc
    scanf("%d", &dm->maDanhMuc);    
    printf("Enter a catalog name: "); //Nhap tên danh muc
    scanf("%s",&dm->tenDanhMuc);
//    fgets(dm->tenDanhMuc, 100, stdin);
}
//void nhapDanhMuc(DanhMuc *dm) {
//    printf("Nhap ma danh muc: ");
//    scanf("%d", &dm->maDanhMuc);
//
//    // su dung fgets de nhap ten danh muc bao gom ca dau cach
//    printf("Nhap ten danh muc: ");
//    fgets(dm->tenDanhMuc, 100, stdin); 
//    
//
//    // Loai bo ky tu '\n' o cuoi chuoi
//    dm->tenDanhMuc[strcspn(dm->tenDanhMuc, "\n")] = '\0'; 
//}
void hienThiDanhSach(DanhMuc *danhSach, int soLuong) {
    printf("\nCatalog List:\n");
    int i; 
    printf("+-----------------+-----------------------+\n");
    printf("|   Catalog id    |      Catalog name     |\n");
    printf("+-----------------+-----------------------+\n");
    for ( i = 0; i < soLuong; i++) {
        printf("| %15d | %-20s |\n", danhSach[i].maDanhMuc, danhSach[i].tenDanhMuc);
    }
    printf("+-----------------+-----------------------+\n");
}

void timDanhMuc(DanhMuc *danhSach, int soLuong) {
    char ten[50];
    printf("Enter the name of the category to look for: ");
    scanf("%s", ten);

    int i;
    for (i = 0; i < soLuong; i++) {
        if (strcmp(danhSach[i].tenDanhMuc, ten) == 0) {
            printf("Find the catalog:\n");
            printf("Ma: %d\tTen: %s\n", danhSach[i].maDanhMuc, danhSach[i].tenDanhMuc);
            return;
        }
    }

    printf("Khong tim thay danh muc!\n");
}
void luuDanhSachVaoFile(DanhMuc *danhSach, int soLuong) {
    FILE *fp = fopen("danh_sach.txt", "w");
    if (fp == NULL) {
        printf("Loi mo file!\n");
        return;
    }
	int i; 
    for ( i = 0; i < soLuong; i++) {
        fprintf(fp, "%d,%s\n", danhSach[i].maDanhMuc, danhSach[i].tenDanhMuc);
    }

    fclose(fp);
    printf("Luu danh sach vao file thanh cong!\n");
}

void themDanhMuc(DanhMuc *danhSach, int *soLuong) {
    if (*soLuong >= MAX_DANH_MUC) {
        printf("Danh sach da day!\n");
        return;
    }
    DanhMuc dm;
    nhapDanhMuc(&dm);
    danhSach[*soLuong] = dm;
    (*soLuong)++;
    printf("Them danh muc thanh cong ! \n");
}
void suaDanhMuc(DanhMuc *danhSach, int soLuong) {
    int idCanSua, i;
    printf("Nhap ID danh muc muon sua: ");
    scanf("%d", &idCanSua);

    // Tim danh sach danh muc can sua  
    for (i = 0; i < soLuong; i++) {
        if (danhSach[i].maDanhMuc == idCanSua) {
            break;
        }
    }

    // Neu khong tim thay danh muc
    if (i == soLuong) {
        printf("Khong tim thay danh muc co ID %d!\n", idCanSua);
        return;
    }

    // Hien thi thong tin hien tai cua danh muc
    printf("Thong tin hien tai cua danh muc:\n");
    printf("Ma: %d\tTen: %s\n", danhSach[i].maDanhMuc, danhSach[i].tenDanhMuc);

    // Nhap thong tin moi
    printf("Nhap ten moi cho danh muc: ");
    scanf("%s", danhSach[i].tenDanhMuc);

    printf("Sua danh muc thanh cong!\n");
}
void quayLaiMenu() {
    printf("\nNhan Enter de quay lai menu chinh...");
    getchar();
}
