#include <Arduino.h>
#include <Ticker.h>
#include <ESP8266WiFiMulti.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "WiFi.h"
#include "OLED.h"
#include <PubSubClient.h>
#include <DHT.h>

void OLED_Proc(void);
void WiFi_Proc(void);
void Carton_Proc(void);

Ticker Timer1;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
WiFiClient espClient;
PubSubClient client(espClient);
unsigned char Flag = 0;
unsigned char Number_Picture = 0;
unsigned char OLED_Slow = 1;
unsigned int WiFi_Slow = 0;
unsigned char Carton_Slow = 0;
const char* mqtt_server = "broker-cn.emqx.io";  //192.168.222.88  172.20.10.6
const char* mqtt_id = "2532783676_ESP";   //改成自己的QQ号+_ESP
const char* Mqtt_sub_topic = "2532783676_ESP";   //改成自己的QQ号+_ESP
const char* Mqtt_pub_topic = "2532783676";  //  上报消息给  手机APP的TOPIC  //改成自己的QQ号
long lastMsg = 0; //定时用的

#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Timer1.attach_ms(1, Timer1_Server);

  pinMode(2, OUTPUT);     

  OLED_Init();
  OLED_Clear();

  WiFi_Init();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  OLED_Proc();
  WiFi_Proc();
  Carton_Proc();


  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    float temperature =dht.readTemperature();
    float humidity = dht.readHumidity();
    if(isnan(temperature) || isnan(humidity)){
        Serial.println("Failed to read from DHT senor!");
        return;
      }
       String json = "{\"temperature\":" + String(temperature) + ", \"humidity\":" + String(humidity) + "}";
//     String json = "{\"temperature\":" + String(temperature)  + "}";  
//      String json = "{\"temperature\":"+String(analogRead(A0))+"}";
    client.publish(Mqtt_pub_topic,json.c_str());
  }

}

void OLED_Proc(void)
{
  if(OLED_Slow) return;
  OLED_Slow = 1;
  
  if(results_0_last_update_str.isEmpty())
    OLED_ShowString(1, 1, "Waiting...");
  else 
  {
    if(Flag == 0)
    {
      Flag = 1;
      OLED_Clear();
    }
    
    //显示天气
    if(results_0_now_code_int == 0 || results_0_now_code_int == 1 || results_0_now_code_int == 2 || results_0_now_code_int == 3){
      OLED_ShowAPicTure(0, 4, 31, 7, 0);
      OLED_ShowAHanzi(4, 3, 7); OLED_ShowAHanzi(4, 5, 8);}//晴天
    else if(results_0_now_code_int == 4 || results_0_now_code_int == 5 || results_0_now_code_int == 6 || results_0_now_code_int == 7 || results_0_now_code_int == 8){
      OLED_ShowAPicTure(0, 4, 31, 7, 1);
      OLED_ShowAHanzi(4, 3, 9); OLED_ShowAHanzi(4, 5, 10);}//多云
    else if(results_0_now_code_int == 9){
      OLED_ShowAPicTure(0, 4, 31, 7, 2);
      OLED_ShowAHanzi(4, 3, 11); OLED_ShowAHanzi(4, 5, 8);}//阴天
    else if(results_0_now_code_int == 10){
      OLED_ShowAPicTure(0, 4, 31, 7, 3);
      OLED_ShowAHanzi(4, 3, 12); OLED_ShowAHanzi(4, 5, 13);}//阵雨
    else if(results_0_now_code_int == 11){
      OLED_ShowAPicTure(0, 4, 31, 7, 4);
      OLED_ShowAHanzi(4, 3, 14);OLED_ShowAHanzi(4, 4, 12); OLED_ShowAHanzi(4, 5, 13);}//雷阵雨
    else if(results_0_now_code_int == 12){
      OLED_ShowAPicTure(0, 4, 31, 7, 5);
      OLED_ShowAHanzi(4, 3, 15); OLED_ShowAHanzi(4, 5, 16);}//雷阵雨伴有冰雹
    else if(results_0_now_code_int == 13){
      OLED_ShowAPicTure(0, 4, 31, 7, 6);
      OLED_ShowAHanzi(4, 3, 17); OLED_ShowAHanzi(4, 5, 13);}//小雨
    else if(results_0_now_code_int == 14){
      OLED_ShowAPicTure(0, 4, 31, 7, 7);
      OLED_ShowAHanzi(4, 3, 18); OLED_ShowAHanzi(4, 5, 13);}//中雨
    else if(results_0_now_code_int == 15){
      OLED_ShowAPicTure(0, 4, 31, 7, 8);
      OLED_ShowAHanzi(4, 3, 19); OLED_ShowAHanzi(4, 5, 13);}//大雨
    else if(results_0_now_code_int == 16){
      OLED_ShowAPicTure(0, 4, 31, 7, 9);
      OLED_ShowAHanzi(4, 3, 20); OLED_ShowAHanzi(4, 5, 13);}//暴雨

    //显示温度
    OLED_ShowString(3, 5, "T:");
    OLED_ShowNum(3, 7, results_0_now_temperature_int, 2); OLED_ShowAHanzi(3, 5, 6);
      
    //显示实时时间
    timeClient.update();
    timeClient.setTimeOffset(28800);
    OLED_ShowTime(1, 1, timeClient.getFormattedTime().c_str());
    // OLED_ShowString(1, 9, timeClient.getFormattedTime().c_str());
  }
  
}

void WiFi_Proc(void)
{
  if(WiFi_Slow) return;
  WiFi_Slow = 1;

  Client_Request();
}

void Carton_Proc(void)
{
  if(Carton_Slow) return;
  Carton_Slow = 1;
  
  //显示旋转太空人
  OLED_ShowCarton(87, 4, 127, 7 ,Number_Picture);
  Number_Picture++;
  Number_Picture %= 13;
}

void Timer1_Server(void)
{
  if(OLED_Slow != 0)
    OLED_Slow ++;
  if(OLED_Slow == 100)
    OLED_Slow = 0;
    
  if(Carton_Slow != 0)
    Carton_Slow ++;
  if(Carton_Slow == 100)
    Carton_Slow = 0;

  if(WiFi_Slow != 0)
    WiFi_Slow++;
  if(WiFi_Slow == 10000)
    WiFi_Slow = 0;
}
void callback(char* topic, byte* payload, unsigned int length) {
  String msg="";
  String LED_set = "";
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    msg+= (char)payload[i];
  }
  Serial.println(msg);
  if(msg.indexOf("led"))  //判断是否是要设置LED灯
  {
    //取出LED_set数据 并执行
    LED_set = msg.substring(msg.indexOf("led\":")+5,msg.indexOf("}")); 
    digitalWrite(2,!LED_set.toInt()); 
  }
}
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(mqtt_id)) {
      Serial.println("connected");
      //连接成功以后就开始订阅
      client.subscribe(Mqtt_sub_topic,1);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
