/* cricket
 *  
 *  CSE 132 - Assignment 3
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Yangchen Shen
 *  WUSTL Key: sheny
 *  
 *  and if two are partnered together
 *  
 *  Name:
 *  WUSTL Key:
 */

const int ANALOG_PIN = A0;
const int LED_PIN = 10;
unsigned long accumulator = 0;
unsigned long accumulator2 = 0;
const int interval = 250;
float val = 0;
float voltage = 0;
float temperature = 0;
const int FILTER_COUNTS = 10;
float temps[FILTER_COUNTS]; 
int count = 0;
float sum = 0;
float avg = 0;

void setup() {
	Serial.begin(9600);
	analogReference(INTERNAL);
	pinMode(LED_PIN, OUTPUT);
	//pinMode(ANALOG_PIN, OUTPUT);
	//cannot add this line above, or will get -40 degrees
}

void loop() {
	if(millis() - accumulator2 > interval/FILTER_COUNTS) { 
		accumulator2 += interval/FILTER_COUNTS; 
		val = analogRead(ANALOG_PIN);
		voltage = val*1.1/1023;
		temperature = 100*voltage - 50;
		temps[count % FILTER_COUNTS] = temperature;
		count = count + 1;
	}

	if(millis() - accumulator > interval) { 
		accumulator += interval; 
		val = analogRead(ANALOG_PIN);
		//Serial.println(val);
		voltage = val*1.1/1023;
		temperature = 100*voltage - 50;

		//unfiltered data
		Serial.print(temperature);
		Serial.print(",");

		//filtered data
		for (int i = 0; i < FILTER_COUNTS; i++){
			sum = sum + temps[i];
		}
		avg = sum/FILTER_COUNTS;
		sum = 0;
		count = 0;
		Serial.println(avg);
	}
}
