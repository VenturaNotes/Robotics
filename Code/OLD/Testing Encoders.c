#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop)           //2 Opens and Closes
#pragma config(Motor,  port3,           RFWheel,       tmotorVex393_MC29, openLoop, reversed) //3 Right Front Wheel
#pragma config(Motor,  port4,           LBWheel,       tmotorVex393_MC29, openLoop)           //4 Left Back Wheel
#pragma config(Motor,  port5,           LFWheel,       tmotorVex393_MC29, openLoop, reversed) //5 Left Front Wheel
#pragma config(Motor,  port6,           RBWheel,       tmotorVex393_MC29, openLoop)           //6 Right Back Wheel
#pragma config(Motor,  port7,           scissorLift,   tmotorVex393_MC29, openLoop, reversed) //7 Scissorlift
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop)					  //8 Lifts up the claw
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed) //9 Fork Lift
#pragma config(Sensor, dgtl7,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl10, rightEncoder,   sensorQuadEncoder)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int left = 0;
int right = 0;


task main()
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	while(1==1)
	{
		motor[RFWheel] = 90;
		motor[LFWheel] = -90;
		left = SensorValue[leftEncoder];
		right = SensorValue[rightEncoder];
	}
}

//Change the name of the port to test if it works.