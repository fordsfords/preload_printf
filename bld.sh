#!/bin/sh
# bld.sh

# Update TOC in doc
for F in *.md; do :
  if egrep "<!-- mdtoc-start -->" $F >/dev/null; then :
    # Update doc table of contents (see https://github.com/fordsfords/mdtoc).
    if which mdtoc.pl >/dev/null; then mdtoc.pl -b "" $F;
    elif [ -x ../mdtoc/mdtoc.pl ]; then ../mdtoc/mdtoc.pl -b "" $F;
    else echo "FYI: mdtoc.pl not found; Skipping doc build"; echo ""; fi
  fi
done

gcc -Wall -shared -fPIC -o libpreloadprintf.so preload_printf.c -ldl; if [ $? -ne 0 ]; then exit 1; fi

gcc -Wall -o hello hello.c; if [ $? -ne 0 ]; then exit 1; fi
