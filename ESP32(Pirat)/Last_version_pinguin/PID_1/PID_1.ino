#include "all_data_1.h"

String ans;
const char sep =',';

TaskHandle_t Task1;
double pgo_l, pgo_r;

void setup() {
  Serial.begin(115200);
  //init_piezo();
  if (init_bmp()){delay_piezo(100);}
  delay(100);
//  init_gps();
  if (init_sd()){delay_piezo(100);}
  init_control();
  delay_piezo(1000);
  delay(500);
  xTaskCreatePinnedToCore(mpu_read,"Task1",10000,NULL,10,&Task1,0);
}

void mpu_read( void * pvParameters ){
  if (init_mpu()){delay_piezo(100);}
  while(true){
    update_mpu();
    delay(1);
    }
}

void loop() {
//      Serial.print(alt());Serial.print(" ");
//      Serial.print(pitch);Serial.print(" ");
//      Serial.print(yaw);Serial.print(" ");
      Serial.println(bmp.readPressure());
  //update_gps();
    read_control();
    
    if(!hand_control_flag){
//      Serial.print(servo_control[0]);Serial.print(" ");
//    Serial.print(servo_control[1]);Serial.print(" ");
//    Serial.print(servo_control[2]);Serial.print(" ");
//    Serial.print(servo_control[3]);Serial.print(" ");
//    Serial.print(servo_control[4]);Serial.print(" ");
//    Serial.print(servo_control[5]);Serial.print(" ");
//    Serial.println(servo_control[6]);
      write_control_hand_petr();

      
    }
    else {
      Serial.print(alt());
      Serial.print(pitch);Serial.print(" ");
      Serial.println(roll);
    }
    delay(1);
}

