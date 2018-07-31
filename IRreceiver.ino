/* IR-receiver & decoder adruino sketch for IR-receiver module; plese read the "README" file.

 * Connect the IR module, upload this sketch on your own arduino board,
   open the serial monitor send some IR signals (you could use a common TV remote);
   you'll see the coded IR signals.
   
 * <--by E-partZ--> */

#include <IRremote.h> //use the library linked in in the "README" file.

IRrecv receiver(12); //it creates a receiving object, it gives the object its name (as a variable); between the gaps there is the arduino's pin number that you will connect to the module. 
decode_results result; //it creates a decode_result variable and it gives its name.

void setup() 
{

Serial.begin (9600);//starts the serial at 9600 bauds.
receiver.enableIRIn(); //starts the receiving proccess.

}

void loop() 
{
   if (receiver.decode(&result)) //tries to receive an IR signal, if the module receives a signal, it gives back a "true" state.
   {
    Serial.println(result.value); //prints on the serial monitor the coded IR value of the signal (you can also code it, for example in "HEX").
    receiver.resume(); //receive the next value.
    delay(150);
   }
}
