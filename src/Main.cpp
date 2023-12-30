#include "notation.h"
#include <app.h>
#include <swTimer.h>
#include "network.h"
#include <frame.h>
#include "driver/timer.h"
#include "memory.h"
#include < WebServer.h>

static int temp = 0;
void ReceiveHandler();
int8_t rssi;
double distance;
static double a_distance[10];
void WiFiReceive();

const char *ssid = "Asus";
const char *password = "123123123";
WiFiServer server(80);
const char *host = "192.168.253.6"; // IP address of the server
const int port = 80;
WiFiClient client;

void shiftArrayAndAddValue()
{

  // Shift all elements to the left by one position
  for (int i = 0; i < 9; i++)
  {
    a_distance[i] = a_distance[i + 1];
  }

  // Add the new value at the end of the array
  a_distance[9] = distance;
}

double mean()
{
  double meanVal = 0.00;

  for (int i = 0; i < 9; i++)
  {
    meanVal = a_distance[i] + meanVal;
  }
  meanVal = meanVal / 10.00;
  return meanVal;
}

void get(TimerHandle_t getTimer)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    rssi = WiFi.RSSI();
    g_sendPacket.rssi = rssi;
    distance = RssiBasedCalculation(rssi);
    shiftArrayAndAddValue();
  }
}

void print(TimerHandle_t printTime)
{
  if (DEVICE_TYPE == ANCHOR_DEVICE_ONE)
  {
    Serial.println(g_receivedPacket.rssi);
  }

  else
  {
  }
}

void checkConnection(TimerHandle_t xTimer)
{
  if (DEVICE_TYPE == ANCHOR_DEVICE_ONE)
  {
    return;
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    WifiReconnectCB();
  }
  else if (WiFi.status() == WL_CONNECTED && CONNECTION_FLAG != WIFI_CONNECTED)
  {
    Esp32NowInit();
    Serial.println("Wifi Reconnected");
    CONNECTION_FLAG = WIFI_CONNECTED;
  }
  else
  {
    CONNECTION_FLAG = WIFI_CONNECTED;
  }
}

void checkEspNow(TimerHandle_t xTimer)
{
  if (esp_now_init() != ESP_OK)
  {
    Esp32NowInit();
  }
}

void setup()
{

  Serial.begin(115200);
  // initWiFi();
  MemoryInit();
  // Esp32NowInit();
  memset(a_distance, 0, sizeof(a_distance));
  memset(&g_sendPacket, 0, sizeof(g_sendPacket));

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  // 192.168.253.6

  Serial.print("Server IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", []()
            { server.send(200, "text/plain", "Hello from ESP32"); });
  server.begin();

  TimerHandle_t rssiGetTime = xTimerCreate("RSSI Get", pdMS_TO_TICKS(200), pdTRUE, 0, get);
  TimerHandle_t rssiPrintTime = xTimerCreate("RSSI Print", pdMS_TO_TICKS(5000), pdTRUE, 0, print);
  TimerHandle_t checkWifi = xTimerCreate("Check Wifi Connection", pdMS_TO_TICKS(5000), pdTRUE, 0, checkConnection);
  TimerHandle_t checkEsp_Now = xTimerCreate("Check ESP_NOW Connection", pdMS_TO_TICKS(2000), pdTRUE, 0, checkEspNow);

  if (rssiGetTime == NULL)
  {
    Serial.println("Timer creation failed!(Get)");
  }
  else
  {
    if (xTimerStart(rssiGetTime, 0) != pdPASS)
    {
      Serial.println("Timer start failed!(Get)");
    }
  }

  if (rssiPrintTime == NULL)
  {
    Serial.println("Timer creation failed!(print)");
  }
  else
  {
    if (xTimerStart(rssiPrintTime, 0) != pdPASS)
    {
      Serial.println("Timer start failed!(print)");
    }
  }

  if (checkWifi == NULL)
  {
    Serial.println("Timer creation failed!(checkWifi)");
  }
  else
  {
    if (xTimerStart(checkWifi, 0) != pdPASS)
    {
      Serial.println("Timer start failed!(checkWifi)");
    }
  }
  /*
    if (checkEsp_Now == NULL)
    {
      Serial.println("Timer creation failed!(checkEspNow)");
    }
    else
    {
      if (xTimerStart(checkEsp_Now, 0) != pdPASS)
      {
        Serial.println("Timer start failed!(checkEsp_Now)");
      }
    }*/
}

void loop()
{
  server.handleClient();
}
