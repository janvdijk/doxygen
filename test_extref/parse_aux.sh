
function make_dictionary
{
for AUXFILE in $@; do
  grep --no-filename "^\\\\newlabel" $@ |
	sed 's/\\newlabel{\([^}]*\)}{{\([^}]*\)}{\([^}]*\)}[^$]*/\\extref \1#\2 on page \3/';
done
}

make_dictionary $@;


