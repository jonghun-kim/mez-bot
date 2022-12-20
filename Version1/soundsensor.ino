#define FRONT_TRIG A0
#define FRONT_ECHO A1

#define LEFT_TRIG A2
#define LEFT_ECHO A3

#define RIGHT_TRIG A4
#define RIGHT_ECHO A5

void setup()
{
    Serial.begin(9600);
    pinMode(FRONT_TRIG, OUTPUT);
    pinMode(FRONT_ECHO, INPUT);
    pinMode(LEFT_TRIG, OUTPUT);
    pinMode(LEFT_ECHO, INPUT);
    pinMode(RIGHT_TRIG, OUTPUT);
    pinMode(RIGHT_ECHO, INPUT);
}

void loop()
{
    long front_duration, front_distance;
    int limit = 4;

    digitalWrite(FRONT_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(FRONT_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(FRONT_TRIG, LOW);

    front_duration = pulseIn(FRONT_ECHO, HIGH); // 물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.
    front_distance = front_duration * 17 / 1000;

    Serial.println(front_duration); // 초음파가 반사되어 돌아오는 시간을 보여줍니다.
    Serial.print("\nDIstance : ");
    Serial.print(front_distance); // 측정된 물체로부터 거리값(cm값)을 보여줍니다.
    Serial.println(" Cm");
    delay(1000); // 1초마다 측정값을 보여줍니다.

    while (front_distance < limit || front_duration > 70000)
    {
        long left_duration, left_distance, right_duration, right_distance;

        digitalWrite(LEFT_TRIG, LOW);
        digitalWrite(RIGHT_TRIG, LOW);
        delayMicroseconds(2);
        digitalWrite(LEFT_TRIG, HIGH);
        digitalWrite(RIGHT_TRIG, HIGH);
        delayMicroseconds(10);
        digitalWrite(LEFT_TRIG, LOW);
        digitalWrite(RIGHT_TRIG, LOW);

        left_duration = pulseIn(LEFT_ECHO, HIGH);   // 물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.
        right_duration = pulseIn(RIGHT_ECHO, HIGH); // 물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.
        left_distance = left_duration * 17 / 1000;
        right_distance = right_duration * 17 / 1000;

        if (left_duration > right_duration)
        {
            Serial.println("Right Turn");
            Serial.println(right_duration); // 초음파가 반사되어 돌아오는 시간을 보여줍니다.
            Serial.print("\nDIstance : ");
            Serial.print(right_distance); // 측정된 물체로부터 거리값(cm값)을 보여줍니다.
            Serial.println(" Cm");
        }
        else
        {
            Serial.println("Right Turn");
            Serial.println(left_duration); // 초음파가 반사되어 돌아오는 시간을 보여줍니다.
            Serial.print("\nDIstance : ");
            Serial.print(left_distance); // 측정된 물체로부터 거리값(cm값)을 보여줍니다.
            Serial.println(" Cm");
        }

        delay(1000); // 1초마다 측정값을 보여줍니다.
    }
}
