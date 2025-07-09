#ifndef __OLED_DATA_H
#define __OLED_DATA_H

#include "Platform_Types.h"

/*中文字符字节宽度*/
#define OLED_CHN_CHAR_WIDTH			3		//UTF-8编码格式给3，GB2312编码格式给2

/*字模基本单元*/
typedef struct 
{
	uint8 Data[32];						//字模数据
	char Index[OLED_CHN_CHAR_WIDTH + 1];	//汉字索引
} ChineseCell_t;

/*ASCII字模数据声明*/
extern const uint8 OLED_F8x16[][16];
extern const uint8 OLED_F6x8[][6];

/*汉字字模数据声明*/
extern const ChineseCell_t OLED_CF16x16[];


/*图像数据声明*/
// extern const uint8 Diode[];
/*按照上面的格式，在这个位置加入新的图像数据声明*/
// extern const uint8 Cursor[];
// extern const uint8 goutou[];
// extern const uint8 Wallpaper[];

//...
	
#endif