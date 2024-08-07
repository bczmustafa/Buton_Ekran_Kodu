#include <SoftwareSerial.h>
#include <Nextion.h>


SoftwareSerial HMISerial(16, 17);

// Nextion bileşenleri oluşturuluyor
 NexPicture p8 = NexPicture(0, 9, "p8"); // Ekranın 0. sayfasında, ID'si 10 olan p8 adlı bir resim bileşeni
 NexPicture p10 = NexPicture(0, 10, "p10"); // Ekranın 0. sayfasında, ID'si 12 olan p10 adlı bir resim bileşeni
 NexPicture p11 = NexPicture(0, 11, "p11"); // Ekranın 0. sayfasında, ID'si 13 olan p11 adlı bir resim bileşeni


// Buton pinlerini tanımlıyoruz
const int button1Pin = 5; // FAR KONTROL
const int button2Pin = 6; // SOL SİNYAL
const int button3Pin = 7; // SAG SİNYAL




void setup()
{
   Serial.begin(115200);
   delay(100);

 HMISerial.begin(9600); // Nextion ekranı için baudrate
  nexInit();
  // Buton pinini giriş olarak ayarlıyoruz
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button1Pin, INPUT_PULLUP);
  
 Serial.println("Nextion ekranı başlatıldı.");

}

void loop() {
      
        

  // Buton 1'e basıldı mı kontrol ediyoruz (far)
  if (digitalRead(button1Pin) == HIGH) {
    p8.setPic(0); // Buton 1'e basıldığında gösterilecek resim ID'si
  } else if (digitalRead(button1Pin) == LOW) {
    p8.setPic(1); // Buton 1'e basılmadığında gösterilecek resim ID'si
  }

 // Buton 2'ye basıldı mı kontrol ediyoruz (sol sinyal)
  if (digitalRead(button2Pin) == HIGH) {
    p10.setPic(2); // Buton 2'ye basıldığında gösterilecek resim ID'si
  } else if (digitalRead(button2Pin) == LOW) {
    p10.setPic(3); // Buton 2'ye basılmadığında gösterilecek resim ID'si
  }
 
  // Buton 3'e basıldı mı kontrol ediyoruz (sağ sinyal)
  if (digitalRead(button3Pin) == HIGH) {
    p11.setPic(4); // Buton 3'e basıldığında gösterilecek resim ID'si
  } else if (digitalRead(button3Pin) == LOW) {
    p11.setPic(5); // Buton 3'e basılmadığında gösterilecek resim ID'si
  }

   delay(100);
}
