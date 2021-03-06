#
# "Software pw3270, desenvolvido com base nos códigos fontes do WC3270  e X3270
# (Paul Mattes Paul.Mattes@usa.net), de emulação de terminal 3270 para acesso a
# aplicativos mainframe. Registro no INPI sob o nome G3270.
#
# Copyright (C) <2008> <Banco do Brasil S.A.>
#
# Este programa é software livre. Você pode redistribuí-lo e/ou modificá-lo sob
# os termos da GPL v.2 - Licença Pública Geral  GNU,  conforme  publicado  pela
# Free Software Foundation.
#
# Este programa é distribuído na expectativa de  ser  útil,  mas  SEM  QUALQUER
# GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou  de  ADEQUAÇÃO
# A QUALQUER PROPÓSITO EM PARTICULAR. Consulte a Licença Pública Geral GNU para
# obter mais detalhes.
#
# Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este
# programa;  se  não, escreva para a Free Software Foundation, Inc., 59 Temple
# Place, Suite 330, Boston, MA, 02111-1307, USA
#
# Contatos:
#
# perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
# erico.mendonca@gmail.com	(Erico Mascarenhas de Mendonça)
#

#---[ Library configuration ]------------------------------------------------------------

MODULE_NAME=ipcserver
SERVICE_NAME=ipc3270d
PACKAGE_NAME=ipc3270
PRODUCT_NAME=pw3270

