#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_MOSI   11
#define OLED_CLK    13
#define OLED_DC     8
#define OLED_CS     10
#define OLED_RESET  9

Adafruit_SSD1306 display(128, 64, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
    Serial.begin(115200);
    
    if(!display.begin(SSD1306_SWITCHCAPVCC)) {
        Serial.println("OLED初始化失败!");
        while(1);
    }
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Ellipse Branch Test");
    
    // 测试椭圆
    display.drawEllipse(64, 32, 30, 20, SSD1306_WHITE);
    display.drawEllipse(32, 16, 15, 10, SSD1306_WHITE);
    display.drawEllipse(96, 48, 10, 15, SSD1306_WHITE);
    
    //测试填充椭圆
    display.fillEllipse(32, 48, 12, 8, SSD1306_WHITE);
    display.fillEllipse(96, 16, 8, 12, SSD1306_WHITE);

    // 测试圆形（椭圆特例）
    display.drawEllipse(64, 32, 10, 10, SSD1306_WHITE);
    
    display.display();
}

void loop() {
    // 空循环
}