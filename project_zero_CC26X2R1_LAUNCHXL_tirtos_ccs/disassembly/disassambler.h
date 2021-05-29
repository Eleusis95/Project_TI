#ifndef DISASSAMBLER_H_
#define DISASSAMBLER_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands/localtypes.h"

frame_segtion disassambler_fuction(frame_recieve frame);/*disassambler function*/
frame_convert convertions(frame_segtion frame_segmented);/*convertion function*/

uint8_t convert_id(char *ID);
static uint8_t* convert_public_key(char* PublicKey);
static uint8_t* convert_encrypted_msg(char* EncryptedMssg);
uint8_t* datahex(char* buf);
void get16Key(aes_special_key *aes_key_type);

#endif /* DISASSAMBLER_H_ */
