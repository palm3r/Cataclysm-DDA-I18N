#!/bin/sh

MSGFMT="msgfmt -c"
CP="cp -f"

domain=$1
podir=$2
modir=$3

help()
{
  echo " ${0} <domain> <podir> <modir>"
  exit 1
}

if [ $# -lt 3 ]; then
  help
fi

if [ ! -d "${podir}" ]; then
  echo "'${podir}' does not exist, or not directory"
  help
fi

locales=`find ${podir} -mindepth 1 -maxdepth 1 -type d -exec basename {} \;`
for locale in ${locales}
do
  po="${podir}/${locale}/${domain}.po"
  if [ -f "${po}" ]; then
    locale_dir="${modir}/${locale}/LC_MESSAGES"
    if [ ! -d "${locale_dir}" ]; then
      mkdir -p ${locale_dir}
    fi
    mo="${locale_dir}/${domain}.mo"
    echo "Generating ${mo}"
    ${MSGFMT} -o ${mo} ${po}

    # for test translators
    ${CP} ${po} "${locale_dir}/${domain}.po"
  fi
done

exit $?
