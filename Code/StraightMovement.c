#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

 	wait1Msec(2000);
 	SensorValue[rightEncoder] = 0;
 	SensorValue[leftEncoder] = 0;
 	while(SensorValue[leftEncoder] < 1260)
{
 		 if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
 			{
 		 		motor[rightMotor] = 63;
 		 		motor[leftMotor] = 50;
 			}

 		 if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
 		{
 		    motor[rightMotor] = 50;
 		 		motor[leftMotor] = 63;
		}

		if(SensorValue[leftEncoder] == SensorValue[rightEncoder])
 		{
 			motor[rightMotor] = 63;
 			motor[leftMotor] = 63;
		}
	}

 	SensorValue[rightEncoder] = 0;
 	SensorValue[leftEncoder] = 0;

}