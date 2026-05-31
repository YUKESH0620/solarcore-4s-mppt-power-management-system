/*
Project     : MPPT Solar Power Supply
File        : system.h

Description :
System initialization definitions.

Developer Notes :

* Centralized system startup.
* Initializes firmware modules.
* Called once during startup.
* No application logic shall be placed here.

Initialization Flow :

System_Init()
|
+--> Scheduler_Init()
|
+--> StateMachine_Init()
|
+--> Future Modules
|
+--> UART
+--> OLED
+--> BQ76920
+--> Battery
+--> MPPT
*/

#ifndef SYSTEM_H
#define SYSTEM_H

// Public APIs

// Initialize complete firmware system
void System_Init(void);

#endif
