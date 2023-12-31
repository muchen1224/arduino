
//汉字信息库
/**********************************************************************
 * 使用取模软件：PCTOLCD 2002完美版 
 * 取模方式为：阴码，逐行式，逆向  
 * 字体：16X16
***********************************************************************/

const uint8_t ben[] PROGMEM=
{0x08,0x02,0x08,0x02,0xFC,0x7E,0x12,0x09,0xA1,0x10,0x80,0x00,0xFE,0x3F,0xC0,0x01,
 0xA0,0x02,0x90,0x04,0x88,0x08,0xF4,0x17,0x83,0x60,0x80,0x00,0x80,0x00,0x80,0x00};//笨

const uint8_t niao[] PROGMEM=
{0x80,0x00,0x40,0x00,0xF8,0x0F,0x08,0x08,0x48,0x08,0x88,0x08,0x88,0x0A,0x08,0x04,
 0x08,0x00,0xF8,0x3F,0x00,0x20,0x00,0x20,0xFE,0x27,0x00,0x20,0x00,0x14,0x00,0x08};//鸟

const uint8_t yuan[] PROGMEM=
{0x00,0x00,0xC4,0x1F,0x08,0x00,0x08,0x00,0x00,0x00,0xE0,0x3F,0x8F,0x04,0x88,0x04,
 0x88,0x04,0x88,0x04,0x88,0x24,0x48,0x24,0x48,0x24,0x28,0x38,0x14,0x00,0xE2,0x7F};//远

const uint8_t cheng[] PROGMEM=
{0x10,0x00,0xB8,0x3F,0x8F,0x20,0x88,0x20,0x88,0x20,0xBF,0x3F,0x08,0x00,0x0C,0x00,
 0x9C,0x7F,0x2A,0x04,0x2A,0x04,0x89,0x3F,0x08,0x04,0x08,0x04,0xC8,0x7F,0x08,0x00};//程
 
const uint8_t kai[] PROGMEM=
{0x00,0x00,0xFE,0x3F,0x10,0x04,0x10,0x04,0x10,0x04,0x10,0x04,0x10,0x04,0xFF,0x7F,
 0x10,0x04,0x10,0x04,0x10,0x04,0x10,0x04,0x08,0x04,0x08,0x04,0x04,0x04,0x02,0x04};//开
 
const uint8_t guan[] PROGMEM=
{0x08,0x08,0x10,0x08,0x10,0x04,0x00,0x00,0xFC,0x1F,0x80,0x00,0x80,0x00,0x80,0x00,
 0xFF,0x7F,0x80,0x00,0x40,0x01,0x40,0x01,0x20,0x02,0x10,0x04,0x0C,0x18,0x03,0x60};//关
 
const uint8_t deng[] PROGMEM=
{0x08,0x00,0x08,0x00,0xC8,0x7F,0x08,0x04,0x2A,0x04,0x1A,0x04,0x0A,0x04,0x09,0x04,
 0x08,0x04,0x08,0x04,0x08,0x04,0x14,0x04,0x24,0x04,0x22,0x04,0x02,0x05,0x01,0x02};//灯

const uint8_t jin[] PROGMEM=
{0x80,0x00,0x80,0x00,0x40,0x01,0x20,0x02,0x10,0x04,0x48,0x08,0x84,0x10,0x83,0x60,
 0x00,0x00,0xF8,0x0F,0x00,0x08,0x00,0x04,0x00,0x04,0x00,0x02,0x00,0x01,0x80,0x00};//今

const uint8_t ming[] PROGMEM=
{0x00,0x00,0x00,0x3F,0x3E,0x21,0x22,0x21,0x22,0x21,0x22,0x3F,0x3E,0x21,0x22,0x21,
 0x22,0x21,0x22,0x3F,0x3E,0x21,0x22,0x21,0x80,0x20,0x80,0x20,0x40,0x28,0x20,0x10};//明

