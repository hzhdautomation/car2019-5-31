#include "autoController.h"
int x;
int y;

void path::setpath()
{
	point head;
	point bady;
	point checkpoint;
	point path;
	string direction;
	static int i = 0;
	checkpoint = gameCtrl.getcheckpoint();
	head=gameCtrl.getsnakepoint(I);
	y = checkpoint.getcolum() - head.getcolum() >= 0 ? checkpoint.getcolum() - head.getcolum() : -(checkpoint.getcolum() - head.getcolum());
	x = checkpoint.getrow() - head.getrow() >= 0 ? checkpoint.getrow() - head.getrow() : -(checkpoint.getrow() - head.getrow());
	if (x>=y) {//策略第一步，绘制一次转折即可到达,基本策略为先走非反向。
		if (gameCtrl.getsnakehead()=="up")
		{
			if (checkpoint.getrow()<=head.getrow())
			{
				for (int i = 0; i < (head.getrow() - checkpoint.getrow()); i++) {

				}
			}
			else {
				if (checkpoint.getcolum()==head.getcolum())
				{
					for (int i = 0,int i_left=0,int i_right=0; i < gameCtrl.getsnakelang(); i++)
					{
						if (gameCtrl.getsnakepoint(I-i).getcolum()>head.getcolum())
						{
							i_right = i_right + 1;
						}
						if (gameCtrl.getsnakepoint(I - i).getcolum() < head.getcolum()) 
						{
							i_left = i_left + 1;
						}
						if (i=gameCtrl.getsnakelang()-1)
						{
							if (i_left>=i_right)
							{
								direction = "right";
							}
							else
							{
								direction = "left";
							}
						}
					}
					if (direction=="right") {

					}
					if (direction=="left")
					{

					}
				}
			}
		}
		for (int i = 0; i < x; i++)
			if (checkpoint.getrow()>head.getrow())
			{
				if (gameCtrl.getsnakehead()!="up")
				{
					plan[i].setpoint(head.getrow() + 1, head.getcolum());
				}
				else {

				}
			}
			else {
				plan[i].setpoint(head.getrow() - 1, head.getcolum());
			}
		for (int i = x; i < (x+y); i++) {
			if (checkpoint.getcolum() > head.getcolum())
			{
				plan[i].setpoint(head.getrow(), head.getcolum()+1);
			}
			else {
				plan[i].setpoint(head.getrow(), head.getcolum()-1);
			}
		}
	}
	else {
		for (int i = 0; i < y; i++)
			if (checkpoint.getcolum() > head.getcolum())
			{
				plan[i].setpoint(head.getrow(), head.getcolum() + 1);
			}
			else {
				plan[i].setpoint(head.getrow(), head.getcolum() - 1);
			}
			
		for (int i = y; i < (x + y); i++) {
			if (checkpoint.getrow() > head.getrow())
			{
				plan[i].setpoint(head.getrow() + 1, head.getcolum());
			}
			else {
				plan[i].setpoint(head.getrow() - 1, head.getcolum());
			}
		}
	}
	for (int i = 0; i < gameCtrl.getsnakelang(); i++) {
		bady = gameCtrl.getsnakepoint(I-i);
	}
}

void path::automove()
{
	point nextpoint;
	for (int i = 0; i < (x + y); i++)
	{
		if (gameCtrl.getsnakehead() == "up")
		{
			nextpoint.setrow = gameCtrl.getsnakepoint(I).getrow() - 1;
			nextpoint.setcolum = gameCtrl.getsnakepoint(I).getcolum();
		}
		if (gameCtrl.getsnakehead() == "down")
		{
			nextpoint.setrow = gameCtrl.getsnakepoint(I).getrow() + 1;
			nextpoint.setcolum = gameCtrl.getsnakepoint(I).getcolum();
		}
		if (gameCtrl.getsnakehead() == "left")
		{
			nextpoint.setrow = gameCtrl.getsnakepoint(I).getrow();
			nextpoint.setcolum = gameCtrl.getsnakepoint(I).getcolum() - 1;
		}
		if (gameCtrl.getsnakehead() == "right")
		{
			nextpoint.setrow = gameCtrl.getsnakepoint(I).getrow();
			nextpoint.setcolum = gameCtrl.getsnakepoint(I).getcolum() + 1;
		}
		if (nextpoint==plan[i])
		{

		}
		else {
			if (nextpoint.getrow()>plan[i].getrow())
			{
				gameCtrl.changesnakehead("down");
			}
			if (nextpoint.getrow() < plan[i].getrow())
			{
				gameCtrl.changesnakehead("up");
			}
			if (true)
			{

			}
		}
	}
}
