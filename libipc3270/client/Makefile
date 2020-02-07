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

MODULE_NAME=ipc3270
PACKAGE_NAME=ipc3270
PRODUCT_NAME=pw3270

MAIN_SOURCES= \
	$(wildcard src/core/*.cc) \
	$(wildcard src/core/linux/*.cc) \
	$(wildcard src/core/linux/*.rc) \
	$(wildcard src/host/*.cc) \
	$(wildcard src/session/*.cc) \
	$(wildcard src/session/local/*.cc) \
	$(wildcard src/session/remote/*.cc) \
	$(wildcard src/session/remote/linux/*.cc)

DYNAMIC_SOURCES= \
	$(wildcard src/core/linux/dynamic/*.cc)

TEST_SOURCES= \
	$(wildcard src/testprogram/*.cc)

TARGETS= \
	linux-lib devel

#---[ Tools ]----------------------------------------------------------------------------

CXX=g++
LD=g++
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
DLLTOOL=no

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
	src/include/*.h \
	$(BASEDIR)/common/src/include/*.h \
	$(BASEDIR)/client/src/include/lib3270/*.h \
	$(BASEDIR)/client/src/include/lib3270/ipc/*.h \

CFLAGS= \
	-g -O2 -pthread -fPIC -std=gnu++11 -DHAVE_CONFIG_H \
	-I$(BASEDIR)/common/src/include \
	-Isrc/include \
	-DBUILD_DATE=`date +%Y%m%d` \
	-DLOCALEDIR=$(localedir) \
	-DLIB3270_NAME=3270 -DLIB3270_REVISION=20200206 \
	-I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include

LDFLAGS=\
	 -pthread

LIBS= \
	 \
	 \
	 \
	 \
	-l3270 \
	-ldbus-1

#---[ Debug Rules ]----------------------------------------------------------------------

$(OBJDBG)/%.o: \
	%.cc \
	$(DEPENDS)

	@echo $< ...
	@$(MKDIR) $(@D)

	@$(CXX) \
		$(CFLAGS) \
		-Wall -Wextra -fstack-check \
		-DDEBUG=1 \
		-o $@ \
		-c $<

$(OBJDBG)/%.o: \
	%.rc

	@echo $< ...
	@$(MKDIR) $(@D)
	@$(WINDRES) $< -O coff -o $@

#---[ Release Rules ]--------------------------------------------------------------------

$(OBJRLS)/%.o: \
	%.cc \
	$(DEPENDS)

	@echo $< ...
	@$(MKDIR) $(@D)
	@$(CXX) \
		$(CFLAGS) \
		-DNDEBUG=1 \
		-o $@ \
		-c $<

$(OBJRLS)/%.o: \
	%.rc

	@echo $< ...
	@$(MKDIR) $(@D)
	@$(WINDRES) $< -O coff -o $@

#---[ Misc Rules ]-----------------------------------------------------------------------

$(POTDIR)/$(MODULE_NAME)/%.pot: \
	%.cc

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
	$(BINRLS)/lib$(MODULE_NAME).so.5.3 \
	$(BINRLS)/lib$(MODULE_NAME).a \
	$(POTDIR)/$(MODULE_NAME).pot

Release: \
	$(BINRLS)/lib$(MODULE_NAME).so.5.3 \
	$(BINRLS)/lib$(MODULE_NAME).static.a

$(BINRLS)/lib$(MODULE_NAME).so.5.3: \
	$(foreach SRC, $(basename $(MAIN_SOURCES)), $(OBJRLS)/$(SRC).o) \
	$(foreach SRC, $(basename $(DYNAMIC_SOURCES)), $(OBJRLS)/$(SRC).o)

	@$(MKDIR) $(@D)
	@echo $< ...
	@$(LD) \
		-shared \
		-Wl,-soname,$(@F) \
		-o $@ \
		$(LDFLAGS) \
		$^ \
		$(LIBS)

$(BINRLS)/lib$(MODULE_NAME).static.a: \
	$(foreach SRC, $(basename $(MAIN_SOURCES)), $(OBJRLS)/$(SRC).o)

	@$(MKDIR) $(@D)
	@echo $< ...

	@$(AR) rcs $@ $^


#---[ Install Targets ]------------------------------------------------------------------

install: \
       $(foreach TARGET, $(TARGETS), install-$(TARGET))

install-linux-lib: \
	$(BINRLS)/lib$(MODULE_NAME).so.5.3

	@$(MKDIR) \
		$(DESTDIR)$(libdir)

	@$(INSTALL_PROGRAM) \
		$(BINRLS)/lib$(MODULE_NAME).so.5.3 \
		$(DESTDIR)$(libdir)/lib$(MODULE_NAME).so.5.3
		
	@$(LN_S) \
		lib$(MODULE_NAME).so.5.3 \
		$(DESTDIR)$(libdir)/lib$(MODULE_NAME).so

install-windows-lib: \
	$(BINRLS)/lib$(MODULE_NAME).so.5.3

	@$(MKDIR) \
		$(DESTDIR)$(bindir)

	@$(INSTALL_PROGRAM) \
		$(BINRLS)/lib$(MODULE_NAME).so.5.3 \
		$(DESTDIR)$(bindir)/lib$(MODULE_NAME).so.5.3
		
	@$(MKDIR) \
		$(DESTDIR)$(libdir)

	@$(DLLTOOL) \
		--input-def $(BINRLS)/lib$(MODULE_NAME).def \
		--dllname lib$(MODULE_NAME).dll \
		--output-lib $(DESTDIR)$(libdir)/lib$(MODULE_NAME).dll.a

	@$(MKDIR) \
		$(DESTDIR)$(datarootdir)/$(PRODUCT_NAME)/def

	@$(INSTALL_DATA) \
		$(BINRLS)/lib$(MODULE_NAME).def \
		$(DESTDIR)$(datarootdir)/$(PRODUCT_NAME)/def

install-static: \
	$(BINRLS)/lib$(MODULE_NAME).static.a

	@$(MKDIR) \
		$(DESTDIR)$(libdir)

	@$(INSTALL_PROGRAM) \
		$(BINRLS)/lib$(MODULE_NAME).static.a \
		$(DESTDIR)$(libdir)

	@$(MKDIR) \
		$(DESTDIR)$(libdir)/pkgconfig

	@$(INSTALL_DATA) \
		sdk/ipc3270-static.pc \
		$(DESTDIR)$(libdir)/pkgconfig/ipc3270-static.pc

install-devel:

	@$(MKDIR) \
		$(DESTDIR)$(includedir)/lib3270

	@$(MKDIR) \
		$(DESTDIR)$(includedir)/lib3270/ipc

	@$(INSTALL_DATA) \
		src/include/lib3270/ipc.h \
		$(DESTDIR)$(includedir)/lib3270

	@$(INSTALL_DATA) \
		src/include/lib3270/ipc/*.h \
		$(DESTDIR)$(includedir)/lib3270/ipc

	# Install PKG-CONFIG files
	@$(MKDIR) \
		$(DESTDIR)$(libdir)/pkgconfig

	@$(INSTALL_DATA) \
		sdk/ipc3270.pc \
		$(DESTDIR)$(libdir)/pkgconfig/ipc3270.pc

#---[ Misc Targets ]---------------------------------------------------------------------

$(POTDIR)/$(MODULE_NAME).pot: \
	$(foreach SRC, $(basename $(MAIN_SOURCES)), $(POTDIR)/$(MODULE_NAME)/$(SRC).pot)

	@rm -f $@
	@mkdir -p `dirname $@`
	@$(MSGCAT) --sort-output $^ > $@

locale: \
	$(POTDIR)/$(MODULE_NAME).pot


#---[ Debug Targets ]--------------------------------------------------------------------

Debug: \
	$(BINDBG)/$(MODULE_NAME)-client

$(BINDBG)/$(MODULE_NAME)-client: \
	$(foreach SRC, $(basename $(TEST_SOURCES)), $(OBJDBG)/$(SRC).o) \
	$(BINDBG)/lib$(MODULE_NAME).so.5.3

	@$(MKDIR) $(@D)
	@echo $< ...
	@$(LD) \
		-o $@ \
		$^ \
		-L$(BINDBG) \
		-Wl,-rpath,$(BINDBG) \
		 -pthread \
		$(LDFLAGS) \
		$(LIBS)


$(BINDBG)/lib$(MODULE_NAME).so.5.3: \
	$(foreach SRC, $(basename $(MAIN_SOURCES)), $(OBJDBG)/$(SRC).o) \
	$(foreach SRC, $(basename $(DYNAMIC_SOURCES)), $(OBJDBG)/$(SRC).o)

	@$(MKDIR) $(@D)
	@echo $< ...
	@$(LD) \
		-shared \
		-Wl,-soname,$(@F) \
		-o $@ \
		$(LDFLAGS) \
		$^ \
		$(LIBS)


run: \
	$(BINDBG)/$(MODULE_NAME)-client

ifeq ($(VALGRIND),no)

	@LD_LIBRARY_PATH=$(BINDBG) \
		$(BINDBG)/$(MODULE_NAME)-client

else
	@touch valgrind.suppression

	@LD_LIBRARY_PATH=$(BINDBG) \
		$(VALGRIND) --leak-check=full --track-origins=yes --gen-suppressions=all --suppressions=valgrind.suppression \
		$(BINDBG)/$(MODULE_NAME)-client
endif

#---[ Clean Targets ]--------------------------------------------------------------------

clean: \
	cleanDebug \
	cleanRelease

cleanDebug:

	@rm -fr $(OBJDBG)
	@rm -fr $(BINDBG)

cleanRelease:

	@rm -fr $(OBJRLS)
	@rm -fr $(BINRLS)
	@rm -fr $(POTDIR)
	@rm -f $(MODULE_NAME).pot

clean: \
	cleanDebug \
	cleanRelease


