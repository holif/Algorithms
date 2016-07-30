/***农夫过河问题***/
#include<stdio.h>
#include<stdlib.h>
#define  MAXNUM   20

typedef int DataType;

struct  SeqQueue {      // 顺序队列类型定义
    int  f, r;	//队首、队尾
    DataType q[MAXNUM];
};

typedef struct SeqQueue * PSeqQueue;    // 重定义队列指针类型名

PSeqQueue createEmptyQueue_seq() {	 //创建一个空队列
    PSeqQueue paqu = (PSeqQueue)malloc(sizeof(struct SeqQueue));
    if (paqu == NULL)
        printf("Out of space!! \n");// 存储分配失败
    else
        paqu->f = paqu->r = 0;
    return (paqu);
}

int isEmptyQueue_seq( PSeqQueue paqu ) {	//判断队列是否为空
    return paqu->f == paqu->r;
}
// 将元素x插在队尾
void  enQueue_seq( PSeqQueue paqu, DataType x ) {
    if ( (paqu->r + 1) % MAXNUM == paqu->f  )
        printf( "Full queue.\n" );
    else {
        paqu->q[paqu->r] = x;
        paqu->r = (paqu->r + 1) % MAXNUM;
    }
}
// 删除队列头部元素
void  deQueue_seq( PSeqQueue paqu ) {
    if( paqu->f == paqu->r )
        printf( "Empty Queue.\n" );
    else
        paqu->f = (paqu->f + 1) % MAXNUM;
}
// 队首状态
DataType  frontQueue_seq( PSeqQueue paqu ) {
    return (paqu->q[paqu->f]);
}
/*
	使用4个二进制位0/1表示状态
	从高位到地位分别表示农夫、狼、羊和白菜
	0000表示均在左岸，1111表示均在右岸
	二进制0x08即1000
	0x08----1000
	0x04----0100
	0x02----0010
	0x01----0001
	以下是个体状态判断函数farmer()、wolf()、cabbage()、goat()返回0/1表示左岸/右岸
*/
int farmer(int location) {
    return 0 != (location & 0x08);	//判断农夫的位置
}
int wolf(int location) {
    return 0 != (location & 0x04);	//判断狼的位置
}
int goat(int location) {
    return 0 !=(location & 0x02);	//判断羊的位置
}
int cabbage(int location) {
    return 0 != (location & 0x01);	//判断白菜的位置
}


//安全状态的判断函数
int safe(int location) {
    // 若状态安全则返回true
    if ((goat(location) == cabbage(location)) && (goat(location) != farmer(location)) )	 // 羊吃白菜
        return 0;

    if ((goat(location) == wolf(location)) && (goat(location) != farmer(location)))	 // 狼吃羊
        return 0;
    return 1;   // 其他状态是安全的
}
//将十进制数val转化为二进制输出
void printbinary(int val) {
    for(int i = 3; i >= 0; i--) {
        if(val & (1 << i))
            printf("1");
        else
            printf("0");
    }
}

void farmerProblem() {

    int movers, i, location, newlocation;
    int route[16],temproute[16],temp=0;       //用于记录已考虑的状态路径
    //route数组的作用是储存位置状态的值，

    PSeqQueue moveTo;	//用于记录可以安全到达的中间状态

    moveTo = createEmptyQueue_seq( );//创建空队列
    enQueue_seq(moveTo, 0x00);	//初始状态进队列

    for (i = 0; i < 16; i++)
        route[i] = -1;

    //准备数组route初值
    route[0]=0;

    while (!isEmptyQueue_seq(moveTo)&&(route[15] == -1)) {
        location = frontQueue_seq(moveTo);		 //取队首状态为当前状态
        deQueue_seq(moveTo);
        for (movers = 1; movers <= 8; movers <<= 1) { //考虑各种物品移动
            if ((0 != (location & 0x08)) == (0 != (location & movers))) {	 //农夫与移动的物品在同一侧
                newlocation = location^(0x08|movers);	//异或计算新状态 如初始状态下为 0000^(1000|0001) = 1001
                if (safe(newlocation) && (route[newlocation] == -1)) {	//新状态安全且未处理
                    route[newlocation] = location;		//记录新状态的前驱
                    enQueue_seq(moveTo, newlocation);	//新状态入队
                }
            }
        }
    }
    //到达最终状态
    if(route[15] != -1) {
        printf("The reverse path is : \n");
        for(location = 15; location >= 0; location = route[location]) {
            temproute[temp]=location;
            ++temp;
            printf("The location is : %d\n",location);
            if (location == 0) {
                for(temp=7; temp>=0; --temp) {
                    //printf("%d\n",temproute[temp]);
                    printbinary(temproute[temp]);
                    printf("\n");
                }
                return;
            }
        }
    } else
        printf("No solution.\n");
}

int main() {
    farmerProblem();
    return 0;
}

