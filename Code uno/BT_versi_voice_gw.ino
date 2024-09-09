#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

#define buzzer 12
#define relay 13
#define red_led 10
#define green_led 11

String voice = "";
char data = 0;
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial bt(2, 3);
char daysOfTheWeek[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"}; //{“Sun“, “Mon“, “Tue“, “Wed“, “Thu“, “Fri“, “Sat“};

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  lcd.begin();

  if (! rtc.begin()) {
    lcd.print("Couldn’t find RTC");
    Serial.print("Couldn’t find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    lcd.print("RTC is NOT running!");
    Serial.print("RTC is NOT running!");
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
  //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manualy

  delay(10);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(relay, LOW); //AKTIF LOW
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME  ");
  lcd.setCursor(0, 1);
  lcd.print("HELLO, VEENDY :) ");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   STOP KONTAK  ");
  lcd.setCursor(0, 1);
  lcd.print("    BLUETOOTH   ");
  delay(5000);
  lcd.clear();
}

void loop() {
  myTimer();
  if (bt.available() > 0) {
    voice = bt.readString();
    data = bt.read();
    Serial.print("voice = ");
    Serial.println(voice);
    Serial.print("data = ");
    Serial.println(data);
    if (voice == "lampu menyala") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (voice == "on") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (voice == "off") {
      digitalWrite(relay, HIGH);
      notif();
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
    else if (data == "1") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (data == "0") {
      digitalWrite(relay, HIGH);
      notif();
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
    else if (voice == "Assalamualaikum") {
      digitalWrite(green_led, HIGH);
      digitalWrite(red_led, LOW);
      delay(1000);
      digitalWrite(green_led, LOW);
      digitalWrite(red_led, HIGH);
      delay(1000);
      digitalWrite(green_led, HIGH);
      digitalWrite(red_led, LOW);
    }
    else if (voice == "Wassalamualaikum") {
      digitalWrite(green_led, LOW);
      digitalWrite(red_led, HIGH);
      delay(500);
      digitalWrite(green_led, HIGH);
      digitalWrite(red_led, LOW);
      delay(500);
      digitalWrite(green_led, LOW);
      digitalWrite(red_led, HIGH);
    }
    else if (voice == "hai") {
      digitalWrite(red_led, HIGH);
      delay(1000);
      digitalWrite(green_led, LOW);
      delay(500);
      digitalWrite(red_led, HIGH);
      delay(1000);
      digitalWrite(green_led, LOW);
      delay(500);
    }
    else if (voice == "Nyalakan semua") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (voice == "lampu hidup") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (voice == "goblok") {
      digitalWrite(relay, LOW);
      digitalWrite(red_led, LOW);
    }
    else if (voice == "Hidupkan lampu") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (voice == "hidup") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (voice == "mati") {
      digitalWrite(relay, HIGH);
      notif();
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
    else if (voice == "lampu mati") {
      digitalWrite(relay, HIGH);
      notif();
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
    else if (voice == "Matikan lampu") {
      digitalWrite(relay, HIGH);
      notif();
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
    else if (voice == "matikan semua") {
      digitalWrite(relay, HIGH);
      notif();
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
    else if (voice == "nyalakan lampu") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (voice == "Urip ke lampu") {
      digitalWrite(relay, LOW);
      notif();
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
    else if (voice == "Lampu matek") {
      digitalWrite(relay, HIGH);
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
  }
}

void myTimer() {
  DateTime now = rtc.now();
  lcd.setCursor(0, 1);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  lcd.println("                       ");
  lcd.setCursor(0, 0);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print(",");
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());
  lcd.println("         ");
  //  Serial.print(now.hour());
  //  Serial.print(":");
  //  Serial.print(now.minute());
  //  Serial.print(":");
  //  Serial.print(now.second());
  //  Serial.print(" | ");
  //  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  //  Serial.print(",");
  //  Serial.print(now.day());
  //  Serial.print("/");
  //  Serial.print(now.month());
  //  Serial.print("/");
  //  Serial.print(now.year());
  //  Serial.println("         ");
}

void notif() {
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  delay(50);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
}
