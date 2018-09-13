const int trigPin = 9;
const int echoPin = 8;
const int rlyPwr = 13;
const int rlyTrig = 12;

float duration, distance;

unsigned long previousMillis =0;

const float minutes = 0.5;

const long interval = 1000 * 10;


int status;

void setup() 
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(rlyPwr, OUTPUT);
    pinMode(rlyTrig, OUTPUT);

    digitalWrite(rlyPwr, HIGH);
    digitalWrite(rlyTrig, LOW);

    int status = 0;

    Serial.begin(9600);
}

void loop() 
{
    unsigned long currentMillis = millis();

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);

    if (distance < 10)
    {
        previousMillis = currentMillis;

        digitalWrite(rlyTrig, HIGH);

        status = 1;
    }

    if (status ==1 && currentMillis - previousMillis >= interval && distance > 10)
    {
        previousMillis = currentMillis;

        digitalWrite(rlyTrig, LOW);
        
        status = 0;

    }
    
}