CORE_SOURCES= \
	$(wildcard src/core/*.c) \
	$(wildcard src/core/methods/*.c) \
	$(wildcard src/core/linux/*.c)

PLUGIN_SOURCES= \
	$(wildcard src/plugin/*.c) \
	$(wildcard src/plugin/linux/*.rc)

SERVICE_SOURCES= \
	$(wildcard src/service/*.c) \
	$(wildcard src/service/linux/*.c) \
	$(wildcard src/service/linux/*.rc)

TEST_SOURCES= \
	$(wildcard src/testprogram/*.c)

#---[ Tools ]----------------------------------------------------------------------------

CC=gcc
LD=gcc
LN_S=ln -s
MKDIR=/usr/bin/mkdir -p
INSTALL=/usr/bin/install -c
INSTALL_DATA=${INSTALL} -m 644
INSTALL_PROGRAM=${INSTALL}
XGETTEXT=/usr/bin/xgettext
MSGCAT=/usr/bin/msgcat
WINDRES=no
AR=/usr/bin/ar
VALGRIND=no

#---[ Paths ]----------------------------------------------------------------------------

prefix=/usr/local
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
sbindir=${exec_prefix}/sbin
libdir=${exec_prefix}/lib
includedir=${prefix}/include
datarootdir=${prefix}/share
localedir=${datarootdir}/locale
docdir=${datarootdir}/doc/${PACKAGE_TARNAME}
sysconfdir=${prefix}/etc

BASEDIR=/opt/git/libipc3270

POTDIR=$(BASEDIR)/.pot

OBJDIR=.obj/$(MODULE_NAME)
OBJDBG=$(OBJDIR)/Debug
OBJRLS=$(OBJDIR)/Release

BINDIR=$(BASEDIR)/.bin
BINDBG=$(BINDIR)/Debug
BINRLS=$(BINDIR)/Release

#---[ Rules ]----------------------------------------------------------------------------

DEPENDS= \
	Makefile \
	$(BASEDIR)/common/src/include/*.h

LDFLAGS= \
	 -pthread

CFLAGS= \
	-g -O2 -pthread -fPIC -DHAVE_CONFIG_H \
	-I$(BASEDIR)/server/src/include \
	-I$(BASEDIR)/common/src/include \
	-DBUILD_DATE=`date +%Y%m%d` \
	-DLOCALEDIR=$(localedir) \
	-DLIB3270_NAME=3270 -DLIB3270_REVISION=20200206 -pthread -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/libdrm -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/uuid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
	-pthread -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/libdrm -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/uuid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
	-pthread -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/uuid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
	-I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include \
	-I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include

LIBS= \
	 \
	 \
	 \
	-lv3270 -l3270 -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 \
	-lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 \
	-Wl,--export-dynamic -lgmodule-2.0 -pthread -lgio-2.0 -lgobject-2.0 -lglib-2.0 \
	-ldbus-1 \
	-ldbus-glib-1 -ldbus-1 -lgobject-2.0 -lglib-2.0

#---[ Debug Rules ]----------------------------------------------------------------------

$(OBJDBG)/%.o: \
	%.c \
	$(DEPENDS)

	@echo $< ...
	@$(MKDIR) $(@D)

	@$(CC) \
		$(CFLAGS) \
		-Wall -Wextra -fstack-check \
		-DDEBUG=1 \
		-DPLUGIN_PATH=$(BINDBG) \
		-o $@ -c $<

$(OBJDBG)/%.o: \
	%.rc

	@echo $< ...
	@$(MKDIR) $(@D)
	@$(WINDRES) $< -O coff -o $@

#---[ Release Rules ]--------------------------------------------------------------------

$(OBJRLS)/%.o: \
	%.c \
	$(DEPENDS)

	@echo $< ...
	@$(MKDIR) $(@D)
	@$(CC) \
		$(CFLAGS) \
		-DNDEBUG=1 \
		-o $@ -c $<

$(OBJRLS)/%.o: \
	%.rc

	@echo $< ...
	@$(MKDIR) $(@D)
	@$(WINDRES) $< -O coff -o $@

#---[ Misc Rules ]-----------------------------------------------------------------------

$(POTDIR)/$(MODULE_NAME)/%.pot: \
	%.c

	@echo $(notdir $@) ...
	@$(MKDIR) $(@D)
	@$(XGETTEXT) \
		--language=C \
		--keyword=_ \
		--keyword=N_ \
		--keyword=MSG_:2 \
		--output=$@ \
		$<
	@touch $@

$(POTDIR)/$(MODULE_NAME)/%.pot: \
	%.rc

	@echo $< ...
	@$(MKDIR) $(@D)
	@touch $@


#---[ Release Targets ]------------------------------------------------------------------

all: \
	$(BINRLS)/$(MODULE_NAME).so \
	$(POTDIR)/$(MODULE_NAME).pot

Release: \
	$(BINRLS)/$(MODULE_NAME).so

$(BINRLS)/$(MODULE_NAME).so: \
	$(foreach SRC, $(basename $(PLUGIN_SOURCES)), $(OBJRLS)/$(SRC).o) \
	$(BINRLS)/lib$(MODULE_NAME).a	

	@$(MKDIR) $(@D)
	@echo $< ...
	@$(LD) \
		-shared -Wl,-soname,$(@F) \
		-o $@ \
		$(LDFLAGS) \
		$(foreach SRC, $(basename $(PLUGIN_SOURCES)), $(OBJRLS)/$(SRC).o) \
		-L$(BINRLS) -l$(MODULE_NAME) \
		$(LIBS)

$(BINRLS)/lib$(MODULE_NAME).a: \
	$(foreach SRC, $(basename $(CORE_SOURCES)), $(OBJRLS)/$(SRC).o)

	@$(MKDIR) $(@D)
	@echo $< ...

	@$(AR) rcs $@ $^


#---[ Install Targets ]------------------------------------------------------------------

install: \
	install-plugin

install-plugin: \
	$(BINRLS)/$(MODULE_NAME).so

	@$(MKDIR) $(DESTDIR)$(libdir)/$(PRODUCT_NAME)-plugins

	@$(INSTALL_PROGRAM) \
		$(BINRLS)/$(MODULE_NAME).so \
		$(DESTDIR)$(libdir)/$(PRODUCT_NAME)-plugins

#---[ Misc Targets ]---------------------------------------------------------------------

$(POTDIR)/$(MODULE_NAME).pot: \
	$(foreach SRC, $(basename $(CORE_SOURCES) $(PLUGIN_SOURCES) $(SERVICE_SOURCES)), $(POTDIR)/$(MODULE_NAME)/$(SRC).pot)

	@rm -f $@
	@mkdir -p `dirname $@`
	@$(MSGCAT) --sort-output $^ > $@

locale: \
	$(POTDIR)/$(MODULE_NAME).pot


#---[ Debug Targets ]--------------------------------------------------------------------

Debug: \
	$(BINDBG)/$(MODULE_NAME).so \
	$(BINDBG)/$(MODULE_NAME)

$(BINDBG)/lib$(MODULE_NAME).a: \
	$(foreach SRC, $(basename $(CORE_SOURCES)), $(OBJDBG)/$(SRC).o)

	@$(MKDIR) $(@D)
	@echo $< ...

	@$(AR) rcs $@ $^


$(BINDBG)/$(MODULE_NAME): \
	$(foreach SRC, $(basename $(TEST_SOURCES)), $(OBJDBG)/$(SRC).o)

	@$(MKDIR) $(@D)
	@echo $< ...
	@$(LD) \
		-o $@ \
		$^ \
		-L$(BINDBG) \
		-Wl,-rpath,$(BINDBG) \
		$(LDFLAGS) \
		$(LIBS)

$(BINDBG)/$(SERVICE_NAME): \
	$(foreach SRC, $(basename $(SERVICE_SOURCES)), $(OBJDBG)/$(SRC).o) \
	$(BINDBG)/lib$(MODULE_NAME).a	

	@$(MKDIR) $(@D)
	@echo $< ...
	@$(LD) \
		-o $@ \
		$(foreach SRC, $(basename $(SERVICE_SOURCES)), $(OBJDBG)/$(SRC).o) \
		-L$(BINDBG) \
		-Wl,-rpath,$(BINDBG) \
		$(LDFLAGS) \
		$(LIBS) \
		-l$(MODULE_NAME) \
		$(GLIB_LIBS)

$(BINDBG)/$(MODULE_NAME).so: \
	$(foreach SRC, $(basename $(PLUGIN_SOURCES)), $(OBJDBG)/$(SRC).o) \
	$(BINDBG)/lib$(MODULE_NAME).a	

	@$(MKDIR) $(@D)
	@echo $< ...
	@$(LD) \
		-shared -Wl,-soname,$(@F) \
		-o $@ \
		$(LDFLAGS) \
		$(foreach SRC, $(basename $(PLUGIN_SOURCES)), $(OBJDBG)/$(SRC).o) \
		-L$(BINDBG) -l$(MODULE_NAME) \
		$(LIBS)


run: \
	run-plugin

check-plugin: \
	$(BINDBG)/$(MODULE_NAME).so \
	$(BINDBG)/$(MODULE_NAME)

ifeq ($(VALGRIND),no)

	@LD_LIBRARY_PATH=$(BINDBG) \
		$(BINDBG)/$(MODULE_NAME)

else
	@touch valgrind.suppression

	@LD_LIBRARY_PATH=$(BINDBG) \
		$(VALGRIND) --leak-check=full --track-origins=yes --gen-suppressions=all --suppressions=valgrind.suppression \
			$(BINDBG)/$(MODULE_NAME)
endif

run-plugin: \
	$(BINDBG)/$(MODULE_NAME).so \
	$(BINDBG)/$(MODULE_NAME)

	@LD_LIBRARY_PATH=$(BINDBG) \
		$(BINDBG)/$(MODULE_NAME)

run-service: \
	$(BINDBG)/$(SERVICE_NAME)

	@LD_LIBRARY_PATH=$(BINDBG) \
		$(BINDBG)/$(PACKAGE_NAME)d


#---[ Clean Targets ]--------------------------------------------------------------------

clean: \
	cleanDebug \
	cleanRelease

	@rm -fr $(BASEDIR)/.tmp/$(MODULE_NAME)
	@rm -fr $(POTDIR)/$(MODULE_NAME).pot
	@rm -fr src/include/marshal

cleanDebug:

	@rm -fr $(OBJDBG)
	@rm -fr $(BINDBG)
	@rm -fr $(OBJDIR)/marshal
	@rm -f src/v3270/marshal.h
	@rm -f src/v3270ft/marshal.h

cleanDebug-plugin:
	@rm -fr $(OBJDBG)
	@rm -fr $(BINDBG)
	@rm -fr $(OBJDIR)/marshal
	@rm -f src/v3270/marshal.h
	@rm -f src/v3270ft/marshal.h

cleanDebug-service:
	@rm -fr $(OBJDBG)
	@rm -fr $(BINDBG)
	@rm -fr $(OBJDIR)/marshal
	@rm -f src/v3270/marshal.h
	@rm -f src/v3270ft/marshal.h

cleanRelease:

	@rm -fr $(OBJRLS)
	@rm -fr $(BINRLS)
	@rm -fr $(POTDIR)
	@rm -f $(MODULE_NAME).pot

clean: \
	cleanDebug \
	cleanRelease