const uint8_t hou[] PROGMEM=
{0x00,0x08,0x00,0x1F,0xF8,0x00,0x08,0x00,0x08,0x00,0xF8,0x7F,0x08,0x00,0x08,0x00,
 0x08,0x00,0xE8,0x1F,0x28,0x10,0x24,0x10,0x24,0x10,0x22,0x10,0xE1,0x1F,0x20,0x10};//后

const uint8_t tian[] PROGMEM=
{0x00,0x00,0xFC,0x1F,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xFF,0x7F,0x80,0x00,
 0x40,0x01,0x40,0x01,0x20,0x02,0x20,0x02,0x10,0x04,0x08,0x08,0x04,0x10,0x03,0x60};//天

const uint8_t nian[] PROGMEM=
{0x08,0x00,0x08,0x00,0xF8,0x3F,0x04,0x01,0x04,0x01,0x02,0x01,0xF8,0x1F,0x08,0x01,
 0x08,0x01,0x08,0x01,0xFF,0x7F,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01};//年

const uint8_t yue[] PROGMEM=
{0x00,0x00,0xF8,0x1F,0x08,0x10,0x08,0x10,0x08,0x10,0xF8,0x1F,0x08,0x10,0x08,0x10,
 0x08,0x10,0xF8,0x1F,0x08,0x10,0x08,0x10,0x04,0x10,0x04,0x10,0x02,0x14,0x01,0x08};//月

const uint8_t ri[] PROGMEM=
{0x00,0x00,0xF8,0x0F,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0x0F,
 0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0x0F,0x08,0x08};//日

const uint8_t xing[] PROGMEM=
{0x00,0x00,0xF8,0x0F,0x08,0x08,0xF8,0x0F,0x08,0x08,0xF8,0x0F,0x80,0x00,0x88,0x00,
 0xF8,0x1F,0x84,0x00,0x82,0x00,0xF8,0x0F,0x80,0x00,0x80,0x00,0xFE,0x3F,0x00,0x00};//星

const uint8_t qi[] PROGMEM=
{0x44,0x00,0x44,0x3E,0xFE,0x22,0x44,0x22,0x44,0x22,0x7C,0x3E,0x44,0x22,0x44,0x22,
 0x7C,0x22,0x44,0x3E,0x44,0x22,0xFF,0x22,0x20,0x21,0x44,0x21,0x82,0x28,0x41,0x10};//期

const uint8_t yi[] PROGMEM=
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};//一

const uint8_t er[] PROGMEM=
{0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00};//二

const uint8_t san[] PROGMEM=
{0x00,0x00,0x00,0x00,0xFE,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x1F,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00};//三

const uint8_t si[] PROGMEM=
{0x00,0x00,0x00,0x00,0xFE,0x3F,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0x22,
 0x12,0x22,0x12,0x3C,0x0A,0x20,0x06,0x20,0x02,0x20,0xFE,0x3F,0x02,0x20,0x00,0x00};//四

const uint8_t wu[] PROGMEM=
{0x00,0x00,0xFE,0x3F,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0xFC,0x0F,0x20,0x08,
 0x20,0x08,0x20,0x08,0x20,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0xFF,0x7F,0x00,0x00};//五

const uint8_t liu[] PROGMEM=
{0x40,0x00,0x80,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0xFF,0x7F,0x00,0x00,0x00,0x00,
 0x20,0x02,0x20,0x04,0x10,0x08,0x10,0x10,0x08,0x10,0x04,0x20,0x02,0x20,0x00,0x00};//六

const uint8_t xi[] PROGMEM=
{0x00,0x00,0xFF,0x7F,0x20,0x02,0x20,0x02,0x20,0x02,0xFC,0x1F,0x24,0x12,0x24,0x12,
 0x24,0x12,0x24,0x12,0x14,0x1C,0x0C,0x10,0x04,0x10,0x04,0x10,0xFC,0x1F,0x04,0x10};//西

