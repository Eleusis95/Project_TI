#include "disassambler.h"
#include <stdio.h>


#define IDpos 0
#define PublicKeypos 1
#define Encryptmsgposc 2


#define hexArray_len 2

frame_segtion disassambler_fuction(frame_recieve frame) {

	frame_segtion FrameParts;
	uint8_t PosId = 0;
	char GobalsegtionSeparator[2]= {';'};
	uint8_t lenghtframe = strlen(frame);
	char* token;
	token = strtok(frame,GobalsegtionSeparator);
	FrameParts.ID = token;
	while(token!=NULL && PosId<=1){
	    token = strtok(NULL, GobalsegtionSeparator);
	    if(PosId ==0){ FrameParts.PublicKey = token;}
	    else if(PosId>0){ FrameParts.EncryptedMssg = token;}
	    PosId++;
	}

	return FrameParts;
}
frame_convert convertions(frame_segtion frame_segmented) {
	frame_convert convertion;
	convertion.uID = convert_id(frame_segmented.ID);
	/*****Convertion of public key*******/
	int counter_uArray = 0;
	char cHexArray[hexArray_len];
	char* aux;
	size_t len = strlen(frame_segmented.PublicKey);
	if (len % 2 != 0) { len = len + 1; }
	for (int bufcounter = 0; bufcounter < len; bufcounter += 2) {
		aux = &frame_segmented.PublicKey[bufcounter];
		memcpy(cHexArray, aux, hexArray_len);
		sscanf(cHexArray, "%x", &convertion.uPublicKey[counter_uArray]);
		if (counter_uArray < publicKey_len)
			counter_uArray++;
	}
	/****Convertion of encrypted message****/
	counter_uArray = 0;
	memset(cHexArray,0, hexArray_len);
	len = strlen(frame_segmented.EncryptedMssg);
	if (len % 2 != 0) { len = len + 1; }
	for (int bufcounter = 0; bufcounter < len; bufcounter += 2) {
		aux = &frame_segmented.EncryptedMssg[bufcounter];
		memcpy(cHexArray, aux, hexArray_len);
		sscanf(cHexArray, "%x", &convertion.uEncryptedMsg[counter_uArray]);
		if (counter_uArray < encryptedmsg_len)
			counter_uArray++;
	}
	
	return convertion;
}

uint8_t convert_id(char* ID) {
	return (uint8_t)atoi(ID);
}

void get16Key(aes_special_key *aes_key_type) {
    int i = 0;
    for (; i < 16; i++) {
        if (i < 12) {
            aes_key_type->AESKey.Data[i] = aes_key_type->PrivateKey.Data[i];
        }
        else {
            aes_key_type->AESKey.Data[i] = aes_key_type->PublicKey.Data[i - 12];
        }
    }
}
