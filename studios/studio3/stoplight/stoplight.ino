/* stoplight
 *  
 *  CSE 132 - Studio 3
 *  
 *  Fill this out so we know whose studio this is.
 *  
 *  Name: Yangchen Shen
 *  WUSTL Key: sheny
 */
enum State {
	up0,        // NSG
	up1,        // NSY
	up2,        // EWG
	up3,        // EWY
	up4,        // PED
};

State counterState = up0; 

unsigned long accumulator = 0;
unsigned long accumulator2 = 0;

const int interval = 3041;

void setup() {
	// put your setup code here, to run once:
	pinMode(12,OUTPUT);//blue - walk
	pinMode(11,OUTPUT);//yellow - don't walk

	pinMode(10,OUTPUT);//EW green
	pinMode(9,OUTPUT);//EW yellow
	pinMode(8,OUTPUT);//EW red

	pinMode(6,OUTPUT);//NS red
	pinMode(5,OUTPUT);//NS yellow
	pinMode(4,OUTPUT);//NS green

}

void loop() {
	// put your main code here, to run repeatedly:
	// to create flashing walk signals
	if(millis() - accumulator > interval) { 
		accumulator += interval; 
		counterState = nextState(counterState);
	}
	// if the current state is not 4, the next state is not 0
	if(counterState != 0){
		if(millis() - accumulator2 > interval/5.0) {
			accumulator2 += interval/5.0; 
			digitalWrite(11,LOW);
		}
		else if(millis() - accumulator2 > interval/10.0){
			digitalWrite(11,HIGH);
		}
	}
}

State nextState(State state) {
	switch (state) {
	case up0:
		digitalWrite(12,LOW);
		digitalWrite(11,HIGH);
		digitalWrite(6,LOW);
		digitalWrite(4,HIGH);
		digitalWrite(8,HIGH);
		state = up1;
		break;                       

	case up1:               
		digitalWrite(4,LOW);
		digitalWrite(5,HIGH);
		state = up2;
		break;

	case up2:
		digitalWrite(5,LOW);
		digitalWrite(8,LOW);
		digitalWrite(6,HIGH);
		digitalWrite(10,HIGH);
		state = up3;
		break;

	case up3:
		digitalWrite(10,LOW);
		digitalWrite(9,HIGH);
		state = up4;
		break;

	case up4:
		digitalWrite(11,LOW);
		digitalWrite(12,HIGH);
		digitalWrite(9,LOW);
		digitalWrite(11,LOW); 
		digitalWrite(8,HIGH);
		state = up0;
		break;
	}
	return state;
}