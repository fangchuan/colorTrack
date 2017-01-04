#ifndef EASY_TRACER_H
#define EASY_TRACER_H

#define IMG_X 0	           //ͼƬx����
#define IMG_Y 0	           //ͼƬy����
#define IMG_W 320          //ͼƬ���
#define IMG_H 240          //ͼƬ�߶�

#define ALLOW_FAIL_PER 3   //�ݴ��ʣ�û1<<ALLOW_FAIL_PER�����������һ������㣬�ݴ���Խ��Խ����ʶ�𣬵�������Խ��
#define ITERATE_NUM    8   //������������������Խ��ʶ��Խ��ȷ����������Խ��

#define min3v(v1, v2, v3)   ((v1)>(v2)? ((v2)>(v3)?(v3):(v2)):((v1)>(v3)?(v3):(v1)))
#define max3v(v1, v2, v3)   ((v1)<(v2)? ((v2)<(v3)?(v3):(v2)):((v1)<(v3)?(v3):(v1)))

//ʹ�þ���
//RESULT Resu;
//TARGET_CONDI Condition={60,100,20,120,10,160,40,40,320,240};
//Trace(&Condition,&Resu);

typedef struct             //�ж�Ϊ��Ŀ������
{
	unsigned char  H_MIN;    //Ŀ����Сɫ��
	unsigned char  H_MAX;    //Ŀ�����ɫ��	
	
	unsigned char  S_MIN;    //Ŀ����С���Ͷ�  
	unsigned char  S_MAX;    //Ŀ����󱥺Ͷ�

	unsigned char  L_MIN;    //Ŀ����С����  
	unsigned char  L_MAX;    //Ŀ���������

	unsigned int   WIDTH_MIN; //Ŀ����С���
	unsigned int   HIGHT_MIN; //Ŀ����С�߶�

	unsigned int   WIDTH_MAX; //Ŀ�������
	unsigned int   HIGHT_MAX; //Ŀ�����߶�
}TARGET_CONDI;

typedef struct             //ʶ����
{
	unsigned int x;         //Ŀ���x����
	unsigned int y;         //Ŀ���y����
	unsigned int w;         //Ŀ��Ŀ��
	unsigned int h;         //Ŀ��ĸ߶�
}RESULT;

typedef struct                      //RGB��ʽ��ɫ
{
    unsigned char  red;             // [0,255]
    unsigned char  green;           // [0,255]
    unsigned char  blue;            // [0,255]
}COLOR_RGB;


typedef struct                      //HSL��ʽ��ɫ
{
    unsigned char hue;              // [0,240] ɫ��
    unsigned char saturation;       // [0,240] ���Ͷ�
    unsigned char luminance;        // [0,240] ����
}COLOR_HSL;


typedef struct                      //����
{
	unsigned int X_Start;              
	unsigned int X_End;
	unsigned int Y_Start;              
	unsigned int Y_End;
}SEARCH_AREA;

/*���峣����ɫ����ɫ��*/
#define RED 0xf800	//��
#define YELLOW 0xffe0	//��
#define GREEN 0x07e0	//��
#define CYAN 0x07ff	//��
#define BLUE 0x001f	//��
#define PURPLE 0xf81f	//��
#define BLACK 0x0000	//��
#define WHITE 0xffff	//��
#define GRAY 0x7bef	//��

//-----------------------------------------------------------------------------------------
//Ψһ��API���û���ʶ������д��Conditionָ��Ľṹ���У��ú���������Ŀ���x��y����ͳ���
//����1ʶ��ɹ�������1ʶ��ʧ��
//-----------------------------------------------------------------------------------------
int Trace(const TARGET_CONDI *Condition,RESULT *Resu);
void RGBtoHSL(const COLOR_RGB *Rgb, COLOR_HSL *Hsl);
#endif
