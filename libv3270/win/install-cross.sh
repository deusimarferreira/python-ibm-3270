#!/bin/bash

install_packages() {

TEMPFILE=$(mktemp)

cat > ${TEMPFILE} << EOF
cross-binutils
cross-gcc
cross-gcc-c++
cross-pkg-config
filesystem
libopenssl
libopenssl-devel
libintl-devel
win_iconv-devel
zlib-devel
winpthreads-devel
cross-cpp
gettext-tools
headers
libepoxy0
libgdk_pixbuf-2_0-0
atk-devel
pango-devel
win_iconv-devel
pixman-devel
glib2-devel
cairo-devel
freetype-devel
gtk3-devel
filesystem
gettext-tools
gtk3-data
gtk3-tools
gnome-icon-theme
hicolor-icon-theme
gdk-pixbuf-loader-rsvg
gdk-pixbuf-query-loaders
lib3270-5_2-devel
EOF

# Instala apicativos e temas necessários
sudo zypper --non-interactive in \
        adwaita-icon-theme \
        gettext-tools \
        glib2-devel \
        optipng \
        ImageMagick

while read FILE
do
	sudo zypper --non-interactive in ${1}-${FILE}
done < ${TEMPFILE}

rm -f ${TEMPFILE}

}

if [ -z ${1} ]; then
	echo "Use ${0} --32 for 32 bits cross-compiler"
	echo "Use ${0} --64 for 64 bits cross-compiler"
	exit -1
fi


until [ -z "${1}" ]
do
	if [ ${1:0:2} = '--' ]; then
		tmp=${1:2}
		parameter=${tmp%%=*}
		parameter=$(echo $parameter | tr "[:lower:]" "[:upper:]")

		case $parameter in

		ar)
			zypper ar --refresh http://download.opensuse.org/repositories/windows:/mingw:/win32/openSUSE_42.3/ mingw32
			zypper ar --refresh http://download.opensuse.org/repositories/windows:/mingw:/win64/openSUSE_42.3/ mingw64
			;;

		32)
			install_packages mingw32
			;;

		64)
			install_packages mingw64
			;;

		ALL)
			install_packages mingw32
			install_packages mingw64
			;;


		*)
			value=${tmp##*=}
			eval $parameter=$value
		esac

	fi

	shift
done


