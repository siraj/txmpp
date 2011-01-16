BUILD?=config.build
INSTALL?=config.install
SCONS?=scons
OPTFLAGS?=
PREFIX?=/usr/local

$(BUILD):
	echo -n "$(SCONS) --flags=\"$(OPTFLAGS)\" --prefix=\"$(PREFIX)\"" > $(BUILD)
	sh $(BUILD)

build: $(BUILD)

install: $(BUILD)
	cp -f $(BUILD) $(INSTALL)
	echo -n " --install" >> $(INSTALL)
	sh $(INSTALL)

devel:
	$(SCONS) --flags="$(OPTFLAGS)" --with-devel

clean:
	$(SCONS) -c || :
	rm -f config.*
	find . -name \*.o -type f -delete
