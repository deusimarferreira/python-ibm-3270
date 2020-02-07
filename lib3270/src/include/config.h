/* src/include/config.h.  Generated from config.h.in by configure.  */
/*
 * Software pw3270, desenvolvido com base nos códigos fontes do  C3270  e  X3270
 * (Paul Mattes Paul.Mattes@usa.net), de emulação de terminal 3270 para acesso a
 * aplicativos mainframe. Registro no INPI sob o nome G3270.
 *
 * Copyright (C) <2008> <Banco do Brasil S.A.>
 *
 * Este programa é software livre. Você pode redistribuí-lo e/ou modificá-lo sob
 * os termos da GPL v.2 - Licença Pública Geral  GNU,  conforme  publicado  pela
 * Free Software Foundation.
 *
 * Este programa é distribuído na expectativa de  ser  útil,  mas  SEM  QUALQUER
 * GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou  de  ADEQUAÇÃO
 * A QUALQUER PROPÓSITO EM PARTICULAR. Consulte a Licença Pública Geral GNU para
 * obter mais detalhes.
 *
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este
 * programa;  se  não, escreva para a Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA, 02111-1307, USA
 *
 * Este programa está nomeado como config.h.in e possui - linhas de código.
 *
 * Contatos:
 *
 * perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
 * erico.mendonca@gmail.com	(Erico Mascarenhas de Mendonça)
 *
 */

#ifndef LIB3270_CONFIG_INCLUDED

	#define LIB3270_CONFIG_INCLUDED 1

	/* Version info */
	#define PACKAGE_NAME "lib3270"
	#define PRODUCT_NAME pw3270
	#define PACKAGE_VERSION "5.3"
	#define PACKAGE_RELEASE 20037
	#define LIB3270_NAME 3270

	/* Default settings */

	/** @brief The lib3270's default host URL */
/* 	#undef LIB3270_DEFAULT_HOST */

/* 	#undef LIB3270_DATADIR */

	/** @brief the delay, in miliseconds, between the host unlocking the keyboard and lib3270 actually performing the unlock */
	#define UNLOCK_MS 350

	/* Library options */
	#define HAVE_GNUC_VISIBILITY 1
	#define HAVE_LIBINTL 1
	#define HAVE_GETADDRINFO 1
	#define HAVE_VASPRINTF 1
	#define HAVE_INET_NTOP 1
	#define HAVE_DBUS 1
	#define HAVE_LIBCURL 1
	#define HAVE_SYSLOG /**/

	#define HAVE_ICONV 1
	#define ICONV_CONST 

	/* Security options */
/* 	#undef HAVE_LDAP */
	#define HAVE_LIBSSL 1

/* 	#undef SSL_ENABLE_SELF_SIGNED_CERT_CHECK */

	#define SSL_ENABLE_CRL_CHECK 1
	#define SSL_ENABLE_CRL_EXPIRATION_CHECK 1
	#define SSL_ENABLE_NOTIFICATION_WHEN_FAILED 1

	/* If defined uses a hardcoded CRL path */
/* 	#undef SSL_CRL_URL */

	/* Optional parts. */
/* 	#undef X3270_DBCS */
/* 	#undef X3270_SCRIPT */

	#define X3270_TN3270E
	#define X3270_ANSI
	#define X3270_APL

	#define X3270_TRACE
	#define X3270_FT

/* 	#undef HAVE_PRINTER */
	#define HAVE_MALLOC_H /**/
	#define HAVE_STRTOK_R 1

#endif /* LIB3270_CONFIG_INCLUDED */

