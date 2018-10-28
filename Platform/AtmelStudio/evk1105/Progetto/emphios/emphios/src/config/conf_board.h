/**
 * \file
 *
 * \brief EVK1105 board configuration template
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef CONF_BOARD_H
#define CONF_BOARD_H

// Enable on-board AT45DBX interface (SPI)
#define CONF_BOARD_AT45DBX

// Enable on-board SD/MMC card interface (SPI)
#define CONF_BOARD_SD_MMC_SPI

// Enable TWI interface (TWI)
#define CONF_BOARD_TWI

// Enable UART Communication Port interface (UART)
#define CONF_BOARD_COM_PORT


#define FMCK_HZ                           62092800
#define FCPU_HZ                           FMCK_HZ
#define FHSB_HZ                           FCPU_HZ
#define FPBB_HZ                           FMCK_HZ
#define FPBA_HZ                           FMCK_HZ


#endif // CONF_BOARD_H
