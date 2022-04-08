/*
 * MDIO_Private.h
 *
 *  Created on: Jan 15, 2022
 *      Author: Dell
 */

#ifndef MCAL_MDIO_MDIO_PRIVATE_H_
#define MCAL_MDIO_MDIO_PRIVATE_H_

#define PORT_HIGH   255

// t3ref register ports from data sheet "register summary"

#define PORTA     *((volatile uint8*)0x3B)  // volatile 3ashn myhslh optimization 3ash acess hardware
#define DDRA     *((volatile uint8*)0x3A)
#define PINA     *((volatile uint8*)0x39)

#define PORTB     *((volatile uint8*)0x38)  // volatile 3ashn myhslh optimization 3ash acess hardware
#define DDRB    *((volatile uint8*)0x37)
#define PINB    *((volatile uint8*)0x36)

#define PORTC     *((volatile uint8*)0x35)  // volatile 3ashn myhslh optimization 3ash acess hardware
#define DDRC     *((volatile uint8*)0x34)
#define PINC     *((volatile uint8*)0x33)

#define PORTD     *((volatile uint8*)0x32)  // volatile 3ashn myhslh optimization 3ash acess hardware
#define DDRD     *((volatile uint8*)0x31)
#define PIND     *((volatile uint8*)0x30)


#endif /* MCAL_MDIO_MDIO_PRIVATE_H_ */
