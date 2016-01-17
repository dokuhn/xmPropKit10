## TODO: emacs TAGS sollen auch Systemheader-Dateien mit einbinden

## Versionsinfo
MAJOR_VERSION = 0
MINOR_VERSION = 1

# Specify the compiler to use
CC=arm-none-eabi-gcc
# Specify the assembler to use
AS=arm-none-eabi-as
# Specity the linker to use
LD=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
STRIP=arm-none-eabi-strip

JLINKEXE = /usr/bin/JLinkExe
JLINKOPT = -device xmc1100-64 -if SWD -speed 400

## Dateiname des Binaries
TARGET=out/main.bin

## alle Quelldateien hier einfuegen
SRCS =  DrvEEPROM.c  DrvGPIO.c  DrvI2C.c  DrvNVM.c  DrvSCU.c  DrvUSIC.c  init.c  main.c

## Suche nach Sourcen und Target Dateien in folgenden Verzeichnissen
## [2015-01-01 Thu 18:39] vpath macht das Makefile Leben leicht
VPATH = src

## Compiler-Einstellungen
INCLUDES = -I ./src
CFLAGS=  -mcpu=cortex-m0 -mthumb -g -ffunction-sections -Os -Wall $(INCLUDES)
# -Wformat=0 : Warnungen in printf/scanf ausschalten
# -ggdb : Debuginfo ins Binary
# -Werror : Warnungen als Fehler
# -O3 : Optimierung Stufe 3
# -Wall alles warnen
LIBSPEC= -L /usr/lib/arm-none-eabi/new/armv6-m/
LDFLAGS= -T linker_script.ld $(LIBSPEC) -lgcc
# -lncurses : ncurses einbinden

########################
define SEGGER_FLASH_SOFTDEVICE_CMD
r
loadbin $(TARGET) 0x10001000
r
g
exit
endef

########################
export SEGGER_FLASH_SOFTDEVICE_CMD

## 8<-----8<-----8<----- end of configure-section 8<-----8<-----8<-----

## Zielverzeichnis für Objektdateien
OBJDIR = ./obj
BINDIR = ./bin
## Objektdateien werden aus Quelldateien abgeleitet
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

## Abhaengigkeiten von Headerdateien werden automatisch generiert
DEPS:=$(OBJS:.o=.d)

## Zeitstempel des Makedurchlaufs (für Erzeugung tgz und encryption)
## einmalig merken
TIMESTAMP=$(shell date +%Y%m%d_%H%M%S)
TGZNAME:=$(notdir $(CURDIR))-$(TIMESTAMP).tgz
SYS := $(shell $(CC) -dumpmachine)
ifneq (,$(findstring /cygdrive/,$(PATH)))
	OS := Cygwin
else
ifneq (,$(findstring WINDOWS,$(PATH)))
	OS := Windows
else
	OS := $(shell uname -s)
endif
endif

ifeq ($(OS), Linux)
	MAILER := icedove
else
	MAILER := thunderbird
endif

## ein FIXME Idiom sieht in Makefile so aus:
## $(warning "FIXME: bla bla bla")

.PHONY: all tags
all: $(TARGET)

# $(TARGET) : $(OBJS)
# 	@mkdir -p $(@D)
# 	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(TARGET)
#	cp $(TARGET) ../lib
#	ln -sf $(TARGET) $(basename $(TARGET)) # FIXME das mit dem ln müsste man nochmal genauer machen

-include $(DEPS)

$(OBJS) : Makefile

# $(OBJDIR)/%.so : ($OBJS)
# 	@if ! [ -d ./obj ] ; then mkdir ./obj ; fi
# 	$(CC) -c $(CFLAGS) -shared -MMD -o $@ $<

$(OBJDIR)/%.o: %.c
	@if ! [ -d ./obj ] ; then mkdir ./obj ; fi
#	$(CC) -c $(CFLAGS) -MMD -o $@ $<
	$(CC) -c $(CFLAGS) -MD -o $@ $< # -MD mit System-Header-Dateien Abhängigkeit

.PHONY: print-vars
print-vars:
	@echo "SRCS="$(SRCS)
	@echo "DEPS="$(DEPS)
	@echo "OBJS="$(OBJS)
	@echo "Zeitstempel make-Durchlauf '$(TIMESTAMP)'"
	@echo "TGZNAME="$(TGZNAME)
	@echo "OS="$(OS)


# a:
# x:
# h:
# print-deps: a x h
# 	@echo $^

# .PHONY: depend
# depend: .depend

# .depend: $(SRCS)
# 	rm -f ./.depend
# 	$(CC) $(CFLAGS) -MM $^>>./.depend;

#include .depend

# .PHONY: TAGS
# TAGS tags: $(TARGET)
# 	rm -f TAGS
# 	cat $(DEPS) | sort -u | sed 's/.*:.*$$//' | tr -d '\\' | tr "\n" " " | xargs -n 1 readlink -f | sort -u | xargs etags -a

TAGFILES = $(OBJS:.o=.t)

# prune the .d files a bit to get a list of files for etags to scan
%.t: %.d
	cat $< | sed -e 's/.*: //' -e 's# /#\n/#g' -e 's# ../#\n../#g' -e 's/ \\//' | grep '\S' > $@
	cat $@ | xargs etags -a

.PHONY: tags
tags : $(TAGFILES)

.PHONY:  clean
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS) $(TAGFILES) ./TAGS

.PHONY:  distclean
distclean: clean
	rm -f TAGS items.dat nodes.dat

.PHONY:  tgz
tgz: # clean
	tar cvzf ../$(TGZNAME) -C .. --exclude=*~ --exclude=.git $(notdir $(CURDIR))

.PHONY:  release-tgz
release-tgz:  dist-clean tgz

.PHONY: encrypt
encrypt: release-tgz
	gpg -c ../$(TGZNAME)

out/main.elf: $(OBJS)
	@if ! [ -d ./out ] ; then mkdir ./out ; fi
	$(LD) $(OBJS) -o $@ -Wl,$(LDFLAGS) -nostartfiles

$(TARGET): out/main.elf
	$(OBJCOPY) -O binary $< $@

$(OBJDIR)/%.hex: $(OBJDIR)/%.elf
	$(OBJCOPY) -O ihex $< $@


flash: $(TARGET)
	@echo "$$SEGGER_FLASH_SOFTDEVICE_CMD" | $(JLINKEXE) $(JLINKOPT)
