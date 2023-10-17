#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // 初始化串口
  Serial.begin(9600);

  // 初始化OLED屏幕
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // 清除屏幕
  display.clearDisplay();
  display.display();

  // 设置文本大小
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Hello, OLED!"));
  display.display();
}

void loop() {
  // 在循环中可以添加更多的显示内容

  delay(1000); // 延迟1秒
}
