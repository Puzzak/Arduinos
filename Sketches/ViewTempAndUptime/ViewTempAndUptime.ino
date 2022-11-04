#include <DHT.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

long day = 86400000; // 86400000 milliseconds in a day
long hour = 3600000; // 3600000 milliseconds in an hour
long minute = 60000; // 60000 milliseconds in a minute
long second =  1000; // 1000 milliseconds in a second
#define DHTTYPE DHT11
#define DHTPIN 2     // Pin D2
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    lcd.begin(16, 2);
}

void loop() {
  long timeNow = millis();
  int days = timeNow / day ;                                
  int hours = (timeNow % day) / hour;                       
  int minutes = ((timeNow % day) % hour) / minute ;         
  int seconds = (((timeNow % day) % hour) % minute) / second;

    float temp_hum_val[2] = {0};
    lcd.setCursor(0, 0);
    lcd.print("Uptime: ");
    if(hours <10){lcd.print("0");}
    lcd.print(hours);
    lcd.print(":");
    if(minutes <10){lcd.print("0");}
    lcd.print(minutes);
    lcd.print(":");
    if(seconds <10){lcd.print("0");}
    lcd.print(seconds);
    
    lcd.setCursor(0, 1);
    if (!dht.readTempAndHumidity(temp_hum_val)) {
        lcd.print("Temprt: ");
        lcd.print(temp_hum_val[1]);
        lcd.print("C");
    } else {
        lcd.print("Sensor error   ");
    }
    delay(500);
}
