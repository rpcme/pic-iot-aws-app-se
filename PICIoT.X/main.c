#include <string.h>
#include "system.h"
#include "uart1.h"
#include "delay.h"
#include "debug_print.h"

#include "CryptoAuth_init.h"
#include "CryptoAuthenticationLibrary/basic/atca_basic.h"

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#define CFG_DEBUG_PRINT (1)
#define ENABLE_DEBUG_IOT_APP_MSGS (1)

/** \brief global storage for signer certificate */
uint8_t g_signer_cert[1024];
size_t  g_signer_cert_size = sizeof(g_signer_cert);

/** \brief global storage for device certificate */
uint8_t g_device_cert[1024];
size_t  g_device_cert_size = sizeof(g_device_cert);

/** \brief global storage for the challenge data to sign by the device */
uint8_t g_challenge[32];
uint8_t g_response[64];

extern uint8_t g_signer_ca_public_key[64];

int main(void)
{
    debug_init("pic-iot");
    SYSTEM_Initialize();
    
    // Initialize the module for use
    if ( ! CryptoAuth_Initialize() ) {
        printf("CryptoAuth_Initialize(): failed\n");
        while(1);
    }

    char se_version[60];
    if ( ATCA_SUCCESS != atcab_version(se_version) ) {
        printf("Failed to retrieve version number\n");
        while(1);        
    }

    printf("atcab_version: %s\n", se_version);
    
//    char serial_number[ATCA_SERIAL_NUM_SIZE];
    unsigned int tick = 0;
	while (1)
	{
        printf("tick %d\n", tick);
//        get_serial_number(serial_number);
        //printf("serial number: %s\n", serial_number);
        DELAY_milliseconds(2000);
        tick++;
	}
   
	return 0;
}
