#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define TRIG D5
#define ECHO D6
#define LED  D2

const char* ssid = "Sadhana";
const char* password = "123456789";

ESP8266WebServer server(80);

float distanceCM = 0;

float getDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);

  float distance = duration * 0.0343 / 2;

  return distance;
}

String webpage()
{
  distanceCM = getDistance();

  String alertMsg;
  String alertColor;

  if(distanceCM > 20)
  {
    digitalWrite(LED, HIGH);

    alertMsg =
    "⚠ ALERT! Object Distance Exceeded 20 cm";
    alertColor = "#ff1744";
  }
  else
  {
    digitalWrite(LED, LOW);

    alertMsg =
    "✅ SAFE! Object Within Limit";
    alertColor = "#00e676";
  }

  String html = R"rawliteral(

<!DOCTYPE html>
<html>

<head>

<meta name="viewport"
content="width=device-width,initial-scale=1">

<meta http-equiv="refresh" content="2">

<title>Distance Monitoring System</title>

<style>

*{
margin:0;
padding:0;
box-sizing:border-box;
font-family:Segoe UI;
}

body{
height:100vh;
display:flex;
justify-content:center;
align-items:center;
background:linear-gradient(
135deg,
#0d47a1,
#1976d2,
#42a5f5
);
}

.container{
text-align:center;
}

.title{
font-size:40px;
font-weight:bold;
color:white;
margin-bottom:30px;
}

.card{
background:white;
padding:40px;
width:350px;
border-radius:20px;
box-shadow:0 10px 25px rgba(0,0,0,0.3);
margin:auto;
}

.label{
font-size:24px;
color:#1565c0;
font-weight:bold;
}

.value{
font-size:50px;
font-weight:bold;
margin-top:10px;
color:#333;
}

.alert{
margin-top:25px;
padding:15px;
border-radius:10px;
font-size:20px;
font-weight:bold;
color:white;
}

.footer{
margin-top:20px;
color:white;
font-size:16px;
}

</style>

</head>

<body>

<div class='container'>

<div class='title'>
📏 Ultrasonic Distance Monitor
</div>

<div class='card'>

<div class='label'>
Distance
</div>

<div class='value'>
)rawliteral";

  html += String(distanceCM,1);

  html += R"rawliteral(
 cm
</div>

</div>

<div class='alert'
style='background:)rawliteral";

  html += alertColor;

  html += R"rawliteral(;'>

)rawliteral";

  html += alertMsg;

  html += R"rawliteral(

</div>

<div class='footer'>
ESP8266 Local Web Server
</div>

</div>

</body>

</html>

)rawliteral";

  return html;
}

void handleRoot()
{
  server.send(200, "text/html", webpage());
}

void setup()
{
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();
}

void loop()
{
  server.handleClient();
}
