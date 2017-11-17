#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LWheel,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           scissorLift1,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           scissorLift2,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(Motor,  port9,           LClaw,         tmotorVex393_MC29, openLoop)


//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (1 == 1)
	{
		motor[RWheel] = vexRT(Ch2)*-1; //-2?
		motor[LWheel] = vexRT(Ch3)*1;

		if(vexRT[Btn7U] == 1) //WHEN SHOULDER BUTTON 5U IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO 20
		{
			motor[FLift] = -90;
		}

		else if(vexRT[Btn7D] == 1) //WHEN SHOULDER BUTTON 5D IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO -20
		{
			motor[FLift] = 90;
		}
		else
		{
			motor[FLift] = 0;
		}

		if(vexRT[Btn5U] == 1)
		{
			motor[clawLift] = 50;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[clawLift] = -50;
		}
		else
		{
			motor[clawLift] = 0;
		}

		if(vexRT(Btn8R) == 1)
		{
			motor[clawGrip] = 50;
		}
		else if(vexRT(Btn8L) == 1)
		{
			motor[clawGrip]	= -50;
		}
		else
		{
			motor[clawGrip] = 0;
		}

		if(vexRT[Btn6D] == 1)
		{
			motor[scissorLift1] = 100;
			motor[scissorLift2] = 100;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[scissorLift1] = -100;
			motor[scissorLift2] = -100;
		}
		else
		{
			motor[scissorLift1] = 0;
			motor[scissorLift2] = 0;
		}
	}
}
