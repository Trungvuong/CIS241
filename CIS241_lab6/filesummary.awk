#!/bin/gawk -f
BEGIN	{
	d = 0	# count for number of directory
	f = 0
	l = 0
	t = 0
	s = 0
	}

$1 ~ /^d[rwxts-]{9}/	{d += 1}	# directory
$1 ~ /^[l]/             {l += 1}
$1 ~ /^[-]/     	{f+= 1}
$1 ~ /^d[rwxts-]{9}|^[l]|^[-]/			{t += 1 }
$5 ~ /^[0-9]/		{s += $5 }


END	{print ""
	 print "Here is the summary of files under your home directory:"
	 print ""
	 print "directories   files     links      total       storage(Bytes)"
	 print "============================================================="
	 printf "%-13d %-9d %-11d %-10d %-10d\n\n", d, f, l, t, s 
	} 
