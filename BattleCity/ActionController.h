#pragma once


class Tank;

class ActionController
{
public:
	virtual void PerformAction(Tank&)=0;
};

class PlayerController:public ActionController
{
public:
	virtual void PerformAction(Tank& T);
};

class BotController:public ActionController
{
public:
	virtual void PerformAction(Tank& T);
};