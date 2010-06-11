/*
 * This is the header file for the MD5 message-digest algorithm.
 * The algorithm is due to Ron Rivest.  This code was
 * written by Colin Plumb in 1993, no copyright is claimed.
 * This code is in the public domain; do with it what you wish.
 *
 * Equivalent code is available from RSA Data Security, Inc.
 * This code has been tested against that, and is equivalent,
 * except that you don't need to include two pages of legalese
 * with every copy.
 * To compute the message digest of a chunk of bytes, declare an
 * MD5Context structure, pass it to MD5Init, call MD5Update as
 * needed on buffers full of bytes, and then call MD5Final, which
 * will fill a supplied 16-byte array with the digest.
 *
 */

#ifndef _TXMPP_MD5_H_
#define _TXMPP_MD5_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef long unsigned int uint32;
typedef struct MD5Context MD5_CTX;

#define md5byte unsigned char

struct MD5Context {
  uint32 buf[4];
  uint32 bits[2];
  uint32 in[16];
};

void MD5Init(struct MD5Context *context);
void MD5Update(struct MD5Context *context, md5byte const *buf, unsigned len);
void MD5Final(unsigned char digest[16], struct MD5Context *context);
void MD5Transform(uint32 buf[4], uint32 const in[16]);

#ifdef __cplusplus
};
#endif

#endif  // _TXMPP_MD5_H_
