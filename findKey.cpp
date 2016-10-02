#include<stdio.h>
#define ROW 4
#define COL 4
bool Find(int array[][COL], int key){
    int i = 0, j = COL - 1;
    int temp = array[i][j];
    while (true){
        if (temp == key)
            return true;
        else if (temp < key && i < ROW - 1)
            temp = array[++i][j];
        else if (temp > key && j > 0)
            temp = array[i][--j];
        else
            return false;
    }
}
int main(){
	int matrix[][4] = {{1,2,8,9}, {2,4,9,12},{4,7,10,13},{6,8,11,15}};
	if(Find(matrix,7)){
		printf("Find");
	}else{
		printf("Not Find");
	}
	return 0;
}
