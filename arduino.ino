#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define RELAY_PIN 7     // Ventilateur
#define BUZZER_PIN 5    // Buzzer

float tempMin = 0.0;  // Température minimale pour activer le ventilateur (pas encore défini)
float tempMax = 0.0;  // Température maximale pour l'activation du buzzer (pas encore défini)
bool seuilsRecus = false;  // Indicateur pour savoir si les seuils ont été reçus

String serialInput = "";

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);  // Ventilateur OFF par défaut
  digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF par défaut

  Serial.println("Système initialisé. En attente de seuils...");
}

void loop() {
  // Lire les données série (si Qt envoie les seuils)
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      processSerialInput(serialInput);
      serialInput = ""; // Réinitialiser après traitement
    } else {
      serialInput += c;
    }
  }

  // Vérifier si les seuils ont été reçus
  if (!seuilsRecus) {
    delay(1000);
    return; // Attendre les seuils
  }

  // Lire la température
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Erreur capteur !");
    return;
  }

  Serial.print("Temp actuelle : ");
  Serial.println(temp);

  // Si la température dépasse tempMax, activer le buzzer
  if (temp >= tempMax) {
    Serial.println("Alerte ! Température trop haute !");
    digitalWrite(RELAY_PIN, LOW);   // Ventilateur OFF
    digitalWrite(BUZZER_PIN, HIGH); // Buzzer ON
  } 
  // Si la température est entre tempMin et tempMax, garder le ventilateur allumé
  else if (temp > tempMin && temp < tempMax) {
    Serial.println("Ventilateur activé");
    digitalWrite(RELAY_PIN, HIGH);  // Ventilateur ON
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
  } 
  // Si la température est inférieure à tempMin, éteindre le ventilateur
  else {
    Serial.println("Ventilateur désactivé");
    digitalWrite(RELAY_PIN, LOW);   // Ventilateur OFF
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
  }

  delay(2000); // Délai avant la prochaine mesure
}

void processSerialInput(String input) {
  // Affichage de débogage
  Serial.print("Données reçues : ");
  Serial.println(input);
  
  // Format attendu : "23.0,30.0" (min, max)
  int commaIndex = input.indexOf(',');
  if (commaIndex != -1) {
    String minStr = input.substring(0, commaIndex);
    String maxStr = input.substring(commaIndex + 1);

    float minVal = minStr.toFloat();
    float maxVal = maxStr.toFloat();

    // Vérifier que tempMin est inférieur à tempMax
    if (minVal >= 0 && maxVal > minVal) {
      tempMin = minVal;
      tempMax = maxVal;
      seuilsRecus = true; // Indiquer que les seuils sont maintenant définis
      Serial.print("Nouveaux seuils : ");
      Serial.print(tempMin);
      Serial.print(" - ");
      Serial.println(tempMax);
    } else {
      Serial.println("Erreur : tempMin >= tempMax ou valeur invalide.");
    }
  } else {
    Serial.println("Format invalide reçu ! Attendu : min,max");
  }
}