const uint8_t an[] PROGMEM=
{0x40,0x00,0x80,0x00,0xFC,0x3F,0x04,0x20,0x42,0x10,0x40,0x00,0x40,0x00,0xFF,0x7F,
 0x20,0x04,0x10,0x04,0x18,0x02,0x60,0x02,0x80,0x01,0x40,0x06,0x30,0x08,0x0E,0x10};//安

const uint8_t qing[] PROGMEM=
{0x00,0x04,0x00,0x04,0xDE,0x7F,0x12,0x04,0x92,0x3F,0x12,0x04,0xD2,0x7F,0x1E,0x00,
 0x92,0x3F,0x92,0x20,0x92,0x3F,0x92,0x20,0x9E,0x3F,0x92,0x20,0x80,0x28,0x80,0x10};//晴

const uint8_t duo[] PROGMEM=
{0x40,0x00,0x40,0x00,0xE0,0x0F,0x10,0x04,0x1C,0x02,0x20,0x01,0xC0,0x02,0x30,0x01,
 0x8E,0x1F,0x40,0x10,0x30,0x08,0x4C,0x04,0x80,0x02,0x80,0x01,0x70,0x00,0x0E,0x00};//多

const uint8_t yun[] PROGMEM=
{0x00,0x00,0xFC,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x7F,0x40,0x00,
 0x20,0x00,0x20,0x00,0x10,0x02,0x08,0x04,0x04,0x08,0xFE,0x1F,0x04,0x10,0x00,0x10};//云

const uint8_t yin[] PROGMEM=
{0x00,0x00,0xBE,0x3F,0xA2,0x20,0x92,0x20,0x92,0x20,0x8A,0x3F,0x92,0x20,0x92,0x20,
 0xA2,0x20,0xA2,0x3F,0xA2,0x20,0x96,0x20,0x4A,0x20,0x42,0x20,0x22,0x28,0x12,0x10};//阴

const uint8_t zhen[] PROGMEM=
{0x00,0x02,0x3E,0x02,0x22,0x02,0xD2,0x7F,0x12,0x01,0x0A,0x05,0x92,0x04,0x92,0x3F,
 0x22,0x04,0x22,0x04,0x22,0x04,0xD6,0x7F,0x0A,0x04,0x02,0x04,0x02,0x04,0x02,0x04};//阵

const uint8_t yu[] PROGMEM=
{0x00,0x00,0xFF,0x7F,0x80,0x00,0x80,0x00,0x80,0x00,0xFE,0x3F,0x82,0x20,0x82,0x20,
 0x92,0x22,0xA2,0x24,0x82,0x20,0x92,0x22,0xA2,0x24,0x82,0x20,0x82,0x28,0x02,0x10};//雨

const uint8_t da[] PROGMEM=
{0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xFF,0x7F,0x80,0x00,0x80,0x00,
 0x40,0x01,0x40,0x01,0x20,0x02,0x20,0x02,0x10,0x04,0x08,0x08,0x04,0x10,0x03,0x60};//大

const uint8_t zhong[] PROGMEM=
{0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xFC,0x1F,0x84,0x10,0x84,0x10,0x84,0x10,
 0x84,0x10,0x84,0x10,0xFC,0x1F,0x84,0x10,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00};//中

const uint8_t xiao[] PROGMEM=
{0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x88,0x08,0x88,0x10,0x88,0x20,
 0x84,0x20,0x84,0x40,0x82,0x40,0x81,0x40,0x80,0x00,0x80,0x00,0xA0,0x00,0x40,0x00};//小

const uint8_t xue[] PROGMEM=
{0xFC,0x1F,0x80,0x00,0xFE,0x7F,0x82,0x40,0xB9,0x2E,0x80,0x00,0xB8,0x0E,0x00,0x00,
 0xFC,0x1F,0x00,0x10,0x00,0x10,0xF8,0x1F,0x00,0x10,0x00,0x10,0xFC,0x1F,0x00,0x10};//雪
