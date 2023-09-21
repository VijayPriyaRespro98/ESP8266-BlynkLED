/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL3GjPs2q-q"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "KsXiCdwTJQotmNJ64PuowGsHGKhmlcIZ"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "client";
char pass[] = "vijay123";

BlynkTimer timer;

// Define the LED pins
const int ledPinD0 = D0;
const int ledPinD1 = D1;
const int ledPinD2 = D2;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state and control the LED on D0
  digitalWrite(ledPinD0, value);
}

BLYNK_WRITE(V1)
{
  // Set incoming value from pin V1 to a variable
  int value = param.asInt();

  // Update state and control the LED on D1
  digitalWrite(ledPinD1, value);
}

BLYNK_WRITE(V2)
{
  // Set incoming value from pin V2 to a variable
  int value = param.asInt();

  // Update state and control the LED on D2
  digitalWrite(ledPinD2, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 4.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more than 10 values per second.
  Blynk.virtualWrite(V4, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Set LED pins as outputs
  pinMode(ledPinD0, OUTPUT);
  pinMode(ledPinD1, OUTPUT);
  pinMode(ledPinD2, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify the Blynk server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
