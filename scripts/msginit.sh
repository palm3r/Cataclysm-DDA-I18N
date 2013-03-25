#!/bin/bash

MSGINIT="msginit"

domain=$1
podir=$2
locale=$3

help()
{
  echo " ${0} <domain> <podir> <locale>"
  exit 1
}

if [ $# -lt 3 ]; then
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

locale_dir="${podir}/${locale}"
if [ ! -d "${locale_dir}" ]; then
  mkdir -p ${locale_dir}
fi

po="${locale_dir}/${domain}.po"
${MSGINIT} -o ${po} -i ${pot} -l ${locale}

exit $?

