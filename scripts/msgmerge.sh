#!/bin/bash

MSGMERGE="msgmerge -U"

domain=$1
podir=$2

help()
{
  echo " ${0} <domain> <podir>"
  exit 1
}

if [ $# -lt 2 ]; then
  help
fi

if [ ! -d "${podir}" ]; then
  echo "'${podir}' is not directory"
  help
fi

pot="${podir}/${domain}.pot"
if [ ! -f "${pot}" ]; then
  echo "'${pot}' does not exist"
  help
fi

locales=`find ${podir} -mindepth 1 -maxdepth 1 -type d -exec basename {} \;`
for locale in ${locales}
do
  po="${podir}/${locale}/${domain}.po"
  if [ -f "${po}" ]; then
    echo "Merging ${po}"
    ${MSGMERGE} ${po} ${pot}
  fi
done

exit $?

