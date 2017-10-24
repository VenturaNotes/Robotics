#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
//This configurizes the motors and encoders to their correct ports.

int test = 0;
int test2 = 40;
int test3 = 0;

task main()
{
	SensorValue[leftEncoder] = 0; //The leftEncoder keeps track of the degrees turned by the wheels of the leftMotor
	SensorValue[rightEncoder] = 0;//The rightEncoder keeps track of the degrees turned by the wheels of the rightMotor
	//Sets the encoders to their default value of 0.

	int limit = 0; //Stops the while loop when the robot moves a certain distance

	//Data gathered from measured values
	float diameterOfWheel = 4.25; //Diameter of each wheel in inches
	float tile = 23.25; //Length of each tile in inches on the field

	//Applications of the measured values
	float distanceToGo = tile*1; //Distance the robot needs to go in inches.
  float circumference = diameterOfWheel*PI; //Finds the circumference of each wheel in inches
  float rotations = distanceToGo/circumference; //Number of rotations the wheels turn to go a certain distance
  float degreesToTurn = rotations*360; //Degrees the wheels must turn in order to go a certain distance

	while(limit == 0) //Loop will run continuously until the limit value is changed
	{
        
        if(test2 >= abs(SensorValue[rightEncoder]-SensorValue[leftEncoder]) && test3 >= 1000)
        {
            test3+=1;
            if(SensorValue[rightEncoder] < SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
            {
                motor[leftMotor] = 40;
                motor[rightMotor] = 30.5;
            }
            
            if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
            {
                motor[leftMotor] = 30.5;
                motor[rightMotor] = 40;
            }
        }
        else
        {
        
            if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) //If the sensor values are equal, then all the wheels must be turning equally
                {
                    motor[leftMotor] = 40;  //Sets the speed of the left wheels
                    motor[rightMotor] = 40; //Sets the speed of the right wheels
                }

            if(SensorValue[rightEncoder] < SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
                {
                    motor[leftMotor] = 40; //Sets the speed of the left wheels
                    motor[rightMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
                    /*The right motor is slowed down so that the left wheels can catch up to the speed of the right wheels
                     This is done by finding the absolue value of the cosine of the difference between the left and and right
                     encoders. The absolute value of the cosine of any number will always be between 0 and 1. This value will
                     be multiplied by the base speed of 40 in order to slow the more powerful motor.
                     */
                }
            else if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
                {
                    motor[leftMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder])); //Similar function as above
                    motor[rightMotor] = 40; //Sets the speed of the right wheels
                }
                    /*
                     if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
                     {
                     limit+=1;
                     }
                     If the number of degrees to turn is less than both the absolute value of the encoder values, the limit will increase so
                     that the while loop it's inside of will stop.
                     */

                test = (SensorValue[rightEncoder]-SensorValue[leftEncoder]);
        }
	}
}

/*
Notes:
The problem with the robot is that it takes a second to synch the motors together. How could we make it sync faster?
Options
1.) What if we set the decoder values to which they become equal? So instead of setting the decoder values to 0, you could
set them up to have a greater value.

test = (SensorValue[rightEncoder]-SensorValue[leftEncoder]);

*/
