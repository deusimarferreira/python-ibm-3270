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

PACKAGE_NAME=ipc3270
PRODUCT_NAME=pw3270
LIBNAME=libipc3270

CLIENT_TARGETS= \
	linux-lib devel

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
POTDIR=$(BASEDIR)/.pot
GETTEXT_PACKAGE=libipc3270

BASEDIR=/opt/git/libipc3270

BINDIR=$(BASEDIR)/.bin
BINDBG=$(BINDIR)/Debug
BINRLS=$(BINDIR)/Release

#---[ Tools ]----------------------------------------------------------------------------

LN_S=ln -s
MKDIR=/usr/bin/mkdir -p
INSTALL=/usr/bin/install -c
INSTALL_DATA=${INSTALL} -m 644
INSTALL_PROGRAM=${INSTALL}
DOXYGEN=
MSGCAT=/usr/bin/msgcat

#---[ Release Targets ]------------------------------------------------------------------

all: \
	$(BINRLS)/ipcserver.so \
	$(BINRLS)/libipc3270.so.5.3 \
	locale/$(GETTEXT_PACKAGE).pot

plugin: \
	$(BINRLS)/ipcserver.so

library: \
	$(BINRLS)/libipc3270.so.5.3

$(BINRLS)/ipcserver.so:
	@$(MAKE) -C server $@	

$(BINRLS)/libipc3270.so.5.3:
	@$(MAKE) -C client $@	

locale/$(GETTEXT_PACKAGE).pot:

	@rm -f $@
	@$(MKDIR) $(@D)
	@$(MAKE) -C client locale
	@$(MAKE) -C server locale
	@$(MSGCAT) \
		--sort-output \
		$(POTDIR)/ipc3270.pot \
		$(POTDIR)/ipcserver.pot \
		> $@


#---[ Install Targets ]------------------------------------------------------------------

install: \
	install-plugin \
	install-locale \
	$(foreach CLIENT_TARGET, $(CLIENT_TARGETS), install-$(CLIENT_TARGET))

install-locale: \
	locale/$(LIBNAME).pot
	@$(MAKE) -C locale DESTDIR=$(DESTDIR) install

install-plugin:
	@$(MAKE) -C server DESTDIR=$(DESTDIR) install

install-linux-lib:
	@$(MAKE) -C client DESTDIR=$(DESTDIR) install-linux-lib

install-static:
	@$(MAKE) -C client DESTDIR=$(DESTDIR) install-static

install-devel: \
	locale/$(LIBNAME).pot

	@$(MAKE) -C client DESTDIR=$(DESTDIR) install-devel

	# Install translation files
	@$(MKDIR) \
		$(DESTDIR)$(datarootdir)/$(PRODUCT_NAME)/pot

	@$(INSTALL_DATA) \
		locale/$(LIBNAME).pot \
		$(DESTDIR)$(datarootdir)/$(PRODUCT_NAME)/pot

install-windows-lib:
	@$(MAKE) -C client DESTDIR=$(DESTDIR) install-windows-lib

doc:
	@$(DOXYGEN) ./doxygen/doxyfile

#---[ Clean Targets ]--------------------------------------------------------------------

clean: \

	@$(MAKE) -C client $@
	@$(MAKE) -C server $@

cleanDebug:

	@$(MAKE) -C client $@
	@$(MAKE) -C server $@

cleanRelease:

	@$(MAKE) -C client $@
	@$(MAKE) -C server $@


