BUILD?=config.build
INSTALL?=config.install
SCONS?=scons
OPTFLAGS?=
PREFIX?=/usr/local

.PHONY: build install devel clean

build:
	test -f $(BUILD) || \
		echo -n "$(SCONS) --flags=\"$(OPTFLAGS)\" --prefix=\"$(PREFIX)\" --with-examples" \
		> $(BUILD)
	sh $(BUILD)

install: build
	cp -f $(BUILD) $(INSTALL)
	echo -n " --install" >> $(INSTALL)
	sh $(INSTALL)

devel:
	$(SCONS) --flags="$(OPTFLAGS)" --with-devel

clean:
	$(SCONS) -c || :
	rm -f config.*
	rm -f hello-example
	rm -f src/config.h
	rm -fr .scon*
	find . -name \*.o -type f -delete
