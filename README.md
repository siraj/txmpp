txmpp
=====

_txmpp_ is a C++ XMPP library created from the non-[XEP-0166][xep0166] portions
of [libjingle][libjingle] with various bits removed and tweaked.

The [motivating factor][motivating-factor] for "creating" _txmpp_ was the lack
of [permissively licenced alternatives][permissive].

If you don't mind a library with a [copyleft][copyleft] license you might also
try [gloox][gloox].

### Requirements

 * [Expat][expat] >= 2.0.1
 * [OpenSSL][openssl]
 * [SCons][scons] (build)

### Build and Install

    make
    make install

### Getting Started

See the `src/examples` directory.

### License

This work is licensed under the New BSD License (see the LICENSE file).

[xep0166]: http://xmpp.org/extensions/xep-0166.html
[motivating-factor]: http://www.silassewell.com/blog/2010/06/16/txmpp-a-bsd-licensed-cpp-xmpp-library/
[libjingle]: http://code.google.com/p/libjingle/
[permissive]: http://en.wikipedia.org/wiki/Permissive_license
[copyleft]: http://en.wikipedia.org/wiki/Copyleft
[gloox]: http://camaya.net/gloox/
[expat]: http://expat.sourceforge.net/
[openssl]: http://www.openssl.org/
[scons]: http://www.scons.org/
