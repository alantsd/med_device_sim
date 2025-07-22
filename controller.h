// Author: Alan Sing Teik, 2025
// Middleware layer
// function: abstract controller base class 
#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller_t 
{
public:
	virtual ~Controller_t() = default;
	virtual uint32_t getData() = 0;
	virtual void run() = 0;
};

#endif // CONTROLLER_H