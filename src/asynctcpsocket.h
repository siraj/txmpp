/*
 * libjingle
 * Copyright 2004--2010, Google Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TXMPP_ASYNCTCPSOCKET_H_
#define TXMPP_ASYNCTCPSOCKET_H_

#ifndef NO_CONFIG_H
#include "config.h"
#endif

#include "asyncpacketsocket.h"
#include "socketfactory.h"

namespace txmpp {

// Simulates UDP semantics over TCP.  Send and Recv packet sizes
// are preserved, and drops packets silently on Send, rather than
// buffer them in user space.
class AsyncTCPSocket : public AsyncPacketSocket {
 public:
  static AsyncTCPSocket* Create(SocketFactory* factory);
  explicit AsyncTCPSocket(AsyncSocket* socket);
  virtual ~AsyncTCPSocket();

  virtual int Send(const void* pv, size_t cb);
  virtual int SendTo(const void* pv, size_t cb, const SocketAddress& addr);

  signal1<AsyncTCPSocket*> SignalConnect;
  signal2<AsyncTCPSocket*, int> SignalClose;

 protected:
  int SendRaw(const void* pv, size_t cb);
  virtual void ProcessInput(char* data, size_t& len);

 private:
  int Flush();

  // Called by the underlying socket
  void OnConnectEvent(AsyncSocket* socket);
  void OnReadEvent(AsyncSocket* socket);
  void OnWriteEvent(AsyncSocket* socket);
  void OnCloseEvent(AsyncSocket* socket, int error);

  char* inbuf_, * outbuf_;
  size_t insize_, inpos_, outsize_, outpos_;
};

}  // namespace txmpp

#endif  // TXMPP_ASYNCTCPSOCKET_H_
