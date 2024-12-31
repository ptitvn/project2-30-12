#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	DanhMuc danhSach [MAX_DANH_MUC];
    int soLuong = 0;
    int luaChon;
    do {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
               hienThiDanhSach(danhSach, soLuong);
               quayLaiMenu();
				
                break;
            case 2:
               themDanhMuc(danhSach, &soLuong);
               quayLaiMenu();
                break;
            case 3:
	           timDanhMuc(danhSach, soLuong);
	           quayLaiMenu();
                break;
            case 4:
            	luuDanhSachVaoFile(danhSach, soLuong);
            	quayLaiMenu();
                break;
            case 5:
            	suaDanhMuc(danhSach, soLuong);
            	quayLaiMenu();
				break;    
            case 0:
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);
	
	return 0;
}
