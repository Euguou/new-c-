#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
//������ָ�������
#define KONG 12//��
#define QIANG 22//ǽ
#define YAOSHI 32//Կ��
#define SLM 0//ʷ��ķ
#define BF 1//����
#define DOOR 62//��
#define MAN 72//����
#define KEY_SHOP 82//Կ���̵�
#define UP 92//��¥
#define DOWN 102//��¥
#define MEDICINE 122//ҩˮ
#define KULOU 2//����
#define SUPERKULOU 3//���öӳ�
#define SANGSHI 4//ɥʬ
#define SHOP 142//�����̵�
#define STONEA 152//������ʯ
#define STONED 162//������ʯ
#define DDOOR 172//������
#define BDOOR 182//���α��䰵��
#define DLSW 9//��������
#define SWORD 192//����
#define SLMKING 7//ʷ��ķ��
#define SSANGSHI 5//ɥʬսʿ
#define SHIELD 202//����
#define NPCJ 212//�ṩ������Ϣ��npc
#define NPCD 222//�ṩ�ܵ���Ϣ��npc
#define NPCS 232//�������npc
#define MFSW 6//ħ������
#define NPCM 242//npc����
#define QWDATA 252//��������
#define UPP 262//
#define DOWNN 272//����¥��
#define MOWANG 8//ħ��
#define MODATA 282//ħ�������¼���������
#define NPCB 292//����npc
struct room//ÿ�������
{
	int x;
	int y;
	//���ӵ�����������
	int data;
}ro[10][10][10];
int xx,yy,zz;//���ǵ�ǰ����
int hp,attack,defend;//���ǵ�ǰ����
int keys;//Կ������
int money;//Ǯ
int key_price;//Կ�׼۸��湺������ϸ�
int p_price;//�����̵�۸�
int d_key;//����Կ��
int db_key;//���α���Կ��
int qw_task;//�������
int qw_data;//������Ʒ
FILE *fp;//�浵�ļ�ָ��
struct warrior
{
	char *name;
	int hp;
	int attack;
	int defend;
	int money;
}monster[11];//����
struct all
{
	struct room ro[10][10][10];
	struct warrior monster[11];
	int xx,yy,zz;//���ǵ�ǰ����
	int hp,attack,defend;//���ǵ�ǰ����
	int keys;//Կ������
	int money;//Ǯ
	int key_price;//Կ�׼۸��湺������ϸ�
	int p_price;//�����̵�۸�
	int d_key;//����Կ��
	int db_key;//���α���Կ��
	int qw_task;//�������
	int qw_data;//������Ʒ
};
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}//��װgontoxy
void end1()
{
	system("cls");
	gotoxy(60,60);
	printf("�Ӵˣ���ʿ��ħ���������Ҹ��������������");getch();
}
void end2()
{
	system("cls");
	gotoxy(60,60);
	printf("��ʿɱ����ħ�����ɹ��ȳ������������ӡ��Ӵˣ���ʿ�����ӹ������Ҹ��������������");getch();
}
void save()//�浵
{
	struct all al;
	int x,y,z;
	for(z=0;z<10;z++)
		for(x=0;x<10;x++)
			for(y=0;y<10;y++)
				al.ro[z][x][y]=ro[z][x][y];
	for(x=0;x<10;x++)
		al.monster[x]=monster[x];
	al.xx=xx;
	al.yy=yy;
	al.zz=zz;
	al.hp=hp;
	al.attack=attack;
	al.defend=defend;
	al.keys=keys;
	al.money=money;
	al.key_price=key_price;
	al.p_price=p_price;
	al.d_key=d_key;
	al.db_key=db_key;
	al.qw_data=qw_data;
	al.qw_task=qw_task;//����������װ���ṹ��all
	fp=fopen("mtw","wb");
	fwrite(&al,sizeof(struct all),1,fp);
	fclose(fp);
}
void load()//����
{
	struct all al;
	fp=fopen("mtw","rb");
	fread(&al,sizeof(struct all),1,fp);
	fclose(fp);
	int x,y,z;
	for(z=0;z<10;z++)
		for(x=0;x<10;x++)
			for(y=0;y<10;y++)
				ro[z][x][y]=al.ro[z][x][y];
	for(x=0;x<10;x++)
		monster[x]=al.monster[x];
	xx=al.xx;
	yy=al.yy;
	zz=al.zz;
	hp=al.hp;
	attack=al.attack;
	defend=al.defend;
	keys=al.keys;
	money=al.money;
	key_price=al.key_price;
	p_price=al.p_price;
	d_key=al.d_key;
	db_key=al.db_key;
	qw_data=al.qw_data;
	qw_task=al.qw_task;//����������װ���ṹ��all
}
void startp()//���������ʼ����
{
	xx=1;
	yy=9;
	zz=0;
	hp=3000000;
	attack=200000;
	defend=1000;
	money=100000000;
	keys=100000;
	key_price=1;
	p_price=100;
	d_key=10010;
	db_key=1000;
	qw_task=5;
	qw_data=5;
	monster[10].hp=1;
	monster[10].attack=250;
	monster[10].defend=160;
}
void setmonster()//���ù�������	
{
	int i;
	for(i=0;i<10;i++)
	{
		monster[i].hp=50*(i);
		monster[i].attack=15*(i);
		monster[i].defend=5*(i);
		monster[i].money=10+5*(i);
	}
	monster[0];
	monster[1];
	monster[2];
	monster[4];
	monster[5];
	monster[9];
	monster[7];
	monster[6];
	monster[8];
	monster[9].attack=monster[2].attack;
	monster[9].hp=monster[5].hp;
	monster[9].defend=monster[4].defend;
	monster[7].hp*=2;
	monster[7].defend;
	monster[6].hp=1;
	monster[6].attack=9;
	monster[6].defend=5;
	monster[8]=monster[10];
}
void showroom(struct room rr)//�����ͬ����
{
	int i,j;
	switch(rr.data)
	{
	case QIANG:{
		gotoxy(rr.x,rr.y);
		printf("#####");
		gotoxy(rr.x,rr.y+1);
		printf("#####");
		gotoxy(rr.x,rr.y+2);
		printf("#####");
		break;
			   }
	case DOOR:{
		for(i=0;i<3;i++)
		{
			gotoxy(rr.x,(rr.y+i));
			printf("[-|-]");
		}
		gotoxy(rr.x,rr.y+1);
		printf("[o|o]");
		break;
			  }
	case YAOSHI:{
		gotoxy(rr.x+2,rr.y+1);
		printf("K");
		break;
				}
	case SLM:{
		for(i=0;i<3;i++)
		{
			gotoxy(rr.x+1,rr.y+i);
			if(i==1)
				printf("slm");
			else
			printf("OOO");
		}
		break;
			 }
	case BF:{
		gotoxy(rr.x,rr.y);
		printf(" ] [");
		gotoxy(rr.x,rr.y+1);
		printf(" bfu");
		gotoxy(rr.x,rr.y+2);
		printf(" ] [");
		break;
			}
	case MAN:{
		gotoxy(rr.x,rr.y);
		printf("  \2");
		gotoxy(rr.x,rr.y+1);
		printf("-[-]-");
		gotoxy(rr.x,rr.y+2);
		printf(" / \\");
		break;
			 }
	case KEY_SHOP:{
		gotoxy(rr.x,rr.y);
		printf("  \1");
		gotoxy(rr.x,rr.y+1);
		printf(" [-] ");
		gotoxy(rr.x,rr.y+2);
		printf("// \\\\");
		break;
			 }
	case UP:{
		for(i=0;i<3;i++)
		{
			gotoxy(rr.x,(rr.y+i));
			printf("��|��");
		}
		gotoxy(rr.x,rr.y+1);
		printf("��|��");
		break;
			}
	case DOWN:{
		for(i=0;i<3;i++)
		{
			gotoxy(rr.x,(rr.y+i));
			printf("��|��");
		}
		gotoxy(rr.x,rr.y+1);
		printf("��|��");
		break;
			}
	case UPP:{
		for(i=0;i<3;i++)
		{
			gotoxy(rr.x,(rr.y+i));
			printf("��|��");
		}
		gotoxy(rr.x,rr.y+1);
		printf("��|��");
		break;
			}
	case DOWNN:{
		for(i=0;i<3;i++)
		{
			gotoxy(rr.x,(rr.y+i));
			printf("��|��");
		}
		gotoxy(rr.x,rr.y+1);
		printf("��|��");
		break;
			}
	case MEDICINE:{
		gotoxy(rr.x,rr.y);
		printf("  +");
		gotoxy(rr.x,rr.y+1);
		printf(" +++");
		gotoxy(rr.x,rr.y+2);
		printf("  +");
		break;
				  }
	case KULOU:{
		gotoxy(rr.x,rr.y);
		printf("  O");
		gotoxy(rr.x,rr.y+1);
		printf("-----");
		gotoxy(rr.x,rr.y+2);
		printf(" ---");
		break;
			   }
	case SUPERKULOU:{
		gotoxy(rr.x,rr.y);
		printf("  O");
		gotoxy(rr.x,rr.y+1);
		printf("|--[]");
		gotoxy(rr.x,rr.y+2);
		printf(" --");
		break;
				   }
	case SANGSHI:{
		gotoxy(rr.x,rr.y);
		printf("  O");
		gotoxy(rr.x,rr.y+1);
		printf(" -0-");
		gotoxy(rr.x,rr.y+2);
		printf("{} {}");
		break;
				 }
	case SHOP:{
		gotoxy(rr.x -5,rr.y);
		printf("   xxxxxxxxx");
		gotoxy(rr.x-5,rr.y+1);
		printf("[--s  h o  p--]");
		gotoxy(rr.x-5,rr.y+2);
		printf("[_____________]");
		break;
			  }
	case STONEA:{
		gotoxy(rr.x,rr.y);
		printf(" ---");
		gotoxy(rr.x,rr.y+1);
		printf(" |A|");
		gotoxy(rr.x,rr.y+2);
		printf(" ---");
		break;
				}
	case STONED:{
		gotoxy(rr.x,rr.y);
		printf(" ---");
		gotoxy(rr.x,rr.y+1);
		printf(" |D|");
		gotoxy(rr.x,rr.y+2);
		printf(" ___");
		break;
				}
	case DDOOR:{
		gotoxy(rr.x,rr.y);
		printf("-----");
		gotoxy(rr.x,rr.y+1);
		printf("-----");
		gotoxy(rr.x,rr.y+2);
		printf("-----");
		break;
			   }
	case BDOOR:{
		gotoxy(rr.x,rr.y);
		printf("#####");
		gotoxy(rr.x,rr.y+1);
		printf("#####");
		gotoxy(rr.x,rr.y+2);
		printf("#####");
		break;
			   }
	case DLSW:{
		gotoxy(rr.x,rr.y);
		printf("  0");
		gotoxy(rr.x,rr.y+1);
		printf(" ###");
		gotoxy(rr.x,rr.y+2);
		printf("~~~~~");
		break;
			  }
	case SWORD:{
		gotoxy(rr.x,rr.y);
		printf(" _");
		gotoxy(rr.x,rr.y+1);
		printf("-]>>>");
		gotoxy(rr.x,rr.y+2);
		printf(" ~");
		break;
			   }
	case SLMKING:{
		gotoxy(rr.x -5,rr.y-3);
		printf("  /~~~~~~~~~\\");
		gotoxy(rr.x-5,rr.y-2);
		printf(" /~~~~~~~~~~~\\");
		gotoxy(rr.x-5,rr.y-1);
		printf("/~~~~~~~~~~~~~\\");
		gotoxy(rr.x -5,rr.y);
		printf(" /~~~~~~~~~~~\\");
		gotoxy(rr.x-5,rr.y+1);
		printf("/~~~~~~~~~~~~~\\");
		gotoxy(rr.x-5,rr.y+2);
		printf("~~~~~~~~~~~~~~~");
		break;
				 }
	case SSANGSHI:{
		gotoxy(rr.x,rr.y);
		printf("  O");
		gotoxy(rr.x,rr.y+1);
		printf("[]0->");
		gotoxy(rr.x,rr.y+2);
		printf("{} {}");
		break;
				  }
	case SHIELD:{
		gotoxy(rr.x,rr.y);
		printf(" ___");
		gotoxy(rr.x,rr.y+1);
		printf(" [ ]");
		gotoxy(rr.x,rr.y+2);
		printf("  V");
		break;
				}
	case NPCJ:{
		gotoxy(rr.x,rr.y);
		printf("  \1");
		gotoxy(rr.x,rr.y+1);
		printf(" [o]");
		gotoxy(rr.x,rr.y+2);
		printf("// \\\\");
		break;
			  }
	case NPCD:{
		gotoxy(rr.x,rr.y);
		printf("  \2");
		gotoxy(rr.x,rr.y+1);
		printf(" [-] ");
		gotoxy(rr.x,rr.y+2);
		printf("/~~~\\");
		break;
			  }
	case NPCS:{
		gotoxy(rr.x,rr.y);
		printf("  \2");
		gotoxy(rr.x,rr.y+1);
		printf(" [-] ");
		gotoxy(rr.x,rr.y+2);
		printf("/~~~\\");
		break;
			  }
	case MFSW:{	
		gotoxy(rr.x,rr.y);
		printf("  O");
		gotoxy(rr.x,rr.y+1);
		printf(" ^^^ ");
		gotoxy(rr.x,rr.y+2);
		printf("~~~~~");
		break;
			  }
	case NPCM:{	
		gotoxy(rr.x,rr.y);
		printf("  \2");
		gotoxy(rr.x,rr.y+1);
		printf(" --- ");
		gotoxy(rr.x,rr.y+2);
		printf("^^^^^");
		break;
			  }
	case QWDATA:{
		gotoxy(rr.x,rr.y);
		printf("?????");
		gotoxy(rr.x,rr.y+1);
		printf("?????");
		gotoxy(rr.x,rr.y+2);
		printf("?????");
		break;
				}
	case MOWANG:{	
		gotoxy(rr.x,rr.y);
		printf("  \1");
		gotoxy(rr.x,rr.y+1);
		printf(" -O- ");
		gotoxy(rr.x,rr.y+2);
		printf("^^^^^");
		break;
			  }
	case NPCB:{
		gotoxy(rr.x,rr.y);
		printf("  \1");
		gotoxy(rr.x,rr.y+1);
		printf(" [-] ");
		gotoxy(rr.x,rr.y+2);
		printf("/~~~\\");
		break;
			  }
	}
}
int demage(int kind)//�����˺�����
{
	int a;
	if((attack-monster[kind].defend)>0)
		a=(monster[kind].hp/(attack-monster[kind].defend))*(monster[kind].attack-defend);
	else
		a=9999999;
	return a;
}
void showmap()//���������������ͼ�Լ�������Ϣ����
{
	system("cls");
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			showroom(ro[zz][i][j]);
		}
	}
	for(i=0;i<50;i++){
		gotoxy(i,30);
		printf("#");}
	for(j=0;j<30;j++)
	{
		gotoxy(50,j);
		printf("#");
	}
	gotoxy(60,0);
	printf("hp:%d",hp);
	gotoxy(60,2);
	printf("attack:%d     defend:%d",attack,defend);
	gotoxy(60,4);
	printf("keys:%d     money:%d",keys,money);
	gotoxy(60,6);
	printf("o:�鿴�����ֲ�");
	gotoxy(60,7);
	printf("i:�浵");
}
void fight(int kind);//����ս������
void dlsw();//������������ս������
void mfsw();//����ħ������ս������
void key_shop();//Կ���̵�
void qw_taskk();//��������
void upstairs();//��¥
void downstairs();//��¥
void shop();//�̵�
void nextroom(char f)//�Ի�õķ���������жϲ�ִ����һ���е���Ӧ����
{
	int dx=xx;
	int dy=yy;
	switch (f)
	{
	case 'a':dx--;break;
	case 's':dy++;break;
	case 'w':dy--;break;
	case 'd':dx++;break;
	}
	if(dx>=0 && dx<10 && dy>=0 && dy<10)
	{
		switch (ro[zz][dx][dy].data)
		{
		case KONG:ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case MAN:ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case YAOSHI:ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;keys++;break;
		case DOOR:if(keys>0) {ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;keys--;xx=dx;yy=dy;};break;
		case SLM:fight(0);ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case BF:fight(1);ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case KEY_SHOP:key_shop();break;
		case UP:upstairs();break;
		case DOWN:downstairs();break;
		case UPP:upstairs();upstairs();break;
		case DOWNN:downstairs();downstairs();break;
		case MEDICINE:ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;hp+=100;break;
		case KULOU:fight(2);ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case SUPERKULOU:fight(3);ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case SANGSHI:fight(4);ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case SHOP:shop();break;
		case STONEA:attack+=2;ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case STONED:defend+=2;ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case DDOOR:if(d_key>0) {ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;} else {gotoxy(60,10);
			printf("���δ��Ž�����Ҳ������Ҫ���ҵ����ܹ�����");getch();};break;
		case BDOOR:if(db_key>0) {ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;};break;
		case DLSW:ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;dlsw();break;
		case SWORD:attack+=20;ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case SLMKING:fight(7);if(qw_task==1) ro[5][5][5].data=QWDATA;ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case SSANGSHI:fight(5);ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case SHIELD:defend+=20;ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case NPCJ:gotoxy(60,10);printf("��ͽ1���𾴵���ʿ����л����Ӫ�ȡ��ҽ�Ϊ���ṩһ���ش���Ϣ��");getch();
			gotoxy(60,10);printf("�ڵ����Ĺ���Ӫ��һ���ܱշ����������һ�ѷ����ı������ҽ�Ϊ����ͨͨ������ĵ�·��������");
			getch();ro[4][9][3].data=KONG;break;
		case NPCD:gotoxy(60,10);printf("��ͽ2���𾴵���ʿ����л����Ӫ�ȡ��ҽ�Ϊ���ṩһ���ش���Ϣ��");getch();
			gotoxy(60,10);printf("�ڵ��߲�Ļ������ȵľ�ͷ�����һ����ʵ�Ķ��ơ��ҽ�Ϊ����ͨͨ������ĵ�·��������");
			getch();ro[6][6][5].data=KONG;break;
		case NPCS:gotoxy(60,10);printf("С͵���຾�����������ҵ�ģ�");getch();
			gotoxy(60,10);printf("�ҿ���Ϊ����ͨһ������ƿ�6¥�Ǹ���һ��Ҫ998����Ҫ698ֻҪ20����Y/yes,else/no");
			if(getch()=='y') {
				if(money>20)
				{
					int m,n;
				for(m=1,n=0;n<10;n++) 
					ro[5][m][n].data=KONG;
				ro[5][2][0].data=ro[5][2][9].data=KONG;
				money-=20;
				}
				else
					gotoxy(60,12),printf("ûǮ��ѧ�˼ҳ������ԣ�");
			};break;
		case MFSW:ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;mfsw();break;
		case NPCM:qw_taskk();break;
		case QWDATA:qw_data++;ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;break;
		case MOWANG:fight(8);ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;xx=dx;yy=dy;if(qw_task==4) qw_task++,qw_taskk();
			if(qw_task==6) end2();break;
		case MODATA:ro[zz][xx][yy].data=KONG;ro[zz][dx][dy].data=MAN;qw_task++;qw_taskk();break;
		case NPCB:gotoxy(60,10);printf("��ͽ3����л����Ӫ�ȣ����ǽ������ǵĲƸ����׳�����������");money=0;break;
		}
	}
}
int imfor(int i,int kind)//���������Ϣ
{
	setmonster();
	if(kind==6)
	{
		if(ro[8][1][1].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][1][8].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][3][0].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][3][9].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][6][0].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][6][9].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][8][1].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][8][8].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
	}
	int a,b;
	for(a=0;a<10;a++)
	{
	for(b=0;b<10;b++)
		{
			if(ro[zz][a][b].data==kind)
			{
				gotoxy(52,i);
				printf("%s  ������%d  ����:%d  ������%d  ��Ǯ��%d  ���ģ�%d",
					monster[kind].name,monster[kind].hp,monster[kind].attack,monster[kind].defend,monster[kind].money,demage(kind));
				i+=2;
				return i;
			}
		}
	}
	return i;
}
void nextchar(char b)//�жϻ�õ��ַ��Ƿ������������������ָ��
{
	int i=6,j;
	if(b=='w' || b=='s' || b=='a'|| b=='d')
		nextroom(b);
	if(b=='o')
	{
		for(j=0;j<10;j++)
		{
			i=imfor(i,j);
		}
		gotoxy(52,i+2);
		system("pause");
	}
	if(b=='i')
	{
		save();
	}
}//�����һ����������ж�
void map1();//�����һ��
void map2();//����ڶ���
void map3();//���������	
void map4();//������Ĳ�
void map5();//��������
void map6();//���������
void map7();//������߲�
void map8();//����ڰ˲�
void map9();//����ھŲ�
void map10();//�����ʮ��
void mapmake()
{
	map1();
	map2();
	map3();
	map4();
	map5();
	map6();
	map7();
	map8();
	map9();
	map10();
}
int main(void)//������
{
	int a;
	gotoxy(50,6);
	printf("1.�µĿ�ʼ");
	gotoxy(50,8);
	printf("2.�ɵĻ���");
	if(getch()=='2')
	{
		load();
	}
	else
	{
		startp();//��ʼ����������
		mapmake();
	}
	showmap();
	for(; ;)
	{
		nextchar(getch());
		showmap();
		if(hp<0)
			break;
	}
	system("cls");
	system("pause");
	for(a=0;a<100;a++)
		printf("game over!!\n");
	system("pause");
	return 0;
}
void map1()//�����һ��
{
	int a,b,c;
	for(c=0;c<10;c++)
	{
	for(a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			ro[c][a][b].x=a*5;
			ro[c][a][b].y=b*3;
			ro[c][a][b].data=KONG;
		}
	}
	}
	for(a=3,b=1;b<9;b++)
		ro[0][a][b].data=QIANG;
	for(a=5,b=1;b<10;b++)
		ro[0][a][b].data=QIANG;
	for(a=1,b=5;a<3;a++)
		ro[0][a][b].data=QIANG;
	for(a=0,b=8;a<4;a++)
		ro[0][a][b].data=QIANG;
	for(a=7,b=0;b<10;b++)
		ro[0][a][b].data=QIANG;
	for(a=9,b=0;b<7;b++)
		ro[0][a][b].data=QIANG;
	ro[0][7][6].data=KONG;
	ro[0][3][0].data=ro[0][0][5].data=ro[0][8][7].data=ro[0][5][0].data=DOOR;
	ro[0][2][6].data=ro[0][2][7].data=ro[0][2][1].data=ro[0][0][9].data=ro[0][9][7].data=YAOSHI;
	ro[0][1][9].data=MAN;
	ro[0][0][6].data=ro[0][8][8].data=ro[0][4][5].data=ro[0][4][4].data=SLM;
	ro[0][1][0].data=ro[0][0][1].data=ro[0][9][8].data=BF;
	ro[0][0][0].data=KEY_SHOP;
	ro[0][9][0].data=UP;
	ro[0][1][7].data=ro[0][9][9].data=MEDICINE;
	ro[0][0][6].data=ro[0][0][1].data=KULOU;
}
void map2()//����ڶ���
{
	int a,b;
	for(a=0,b=8;a<4;a++)
		ro[1][a][b].data=QIANG;
	for(a=1,b=0;b<9;b++)
		ro[1][a][b].data=QIANG;
	for(a=3,b=0;b<9;b++)
		ro[1][a][b].data=QIANG;
	ro[1][1][4].data=ro[1][3][4].data=KONG;
	for(a=5,b=0;b<10;b++)
		ro[1][a][b].data=QIANG;
	for(a=5,b=4;b<10;b++)
		ro[1][a][b].data=QIANG;
	for(a=7,b=0;b<3;b++)
		ro[1][a][b].data=QIANG;
	ro[1][9][2].data=QIANG;
	for(a=7,b=6;b<10;b++)
		ro[1][a][b].data=QIANG;
	ro[1][9][6].data=QIANG;
	for(a=5,b=4;a<10;a++)
		ro[1][a][b].data=QIANG;
	ro[1][5][5].data=ro[1][7][4].data=ro[1][8][2].data=ro[1][8][6].data=DOOR;
	ro[1][0][7].data=ro[1][2][7].data=YAOSHI;
	ro[1][0][9].data=DOWN;
	ro[1][6][9].data=UP;
	ro[1][3][9].data=ro[1][0][6].data=ro[1][0][2].data=ro[1][6][7].data=SLM;
	ro[1][2][2].data=ro[1][2][6].data=BF;
	ro[1][0][0].data=STONEA;
	ro[1][2][0].data=STONED;
	ro[1][6][0].data=ro[1][6][1].data=MEDICINE;
	ro[1][6][2].data=KULOU;
	ro[1][8][7].data=SUPERKULOU;
	ro[1][8][3].data=SANGSHI;
	ro[1][9][0].data=DLSW;
	ro[1][9][9].data=NPCS;
}
void map3()//������
{
	int a,b;
	for(a=0,b=1;a<4;a++)
		ro[2][a][b].data=QIANG;
	for(a=3,b=2;b<9;b++)
		ro[2][a][b].data=QIANG;
	for(a=5,b=0;b<10;b++)
		ro[2][a][b].data=QIANG;
	for(a=6,b=4;a<10;a++)
		ro[2][a][b].data=QIANG;
	for(a=6,b=6;a<10;a++)
		ro[2][a][b].data=QIANG;
	ro[2][5][5].data=KONG;
	ro[2][1][6].data=ro[2][3][9].data=ro[2][6][6].data=ro[2][6][4].data=DOOR;
	ro[2][1][4].data=ro[2][1][5].data=ro[2][2][7].data=ro[2][4][2].data=ro[2][8][2].data=ro[2][7][1].data=BF;
	ro[2][2][9].data=ro[2][4][8].data=ro[2][7][0].data=ro[2][7][5].data=SLM;
	ro[2][0][7].data=YAOSHI;
	ro[2][1][2].data=SHOP;
	ro[2][6][3].data=ro[2][9][2].data=KULOU;
	ro[2][6][7].data=SUPERKULOU;
	ro[2][0][0].data=DOWN;
	ro[2][9][5].data=UP;
	ro[2][8][1].data=ro[2][8][9].data=ro[2][9][0].data=ro[2][9][8].data=MEDICINE;
	ro[2][0][3].data=ro[2][0][6].data=ro[2][2][6].data=ro[2][2][3].data=QIANG;
	ro[2][8][0].data=ro[2][8][8].data=STONEA;
	ro[2][9][1].data=ro[2][9][9].data=STONED;
}
void map4()//���Ĳ�
{
	int a,b;
	for(a=0,b=4;a<10;a++)
		ro[3][a][b].data=QIANG;
	for(a=0,b=6;a<10;a++)
		ro[3][a][b].data=QIANG;
	for(a=3,b=0;b<10;b++)
		ro[3][a][b].data=QIANG;
	for(a=6,b=0;b<10;b++)
		ro[3][a][b].data=QIANG;
	ro[3][1][4].data=ro[3][1][6].data=ro[3][8][4].data=ro[3][8][6].data=DDOOR;
	ro[3][4][4].data=ro[3][5][4].data=ro[3][4][6].data=ro[3][5][6].data=BDOOR;
	ro[3][8][0].data=ro[3][8][1].data=ro[3][9][1].data=BF;
	ro[3][8][9].data=ro[3][8][8].data=ro[3][9][8].data=SLM;
	ro[3][0][1].data=ro[3][1][0].data=ro[3][1][1].data=SUPERKULOU;
	ro[3][0][8].data=ro[3][1][8].data=ro[3][1][9].data=KULOU;
	ro[3][4][2].data=ro[3][5][2].data=ro[3][4][3].data=ro[3][5][3].data=ro[3][4][7].data
		=ro[3][4][8].data=ro[3][5][7].data=ro[3][5][8].data=MEDICINE;
	ro[3][4][0].data=ro[3][4][1].data=ro[3][5][9].data=STONEA;
	ro[3][5][0].data=ro[3][5][1].data=ro[3][4][9].data=STONED;
	ro[3][3][5].data=ro[3][6][5].data=KONG;
	ro[3][0][5].data=UP;
	ro[3][9][5].data=DOWN;
	ro[3][9][9].data=NPCJ;
	ro[3][9][0].data=NPCD;
	ro[3][0][0].data=NPCM;
	ro[3][0][9].data=NPCB;
}
void map5()
{
	int a,b;
	for(a=1,b=0;b<5;b++)
		ro[4][a][b].data=QIANG;
	for(a=4,b=0;b<10;b++)
		ro[4][a][b].data=QIANG;
	for(a=6,b=0;b<9;b++)
		ro[4][a][b].data=QIANG;
	for(a=1,b=4;a<5;a++)
		ro[4][a][b].data=QIANG;
	for(a=6,b=3;a<10;a++)
		ro[4][a][b].data=QIANG;
	for(a=6,b=5;a<10;a++)
		ro[4][a][b].data=QIANG;
	for(a=6,b=8;a<10;a++)
		ro[4][a][b].data=QIANG;
	for(a=0,b=6;a<5;a++)
		ro[4][a][b].data=QIANG;
	ro[4][4][5].data=ro[4][6][4].data=KONG;
	ro[4][2][4].data=ro[4][4][9].data=ro[4][9][5].data=DOOR;
	for(a=7,b=0;b<3;a++,b++)
		ro[4][a][b].data=BF;
	for(a=7,b=6;a<10;a++)
		ro[4][a][b].data=BF;
	ro[4][2][2].data=ro[4][3][2].data=ro[4][2][7].data=ro[4][2][8].data=ro[4][1][9].data=ro[4][0][9].data=ro[4][9][7].data=ro[4][3][5].data=BF;
	ro[4][1][8].data=ro[4][5][0].data=ro[4][5][1].data=YAOSHI;
	ro[4][0][7].data=ro[4][7][7].data=ro[4][8][4].data=MEDICINE;
	ro[4][2][9].data=ro[4][3][8].data=ro[4][3][7].data=ro[4][5][7].data=ro[4][2][3].data=ro[4][3][3].data=SLM;
	ro[4][3][9].data=ro[4][2][1].data=ro[4][3][1].data=KULOU;
	ro[4][5][2].data=ro[4][8][0].data=ro[4][9][1].data=SUPERKULOU;
	ro[4][1][7].data=ro[4][2][0].data=ro[4][8][7].data=STONEA;
	ro[4][0][8].data=ro[4][3][0].data=STONED;
	ro[4][7][4].data=BF;
	ro[4][0][0].data=DOWN;
	ro[4][9][9].data=UP;
	ro[4][9][0].data=SWORD;
}
void map6()
{
	int a,b;
	for(a=0;a<3;a++)
	{
		for(b=0;b<10;b++)
			ro[5][a][b].data=QIANG;
	}
	for(a=6;a<10;a++)
	{
		for(b=0;b<10;b++)
			ro[5][a][b].data=QIANG;
	}
	ro[5][4][0].data=UP;
	ro[5][4][9].data=DOWN;
	ro[5][4][3].data=SLMKING;
	ro[5][3][3].data=ro[5][5][3].data=1234;
}
void map7()
{
	int a,b;
	for(a=8,b=1;b<10;b++)
		ro[6][a][b].data=QIANG;
	for(a=1,b=1;a<9;a++)
		ro[6][a][b].data=QIANG;
	for(a=1,b=1;b<9;b++)
		ro[6][a][b].data=QIANG;
	for(a=1,b=8;a<7;a++)
		ro[6][a][b].data=QIANG;
	for(a=6,b=3;b<9;b++)
		ro[6][a][b].data=QIANG;
	for(a=3,b=3;a<7;a++)
		ro[6][a][b].data=QIANG;
	for(a=3,b=3;b<7;b++)
		ro[6][a][b].data=QIANG;
	for(a=3,b=6;a<7;a++)
		ro[6][a][b].data=QIANG;
	ro[6][9][9].data=DOWN;
	ro[6][5][7].data=UPP;
	ro[6][9][7].data=ro[6][9][5].data=ro[6][0][6].data=SLM;
	ro[6][9][3].data=ro[6][9][1].data=ro[6][5][0].data=ro[6][3][0].data=ro[6][0][4].data=BF;
	ro[6][1][0].data=ro[6][0][2].data=KULOU;
	ro[6][0][8].data=ro[6][1][9].data=ro[6][4][2].data=ro[6][2][4].data=SUPERKULOU;
	ro[6][5][9].data=ro[6][7][6].data=ro[6][2][7].data=SANGSHI;
	ro[6][2][5].data=ro[6][3][7].data=MEDICINE;
	ro[6][8][0].data=STONEA;
	ro[6][3][9].data=STONED;
	ro[6][2][4].data=SSANGSHI;
	ro[6][5][4].data=SHIELD;
	ro[6][5][5].data=ro[6][4][4].data=SANGSHI;
	ro[6][4][5].data=QWDATA;
}
void map8()
{
	int a,b;
	for(a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
			ro[7][a][b].data=QIANG;
	}
	for(a=0;a<2;a++)
	{
		for(b=0;b<2;b++)
			ro[7][a][b].data=STONEA;
	}
	for(a=8;a<10;a++)
	{
		for(b=0;b<2;b++)
			ro[7][a][b].data=STONED;
	}
	for(a=0;a<2;a++)
	{
		for(b=8;b<10;b++)
			ro[7][a][b].data=YAOSHI;
	}
	for(a=8;a<10;a++)
	{
		for(b=8;b<10;b++)
			ro[7][a][b].data=MEDICINE;
	}
	for(a=0,b=3;a<4;a++)
		ro[7][a][b].data=KULOU;
	for(a=6;a<10;a++)
		ro[7][a][b].data=KULOU;
	for(a=0,b=6;a<4;a++)
		ro[7][a][b].data=SLM;
	for(a=6;a<10;a++)
		ro[7][a][b].data=SLM;
	for(a=3,b=0;b<3;b++)
		ro[7][a][b].data=KULOU;
	for(a=6,b=0;b<3;b++)
		ro[7][a][b].data=KULOU;
	for(a=3,b=7;b<10;b++)
		ro[7][a][b].data=SLM;
	for(a=6,b=7;b<10;b++)
		ro[7][a][b].data=SLM;
	for(a=0;a<3;a++)
	{
		for(b=4;b<6;b++)
			ro[7][a][b].data=KONG;
	}
	for(a=7;a<10;a++)
	{
		for(b=4;b<6;b++)
			ro[7][a][b].data=KONG;
	}
	ro[7][1][5].data=ro[7][8][5].data=SLMKING;
	ro[7][0][5].data=ro[7][2][5].data=ro[7][7][5].data=ro[7][9][5].data=1234;
	ro[7][2][0].data=ro[7][7][0].data=ro[7][0][7].data=ro[7][9][7].data=SUPERKULOU;
	ro[7][4][9].data=UP;
	ro[7][5][9].data=DOWN;
	ro[7][3][9].data=ro[7][6][9].data=KONG;
	ro[7][4][1].data=ro[7][5][1].data=SSANGSHI;
}
void map9()
{
	int a,b;
	for(a=0;a<10;a++)
	{
		for(b=0;b<4;b++)
			ro[8][a][b].data=QIANG;
	}
	for(a=0;a<10;a++)
	{
		for(b=6;b<10;b++)
			ro[8][a][b].data=QIANG;
	}
	ro[8][1][1].data=ro[8][3][0].data=ro[8][6][0].data=ro[8][8][1].data=SLM;
	ro[8][1][2].data=ro[8][8][2].data=ro[8][1][7].data=ro[8][8][7].data=SUPERKULOU;
	ro[8][3][1].data=ro[8][3][2].data=ro[8][3][8].data=ro[8][3][7].data=KULOU;
	ro[8][6][1].data=ro[8][6][2].data=ro[8][6][8].data=ro[8][6][7].data=KULOU;
	ro[8][1][8].data=ro[8][3][9].data=ro[8][6][9].data=ro[8][8][8].data=BF;
	for(a=1;a<10;a+=7)
	{
		for(b=3;b<9;b+=3)
			ro[8][a][b].data=DOOR;
	}
	for(a=3;a<8;a+=3)
	{
		for(b=3;b<9;b+=3)
			ro[8][a][b].data=KONG;
	}
	ro[8][0][4].data=DOWNN;
	ro[8][9][5].data=MFSW;
}
void map10()
{
	int a,b;
	for(a=0;a<4;a++)
	{
		for(b=0;b<10;b++)
			ro[9][a][b].data=QIANG;
	}
	for(a=6;a<10;a++)
	{
		for(b=0;b<10;b++)
			ro[9][a][b].data=QIANG;
	}
	ro[9][4][0].data=DOWN;
	ro[9][5][1].data=MODATA;
	ro[9][4][3].data=MOWANG;
}
void fight(int kind)//ս������
{
	setmonster();
	if(kind==6)
	{
		if(ro[8][1][1].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][1][8].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][3][0].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][3][9].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][6][0].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][6][9].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][8][1].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
		if(ro[8][8][8].data==KONG)
			monster[6].hp-=1000,monster[6].attack-=100,monster[6].defend-=50;
	}
	hp=500000;
	for(;monster[kind].hp>0 && hp>0;)
	{
		gotoxy(60,6);
		printf("=======================================");
		gotoxy(60,7);
		printf("|                                     |");
		gotoxy(60,8);
		printf("|                                     |");
		gotoxy(60,8);
		printf("|   %s  hp:%d",monster[kind].name,monster[kind].hp);
		gotoxy(60,9);
		printf("|                                     |");
		gotoxy(60,10);
		printf("|                                     |");
		gotoxy(60,10);
		printf("| attack:%d   defend:%d",monster[kind].attack,monster[kind].defend);
		gotoxy(60,11);
		printf("|                                     |");
		gotoxy(60,12);
		printf("=======================================");		
		gotoxy(60,12);
		printf("=======================================");
		gotoxy(60,13);
		printf("|                                     |");
		gotoxy(60,14);
		printf("|                                     |");
		gotoxy(60,14);
		printf("|  ��ʿ  hp:%d",hp);
		gotoxy(60,15);
		printf("|                                     |");
		gotoxy(60,16);
		printf("|                                     |");
		gotoxy(60,16);
		printf("|attack:%d   defend:%d",attack,defend);
		gotoxy(60,17);
		printf("|                                     |");
		gotoxy(60,18);
		printf("=======================================");
		Sleep(500);
		hp-=(monster[kind].attack-defend);
		monster[kind].hp-=(attack-monster[kind].defend);
	}
	money+=monster[kind].money;
}
void key_shop()//Կ���̵�npc����
{
	gotoxy(60,10);
	printf("Կ�����ˣ�����Կ��$%dһ��,�Ƿ���~��Y����/else�˳�",key_price);
	if(getch()=='y')
	{
		if(money>=key_price)
		{
			money-=key_price;
			keys++;
			key_price+=5;
		}
		else
		{
			gotoxy(60,12);
			printf("����Ͳ�Ҫ���ԣ���");
		}
	}
}
void upstairs()//��¥
{
	ro[zz][xx][yy].data=KONG;
	zz++;
	int l_x,l_y;
	for(l_x=0;l_x<10;l_x++)
	{
		for(l_y=0;l_y<10;l_y++)
		{
			if(ro[zz][l_x][l_y].data==DOWN || ro[zz][l_x][l_y].data==DOWNN)
			{
				goto find_down;
			}
		}
	}
find_down:if(ro[zz][l_x+1][l_y].data==KONG && l_x<9)
			  xx=l_x+1,yy=l_y;
		  else if(ro[zz][l_x-1][l_y].data==KONG && l_x>0)
			  xx=l_x-1,yy=l_y;
		  else if(ro[zz][l_x][l_y-1].data==KONG && l_y>0)
			  xx=l_x,yy=l_y-1;
		  else
			  xx=l_x,yy=l_y+1;
		  ro[zz][xx][yy].data=MAN;
}
void downstairs()//��¥
{
	ro[zz][xx][yy].data=KONG;
	zz--;
	int l_x,l_y;
	for(l_x=0;l_x<10;l_x++)
	{
		for(l_y=0;l_y<10;l_y++)
		{
			if(ro[zz][l_x][l_y].data==UP || ro[zz][l_x][l_y].data==UPP)
			{
				goto find_up;
			}
		}
	}
find_up:if(ro[zz][l_x+1][l_y].data==KONG && l_x<9)
			  xx=l_x+1,yy=l_y;
		  else if(ro[zz][l_x-1][l_y].data==KONG && l_x>0)
			  xx=l_x-1,yy=l_y;
		  else if(ro[zz][l_x][l_y-1].data==KONG && l_y>0)
			  xx=l_x,yy=l_y-1;
		  else
			  xx=l_x,yy=l_y+1;
		  ro[zz][xx][yy].data=MAN;
}
void shop()
{
	
	for(;;)
	{
		showmap();
		gotoxy(60,10);
		printf("�����̵꣺�����Ի��ѣ�%d������һ��������",p_price);
		gotoxy(60,12);
		printf("1.����ֵ+400    2.������+3      3.������+3");
		gotoxy(60,14);
		switch (getch())
		{
		case '1':{
			if(money>=p_price)
				hp+=200,money-=p_price,p_price+=2;
			else
			{
				printf("ûǮ�������ԣ�");
				goto exit;
			}
			break;
				 }
		case '2':{
			if(money>=p_price)
				attack+=2,money-=p_price,p_price+=2;
			else
			{
				printf("ûǮ��ѧ�˼����ԣ�");
				goto exit;
			}
			break;
				 }
		case '3':{
			if(money>=p_price)
				defend+=2,money-=p_price,p_price+=2;
			else
			{
				printf("ûǮ��ѧ�˼����ԣ�");
				goto exit;
			}
			break;
				 }
		default:goto exit;
		}
	}
exit:;
}
void dlsw()
{
	fight(9);
	d_key++;
	ro[1][8][0].data=ro[1][8][1].data=ro[1][9][1].data=MEDICINE;
}
void mfsw()
{
	fight(6);
	ro[8][9][4].data=UP;
}
void qw_taskk()
{
	if(qw_task==0)
	{
		gotoxy(60,10);
		printf("��ͽ0������������ħ���İɣ�Ը����Ҽ���æ��?��Ϊ�����ҿ��Ը�������ħ��ʵ���ķ�����y/yes,else/no");
		if(getch()=='y')
			qw_task++,qw_taskk();
	}
	if(qw_task==1)
	{
		if(qw_data==0)
		{
			gotoxy(60,10);
			printf("��ͽ0������ǰ���������Ⱦ�ͷ�������ڣ������������õ�һ���������������ħ��ȡ���ش����ã���ȥ����ʿ��");getch();
		}
		else
		{
			qw_data--,qw_task++;
			gotoxy(60,10);
			printf("��ͽ0�������������ô��������ǰ��ʷ��ķ�����ص�ͨ���ؿ�������ʷ��ķ���ûصڶ������Ȼ��������Ұɣ�");getch();
			gotoxy(60,12);
			printf("attack up!!");
			attack+=20;
		}
	}
	if(qw_task==2)
	{
		if(qw_data==0)
		{
			gotoxy(60,10);
			printf("��ͽ0������ȡ��������");
		}
		else
		{
			if(qw_data==1)
				defend+=20,gotoxy(60,14),printf("defend up!!");
			qw_data--;
			qw_task++;
			gotoxy(60,10);
			printf("��ͽ0���ܺã���������������ҿ��԰����ڵ��߲�������Ⱦ�ͷ��ͨ�����صĵڰ˲�ر����ͨ����");
			ro[6][4][5].data=UP;
			gotoxy(60,12);
			printf("��ͽ0����ʱ����Ϊ�����ľ�����Щ�ˣ�������ħ����ս��ʱ���һ��ٳ��ֵģ�");
			getch();
		}
	}
	if(qw_task==4)
	{
		ro[9][5][3].data=NPCM;
		gotoxy(60,10);
		printf("��ͽ0������������ҵ���������ҿ��԰����ס��һ��ʵ������ʣ�����Ŀ�����ˣ���");
		gotoxy(60,12);getch();
		printf("ħ�����������㣡����");getch();
		ro[9][5][8].data=KONG;
		ro[3][0][0].data=KONG;
		monster[10].hp/=2;
		monster[10].attack/=2;
		monster[10].defend/=2;
	}
	if(qw_task==5)
	{
		ro[9][5][3].data=KONG;
		ro[9][4][2].data=MOWANG;
		gotoxy(60,10);
		printf("��ͽ0���������������������ħ���������ˣ�������λ���������ڼ�����ʮ�꣡���ڱ��Ҷ���������ҵ�һ�У���");
		getch();
		gotoxy(60,12);
		printf("��ħ������ͽ0�������أ����ϣ��������ǻ���y/yes,else/no");
		if(getch()=='y')
			end1();
		else
		{
			qw_task++;
			monster[10].hp*=3;
			monster[10].attack*=3;
			monster[10].defend*=3;
		}
	}
}
