#!/bin/sh

MSGFMT="msgfmt -c"

podir=$1
modir=$2
domain=$3

help()
{
  echo " ${0} <podir> <modir>"
  exit 1
}

if [ $# -lt 2 ]; then
  help
fi

if [ ! -d "${podir}" ]; then
  echo "'${podir}' does not exist, or not directory"
  help
fi

if [ -z "${domain}" ]; then
  echo "parameter missing: domain"
  help
fi

po_files=`find ${podir} -type f -iname "*.po"`
if [ ${#po_files[*]} -gt 0 ]; then
  for po_path in ${po_files}
  do
    filename="${po_path##*/}"
    locale="${filename%.*}"
    po_path="${podir}/${locale}.po"
    locale_dir="${modir}/${locale}/LC_MESSAGES"
    mo_path="${locale_dir}/${domain}.mo"

    if [ ! -d "${locale_dir}" ]; then
      mkdir -p ${locale_dir}
    fi

    echo "Generating ${mo_path}"
    ${MSGFMT} -o ${mo_path} ${po_path}
  done
fi

exit $?
