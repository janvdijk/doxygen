
function make_dictionary
{
for AUXFILE in $@; do
  grep --no-filename "^\\\\newlabel" $@ |
	sed 's/\\newlabel{\([^}]*\)}{{\([^}]*\)}{\([^}]*\)}[^$]*/\1 \2/';
done
}

make_dictionary $@;


