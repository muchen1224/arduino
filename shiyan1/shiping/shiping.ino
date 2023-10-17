#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1
#define OLED_I2C_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!display.begin(OLED_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    Serial.println(F("Check OLED connection or OLED failure."));
    for (;;);
  }

  display.setTextSize(2);
  //display.clearDisplay(); // 只在setup函数中清空一次

  // 设置光标位置以居中显示文本
  int textWidth = display.width() * 2;
  int textX = (display.width() - textWidth) / 2;

  // 在居中位置显示文本
  display.setCursor(textX, 0);
  display.println("leixuran");

  display.display();
  Serial.println("OLED is working correctly.");
}

void loop() {
  // 延迟一段时间，或者您可以删除下面这行以使文本一直保持显示
  // delay(2000);
}
