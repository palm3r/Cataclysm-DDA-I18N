#!/bin/bash

MSGMERGE="msgmerge -U"

podir=$1

help()
{
  echo " ${0} <podir>"
  exit 1
}

if [ $# -lt 1 ]; then
  help
fi

if [ ! -d "${podir}" ]; then
  echo "'${podir}' is not directory"
  help
fi

pot_files=`find ${podir} -type f -iname "*.pot"`
if [ ${#pot_files[*]} -eq 0 ]; then
  echo "'${podir}' does not contain any .pot file"
  help
fi

po_files=`find ${podir} -type f -iname "*.po"`
if [ ${#po_files[*]} -gt 0 ]; then
  for po_path in ${po_files}
  do
    echo "Merging ${po_path}"
    ${MSGMERGE} ${po_path} ${pot_files[0]}
  done
fi

exit $?

