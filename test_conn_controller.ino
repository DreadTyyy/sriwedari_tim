#define RXD2 16  
#define TXD2 17  

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  Serial.println("Mengirim perintah uji baud rate...");

  Serial2.print("#0P1500T1000D500\r\n"); 
}

void loop() {
  if (Serial2.available()) {
    String response = Serial2.readStringUntil('\n'); 
    Serial.print("Respon: ");
    Serial.println(response);
  }
}
