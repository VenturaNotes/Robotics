#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LWheel,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RClaw,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LClaw,         tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (1 == 1)
	{
	motor[RWheel] = vexRT(Ch2)*-.98;
	motor[LWheel] = vexRT(Ch3)*.98;

	if(vexRT[Btn6U] == 1) //WHEN BUTTON 5U IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO 20
	{
		motor[LClaw] = -90;
		motor[RClaw] = 85;
	}

	else if(vexRT[Btn6D] == 1) //WHEN BUTTON 5D IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO -20
	{
		motor[LClaw] = 85;
		motor[RClaw] = -90;
	}
	else
		{
		motor[LClaw] = 0;
		motor[RClaw] = 0;
		}

	}
}
