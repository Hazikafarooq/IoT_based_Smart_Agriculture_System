/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
// #define BLYNK_TEMPLATE_ID "TMPL6tbXuEiW-"
// #define BLYNK_TEMPLATE_NAME "Quickstart Template"
// #define BLYNK_AUTH_TOKEN "gFHYQayBhfh9BA3KHM0ETRsLLJZK2iiq"
// #define BLYNK_TEMPLATE_ID           "TMPL6tbXuEiW-"
// #define BLYNK_TEMPLATE_NAME         "Quickstart Template"

// #define BLYNK_TEMPLATE_ID           "TMPL6tbXuEiW-"
// #define BLYNK_TEMPLATE_NAME         "Quickstart Template"
// #define BLYNK_AUTH_TOKEN            "OAzhhzZJ1Lw9NP7d2IG-98j-A6udOhtl"

#define BLYNK_TEMPLATE_ID           "TMPL6tbXuEiW-"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "1qGVGBI_zpel673_BEtILbBp2m1wQ1Wu"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
char ssid[] = "Honor 8C";
char pass[] = "12345678";

// char ssid[] = "Shabbir Network=R1=03153817758";
// char pass[] = "aaaaaaaa";
#define DHTPIN D4     // what digital pin we're connected to
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
// Your WiFi credentials.
// Set password to "" for open networks.


BlynkTimer timer;



// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  Serial.println(value);

  if (value ==1){
    // tone(D3,1100);
    digitalWrite(D0, HIGH);
    Serial.println(value);
	//   delay(2000);
	// // Now change motor directions
	//   digitalWrite(in2, LOW);
  //   delay(2000);
    //digitalWrite(D5,HIGH);
   

  } 
  else {
    // noTone(D3);
  
    digitalWrite(D0, LOW);
	//     delay(2000);
	// // Now change motor directions
	//     digitalWrite(in2, LOW);
  //   	delay(2000);
  }
  // int x = analogRead(A0);
  // x = map(x, 0, 1024, 0, 100);
  // x = (x -100) * (-1);
  // Blynk.virtualWrite(V1,x);
  // Serial.println("this");
  // Serial.println(x);
}
void motion(){
  
  int motion = digitalRead(D2);
  delay(2000);
  //Serial.println(motion);
  Blynk.virtualWrite(V9, motion);
  if (motion ==1){
    for (int i =0 ; i<5; i++){
      tone(D3,1100);
      

    }
  }
  else{
    noTone(D3);
  }

}
void temperature(){
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  // if (isnan(h) || isnan(t) || isnan(f)) {
  //   Serial.println("Failed to read from DHT sensor!");
  //   return;
  // }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  // Serial.print("Humidity: ");
  // Serial.print(h);
  // Serial.print(" %\t");
  // Serial.print("Temperature: ");
  // Serial.print(t);
  // Serial.print(" *C ");
  // Serial.print(f);
  // Serial.print(" *F\t");
  // Serial.print("Heat index: ");
  // Serial.print(hic);
  // Serial.print(" *C ");
  // Serial.print(hif);
  // Serial.println(" *F");
  Blynk.virtualWrite(V4,h);
  
  Blynk.virtualWrite(V5,t);
  // Blynk.virtualWrite(V6,hic);
  // Blynk.virtualWrite(V7,f);
}
// void waterlevel(){
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   // Sets the trigPin on HIGH state for 10 micro seconds
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   // Reads the echoPin, returns the sound wave travel time in microseconds
//   duration = pulseIn(echoPin, HIGH);
//   // Calculating the distance
//   int x = duration * 0.034 / 2;;
//   distance = (6-x)*10;

//   Serial.println("Distance: ");
//   Serial.println(x);
//   // Serial.println("per: ");
//   // Serial.println(distance);
//   delay(2000);
//   Blynk.virtualWrite(V8,distance);
// }
int x;
void soilmoisture(){
  x = analogRead(A0);
  // int motion = digitalRead(D2);
  x = map(x, 1023, 465, 0, 100);
  // x = (x -100) * (-1);
  Blynk.virtualWrite(V1,x);
  // if (x <50){
  //   for (int i =0 ; i<1000; i++){
  //     digitalWrite(in1, HIGH);
  //     // tone(D3,1100);
	//     delay(2000);
	// // Now change motor directions
	//     digitalWrite(in2, LOW);
  //   	delay(2000);
  //   }
    
	// Turn on motor A & B
  // }
  // else{
  //   digitalWrite(in1, LOW);
  //     // tone(D3,1100);
	//     delay(2000);
	// // Now change motor directions
	//     digitalWrite(in2, LOW);
  //   	delay(2000);
  // }
  
}



// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  // Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  // Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  // Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  // Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  // Debug console
  
  pinMode(A0,INPUT); //soil sensor
  pinMode(D0,OUTPUT); // motor driver D0
  
  pinMode(D2,INPUT); // motion sensor
  pinMode(D3,OUTPUT); // buzzer
  
  // pinMode(D4, INPUT);
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
 
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // delay(2000);

  // Serial.println(value);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  

  // if (motion ==0){
  //   for (int i =0 ; i<5; i++){
  //     noTone(D3);
  //   }
  // }
  soilmoisture();
  
  temperature();
  motion();
 

}


