/*
 * libjingle
 * Copyright 2004--2005, Google Inc.
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

#if defined(_MSC_VER) && _MSC_VER < 1300
#pragma warning(disable:4786)
#endif

#include "txmpp/base/asyncpacketsocket.h"

namespace txmpp {

AsyncPacketSocket::AsyncPacketSocket(AsyncSocket* socket) : socket_(socket) {
}

AsyncPacketSocket::~AsyncPacketSocket() {
  delete socket_;
}

SocketAddress AsyncPacketSocket::GetLocalAddress() const {
  return socket_->GetLocalAddress();
}

SocketAddress AsyncPacketSocket::GetRemoteAddress() const {
  return socket_->GetRemoteAddress();
}

int AsyncPacketSocket::Bind(const SocketAddress& addr) {
  return socket_->Bind(addr);
}

int AsyncPacketSocket::Connect(const SocketAddress& addr) {
  return socket_->Connect(addr);
}

int AsyncPacketSocket::Send(const void *pv, size_t cb) {
  return socket_->Send(pv, cb);
}

int AsyncPacketSocket::SendTo(
    const void *pv, size_t cb, const SocketAddress& addr) {
  return socket_->SendTo(pv, cb, addr);
}

int AsyncPacketSocket::Close() {
  return socket_->Close();
}

Socket::ConnState AsyncPacketSocket::GetState() const {
  return socket_->GetState();
}

int AsyncPacketSocket::GetOption(Socket::Option opt, int* value) {
  return socket_->GetOption(opt, value);
}

int AsyncPacketSocket::SetOption(Socket::Option opt, int value) {
  return socket_->SetOption(opt, value);
}

int AsyncPacketSocket::GetError() const {
  return socket_->GetError();
}

void AsyncPacketSocket::SetError(int error) {
  return socket_->SetError(error);
}

}  // namespace txmpp
