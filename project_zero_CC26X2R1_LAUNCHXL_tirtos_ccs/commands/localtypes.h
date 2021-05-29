#ifndef LOCALTYPES_H_
#define LOCALTYPES_H_
#include <stdint.h>


#define publicKey_len 4
#define encryptedmsg_len 16

/******************Basic types*******************/
typedef struct /*private key type*/
{
	uint8_t Data[12];
}tuint96;

typedef struct /*public key type*/
{
	uint8_t Data[4]; /** */
}tuint4;

typedef struct /*Aes key type & commad*/
{
	uint8_t Data[16];
}tuint128;

/****************assambler types*****************/
typedef struct {
	char* ID;
	char* PublicKey;
	char* EncryptedMssg;
}frame_segtion;

typedef struct {
	uint8_t uID;
	uint8_t uPublicKey[publicKey_len];
	uint8_t uEncryptedMsg[encryptedmsg_len];
}frame_convert;

/****************AES types**********************/
typedef struct {/*private id and private key type*/
	uint8_t uIDPrivateKey;
	tuint96 uPrivateKey;
}public_key_type;

typedef struct { /*AES key type*/
	tuint96 PrivateKey;
	tuint4	PublicKey;
	tuint128 AESKey;
}aes_special_key;


/*comands*/

typedef enum Actions_tasks {Lock,UnLock,Truck,Light,Horn,Panic,Engine,NoAction};

typedef char* frame_recieve; /*frame type*/


#endif /* DISASSAMBLER_H_ */
