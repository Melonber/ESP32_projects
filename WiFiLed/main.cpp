#include <WiFi.h>


const char* ssid = "";
const char *password = "";

WiFiServer server(80);

int ledPin_green = 0;
int ledPin_red = 1;

void setup()
{
  Serial.begin(115200);

  pinMode(ledPin_green, OUTPUT);
  pinMode(ledPin_red, OUTPUT);

  digitalWrite(ledPin_green, LOW);
  digitalWrite(ledPin_red, LOW);

  Serial.println("Connecting wifi: ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected !");
  Serial.print(WiFi.localIP());

  server.begin();
}

void loop(){
  WiFiClient client = server.available();
  if(client){
    Serial.println("Client connected");
    String request = client.readStringUntil('\r');
    client.flush();

    if(request.indexOf("/GREENLED=ON")!=-1){
      digitalWrite(ledPin_green, HIGH);
    }
    if(request.indexOf("/GREENLED=OFF")!=-1){
      digitalWrite(ledPin_green, LOW);
    }
    if(request.indexOf("/REDLED=ON")!=-1){
      digitalWrite(ledPin_red, HIGH);
    }
    if(request.indexOf("/REDLED=OFF")!=-1){
      digitalWrite(ledPin_red, LOW);
    }


    // Ответ клиенту (HTML страница)
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<h1>ESP32 LED Control</h1>");
    client.println("<p><a href=\"/GREENLED=ON\"><button>Turn Green LED ON</button></a></p>");
    client.println("<p><a href=\"/GREENLED=OFF\"><button>Turn Green LED OFF</button></a></p>");
    client.println("<p><a href=\"/REDLED=ON\"><button>Turn Red LED ON</button></a></p>");
    client.println("<p><a href=\"/REDLED=OFF\"><button>Turn Red LED OFF</button></a></p>");
    client.println("</html>");

    client.stop();
    Serial.println("Disconnected");
  }
}
