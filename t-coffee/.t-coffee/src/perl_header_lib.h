/******************************COPYRIGHT NOTICE*******************************/
/*  (c) Centro de Regulacio Genomica                                                        */
/*  and                                                                                     */
/*  Cedric Notredame                                                                        */
/*  30 Nov 2019 - 10:22.                                                                    */
/*All rights reserved.                                                                      */
/*This file is part of T-COFFEE.                                                            */
/*                                                                                          */
/*    T-COFFEE is free software; you can redistribute it and/or modify                      */
/*    it under the terms of the GNU General Public License as published by                  */
/*    the Free Software Foundation; either version 2 of the License, or                     */
/*    (at your option) any later version.                                                   */
/*                                                                                          */
/*    T-COFFEE is distributed in the hope that it will be useful,                           */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of                        */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         */
/*    GNU General Public License for more details.                                          */
/*                                                                                          */
/*    You should have received a copy of the GNU General Public License                     */
/*    along with Foobar; if not, write to the Free Software                                 */
/*    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA             */
/*...............................................                                           */
/*  If you need some more information                                                       */
/*  cedric.notredame@gmail.com                                                             */
/*...............................................                                           */
/******************************COPYRIGHT NOTICE*******************************/
char *PerlScriptName[]={"rec_sum.pl","count.pl","p\
rocess_list.pl","make_license.pl","CCsed.script","\
msa2bootstrap.pl","tc_generic_method.pl","rnapdb2p\
rotpdb.pl","generic_method.tc_method","clustalw_me\
thod.tc_method","extract_from_pdb","install.pl","c\
lean_cache.pl","nature_protocol.pl","mocca","dalil\
ite.pl","wublast.pl","blastpgp.pl","ncbiblast_lwp.\
pl","wublast_lwp.pl","RNAplfold2tclib.pl","fasta_s\
eq2RNAplfold_templatefile.pl","fasta_seq2hmmtop_fa\
sta.pl","fasta_seq2consan_aln.pl","clustalw_aln2fa\
sta_aln.pl","seq2name_seq.pl","seq2intersection.pl\
","msf_aln2fasta_aln.pl","msa.pl","upp.pl","clusta\
lo.pl","dca.pl","blast_aln2fasta_aln.pl","blast_xm\
l2fasta_aln.pl","fasta_aln2fasta_aln_unique_name.p\
l","newick2name_list.pl","excel2fasta.pl","nameseq\
2fasta.pl","any_file2unix_file.pl","EndList"};char\
 *PerlScriptFile[]={"use File::Copy;\nuse Env qw(H\
OST);\nuse Env qw(HOME);\nuse Env qw(USER);\n$x_fi\
eld=0;\n$y_field=1;\n$y_field_set=1;\n$nyf=1;\n\n$\
interval=0;\n$file=\"stdin\";\n\n$print_avg=1;\n$p\
rint_sd=0;\n$print_sum=0;\n$print_n=0;\nforeach $v\
alue ( @ARGV)\n    {\n	if ($value ne $ARGV[$np]) \\
n	    {\n	    ;\n	    }\n	elsif($value eq \"-s\")\\
n	     {\n	       $step=$ARGV[++$np];\n	       $np\
++;\n	     }\n	elsif($value eq \"-print_all\")\n	 \
   {\n	    $print_sd=$print_avg=$print_n=$print_su\
m=1;\n	    $np++;\n	    }\n	elsif($value eq \"-pri\
nt_sum\")\n	    {\n	    $print_sum=1;\n	    $print\
_avg=0;\n	    $np++;\n	    }\n	elsif($value eq \"-\
print_n\")\n	    {\n	    $print_n=1;\n	    $print_\
avg=0;\n	    $np++;\n	    }\n	elsif($value eq \"-p\
rint_avg\")\n	    {\n	    $print_avg=1;\n	    $pri\
nt_avg=0;\n	    $np++;\n	    }\n	elsif($value eq \\
"-sd\")\n	    {\n	    $print_sd=1;\n	    $print_av\
g=0;\n	    $np++;\n	    }\n	elsif($value eq \"-h\"\
)\n	    {\n	    $header=1;\n	    $np++;\n	    }\n	\
elsif ($value eq \"-i\")\n	    {\n	    $interval= \
$ARGV[++$np];\n	    $np++;\n    	    }\n	elsif ($v\
alue eq \"-r2\")\n	    {\n	      $r2=1;\n	      \n\
	      $np  = $ARGV[++$np];\n	      $nsim= $ARGV[+\
+$np];\n	      $np++;\n    	    }\n	elsif ($value \
eq \"-r\")\n	    {\n	    $min= $ARGV[++$np];\n	   \
 $max= $ARGV[++$np];\n	    $np++;\n    	    }\n	\n\
	elsif ($value eq \"-x\")\n	    {\n	    $x_field= \
$ARGV[++$np]-1;\n	    $np++;\n    	    }\n	elsif (\
$value eq \"-y\")\n	    {\n	    $nyf=0;  \n	    wh\
ile ($ARGV[$np+1] && !($ARGV[$np+1]=~/\\-/))\n	   \
   {\n		$y_field[$nyf++]=$ARGV[++$np]-1;\n		$y_fie\
ld_set=1;\n	      }\n\n	    $np++;\n    	    }\n	e\
lsif ($value eq \"-file\")\n	    {\n	    $file= $A\
RGV[++$np];\n	    $file_set=1;\n	    $np++;\n    	\
    }       \n	elsif ( $value eq \"h\" ||  $value \
eq \"-h\" || $value eq \"-H\" || $value eq \"-help\
\" || $value eq \"help\")\n	  {\n	    print STDOUT\
 \"data_analyse: Analyse and discretization of dat\
a\\n\";\n	    print STDOUT \"       -file:    <fil\
e containing the data to analyze>,.<def=STDIN>\\n\\
";\n	    print STDOUT \"       -x: <field containi\
ng the X>,...............<Def=0>\\n\";\n	    print\
 STDOUT \"       -y: <field containing the Y>,....\
...........<Def=1>\\n\";\n	    print STDOUT \"    \
   -i:<Interval size on the X>,...............<Def\
=0>\\n\";\n	    print STDOUT \"       -i:<0:only o\
ne interval>\\n\";\n	    print STDOUT \"       -r:\
<Range of the X>\\n\";\n	    print STDOUT \"      \
 -s:<Step on the  X, 0 means non sliding bins>\\n\\
";\n	    print STDOUT \"       -sd: print standard\
 deviation on the Y\";\n	    print STDOUT \"      \
 -h  : print column header \\n\";\n	    exit (0);\\
n	  }\n	elsif ($value=~/-/)\n	  {\n	    print \"$v\
alue is not a valid FLAG[FATAL]\\n\";\n	    exit (\
0);\n	   } \n	elsif ($list eq \"\") \n	    {\n	   \
 $file=$ARGV[$np];\n	    $np++;\n	    }\n	\n	\n   \
   }\n\n\n\n\n\nif ($file eq \"stdin\")\n	{\n	$rem\
ove_file=1;\n	$file=\"tmp$$\";\n	open (F, \">$file\
\");\n	while (<STDIN>)\n		{\n		print F $_;\n		}\n	\
close (F);\n	 \n	;}\n\n\n\nif ($interval && $step)\
\n  {\n    my $nl;\n    open(F,$file);\n    while \
(<F>)\n      {\n	$line=$_;\n	\n	if (!/\\S/){next;}\
\n	@list=($line=~/(\\S+)/g);\n	$val{$nl}{x}=$list[\
$x_field];\n	$val{$nl}{y}=$list[$y_field[0]];\n	$n\
l++\n      }\n    close (F);\n    \n    for (my $a\
=$min; $a<($max+$interval); $a+=$step)\n      {\n	\
my ($avgx, $avgy, $cn);\n	\n	my $rmin=$a-$interval\
;\n	my $rmax=$a;\n	$cn=0;\n	for (my $b=0; $b<$nl; \
$b++)\n	  {\n	    my $x=$val{$b}{x};\n	    my $y=$\
val{$b}{y};\n	    if ($x<=$rmax && $x>=$rmin)\n	  \
    {\n		$avgx+=$x;\n		$avgy+=$y;\n		$cn++;\n		$tc\
n++;\n		$val{$b}{used}=1;\n	      }\n	  }\n	if ($c\
n)\n	  {\n	    $avgx/=$cn;\n	    $avgy/=$cn;\n	  }\
\n	printf \"%.3f %.3f %.3f\\n\", $avgx, $avgy, $av\
gx-$avgy;\n      }\n    for (my $a=0; $a<$nl; $a++\
)\n      {\n	if ( !$val{$a}{used})\n	  {\n	    pri\
nt \"---$val{$a}{x}; $val{$a}{y}\\n\";\n	  }\n    \
  }\n  }\nelse\n  {\n    if ($interval && $max)\n \
     {\n	$interval_size=($max-$min)/$interval;\n  \
    }\n    elsif ($interval)\n      {\n	open(F,$fi\
le);  \n	my $set_max=0;\n	my $set_min=0;\n	while (\
<F>)\n	  {\n	    my $v=$_;\n	    chomp($v);\n	    \
print \"--$v--\";\n	    \n	    if ($v<$min ||!$set\
_min){$set_min=1;$min=$v;}\n	    if ($v>$max ||!$s\
et_max){$set_max=1;$max=$v;}\n	  }\n	close (F);\n	\
print \"$min $max uuuu\";\n	$interval_size=($max-$\
min)/$interval;\n      }\n    open(F,$file);  \n  \
  while (<F>)\n      {\n	$line=$_;\n	if (!/\\S/){n\
ext;}\n	@list=($line=~/(\\S+)/g);\n	\n	if ($interv\
al==0){$bin=0;}\n	else{$bin=int (($list[$x_field]-\
$min)/($interval_size));}\n	\n	\n	if ($bin && $bin\
==$interval){$bin--;}\n	for ( $a=0; $a<$nyf; $a++)\
\n	  {\n	    $sum{$a}{$bin}+=$list[$y_field[$a]];\\
n	    $sum2{$a}{$bin}+=$list[$y_field[$a]]*$list[$\
y_field[$a]];\n	    $n{$a}{$bin}++;\n	  }\n      }\
\n    \n    if (!$interval){$interval=1;}\n    for\
 ( $a=0; $a<$interval; $a++)\n      {\n	printf ( \\
"%4d %4d \", $interval_size*$a, $interval_size*($a\
+1));\n	for ( $b=0; $b<$nyf; $b++)	\n	  {\n	    $i\
=$interval*$a;\n	    if ( $n{$b}{$a}==0)\n	      {\
\n		$avg=0;\n		$sd=0;\n	      }\n	    else\n	     \
 {\n		$avg=$sum{$b}{$a}/$n{$b}{$a};\n		$sd=sqrt($s\
um2{$b}{$a}*$n{$b}{$a}-$sum{$b}{$a}*$sum{$b}{$a})/\
($n{$b}{$a}*$n{$b}{$a});\n	      }\n	    if ($prin\
t_n) {printf \"%15.4f \", $n{$b}{$a};}\n	    if ($\
print_sum){printf \"%15.4f \", $sum{$b}{$a};}\n	  \
  if ($print_avg){printf \"%15.4f \", $avg}\n	    \
if ($print_sd) {printf \"%15.4f \", $sd;}\n	  }\n	\
printf (\"\\n\");\n      }\n  }\n\nif ( $remove_fi\
le){unlink $file;}\n","use File::Copy;\nuse Env qw\
(HOST);\nuse Env qw(HOME);\nuse Env qw(USER);\n\nf\
oreach $v (@ARGV){$cl.=$v;}\n\n\nif ( $cl=~/-k(\\d\
+)/){$k=$1;}\nelse {$k=1;}\nif ( $cl=~/-w(\\d+)/){\
$w=$1;}\nelse {$w=-1;}\nif ( $cl=~/-p(\\d+)/){$p=$\
1;}\nelse {$p=-1;}\n\nwhile (<STDIN>)\n  {\n    @l\
=($_=~/(\\S+)/g);\n    $v=$l[$k-1];\n    if ( !$h{\
$v}){@ll=($v, @ll);}\n    \n    if ( $w==-1)\n    \
  {$h{$v}++;}\n    else\n      {$h{$v}+=$l[$w-1];}\
\n\n    if ($p!=-1){$print{$v}=$l[$p-1];}\n\n  }\n\
foreach $v (@ll)\n  {\n    print \"$v $print{$v} $\
h{$v}\\n\";\n  }\n","\nuse Env qw(HOST);\nuse Env \
qw(HOME);\nuse Env qw(USER);\n$random_tag=int (ran\
d 10000)+1;\n$unique_prefix=\"$$.$HOST.$random_tag\
\";\n$queue=\"distillery.and.mid\";\n$monitor=0;\n\
$stderr_file=\"/dev/null\";\n$stdio_file=\"/dev/nu\
ll\";\n$log_file=\"/dev/null\";\n$pause_time=0;\n$\
max_sub_jobs=60;\n$min_sub_jobs=30;\n$output_all=0\
;\n$var='\\$';\n\nforeach $value ( @ARGV)\n    {\n\
	if ($value ne $ARGV[$np]) \n	    {\n	    ;\n	    \
}\n	elsif ($value eq \"-max_sub_jobs\")\n	    {\n	\
    $max_sub_jobs= $ARGV[++$np];\n	    $np++;\n   \
 	    }	\n	elsif ($value eq \"-min_sub_jobs\" )\n	\
    {\n	    $min_sub_jobs= $ARGV[++$np];\n	    $np\
++;\n    	    }\n	elsif ($value eq \"-para\")\n	  \
  {\n	    $para=1;\n	    $monitor=1;\n	    $np++;\\
n    	    }\n	elsif ($value eq \"-monitor\") \n	  \
  {\n	    $monitor=1;\n	    $np++;\n	    }\n	elsif\
 ($value eq \"-no_monitor\") \n	    {\n	    $monit\
or=0;\n	    $np++;\n	    }\n	elsif ($value eq \"-q\
ueue\")\n	    {\n	    $queue=$ARGV[++$np];\n	    $\
np++;\n	    }	\n	elsif ($value eq \"-stderr_file\"\
)\n	    {\n	    $stderr_file=$ARGV[++$np];\n	    $\
np++;\n	    }\n	elsif ($value eq \"-stdio_file\")\\
n	    {\n	    $stdio_file=$ARGV[++$np];\n	    $np+\
+;\n	    }\n	elsif ($value eq \"-output_all\")\n	 \
   {\n	    $output_all=1;\n	    $np++;\n	    }\n	e\
lsif ($value eq \"-pause\") \n	    {\n	    $pause_\
time=$ARGV[++$np];\n	    $np++;\n	    }\n	elsif ($\
value eq \"-log\")\n	      {\n	       $log=1;\n	  \
     \n	       if ($ARGV[$np+1]=~/\\-\\S+/) \n	   \
       {\n		  $log_file=\"stderr\";\n	          }\\
n	       else \n	          {\n		  $log_file=$ARGV[\
++$np]; \n		  ++$np;\n		 \n	          }\n	      }\\
n	elsif ( $value eq \"-com\")\n	    {\n		\n		if (!\
$ARGV[$np+1]=~/^\\'/) { $com=$ARGV[++$np];}\n		els\
e {$com=$ARGV[++$np];}\n\n	     $np++;\n	    }\n	e\
lsif ( $value eq \"-check\")\n	  {\n	    \n	    if\
 (!$ARGV[$np+1]=~/^\\'/) { $check=$ARGV[++$np];}\n\
	    else {$check=$ARGV[++$np];}\n	    $np++;\n	  \
}\n	elsif ($com eq \"\") \n	    {\n	    $com_set=1\
;\n	    $com=$ARGV[$np];\n	    \n	    $np++;\n	   \
 }\n	elsif ($list eq \"\") \n	    {\n	    $list_se\
t=1;\n	    $list=$ARGV[$np];\n	    $np++;\n	    }\\
n	elsif ( $var_set eq \"\")\n	    {\n	    $var_set\
=1;\n	    $var=$ARGV[$np];\n	    $np++;\n	    }\n	\
}\n\n\n\n\nif ( $com eq \"\"){print \"You Need to \
Provide a Command [FATAL]\\n\";\n	      die;\n	   \
  }\n\n\n\nif ($list_set==0) \n    {\n    $x= int \
(rand 100000)+1;\n    $tmp_file_name=\"tmp_file_$x\
\";\n    open ( TMP, \">$tmp_file_name\");\n    wh\
ile (<STDIN>)\n      {\n	print TMP $_;\n      }\n \
   close (TMP);\n    open (F, $tmp_file_name);\n  \
  }\nelse \n    {\n    open (F, $list);\n    }\n\n\
if ($para==0) \n    {\n\n     @tc_list= <F>;\n    \
 close (F); \n     \n     foreach $val(@tc_list) \\
n	    {\n	      \n	      \n	      \n	      $loc_co\
m=$com;\n	      if ($check){$loc_check=$check;}\n	\
      \n	      @i_val=($val=~/([^\\s]+)/g);\n	    \
  \n	      if ( $#i_val==0)\n		{\n		  if ($check){\
$loc_check=~s/$var/$i_val[0]/g;}\n		  $loc_com=~s/\
$var/$i_val[0]/g;\n		}\n	      else\n		{\n		  for \
($n=1; $n<=$#i_val+1;$n++ )\n		    {\n		      \n		\
      $sub=\"$var$n\";\n		      \n		      $loc_com\
=~s/$sub/$i_val[$n-1]/g;\n		      if ($check){$loc\
_check=~s/$var/$i_val[0]/g;}\n		    }\n		}\n	     \
 if ( $check && -e $loc_check)\n		{\n		  print STD\
ERR \"skipping $loc_com...\\n\";\n		  }\n	      el\
se\n		{\n		  system \"$loc_com\";\n		}\n	    }\n  \
  exit;\n    }\n\nelsif ($para==1) \n    {\n    pr\
int STDERR \"do parallel execution of: \\\"$com $l\
ist\\\"\\n\";\n    \n    if ($log==1) \n	{\n	if ($\
log_file eq \"stdout\" || $log_file eq \"stderr\" \
) \n		{\n		$log_file=\"\";\n	        }\n\n        \
else \n		{\n		system \"echo LOG FILE> $log_file\";\
\n		\n	        }\n	}\n    else	\n	{\n	open ( OUT, \
\">/dev/null\");\n	}\n	\n    \n    $id=0;\n    $n_\
sub=0;\n    while ($val=<F>) \n	    {	    	    \n	\
    $job_log[$id]=\"$HOME/tmp/$unique_prefix.$id.l\
og_file\";\n	    \n	    $job=$unique_prefix.\"_$id\
\";\n	    open (JOB, \">$job\");\n	    \n	    $loc\
_com=$com;\n	    chop $val;\n\n	    $loc_com=~s/\\\
$/$val/g;\n	 \n	    print JOB \"#!/bin/csh\\n\";\n\
	    print JOB \"#\\$ -cwd\\n\";\n	    print JOB \\
"#\\$ -N $unique_prefix\\n\";\n	    if ($queue && \
!($queue eq \" \")) {print JOB \"#\\$ -l $queue\\n\
\";}\n	    print JOB \"#\\n\";	    \n            p\
rint JOB \"$loc_com\\n\";\n	    print JOB \"echo F\
INISHED  >> $job_log[$id]\\n\";\n	    print JOB \"\
pwd\\n\";\n	    \n	    close (JOB);\n	    if ( $ou\
tput_all==1)\n		{\n		system \"qsub $job >  $unique\
_prefix\";		\n	        }\n	    else\n		{system \"q\
sub $job -e $stderr_file -o $stdio_file >$unique_p\
refix\";	        \n	        } \n\n\n\n	    print S\
TDERR \"$id: $output_all\\n\";\n	    $n_sub++;\n	 \
   if ( $max_sub_jobs && $n_sub==$max_sub_jobs) \n\
		{\n		$n_sub=monitor_process($min_sub_jobs,@job_l\
og); 		 \n		\n	        }	\n	   \n            unlin\
k $unique_prefix;\n	    sleep $pause_time;\n	    $\
id++;\n	    }\n\n    close (OUT);\n    close (F);\\
n\n    print STDERR \"Your $id Jobs Have Been Subm\
ited (NAME=$unique_prefix)\\n\";\n    monitor_proc\
ess (0, @job_log);\n    foreach $file(@job_log) {i\
f (-e $file) {unlink($file);}}\n    \n    }\n\nsub\
 monitor_process ( @job_list)\n    {\n    my (@job\
_list)=@_;\n    my $min_sub_jobs=shift (@job_list)\
;\n    my $n_sub_jobs;\n    my $finished;\n    my \
$n=0;\n\n    $n_sub_jobs=-1;\n    $finished=0;\n  \
  print STDERR \"\\nMonitor Batch: [$min_sub_jobs]\
\";\n       \n    while (!$finished && (($n_sub_jo\
bs>$min_sub_jobs)|| $n_sub_jobs==-1) ) \n	{\n	$fin\
ished=1;\n	$n_sub_jobs=0;\n	$n=0;\n	foreach $file \
(@job_list)\n	        {\n	\n		if (-e $file){;}\n		\
else \n		    {\n		    $finished=0; $n_sub_jobs++;\\
n	            }\n	        }\n	system \"sleep 1\";\\
n        }\n    \n    return $n_sub_jobs;\n    }\n\
    \n    \nif ($tmp_file_name){unlink($tmp_file_n\
ame);}\n","\n\nforeach ($np=0; $np<=$#ARGV; $np++)\
\n    {\n    $value=$ARGV[$np];\n\n    if ($value \
eq \"-file\")\n      {\n      $file= $ARGV[++$np];\
\n      }\n    elsif ($value eq \"-type\")\n      \
{\n        $type= $ARGV[++$np];\n      }\n    elsi\
f ($value eq \"-institute\")\n      {\n        $in\
stitute= $ARGV[++$np];\n      }\n    elsif ($value\
 eq \"-author\")\n      {\n        $author= $ARGV[\
++$np];\n      }\n    elsif ($value eq \"-date\")\\
n      {\n        $date= $ARGV[++$np];\n      }\n \
    elsif ($value eq \"-program\")\n      {\n     \
   $program= $ARGV[++$np];\n      }\n    elsif ($v\
alue eq \"-email\")\n      {\n        $email= $ARG\
V[++$np];\n      }\n    else\n      {\n	print \"$v\
alue is an unkown argument[FATAL]\\n\";\n	exit (1)\
;\n      }\n  }\n\n\n\nopen F, $file || die;\nprin\
t $INSTITUTE;\nif ( $type eq \"c\"){print \"/*****\
*************************COPYRIGHT NOTICE*********\
**********************/\\n\";}\nif ( $type eq \"pe\
rl\"){print \"##############################COPYRI\
GHT NOTICE##############################/\\n\";}\n\
if ( $type eq \"txt\"){print \"-------------------\
------------COPYRIGHT NOTICE----------------------\
--------/\\n\";}\n\n\nwhile (<F>)\n  {\n  s/\\$INS\
TITUTE/$institute/g;\n  s/\\$AUTHOR/$author/g;\n  \
s/\\$DATE/$date/g;\n  s/\\$PROGRAM/$program/g;  \n\
  s/\\$EMAIL/$email/g;  \n  if ( $type eq \"txt\")\
{print $_;}\n  elsif ($type eq \"c\"){chop $_; pri\
nt \"\\/*$_*\\/\\n\";}\n  elsif ($type eq \"perl\"\
){print \"\\#$_\";}\n}\nclose (F);\nif ( $type eq \
\"c\"){print \"/******************************COPY\
RIGHT NOTICE*******************************/\\n\";\
}\nif ( $type eq \"perl\"){print \"###############\
###############COPYRIGHT NOTICE###################\
###########/\\n\";}\nif ( $type eq \"txt\"){print \
\"-------------------------------COPYRIGHT NOTICE-\
-----------------------------/\\n\";}\n\n","\nwhil\
e (<>)	\n	{\n	s/\\=cc/123456789/g;\n	s/\\bcc/\\$\\\
(CC\\)/g;\n	s/123456789/\\=cc/g;\n	print $_;\n	}\n\
\n","$version=\"1.00\";\n$rseed= int(rand(100000))\
+1;\n\n\nif ( $#ARGV==-1)\n  {\n    print \"msa2bo\
otstrap -i <input_file> -input <seq|msa|matrix|tre\
e> -n <N-Boostrap> -o <outtree> -tmode <nj|upgma|p\
arsimony|ml> -dmode <kimura> -alignpg <t_coffee | \
muscle | clustalw> -rtree <file> -stype <prot|cdna\
|dna> -recompute -system <cygwin|unix>\";\n    pri\
nt \"\\n\\t-i: input file, can be sequneces, msa, \
matrix, trees, type is specified via -input\";\n  \
  print \"\\n\\t-input: Type of input data\";\n   \
 print \"\\n\\t\\tmsa: msa in fasta format\";\n   \
 print \"\\n\\t\\tseq: compute an msa with -alignp\
g\";\n    print \"\\n\\t\\tmatrix: phylipp distanc\
e matrix fed directly to method -tmode [caveat: tm\
ode=nj or upgma]\";\n    print \"\\n\\t\\ttree: li\
st of newick trees directly fed to consence in ord\
er to generate a bootstraped tree\";\n    \n    pr\
int \"\\n\\t-n: number of bootstrap replicates\";\\
n    print \"\\n\\t-o: name of the output tree. Fi\
les are not overwritten. Use -recompute to overwri\
te existing file\";\n    print \"\\n\\t-tmode: tre\
e mode: nj|upgma|parsimony|ml\";\n    print \"\\n\\
\t-dmode: distance mode\";\n    print \"\\n\\t-ali\
gnpg: program for aligning sequences (t_coffee=def\
ault)\";\n    print \"\\n\\t-rtree: replicate tree\
 file (default: no file)\";\n    print \"\\n\\t-rm\
sa: replicate msa file (default: no file)\";\n    \
print \"\\n\\t-rmat: replicate matrix file (defaul\
t: no file)\";\n    print \"\\n\\t-stype: sequence\
 type: protein, dna or cdna\";\n    print \"\\n\\t\
-recompute: force files to be overwritten\";\n    \
print \"\\n\\t-system: cygwin|unix\";\n      \n\n \
   \n    &my_exit (EXIT_FAILURE);\n  }\nforeach $a\
rg (@ARGV){$command.=\"$arg \";}\n\nprint \"CLINE:\
 $command\\n\";\n$threshold=100;\n$trim_msa=0;\n$s\
type=\"prot\";\nprint \"msa2bootstrap \";\n\n$syst\
em=\"cygwin\";\nif(($command=~/\\-system (\\S+)/))\
\n  {\n    $system=$1;\n    if ( $system eq \"cygw\
in\")\n      {\n	$exec_extension=\".exe\";\n      \
}\n    elsif ( $system eq \"unix\")\n      {\n	$ex\
ec_extension=\"\";\n	print \"system=Unix\";die;\n \
     }\n    else\n      {\n	print \"msa2boostrap: \
-system=$system is an unknown mode [FATAL]\\n\"; d\
ie;\n      }\n    \n    print \"-system $system \"\
;\n  }\nif(($command=~/\\-stype (\\S+)/))\n  {\n  \
  $stype=$1;\n  }\nprint \"-stype=$stype \";\n\n\n\
\nif(($command=~/\\-i (\\S+)/))\n  {\n    $msa=$1;\
\n    print \"-i $msa \";\n  }\n\nif(($command=~/\\
\-rtree (\\S+)/))\n  {\n    $rtree=$1;\n    print \
\"-rtree=$rtree \";\n  }\n\nif(($command=~/\\-rmsa\
 (\\S+)/))\n  {\n    $rmsa=$1;\n  }\nif(($command=\
~/\\-rmat (\\S+)/))\n  {\n    $rmat=$1;\n  }\n$inp\
ut=\"seq\";\nif(($command=~/\\-input (\\S+)/))\n  \
{\n    $input=$1;\n  }\nprint \"-input=$input \";\\
n\n$dmode=\"kimura\";\nif(($command=~/\\-dmode (\\\
S+)/))\n  {\n    $dmode=$1;\n  }\nprint \"-dmode=$\
dmode \";\n$alignpg=\"muscle\";\nif(($command=~/\\\
-alignpg (\\S+)/))\n  {\n    $alignpg=$1;\n  }\npr\
int \"-alignpg=$dmode \";\n\n$tmode=\"nj\";\nif(($\
command=~/\\-tmode (\\S+)/))\n  {\n    $tmode=$1;\\
n  }\nprint \"-tmode=$tmode \";\n$recompute=0;\nif\
(($command=~/\\-recompute/))\n  {\n    $recompute=\
1;\n    print \"-recompute \";\n  }\n\n$out=$msa;\\
n$out=~s/\\..*//;\n$out.=\".bph\";\nif(($command=~\
/\\-o (\\S+)/))\n  {\n    $out=$1;\n    \n  }\npri\
nt \"-out=$out \";\nif (-e $out && !$recompute)\n \
 {\n    print \"\\nNo Computation Required $out al\
ready exists\\n\";\n    &my_exit (EXIT_SUCCESS);\n\
    \n  }\n\n$n=100;\nif(($command=~/\\-n (\\d+)/)\
)\n  {\n    $n=$1;\n  }\nprint \"-n=$n \";\n$seed=\
3;\nif(($command=~/\\-s (\\d+)/))\n  {\n    $seed=\
$1;\n  }\nprint \"-s=$seed \";\n\nif(($command=~/\\
\-run_name (\\d+)/))\n  {\n    $suffix=$1;\n  }\ne\
lse\n  {\n    $msa=~/([^.]+)/;\n    $suffix=$1;\n \
 }\nprint \"-run_name=$suffix\\n\";\n\n\nif ( $inp\
ut eq \"seq\")\n  {\n    $seq=$msa;\n    $msa=\"$s\
uffix.prot_msa\";\n    \n    if ($stype eq \"cdna\\
")\n      {\n	$cdna_seq=$seq;\n	$clean_cdna_seq=&v\
tmpnam();\n	$seq=&vtmpnam();\n	`t_coffee -other_pg\
 seq_reformat -in $cdna_seq -action +clean_cdna >$\
clean_cdna_seq`;\n	`t_coffee -other_pg seq_reforma\
t -in $clean_cdna_seq -action +translate >$seq`;\n\
	\n      }\n\n    if (!-e $msa || $recompute)\n   \
   {\n	print \"\\n#####   Compute an MSA With $ali\
gnpg\\n\";\n	\n	if ( $alignpg eq \"t_coffee\")\n	 \
 {`$alignpg $seq -outfile=$msa >/dev/null 2>/dev/n\
ull`;}\n	elsif ( $alignpg eq \"muscle\")\n	  {\n	 \
   `$alignpg -in $seq > $msa 2>/dev/null`;\n	  }\n\
	elsif ( $alignpg eq \"clustalw\")\n	  {\n	    `$a\
lignpg -infile=$seq -outfile=$msa -quicktree >/dev\
/null 2>/dev/null`;\n	  }\n	elsif ( $align eq \"ma\
fft\")\n	  {\n	    `$alignpg $seq > $msa >/dev/nul\
l 2>/dev/null`;\n	  }\n	else\n	  {\n	    `$alignpg\
 -in=$seq -outfile=$msa`;\n	  }\n      }\n    if (\
!-e $msa)\n      {\n	print \"\\nError: $alignpg Co\
uld Not produce the MSA $msa [FATAL]\\n\";\n      \
}\n\n    if ($stype eq \"cdna\")\n      {\n	$msa2=\
\"$suffix.cdna_msa\";\n	`t_coffee -other_pg seq_re\
format -in $clean_cdna_seq -in2 $msa -action +thre\
ad_dna_on_prot_aln -output fasta_aln  >$msa2`;\n	$\
msa=$msa2;\n      }\n    \n    $input=\"msa\";\n  \
}\n\n\n\n$seqboot_o=&vtmpnam();\n$seqboot_c=&vtmpn\
am();\n\n$protdist_o=&vtmpnam();\n$protdist_c=&vtm\
pnam();\nif ( $input eq \"msa\")\n  {\n    if ($tm\
ode eq \"nj\" || $tmode eq \"upgma\"){$input=\"mat\
rix\";}\n    \n    $lmsa= &vtmpnam ();\n    `t_cof\
fee -other_pg seq_reformat -in $msa -output phylip\
_aln > $lmsa`;\n    \n    if ( -e \"outfile\"){unl\
ink (\"outfile\");}\n    # run seqboot\n  \n    if\
 ( $n>1)\n      {\n	print \"Run SeqBoot .....\";\n\
	open (F, \">$seqboot_c\");\n	print F \"$lmsa\\nR\\
\n$n\\nY\\n$seed\\n\";\n	close (F);\n	`seqboot$exe\
c_extension  < $seqboot_c`;\n	if ( -e \"outfile\")\
{ print \"[OK]\\n\";}\n	else { print \"[FAILED]\\n\
\";&my_exit (EXIT_FAILURE);}\n	`mv outfile $seqboo\
t_o`;\n      }\n    else\n      {\n	`cp $lmsa $seq\
boot_o`;\n      }\n\n    if ($rmsa){`cp $seqboot_o\
 $rmsa`;}\n    \n    if ($tmode eq \"nj\" || $tmod\
e eq \"upgma\")\n      {\n	if ( $stype eq \"prot\"\
)\n	  {\n	    # run protdist\n	    print \"Run Pro\
tdist [dmode=$dmode]\";\n	    if ($dmode eq \"kimu\
ra\")\n	      {\n		$dmode=\"P\\nP\\nP\";\n	      }\
\n	    else\n	      {\n		print \"\\n$dmode is an u\
nknown mode for Protdist [FATAL:msa2bootstrap.pl]\\
\n\";\n		&my_exit (EXIT_FAILURE);\n	      }\n	    \
open (F, \">$protdist_c\");\n	    if ($n>1){print \
F \"$seqboot_o\\n$dmode\\nM\\nD\\n$n\\nY\\n\";}\n	\
    else {printf F \"$seqboot_o\\n$dmode\\nY\\n\";\
}\n	    close (F);\n	    `protdist$exec_extension \
 < $protdist_c`;\n	    if ( -e \"outfile\"){ print\
 \"[OK]\\n\";}\n	    else { print \"[FAILED]\\n\";\
&my_exit (EXIT_FAILURE);}\n	    `mv outfile $protd\
ist_o`;\n	 \n	  }\n	elsif ( $stype eq \"cdna\" || \
$stype eq \"dna\")\n	  {\n	    print \"Run dnadist\
 [dmode=default\";\n	    open (F, \">$protdist_c\"\
);\n	    if ($n>1){print F \"$seqboot_o\\nM\\nD\\n\
$n\\nY\\n\";}\n	    else {printf F \"$seqboot_o\\n\
Y\\n\";}\n	    close (F);\n	    `protdist$exec_ext\
ension  < $protdist_c`;\n	    if ( -e \"outfile\")\
{ print \"[OK]\\n\";}\n	    else { print \"[FAILED\
]\\n\";&my_exit (EXIT_FAILURE);}\n	    `mv outfile\
 $protdist_o`;\n	  }\n      }\n  }\nelsif ( $input\
 eq \"matrix\")\n  {\n    $protdist_o=&vtmpnam();\\
n    print \"MSA: $msa\\n\";\n    `cp $msa $protdi\
st_o`;\n    $n=1;\n  }\n\n\n\n\n\n$nb_o=&vtmpnam()\
;\n$nb_c=&vtmpnam();\nif ($input eq \"matrix\" && \
$tmode ne \"parsimony\" && $tmode ne \"ml\")\n  {\\
n    print \"Run neighbor [tmode=$tmode]\";\n\n   \
 if ($tmode eq \"nj\")\n      {\n	$tmode=\"\\nN\\n\
N\";\n      }\n    elsif ( $tmode eq \"upgma\")\n \
     {\n	$tmode = \"\\nN\";\n      }\n    else\n  \
    {\n	print \"\\n ERROR: $tmode is an unknown tr\
ee computation mode\\n\";\n	&my_exit (EXIT_FAILURE\
);\n      }\n\n    open (F, \">$nb_c\");\n    if (\
$n>1){print F \"$protdist_o$tmode\\nM\\n$n\\n$seed\
\\nY\\n\";}\n    else {print F \"$protdist_o$tmode\
\\nY\\n\";}\n    close (F);\n\n    `neighbor$exec_\
extension  < $nb_c`;\n    if ( -e \"outtree\"){ pr\
int \"[Neighbor OK]\\n\";}\n    else { print \"[FA\
ILED]\\n\";&my_exit (EXIT_FAILURE);}\n    `mv outt\
ree $nb_o`;\n    unlink (\"outfile\");\n  }\nelsif\
 ($input eq \"msa\" && $tmode eq \"parsimony\")\n \
 {\n    if ( -e \"outfile\"){unlink (\"outfile\");\
}\n    if ( -e \"outtree\"){unlink (\"outtree\");}\
\n    \n    if ($stype eq \"prot\")\n      {\n	pri\
nt \"Run protpars [tmode=$tmode]\";\n	open (F, \">\
$nb_c\");\n	if ($n>1){print F \"$seqboot_o\\nM\\nD\
\\n$n\\n$seed\\n10\\nY\\n\";}\n	else {print F \"$s\
eqboot_o\\nY\\n\";}\n	close (F);\n	`protpars$exec_\
extension  < $nb_c`;\n      }\n    elsif ( $stype \
eq \"dna\" || $stype eq \"cdna\")\n      {\n	print\
 \"Run dnapars [tmode=$tmode]\";\n	open (F, \">$nb\
_c\");\n	if ($n>1){print F \"$seqboot_o\\nM\\nD\\n\
$n\\n$seed\\n10\\nY\\n\";}\n	else {print F \"$seqb\
oot_o\\nY\\n\";}\n	close (F);\n	`dnapars$exec_exte\
nsion  < $nb_c`;\n      }\n    if ( -e \"outtree\"\
){ print \"[OK]\\n\";}\n    else { print \"[FAILED\
]\\n\";&my_exit (EXIT_FAILURE);}\n    `mv outtree \
$nb_o`;\n   unlink (\"outfile\");\n  }\nelsif ($in\
put eq \"msa\" && $tmode eq \"ml\")\n  {\n    if (\
 -e \"outfile\"){unlink (\"outfile\");}\n    if ( \
-e \"outtree\"){unlink (\"outtree\");}\n    \n    \
if ($stype eq \"prot\")\n      {\n	print \"Error: \
ML impossible with Protein Sequences [ERROR]\";\n	\
&my_exit (EXIT_FAILURE);\n      }\n    elsif ( $st\
ype eq \"dna\" || $stype eq \"cdna\")\n      {\n	p\
rint \"Run dnaml [tmode=$tmode]\";\n	open (F, \">$\
nb_c\");\n	if ($n>1){print F \"$seqboot_o\\nM\\nD\\
\n$n\\n$seed\\n10\\nY\\n\";}\n	else {print F \"$se\
qboot_o\\nY\\n\";}\n	close (F);\n	`dnaml$exec_exte\
nsion  < $nb_c`;\n      }\n    if ( -e \"outtree\"\
){ print \"[OK]\\n\";}\n    else { print \"[FAILED\
]\\n\";&my_exit (EXIT_FAILURE);}\n    `mv outtree \
$nb_o`;\n   unlink (\"outfile\");\n  }\n\n\nelse\n\
  {\n    `cp $msa $nb_o`;\n    $n=2;\n  }\n\nif ($\
rmsa && -e $seqboot_o){print \"\\nOutput List of $\
n Replicate MSA: $rmsa\\n\";`cp $seqboot_o $rmsa`;\
}\nif ($rmat && -e $protdist_o){print \"\\nOutput \
List of $n Replicate MATRICES: $rmat\\n\";`cp $pro\
tdist_o $rmat`;}\nif ($rtree && -e $nb_o){print \"\
\\nOutput List of $n Replicate TREES: $rtree\\n\";\
`cp $nb_o $rtree`;}\n\n\n\n$con_o=&vtmpnam();\n$co\
n_c=&vtmpnam();\nif ($n >1)\n  {\n    print \"Run \
Consense.....\";\n    open (F, \">$con_c\");\n    \
print F \"$nb_o\\nY\\n\";\n    close (F);\n    `co\
nsense$exec_extension  < $con_c`;\n    if ( -s \"o\
uttree\"  > 0) { print \"[OK]\\n\";}\n    else { p\
rint \"[FAILED]\\n\";&my_exit (EXIT_FAILURE);}\n  \
  `mv outtree $con_o`;\n    unlink (\"outfile\");\\
n  }\nelse\n  {\n    `cp $nb_o $con_o`;\n  }\n\n\n\
`cp $con_o $out`;\nif ( !-e $out)\n  {\n    print \
\"Tree Computation failed [FAILED]\\n\";\n    &my_\
exit (EXIT_FAILURE);\n  }\nelsif ($n>1)\n  {\n    \
print \"\\nOutput Bootstrapped Tree: $out\\n\";\n \
   $avg=`t_coffee -other_pg seq_reformat -in $out \
-action +avg_bootstrap`;\n    $avg=~s/\\n//g;\n   \
 print \"$avg\\n\";\n  }\nelse\n  {\n    print \"\\
\nOutput Tree: $out\\n\";\n  }\n\nopen (F, \"$out\\
");\nwhile (<F>)\n  {\n    \n    $tree.=$_;\n  }\n\
close (F);\n$tree=~s/\\n//g;\nprint \"BPH: $tree\\\
n\";\n\n\n&my_exit (EXIT_SUCCESS);\n\nsub my_exit \
\n  {\n    my $m=@_[0];\n    &clean_vtmpnam();\n  \
  exit ($m);\n  }\nsub vtmpnam \n  {\n    my $file\
;\n\n\n    $ntmp++;\n    $file=\"tmp4msa2bootstrap\
.$rseed.$$.$ntmp\";\n    \n    push (@tmpfile, $fi\
le);\n    return $file;\n  }\nsub clean_vtmpnam \n\
  {\n    my $t;\n    foreach $t (@tmpfile)\n      \
{\n	if ( -e $t){unlink ($t)};\n      }\n  }\n","us\
e Env;\nuse FileHandle;\nuse Cwd;\nuse File::Path;\
\nuse Sys::Hostname;\n\n\nour $PIDCHILD;\nour $ERR\
OR_DONE;\nour @TMPFILE_LIST;\nour $EXIT_FAILURE=1;\
\nour $EXIT_SUCCESS=0;\n\nour $REFDIR=getcwd;\nour\
 $EXIT_SUCCESS=0;\nour $EXIT_FAILURE=1;\n\nour $PR\
OGRAM=\"tc_generic_method.pl\";\nour $CL=$PROGRAM;\
\n\nour $CLEAN_EXIT_STARTED;\nour $debug_lock=$ENV\
{\"DEBUG_LOCK\"};\nour $debug_generic_method=$ENV{\
\"DEBUG_GENERIC_METHOD\"};\nour $LOCKDIR=$ENV{\"LO\
CKDIR_4_TCOFFEE\"};\nif (!$LOCKDIR){$LOCKDIR=getcw\
d();}\nour $ERRORDIR=$ENV{\"ERRORDIR_4_TCOFFEE\"};\
\nour $ERRORFILE=$ENV{\"ERRORFILE_4_TCOFFEE\"};\n&\
set_lock ($$);\nif (isshellpid(getppid())){lock4tc\
(getppid(), \"LLOCK\", \"LSET\", \"$$\\n\");}\nour\
 %RECODE;\nour $RECODE_N;\n\n\n\n\nour $BLAST_MAX_\
NRUNS=2;\nour $COMMAND;\nour $PIDCHILD;\n\n$REF_EM\
AIL=\"\";\n$tmp_dir=\"\";\n$init_dir=\"\";\n\n\n$t\
est=0;\nif ($test==1)\n  {\n    $SERVER=\"NCBI\";\\
n    $query=$ARGV[0];\n    $hitf=$ARGV[1];\n    %s\
=read_fasta_seq($query);\n    @sl=keys(%s);\n    &\
blast_xml2profile (\"xx\", $s{$sl[0]}{seq},$maxid,\
$minid,$mincov, $hitf);\n    myexit ($EXIT_FAILURE\
);\n  }\n\nforeach $v(@ARGV){$cl.=\"$v \";}\n$COMM\
AND=$cl;\n($mode)=&my_get_opt ( $cl, \"-mode=\",1,\
0);\n\n($A)=(&my_get_opt ( $cl, \"-name1=\",0,0));\
\n($B)=(&my_get_opt ( $cl, \"-name2=\",0,0));\n($T\
MPDIR)=(&my_get_opt ( $cl, \"-tmpdir=\",0,0));\n($\
CACHE)=(&my_get_opt ( $cl, \"-cache=\",0,0));\n($S\
ERVER)=((&my_get_opt ( $cl, \"-server=\",0,0)));\n\
($EMAIL)=((&my_get_opt ( $cl, \"-email=\",0,0)));\\
n\nif (!$A){$A=\"A\";}\nif (!$B){$B=\"B\";}\n\n\ni\
f (!$TMPDIR)\n  {\n    $HOME=$ENV{HOME};\n    if (\
$ENV{TMP_4_TCOFFEE}){$TMPDIR=$ENV{TMP_4_TCOFFEE};}\
\n    else{$TMPDIR=\"$HOME/.t_coffee/tmp/\";}\n  }\
\nif ( ! -d $TMPDIR)\n  {\n    mkdir $TMPDIR;\n  }\
\nif ( ! -d $TMPDIR)\n  {\n    print \"ERROR: Coul\
d not create temporary dir: $TMPDIR\\n\";\n    mye\
xit ($EXIT_FAILURE);\n  }\n\n$EMAIL=~s/XEMAILX/\\@\
/g;\nif (!$EMAIL)\n  {\n    if ($ENV{EMAIL_4_TCOFF\
EE}){$EMAIL=$ENV{EMAIL_4_TCOFFEE};}\n    elsif ($E\
NV{EMAIL}){$EMAIL=$ENV{EMAIL};}\n    else {$EMAIL=\
$REF_EMAIL;}\n  }\n\n($maxid,$minid,$mincov,$trim)\
=(&my_get_opt ( $cl, \"-maxid=\",0,0, \"-minid=\",\
0,0,\"-mincov=\",0,0, \"-trim=\",0,0));\nif (!$cl=\
~/\\-maxid\\=/){$maxid=95;}\nif (!$cl=~/\\-minid\\\
=/){$minid=35;}\nif (!$cl=~/\\-mincov\\=/){$mincov\
=80;}\nif (!$cl=~/\\-trim\\=/){$trim;}\n\n\n\n\nif\
 ($mode eq \"seq_msa\")\n  {\n    &seq2msa($mode,&\
my_get_opt ( $cl, \"-infile=\",1,1, \"-method=\",1\
,2, \"-param=\",0,0,\"-outfile=\",1,0, \"-database\
=\",0,0));\n  }\nelsif ( $mode eq \"tblastx_msa\")\
\n  {\n    &seq2tblastx_lib ($mode,&my_get_opt ( $\
cl, \"-infile=\",1,1, \"-outfile=\",1,0));\n  }\ne\
lsif ( $mode eq \"tblastpx_msa\")\n  {\n    &seq2t\
blastpx_lib ($mode,&my_get_opt ( $cl, \"-infile=\"\
,1,1, \"-outfile=\",1,0));\n  }\nelsif ( $mode eq \
\"thread_pair\")\n  {\n    &seq2thread_pair($mode,\
&my_get_opt ( $cl, \"-infile=\",1,1, \"-pdbfile1=\\
",1,1, \"-method=\",1,2,\"-param=\",0,0, \"-outfil\
e=\",1,0, ));\n  }\nelsif ( $mode eq \"pdbid_pair\\
")\n  {\n    &seq2pdbid_pair($mode,&my_get_opt ( $\
cl, \"-pdbfile1=\",1,0, \"-pdbfile2=\",1,0, \"-met\
hod=\",1,2,\"-param=\",0,0, \"-outfile=\",1,0, ));\
\n  }\nelsif ( $mode eq \"pdb_pair\")\n  {\n    &s\
eq2pdb_pair($mode,&my_get_opt ( $cl, \"-pdbfile1=\\
",1,1, \"-pdbfile2=\",1,1, \"-method=\",1,2,\"-par\
am=\",0,0, \"-outfile=\",1,0, ));\n  }\nelsif ( $m\
ode eq \"rnapdb_pair\")\n{\n    &seq2rnapdb_pair($\
mode,&my_get_opt ( $cl, \"-pdbfile1=\",1,1, \"-pdb\
file2=\",1,1, \"-method=\",1,2,\"-param=\",0,0, \"\
-outfile=\",1,0, ));\n}\nelsif ( $mode eq \"profil\
e_pair\")\n  {\n     &seq2profile_pair($mode,&my_g\
et_opt ( $cl, \"-profile1=\",1,1, \"-profile2=\",1\
,1, \"-method=\",1,2,\"-param=\",0,0, \"-outfile=\\
",1,0 ));\n  }\nelsif ($mode eq \"pdb_template_tes\
t\")\n  {\n    &blast2pdb_template_test ($mode,&my\
_get_opt ( $cl, \"-infile=\",1,1));\n\n  }\nelsif \
($mode eq \"psi_template_test\")\n  {\n    &psibla\
st2profile_template_test ($mode,&my_get_opt ( $cl,\
 \"-seq=\",1,1,\"-blast=\",1,1));\n\n  }\n\nelsif \
( $mode eq \"pdb_template\")\n  {\n    &blast2pdb_\
template ($mode,&my_get_opt ( $cl, \"-infile=\",1,\
1, \"-database=\",1,0, \"-method=\",1,0, \"-outfil\
e=\",1,0,\"-pdb_type=\",1,0));\n  }\n\nelsif ( $mo\
de eq \"profile_template\")\n  {\n\n    &seq2profi\
le_template ($mode,&my_get_opt ( $cl, \"-infile=\"\
,1,1, \"-database=\",1,0, \"-method=\",1,0, \"-out\
file=\",1,0));\n  }\nelsif ( $mode eq \"psiprofile\
_template\")\n  {\n    &seq2profile_template ($mod\
e,&my_get_opt ( $cl, \"-infile=\",1,1, \"-database\
=\",1,0, \"-method=\",1,0, \"-outfile=\",1,0));\n \
 }\nelsif ( $mode eq \"RNA_template\")\n  {\n    &\
seq2RNA_template ($mode,&my_get_opt ( $cl, \"-infi\
le=\",1,1,\"-pdbfile=\",1,1,\"-outfile=\",1,0));\n\
  }\nelsif ( $mode eq \"tm_template\")\n  {\n    &\
seq2tm_template ($mode,&my_get_opt ( $cl, \"-infil\
e=\",1,1,\"-arch=\",1,1,\"-psv=\",1,1, \"-outfile=\
\",1,0));\n  }\nelsif ( $mode eq \"psitm_template\\
")\n  {\n    &seq2tm_template ($mode,&my_get_opt (\
 $cl, \"-infile=\",1,1, \"-arch=\",1,1,\"-psv=\",1\
,1, \"-outfile=\",1,0,\"-database=\",1,0));\n  }\n\
elsif ( $mode eq \"ssp_template\")\n  {\n    &seq2\
ssp_template ($mode,&my_get_opt ( $cl, \"-infile=\\
",1,1,\"-seq=\",1,1,\"-obs=\",1,1, \"-outfile=\",1\
,0));\n  }\nelsif ( $mode eq \"psissp_template\")\\
n  {\n    &seq2ssp_template ($mode,&my_get_opt ( $\
cl, \"-infile=\",1,1,\"-seq=\",1,1,\"-obs=\",1,1, \
\"-outfile=\",1,0));\n  }\n\n\n\nelse\n  {\n    my\
exit(flush_error( \"$mode is an unknown mode of tc\
_generic_method.pl\"));\n  }\nmyexit ($EXIT_SUCCES\
S);\n\n\nsub seq2ssp_template\n  {\n  my ($mode, $\
infile,$gor_seq,$gor_obs,$outfile)=@_;\n  my %s, %\
h;\n  my $result;\n  my (@profiles);\n  &set_tempo\
rary_dir (\"set\",$infile,\"seq.pep\");\n  %s=read\
_fasta_seq (\"seq.pep\");\n\n\n  open (R, \">resul\
t.aln\");\n\n  #print stdout \"\\n\";\n  foreach $\
seq (keys(%s))\n    {\n\n      open (F, \">seqfile\
\");\n      $s{$seq}{seq}=uc$s{$seq}{seq};\n      \
print (F \">$s{$seq}{name}\\n$s{$seq}{seq}\\n\");\\
n      close (F);\n      $lib_name=\"$s{$seq}{name\
}.ssp\";\n      $lib_name=&clean_file_name ($lib_n\
ame);\n\n      if ($mode eq \"ssp_template\"){&seq\
2gor_prediction ($s{$seq}{name},$s{$seq}{seq}, \"s\
eqfile\", $lib_name,$gor_seq, $gor_obs);}\n      e\
lsif ($mode eq \"psissp_template\")\n	{\n	  &seq2m\
sa_gor_prediction ($s{$seq}{name},$s{$seq}{seq},\"\
seqfile\", $lib_name,$gor_seq, $gor_obs);\n	}\n\n \
     if ( !-e $lib_name)\n	{\n	  myexit(flush_erro\
r(\"GORIV failed to compute the secondary structur\
e of $s{$seq}{name}\"));\n	  myexit ($EXIT_FAILURE\
);\n	}\n      else\n	{\n	  print stdout \"!\\tProc\
ess: >$s{$seq}{name} _E_ $lib_name \\n\";\n	  prin\
t R \">$s{$seq}{name} _E_ $lib_name\\n\";\n	}\n   \
   unshift (@profiles, $lib_name);\n    }\n  close\
 (R);\n  &set_temporary_dir (\"unset\",$mode, $met\
hod,\"result.aln\",$outfile, @profiles);\n}\n\nsub\
 seq2tm_template\n  {\n  my ($mode,$infile,$arch,$\
psv,$outfile,$db)=@_;\n  my %s, %h;\n  my $result;\
\n  my (@profiles);\n  &set_temporary_dir (\"set\"\
,$infile,\"seq.pep\");\n  %s=read_fasta_seq (\"seq\
.pep\");\n\n\n  open (R, \">result.aln\");\n\n  #p\
rint stdout \"\\n\";\n  foreach $seq (keys(%s))\n \
   {\n      open (F, \">seqfile\");\n      print (\
F \">$s{$seq}{name}\\n$s{$seq}{seq}\\n\");\n      \
close (F);\n      $lib_name=\"$s{$seq}{name}.tmp\"\
;\n      $lib_name=&clean_file_name ($lib_name);\n\
\n      if ($mode eq \"tm_template\")\n	{\n	  &saf\
e_system (\"t_coffee -other_pg fasta_seq2hmmtop_fa\
sta.pl -in=seqfile -out=$lib_name -arch=$arch -psv\
=$psv\");\n	}\n      elsif ( $mode eq \"psitm_temp\
late\")\n	{\n	  &seq2msa_tm_prediction ($s{$seq}{n\
ame},$s{$seq}{seq}, $db, \"seqfile\", $lib_name,$a\
rch, $psv);\n	}\n      if ( !-e $lib_name)\n	{\n	 \
 myexit(flush_error(\"hmmtop failed to compute the\
 secondary structure of $s{$seq}{name}\"));\n	  my\
exit ($EXIT_FAILURE);\n	}\n      else\n	{\n	  prin\
t stdout \"!\\tProcess: >$s{$seq}{name} _T_ $lib_n\
ame\\n\";\n	  print R \">$s{$seq}{name} _T_ $lib_n\
ame\\n\";\n	}\n      unshift (@profiles, $lib_name\
);\n    }\n  close (R);\n  &set_temporary_dir (\"u\
nset\",$mode, $method,\"result.aln\",$outfile, @pr\
ofiles);\n}\n\n\n\nsub seq2RNA_template\n  {\n    \
\n    my ($mode, $infile, $pdbfile, $outfile)=@_;\\
n    my %s, %h ;\n    my $result;\n    my (@profil\
es);\n    my ($seq_mode, $pdb_mode, $pwd);\n    \n\
    #use $seq_mode to estimate the template of seq\
uences WITHOUT a PDB\n    #use $pdb_mode to estima\
te the template of sequences WITH    a PDB\n\n    \
$seq_mode=$ENV{\"SEQ2TEMPLATE4_F_\"};\n    $pdb_mo\
de=$ENV{\"PDB2TEMPLATE4_F_\"};\n    \n    if (!$pd\
b_mode){$pdb_mode=\"find_pair-p\";}\n    if (!$seq\
_mode){$seq_mode=\"RNAplfold\";}\n    \n    my $cw\
d = cwd();\n    &set_temporary_dir (\"set\",$infil\
e,\"seq.pep\");\n    %s=read_fasta_seq (\"seq.pep\\
");\n    %pdb_template_h = &read_template_file($pd\
bfile);\n    my $pdb_chain;\n    \n       \n    op\
en (R, \">result.aln\");\n    #print stdout \"\\n\\
";\n    foreach $seq (keys(%s))\n      {\n	\n	open\
 (F, \">seqfile\");\n	print (F \">$s{$seq}{name}\\\
n$s{$seq}{seq}\\n\");\n	close (F);\n	$pdb_chain = \
$pdb_template_h{$seq};\n	$lib_name=\"$s{$seq}{name\
}.rfold\";\n	$lib_name=&clean_file_name ($lib_name\
);\n	if ($pdb_template_h{$seq} eq \"\")\n	  {\n	  \
  if    ($seq_mode eq \"RNAplfold\"){RNAplfold2lib\
 (\"seqfile\", \"$lib_name\");}\n	    elsif ($seq_\
mode eq \"no\"){$lib_name=0;}\n	    else\n	      {\
\n		myexit(add_error (EXIT_FAILURE,$$,$$,getppid()\
, \"seq2RNA_template failure::method $seq_mode not\
 available for sequences without PDB structures\")\
);\n	      }\n	  }\n	elsif ($pdb_template_h{$seq} \
ne \"\")\n	  {\n	    my $pdbf;\n	    if (-e \"$cwd\
/$pdb_chain\"){$pdbf=\"$cwd/$pdb_chain\";}\n	    e\
lse {$pdbf=\"$CACHE$pdb_chain\";}\n	    \n\n	    i\
f($pdb_mode eq \"x3dna-ssr\")\n	      {\n		x3dnass\
r2lib (\"seqfile\", \"$pdbf\", \"$lib_name\");\n	 \
     }\n	    elsif ($pdb_mode eq \"find_pair-p\")\\
n	      {\n		x3dna_find_pair2lib (\"seqfile\", \"$\
pdbf\", \"$lib_name\", \"find_pair -p\");\n	      \
}\n	    elsif ($pdb_mode eq \"find_pair\")\n	     \
 {\n		x3dna_find_pair2lib (\"seqfile\", \"$pdbf\",\
 \"$lib_name\", \"find_pair\");\n	      }\n	    el\
sif ($pdb_mode eq \"RNAplfold\")\n	      {\n		RNAp\
lfold2lib (\"seqfile\", \"$lib_name\");\n	      }\\
n	    elsif ($pdb_mode eq \"no\"){$lib_name=0;}\n	\
    else\n	      {\n		myexit(add_error (EXIT_FAILU\
RE,$$,$$,getppid(), \"seq2RNA_template failure::Co\
uld not find method $pdb_mode\"));\n	      }\n	  }\
\n	if ($lib_name)\n	  {\n	    print stdout \"!\\tP\
rocess: >$s{$seq}{name} _F_ $lib_name\\n\";\n	    \
print R \">$s{$seq}{name} _F_ $lib_name\\n\";\n	  \
  unshift (@profiles, $lib_name);\n	  }\n      }\n\
    close (R);\n    &set_temporary_dir (\"unset\",\
$mode, $method,\"result.aln\",$outfile, @profiles)\
;\n  }\n\n\n\nsub psiblast2profile_template_test\n\
  {\n  my ($mode, $seq,$blast)=@_;\n  my %s, %h, ;\
\n  my ($result,$psiblast_output,$profile_name,@pr\
ofiles);\n  my $trim=0;\n  my $maxid=100;\n  my $m\
inid=0;\n  my $mincov=0;\n  my $maxcov=100;\n\n  %\
s=read_fasta_seq ($seq);\n  open (R, \">result.aln\
\");\n\n  #print stdout \"\\n\";\n  foreach $seq (\
keys(%s))\n    {\n\n      open (F, \">seqfile\");\\
n      print (F \">$A\\n$s{$seq}{seq}\\n\");\n    \
  close (F);\n      $psiblast_output=$blast;\n    \
  if ( -e $psiblast_output)\n	{\n	  %profile=blast\
_xml2profile($s{$seq}{name}, $s{$seq}{seq},$maxid,\
 $minid,$mincov,$psiblast_output);\n\n\n\n	  $prof\
ile_name=\"$s{$seq}{name}.prf\";\n	  $profile_name\
=&clean_file_name ($profile_name);\n	  unshift (@p\
rofiles, $profile_name);\n	  output_profile ($prof\
ile_name, \\%profile, $trim);\n	  print stdout \"!\
\\tProcess: >$s{$seq}{name} _R_ $profile_name [$pr\
ofile{n} Seq.] [$SERVER/blast/$db][$CACHE_STATUS]\\
\n\";\n	  print R \">$s{$seq}{name} _R_ $profile_n\
ame\\n\";\n	}\n    }\n  close (R);\n\n  die;\n}\ns\
ub seq2profile_template\n    {\n      my ($mode, $\
infile, $db, $method, $outfile)=@_;\n      if    (\
$method eq \"psiblast\"){return psiblast2profile_t\
emplate ($mode, $infile, $db, $method, $outfile);}\
\n      elsif ($method eq \"blastp\")   {return ps\
iblast2profile_template ($mode, $infile, $db, $met\
hod, $outfile);}\n      elsif ($method eq \"hh\") \
     {return hh2profile_template ($mode, $infile, \
$db, $method, $outfile);}\n    }\n\nsub psiblast2p\
rofile_template\n  {\n  my ($mode, $infile, $db, $\
method, $outfile)=@_;\n  my %s, %h, ;\n  my ($resu\
lt,$psiblast_output,$profile_name,@profiles);\n  &\
set_temporary_dir (\"set\",$infile,\"seq.pep\");\n\
  %s=read_fasta_seq (\"seq.pep\");\n  open (R, \">\
result.aln\");\n\n  #print stdout \"\\n\";\n  fore\
ach $seq (keys(%s))\n    {\n      open (F, \">seqf\
ile\");\n      print (F \">$A\\n$s{$seq}{seq}\\n\"\
);\n      close (F);\n      $psiblast_output=&run_\
blast ($s{$seq}{name},$method, $db, \"seqfile\",\"\
outfile\");\n\n      if ( -e $psiblast_output)\n	{\
\n	  my %profile=blast_xml2profile($s{$seq}{name},\
 $s{$seq}{seq},$maxid, $minid,$mincov,$psiblast_ou\
tput);\n	  unlink ($psiblast_output);\n	  \n	  $pr\
ofile_name=\"$s{$seq}{name}.prf\";\n	  $profile_na\
me=&clean_file_name ($profile_name);\n	  unshift (\
@profiles, $profile_name);\n	  output_profile ($pr\
ofile_name, \\%profile, $trim);\n	  \n	  print std\
out \"!\\tProcess: >$s{$seq}{name} _R_ $profile_na\
me [$profile{n} Seq.] [$SERVER/blast/$db][$CACHE_S\
TATUS]\\n\";\n	  print R \">$s{$seq}{name} _R_ $pr\
ofile_name\\n\";\n	  \n	  \n	}\n      \n    }\n  c\
lose (R);\n  \n  \n\n  &set_temporary_dir (\"unset\
\",$mode, $method,\"result.aln\",$outfile, @profil\
es);\n}\n\nsub hh2profile_template\n  {\n\n  #for \
each sequence, build a profile, in FASTA, with ung\
apped querry on top  \n  my ($mode, $infile, $db, \
$method, $outfile)=@_;\n  my %s, %h, ;\n  my ($res\
ult,$psiblast_output,$profile_name,@profiles);\n  \
&set_temporary_dir (\"set\",$infile,\"seq.pep\");\\
n  %s=read_fasta_seq (\"seq.pep\");\n  open (R, \"\
>result.aln\");\n  \n  my $hh=$ENV{\"HHSEARCH_4_TC\
OFFEE\"};\n  if (!$hh)\n    {\n      print \"ERROR\
: HHSEARCH_4_TCOFFEE is not set\\n\";\n      myexi\
t ($EXIT_FAILURE);\n    }\n  \n  #print stdout \"\\
\n\";\n  foreach $seq (keys(%s))\n    {\n      my \
($profile_name, $nseq);\n      open (F, \">seqfile\
\");\n      print (F \">$A\\n$s{$seq}{seq}\\n\");\\
n      close (F);\n      \n      #This function sh\
ould input a querry and a database and return as o\
utput a fasta MSA with quesry on top\n      $profi\
le_name=\"$s{$seq}{name}.prf\";\n      $profile_na\
me=&clean_file_name ($profile_name);\n      unshif\
t (@profiles, $profile_name);\n      \n      \n   \
   safe_system  (\"$hh -name=$s{$seq}{name} -metho\
d=search -db=$db -seq=seqfile -outfile=$profile_na\
me\");\n      if (-e $profile_name){$nseq=fasta2ns\
eq($profile_name);}\n      \n      print stdout \"\
!\\tProcess: >$s{$seq}{name} _R_ $profile_name [$n\
seq Seq.] [$method/$db][$CACHE_STATUS]\\n\";\n    \
  print R \">$s{$seq}{name} _R_ $profile_name\\n\"\
;\n    }\n  close (R);\n  &set_temporary_dir (\"un\
set\",$mode, $method,\"result.aln\",$outfile, @pro\
files);\n}\n\nsub blast2pdb_template_test\n    {\n\
      my ($mode,$infile)=@_;\n      my ($maxid,$mi\
nid,$mincov);\n      $maxid=100;\n      $minid=0;\\
n      $mincov=0;\n\n      print \"$infile\\n\";\n\
\n      %p=blast_xml2profile($s{$seq}{name}, $s{$s\
eq}{seq},$maxid, $minid,$mincov,$infile);\n      $\
c=1;\n      print stdout \"!\\tProcess: >$s{$seq}{\
name} [$SERVER/blast/$db][$CACHE_STATUS]\\n\";\n  \
    while (!$found && $c<$p{n})\n	{\n	  $pdbid=&id\
2pdbid($p{$c}{identifyer});\n	  if ( length ($pdbi\
d)>5){$pdbid=id2pdbid($p{$c}{definition});}\n\n	  \
if ( length ($pdbid)>5)\n	    {\n	      myexit(add\
_error (EXIT_FAILURE,$$,$$,getppid(), \"BLAST_FAIL\
URE::Could Not Parse PDBID ($p{$c}{identifyer},$p{\
$c}{definition})\"));\n	    }\n\n\n	  if (!&pdb_is\
_released($pdbid))\n	    {\n	      print stdout \"\
\\t\\t**$pdbid [WARNIG: PDB NOT RELEASED or WITHDR\
AWN]\\n\";\n	      $c++;\n	    }\n	  elsif (!&pdb_\
has_right_type ($pdbid,$type))\n	    {\n	      my \
$ptype=&pdb2type ($pdbid);\n	      my $etype=&type\
2etype($type);\n\n	      print stdout \"\\t\\t**$p\
dbid [$ptype cannot be used (expected: $etype)]\\n\
\";\n	      $c++;\n	    }\n	  else\n	    {\n	     \
 $found=1;\n	    }\n	}\n\n      if ($found)\n	{\n	\
  print stdout \"\\t\\t >$s{$seq}{name} _P_ $pdbid\
\\n\";\n	}\n      else\n	{\n	  print stdout \"\\t\\
\t >$s{$seq}{name} No Template Selected\\n\";\n	}\\
n      die;\n    }\nsub blast2pdb_template\n  {\n \
 my ($mode, $infile, $db, $method, $outfile,$type)\
=@_;\n  my %s, %h, ;\n  my ($result,$blast_output)\
;\n  &set_temporary_dir (\"set\",$infile,\"seq.pep\
\");\n  %s=read_fasta_seq (\"seq.pep\");\n  open (\
R, \">result.aln\");\n\n\n  #print stdout \"\\n\";\
\n  foreach $seq (keys(%s))\n    {\n      my $c;\n\
      my $found;\n\n      open (F, \">seqfile\");\\
n      print (F \">$A\\n$s{$seq}{seq}\\n\");\n    \
  close (F);\n\n      $blast_output=&run_blast ($s\
{$seq}{name},$method, $db, \"seqfile\",\"outfile\"\
);\n\n      %p=blast_xml2profile($s{$seq}{name}, $\
s{$seq}{seq},$maxid, $minid,$mincov,$blast_output)\
;\n      unlink ($blast_output);\n\n      $c=1;\n \
     print stdout \"!\\tProcess: >$s{$seq}{name} [\
$SERVER/blast/$db][$CACHE_STATUS]\\n\";\n      whi\
le (!$found && $c<$p{n})\n	{\n	  $pdbid=&id2pdbid(\
$p{$c}{identifyer});\n	  if ( length ($pdbid)>5){$\
pdbid=id2pdbid($p{$c}{definition});}\n\n	  if ( le\
ngth ($pdbid)>5)\n	    {\n	      myexit(add_error \
(EXIT_FAILURE,$$,$$,getppid(), \"BLAST_FAILURE::Co\
uld Not Parse PDBID ($p{$c}{identifyer},$p{$c}{def\
inition})\"));\n	    }\n\n\n	  if (!&pdb_is_releas\
ed($pdbid))\n	    {\n	      print stdout \"\\t\\t*\
*$pdbid [PDB NOT RELEASED or WITHDRAWN]\\n\";\n	  \
    $c++;\n	    }\n	  elsif (!&pdb_has_right_type \
($pdbid,$type))\n	    {\n	      my $ptype=&pdb2typ\
e ($pdbid);\n	      my $etype=&type2etype($type);\\
n\n	      print stdout \"\\t\\t**$pdbid [$ptype ca\
nnot be used (expected: $etype)]\\n\";\n	      $c+\
+;\n	    }\n	  else\n	    {\n	      $found=1;\n	  \
  }\n	}\n\n      if ($found)\n	{\n	  print R \">$s\
{$seq}{name} _P_ $pdbid\\n\";\n	  print stdout \"\\
\t\\t >$s{$seq}{name} _P_ $pdbid\\n\";\n	}\n      \
else\n	{\n	  print R \">$s{$seq}{name}\\n\";\n	  p\
rint stdout \"\\t\\t >$s{$seq}{name} No Template S\
elected\\n\";\n	}\n    }\n  close (R);\n  &set_tem\
porary_dir (\"unset\",$mode, $method,\"result.aln\\
",$outfile);\n}\nsub type2etype\n  {\n    my $type\
=shift;\n    my $etype;\n\n    if ( $type=~/n/){$e\
type.=\"NMR \";}\n    if ( $type=~/d/){$etype.=\"d\
iffraction \";}\n    if ( $type=~/m/){$etype.=\"mo\
del \";}\n    return $etype;\n  }\nsub pdb2type\n \
 {\n     my $pdb=shift;\n     my $f=vtmpnam();\n\n\
     my $value= &safe_system (\"t_coffee -other_pg\
 extract_from_pdb -model_type $pdb > $f\");\n     \
my $r=&file2string ($f);\n     chomp($r);\n     re\
turn $r;\n   }\nsub pdb_has_right_type\n  {\n    m\
y $pdb=shift;\n    my $type=shift;\n\n    my $f=vt\
mpnam();\n\n    my $value= &safe_system (\"t_coffe\
e -other_pg extract_from_pdb -model_type $pdb > $f\
\");\n    my $r=&file2string ($f);\n    chomp($r);\
\n\n\n    if ( $r eq \"NMR\" && $type=~/n/){return\
 1;}\n    elsif ( $r eq \"diffraction\" && $type=~\
/d/){return 1;}\n    elsif ( $r eq \"model\" && $t\
ype=~/m/){return 1;}\n    else {return 0;}\n  }\ns\
ub pdb_is_released\n  {\n    my $pdb=shift;\n    m\
y $f=vtmpnam();\n\n    $value= &safe_system (\"t_c\
offee -other_pg extract_from_pdb -is_released_pdb_\
name $pdb > $f\");\n    my $r=&file2string ($f);\n\
    chomp($r);\n    return $r;\n  }\nsub blast_msa\
\n  {\n    my ($blast,$infile,$db,$outfile)=@_;\n \
   my ($a, %s1, %s, %qs, %qs1);\n    my $seqfile;\\
n    my $SEQ=new FileHandle;\n    my $seqfile=\"se\
qfile\";\n    my @txt;\n\n\n    %s1=&read_fasta_se\
q ($db);\n    %s=&fasta_hash2index_hash(%s1);\n   \
 %qs1=&read_fasta_seq ($infile);\n    %qs=&fasta_h\
ash2index_hash(%qs1);\n\n\n    #&safe_system (\"fo\
rmatdb -i $db\");\n    if ($blast eq \"blastp\"){&\
safe_system  (\"blastall -i $infile -d $db -m7 -p \
blastp -o io\");}\n    elsif ($blast eq \"blastn\"\
){&safe_system  (\"blastn -query $infile -db $db -\
outfmt 5 -word_size 4 -out io\");}\n\n    &set_bla\
st_type (\"io\");\n\n\n    my %FB=&xml2tag_list (\\
"io\", \"Iteration\");\n    open (F, \">$outfile\"\
);\n    print F \"! TC_LIB_FORMAT_01\\n\";\n    pr\
int F \"$s{n}\\n\";\n    for ( my $a=0; $a<$s{n}; \
$a++)\n      {\n	print F \"$s{$a}{name} $s{$a}{len\
} $s{$a}{seq}\\n\";\n      }\n\n\n    for ( my $a=\
0; $a<$FB{n}; $a++)\n      {\n	my %p=blast_xml2pro\
file ($qs{$a}{name}, $qs{$a}{seq},100, 0, 0, $FB{$\
a}{body});\n	my $query=$p{0}{name};\n	my $i= $s1{$\
query}{order}+1;\n	for (my $b=1; $b<$p{n}; $b++)\n\
	  {\n	    my $l=length ($p{$b}{Qseq});\n	    my $\
hit=$p{$b}{definition};\n	    my $Qstart=$p{$b}{Qs\
tart};\n	    my $Hstart=$p{$b}{Hstart};\n	    my $\
identity=$p{$b}{identity};\n	    my @lrQ=split (//\
,$p{$b}{Qseq});\n	    my @lrH=split (//,$p{$b}{Hse\
q});\n\n	    my $j= $s1{$hit}{order}+1;\n	    #if \
( $j==$i){next;}\n	    printf F \"# %d %d\\n\", $i\
, $j;\n	    #  print  F \"\\n$p{$b}{Qseq} ($Qstart\
)\\n$p{$b}{Hseq} ($Hstart)\";\n	    for ($c=0; $c<\
$l; $c++)\n	      {\n		my $rQ=$lrQ[$c];\n		my $rH=\
$lrH[$c];\n		my $n=0;\n\n		if ($rQ ne \"-\"){$n++,\
 $Qstart++;}\n		if ($rH ne \"-\"){$n++; $Hstart++;\
}\n\n		if ( $n==2)\n		  {\n		    printf F \"\\t%d \
%d %d\\n\", $Qstart-1, $Hstart-1,$identity;\n		  }\
\n	      }\n	  }\n      }\n    print F \"! SEQ_1_T\
O_N\\n\";\n    close (F);\n    return $output;\n  \
}\n\nsub blast_msa_old\n  {\n    my ($infile,$outf\
ile)=@_;\n    my ($a, %seq);\n    %s1=&read_fasta_\
seq ($infile);\n    foreach $s (keys (%s1))\n     \
 {\n	$i=$s1{$s}{order};\n	$s{$i}{name}=$s;\n	$s{$i\
}{seq}=$s1{$s}{seq};\n	$s{$i}{len}=length( $s{$i}{\
seq});\n	$s{n}++;\n      }\n    &safe_system (\"fo\
rmatdb -i $infile\");\n    &safe_system (\"blastal\
l -i $infile -d $infile -m7 -o io\");\n    &set_bl\
ast_type (\"io\");\n\n    %FB=&xml2tag_list (\"io\\
", \"Iteration\");\n\n    open (F, \">$outfile\");\
\n    print F \"! TC_LIB_FORMAT_01\\n\";\n    prin\
t F \"$s{n}\\n\";\n    for ( $a=0; $a<$s{n}; $a++)\
\n      {\n	print F \"$s{$a}{name} $s{$a}{len} $s{\
$a}{seq}\\n\";\n      }\n    for ( $a=0; $a<$FB{n}\
; $a++)\n      {\n	%p=blast_xml2profile ($s{$a}{na\
me}, $s{$a}{seq},100, 0, 0, $FB{$a}{body});\n	for \
($b=1; $b<$p{n}; $b++)\n	  {\n	    my $l=length ($\
p{$b}{Qseq});\n	    my $hit=$p{$b}{definition};\n	\
    my $Qstart=$p{$b}{Qstart};\n	    my $Hstart=$p\
{$b}{Hstart};\n	    my $identity=$p{$b}{identity};\
\n	    my @lrQ=split (//,$p{$b}{Qseq});\n	    my @\
lrH=split (//,$p{$b}{Hseq});\n	    my $i= $s1{$s{$\
a}{name}}{order}+1;\n	    my $j= $s1{$hit}{order}+\
1;\n	    #if ( $j==$i){next;}\n	    printf F \"# %\
d %d\\n\", $i, $j;\n	    #  print  F \"\\n$p{$b}{Q\
seq} ($Qstart)\\n$p{$b}{Hseq} ($Hstart)\";\n	    f\
or ($c=0; $c<$l; $c++)\n	      {\n		my $rQ=$lrQ[$c\
];\n		my $rH=$lrH[$c];\n		my $n=0;\n\n		if ($rQ ne\
 \"-\"){$n++, $Qstart++;}\n		if ($rH ne \"-\"){$n+\
+; $Hstart++;}\n\n		if ( $n==2)\n		  {\n		    prin\
tf F \"\\t%d %d %d\\n\", $Qstart-1, $Hstart-1,$ide\
ntity;\n		  }\n	      }\n	  }\n      }\n    print \
F \"! SEQ_1_TO_N\\n\";\n    close (F);\n    return\
 $output;\n\n  }\n\nsub seq2msa\n  {\n    my ($mod\
e, $infile, $method, $param, $outfile,$database)=@\
_;\n    &set_temporary_dir (\"set\",$infile,\"seq.\
pep\", $database, \"db.pep\");\n    $param.=\" >/d\
ev/null 2>&1 \";\n\n\n    #make sure test.pep is i\
n FASTA\n    &safe_system (\"t_coffee -other_pg se\
q_reformat -in seq.pep -output fasta_seq > x\");\n\
    `mv x seq.pep`;\n\n    if ( $method eq \"blast\
p\")\n      {\n	&blast_msa (\"blastp\",\"seq.pep\"\
,$database,\"result.aln\");\n      }\n    elsif ( \
$method eq \"blastn\")\n      {\n	&blast_msa (\"bl\
astn\",\"seq.pep\",$database,\"result.aln\");\n   \
   }\n\n    elsif ( $method eq \"muscle\")\n      \
{\n	`muscle -in seq.pep -out result.aln $param`;\n\
      }\n    elsif ( $method eq \"probcons\")\n   \
   {\n	`probcons seq.pep >result.aln 2>/dev/null`;\
\n      }\n    elsif ( $method eq \"mafft\")\n    \
  {\n	`mafft --quiet --localpair --maxiterate 1000\
 seq.pep> result.aln  2>/dev/null`\n      }\n    e\
lsif ( $method=~/prank/)\n      {\n	`$method -d=se\
q.pep -o=result.aln -quiet 2>/dev/null`;\n	`mv res\
ult.aln.1.fas result.aln`;\n      }\n    elsif ($m\
ethod eq \"clustalo\")\n      {\n	`clustalo -i seq\
.pep > result.aln`;\n      }\n\n    else\n      {\\
n	`$method -infile=seq.pep -outfile=result.aln`;\n\
      }\n\n    &set_temporary_dir (\"unset\",$mode\
, $method,\"result.aln\",$outfile);\n    myexit ($\
EXIT_SUCCESS);\n  }\n\nsub seq2thread_pair\n  {\n \
   my ($mode, $infile, $pdbfile1, $method, $param,\
 $outfile)=@_;\n    &set_temporary_dir (\"set\",$i\
nfile,\"seq.pep\",$pdbfile1,\"struc.pdb\");\n    i\
f ($method eq \"fugueali\")\n      {\n	#Env Variab\
le that need to be defined for Fugue\n	if (!$ENV{F\
UGUE_LIB_LIST}){$ENV{FUGUE_LIB_LIST}=\"DUMMY\";}\n\
	if (!$ENV{HOMSTRAD_PATH})  {$ENV{HOMSTRAD_PATH}=\\
"DUMMY\";}\n	if (!$ENV{HOMS_PATH}){$ENV{HOMS_PATH}\
=\"DUMMY\";}\n\n	`joy struc.pdb >x 2>x`;\n	&check_\
file(\"struc.tem\", \"Joy failed [FATAL:$PROGRAM/$\
method]\");\n	`melody -t struc.tem >x 2>x`;\n	&che\
ck_file(\"struc.tem\", \"Melody failed [FATAL:$PRO\
GRAM/$method]\");\n	`fugueali -seq seq.pep -prf st\
ruc.fug -print > tmp_result.aln`;\n\n	&check_file(\
\"tmp_result.aln\", \"Fugue failed [FATAL:$PROGRAM\
/$method]\");\n	&safe_system (\"t_coffee -other_pg\
 seq_reformat -in tmp_result.aln -output fasta_aln\
 >result.aln\");\n      }\n    elsif ( $method eq \
\"t_coffee\")\n      {\n	&safe_system (\"t_coffee \
-in Pstruc.pdb Sseq.pep Mslow_pair -outfile result\
.aln -quiet\");\n      }\n    else\n      {\n	&saf\
e_system (\"$method -infile=seq.pep -pdbfile1=stru\
c.pdb -outfile=result.aln $param>x 2>x\");\n      \
}\n    &set_temporary_dir (\"unset\",$mode,$method\
,\"result.aln\",$outfile);\n    myexit ($EXIT_SUCC\
ESS);\n  }\nsub seq2pdbid_pair\n  {\n    my ($mode\
, $pdbfile1, $pdbfile2, $method, $param, $outfile)\
=@_;\n    my ($name);\n\n\n    &set_temporary_dir \
(\"set\");\n    $name=$pdbfile1.\" \".$pdbfile2;\n\
\n    if (    &cache_file(\"GET\",\"\",\"$name\",\\
"$method\",\"dali\",$outfile,\"EBI\"))\n      {ret\
urn $outfile;}\n    else\n      {\n	if ($method eq\
 \"daliweb\")\n	  {\n	    $pdbfile1=~/(....)(.)/;\\
n	    $id1=$1; $c1=$2;\n\n	    $pdbfile2=~/(....)(\
.)/;\n	    $id2=$1; $c2=$2;\n\n	    $command=\"t_c\
offee -other_pg dalilite.pl --pdb1 $id1 --chainid1\
 $c1 --pdb2 $id2 --chainid2 $c2 --email=$EMAIL  >d\
ali_stderr 2>dali_stderr\";\n	    $dali=`$command`\
;\n\n	    open (F, \"dali_stderr\");\n	    while (\
<F>)\n	      {\n		if ( /JobId: dalilite-(\\S+)/)\n\
		{\n		  $jobid=$1;\n		}\n	      }\n	    close (F)\
;\n	    unlink (\"dali_stderr\");\n\n	    $output1\
=\"dalilite-$jobid.txt\";\n	    if ( -e $output1)\\
n	      {\n		unlink ($output1);\n		&url2file (\"ht\
tp://www.ebi.ac.uk/Tools/es/cgi-bin/jobresults.cgi\
/dalilite/dalilite-$jobid/aln.html\", \"output2\")\
;\n\n		if ( -e \"output2\")\n		  {\n		    my ($seq\
1, $seq2);\n		    $seq1=$seq2=\"\";\n\n		    open \
(F, \"output2\");\n		    while (<F>)\n		      {\n	\
		$l=$_;\n			if ( $l=~/Query\\s+(\\S+)/)\n			  {\n\
			    $seq1.=$1;\n			  }\n			elsif ( $l=~/Sbjct\\\
s+(\\S+)/)\n			  {\n			    $seq2.=$1;\n			  }\n		 \
     }\n		    close (F);\n		    unlink (\"output2\\
");\n		    if ($seq1 ne \"\" && $seq2 ne \"\")\n		\
      {\n			$output3=\">$A\\n$seq1\\n>$B\\n$seq2\\\
n\";\n			$output3=~s/\\./-/g;\n			open (F, \">resu\
lt.aln\");\n			print F \"$output3\";\n			close (F)\
;\n		      }\n		  }\n	      }\n	  }\n      }\n    \
&cache_file(\"SET\",\"\",\"$name\",\"$method\",\"d\
ali\",\"result.aln\",\"EBI\");\n    &set_temporary\
_dir (\"unset\",$mode, $method, \"result.aln\",$ou\
tfile);\n    myexit ($EXIT_SUCCESS);\n  }\nsub seq\
2pdb_pair\n  {\n    my ($mode, $pdbfile1, $pdbfile\
2, $method, $param, $outfile)=@_;\n\n    &set_temp\
orary_dir (\"set\",$pdbfile1,\"pdb1.pdb\",$pdbfile\
2,\"pdb2.pdb\");\n    if ($method eq \"t_coffee\")\
\n      {\n	&safe_system (\"t_coffee -in Ppdb1.pdb\
 Ppdb2.pdb -quiet -outfile=result.aln\");\n      }\
\n    elsif ( $method eq \"DaliLite\")\n      {\n	\
if ( &safe_system (\"DaliLite -pairwise pdb1.pdb p\
db2.pdb >tmp1\")==$EXIT_SUCCESS)\n	  {\n	     my (\
$seq1, $seq2);\n	     $seq1=$seq2=\"\";\n\n	     o\
pen (F, \"tmp1\");\n	     while (<F>)\n	       {\n\
		 $l=$_;\n		 if ( $l=~/Query\\s+(\\S+)/)\n		   {\\
n		     $seq1.=$1;\n		   }\n		 elsif ( $l=~/Sbjct\\
\s+(\\S+)/)\n		   {\n		     $seq2.=$1;\n		   }\n	 \
      }\n	     close (F);\n	     unlink (\"tmp1\")\
;\n	     if ($seq1 ne \"\" && $seq2 ne \"\")\n	   \
    {\n		 my $output3=\">$A\\n$seq1\\n>$B\\n$seq2\\
\n\";\n		 $output3=~s/\\./-/g;\n		 open (F, \">res\
ult.aln\");\n		 print F \"$output3\";\n		 close (F\
);\n	       }\n	   }\n	else\n	  {\n	    print \"ER\
ROR: DalLite failed to align the considered struct\
ures[tc_generic_method.pl]\\n\";\n	  }\n      }\n \
   elsif ( $method eq \"TMalign\")\n      {\n	if (\
 &safe_system (\"TMalign pdb1.pdb pdb2.pdb >tmp1\"\
)==$EXIT_SUCCESS)\n	  {\n	    `tail -4 tmp1 > tmp2\
`;\n\n	    open (F, \"tmp2\");\n	    while (<F>)\n\
	      {\n		unshift(@l, $_);\n	      }\n	    close\
 (F);\n	    open (F, \">result.aln\");\n	    $l[3]\
=~s/[^a-zA-Z0-9-]/\\-/g;\n	    $l[1]=~s/[^a-zA-Z0-\
9-]/\\-/g;\n	    print F \">$A\\n$l[3]\\n>$B\\n$l[\
1]\\n\";\n	    close (F);\n	  }\n	else\n	  {\n	   \
 print \"ERROR: TMalign failed to align the consid\
ered structures[tc_generic_method.pl]\\n\";\n	    \
`rm result.aln >/dev/null 2>/dev/null`;\n	  }\n   \
   }\n    elsif ( $method eq \"mustang\")\n      {\
\n	if ( &safe_system (\"mustang -i pdb1.pdb pdb2.p\
db -F fasta >/dev/null 2>/dev/null\")==$EXIT_SUCCE\
SS)\n	  {\n	    `mv results.afasta result.aln`;\n	\
  }\n	else\n	  {\n	    print \"ERROR: mustang fail\
ed to align the considered structures[tc_generic_m\
ethod.pl]\\n\";\n	    `rm result.aln >/dev/null 2>\
/dev/null`;\n	  }\n      }\n    else\n      {\n	if\
 ( &safe_system (\"$method -pdbfile1=pdb1.pep -pdb\
file2=pdb2.pdb -outfile=result.aln $param>x 2>x\")\
==$EXIT_SUCCESS)\n	  {\n	    `mv results.afasta re\
sult.aln`;\n	  }\n	else\n	  {\n	    print \"ERROR:\
 $method failed to align the considered structures\
[tc_generic_method.pl]\\n\";\n	    `rm result.aln \
>/dev/null 2>/dev/null`;\n	  }\n      }\n    &set_\
temporary_dir (\"unset\",$mode, $method, \"result.\
aln\",$outfile);\n    myexit ($EXIT_SUCCESS);\n  }\
\n\nsub seq2rnapdb_pair\n  {\n    my ($mode, $pdbf\
ile1, $pdbfile2, $method, $param, $outfile)=@_;\n \
   \n    if ($method eq \"runsara.py\")\n      {\n\
	my $path=$ENV{PATH};\n	\n	if ($ENV{X3DNA_4_SARA})\
{$ENV{PATH}=\"$ENV{X3DNA_4_SARA}:$path\";}\n	\n	op\
en(TMP,\"<$pdbfile1\");\n	my $count = 0;\n	my $lin\
e;\n	while (<TMP>)\n	  {\n	    $line = $_;\n	    i\
f ($count ==1)\n	      {\n		last;\n	      }\n	    \
$count += 1;\n	  }\n	\n	\n	$chain1 = substr($line,\
length($line)-3,1);\n	\n	close TMP;\n	open(TMP,\"<\
$pdbfile2\");\n	my $count = 0;\n	while (<TMP>)\n	 \
 {\n	    $line = $_;\n	    if ($count ==1)\n	     \
 {\n		last;\n	      }\n	    $count += 1;\n	  }\n	$\
chain2 = substr($line,length($line)-3,1);\n	close \
TMP;\n	\n	$tmp_file=&vtmpnam();\n	\n	safe_system(\\
"runsara.py $pdbfile1 $chain1 $pdbfile2 $chain2 -s\
 -o $tmp_file --limitation 5000 > /dev/null 2> /de\
v/null\");\n	if ($ENV{X3DNA_4_SARA}){$ENV{PATH}=$p\
ath;}\n	\n	open(TMP,\"<$tmp_file\") or die \"canno\
t open the sara tmp file:$!\\n\";\n	open(OUT,\">$o\
utfile\") or die \"cannot open the $outfile file:$\
!\\n\";\n	\n	my $switch = 0;\n	my $seqNum = 0;\n	f\
oreach my $line (<TMP>)\n	  {\n	    next unless ($\
line=~/SARAALI/);\n	    if ($line=~/>/)\n	      {\\
n		$switch =0;\n		print OUT \">seq$seqNum\\n\";\n	\
	$seqNum++;\n	      }\n	    if ($switch < 2){\n	  \
    $switch++;\n	      next;\n	    }\n	    \n	    \
if ($line =~/REMARK\\s+SARAALI\\s+([^\\*]+)\\*/)\n\
	      {\n		my $string = $1;\n		print OUT \"$strin\
g\\n\";\n	      }\n	  }\n	close TMP;\n	close OUT;\\
n	unlink($tmp_file);\n      }\n  }\nsub seq2profil\
e_pair\n  {\n    my ($mode, $profile1, $profile2, \
$method, $param, $outfile)=@_;\n    \n    \n    if\
 ($method eq \"clustalw\")\n      {\n	`clustalw -p\
rofile1=$profile1 -profile2=$profile2 -outfile=$ou\
tfile`;\n      }\n    elsif ( $method eq \"clustal\
o\")\n      {\n	\n	`clustalo --p1 $profile1 --p2 $\
profile2 -o $outfile --force`;\n      }\n    elsif\
 ( $method eq \"hhalign\")\n      {\n	hhalign ( $p\
rofile1,$profile2,$outfile,$param);\n      }\n    \
else\n      {\n	`$method -profile1=$profile1 -prof\
ile2=$profile2 -outfile=$outfile $param> /dev/null\
 2>/dev/null`;\n      }\n    myexit ($EXIT_SUCCESS\
);\n  }\n\nsub pg_is_installed\n  {\n    my @ml=@_\
;\n    my ($r, $p, $m);\n    my $supported=0;\n\n \
   my $p=shift (@ml);\n    if ($p=~/::/)\n      {\\
n	if (safe_system (\"perl -M$p -e 1\")==$EXIT_SUCC\
ESS){return 1;}\n	else {return 0;}\n      }\n    e\
lse\n      {\n	$r=`which $p 2>/dev/null`;\n	if ($r\
 eq \"\"){$r=0;}\n	else {$r=1;}\n\n	if ($r==0 && i\
s_blast_package ($p)){return pg_is_installed (\"le\
gacy_blast.pl\");}\n	else {return $r;}\n      }\n \
 }\n\nsub is_blast_package\n  {\n    my $p=shift;\\
n    if ( $p=~/blastp/){return 1;}\n    elsif ($p=\
~/blastall/){return 1;}\n    elsif ($p=~/blastn/){\
return 1;}\n    elsif ($p=~/blastx/){return 1;}\n \
   elsif ($p=~/formatdb/){return 1;}\n    else {re\
turn 0;}\n  }\n\nsub check_internet_connection\n  \
{\n    my $internet;\n    my $tmp;\n    &check_con\
figuration ( \"wget\");\n\n    $tmp=&vtmpnam ();\n\
\n    if     (&pg_is_installed    (\"wget\")){`wge\
t www.google.com -O$tmp >/dev/null 2>/dev/null`;}\\
n    elsif  (&pg_is_installed    (\"curl\")){`curl\
 www.google.com -o$tmp >/dev/null 2>/dev/null`;}\n\
\n    if ( !-e $tmp || -s $tmp < 10){$internet=0;}\
\n    else {$internet=1;}\n    if (-e $tmp){unlink\
 $tmp;}\n\n    return $internet;\n  }\nsub check_p\
g_is_installed\n  {\n    my @ml=@_;\n    my $r=&pg\
_is_installed (@ml);\n    if (!$r && $p=~/::/)\n  \
    {\n	print STDERR \"\\nYou Must Install the per\
l package $p on your system.\\nRUN:\\n\\tsudo perl\
 -MCPAN -e 'install $pg'\\n\";\n      }\n    elsif\
 (!$r)\n      {\n	myexit(flush_error(\"\\nProgram \
$p Supported but Not Installed on your system\"));\
\n      }\n    else\n      {\n	return 1;\n      }\\
n  }\nsub set_temporary_dir\n  {\n    my @list=@_;\
\n    my $dir_mode, $a, $mode, $method;\n\n    $di\
r_mode=shift (@list);\n\n\n    if ( $dir_mode eq \\
"set\")\n      {\n	$initial_dir=cwd();\n	if ( !$tm\
p_dir)\n	  {\n	    $rand=rand (100000);\n	    $tmp\
_dir=\"$TMPDIR/tmp4tcoffee_profile_pair_dir_$$\\_P\
_$rand\";\n	  }\n	if ( !-d $tmp_dir)\n	  {\n	    p\
ush (@TMPDIR_LIST, $tmp_dir);\n	    `mkdir $tmp_di\
r`;\n	  }\n\n	for ( $a=0; $a<=$#list; $a+=2)\n	   \
   {\n		if (-e $list[$a]){ `cp $list[$a] $tmp_dir/\
$list[$a+1]`;}\n	      }\n	chdir $tmp_dir;\n      \
}\n    elsif ( $dir_mode eq \"unset\")\n      {\n	\
$mode=shift (@list);\n	$method=shift (@list);\n\n	\
if (!-e $list[0])\n	  {\n	   myexit(flush_error(\"\
Program $method failed to produce $list[1]\" ));\n\
	    myexit ($EXIT_FAILURE);\n	  }\n	else\n	  {\n	\
    chdir $initial_dir;\n	    # `t_coffee -other_p\
g seq_reformat -in $tmp_dir/$list[0] -output fasta\
_aln -out $tmp_dir/result2.aln`;\n	    `cp $tmp_di\
r/$list[0] $tmp_dir/result2.aln`;\n	    if ( $list\
[1] eq \"stdout\")\n	      {\n		open (F, \"$tmp_di\
r/result2.aln\");\n		while (<F>){print $_;}close(F\
);\n	      }\n	    else\n	      {\n		`mv $tmp_dir/\
result2.aln $list[1]`;\n	      }\n	    shift (@lis\
t); shift (@list);\n	    foreach $f (@list)\n	    \
  {\n		if (-e (\"$tmp_dir/$f\")){`mv $tmp_dir/$f .\
`;}\n	      }\n	  }\n      }\n  }\n\n\n\n\nsub my_\
get_opt\n  {\n    my @list=@_;\n    my ($cl, $a, $\
argv, @argl);\n\n    \n    @argl=();\n    $cl=shif\
t @list;\n    for ( my $a=0; $a<=$#list; $a+=3)\n \
     {\n	my $option=$list[$a];\n	my $optional=$lis\
t[$a+1];\n	my $status=$list[$a+2];\n	my $argv=\"\"\
;\n	if ($cl=~/$option(\\S+)/){$argv=$1;}\n	@argl=(\
@argl,$argv);\n\n\n	#$optional:0=>optional\n	#$opt\
ional:1=>must be set\n	#$status: 0=>no requirement\
\n	#$status: 1=>must be an existing file\n	#$statu\
s: 2=>must be an installed package\n	\n\n	if ($opt\
ional==0){;}\n	elsif ( $optional==1 && $argv eq \"\
\")\n	  {\n	    myexit(flush_error( \"ERROR: Optio\
n $option must be set\"));\n	    myexit ($EXIT_FAI\
LURE);\n	  }\n	if ($status==0){;}\n	elsif ($status\
 ==1 && $argv ne \"\" && !-e $argv)\n	  {\n	    my\
exit(flush_error( \"File [$argv] must exist\"));\n\
	    myexit ($EXIT_FAILURE);\n	  }\n	elsif ( $stat\
us==2 && $argv ne \"\" && &check_pg_is_installed (\
$argv)==0)\n	  {\n	    myexit(flush_error( \" $arg\
v is not installed\"));\n	    myexit ($EXIT_FAILUR\
E);\n	  }\n      }\n    return @argl;\n    }\n\nsu\
b check_file\n  {\n    my ($file, $msg)=@_;\n\n   \
 if ( !-e $file)\n      {\n	myexit(flush_error(\"$\
msg\"));\n      }\n    }\nsub hhalign\n  {\n    my\
 ($aln1, $aln2, $outfile, $param)=@_;\n    my $hh=\
$ENV{\"HHALIGN_4_TCOFFEE\"};\n    \n    \n    if (\
$hh)\n      {\n	\n	#external_hhalign\n	# set via H\
HALIGN_4_TCOFFEE\n	#<pg> -profile1 <fasta_prf with\
 seq1 top> -profile2 <fasta profile with seq2 top>\
 -outfile < fasta alignmentof seq1 and 2 | tc_lib \
of seq 1 and 2>\n	\n	safe_system (\"$hh -method=al\
ign -profile1=$aln1 -profile2=$aln2 -outfile=$outf\
ile\");\n      }\n    else\n      {\n	&local_hhali\
gn ($aln1, $aln2, $outfile, $param);\n      }\n  }\
\n\n    \n    \nsub local_hhalign\n  {\n    my ($a\
ln1, $aln2, $outfile, $param)=@_;\n    my $h1, $h2\
;\n\n    $h{0}{index}=0;\n    $h{1}{index}=1;\n\n \
   $h{0}{aln}=$aln1;\n    $h{1}{aln}=$aln2;\n\n\n\\
n    %{$h{0}}=aln2psi_profile (%{$h{0}});\n    %{$\
h{1}}=aln2psi_profile (%{$h{1}});\n\n    $param=~s\
/#S/ /g;\n    $param=~s/#M/\\-/g;\n    $param=~s/#\
E/\\=/g;\n\n\n\n    $command=\"hhalign -i $h{0}{a3\
m} -t $h{1}{a3m} -tc $outfile.tmp -rank 1 -mapt 0 \
$param\";\n    `$command`;\n\n  #  `hhalign -i $h{\
0}{a3m} -t $h{1}{a3m} -tc $outfile.tmp -rank 1 -ma\
pt 0 -gapf 0.8 -gapg 0.8`;\n\n\n    # To run globa\
l use the following\n\n    open (I, \"$outfile.tmp\
\");\n    open (O, \">$outfile\");\n    $h{0}{cons\
}=s/\\./x/g;\n    $h{1}{cons}=s/\\./x/g;\n\n    pr\
int O \"! TC_LIB_FORMAT_01\\n2\\n$h{0}{name} $h{0}\
{len} $h{0}{seq}\\n$h{1}{name} $h{1}{len} $h{1}{se\
q}\\n#1 2\\n\";\n\n    while (<I>)\n      {\n	if (\
/(\\d+)\\s+(\\d+)\\s+(\\d+)/)\n	  {\n	    print O \
\"\\t$h{0}{$1}\\t$h{1}{$2}\\t$3\\n\";\n	  }\n     \
 }\n    print O \"! SEQ_1_TO_N\\n\";\n\n    close \
(O);\n    close (I);\n  }\n\nsub aln2psi_profile\n\
  {\n    my (%h)=@_;\n    my ($aln,$i,$hv, $a, @c,\
 $n);\n\n\n    $i=$h{index};\n    $aln=$h{aln};\n\\
n    `cp $aln $$.hhh_aln`;\n    $command=\"t_coffe\
e -other_pg seq_reformat -in $aln -output hasch\";\
\n    $hv=`$command`;chomp ($hv);\n\n    $h{a2m}=\\
"$tmp/$hv.tmp4hhpred.a2m\";\n    $h{a3m}=\"$tmp/$h\
v.tmp4hhpred.a3m\";\n    if ( -e $h{a3m}){;}\n    \
else\n      {\n	$x=`which hhconsensus`;\n	`hhconse\
nsus  -M 50 -i $h{aln} -oa2m $h{a2m}`;\n	if (!-e $\
h{a2m})\n	  {\n	    print STDERR \"Program tc_gene\
ric_method.pl FAILED to run:\\n\\thhconsensus  -M \
50 -i $h{aln} -oa2m $h{a2m}\";\n	    myexit ($EXIT\
_FAILURE);\n	  }\n\n	`hhconsensus  -M 50 -i $h{aln\
} -oa3m $h{a3m}`;\n	if (!-e $h{a3m})\n	  {\n	    p\
rint STDERR \"Program tc_generic_method.pl FAILED \
to run:\\n\\thhconsensus  -M 50 -i $h{aln} -oa3m $\
h{a3m}\";\n	    myexit ($EXIT_FAILURE);\n	  }\n   \
    `buildali.pl $h{a3m} -n 1`;\n      }\n\n\n    \
$h{a2m_seq}=`head -n 2 $h{a2m} | grep -v \">\"`;ch\
omp ($h{a2m_seq});\n    $h{a3m_seq}=`head -n 2 $h{\
a3m} | grep -v \">\"`;chomp ($h{a3m_seq});\n    $h\
{cons}=$h{a2m_seq};\n    $h{seq}=`head -n 2 $h{aln\
} | grep -v \">\"`;chomp ($h{seq});\n\n\n\n    @c=\
split (//, $h{cons});\n    $h{len}=$#c+1;\n    for\
 ($n=0,$a=0, $b=0; $a<$h{len};$a++)\n      {\n	if \
( $c[$a]=~/[A-Z]/)\n	  {\n	    $h{++$n}=++$b;\n\n	\
  }\n	elsif ( $c[$a]=~/[a-z\\.]/)\n	  {\n	    ++$b\
;\n	  }\n      }\n\n    $name=`head -n 2 $h{aln} |\
 grep \">\"`;\n    $name=~/\\>(\\S+)/;\n    $h{nam\
e}=$1;\n\n    `cp $h{a2m} $i.a2m`;\n    `cp $h{a3m\
} $i.a3m`;\n    `cp $h{aln} $i.hh_aln`;\n\n    ret\
urn %h;\n  }\nsub read_fasta_seq_index\n  {\n    m\
y $f=@_[0];\n    my %hseq;\n    my (@seq, @com, @n\
ame);\n    my ($a, $s,$nseq);\n\n    open (F, $f);\
\n    while (<F>)\n      {\n	$s.=$_;\n      }\n   \
 close (F);\n\n\n    @name=($s=~/>(\\S*).*\\n[^>]*\
/g);\n\n    @seq =($s=~/>.*.*\\n([^>]*)/g);\n    @\
com =($s=~/>\\S*(.*)\\n([^>]*)/g);\n\n\n    $nseq=\
$#name+1;\n\n    for ($a=0; $a<$nseq; $a++)\n     \
 {\n	my $s;\n	my $n=$name[$a];\n	$hseq{$a}{name}=$\
n;\n	$seq[$a]=~s/[^A-Za-z]//g;\n	$hseq{$a}{order}=\
$a;\n	$hseq{$a}{seq}=$seq[$a];\n	$hseq{$a}{com}=$c\
om[$a];\n\n      }\n    return %hseq;\n  }\nsub re\
ad_fasta_seq\n  {\n    my $f=@_[0];\n    my %hseq;\
\n    my (@seq, @com, @name);\n    my ($a, $s,$nse\
q);\n\n    open (F, $f);\n    while (<F>)\n      {\
\n	$s.=$_;\n      }\n    close (F);\n\n\n    @name\
=($s=~/>(\\S*).*\\n[^>]*/g);\n\n    @seq =($s=~/>.\
*.*\\n([^>]*)/g);\n    @com =($s=~/>\\S*(.*)\\n([^\
>]*)/g);\n\n\n    $nseq=$#name+1;\n\n    for ($a=0\
; $a<$nseq; $a++)\n      {\n	my $s;\n	my $n=$name[\
$a];\n	$hseq{$n}{name}=$n;\n	$seq[$a]=~s/[^A-Za-z]\
//g;\n	$hseq{$n}{order}=$a;\n	$hseq{$n}{seq}=$seq[\
$a];\n	$hseq{$n}{com}=$com[$a];\n\n      }\n    re\
turn %hseq;\n  }\n\n\nsub read_fasta_aln\n  {\n   \
 my $f=@_[0];\n    my %hseq;\n    my (@seq, @com, \
@name);\n    my ($a, $s,$nseq);\n\n    open (F, $f\
);\n    while (<F>)\n      {\n	$s.=$_;\n      }\n \
   close (F);\n\n\n    @name=($s=~/>(\\S*).*\\n[^>\
]*/g);\n\n    @seq =($s=~/>.*.*\\n([^>]*)/g);\n   \
 @com =($s=~/>\\S*(.*)\\n([^>]*)/g);\n\n\n    $nse\
q=$#name+1;\n\n    for ($a=0; $a<$nseq; $a++)\n   \
   {\n	my $s;\n	my $n=$name[$a];\n	$hseq{$n}{name}\
=$n;\n	$seq[$a]=~s/[^A-Za-z-.()[\\]]//g;\n	$hseq{$\
n}{order}=$a;\n	$hseq{$n}{seq}=$seq[$a];\n	$hseq{$\
n}{com}=$com[$a];\n\n      }\n    return %hseq;\n \
 }\n\nsub recode_name2\n{\n	my ($in)=shift;\n	my $\
mode=shift;\n\n	my %seq;\n	my $new_name;\n\n	if (!\
 -e $in){return;}\n\n	#needed by ClustalOmega to a\
void very long names\n	open (INFILE, \"+<$in\");\n\
\n	my $line;\n\n	if ($mode eq \"code\")\n	{\n		cho\
mp($line = <INFILE>);\n		my $line_length = length(\
$line);\n		$new_name=++$RECODE_N;\n		$new_name=\">\
$new_name\";\n		my $new_length = length($new_name)\
;\n		$RECODE {$new_name}=$line;\n		for ($count = $\
new_length; $count < $line_length; $count++)\n		{\\
n			$new_name .= \" \";\n		}\n		$new_name=\"$new_n\
ame\\n\";\n		seek INFILE, 0, 0\n			or die \"could \
not seek: $!\";\n		print INFILE \"$new_name\";\n	}\
\n	else\n	{\n		my $n_found = 0;\n		my $file_pos=0;\
\n		$file_pos=tell INFILE;\n		while (<INFILE>)\n		\
{\n			$line=$_;\n			$line =~ s/\\s*$//;\n\n			$old\
_name= $RECODE{$line};\n			if ($old_name ne \"\")\\
n			{\n				seek INFILE, $file_pos, 0\n					or die \
\"could not seek: $!\";\n				print INFILE \"$old_n\
ame\\n\";\n				$file_pos++;\n				if ($file_pos == \
2)\n				{\n					print \"stop\\n\";\n					break;\n	\
			}\n			}\n			$file_pos=tell INFILE;\n		}\n\n	}\n\
\n\n	close INFILE;\n}\n\n\nsub recode_name\n{\n	my\
 ($in)=shift;\n	my $mode=shift;\n	my $f=new FileHa\
ndle;\n	my %seq;\n	my $new_name;\n\n	if (! -e $in)\
{return;}\n\n	#needed by ClustalOmega to avoid ver\
y long names\n	%seq=read_fasta_aln ($in);\n\n	open\
 ($f, \">$in\");\n	foreach my $s (keys(%seq))\n	{\\
n		if ($mode eq \"code\")\n		{\n			$new_name=++$RE\
CODE_N;\n			$RECODE {$new_name}=$seq{$s}{name};\n	\
	}\n		else\n		{\n			$new_name=$RECODE{$seq{$s}{nam\
e}};\n		}\n		print $f \">$new_name\\n$seq{$s}{seq}\
\\n\";\n	}\n	close $f;\n}\n\nsub fasta_hash2index_\
hash\n  {\n    my %s1=@_;\n    my %s;\n    foreach\
 my $s (keys (%s1))\n      {\n	my $i=$s1{$s}{order\
};\n	$s{$i}{name}=$s;\n	$s{$i}{seq}=$s1{$s}{seq};\\
n	$s{$i}{len}=length( $s{$i}{seq});\n	$s{n}++;\n  \
    }\n    return %s;\n  }\nsub file_contains\n  {\
\n    my ($file, $tag, $max)=(@_);\n    my ($n);\n\
    $n=0;\n\n    if ( !-e $file && ($file =~/$tag/\
)) {return 1;}\n    elsif ( !-e $file){return 0;}\\
n    else\n      {\n	open (FC, \"$file\");\n	while\
 ( <FC>)\n	  {\n	    if ( ($_=~/$tag/))\n	      {\\
n		close (FC);\n		return 1;\n	      }\n	    elsif \
($max && $n>$max)\n	      {\n		close (FC);\n		retu\
rn 0;\n	      }\n	    $n++;\n	  }\n      }\n    cl\
ose (FC);\n    return 0;\n  }\n\n\nsub file2string\
\n  {\n    my $f=@_[0];\n    my $string, $l;\n    \
open (F,\"$f\");\n    while (<F>)\n      {\n\n	$l=\
$_;\n	#chomp ($l);\n	$string.=$l;\n      }\n    cl\
ose (F);\n    $string=~s/\\r\\n//g;\n    $string=~\
s/\\n//g;\n    return $string;\n  }\n\n\nsub tag2v\
alue\n  {\n\n    my $tag=(@_[0]);\n    my $word=(@\
_[1]);\n    my $return;\n\n    $tag=~/$word=\"([^\\
"]+)\"/;\n    $return=$1;\n    return $return;\n  \
}\n\nsub hit_tag2pdbid\n  {\n    my $tag=(@_[0]);\\
n    my $pdbid;\n\n    $tag=~/id=\"(\\S+)\"/;\n   \
 $pdbid=$1;\n    $pdbid=~s/_//;\n    return $pdbid\
;\n  }\nsub id2pdbid\n  {\n    my $in=@_[0];\n    \
my $id;\n\n    $in=~/(\\S+)/;\n    $id=$in;\n    $\
id=~s/PDB/pdb/g;\n\n    if ($id =~/pdb(.*)/){$id=$\
1;}\n    elsif ( $id=~/(\\S+)\\s+mol:protein/){$id\
=$1;}\n    $id=~s/[:|��_]//g;\n    return $id;\
\n  }\nsub set_blast_type\n  {\n    my $file =@_[0\
];\n    if (&file_contains ($file,\"EBIApplication\
Result\",100)){$BLAST_TYPE=\"EBI\";}\n    elsif (&\
file_contains ($file,\"NCBI_BlastOutput\",100)) {$\
BLAST_TYPE=\"NCBI\";}\n    else\n      {\n	$BLAST_\
TYPE=\"\";\n      }\n    return $BLAST_TYPE;\n  }\\
nsub is_valid_blast_xml\n    {\n      my $file=shi\
ft;\n      my $line;\n\n\n      if ( !-e $file) {r\
eturn 0;}\n      $line=&file2tail ($file,100);\n\n\
      if ( $line=~/<\\/EBIApplicationResult/ || $l\
ine=~/<\\/NCBI_BlastOutput/ || $line=~/<\\/BlastOu\
tput/ ){return 1;}\n      return 0;\n    }\nsub fi\
le2blast_flavor\n      {\n	my $file=shift;\n	if (&\
file_contains ($file,\"EBIApplicationResult\",100)\
){return \"EBI\";}\n	elsif (&file_contains ($file,\
\"NCBI_BlastOutput\",100)){return \"NCBI\";}\n	els\
e {return \"UNKNOWN\";}\n      }\nsub blast_xml2pr\
ofile\n  {\n    my ($name,$seq,$maxid, $minid, $mi\
ncov, $file)=(@_);\n    my (%p, $a, $string, $n);\\
n\n\n\n    if ($BLAST_TYPE eq \"EBI\" || &file_con\
tains ($file,\"EBIApplicationResult\",100)){%p=ebi\
_blast_xml2profile(@_);}\n    elsif ($BLAST_TYPE e\
q \"NCBI\" || &file_contains ($file,\"NCBI_BlastOu\
tput\",100)){%p=ncbi_blast_xml2profile(@_);}\n    \
else\n      {\n	myexit(add_error ( $$,$$,getppid()\
, \"BLAST_FAILURE::unkown XML\",$CL));\n      }\n \
   for ($a=0; $a<$p{n}; $a++)\n      {\n	my $name=\
$p{$a}{name};\n	$p{$name}{seq}=$p{$a}{seq};\n	$p{$\
name}{index}=$a;\n      }\n    return %p;\n  }\nsu\
b ncbi_tblastx_xml2lib_file\n  {\n    my  ($outlib\
,$string)=(@_);\n    my ($L,$l, $a,$b,$c,$d,$i,$nh\
its,@identifyerL);\n    my (%ITERATION);\n\n    op\
en (F, \">>$outlib\");\n\n    $seq=~s/[^a-zA-Z]//g\
;\n    $L=length ($seq);\n\n    %ITERATION=xml2tag\
_list ($string, \"Iteration\");\n    for ($i=0; $i\
<$ITERATION{n};$i++)\n      {\n	my ($qindex, $qlen\
, %hit, $string);\n	$string=$ITERATION{$i}{body};\\
n\n	$qindex=xmltag2value($string,\"Iteration_iter-\
num\");\n	$qlen  =xmltag2value($string,\"Iteration\
_query-len\");\n	%hit=&xml2tag_list  ($string, \"H\
it\");\n\n	for ($a=0; $a<$hit{n}; $a++)\n	  {\n	  \
  my ($string);\n	    $string=$hit{$a}{body};\n\n	\
    $hindex=xmltag2value($string,\"Hit_accession\"\
)+1;\n	    if ($hindex<=$qindex){next;}\n	    else\
  {print F  \"# $qindex $hindex\\n\";}\n\n\n	    $\
hlen=xmltag2value  ($string,\"Hit_len\");\n	    %H\
SP=&xml2tag_list  ($string, \"Hsp\");\n\n	    for \
($b=0; $b<$HSP{n}; $b++)\n	      {\n		my ($string,\
 $qs,$qe,$qf,$hs,$he,$hf,$s, $d, $e);\n		$string=$\
HSP{$b}{body};\n\n		$qs=xmltag2value  ($string,\"H\
sp_query-from\");\n		$qe=xmltag2value  ($string,\"\
Hsp_query-to\");\n		$qf=xmltag2value  ($string,\"H\
sp_query-frame\");\n\n		$hs=xmltag2value  ($string\
,\"Hsp_hit-from\");\n		$he=xmltag2value  ($string,\
\"Hsp_hit-to\");\n		$hf=xmltag2value  ($string,\"H\
sp_hit-frame\");\n\n		$s=xmltag2value  ($string,\"\
Hsp_identity\");\n		$l=xmltag2value  ($string,\"Hs\
p_align-len\");\n		$s=int(($s*100)/$l);\n\n		if ($\
qf>0)\n		  {$rqs=$qs; $rqe=$qe;}\n		else\n		  {\n	\
	    $rqe=($qlen-$qs)+1;\n		    $rqs=($qlen-$qe)+1\
;\n		  }\n\n		if ($hf>0)\n		  {$rhs=$hs; $rhe=$he;\
}\n		else\n		  {\n		    $rhe=($hlen-$hs)+1;\n		   \
 $rhs=($hlen-$he)+1;\n		  }\n		for ($d=0,$e=$rqs; \
$e<$rqe; $e++,$d++)\n		  {\n		    my ($r1,$r2);\n	\
	    $r1=$e;\n		    $r2=$rhs+$d;\n		    print F \"\
 $r1 $r2 $s 0\\n\";\n		  }\n	      }\n	  }\n      \
}\n    print F \"! SEQ_1_TO_N\\n\";\n\n    close (\
F);\n    return %lib;\n  }\n\nsub ncbi_tblastpx_xm\
l2lib_file\n  {\n    my  ($outlib,$string,%s)=(@_)\
;\n    my ($L,$l, $a,$b,$c,$d,$i,$nhits,@identifye\
rL);\n    my (%ITERATION,%hdes, %qdes);\n\n    ope\
n (F, \">>$outlib\");\n\n    $seq=~s/[^a-zA-Z]//g;\
\n    $L=length ($seq);\n\n    %ITERATION=xml2tag_\
list ($string, \"Iteration\");\n    for ($i=0; $i<\
$ITERATION{n};$i++)\n      {\n	my ($qindex, $qlen,\
 %hit, $string);\n	$string=$ITERATION{$i}{body};\n\
\n	$qdef=xmltag2value($string,\"Iteration_query-de\
f\");\n	%qdes=&tblastpx_name2description($qdef,%s)\
;\n	$qlen  =xmltag2value($string,\"Iteration_query\
-len\");\n	%hit=&xml2tag_list  ($string, \"Hit\");\
\n\n	for ($a=0; $a<$hit{n}; $a++)\n	  {\n	    my (\
$string);\n	    $string=$hit{$a}{body};\n	    $hde\
f=xmltag2value($string,\"Hit_def\");\n	    %hdes=&\
tblastpx_name2description($hdef,%s);\n	    if ($hd\
es{index}<=$qdes{index}){next;}\n	    else  {print\
 F  \"# $qdes{index} $hdes{index}\\n\";}\n\n\n	   \
 $hlen=xmltag2value  ($string,\"Hit_len\");\n	    \
%HSP=&xml2tag_list  ($string, \"Hsp\");\n\n	    fo\
r ($b=0; $b<$HSP{n}; $b++)\n	      {\n		my ($strin\
g, $l,$qs,$qe,$qf,$hs,$he,$hf,$s, $d, $e, @s1, @s2\
);\n		$string=$HSP{$b}{body};\n\n		$qs=xmltag2valu\
e  ($string,\"Hsp_query-from\");\n		$qe=xmltag2val\
ue  ($string,\"Hsp_query-to\");\n		$qf=$qdes{frame\
};\n		$qseq=xmltag2value  ($string,\"Hsp_qseq\");\\
n\n		$hs=xmltag2value  ($string,\"Hsp_hit-from\");\
\n		$he=xmltag2value  ($string,\"Hsp_hit-to\");\n	\
	$hf=$hdes{frame};\n		$hseq=xmltag2value  ($string\
,\"Hsp_hseq\");\n\n		$s=xmltag2value  ($string,\"H\
sp_identity\");\n		$l=xmltag2value  ($string,\"Hsp\
_align-len\");\n		$s=int(($s*100)/$l);\n		@s1=tbla\
stpx_hsp2coordinates($qseq,$qs,$qe,%qdes);\n		@s2=\
tblastpx_hsp2coordinates($hseq,$hs,$he,%hdes);\n\n\
\n		for ($f=0; $f<=$#s1; $f++)\n		  {\n		    if ($\
s1[$f]==-1 || $s2[$f]==-1){next;}\n		    else\n		 \
     {\n			print F \" $s1[$f] $s2[$f] $s 0\\n\";\n\
		      }\n		  }\n	      }\n	  }\n      }\n    pri\
nt F \"! SEQ_1_TO_N\\n\";\n\n    close (F);\n    r\
eturn %lib;\n  }\nsub tblastpx_hsp2coordinates\n  \
{\n    my ($seq, $s, $e, %des)=@_;\n    my @list;\\
n    my @sa;\n    my @gap=(-1,-1,-1);\n\n    $s=$d\
es{start}+3*($s-1);\n\n    if ($des{strand} eq \"d\
\"){;}\n    else {$s=($des{length}-$s)+1;}\n\n    \
foreach $c (split (//,$seq))\n      {\n	if ( $c eq\
 '-'){push (@list,@gap);}\n	elsif ($des{strand} eq\
 \"d\")\n	  {\n	    push(@list,$s++,$s++,$s++);\n	\
  }\n	else\n	  {\n	    push(@list, $s--,$s--,$s--)\
;\n	  }\n      }\n    return @list;\n  }\n\nsub tb\
lastpx_name2description\n  {\n    my ($name, %s)=@\
_;\n    my @at=split(\"__\", $name);\n    my %des;\
\n\n    $des{name}=$at[0];\n    $des{strand}=$at[1\
];\n\n    $des{start}=$at[2];\n    $des{end}=$at[3\
];\n    $des{length}=$at[4];\n    $des{index}=$s{$\
at[0]}{order}+1;\n    return %des;\n  }\nsub ncbi_\
blast_xml2profile\n  {\n    my ($name,$seq,$maxid,\
 $minid, $mincov, $string)=(@_);\n    my ($L,$l, $\
a,$b,$c,$d,$nhits,@identifyerL);\n\n\n    $seq=~s/\
[^a-zA-Z]//g;\n    $L=length ($seq);\n\n    #This \
is causing the NCBI parser to fail when Iteration_\
query-def is missing\n    #%query=&xml2tag_list ($\
string, \"Iteration_query-def\");\n    #$name=$que\
ry{0}{body};\n\n    %hit=&xml2tag_list ($string, \\
"Hit\");\n\n\n    for ($nhits=0,$a=0; $a<$hit{n}; \
$a++)\n      {\n	my ($ldb,$id, $identity, $expecta\
tion, $start, $end, $coverage, $r);\n	my (%ID,%DE,\
%HSP);\n\n	$ldb=\"\";\n\n	%ID=&xml2tag_list ($hit{\
$a}{body}, \"Hit_id\");\n	$identifyer=$ID{0}{body}\
;\n\n	%DE=&xml2tag_list ($hit{$a}{body}, \"Hit_def\
\");\n	$definition=$DE{0}{body};\n\n	%HSP=&xml2tag\
_list ($hit{$a}{body}, \"Hsp\");\n	for ($b=0; $b<$\
HSP{n}; $b++)\n	  {\n	    my (%START,%END,%E,%I,%Q\
,%M);\n\n\n	    %START=&xml2tag_list ($HSP{$b}{bod\
y}, \"Hsp_query-from\");\n	    %HSTART=&xml2tag_li\
st ($HSP{$b}{body}, \"Hsp_hit-from\");\n\n	    %LE\
N=  &xml2tag_list ($HSP{$b}{body}, \"Hsp_align-len\
\");\n	    %END=  &xml2tag_list ($HSP{$b}{body}, \\
"Hsp_query-to\");\n	    %HEND=  &xml2tag_list ($HS\
P{$b}{body}, \"Hsp_hit-to\");\n	    %E=&xml2tag_li\
st     ($HSP{$b}{body}, \"Hsp_evalue\");\n	    %I=\
&xml2tag_list     ($HSP{$b}{body}, \"Hsp_identity\\
");\n	    %Q=&xml2tag_list     ($HSP{$b}{body}, \"\
Hsp_qseq\");\n	    %M=&xml2tag_list     ($HSP{$b}{\
body}, \"Hsp_hseq\");\n\n	    for ($e=0; $e<$Q{n};\
 $e++)\n\n	      {\n		$qs=$Q{$e}{body};\n		$ms=$M{\
$e}{body};\n\n		$expectation=$E{$e}{body};\n		$ide\
ntity=($LEN{$e}{body}==0)?0:$I{$e}{body}/$LEN{$e}{\
body}*100;\n		$start=$START{$e}{body};\n		$end=$EN\
D{$e}{body};\n		$Hstart=$HSTART{$e}{body};\n		$Hen\
d=$HEND{$e}{body};\n\n		$coverage=($L)?(($end-$sta\
rt)*100)/$L:0;\n\n		if ($identity>$maxid || $ident\
ity<$minid || $coverage<$mincov){next;}\n		@lr1=(s\
plit (//,$qs));\n		@lr2=(split (//,$ms));\n		$l=$#\
lr1+1;\n		for ($c=0;$c<$L;$c++){$p[$nhits][$c]=\"-\
\";}\n		for ($d=0,$c=0; $c<$l; $c++)\n		  {\n		   \
 $r=$lr1[$c];\n		    if ( $r=~/[A-Za-z]/)\n		     \
 {\n\n			$p[$nhits][$d + $start-1]=$lr2[$c];\n			$\
d++;\n		      }\n		  }\n		$Qseq[$nhits]=$qs;\n		$H\
seq[$nhits]=$ms;\n		$QstartL[$nhits]=$start;\n		$H\
startL[$nhits]=$Hstart;\n		$identityL[$nhits]=$ide\
ntity;\n		$endL[$nhits]=$end;\n		$definitionL[$nhi\
ts]=$definition;\n		$identifyerL[$nhits]=$identify\
er;\n		$comment[$nhits]=\"$ldb|$identifyer [Eval=$\
expectation][id=$identity%][start=$Hstart end=$Hen\
d]\";\n		$nhits++;\n	      }\n	  }\n      }\n\n\n \
   $profile{n}=0;\n    $profile{$profile{n}}{name}\
=$name;\n    $profile{$profile{n}}{seq}=$seq;\n   \
 $profile {n}++;\n\n    for ($a=0; $a<$nhits; $a++\
)\n      {\n	$n=$a+1;\n\n	$profile{$n}{name}=\"$na\
me\\_$a\";\n	$profile{$n}{seq}=\"\";\n	$profile{$n\
}{Qseq}=$Qseq[$a];\n	$profile{$n}{Hseq}=$Hseq[$a];\
\n	$profile{$n}{Qstart}=$QstartL[$a];\n	$profile{$\
n}{Hstart}=$HstartL[$a];\n	$profile{$n}{identity}=\
$identityL[$a];\n	$profile{$n}{definition}=$defini\
tionL[$a];\n	$profile{$n}{identifyer}=$identifyerL\
[$a];\n	$profile{$n}{comment}=$comment[$a];\n\n	fo\
r ($b=0; $b<$L; $b++)\n	  {\n	    if ($p[$a][$b])\\
n	      {\n		$profile{$n}{seq}.=$p[$a][$b];\n	    \
  }\n	    else\n	      {\n		$profile{$n}{seq}.=\"-\
\";\n	      }\n	  }\n      }\n\n    $profile{n}=$n\
hits+1;\n    return %profile;\n  }\nsub ebi_blast_\
xml2profile\n  {\n    my ($name,$seq,$maxid, $mini\
d, $mincov, $string)=(@_);\n    my ($L,$l, $a,$b,$\
c,$d,$nhits,@identifyerL,$identifyer);\n\n\n\n    \
$seq=~s/[^a-zA-Z]//g;\n    $L=length ($seq);\n    \
%hit=&xml2tag_list ($string, \"hit\");\n\n    for \
($nhits=0,$a=0; $a<$hit{n}; $a++)\n      {\n	my ($\
ldb,$id, $identity, $expectation, $start, $end, $c\
overage, $r);\n	my (%Q,%M,%E,%I);\n\n	$ldb=&tag2va\
lue ($hit{$a}{open}, \"database\");\n	$identifyer=\
&tag2value ($hit{$a}{open}, \"id\");\n\n	$descript\
ion=&tag2value ($hit{$a}{open}, \"description\");\\
n\n	%Q=&xml2tag_list ($hit{$a}{body}, \"querySeq\"\
);\n	%M=&xml2tag_list ($hit{$a}{body}, \"matchSeq\\
");\n	%E=&xml2tag_list ($hit{$a}{body}, \"expectat\
ion\");\n	%I=&xml2tag_list ($hit{$a}{body}, \"iden\
tity\");\n\n\n	for ($b=0; $b<$Q{n}; $b++)\n	  {\n\\
n	    $qs=$Q{$b}{body};\n	    $ms=$M{$b}{body};\n\\
n	    $expectation=$E{$b}{body};\n	    $identity=$\
I{$b}{body};\n\n\n	    $start=&tag2value ($Q{$b}{o\
pen}, \"start\");\n	    $end=&tag2value ($Q{$b}{op\
en}, \"end\");\n	    $startM=&tag2value ($M{$b}{op\
en}, \"start\");\n	    $endM=&tag2value ($M{$b}{op\
en}, \"end\");\n	    $coverage=(($end-$start)*100)\
/$L;\n\n	   # print \"$id: ID: $identity COV: $cov\
erage [$start $end]\\n\";\n\n	    if ($identity>$m\
axid || $identity<$minid || $coverage<$mincov){nex\
t;}\n	    # print \"KEEP\\n\";\n\n\n	    @lr1=(spl\
it (//,$qs));\n	    @lr2=(split (//,$ms));\n	    $\
l=$#lr1+1;\n	    for ($c=0;$c<$L;$c++){$p[$nhits][\
$c]=\"-\";}\n	    for ($d=0,$c=0; $c<$l; $c++)\n	 \
     {\n		$r=$lr1[$c];\n		if ( $r=~/[A-Za-z]/)\n		\
  {\n\n		    $p[$nhits][$d + $start-1]=$lr2[$c];\n\
		    $d++;\n		  }\n	      }\n\n	    $Qseq[$nhits]\
=$qs;\n	    $Hseq[$nhits]=$ms;\n	    $QstartL[$nhi\
ts]=$start;\n	    $HstartL[$nhits]=$Hstart;\n	    \
$identityL[$nhits]=$identity;\n	    $endL[$nhits]=\
$end;\n	    $definitionL[$nhits]=$definition;\n	  \
  $identifyerL[$nhits]=$identifyer;\n	    $comment\
[$nhits]=\"$ldb|$identifyer [Eval=$expectation][id\
=$identity%][start=$startM end=$endM]\";\n	    $nh\
its++;\n	  }\n      }\n\n    $profile{n}=0;\n    $\
profile{$profile{n}}{name}=$name;\n    $profile{$p\
rofile{n}}{seq}=$seq;\n    $profile {n}++;\n\n    \
for ($a=0; $a<$nhits; $a++)\n      {\n	$n=$a+1;\n	\
$profile{$n}{name}=\"$name\\_$a\";\n	$profile{$n}{\
seq}=\"\";\n	$profile{$n}{Qseq}=$Qseq[$a];\n	$prof\
ile{$n}{Hseq}=$Hseq[$a];\n	$profile{$n}{Qstart}=$Q\
startL[$a];\n	$profile{$n}{Hstart}=$HstartL[$a];\n\
	$profile{$n}{identity}=$identityL[$a];\n	$profile\
{$n}{definition}=$definitionL[$a];\n	$profile{$n}{\
identifyer}=$identifyerL[$a];\n	$profile{$n}{comme\
nt}=$comment[$a];\n\n	for ($b=0; $b<$L; $b++)\n	  \
{\n	    if ($p[$a][$b])\n	      {\n		$profile{$n}{\
seq}.=$p[$a][$b];\n	      }\n	    else\n	      {\n\
		$profile{$n}{seq}.=\"-\";\n	      }\n	  }\n     \
 }\n    $profile{n}=$nhits+1;\n\n    return %profi\
le;\n  }\nsub output_profile\n  {\n    my ($outfil\
e,$profileR, $trim)=(@_);\n    my ($a);\n    my %p\
rofile=%$profileR;\n    my $P= new FileHandle;\n  \
  my $tmp=vtmpnam();\n\n    open ($P, \">$tmp\");\\
n    for ($a=0; $a<$profile{n}; $a++)\n      {\n	p\
rint $P \">$profile{$a}{name} $profile{$a}{comment\
}\\n$profile{$a}{seq}\\n\";\n      }\n    close ($\
P);\n\n    if ( $trim)\n      {\n	\n	if ($trim>0)\\
n	  {\n	    &safe_system (\"t_coffee -other_pg seq\
_reformat -in $tmp -action +trim _aln_n$trim\\_K1 \
-output fasta_aln -out $outfile\");\n	  }\n	else\n\
	  {\n	    &safe_system (\"t_coffee -other_pg seq_\
reformat -in $tmp -action +trim _aln_%%$trim\\_K1 \
-output fasta_aln -out $outfile\");\n	  }\n      }\
\n    else\n      {\n	&safe_system (\"mv $tmp $out\
file\");\n      }\n    return;\n  }\nsub blast_xml\
2hit_list\n  {\n    my $string=(@_[0]);\n    retur\
n &xml2tag_list ($string, \"hit\");\n  }\nsub xmlt\
ag2value\n  {\n    my ($string_in, $tag)=@_;\n    \
my %TAG;\n    %TAG=xml2tag_list ($string_in, $tag)\
;\n    return $TAG{0}{body};\n  }\n\nsub xml2tag_l\
ist\n  {\n    my ($string_in,$tag)=@_;\n    my $ta\
g_in, $tag_out;\n    my %tag;\n\n    if (-e $strin\
g_in)\n      {\n	$string=&file2string ($string_in)\
;\n      }\n    else\n      {\n	$string=$string_in\
;\n      }\n    $tag_in1=\"<$tag \";\n    $tag_in2\
=\"<$tag>\";\n    $tag_out=\"/$tag>\";\n    $strin\
g=~s/>/>##1/g;\n    $string=~s/</##2</g;\n    $str\
ing=~s/##1/<#/g;\n    $string=~s/##2/#>/g;\n    @l\
=($string=~/(\\<[^>]+\\>)/g);\n    $tag{n}=0;\n   \
 $in=0;$n=-1;\n\n\n\n    foreach $t (@l)\n      {\\
n\n	$t=~s/<#//;\n	$t=~s/#>//;\n\n	if ( $t=~/$tag_i\
n1/ || $t=~/$tag_in2/)\n	  {\n\n	    $in=1;\n	    \
$tag{$tag{n}}{open}=$t;\n	    $n++;\n\n	  }\n	elsi\
f ($t=~/$tag_out/)\n	  {\n\n\n	    $tag{$tag{n}}{c\
lose}=$t;\n	    $tag{n}++;\n	    $in=0;\n	  }\n	el\
sif ($in)\n	  {\n\n	    $tag{$tag{n}}{body}.=$t;\n\
	  }\n      }\n\n    return %tag;\n  }\n\n\nsub se\
q2gor_prediction\n  {\n    my ($name, $seq,$infile\
, $outfile, $gor_seq, $gor_obs)=(@_);\n    my ($l)\
;\n\n    `gorIV -prd $infile -seq $gor_seq -obs $g\
or_obs > gor_tmp`;\n    open (GR, \">$outfile\");\\
n    open (OG, \"gor_tmp\");\n\n    while (<OG>)\n\
      {\n\n	$l=$_;\n	if ($l=~/\\>/){print GR \"$l\\
";}\n	elsif ( $l=~/Predicted Sec. Struct./)\n	  {\\
n	    $l=~s/Predicted Sec. Struct\\.//;\n	    prin\
t GR \"$l\";\n	  }\n      }\n    close (GR);\n    \
close (OG);\n    return;\n  }\nsub seq2msa_tm_pred\
iction\n  {\n    my ($name, $seq, $db, $infile, $o\
utfile, $arch, $psv)=(@_);\n    my (%p,%gseq,%R, $\
blast_output, %s, $l);\n    my $R2=new FileHandle;\
\n    my $method=\"psitm\";\n    my $SERVER=\"EBI\\
";\n\n    $blast_output=&run_blast ($name,\"blastp\
\", $db, $infile, \"outfile\");\n\n    if (&cache_\
file(\"GET\",$infile,$name,$method,$db,$outfile,$S\
ERVER))\n      {\n	print \"\\tPSITM: USE Cache\\n\\
";\n	return $outfile;\n      }\n    else\n      {\\
n	$CACHE_STATUS=\"COMPUTE CACHE\";\n	%p=blast_xml2\
profile($name,$seq,$maxid, $minid,$mincov,$blast_o\
utput);\n\n\n	open (F, \">tm_input\");\n	for (my $\
a=0; $a<$p{n}; $a++)\n	  {\n	    my $s;\n\n	    $s\
=$p{$a}{seq};\n	    $s=uc($s);\n	    print F \">$p\
{$a}{name}\\n$s\\n\";\n	    #print stdout \">$p{$a\
}{name}\\n$s\\n\";\n	  }\n	close (F);\n	print \"\\\
tPSITM: kept  $p{n} Homologues for Sequence $p{0}{\
name}\\n\";\n	&safe_system (\"t_coffee -other_pg f\
asta_seq2hmmtop_fasta.pl -in=tm_input -out=$outfil\
e -output=cons -cov=70 -trim=95 -arch=$arch -psv=$\
psv\");\n	unlink (\"tm_input\");\n	&cache_file(\"S\
ET\",$infile,$name,$method,$db,$outfile,$SERVER);\\
n	return;\n      }\n  }\n\n\nsub seq2msa_gor_predi\
ction\n  {\n    my ($name, $seq,$infile, $outfile,\
 $gor_seq, $gor_obs)=(@_);\n    my (%p,%gseq,%R, $\
blast_output, %s, $l);\n    my $R2=new FileHandle;\
\n    my $db=\"uniprot\";\n    my $method=\"psigor\
\";\n    my $SERVER=\"EBI\";\n\n    $blast_output=\
&run_blast ($name,\"blastp\", \"uniprot\", $infile\
, \"outfile\");\n\n    if (&cache_file(\"GET\",$in\
file,$name,$method,$db,$outfile,$SERVER))\n      {\
\n	print \"\\tPSIGOR: USE Cache\\n\";\n	return $ou\
tfile;\n      }\n    else\n      {\n	$CACHE_STATUS\
=\"COMPUTE CACHE\";\n	%p=blast_xml2profile($name,$\
seq,$maxid, $minid,$mincov,$blast_output);\n\n\n	o\
pen (F, \">gor_input\");\n	for (my $a=0; $a<$p{n};\
 $a++)\n	  {\n	    my $s;\n\n	    $s=$p{$a}{seq};\\
n	    $s=uc($s);\n	    print F \">$p{$a}{name}\\n$\
s\\n\";\n	    #print stdout \">$p{$a}{name}\\n$s\\\
n\";\n	  }\n	close (F);\n	print \"\\tGORTM: kept  \
$p{n} Homologues for Sequence $p{0}{name}\\n\";\n	\
&safe_system (\"t_coffee -other_pg fasta_seq2hmmto\
p_fasta.pl -in=gor_input -out=$outfile -output=con\
s -cov=70 -trim=95 -gor_seq=$gor_seq -gor_obs=$gor\
_obs -mode=gor\");\n	unlink (\"tm_input\");\n	&cac\
he_file(\"SET\",$infile,$name,$method,$db,$outfile\
,$SERVER);\n	return;\n      }\n  }\n\n\n\nsub run_\
blast\n  {\n    my ($name, $method, $db, $infile, \
$outfile, $run)=(@_);\n    if (!$run){$run=1;}\n  \
  my $error_log=vtmpnam();\n    my $cl_db;\n    \n\
    if (&cache_file(\"GET\",$infile,$name,$method,\
$db,$outfile,$SERVER) && is_valid_blast_xml ($outf\
ile))\n      {return $outfile;}\n    else\n      {\
\n	$CACHE_STATUS=\"COMPUTE CACHE\";\n	if ( $SERVER\
 eq \"EBI_SOAP\")\n	  {\n	    &check_configuration\
 (\"EMAIL\",\"SOAP::Light\",\"INTERNET\");\n\n	   \
 $cl_method=$method;\n	    if ($cl_method =~/wu/)\\
n	      {\n		$cl_method=~s/wu//;\n		if ( $cl_metho\
d eq \"psiblast\")\n		  {\n		    add_warning($$,$$\
,\"PSI BLAST cannot be used with the wuBLAST Clien\
t. Use server=EBI Or server=LOCAL. blastp will be \
used instead\");\n		    $cl_method=\"blastp\";\n		\
  }\n\n		$command=\"t_coffee -other_pg wublast.pl \
--email $EMAIL $infile -D $db -p $cl_method --outf\
ile $outfile -o xml>/dev/null 2>$error_log\";\n		&\
safe_system ( $command);\n		if (-e \"$outfile.xml\\
") {`mv $outfile.xml $outfile`;}\n	      }\n	    e\
lse\n	      {\n		if ($cl_method eq \"psiblast\"){$\
cl_method =\"blastp -j5\";}\n\n		$command=\"t_coff\
ee -other_pg blastpgp.pl --email $EMAIL $infile -d\
 $db --outfile $outfile -p $cl_method --mode PSI-B\
last>/dev/null 2>$error_log\";\n		&safe_system ( $\
command);\n\n		if (-e \"$outfile.xml\") {`mv $outf\
ile.xml $outfile`;}\n	      }\n	  }\n	elsif ($SERV\
ER eq \"EBI_REST\" || $SERVER eq \"EBI\")\n	  {\n	\
    $cl_method=$method;\n	    &check_configuration\
(\"EMAIL\",\"XML::Simple\", \"INTERNET\");\n	    i\
f ($db eq \"uniprot\"){$db1=\"uniprotkb\";}\n	    \
else {$db1=$db;}\n\n	    \n	    if ($cl_method =~/\
wu/)\n	      {\n		$cl_method=~s/wu//;\n		if ( $cl_\
method eq \"psiblast\"){$cl_method=\"blastp\";}\n\\
n		$command=\"t_coffee -other_pg wublast_lwp.pl --\
email $EMAIL -D $db1 -p $cl_method --outfile $outf\
ile --align 5 --stype protein $infile>/dev/null 2>\
error_log\";\n	      }\n	    else\n	      {\n		if \
( $cl_method =~/psiblast/){$cl_method =\"blastp -j\
5\";}\n		$command=\"t_coffee -other_pg ncbiblast_l\
wp.pl --email $EMAIL -D $db1 -p $cl_method --outfi\
le $outfile --align 5 --stype protein $infile>/dev\
/null 2>$error_log\";\n		#DEBUG\n		#$command=\"t_c\
offee -other_pg ncbiblast_lwp.pl --email $EMAIL -D\
 $db1 -p $cl_method --outfile $outfile --align 5 -\
-stype protein $infile\";\n		\n		my $maxrun=5;#num\
ber of crashes accepetd\n		my $nrun;\n		my $keep_g\
oing=1;\n		while ($keep_going)\n		  {\n		    \n		 \
   #print \"----- $command [$nrun]\\n\";\n		    $n\
run++;\n		    $keep_going=0;\n		    &safe_system (\
 $command,5);\n		    \n		    my $success=0;\n		   \
 $success =$success || -e \"$outfile.out.xml\";\n	\
	    $success =$success || -e \"$outfile.xml.xml\"\
;\n		    $success =$success || -e \"$outfile.out..\
xml\";\n		    $success =$success || -e \"$outfile.\
xml..xml\";\n		    \n		    if (!$success && ($nrun\
<$maxrun || -e \"$outfile.out.txt\"))\n		      {\n\
			$keep_going=1;\n			add_warning($$,$$,\"[ncbibla\
st_lwp.pl] [$command] failed to produce xml output\
 -- will ne tried again [$nrun]\");\n		      }\n		\
  }\n		\n		if (-e \"$outfile.out.xml\") {`mv $outf\
ile.out.xml $outfile`;}\n		elsif (-e \"$outfile.xm\
l.xml\"){`mv $outfile.xml.xml $outfile`;}\n		elsif\
 (-e \"$outfile.out..xml\") {`mv $outfile.out..xml\
 $outfile`;}\n		elsif (-e \"$outfile.xml..xml\"){`\
mv $outfile.xml..xml $outfile`;}\n		else\n		  {\n	\
	    add_warning($$,$$,\"[ncbiblast_lwp.pl] [$comm\
and] failed to produce xml output\");\n		  }\n	   \
   }\n	  }\n	elsif ($SERVER eq \"NCBI\")\n	  {\n	 \
   &check_configuration (\"INTERNET\");\n	    if (\
$db eq \"uniprot\"){$cl_db=\"swissprot\";}\n	    e\
lse {$cl_db=$db;}\n\n	    if ( $method eq \"psibla\
st\")\n	      {\n		add_warning($$,$$,\"PSI BLAST c\
annot be used with the NCBI BLAST Client. Use serv\
er=EBI Or server=LOCAL. blastp will be used instea\
d\");\n		$cl_method=\"blastp\";\n	      }\n	    el\
se\n	      {\n		$cl_method=$method;\n	      }\n	  \
    \n	    &check_configuration ($cl_method);  \n	\
    $command=\"$cl_method -db $cl_db -query $infil\
e -out $outfile -outfmt 5 -remote\";\n	    &safe_s\
ystem ($command);\n	  }\n	elsif ($SERVER =~/CLIENT\
_(.*)/)\n	  {\n	    my $client=$1;\n	    $command=\
\"$client -p $method -d $db -i $infile -o $outfile\
 -m 7\";\n	    &safe_system ($command);\n	  }\n	el\
sif ( $SERVER eq \"LOCAL_blastall\")\n	  {\n	    &\
check_configuration (\"blastall\");\n	    if ($met\
hod eq \"blastp\")\n	      {\n		$command=\"blastal\
l -d $db -i $infile -o $outfile -m7 -p blastp\";\n\
	      }\n	    &safe_system ($command);\n	  }\n	el\
sif ( $SERVER eq \"LOCAL\")\n	  {\n	    if ($ENV{\\
"BLAST_DB_DIR\"}) {\n	    	$x=$ENV{\"BLAST_DB_DIR\\
"};\n			$cl_db=\"$x/$db\";\n	    }\n	    else{\n		\
	$cl_db=$db;\n	    }\n\n        ##\n		## BLAST+ pr\
ovide different binaries names and CLI options\n		\
## Use the 'legacy_blast.pl' to keep compatibility\
 with old blast commands\n		##\n		$path=`which leg\
acy_blast.pl 2>/dev/null`;  \n		$path=`dirname $pa\
th`; \n		chomp($path);\n	    if ($method eq \"blas\
tp\"){\n			&check_configuration(\"legacy_blast.pl\\
");\n			$command=\"legacy_blast.pl blastpgp --path\
 $path -d $cl_db -i $infile -o $outfile -m7 -j1\";\
\n	    }\n	    elsif ($method eq \"psiblast\")\n	 \
     {\n		&check_configuration(\"legacy_blast.pl\"\
);\n		$command=\"legacy_blast.pl blastpgp --path $\
path -d $cl_db -i $infile -o $outfile -m7 -j5\";\n\
	      }\n	    elsif ($method eq \"blastn\")\n	   \
   {\n		&check_configuration(\"legacy_blast.pl\");\
\n		$command=\"legacy_blast.pl blastall --path $pa\
th -p blastn -d $cl_db -i $infile -o $outfile -m7 \
-W6\";\n	      }\n	    &safe_system ($command);\n	\
  }\n	else\n	  {\n\n	    myexit(add_error (EXIT_FA\
ILURE,$$,$$,getppid(), \"BLAST_FAILURE::UnknownSer\
ver\",$CL));\n	  }\n\n\n	#Check that everything we\
nt well\n\n	if ( !-e $outfile || !&is_valid_blast_\
xml($outfile))\n	  {\n\n	    if ( -e $outfile)\n	 \
     {\n		add_warning ($$,$$,\"Corrupted Blast Out\
put (Run $run)\");\n		unlink($outfile);\n	      }\\
n	    if ( -e $error_log)\n	      {\n\n		my $error\
_msg=file2string ($error_log);\n\n		if ( $error_ms\
g =~/enter a valid email/)\n		  {\n		    myexit(ad\
d_error (EXIT_FAILURE,$$,$$,getppid(), \"BLAST_FAI\
LURE::Invalid_or_rejected_email::$EMAIL\", \"$comm\
and\"));\n		  }\n	      }\n	    if ( $run==$BLAST_\
MAX_NRUNS)\n	      {\n\n		myexit(add_error (EXIT_F\
AILURE,$$,$$,getppid(), \"BLAST_FAILURE::UnknownRe\
ason\", \"$command\"));\n	      }\n	    else\n	   \
   {\n		my $out;\n		if ($SERVER eq \"NCBI\") {$SER\
VER=\"EBI\"; }\n		elsif ($SERVER eq \"EBI\"){$SERV\
ER=\"NCBI\";}\n		add_warning ($$,$$,\"Blast for $n\
ame failed (Run: $run out of $BLAST_MAX_NRUNS. Use\
 $SERVER)\");\n		$out=&run_blast ($name, $method, \
$db,$infile, $outfile, $run+1);\n		if ($SERVER eq \
\"NCBI\") {$SERVER=\"EBI\"; }\n		elsif ($SERVER eq\
 \"EBI\"){$SERVER=\"NCBI\";}\n		return $out;\n	   \
   }\n	  }\n\n	&cache_file(\"SET\",$infile,$name,$\
method,$db,$outfile,$SERVER);\n	#system (\"cp $out\
file ~/Dropbox/tmp/cedric.out\");\n	#die;\n	return\
 $outfile;\n      }\n  }\n\nsub cache_file\n  {\n \
   my ($cache_mode,$infile,$name,$method,$db, $out\
file,$server)=(@_);\n    my $cache_file;\n    #Pro\
tect names so that they can be turned into legal f\
ilenames\n    $name=&clean_file_name ($name);\n\n \
   if ($db=~/\\//)\n      {\n	$db=~/([^\\/]+)$/;\n\
	$db=$1;\n      }\n    $cache_file_sh=\"$name.$met\
hod.$db.$server.tmp\";\n    $cache_file=\"$CACHE/$\
name.$method.$db.$server.tmp\";\n\n    if ($infile\
 ne \"\")\n      {\n	$cache_file_infile_sh=\"$name\
.$method.$db.$server.infile.tmp\";\n	$cache_file_i\
nfile=\"$CACHE/$name.$method.$db.$server.infile.tm\
p\";\n      }\n\n    if ($cache_mode eq \"GET\")\n\
      {\n	if ($CACHE eq \"\" || $CACHE eq \"no\" |\
| $CACHE eq \"ignore\"  || $CACHE eq \"local\" || \
$CACHE eq \"update\"){return 0;}\n	elsif ( !-d $CA\
CHE)\n	  {\n	    print STDERR \"ERROR: Cache Dir: \
$CACHE Does not Exist\";\n	    return 0;\n	  }\n	e\
lse\n	  {\n	    if ( -e $cache_file && &fasta_file\
1_eq_fasta_file2($infile,$cache_file_infile)==1)\n\
	      {\n		`cp $cache_file $outfile`;\n		$CACHE_S\
TATUS=\"READ CACHE\";\n		return 1;\n	      }\n	  }\
\n      }\n    elsif ($cache_mode eq \"SET\")\n   \
   {\n	if ($CACHE eq \"\" || $CACHE eq \"no\" || $\
CACHE eq \"ignore\"  || $CACHE eq \"local\" || $CA\
CHE eq \"update\"){return 0;}\n	elsif ( !-d $CACHE\
)\n	  {\n	    print STDERR \"ERROR: Cache Dir: $CA\
CHE Does not Exist\";\n	    return 0;\n	  }\n	elsi\
f (-e $outfile)\n	  {\n	    `cp $outfile $cache_fi\
le`;\n	    if ($cache_file_infile ne \"\"){ `cp $i\
nfile $cache_file_infile`;}\n\n	    #functions for\
 updating the cache\n	    #`t_coffee -other_pg cle\
an_cache.pl -file $cache_file_sh -dir $CACHE`;\n	 \
   #`t_coffee -other_pg clean_cache.pl -file $cach\
e_file_infile_sh -dir $CACHE`;\n	    return 1;\n	 \
 }\n      }\n    $CACHE_STATUS=\"COMPUTE CACHE\";\\
n    return 0;\n  }\nsub file1_eq_file2\n  {\n    \
my ($f1, $f2)=@_;\n    if ( $f1 eq \"\"){return 1;\
}\n    elsif ( $f2 eq \"\"){return 1;}\n    elsif \
( !-e $f1){return 0;}\n    elsif ( !-e $f2){return\
 0;}\n    elsif ($f1 eq \"\" || $f2 eq \"\" || `di\
ff $f1 $f2` eq \"\"){return 1;}\n\n    return 0;\n\
  }\nsub clean_file_name\n  {\n    my $name=@_[0];\
\n\n    $name=~s/[^A-Za-z1-9.-]/_/g;\n    return $\
name;\n  }\nsub url2file\n  {\n    my ($address, $\
out)=(@_);\n\n    if (&pg_is_installed (\"wget\"))\
\n	{\n	  return &safe_system (\"wget $address -O$o\
ut >/dev/null 2>/dev/null\");\n	}\n    elsif (&pg_\
is_installed (\"curl\"))\n      {\n	return &safe_s\
ystem (\"curl $address -o$out >/dev/null 2>/dev/nu\
ll\");\n      }\n    else\n      {\n	myexit(flus_e\
rror(\"neither curl nor wget are installed. Imnpos\
sible to fectch remote file\"));\n	exit ($EXIT_FAI\
LURE);\n      }\n  }\nsub fasta_file1_eq_fasta_fil\
e2\n  {\n    my ($f1, $f2)=@_;\n    my (%s1, %s2);\
\n    my @names;\n    %s1=read_fasta_seq ($f1);\n \
   %s2=read_fasta_seq ($f2);\n\n    @names=(keys (\
%s1));\n\n    foreach $n (keys(%s1))\n      {\n	if\
 ($s1{$n}{seq} ne $s2{$n}{seq}){return 0;}\n      \
}\n\n    foreach $n (keys(%s2))\n      {\n	if ($s1\
{$n}{seq} ne $s2{$n}{seq}){return 0;}\n      }\n  \
  return 1;\n  }\n\n\n\nsub read_template_file\n  \
{\n    my $pdb_templates = @_[0];\n    my $tmp=new\
 FileHandle;\n    open ($tmp, \"<$pdb_templates\")\
;\n    my %temp_h;\n    my ($skip,$seq, $temp);\n\\
n    #supports both a simple [seq pdb] format and \
the regular fasta like template format\n    while \
(<$tmp>)\n      {\n	\n	$line = $_;\n	if ($line=~/\\
\>(\\S+)\\s_._\\s(\\S+)/){$temp_h{$1}= $2;}\n	elsi\
f ($line =~/(\\S+)\\s(\\S+)/){$temp_h{$1}= $2;}\n \
     }\n    close($tmp);\n    return %temp_h;\n  }\
\n\n\n\n\n\n\nsub seq2tblastx_lib\n  {\n    my ($m\
ode, $infile, $outfile)=@_;\n    my (%s, $method,$\
nseq);\n\n    $method=$mode;\n    &set_temporary_d\
ir (\"set\",$infile,\"infile\");\n    %s=read_fast\
a_seq(\"infile\");\n\n\n    foreach $seq (keys(%s)\
)\n      {\n	$slist[$s{$seq}{order}]=$s{$seq}{seq}\
;\n	$sname[$s{$seq}{order}]=$s{$seq}{name};\n	$sle\
n[$s{$seq}{order}]=length ($s{$seq}{seq});\n      \
}\n    $nseq=$#sname+1;\n    open (F, \">outfile\"\
);\n    print F \"! TC_LIB_FORMAT_01\\n\";\n    pr\
int F \"$nseq\\n\";\n    for ($a=0; $a<$nseq;$a++)\
\n      {\n	print F \"$sname[$a] $slen[$a]  $slist\
[$a]\\n\"\n      }\n    close (F);\n    &safe_syst\
em (\"formatdb -i infile -p F\");\n    &safe_syste\
m (\"blastall -p tblastx -i infile -d infile -m 7 \
-S1>blast.output\");\n\n    ncbi_tblastx_xml2lib_f\
ile (\"outfile\", file2string (\"blast.output\"));\
\n    &set_temporary_dir (\"unset\",$mode, $method\
, \"outfile\",$outfile);\n    myexit ($EXIT_SUCCES\
S);\n    }\nsub seq2tblastpx_lib\n  {\n    my ($mo\
de, $infile, $outfile)=@_;\n    my (%s, $method,$n\
seq);\n    $method=$mode;\n    &set_temporary_dir \
(\"set\",$infile,\"infile\");\n    %s=read_fasta_s\
eq(\"infile\");\n\n    foreach $seq (keys(%s))\n  \
    {\n	$slist[$s{$seq}{order}]=$s{$seq}{seq};\n	$\
sname[$s{$seq}{order}]=$s{$seq}{name};\n	$slen[$s{\
$seq}{order}]=length ($s{$seq}{seq});\n      }\n  \
  $nseq=$#sname+1;\n    open (F, \">outfile\");\n \
   print F \"! TC_LIB_FORMAT_01\\n\";\n    print F\
 \"$nseq\\n\";\n    for ($a=0; $a<$nseq;$a++)\n   \
   {\n	print F \"$sname[$a] $slen[$a]  $slist[$a]\\
\n\"\n      }\n    close (F);\n    &safe_system(\"\
t_coffee -other_pg seq_reformat -in infile -output\
 tblastx_db1 > tblastxdb\");\n    &safe_system (\"\
formatdb -i tblastxdb -p T\");\n    &safe_system (\
\"blastall -p blastp -i tblastxdb -d tblastxdb -m7\
 >blast.output\");\n    ncbi_tblastpx_xml2lib_file\
 (\"outfile\", file2string (\"blast.output\"), %s)\
;\n    &set_temporary_dir (\"unset\",$mode, $metho\
d, \"outfile\",$outfile);\n    myexit ($EXIT_SUCCE\
SS);\n    }\n\nsub x3dna_find_pair2lib\n      {\n \
     my ($seq, $pdb, $lib, $pg)=@_;\n      my $out\
file1=\"dssr-2ndstrs.dbn\";\n      my $outfile2=\"\
simple.output\";\n      my $f= new FileHandle;\n  \
    my ($rnaSS,$pdbSS);\n      my $command;\n     \
 my %s_pdb;\n      my %s_seq;\n      \n      #$pg:\
 \"find_pair\" OR \"find_pair -p\"\n      \n      \
if (!pg_is_installed (\"find_pair\"))\n	{\n	  add_\
warning ($$,$$, \"x3dna/find_pairs could not be us\
ed to extract RNA secondary structures. Secondary \
structures will be extracted by x3dna-ssr instead\\
");\n	  return x3dnassr2lib ($seq, $pdb, $lib);\n	\
}\n      \n      #get PDB sequence\n      safe_sys\
tem (\"t_coffee -other_pg extract_from_pdb $pdb -s\
eq >$outfile1\");\n      \n      #get find_pair co\
ntacts\n      $command=\"$pg $pdb simple.output > \
/dev/null 2>/dev/null\";\n      safe_system ($comm\
and);\n\n      if (($command=~/find_pair -p/)){$ou\
tfile2=\"allpairs.ana\";}\n      else {$outfile2=\\
"simple.output\";}\n      \n      if ( !-e $outfil\
e2)\n	{\n	  myexit(flush_error(\"x3dna failed to c\
ompute the secondary structure file $outfile2 for \
$pdb\"));\n	  myexit ($EXIT_FAILURE);\n	}\n      \\
n\n      #Handle situations when the pdb sequence \
differs from the RNA sequence\n      #my @out=file\
2array($outfile1);\n      %s_pdb=read_fasta_seq_in\
dex ($outfile1);\n      %s_seq=read_fasta_seq_inde\
x ($seq);\n      my $rnaS=uc($s_seq{0}{seq});\n   \
   my $pdbS=uc($s_pdb{0}{seq});\n      \n      my \
$vienna;\n      my @lu;\n    \n      if ($rnaS ne \
$pdbS)\n	{\n	  \n	  my ($rna,$pdb);\n	  $rnaSS=$rn\
aS;\n	  $pdbSS=$pdbS;\n	  $rnaSS=~s/T/U/g;\n	  $pd\
bSS=~s/T/U/g;\n	  ($rnaSS,$pdbSS)=nw ($rnaS, $pdbS\
);\n	  \n	  my @rnaA =split (//,$rnaSS);\n	  my @p\
dbA=split (//,$pdbSS);\n	  my $l=@rnaA;\n	  \n	  #\
print \"\\n--- $s_seq{0}{name} $rnaSS\\n--- $s_seq\
{0}{name} $pdbSS\\n\\n\";\n	  \n	  for (my $b=0,my\
 $a=0; $a<$l; $a++)\n	    {\n	      if   ($rnaA[$a\
] ne '-' && $pdbA[$a] ne '-'){$lu[++$pdb]=++$rna;}\
\n	      elsif($rnaA[$a] eq '-'){$lu[++$pdb]=-1;}\\
n	      elsif($pdbA[$a] eq '-'){++$rna;}\n	    }\n\
	}\n      else\n	{\n	  for (my $a=0; $a<=length ($\
rnaS); $a++)\n	    {\n	      $lu[$a]=$a;\n	    }\n\
	}\n      my $l=length ($rnaS);\n      open ($f, \\
">$lib\");\n      print $f \"! TC_LIB_FORMAT_01\\n\
\";\n      print $f \"1\\n\";\n      print $f \"$s\
_seq{0}{name} $l $rnaS\\n\";\n      print $f \"!CM\
T: [SOURCE] >$s_seq{0}{name} 3D contact library Ge\
nerated by $pg (x3dna)\\n\";\n      print $f \"#1 \
1\\n\";\n      \n      my $ne;\n      my @array=fi\
le2array($outfile2);\n      for (my $a=0; $a<5; $a\
++){shift (@array);}\n      while (!($array[0]=~/#\
###/))\n	{\n	  my $line= shift (@array);\n	  my @l\
=($line=~/(\\d+)/g);\n	  \n	 \n	  my $f1=$lu[$l[0]\
];\n	  my $s1=$lu[$l[1]];\n\n	  #print \"\\n$line\\
\n$l[0] --> $f1\\n$l[1] --> $s1\\n\\n\"; \n	  \n	 \
 if (!$f1 || !$s1)\n	    {\n	      print \"\\n----\
 $rnaSS\\n---- $pdbSS\\n$line\\n[$l[0] --- $l[1]]<\
---->[$f1 --- $s1]\\n\";\n	      myexit(flush_erro\
r(\"Error while parsing s3dna::find_pair output\")\
);\n	    }\n	  elsif ($f1==-1 || $s1==-1){;}\n	  e\
lsif ($f1<$s1){print $f \"$f1 $s1 100\\n\";}\n	  e\
lse {print $f \"$s1 $f1 100\\n\";$ne++;}\n	}\n    \
  print $f \"! SEQ_1_TO_N\\n\";\n      close ($f);\
\n      return;\n    }\nsub RNAplfold2lib\n  {\n  \
  my ($seq, $lib)=@_;\n    my $f= new FileHandle;\\
n    \n    &safe_system (\"t_coffee -other_pg RNAp\
lfold2tclib.pl -in=$seq -out=$lib\");\n    \n    i\
f ( !-e $lib)\n	{\n	 myexit(flush_error(\"RNAplfol\
d failed to compute the secondary structure of $s{\
$seq}{name}\"));\n	 myexit ($EXIT_FAILURE);\n     \
  }\n    open ($f, \">>$lib\");\n    print $f \"!C\
MT: [SOURCE] 2D contact library Generated by RNAPl\
fold (Vienna Package)\\n\";\n    close $f;\n    re\
turn;\n  }\nsub x3dnassr2lib\n    {\n      my ($se\
q, $pdb, $lib)=@_;\n      my $outfile=\"dssr-2ndst\
rs.dbn\";\n      my $f= new FileHandle;\n      \n\\
n      if (!pg_is_installed (\"x3dna-ssr\"))\n	{\n\
	  add_warning ($$,$$, \"x3dna-ssr could not be us\
ed to extract RNA secondary structures. Secondary \
structures will be predicted ab-initio instead wit\
h RNAPlfold\");\n	  return RNAplfold2lib ($seq,$li\
b);\n	}\n      \n      safe_system (\"x3dna-ssr -i\
=$pdb >/dev/null 2>/dev/null\");\n      if ( !-e $\
outfile)\n	{\n	  myexit(flush_error(\"x3dna-ssr fa\
iled to compute the secondary structure file \"));\
\n	  myexit ($EXIT_FAILURE);\n	}\n\n      #Handle \
situations when the pdb sequence differs from the \
RNA sequence\n      @out=file2array($outfile);\n  \
    my %s=read_fasta_seq ($seq);\n      my @names=\
keys (%s);\n      my $rnaS=uc($s{$names[0]}{seq});\
\n      my $pdbS=uc($out[1]);\n      my $vienna;\n\
      \n      #x3dna returns non legitimate nucleo\
tides\n       $pdbS=~s/[^AGCTU]//g;\n      \n     \
 if ($rnaS ne $pdbS)\n	{\n	  my ($rna,$pdb);\n	  m\
y $rnaSS=$rnaS;\n	  my $pdbSS=$pdbS;\n	  $rnaSS=~s\
/T/U/g;\n	  $pdbSS=~s/T/U/g;\n	  ($rnaSS,$pdbSS)=n\
w ($rnaSS, $pdbSS);\n	  my @rnaA =split (//,$rnaSS\
);\n	  my @pdbA=split (//,$pdbSS);\n	  my @SS=spli\
t (//, $out[2]);\n	  \n	  my $l=@rnaA;\n	  for (my\
 $b=0,my $a=0; $a<$l; $a++)\n	    {\n	      if   (\
$rnaA[$a] ne '-' && $pdbA[$a] ne '-'){$vienna.=$SS\
[$b++];}\n	      elsif($rnaA[$a] eq '-'){$b++;}\n	\
      elsif($pdbA[$a] eq '-'){$vienna.='.';}\n	   \
 }\n	}\n      else\n	{\n	  $vienna=$out[2];\n	}\n \
   \n\n      open ($f, \">seq\");\n      print $f \
\">$names[0]\\n$rnaS\\n\";\n      close $f;\n     \
 \n      open ($f, \">str\");\n      print $f \">$\
names[0]\\n$vienna\\n\";\n      close $f;\n      \\
n      safe_system (\"t_coffee -other_pg seq_refor\
mat -in seq -in2 str -output vienna2tc_lib >$lib\"\
);\n      if ( !-e $lib)\n	    {\n	      myexit(fl\
ush_error(\"seq_reformat failed to convert your se\
condary structure\"));\n	      myexit ($EXIT_FAILU\
RE);\n	    }\n      \n      open ($f, \">>$lib\");\
\n      print $f \"!CMT: [SOURCE] >$names[0] 2D Co\
ntact library generated by x3dna-ssr\\n\";\n      \
#print $f \"! Vienna_Format: >$names[0]\\n\";\n   \
   #print $f \"! Vienna_Format: $vienna\\n\";\n   \
   \n      close $f;\n      return;\n    }\n\n\nsu\
b file2head\n      {\n	my $file = shift;\n	my $siz\
e = shift;\n	my $f= new FileHandle;\n	my $line;\n	\
open ($f,$file);\n	read ($f,$line, $size);\n	close\
 ($f);\n	return $line;\n      }\nsub file2tail\n  \
    {\n	my $file = shift;\n	my $size = shift;\n	my\
 $f= new FileHandle;\n	my $line;\n\n	open ($f,$fil\
e);\n	seek ($f,$size*-1, 2);\n	read ($f,$line, $si\
ze);\n	close ($f);\n	return $line;\n      }\n\n\ns\
ub vtmpnam\n      {\n	my $r=rand(100000);\n	my $f=\
\"file.$r.$$\";\n	while (-e $f)\n	  {\n	    $f=vtm\
pnam();\n	  }\n	push (@TMPFILE_LIST, $f);\n	return\
 $f;\n      }\n\nsub myexit\n  {\n    my $code=@_[\
0];\n    if ($CLEAN_EXIT_STARTED==1){return;}\n   \
 else {$CLEAN_EXIT_STARTED=1;}\n    ### ONLY BARE \
EXIT\n    exit ($code);\n  }\nsub set_error_lock\n\
    {\n      my $name = shift;\n      my $pid=$$;\\
n\n\n      &lock4tc ($$,\"LERROR\", \"LSET\", \"$$\
 -- ERROR: $name $PROGRAM\\n\");\n      return;\n \
   }\nsub set_lock\n  {\n    my $pid=shift;\n    m\
y $msg= shift;\n    my $p=getppid();\n    &lock4tc\
 ($pid,\"LLOCK\",\"LRESET\",\"$p$msg\\n\");\n  }\n\
sub unset_lock\n   {\n\n    my $pid=shift;\n    &l\
ock4tc ($pid,\"LLOCK\",\"LRELEASE\",\"\");\n  }\ns\
ub shift_lock\n  {\n    my $from=shift;\n    my $t\
o=shift;\n    my $from_type=shift;\n    my $to_typ\
e=shift;\n    my $action=shift;\n    my $msg;\n\n \
   if (!&lock4tc($from, $from_type, \"LCHECK\", \"\
\")){return 0;}\n    $msg=&lock4tc ($from, $from_t\
ype, \"LREAD\", \"\");\n    &lock4tc ($from, $from\
_type,\"LRELEASE\", $msg);\n    &lock4tc ($to, $to\
_type, $action, $msg);\n    return;\n  }\nsub issh\
ellpid\n  {\n    my $p=shift;\n    if (!lock4tc ($\
p, \"LLOCK\", \"LCHECK\")){return 0;}\n    else\n \
     {\n	my $c=lock4tc($p, \"LLOCK\", \"LREAD\");\\
n	if ( $c=~/-SHELL-/){return 1;}\n      }\n    ret\
urn 0;\n  }\nsub isrootpid\n  {\n    if(lock4tc (g\
etppid(), \"LLOCK\", \"LCHECK\")){return 0;}\n    \
else {return 1;}\n  }\nsub lock4tc\n	{\n	  my ($pi\
d,$type,$action,$value)=@_;\n	  my $fname;\n	  my \
$host=hostname;\n\n	  if ($type eq \"LLOCK\"){$fna\
me=\"$LOCKDIR/.$pid.$host.lock4tcoffee\";}\n	  els\
if ( $type eq \"LERROR\"){ $fname=\"$LOCKDIR/.$pid\
.$host.error4tcoffee\";}\n	  elsif ( $type eq \"LW\
ARNING\"){ $fname=\"$LOCKDIR/.$pid.$host.warning4t\
coffee\";}\n\n	  if ($debug_lock)\n	    {\n	      \
print STDERR \"\\n\\t---lock4tc(tcg): $action => $\
fname =>$value (RD: $LOCKDIR)\\n\";\n	    }\n\n	  \
if    ($action eq \"LCHECK\") {return -e $fname;}\\
n	  elsif ($action eq \"LREAD\"){return file2strin\
g($fname);}\n	  elsif ($action eq \"LSET\") {retur\
n string2file ($value, $fname, \">>\");}\n	  elsif\
 ($action eq \"LRESET\") {return string2file ($val\
ue, $fname, \">\");}\n	  elsif ($action eq \"LRELE\
ASE\")\n	    {\n	      if ( $debug_lock)\n		{\n		 \
 my $g=new FileHandle;\n		  open ($g, \">>$fname\"\
);\n		  print $g \"\\nDestroyed by $$\\n\";\n		  c\
lose ($g);\n		  safe_system (\"mv $fname $fname.ol\
d\");\n		}\n	      else\n		{\n		  unlink ($fname);\
\n		}\n	    }\n	  return \"\";\n	}\n\nsub file2str\
ing\n	{\n	  my $file=@_[0];\n	  my $f=new FileHand\
le;\n	  my $r;\n	  open ($f, \"$file\");\n	  while\
 (<$f>){$r.=$_;}\n	  close ($f);\n	  return $r;\n	\
}\nsub file2array\n	{\n	  my $file=@_[0];\n	  my $\
f=new FileHandle;\n	  my @r;\n	  open ($f, \"$file\
\");\n	  while (<$f>){@r=(@r,$_);}\n	  close ($f);\
\n	  return @r;\n	}\nsub string2file\n    {\n    m\
y ($s,$file,$mode)=@_;\n    my $f=new FileHandle;\\
n\n    open ($f, \"$mode$file\");\n    print $f  \\
"$s\";\n    close ($f);\n  }\n\nBEGIN\n    {\n    \
  srand;\n\n      $SIG{'SIGUP'}='signal_cleanup';\\
n      $SIG{'SIGINT'}='signal_cleanup';\n      $SI\
G{'SIGQUIT'}='signal_cleanup';\n      $SIG{'SIGILL\
'}='signal_cleanup';\n      $SIG{'SIGTRAP'}='signa\
l_cleanup';\n      $SIG{'SIGABRT'}='signal_cleanup\
';\n      $SIG{'SIGEMT'}='signal_cleanup';\n      \
$SIG{'SIGFPE'}='signal_cleanup';\n\n      $SIG{'SI\
GKILL'}='signal_cleanup';\n      $SIG{'SIGPIPE'}='\
signal_cleanup';\n      $SIG{'SIGSTOP'}='signal_cl\
eanup';\n      $SIG{'SIGTTIN'}='signal_cleanup';\n\
      $SIG{'SIGXFSZ'}='signal_cleanup';\n      $SI\
G{'SIGINFO'}='signal_cleanup';\n\n      $SIG{'SIGB\
US'}='signal_cleanup';\n      $SIG{'SIGALRM'}='sig\
nal_cleanup';\n      $SIG{'SIGTSTP'}='signal_clean\
up';\n      $SIG{'SIGTTOU'}='signal_cleanup';\n   \
   $SIG{'SIGVTALRM'}='signal_cleanup';\n      $SIG\
{'SIGUSR1'}='signal_cleanup';\n\n\n      $SIG{'SIG\
SEGV'}='signal_cleanup';\n      $SIG{'SIGTERM'}='s\
ignal_cleanup';\n      $SIG{'SIGCONT'}='signal_cle\
anup';\n      $SIG{'SIGIO'}='signal_cleanup';\n   \
   $SIG{'SIGPROF'}='signal_cleanup';\n      $SIG{'\
SIGUSR2'}='signal_cleanup';\n\n      $SIG{'SIGSYS'\
}='signal_cleanup';\n      $SIG{'SIGURG'}='signal_\
cleanup';\n      $SIG{'SIGCHLD'}='signal_cleanup';\
\n      $SIG{'SIGXCPU'}='signal_cleanup';\n      $\
SIG{'SIGWINCH'}='signal_cleanup';\n\n      $SIG{'I\
NT'}='signal_cleanup';\n      $SIG{'TERM'}='signal\
_cleanup';\n      $SIG{'KILL'}='signal_cleanup';\n\
      $SIG{'QUIT'}='signal_cleanup';\n\n      our \
$debug_lock=$ENV{\"DEBUG_LOCK\"};\n\n\n\n\n      f\
oreach my $a (@ARGV){$CL.=\" $a\";}\n      if ( $d\
ebug_lock ){print STDERR \"\\n\\n\\n********** STA\
RT PG: $PROGRAM *************\\n\";}\n      if ( $\
debug_lock ){print STDERR \"\\n\\n\\n**********(tc\
g) LOCKDIR: $LOCKDIR $$ *************\\n\";}\n    \
  if ( $debug_lock ){print STDERR \"\\n --- $$ -- \
$CL\\n\";}\n\n\n\n\n    }\nsub flush_error\n  {\n \
   my $msg=shift;\n    return add_error ($EXIT_FAI\
LURE,$$, $$,getppid(), $msg, $CL);\n  }\nsub add_e\
rror\n  {\n    my $code=shift;\n    my $rpid=shift\
;\n    my $pid=shift;\n    my $ppid=shift;\n    my\
 $type=shift;\n    my $com=shift;\n\n    $ERROR_DO\
NE=1;\n    lock4tc ($rpid, \"LERROR\",\"LSET\",\"$\
pid -- ERROR: $type\\n\");\n    lock4tc ($$, \"LER\
ROR\",\"LSET\", \"$pid -- COM: $com\\n\");\n    lo\
ck4tc ($$, \"LERROR\",\"LSET\", \"$pid -- STACK: $\
ppid -> $pid\\n\");\n\n    return $code;\n  }\nsub\
 add_warning\n  {\n    my $rpid=shift;\n    my $pi\
d =shift;\n    my $command=shift;\n    my $msg=\"$\
$ -- WARNING: $command\\n\";\n    print STDERR \"$\
msg\";\n    lock4tc ($$, \"LWARNING\", \"LSET\", $\
msg);\n  }\n\nsub signal_cleanup\n  {\n    print d\
tderr \"\\n**** $$ (tcg) was killed\\n\";\n    &cl\
eanup;\n    exit ($EXIT_FAILURE);\n  }\nsub clean_\
dir\n  {\n    my $dir=@_[0];\n    if ( !-d $dir){r\
eturn ;}\n    elsif (!($dir=~/tmp/)){return ;}#saf\
ety check 1\n    elsif (($dir=~/\\*/)){return ;}#s\
afety check 2\n    else\n      {\n	`rm -rf $dir`;\\
n      }\n    return;\n  }\nsub cleanup\n  {\n    \
#print stderr \"\\n----tc: $$ Kills $PIDCHILD\\n\"\
;\n    #kill (SIGTERM,$PIDCHILD);\n    my $p=getpp\
id();\n    $CLEAN_EXIT_STARTED=1;\n\n\n\n    if (&\
lock4tc($$,\"LERROR\", \"LCHECK\", \"\"))\n      {\
\n	my $ppid=getppid();\n	if (!$ERROR_DONE)\n	  {\n\
	    &lock4tc($$,\"LERROR\", \"LSET\", \"$$ -- STA\
CK: $p -> $$\\n\");\n	    &lock4tc($$,\"LERROR\", \
\"LSET\", \"$$ -- COM: $CL\\n\");\n	  }\n      }\n\
    my $warning=&lock4tc($$, \"LWARNING\", \"LREAD\
\", \"\");\n    my $error=&lock4tc($$,  \"LERROR\"\
, \"LREAD\", \"\");\n    #release error and warnin\
g lock if root\n\n    if (isrootpid() && ($warning\
 || $error) )\n      {\n\n	print STDERR \"********\
******** Summary *************\\n$error\\n$warning\
\\n\";\n\n	&lock4tc($$,\"LERROR\",\"RELEASE\",\"\"\
);\n	&lock4tc($$,\"LWARNING\",\"RELEASE\",\"\");\n\
      }\n\n\n    foreach my $f (@TMPFILE_LIST)\n  \
    {\n	if (-e $f){unlink ($f);}\n      }\n    for\
each my $d (@TMPDIR_LIST)\n      {\n	clean_dir ($d\
);\n      }\n    #No More Lock Release\n    #&lock\
4tc($$,\"LLOCK\",\"LRELEASE\",\"\"); #release lock\
\n\n    if ( $debug_lock ){print STDERR \"\\n\\n\\\
n********** END PG: $PROGRAM ($$) *************\\n\
\";}\n    if ( $debug_lock ){print STDERR \"\\n\\n\
\\n**********(tcg) LOCKDIR: $LOCKDIR $$ **********\
***\\n\";}\n  }\nEND\n  {\n\n    &cleanup();\n  }\\
n\nsub blast_com2new_blast_com\n    {\n      my $c\
om=shift;\n	  if ($com=~/formatdb/)\n	    {\n	    \
  $com=~s/formatdb/makeblastdb/;\n	      $com=~s/\\
\-i/\\-in/;\n	      if ($com =~/pF/){$com=~s/\\-pF\
/\\-dbtype nucl/;}\n	      if ($com =~/p F/){$com=\
~s/\\-p F/\\-dbtype nucl/;}\n	      $com=\"$com -l\
ogfile /dev/null\";\n	      return $com;\n	    }\n\
	  else {return $com;}\n\n    }\nsub safe_system\n\
{\n  my $com=shift;\n  my $ntry=shift;\n  my $ctry\
=shift;\n  my $pid;\n  my $status;\n  my $ppid=get\
ppid();\n  if ($com eq \"\"){return 1;}\n\n  if ( \
($com=~/^blast/) ||($com=~/^formatdb/)){$com=&blas\
t_com2new_blast_com($com);}\n\n  if (($pid = fork \
()) < 0){return (-1);}\n  if ($pid == 0)\n    {\n \
     set_lock($$, \" -SHELL- $com (tcg)\");\n     \
 if( $debug_generic_method ) { printf \"~ exec: %s\
\\n\", $com; }\n      exec ($com);\n      if( $deb\
ug_generic_method ) { printf \"~ exitcode: %s\\n\"\
, $?; }\n    }\n  else\n    {\n      lock4tc ($$, \
\"LLOCK\", \"LSET\", \"$pid\\n\");#update parent\n\
      $PIDCHILD=$pid;\n    }\n  if ($debug_lock){p\
rintf STDERR \"\\n\\t .... safe_system (fasta_seq2\
hmm)  p: $$ c: $pid COM: $com\\n\";}\n\n  waitpid \
($pid,WTERMSIG);\n\n  shift_lock ($pid,$$, \"LWARN\
ING\",\"LWARNING\", \"LSET\");\n\n  if ($? == $EXI\
T_FAILURE || lock4tc($pid, \"LERROR\", \"LCHECK\",\
 \"\"))\n    {\n      if ($ntry && $ctry <$ntry)\n\
	{\n\n	  add_warning ($$,$$,\"$com failed [retry: \
$ctry out of $ntry]\");\n	  lock4tc ($pid, \"LRELE\
ASE\", \"LERROR\", \"\");\n	  #if ($com=~/EBI/){$c\
om=~s/EBI/NCBI/;}\n	  #elsif ($com=~/NCBI/){$com=~\
s/NCBI/EBI/;}\n\n	  return safe_system ($com, $ntr\
y, ++$ctry);\n	}\n      elsif ($ntry == -1)\n	{\n	\
  if (!shift_lock ($pid, $$, \"LERROR\", \"LWARNIN\
G\", \"LSET\"))\n	    {\n	      add_warning ($$,$$\
,\"$com failed\");\n	    }\n	  else\n	    {\n	    \
  lock4tc ($pid, \"LRELEASE\", \"LERROR\", \"\");\\
n	    }\n	  return $?;}\n      else\n	{\n	  if (!s\
hift_lock ($pid,$$, \"LERROR\",\"LERROR\", \"LSET\\
"))\n	    {\n	      myexit(add_error ($EXIT_FAILUR\
E,$$,$pid,getppid(), \"UNSPECIFIED system\", $com)\
);\n	    }\n	}\n    }\n  return $?;\n}\n\nsub chec\
k_configuration\n    {\n      my @l=@_;\n      my \
$v;\n      foreach my $p (@l)\n	{\n\n	  if   ( $p \
eq \"EMAIL\")\n	    {\n	      if ( !($EMAIL=~/@/))\
\n		{\n		add_warning($$,$$,\"Could Not Use EMAIL\"\
);\n		myexit(add_error ($EXIT_FAILURE,$$,$$,getppi\
d(),\"EMAIL\",\"$CL\"));\n	      }\n	    }\n	  els\
if( $p eq \"INTERNET\")\n	    {\n	      if ( !&che\
ck_internet_connection())\n		{\n		  myexit(add_err\
or ($EXIT_FAILURE,$$,$$,getppid(),\"INTERNET\",\"$\
CL\"));\n		}\n	    }\n	  elsif( $p eq \"wget\")\n	\
    {\n	      if (!&pg_is_installed (\"wget\") && \
!&pg_is_installed (\"curl\"))\n		{\n		  myexit(add\
_error ($EXIT_FAILURE,$$,$$,getppid(),\"PG_NOT_INS\
TALLED:wget\",\"$CL\"));\n		}\n	    }\n	  elsif( !\
(&pg_is_installed ($p)))\n	    {\n	      myexit(ad\
d_error ($EXIT_FAILURE,$$,$$,getppid(),\"PG_NOT_IN\
STALLED:$p\",\"$CL\"));\n	    }\n	}\n      return \
1;\n    }\nsub nw\n      {\n	my($A,$B)=@_;\n	my ($\
i,$j, $s);\n	my $gep=-2;\n	my $match=+2;\n	my $mis\
match=0;\n	my ($sub, $ins, $del);\n\n\n	if ($A eq \
$B){return ($A,$B);}\n	\n	$A=~s/[\\s\\d]//g;	\n	$B\
=~s/[\\s\\d]//g;	\n\n\n	my @rA=split ('',$A);\n	my\
 @rB=split ('',$B);\n	\n	#evaluate substitutions\n\
	my $lenA=@rA;\n	my $lenB=@rB;\n	\n	for ($i=0; $i<\
=$lenA; $i++){$smat[$i][0]=$i*$gep;$tb[$i][0 ]= 1;\
}\n	for ($j=0; $j<=$lenB; $j++){$smat[0][$j]=$j*$g\
ep;$tb[0 ][$j]=-1;}\n	\n	for ($i=1; $i<=$lenA; $i+\
+)\n	  {\n	    for ($j=1; $j<=$lenB; $j++)\n	     \
 {\n		if ($rA[$i-1] eq $rB[$j-1]){$s=$match;}\n		e\
lse {$s=$mismatch;}\n		\n		$sub=$smat[$i-1][$j-1]+\
$s;\n		$del=$smat[$i  ][$j-1]+$gep;\n		$ins=$smat[\
$i-1][$j  ]+$gep;\n		\n		if   ($sub>=$del && $sub>\
=$ins){$smat[$i][$j]=$sub;$tb[$i][$j]=0;}\n		elsif\
($del>$ins){$smat[$i][$j]=$del;$tb[$i][$j]=-1;}\n	\
	else {$smat[$i][$j]=$ins;$tb[$i][$j]=1;}\n		}\n	 \
 }\n	#print \"\\n---- SCORE=$smat[$lenA][$lenB]\\n\
\";\n	\n	$i=$lenA;\n	$j=$lenB;\n	my $aln_len=0;\n\\
n	while (!($i==0 && $j==0))\n	  {\n	    if ($tb[$i\
][$j]==0)\n	    {\n	      $aA[$aln_len]=$rA[--$i];\
\n	      $aB[$aln_len]=$rB[--$j];\n	    }\n	  elsi\
f ($tb[$i][$j]==-1)\n	    {\n	      $aA[$aln_len]=\
'-';\n	      $aB[$aln_len]=$rB[--$j];\n	    }\n	  \
elsif ($tb[$i][$j]==1)\n	    {\n	      $aA[$aln_le\
n]=$rA[--$i];\n	      $aB[$aln_len]='-';\n	    }\n\
	  $aln_len++;\n	  }\n	\n	\n	@aA=reverse (@aA);\n	\
@aB=reverse (@aB);\n	my $sA=join('',@aA);\n	my $sB\
=join('',@aB);\n	return ($sA,$sB);\n      }\n     \
 \nsub fasta2nseq\n	{\n	  \n	  my $f=@_[0];\n	  my\
 $nseq;\n\n	  open (F, \"$f\") or return 0;\n	  wh\
ile (<F>)\n	    {\n	      if ($_=~/\\>/){$nseq++;}\
\n	    }\n	  close (F);\n	  return $nseq;\n	}\n	\n\
$program=\"T-COFFEE (Version_13.41.0.28bdc39)\";\\\
n\n","use Env;\nuse FileHandle;\nuse Cwd;\nuse Fil\
e::Path;\nuse Sys::Hostname;\nmy $f = new FileHand\
le;\n\nopen ($f, $ARGV[1]);\n$atom=$ARGV[0];\n\n$a\
tom=~s/PRIME/\\'/;\nwhile (<$f>)\n  {\n    my $l=$\
_;\n\n    $l=~s/$atom/CA /;\n    \n    \n    $l=~s\
/  G /GLY /g;\n    $l=~s/  C /CYS /g;\n    $l=~s/ \
 T /THR /g;\n    $l=~s/  A /ALA /g;\n    $l=~s/  U\
 /THR /g;\n    \n    $l=~s/ DG /GLY /g;\n    $l=~s\
/ DC /CYS /g;\n    $l=~s/ DT /THR /g;\n    $l=~s/ \
DA /ALA /g;\n    $l=~s/ DU /THR /g;\n    \n    pri\
nt $l;\n  }\n\n\n\n","*TC_METHOD_FORMAT_01\n******\
************generic_method.tc_method*************\\
n*\n*       Incorporating new methods in T-Coffee\\
n*       Cedric Notredame 26/08/08\n*\n***********\
********************************************\n*Thi\
s file is a method file\n*Copy it and adapt it to \
your need so that the method \n*you want to use ca\
n be incorporated within T-Coffee\n***************\
****************************************\n*       \
           USAGE                              *\n*\
**************************************************\
****\n*This file is passed to t_coffee via -in:\n*\
\n*	t_coffee -in Mgeneric_method.method\n*\n*	The \
method is passed to the shell using the following\\
n*call:\n*<EXECUTABLE><PARAM1><IN_FLAG><seq_file><\
PARAM2><OUT_FLAG><outname><PARAM>\n*\n*Conventions\
:\n*<FLAG_NAME> 	<TYPE>		<VALUE>\n*<VALUE>:	no_nam\
e 	<=> Replaced with a space\n*<VALUE>:	&nbsp	<=> \
Replaced with a space\n*\n************************\
*******************************\n*                \
  ALN_MODE                           *\n**********\
*********************************************\n*pa\
irwise   ->all Vs all (no self )[(n2-n)/2aln]\n*m_\
pairwise ->all Vs all (no self)[n^2-n]^2\n*s_pairw\
ise ->all Vs all (self): [n^2-n]/2 + n\n*multiple \
  ->All the sequences in one go\n*\nALN_MODE		pair\
wise\n*\n*****************************************\
**************\n*                  OUT_MODE       \
                    *\n***************************\
****************************\n* mode for the outpu\
t:\n*External methods: \n* aln -> alignmnent File \
(Fasta or ClustalW Format)\n* lib-> Lib file (TC_L\
IB_FORMAT_01)\n*Internal Methods:\n* fL -> Interna\
l Function returning a List (Librairie)\n* fA -> I\
nternal Function returning an Alignmnent\n*\nOUT_M\
ODE		aln\n****************************************\
***************\n*                  SEQ_TYPE      \
                     *\n**************************\
*****************************\n*G: Genomic, S: Seq\
uence, P: PDB, R: Profile\n*Examples:\n*SEQTYPE	S	\
sequences against sequences (default)\n*SEQTYPE	S_\
P	sequence against structure\n*SEQTYPE	P_P	structu\
re against structure\n*SEQTYPE	PS	mix of sequences\
 and structure	\n*\nSEQ_TYPE	S\n*\n\n*************\
******************************************\n*     \
           COMMAND LINE                         *\\
n*EXECUTABLE PARAM1 IN_FLAG OUT_FLAG PARAM        \
     *\n******************************************\
*************\n***********************************\
********************\n*                  EXECUTABL\
E                         *\n*********************\
**********************************\n*name of the e\
xecutable\n*passed to the shell: executable\n*	\nE\
XECUTABLE	tc_generic_method.pl\n*\n***************\
****************************************\n*       \
           IN_FLAG                             *\n\
**************************************************\
*****\n*IN_FLAG\n*flag indicating the name of the \
in coming sequences\n*IN_FLAG S no_name ->no flag\\
n*IN_FLAG S &bnsp-in&bnsp -> \" -in \"\n*\nIN_FLAG\
		-infile=\n*\n***********************************\
********************\n*                  OUT_FLAG \
                          *\n*********************\
**********************************\n*OUT_FLAG\n*fl\
ag indicating the name of the out-coming data\n*sa\
me conventions as IN_FLAG\n*OUT_FLAG	S no_name ->n\
o flag\n*if you want to redirect, pass the paramet\
ers via PARAM1\n*set OUT_FLAG to >\n*\nOUT_FLAG		-\
outfile=\n*\n*************************************\
******************\n*                  PARAM_1    \
                          *\n*********************\
**********************************\n*<EXECUTABLE><\
PARAM1><IN_FLAG><seq_file><PARAM2><OUT_FLAG><outna\
me><PARAM>\n*Parameters sent to the EXECUTABLE and\
 specified *before* IN_FLAG \n*If there is more th\
an 1 PARAM line, the lines are\n*concatenated\n*Co\
mmand_line: @EP@PARAM@-gapopen%e10%s-gapext%e20\n*\
	%s white space\n*	%e equal sign\n*\n*PARAM1	\n*\n\
*\n*\n********************************************\
***********\n*                  PARAM_2           \
                   *\n****************************\
***************************\n*<EXECUTABLE><PARAM1>\
<IN_FLAG><seq_file><PARAM2><OUT_FLAG><outname><PAR\
AM>\n*Parameters sent to the EXECUTABLE and specif\
ied \n*after* IN_FLAG and *before* OUT_FLAG\n*If t\
here is more than 1 PARAM line, the lines are\n*co\
ncatenated\n*\n*PARAM1	\n*\n*\n*******************\
************************************\n*           \
       PARAM                              *\n*****\
**************************************************\
\n*<EXECUTABLE><PARAM1><IN_FLAG><seq_file><PARAM2>\
<OUT_FLAG><outname><PARAM>\n*Parameters sent to th\
e EXECUTABLE and specified *after* OUT_FLAG\n*If t\
here is more than 1 PARAM line, the lines are\n*co\
ncatenated\n*\nPARAM	-mode=seq_msa -method=clustal\
w2\nPARAM   -OUTORDER=INPUT -NEWTREE=core -align -\
gapopen=-15\n*\n**********************************\
*********************\n*                  END     \
                           *\n********************\
***********************************\n","*TC_METHOD\
_FORMAT_01\n***************clustalw_method.tc_meth\
od*********\nEXECUTABLE	clustalw\nALN_MODE		pairwi\
se\nIN_FLAG		-INFILE=\nOUT_FLAG		-OUTFILE=\nOUT_MO\
DE		aln\nPARAM		-gapopen=-10\nSEQ_TYPE		S\n*******\
******************************************\n","$Ve\
rsionTag =                                        \
                                                  \
                                         2.43;\nus\
e Env;\nuse FileHandle;\nuse Cwd;\nuse File::Path;\
\nuse Sys::Hostname;\n\nour $PIDCHILD;\nour $ERROR\
_DONE;\nour @TMPFILE_LIST;\nour $EXIT_FAILURE=1;\n\
our $EXIT_SUCCESS=0;\n\nour $REFDIR=getcwd;\nour $\
EXIT_SUCCESS=0;\nour $EXIT_FAILURE=1;\n\nour $PROG\
RAM=\"extract_from_pdb\";\nour $CL=$PROGRAM;\n\nou\
r $CLEAN_EXIT_STARTED;\nour $debug_lock=$ENV{\"DEB\
UG_LOCK\"};\nour $LOCKDIR=$ENV{\"LOCKDIR_4_TCOFFEE\
\"};\nif (!$LOCKDIR){$LOCKDIR=getcwd();}\nour $ERR\
ORDIR=$ENV{\"ERRORDIR_4_TCOFFEE\"};\nour $ERRORFIL\
E=$ENV{\"ERRORFILE_4_TCOFFEE\"};\n&set_lock ($$);\\
nif (isshellpid(getppid())){lock4tc(getppid(), \"L\
LOCK\", \"LSET\", \"$$\\n\");}\n      \nour $SILEN\
T=\" >/dev/null 2>/dev/null\";\nour $INTERNET=-1;\\
n\n\n\n\n\n\n\nour $BLAST_MAX_NRUNS=2;\nour $EXIT_\
SUCCESS=0;\nour $EXIT_FAILURE=1;\nour $CONFIGURATI\
ON=-1;\nour $REF_EMAIL=\"\";\nour $PROGRAM=\"extra\
ct_from_pdb\";\n\n\nmy %onelett_prot=&fill_onelett\
_prot();\nmy %threelett_prot=&fill_threelett_prot(\
);\nmy %onelett_RNA=&fill_onelett_RNA();\nmy %thre\
elett_RNA=&fill_threelett_RNA();\nmy %onelett_DNA=\
&fill_onelett_DNA();\nmy %threelett_DNA=&fill_thre\
elett_DNA();\n\n\n\n\n\nmy %onelett = (\n'P' => \\\
%onelett_prot,\n'D' => \\%onelett_DNA,\n'R' => \\%\
onelett_RNA\n);\n\n\nmy %threelett = (\n'P' => \\%\
threelett_prot,\n'D' => \\%threelett_DNA,\n'R' => \
\\%threelett_RNA\n);\n\n\n\n\n\n\n\nif($ARGV[0]=~/\
help/ ||$ARGV[0]=~/man/ || $ARGV[0]=~/HELP/ || $AR\
GV[0]=~/Man/ || $ARGV[0] eq \"-h\"  || $ARGV[0] eq\
 \"-H\"  )\n{die \"SYNTAX: extract_from_pdb Versio\
n $VersionTag	\n	Minimum:             [extract_fro\
m_pdb file] \n			   OR \n			     [... | extract_fr\
om_pdb]\n 	Flags (Default setting on the first lin\
e)\n	   -version...................[Returns the Ve\
rsion Number]\n           -force..................\
...[Forces the file to be treated like a PDB file]\
\n                                      [Regenerat\
es the header and SEQRES fields]\n           -forc\
e_name................[Forces the file to be named\
 after name]]\n           -infile.....file........\
...[Flag can be omited]\n			              [File mu\
st be pdb or fro pgm]\n                           \
           [File can also be compressed Z or gz]\n\
                                      [In the case\
 of a compressed file, you can omit the gz|Z exten\
sion]\n           -netfile...................[File\
 will be fetch from the net using wget]\n         \
                             [wget or curl must be\
 installed]\n                                     \
 [ftp://ftp.gnu.org/pub/gnu/wget/]\n              \
                        [http://curl.haxx.se/]\n  \
                                    [Must also be \
used to retrieve the file from a local pdb copy (c\
f netaddress)]\n           -netaddress............\
....[Address used for the retrieving the netfile]\\
n                                      [http://www\
.rcsb.org/pdb/cgi/export.cgi/%%.pdb.gz?format=PDB&\
pdbId=%%&compression=gz]\n                        \
              [http://www.expasy.ch/cgi-bin/get-pd\
b-entry.pl?%%]\n                                  \
    [local -> will get the file from pdb_dir (see \
pdb_dir)]\n           -netcompression............[\
Extension if the netfile comes compressed]\n      \
                                [gz]\n           -\
pdb_dir...................[address of the repertor\
y where the pdb is installed]\n                   \
                   [Supports standard ftp style in\
stallation OR every stru in DIR]\n                \
                      [Give the ..../pdb/structure\
/ dir]\n                                      [If \
value omitted, the pg gets it from the env variabl\
e PDB_DIR]\n           -netcompression_pg.........\
[gunzip]\n           -is_pdb_name..........name.[R\
eturns 1 if the name is a PDB ID, 0 otherwise]\n  \
         -model_type...........name.[Returns the m\
odel type if valid PDB name]\n           -is_relea\
sed_pdb_name name.[Returns 1 if the name correspon\
ds to a released PDB file]\n           -get_pdb_ch\
ains.....name...[Returns the list of chains corres\
ponding to the entry]\n           -get_pdb_id.....\
....name...[Returns the PDB id within the provided\
 pdb file]\n           -get_fugue_name.....name...\
[Turns a name into a name valid for fugue]\n      \
                                [Uses the netaddre\
ss to do so]\n	   -chain......FIRST..........[Extr\
act the first chain only]\n		       A B C.........\
.[Extract Several chains if needed]\n		       ALL.\
...........[Extract all the chains]	\n           -\
ligand.....ALL............[Extract the ligands in \
the chain (HETATM)]\n                       <name1\
>,<name2>[Extract All the named lignds]\n	   -liga\
nd_only...............[Extract only the ligands]\n\
           -ligand_list...............[Extract the\
 list of ligands]\n	   -coor.......<start>..<end>.\
[Coordinates of the fragment to extract]\n			     \
         [Omit end to include the Cter]\n         \
  -num........absolute.......[absolute: relative t\
o the seq] \n                       file..........\
.[file: relative to file]\n           -num_out....\
new............[new: start 1->L]\n                \
       old............[old: keep the file coordina\
tes]\n           -delete.....<start>..<end>.[Delet\
e from residue start to residue end]\n	   -atom...\
....CA.............[Atoms to include, ALL for all \
of them]\n		       CA O N.........[Indicate severa\
l atoms if needed]\n	   -code.......3.............\
.[Use the 1 letter code or the 3 letters code]\n	 \
  -mode.......raw............[Output original pdb \
file]\n                       pdb............[Outp\
ut something that looks like pdb]\n		       fasta.\
.........[Output the sequences in fasta format]\n	\
	       simple.........[Output a format easy to pa\
rse in C ]\n            -seq_field..ATOM..........\
.[Field used to extract the sequence]\n		       SE\
QRES.........[Use the complete sequence]\n	   -seq\
.......................[Equivalent to  -mode fasta\
]\n	   -model......1..............[Chosen Model in\
 an NMR file]\n           -nodiagnostic...........\
...[Switches Error Messages off]\n           -debu\
g.....................[Sets the DEBUG ON]\n       \
    -no_remote_pdb_dir.........[Do not look for a \
remote file]\n           -cache_pdb...............\
..[Cache Value, default is $HOME/.t_coffee/cache, \
other values: NO<=> No cache]\n\n      Environemen\
t Variables\n           These variables can be set\
 from the environement\n           Command line va\
lues with the corresponding flag superseed evirone\
ment value\n           NO_REMOTE_PDB_DIR..........\
[Prevents the program from searching remote file: \
faster]\n           PDB_DIR....................[In\
dicates where PDB file must be fetched (localy)]\n\
\n	 PROBLEMS: please contact cedric.notredame\\@eu\
rope.com\\n\";\n	 exit ($EXIT_SUCCESS);\n}\n\n$np=\
0;\n$n_para=$#ARGV;\n$model=1;\n$pdb_dir=$ENV{'PDB\
_DIR'};if ($pdb_dir){$pdb_dir.=\"/\";}\n$debug=$EN\
V{'DEBUG_EXTRACT_FROM_PDB'};\n\n$no_remote_pdb_dir\
=$ENV{NO_REMOTE_PDB_DIR};\n$HOME=$ENV{'HOME'};\nif\
 ( $ENV{CACHE_4_TCOFFEE})\n{$cache=$ENV{CACHE_4_TC\
OFFEE};}\nelse\n{\n    $cache=\"$HOME/.t_coffee/ca\
che/\";\n}\n\n   \n$netaddress=\"http://www.rcsb.o\
rg/pdb/files/%%.pdb.gz\";\n$netcompression_pg=\"gu\
nzip\";\n$netcompression=\"gz\";\n\nforeach ($np=0\
; $np<=$n_para; $np++)\n  {        \n    $value=$A\
RGV[$np];\n   \n    if  ($np==0 && !($value=~/^-.*\
/))\n      { \n	$pdb_file= $ARGV[$np];\n      }\n \
   elsif ( !($value=~/^-.*/))\n      {\n	print \"@\
ARGV\";\n	die;\n      } \n    \n    elsif ($value \
eq \"-nodiagnostic\"){$nodiagnostic=1;}\n    elsif\
 ($value eq \"-force\")\n      {\n	$force_pdb=1;\n\
      }\n    elsif ($value eq \"-force_name\")\n  \
    {\n	$force_name=$ARGV[++$np];\n	$force_pdb=1;\\
n      }\n    \n    elsif ($value eq \"-is_pdb_nam\
e\")\n      {\n	$pdb_file= $ARGV[++$np];	\n	$is_pd\
b_name=1;	\n      } \n    elsif ($value eq \"-is_r\
eleased_pdb_name\")\n      {\n	$pdb_file= $ARGV[++\
$np];\n	\n	if (!$pdb_file){print \"0\";exit (EXIT_\
SUCCESS);}\n	$is_released_pdb_name=1;\n      }\n  \
  elsif ($value eq \"-model_type\")\n      {\n	$pd\
b_file= $ARGV[++$np];	\n	$model_type=1;\n      }\n\
    elsif ($value eq \"-debug\")\n{\n	$debug=1;\n}\
\n    elsif ($value eq \"-get_pdb_chains\")\n{\n	$\
pdb_file= $ARGV[++$np];\n	$get_pdb_chains=1;\n}\n \
   elsif ($value eq \"-get_pdb_ligands\")\n{\n	$ge\
t_pdb_ligands=1;\n}\n    \n    elsif ($value eq \"\
-get_pdb_id\")\n{\n	$pdb_file= $ARGV[++$np];\n	$ge\
t_pdb_id=1;\n	\n}\n    \n    elsif ( $value eq \"-\
get_fugue_name\")\n{\n	$pdb_file= $ARGV[++$np];\n	\
$get_fugue_name=1;\n}\n    elsif ( $value eq \"-in\
file\")\n{\n       $pdb_file= $ARGV[++$np];\n} \n \
   elsif ($value eq \"-netfile\")\n{\n	$netfile=1;\
\n	if ( !($ARGV[$np+1]=~/^-.*/)){$pdb_file= $ARGV[\
++$np];}\n}\n    elsif (  $value eq \"-num\")\n{\n\
       $numbering= $ARGV[++$np];\n}\n    elsif (  \
$value eq \"-num_out\")\n{\n       $numbering_out=\
 $ARGV[++$np];\n}\n    elsif ( $value eq \"-netadd\
ress\")\n{\n	$netadress=$ARGV[++$np];\n}\n     \n \
   elsif ( $value eq \"-netcompression\")\n{\n	 $n\
etcompression=$ARGV[++$np];\n}\n    elsif ( $value\
 eq \"-pdb_dir\")\n{\n	 if ( !($ARGV[$np+1]=~/^-.*\
/)){$pdb_dir= \"$ARGV[++$np]/\";}\n}\n     elsif (\
 $value eq \"-no_remote_pdb_dir\")\n{\n	$no_remote\
_pdb_dir=1;\n	if ( !($ARGV[$np+1]=~/^-.*/)){$pdb_d\
ir= \"$ARGV[++$np]/\";}\n}\n    elsif ( $value eq \
\"-cache\")\n{\n	$cache=$ARGV[++$np];\n}\n    \n  \
  elsif ($value eq \"-netcompression_pg\")\n{\n	  \
$netcompression_pg=$ARGV[++$np];\n}\n     elsif ($\
value eq \"-mode\")\n{\n       $MODE=$ARGV[++$np];\
\n}\n\n    elsif ( $value eq \"-model\")\n{\n     \
  $model= $ARGV[++$np];\n}\n    elsif ($value eq \\
"-seq_field\" )\n{\n       $seq_field= $ARGV[++$np\
];\n}   \n    elsif ($value eq \"-coor\" )\n{\n   \
    $start= $ARGV[++$np];\n  \n       if (($ARGV[$\
np+1] eq \"\") ||($ARGV[$np+1]=~/^-.*/)){$end=\"*\\
";} \n       else {$end=   $ARGV[++$np];}     \n  \
     $coor_set=1;\n}\n    elsif ($value eq \"-dele\
te\" )\n{\n       $delete_start= $ARGV[++$np];\n  \
     $delete_end= $ARGV[++$np];\n       $delete_se\
t=1;\n}\n    elsif  ($value eq \"-code\")\n{\n    \
   $code= $ARGV[++$np];\n}\n    elsif  ($value eq \
\"-no_hetatm\")\n{\n       $no_hetatm=1;\n}\n    e\
lsif ($value eq \"-chain\")\n{\n       while (!($A\
RGV[$np+1] eq \"\") &&!($ARGV[$np+1]=~/^-.*/))\n{\\
n	      ++$np;\n	      @c_chain=(@chain,  $ARGV[$n\
p]);\n	      $hc_chain{$ARGV[$np]}=$#c_chain+1;\n}\
           \n}\n    elsif ($value eq \"-atom\")\n{\
\n\n       while (!($ARGV[$np+1] eq \"\") && !($AR\
GV[$np+1]=~/^-.*/))\n{\n	      ++$np;\n	      $ato\
m[$n_atom++]=  $ARGV[$np];\n	      $atom_list{$ARG\
V[$np]}=1;	      \n} \n       \n}\n    elsif ( $va\
lue eq \"-unfold\")\n{\n	$unfold=1;\n}\n    elsif \
($value eq \"-seq\" ||$value eq \"-fasta\" )\n{\n \
      $MODE=\"fasta\";\n}\n    elsif ( $value eq \\
"-version\")\n{\n	print STDERR  \"\\nextract_from_\
pdb: Version $VersionTag\\n\";\n	&myexit ($EXIT_SU\
CCESS);\n}\n    elsif ( $value eq \"-ligand\")\n{\\
n	while (!($ARGV[$np+1] eq \"\") && !($ARGV[$np+1]\
=~/^-.*/))\n{\n	    ++$np;\n	    $ligand=1;\n	    \
$ligand_list{$ARGV[$np]}=1;	      \n} \n	$hc_chain\
{'LIGAND'}=1;\n}\n    elsif ( $value eq \"-ligand_\
only\")\n{\n	$ligand_only=1;\n}\n}\nif ( $debug)\n\
{\n    print STDERR \"\\n[DEBUG:extract_from_pdb] \
NO_REMOTE_PDB_DIR: $no_remote_pdb_dir\\n\";\n    p\
rint STDERR \"\\n[DEBUG:extract_from_pdb] PDB_DIR:\
 $pdb_dir\\n\";\n}\n\n\nif ( $is_pdb_name)\n  {\n \
   if (&remote_is_pdb_name($pdb_file))\n      {\n	\
print \"1\";\n      }\n    else\n      {\n	print \\
"0\";\n      }\n    exit ($EXIT_SUCCESS);\n  }\n\n\
if ( $is_released_pdb_name)\n  {\n    \n    if (&i\
s_released($pdb_file))\n      {\n	print \"1\";\n  \
    }\n    else\n      {\n	print \"0\";\n      }\n\
    exit ($EXIT_SUCCESS);\n  }\nif ($model_type)\n\
  {\n   \n    printf \"%s\", &pdb2model_type($pdb_\
file);\n    exit ($EXIT_SUCCESS);\n    \n  }\n    \
\n\nif (!$force_name)\n{\n    $pdb_file=~/([^\\/]*\
)$/;\n    $force_name=$1;\n}\n\n$local_pdb_file=$p\
db_file;\n\nif ( $debug){print STDERR \"\\n[DEBUG:\
 extract_from_pdb] Scan For $local_pdb_file\\n\";}\
\n\n$mem=$no_remote_pdb_dir;\n$no_remote_pdb_dir=1\
;\n$tmp_pdb_file=get_pdb_file ($local_pdb_file);\n\
\nif ( !-e $tmp_pdb_file || $tmp_pdb_file eq \"\")\
\n  {\n    $local_pdb_file=$pdb_file;\n    ($local\
_pdb_file, $suffix_chain)=&pdb_name2name_and_chain\
($local_pdb_file);\n\n    if ($local_pdb_file)\n  \
    {\n	if ( $debug){print STDERR \"\\nSplit $pdb_\
file into $local_pdb_file and $suffix_chain \\n\";\
}\n	$tmp_pdb_file=get_pdb_file ($local_pdb_file);\\
n	if ( $tmp_pdb_file ne \"\")\n	  {\n	    @c_chain\
=();\n	    @c_chain=($suffix_chain);\n	    %hc_cha\
in=();\n	    $hc_chain{$suffix_chain}=1;\n	  }\n  \
    }\n  }\n\n$no_remote_pdb_dir=$mem;\nif ($no_re\
mote_pdb_dir==0)\n  {\n    \n    if ( !-e $tmp_pdb\
_file || $tmp_pdb_file eq \"\")\n      {\n	\n	$loc\
al_pdb_file=$pdb_file;\n	($local_pdb_file, $suffix\
_chain)=&pdb_name2name_and_chain($local_pdb_file);\
\n	if ($local_pdb_file)\n	  {\n	    \n	    if ( $d\
ebug){print STDERR \"\\nSplit $pdb_file into $loca\
l_pdb_file and $suffix_chain \\n\";}\n	    \n	    \
$tmp_pdb_file=get_pdb_file ($local_pdb_file);    \\
n	    \n	    if ( $tmp_pdb_file ne \"\")\n	      {\
\n		@c_chain=();\n		@c_chain=($suffix_chain);\n		%\
hc_chain=();\n		$hc_chain{$suffix_chain}=1;\n	    \
  }\n	  }\n      }\n  }\n\nif ( $debug){print STDE\
RR \"\\n$pdb_file copied into ##$tmp_pdb_file##\\n\
\";}\n\nif ( !-e $tmp_pdb_file || $tmp_pdb_file eq\
 \"\")\n{\n	if ($is_pdb_name)\n{\n	    print \"0\\\
n\"; exit ($EXIT_SUCCESS);\n}\n	else\n{\n  \n	    \
print \"\\nEXTRACT_FROM_PDB: NO RESULT for $pdb_fi\
le\\n\";\n	    &myexit ($EXIT_SUCCESS);	\n}\n}\n\n\
\n\n\n%molecule_type=&pdbfile2chaintype($tmp_pdb_f\
ile);\nif ( $debug){print STDERR \"\\n\\tSequence \
Type determined\\n\";}\n\n$pdb_id=&get_pdb_id ($tm\
p_pdb_file);\nif ( $debug){print STDERR \"\\n\\tID\
: $pdb_id (for $tmp_pdb_file)\\n\";}\n\nif ( $pdb_\
id eq \"\"){$pdb_id=$force_name;}\n\n@f_chain=&get\
_chain_list ($tmp_pdb_file);\nif ( $debug){print S\
TDERR \"\\n\\tChain_list:@f_chain\\n\";}\n\nif ( $\
get_pdb_chains)\n{\n    print \"@f_chain\\n\";\n  \
  &myexit ($EXIT_SUCCESS);\n}\nif ( $get_pdb_ligan\
ds)\n{\n    %complete_ligand_list=&get_ligand_list\
 ($tmp_pdb_file);\n    print $complete_ligand_list\
{\"result\"};\n    &myexit ($EXIT_SUCCESS);\n}\n\n\
elsif ( $get_pdb_id ||$get_fugue_name )\n{\n    if\
    (@c_chain && $c_chain[0] eq \"FIRST\"){$pdb_id\
=$pdb_id.$f_chain[0];}\n    elsif (@c_chain && $c_\
chain[0] ne \" \"){$pdb_id=$pdb_id.$c_chain[0];}\n\
    \n    print \"$pdb_id\\n\";\n    &myexit ($EXI\
T_SUCCESS);\n    \n}\nelsif ( $is_pdb_name)\n{\n  \
  printf \"1\\n\";\n    &myexit ($EXIT_SUCCESS);\n\
}\n\n\n\n$structure_file=vtmpnam();\n\nif ( $debug\
){print STDERR \"\\n\\tCheck_point #1: $tmp_pdb_fi\
le  $structure_file\\n\";}\n\n$INFILE=vfopen (\"$t\
mp_pdb_file\", \"r\"); \nmy $TMP=vfopen (\"$struct\
ure_file\", \"w\");\n\n$print_model=1;\n$in_model=\
0;\n\nif ( $debug){print STDERR \"\\n\\tCheck_poin\
t #2\\n\";}\nwhile ( <$INFILE>)\n{\n  my $first_mo\
del=0;\n  $line=$_;\n\n  if ( !$first_model && ($l\
ine =~/^MODEL\\s*(\\d*)/))\n    {\n      $first_mo\
del=$1;\n      if ($model==1){$model=$first_model;\
}\n    }\n  \n  if (($line =~/^MODEL\\s*(\\d*)/))\\
n    {\n      if ($1==$model)\n	{\n	  $in_model=1;\
\n	  $print_model=1;\n	  $is_nmr=1;\n	}\n      els\
if ( $in_model==0)\n	{\n	  $print_model=0;\n	}\n  \
    elsif ( $in_model==1)\n	{\n	  last;\n	}\n    }\
\n  if ($print_model){print $TMP $line;}  \n}\nclo\
se ($TMP);\nclose ($INFILE);\n\nif ( $debug){print\
 STDERR \"\\n\\tCheck_point #3\\n\";}	\n\n  if ($n\
umbering eq \"\"){$numbering=\"absolute\";}\n  if \
($numbering_out eq \"\"){$numbering_out=\"new\";}\\
n\n  if ( $delete_set && $coor_set) {die \"-delete\
 and -coor are mutually exclusive, sorry\\n\";}\n \
 if ( $n_atom==0){$atom_list[$n_atom++]=\"ALL\";$a\
tom_list{$atom_list[0]}=1;}\n  if ( $seq_field eq \
\"\"){$seq_field=\"ATOM\";}\n  \n  if ( $MODE eq \\
"\"){$MODE=\"pdb\";}\n  elsif ( $MODE eq \"simple\\
" && $code==0){$code=1;}\n\n  if ( $code==0){$code\
=3;}\n\n\nif ($f_chain[0] eq \" \"){$hc_chain{' '}\
=1;$c_chain[0]=\" \";}\nelsif (!@c_chain){$hc_chai\
n{FIRST}=1;$c_chain[0]=\"FIRST\";}#make sure the f\
irst chain is taken by default\n\nif    ($hc_chain\
{ALL}) \n{\n      @c_chain=@f_chain;\n      foreac\
h $e (@c_chain){$hc_chain{$e}=1;}\n}\nelsif($hc_ch\
ain{FIRST})\n{\n	@c_chain=($f_chain[0]);\n	$hc_cha\
in{$f_chain[0]}=1;\n}\n\n\n$MAIN_HOM_CODE=&get_mai\
n_hom_code ($structure_file);\n$INFILE=vfopen ($st\
ructure_file, \"r\");\n\n\nif ( $MODE eq \"raw_pdb\
\" || $MODE eq \"raw\")\n{\n    while (<$INFILE>)\\
n{	print \"$_\";}\n    close ( $INFILE);\n    &mye\
xit($EXIT_SUCCESS);\n}    \nif ( $MODE eq \"raw4fu\
gue\" )\n{\n    while (<$INFILE>)\n{	\n	$l=$_;\n	i\
f ($l=~/^SEQRES/)\n{\n	    \n	    $c= substr($l,11\
,1);\n	    if ($hc_chain {$c}){print \"$l\";}\n}\n\
	elsif ( $l=~/^ATOM/)\n{\n	    $c=substr($l,21,1);\
\n	    if ($hc_chain {$c}){print \"$l\";}\n}\n}\n \
   close ( $INFILE);\n    &myexit($EXIT_SUCCESS);\\
n}    \n\nif ( $MODE eq \"pdb\")\n{\n\n    $read_h\
eader=0;\n    while (<$INFILE>) \n{\n	    $line=$_\
;\n	    if    ($line =~ /^HEADER/){print \"$line\"\
;$read_header=1;}\n}\n    close ($INFILE);\n\n    \
if (!$read_header)\n{\n	print \"HEADER    UNKNOWN \
                                00-JAN-00   $force\
_name\\n\";\n}\n\n    $INFILE=vfopen ($structure_f\
ile, \"r\");\n    \n    print \"COMPND   1 CHAIN:\\
";\n    $last=pop(@c_chain);\n    foreach $c ( @c_\
chain){ print \" $c,\";}\n    if ( $last eq \" \")\
{print \" NULL;\\n\";}\n    else \n{\n      print \
\" $last;\\n\";\n}\n    @c_chain=(@c_chain, $last)\
;\n    \n    print \"REMARK Output of the program \
extract_from_pdb (Version $VersionTag)\\n\";\n    \
print \"REMARK Legal PDB format not Guaranteed\\n\\
";\n    print \"REMARK This format is not meant to\
 be used in place of the PDB format\\n\";\n    pri\
nt \"REMARK The header refers to the original entr\
y\\n\";\n    print \"REMARK The sequence from the \
original file has been taken in the field: $seq_fi\
eld\\n\";\n    print \"REMARK extract_from_pdb, 20\
01, 2002, 2003, 2004, 2005 2006 (c) CNRS and Cedri\
c Notredame\\n\";   \n    if ( $coor_set)\n{\n    \
   print \"REMARK Partial chain: Start $start End \
$end\\n\";\n}\n    if ( $is_nmr)\n{\n       print \
\"REMARK NMR structure: MODEL $model\\n\";\n}\n   \
\n    if ( $n_atom!=0)\n{\n       print \"REMARK C\
ontains Coordinates of: \";\n       foreach $a (@a\
tom){print \"$a \";}\n       print \"\\n\";\n}  \n\
}\n\n\n\n\nmy $residue_index = -999;\nmy $old_c = \
\"TemporaryChain\";\n\nwhile (<$INFILE>) \n{\n	$li\
ne=$_;\n\n\n	if ($line =~ /^SEQRES/)\n{\n\n		@fiel\
d=/(\\S*)\\s*/g;\n\n		$c= substr($_,11,1);\n\n		\n\
		$l=$#field;\n		for ($a=4; $a<$#field ;)\n{\n			i\
f (!$onelett{$molecule_type{$c}}->{$field[$a]})\n{\
\n				splice @field, $a, 1;\n}\n			else \n{\n				$\
a++;\n}\n}\n	\n		if ( $c ne $in_chain)\n{\n			$pdb\
_chain_list[$n_pdb_chains]=$c;\n			$pdb_chain_len \
[$n_pdb_chains]=$len;\n			$in_chain=$c;\n			$n_pdb\
_chains++;\n}\n	\n		for ( $a=4; $a<$#field;$a++)\n\
{\n			$complete_seq{$c}[$complete_seq_len{$c}++]=$\
field[$a];\n}\n}\n    elsif ( $line=~/^ATOM/ || ($\
line=~/^HETATM/ && &is_aa(substr($line,17,3),subst\
r($line,21,1)) && !$no_hetatm))\n{\n\n	 \n    $RAW\
_AT_ID=$AT_ID=substr($line,12,4);\n	$RES_ID=&is_aa\
(substr($line,17,3),substr($line,21,1));\n	$CHAIN=\
substr($line,21,1);\n\n    $RES_NO=substr($line,22\
,4);\n	$HOM_CODE=substr ($line, 26, 1);\n	$TEMP=su\
bstr($line,60,6);\n	\n	$TEMP=~s/\\s//g;\n        $\
AT_ID=~s/\\s//g;\n	$RES_ID=~s/\\s//g;\n        $RE\
S_NO=~s/\\s//g;\n		\n	if ( $HOM_CODE ne $MAIN_HOM_\
CODE){next;}\n	elsif ( $already_read2{$CHAIN}{$RES\
_ID}{$AT_ID}{$RES_NO}){next;}\n	else{$already_read\
2{$CHAIN}{$RES_ID}{$AT_ID}{$RES_NO}=1;}\n	\n	\n	if\
 ($coor_set && $numbering eq \"file\" && $residue_\
index ne $RES_NO)\n{\n	    \n	    if ( $RES_NO<=$s\
tart){$real_start{$CHAIN}++;}\n	    if ( $RES_NO<=\
$end){$real_end{$CHAIN}++;}\n}\n	elsif ($numbering\
 eq \"absolute\")\n{\n	    $real_start{$CHAIN}=$st\
art;\n	    $real_end{$CHAIN}=$end;\n}\n\n        $\
KEY=\"ALL\";\n        if ( $CHAIN ne $in_atom_chai\
n)\n{\n	    \n	  $pdb_atom_chain_list[$n_pdb_atom_\
chains]=$c;\n	  $pdb_atom_chain_len [$n_pdb_atom_c\
hains]=$len;\n	  $in_atom_chain=$c;\n	  $n_pdb_ato\
m_chains++;\n}\n	\n	if ( $residue_index ne $RES_NO\
)\n{\n	     $residue_index = $RES_NO;\n	     $atom\
_seq{$CHAIN}[$atom_seq_len{$CHAIN}++]=$RES_ID;;\n}\
\n}\n\n}\nclose ($INFILE);\n\n\n\n\n\n\n$INFILE=vf\
open ($structure_file, \"r\");\nforeach $c (@c_cha\
in)\n{\n\n	if    ( $seq_field eq \"SEQRES\"){@pdb_\
seq=@{$complete_seq{$c}};}\n	elsif ( $seq_field eq\
 \"ATOM\")  {@pdb_seq=@{$atom_seq{$c}};}\n	\n\n	$f\
ull_length=$l=$#pdb_seq+1;\n		\n	if ( $real_end{$c\
}==\"*\"){$real_end{$c}=$full_length;}\n	if ( $coo\
r_set)\n{	   \n\n	   if ( $real_end{$c} < $l){spli\
ce @pdb_seq, $real_end{$c}, $l;}\n	   if ( $real_s\
tart{$c} < $l){splice @pdb_seq, 0, $real_start{$c}\
-1;}	  	   \n	   $l=$#pdb_seq;\n}\n\n	elsif ( $del\
ete_set)\n{\n	   splice @pdb_seq, $delete_start, $\
delete_end-$delete_start+1;\n	   $l=$#pdb_seq;\n}\\
n	\n	$new_fasta_name=\"$pdb_id$c\";\n	if ( $coor_s\
et)\n{\n	   if ( $n_pdb_chains==0){$new_fasta_name\
=\"$new_fasta_name$c\";}\n	   $new_fasta_name= $ne\
w_fasta_name.\"\\_$start\\_$end\";\n}\n	   \n	if (\
 $MODE eq \"pdb\")\n{\n	   $nl=1;\n	   $n=0;\n	   \
\n	   foreach $res ( @pdb_seq)\n		{\n		if ( !$n)\n\
		{\n		\n		 printf \"SEQRES %3d %1s %4d  \", $nl,$\
c, $l;\n		 $nl++;\n	}\n	     $res=~s/\\s//g;\n	   \
  \n	     if ($code==1){ printf \"%3s \",$onelett{\
$molecule_type{$c}}->{$res};}\n	     elsif  ($code\
==3){ printf \"%3s \",$res};\n	     \n	     $n++;	\
	  \n	     if ( $n==13){$n=0;print \"\\n\";}\n}\n	\
  if ( $n!=0){print \"\\n\"; $n=0;}\n}\n	elsif ( $\
MODE eq \"simple\")\n{\n	  print \"# SIMPLE_PDB_FO\
RMAT\\n\";\n	  if ( $new_fasta_name eq \" \"){$new\
_fasta_name=\"dummy_name\";}\n	  print \">$new_fas\
ta_name\\n\";\n\n	  foreach $res ( @pdb_seq)\n{\n	\
      print \"$onelett{$molecule_type{$c}}->{$res}\
\";\n}\n	  print \"\\n\";\n}\n	elsif ( $MODE eq \"\
fasta\")\n{\n	  $n=0;\n	  print \">$new_fasta_name\
\\n\";\n	  \n	  foreach $res ( @pdb_seq)\n{\n\n	  \
    print \"$onelett{$molecule_type{$c}}->{$res}\"\
;\n              $n++;\n	      if ( $n==60){print \
\"\\n\"; $n=0;}\n}\n	  print \"\\n\"; \n}\n}\n\nif\
 ( $MODE eq \"fasta\")\n{\n     &myexit($EXIT_SUCC\
ESS);\n  \n}\n\n  \n  $charcount=0;\n  $inchain=\"\
BEGIN\";\n  $n=0;\n  while (<$INFILE>) \n{\n    $l\
ine=$_;\n     \n    if ($line =~/^ATOM/  ||  ($lin\
e=~/^HETATM/))\n{\n	$line_header=\"UNKNWN\";\n	$RE\
S_ID=substr($line,17,3);\n	$chain = substr($line,2\
1,1);\n\n	if ($line =~/^ATOM/)\n{\n	    $line_head\
er=\"ATOM\";\n	    $RES_ID=(&is_aa($RES_ID,$chain)\
)?&is_aa($RES_ID,$chain):$RES_ID;\n}\n	elsif ($lin\
e=~/^HETATM/ && ($ligand_list {$RES_ID} ||$ligand_\
list {'ALL'} || !&is_aa($RES_ID,$chain)))\n{\n	   \
 $line_header=\"HETATM\";\n}\n	elsif ($line=~/^HET\
ATM/ && (&is_aa($RES_ID,$chain) && !$no_hetatm))\n\
{\n	    $line_header=\"ATOM\";\n	    $RES_ID=&is_a\
a($RES_ID,$chain);\n}\n	else\n{\n	    next;\n}\n\n\
	\n\n	$X=substr($line,30,8);     \n	$Y=substr($lin\
e,38,8);\n	$Z=substr($line,46,8);\n	$TEMP=substr($\
line,60,6);\n	\n	$RAW_AT_ID=$AT_ID=substr($line,12\
,4);\n	$CHAIN=substr($line,21,1);\n	$RES_NO=substr\
($line,22,4);\n	$HOM_CODE=substr ($line, 26, 1);\n\
	\n	$X=~s/\\s//g;\n	$Y=~s/\\s//g;\n	$Z=~s/\\s//g;\\
n	$TEMP=~s/\\s//g;\n	\n	$AT_ID=~s/\\s//g;\n	$RES_I\
D=~s/\\s//g;\n	$RES_NO=~s/\\s//g;\n\n	\n	if ( $HOM\
_CODE ne $MAIN_HOM_CODE){next;}\n	elsif ( $already\
_read{$CHAIN}{$RES_ID}{$AT_ID}{$RES_NO}){next;}\n	\
else{$already_read{$CHAIN}{$RES_ID}{$AT_ID}{$RES_N\
O}=1;}\n	\n	$KEY=\"ALL\";\n\n      	if ( $RES_NO =\
=0){$start_at_zero=1;}\n\n	$RES_NO+=$start_at_zero\
;    \n	\n	if ( $current_chain ne $CHAIN)\n{\n	   \
 $current_chain=$CHAIN;\n	    $pos=$current_residu\
e=0;\n	    $offset=($coor_set)?($real_start{$CHAIN\
}-1):0;\n	    if    ( $seq_field eq \"SEQRES\"){@r\
ef_seq=@{$complete_seq{$CHAIN}};}\n	    elsif ( $s\
eq_field eq \"ATOM\")  {@ref_seq=@{$atom_seq{$CHAI\
N}};}\n}\n	\n	if ($current_residue != $RES_NO)\n{\\
n	    $current_residue=$RES_NO;\n	    if    ( $seq\
_field eq \"SEQRES\"){$pos=$current_residue;}\n	  \
  elsif ( $seq_field eq \"ATOM\"){$pos++;}\n}\n	\n\
	\n	if ($n_atom==0 || $atom_list{$AT_ID}==1 || $at\
om_list{$KEY}==1)\n{ 	\n	    \n	    $do_it=(!@c_ch\
ain || $hc_chain{$CHAIN} ||$hc_chain{'LIGAND'} );\\
n	    \n	    $do_it= ($do_it==1) && ($coor_set==0 \
||($pos>=$real_start{$CHAIN} && $pos<=$real_end{$C\
HAIN}));\n	    $do_it= ($do_it==1) && ($delete_set\
==0 || $pos<$delete_start ||$pos>$delete_end );\n	\
    if ($ligand==0 && $line_header eq \"HETATM\" )\
{$do_it=0;}\n	    if ($ligand_only==1 && $line_hea\
der eq \"ATOM\" ){$do_it=0;}\n	    if ($ligand==1 \
&& $line_header eq \"HETATM\" && $ligand_list{$RES\
_ID}==0 && $ligand_list{\"ALL\"}==0){$do_it=0;} \n\
	    \n	    \n	    if ( $do_it)\n{\n		$n++;\n		$ou\
t_pos=$pos;\n		\n	       if ( $delete_set)\n{\n		 \
 if ( $out_pos< $delete_start){;}\n		  else {$offs\
et=$delete_end-$delete_start;}\n}       \n	       \
\n	       if ( $numbering_out eq \"new\"){$out_pos\
-=$offset;}\n	       elsif ( $numbering_out eq \"o\
ld\"){$out_pos=$RES_NO;}\n	       \n       \n	    \
   \n	       if ( $code==1){$RES_ID=$onelett{$mole\
cule_type{$c}}->{$RES_ID};}\n	    \n	       if ($u\
nfold)\n{\n		   $unfolded_x+=5;\n		   $X=$unfolded\
_x;\n		   $Y=0;\n		   $Z=0;\n		   $float=1;\n}\n	 \
      else\n{\n		   $float=3;\n}\n\n	       if ( $\
MODE eq \"pdb\")\n{\n		   printf \"%-6s%5d %-4s %3\
s %s%4d    %8.3f%8.3f%8.3f  1.00 %5.2f\\n\",$line_\
header, $n, $RAW_AT_ID,$RES_ID,$CHAIN,$out_pos, $X\
, $Y, $Z,$TEMP;		  \n}\n	       elsif ( $MODE eq \\
"simple\")\n{\n		    if ( $RES_ID eq \"\"){$RES_ID\
=\"X\";}\n		  printf \"%-6s %5s %s %2s %4d    %8.3\
f %8.3f %8.3f\\n\",$line_header, $AT_ID, $RES_ID,(\
$CHAIN eq\"\" || $CHAIN eq \" \")?\"A\":$CHAIN,$ou\
t_pos, $X, $Y, $Z,$TEMP;\n}\n\n}\n}\n}\n}\nprint \\
"\\n\";\nclose($INFILE);\n\n\nif ( $error ne \"\")\
 \n{$error=$error.\"\\nDiagnostic:    SEQRES and t\
he residues in ATOM are probably Incompatible\\n\"\
;\n    $error=$error.  \"Recomendation: Rerun with\
 '-fix 1' in order to ignore the SEQRES sequences\\
\n\";\n}\nif (!$nodiagnostic){print STDERR $error;\
}\n&myexit ( $EXIT_SUCCESS);\n\nsub get_pdb_entry_\
type_file\n  {\n    my $cache_file=\"$cache/pdb_en\
try_type.txt\";\n    my $env_file  = $ENV{\"PDB_EN\
TRY_TYPE_FILE\"};\n    my $pdb_file  =\"$ENV{'PDB_\
DIR'}/derived_data/pdb_entry_type.txt\";\n    \n  \
  \n    if (-z $cache_file){unlink ($cache_file);}\
#will get updated\n    if (-z $env_file){$env_file\
=\"\";}    #cannot update\n    if (-z $pdb_file){$\
pdb_file=\"\";}    #cannot update\n    \n    if   \
 (-e $env_file){return $env_file;} #env wins: user\
 decides\n    elsif (-e $pdb_file){return $pdb_fil\
e;} #local database wins: network file may be out \
of sync\n    elsif ($no_remote_pdb_dir==1)\n      \
{\n	if (-e $cache_file){return $cache_file;}\n	els\
e\n	  {add_warning($$,$$,\"PDB_ENTRY_TYPE_FILE mus\
t be set to the location of <pdb>/derived_data/pdb\
_entry_type.txt when using NO_REMOTE_PDB_DIR=1\");\
\n	   return \"\";\n	 }\n      }\n    else #update\
 can only take place if the file lives in cache\n \
     {\n	my $new_file;\n	if (!-e $cache_file || (-\
M $cache_file)>1)\n	  {\n	    $new_file=vtmpnam();\
\n	    &url2file(\"ftp://ftp.wwpdb.org/pub/pdb/der\
ived_data/pdb_entry_type.txt\", $new_file);\n	    \
if ( !-z $new_file){system (\"mv $new_file $cache_\
file\"); unlink ($new_file); $new_file=$cache_file\
;}\n	    else {unlink($new_file);}\n	  }\n	else\n	\
  {\n	    $new_file=$cache_file;\n	  }\n	\n	if (!-\
e $cache_file && !-e $new_file)\n	  {\n	    add_wa\
rning($$,$$,\"Could not download ftp://ftp.wwpdb.o\
rg/pub/pdb/derived_data/pdb_entry_type.txt\");\n	 \
   return \"\";\n	  }\n	elsif (-e $cache_file && !\
-e $new_file)\n	  {\n	    my $m=(-M $cache_file);\\
n	    add_warning($$,$$,\"Could not update file ft\
p://ftp.wwpdb.org/pub/pdb/derived_data/pdb_entry_t\
ype.txt. Older Version [$cache_file]($m Month(s) o\
ld) will be used instead\");\n	    return $cache_f\
ile;\n	  }\n	else\n	  {\n	    return $new_file;\n	\
  }\n      }\n  }\n\n\n\nsub get_unrealeased_file\\
n  {\n    my $cache_file=\"$cache/unrealeased.xml\\
";\n    my $env_file  = $ENV{\"PDB_UNREALEASED_FIL\
E\"};\n    my $pdb_file  =\"$ENV{'PDB_DIR'}/derive\
d_data/unrealeased.xml\";\n    \n    \n    if ($en\
v_file eq \"NO\" || $env_file eq \"No\" || $env_fi\
le eq \"no\" || $env_file eq \"0\"){return \"NO\";\
}\n\n    if (-z $cache_file){unlink ($cache_file);\
}#will get updated\n    if (-z $env_file){unlink($\
env_file);}     #will update\n    if (-z $pdb_file\
){$pdb_file=\"\";}          #cannot update\n    \n\
    if    (-e $env_file){return $env_file;} #env w\
ins: user decides\n    elsif (-e $pdb_file){return\
 $pdb_file;} #local database wins: network file ma\
y be out of sync\n    elsif ($no_remote_pdb_dir==1\
)        \n      {\n	if (-e $cache_file){return $c\
ache_file;}\n	elsif ( $env_file && ! -e $env_file)\
\n	  {\n	    &url2file(\"http://www.rcsb.org/pdb/r\
est/getUnreleased\",$env_file);\n	    if ( -e $env\
_file && !-z $env_file){return $env_file;}\n	  }\n\
	else\n	  {\n	    add_warning($$,$$,\"UNREALEASED_\
FILE must be set to the location of your unrealeas\
ed.xml file as downloaded from http://www.rcsb.org\
/pdb/rest/getUnreleased when using NO_REMOTE_PDB_D\
IR=1\");\n	    return \"\";\n	  }\n      }\n    el\
se #update can only take place if the file lives i\
n cache\n      {\n	my $new_file=vtmpnam ();\n	if (\
!-e $cache_file || (-M $cache_file)>1)\n	  {\n	   \
 &url2file(\"http://www.rcsb.org/pdb/rest/getUnrel\
eased\",$new_file);\n	    if ( !-z $new_file){syst\
em (\"mv $new_file $cache_file\"); unlink ($new_fi\
le); $new_file=$cache_file;}\n	    else {unlink($n\
ew_file);}\n	  }\n	else\n	  {\n	    $new_file=$cac\
he_file;\n	  }\n	\n	if (!-e $cache_file && !-e $ne\
w_file)\n	  {\n	    add_warning($$,$$,\"Could not \
download http://www.rcsb.org/pdb/rest/getUnrelease\
d\");\n	    return \"\";\n	  }\n	elsif (-e $cache_\
file && !-e $new_file)\n	  {\n	    my $m=(-M $cach\
e_file);\n	    add_warning($$,$$,\"Could not updat\
e file http://www.rcsb.org/pdb/rest/getUnreleased.\
 Older Version [$cache_file]($m Month(s) ) will be\
 used\");\n	    return $cache_file;\n	  }\n	else\n\
	  {\n	    return $new_file;\n	  }\n      }\n  }\n\
\nsub is_released \n  {\n    my ($r);\n    my $in=\
@_[0];\n    my $name=&remote_is_pdb_name ($in);\n \
   my $hold=&remote_is_on_hold($in);\n    \n    $r\
=($name && !$hold)?1:0;\n    return $r;\n  }\n\nsu\
b remote_is_pdb_name \n  {\n    my $in=@_[0];\n   \
 my ($pdb);\n    my ($value,$value1,$value2);\n   \
 my $max=2;\n    \n    \n    \n    my $ref_file=&g\
et_pdb_entry_type_file();\n    \n    if ( $in=~/[^\
\\w\\d\\:\\_]/){return 0;}\n    elsif (!-e $ref_fi\
le)\n      {\n	add_warning ($$,$$,\"Cannot find pd\
b_entry_type.txt;  $in is assumed to be valid; add\
 ftp://ftp.wwpdb.org/pub/pdb/derived_data/pdb_entr\
y_type.txt in $cache to automatically check name s\
tatus\");\n	return 1;\n      }\n    else\n      {\\
n	$pdb=substr ($in,0, 4);\n	chomp(($value1=`grep -\
c $pdb $ref_file`));\n	$pdb=lc($pdb);\n	chomp(($va\
lue2=`grep -c $pdb $ref_file`));\n	$value=($value1\
 || $value2)?1:0;\n	$value=($value>0)?1:0;\n	\n	re\
turn $value;\n      }\n  }\n\n\n\nsub pdb2model_ty\
pe\n{\n    my $in=@_[0];\n    my ($ref_file, $pdb)\
;\n    my ($value, $ret);\n\n    if ( $in=~/[^\\w\\
\d\\:\\_]/){return 0;}\n    $ref_file=&get_pdb_ent\
ry_type_file();\n    if (!-e $ref_file)\n      {\n\
	add_warning ($$,$$,\"Cannot find pdb_entry_type.t\
xt;  $in is assumed to be diffraction; add ftp://f\
tp.wwpdb.org/pub/pdb/derived_data/pdb_entry_type.t\
xt in $cache to check name status\");\n	return \"d\
iffraction\";\n      }\n    else\n      {\n	$pdb=s\
ubstr ($in,0, 4);\n	$pdb=lc($pdb);\n	\n	chomp(($va\
lue=`grep $pdb $ref_file`));\n	\n	$value=~/^\\S+\\\
s+\\S+\\s+(\\S+)/;\n	$ret=$1;\n	if ( $ret eq\"\"){\
return \"UNKNOWN\";}\n	\n	return $ret;\n      }\n \
 }\nsub remote_is_on_hold\n  {\n    my $in=@_[0];\\
n    my ($ref_file, $pdb);\n    my ($value1, $valu\
e2,$value);\n    \n\n\n    \n    $ref_file=&get_un\
realeased_file();\n    if ($ref_file eq \"NO\"){re\
turn 0;}\n\n\n    if ($no_remote_pdb==1){return 0;\
}\n    if ( $in=~/[^\\w\\d\\:\\_]/){return 0;}\n  \
  \n    $ref_file=&get_unrealeased_file();\n    if\
 (!-e $ref_file)\n      {\n	add_warning ($$,$$,\"C\
annot find unrealeased.xml;  $in is assumed to be \
released;\");\n	return 1;\n      }\n    \n    $pdb\
=substr ($in,0, 4);\n    chomp(($value1=`grep -c $\
pdb $ref_file`));\n    $pdb=lc($pdb);\n    chomp((\
$value2=`grep -c $pdb $ref_file`));\n    $value=($\
value1 || $value2)?1:0;\n    $value=($value>0)?1:0\
;\n    return $value;\n  }\n\nsub is_pdb_file\n  {\
\n    my @arg=@_;\n    \n    if ( !-e $arg[0]){ret\
urn 0;}\n    \n    $F=vfopen ($arg[0], \"r\");\n  \
  while ( <$F>)\n      {\n	if (/^HEADER/)\n	  {\n	\
    close $F;\n	    return 1;\n	  }\n	elsif ( /^SE\
QRES/)\n	  {\n	    close $F;\n	    return 1;\n	  }\
\n	elsif ( /^ATOM/)\n	  {\n	    close $F;\n	    re\
turn 1;\n	  }\n      }\n    return 0;\n  }\nsub ge\
t_pdb_id\n{\n    my $header_file=@_[0];\n    my $i\
d;\n    my $F= new FileHandle;\n    \n    \n    $F\
=vfopen (\"$header_file\", \"r\");\n\n    while ( \
<$F>)\n      {\n	if ( /HEADER/)\n	  {\n	    if ($d\
ebug){print \"$_\";}\n	    $id=substr($_,62,4 );\n\
	    return $id;\n	  }\n      }\n    close ($F);\n\
    \n    return \"\";\n}\n\nsub get_ligand_list\n\
{\n    my $pdb_file=@_[0];\n    my $chain;\n    my\
 $ligand;\n    my %complete_ligand_list;\n    \n\n\
    $F=vfopen ($pdb_file, \"r\");\n    while ( <$F\
>)\n{\n	if ( /^HETATM/)\n{\n	    $line=$_;\n	    $\
chain=substr($line,21,1);\n	    $ligand=substr($li\
ne,17,3);\n	    \n	    if (!$complete_ligand_list{\
$chain}{$ligand})\n{\n		\n		$complete_ligand_list{\
\"result\"}.=\"CHAIN $chain LIGAND $ligand\\n\";\n\
		$complete_ligand_list{$chain}{$ligand}=1;\n}\n}\\
n}\n    close ($F);\n    return %complete_ligand_l\
ist;\n}\n\nsub get_chain_list \n{\n    my $header_\
file;\n    my @chain_list;\n    my @list;\n    my \
$n_chains;\n    my %chain_hasch;\n    my $pdb_file\
=@_[0];\n    my $c;\n    my %hasch;\n    my $chain\
;\n  \n    \n    $F=vfopen ($pdb_file, \"r\");\n  \
  while ( <$F>)\n{\n\n\n	if (/SEQRES\\s+\\d+\\s+(\\
\S+)/)\n	  {\n	    $chain = substr($_,11,1);$chain\
=~s/\\s//g;if ( $chain eq \"\"){$chain=\" \";}\n	 \
   if (!$hasch{$chain}){$hasch{$chain}=1;push @cha\
in_list, $chain;}\n	  }\n	if (/^ATOM/ || /^HETATM/\
)\n	  {\n	    $chain = substr($_,21,1); $chain=~s/\
\\s//g;if ( $chain eq \"\"){$chain=\" \";}\n	    i\
f (!$hasch{$chain}){$hasch{$chain}=1;push @chain_l\
ist, $chain;}\n	  }\n      }\n\n\nclose ($F);\nif \
(!@chain_list)\n  {\n    @chain_list=(\"A\");\n  }\
\n\n\nreturn @chain_list;\n}\n\nsub token_is_in_li\
st\n{\n\n    my @list=@_;\n    my $a;\n    \n    f\
or ($a=1; $a<=$#list; $a++)\n{\n	if ( $list[$a] eq\
 $list[0]){return $a;}\n}\n}\n\nsub pdb_name2name_\
and_chain \n{\n    my $pdb_file=@_[0];\n    my $pd\
b_file_in;\n    my @array;\n    my $chain;\n    my\
 $c;\n\n    $pdb_file_in=$pdb_file;\n\n    $pdb_fi\
le=~/^(.{4})/;$pdb_id=$1;\n    @array=($pdb_file=~\
/([\\w])/g);\n  \n  \n    $chain=uc ($array[4]);\n\
    $chain=($chain eq \"\")?\"FIRST\":$chain;\n   \
 \n    return ( $pdb_id, $chain);\n\n    if ( $#ar\
ray==3){return ($pdb_id, \"FIRST\");}\n    elsif (\
 $#array<4){ return ($pdb_id, \"\");}\n    else {r\
eturn ( $pdb_id, $chain);}\n      \n    \n    \n}\\
nsub get_main_hom_code \n{\n    my $pdb_file=@_[0]\
;\n    my %hom, $n, $best, $best_h;\n    open (F, \
$pdb_file);\n    while (<F>)\n{\n	if ( $_=~/^ATOM/\
)\n{\n	    $h=substr ($_,26, 1);\n	    $n=++$hom{$\
h};\n	    if ($n>$best)\n{\n		$best=$n;\n		$best_h\
=$h;\n}\n}\n}\n    close (F);\n    return $best_h;\
\n}\n\n\nsub get_pdb_file \n{\n    my ($pdb_file_i\
n)=(@_);\n    my $result;\n    my @letter;\n    my\
 @chain;\n    my $v;\n    my $pdb_file=$pdb_file_i\
n;\n\n    $pdb_file=($pdb_file_in=~/\\S+_S_(\\S+)/\
)?$1:$pdb_file_in;\n    \n    if ($no_remote_pdb_d\
ir==0)\n      {\n	$no_remote_pdb_dir=1;\n	$result=\
get_pdb_file3 ($pdb_file);\n	$no_remote_pdb_dir=0;\
\n	if ( $result){return $result;}\n	else\n	  {\n	 \
   \n	    lc ($pdb_file);\n	    $result=get_pdb_fi\
le3($pdb_file);\n	    return  $result;\n	  }\n    \
  }\n    else\n      {\n	return get_pdb_file3 ($pd\
b_file);\n      }\n    \n  }\n\nsub get_pdb_file3 \
\n{\n    my $pdb_file_in=@_[0];\n    my $result;\n\
    my @letter;\n    my @chain;\n    my $lcfile;\n\
    my $ucfile;\n    my $pdb_file=$pdb_file_in;\n \
   \n    $lcfile=lc $pdb_file;\n    $ucfile=uc $pd\
b_file;\n\n    if ( ($result=get_pdb_file2 ($pdb_f\
ile))){return $result;}\n    \n\n    if ($lcfile n\
e $pdb_file && ($result=get_pdb_file2 ($lcfile))){\
return $result;}\n    if ($ucfile ne $pdb_file && \
($result=get_pdb_file2 ($ucfile))){return $result;\
}\n    \n   \n    \n    return \"\";\n}\nsub get_p\
db_file2\n{\n    my $pdb_file=@_[0];\n    my $retu\
rn_value;\n    \n    $return_value=\"\";\n    \n  \
  if ( ($result=get_pdb_file1 ($pdb_file))){$retur\
n_value=$result;}\n    elsif ( !($pdb_file=~/\\.pd\
b/) && !($pdb_file=~/\\.PDB/))\n{\n	if ( ($result=\
get_pdb_file1 (\"$pdb_file.pdb\"))){$return_value=\
$result;}\n	elsif ( ($result=get_pdb_file1 (\"$pdb\
_file.PDB\"))){$return_value=$result;}\n\n	elsif (\
 ($result=get_pdb_file1 (\"pdb$pdb_file.pdb\"))){$\
return_value=$result;}	\n	elsif ( ($result=get_pdb\
_file1 (\"pdb$pdb_file.PDB\"))){$return_value=$res\
ult;}\n	elsif ( ($result=get_pdb_file1 (\"PDB$pdb_\
file.PDB\"))){$return_value=$result;}\n	elsif ( ($\
result=get_pdb_file1 (\"PDB$pdb_file.pdb\"))){$ret\
urn_value=$result;}\n	\n	\n	elsif ( ($result=get_p\
db_file1 (\"$pdb_file.ent\"))){$return_value=$resu\
lt;}\n	elsif ( ($result=get_pdb_file1 (\"pdb$pdb_f\
ile.ent\"))){$return_value=$result;}\n	elsif ( ($r\
esult=get_pdb_file1 (\"PDB$pdb_file.ent\"))){$retu\
rn_value=$result;}\n\n	elsif ( ($result=get_pdb_fi\
le1 (\"$pdb_file.ENT\"))){$return_value=$result;}\\
n	elsif ( ($result=get_pdb_file1 (\"pdb$pdb_file.E\
NT\"))){$return_value=$result;}\n	elsif ( ($result\
=get_pdb_file1 (\"PDB$pdb_file.ENT\"))){$return_va\
lue=$result;}\n	\n	\n	\n}\n    return $return_valu\
e;\n}\n    \nsub get_pdb_file1\n{\n    my ($pdb_fi\
le)=(@_);\n    my $return_value;\n    \n\n    $ret\
urn_value=\"\";\n    if ( ($result=get_pdb_file0 (\
$pdb_file))){$return_value=$result;}\n    elsif ( \
($result=get_pdb_file0 (\"$pdb_file.Z\"))){$return\
_value=$result;}\n    elsif ( ($result=get_pdb_fil\
e0 (\"$pdb_file.gz\"))){$return_value=$result;}\n \
   elsif ( ($result=get_pdb_file0 (\"$pdb_file.GZ\\
"))){$return_value=$result;}\n    return $return_v\
alue;\n}\nsub get_pdb_file0 \n{ \n    my ($pdb_fil\
e, $attempt)=(@_);\n    my $pdb_file=@_[0];\n    m\
y $tmp_pdb_file;    \n    my $return_value;\n\n   \
 if ( !$attempt){$attempt=1;}\n    \n    $local_pd\
b_file=\"$pdb_file\";\n    if ( $local_pdb_file eq\
 \"\")\n{\n	$tmp_pdb_file=vtmpnam();\n	open F, \">\
$tmp_pdb_file\";\n	\n	while (<STDIN>){print F \"$_\
\";}\n	close (F);\n	\n	if (-e $tmp_pdb_file && &is\
_pdb_file ( $local_pdb_file))\n{return $tmp_pdb_fi\
le;}\n}\n\n    $local_pdb_file=\"$pdb_file\";\n   \
 &debug_print (\"\\nTry access local file: $local_\
pdb_file\");\n    \n    $local_pdb_file=&check_pdb\
_file4compression ($local_pdb_file);\n    if ( -e \
$local_pdb_file && (&is_pdb_file ($local_pdb_file)\
 || $force_pdb))\n{\n	&debug_print ( \"\\n\\tIs in\
 Current Dir\");\n	$tmp_pdb_file=vtmpnam();\n	`cp \
$local_pdb_file $tmp_pdb_file`;\n	return $tmp_pdb_\
file;\n}\n    else\n{\n	&debug_print (\"\\n\\tFile\
 Not in Current Dir\");\n}\n\n    if ($pdb_file=~/\
^pdb/||$pdb_file=~/^PDB/){$pdb_div=substr ($pdb_fi\
le, 4, 2);}\n    else\n{\n	  $pdb_div=substr ($pdb\
_file, 1, 2);\n}\n    $local_pdb_file=\"$pdb_dir/$\
pdb_div/$pdb_file\";\n    $local_pdb_file=&check_p\
db_file4compression ( $local_pdb_file);\n    &debu\
g_print (\"\\nTry access file From PDB_DIR: $local\
_pdb_file\");\n    if ($pdb_dir && -e $local_pdb_f\
ile && &is_pdb_file ($local_pdb_file))\n{\n	&debug\
_print ( \"\\n\\tIs in Local PDB DIR\");\n	$tmp_pd\
b_file=vtmpnam();\n	`cp $local_pdb_file $tmp_pdb_f\
ile`;\n	return $tmp_pdb_file;\n}\n\n    $local_pdb\
_file=\"$pdb_dir/$pdb_file\";\n    $local_pdb_file\
=&check_pdb_file4compression ( $local_pdb_file);\n\
    &debug_print (\"\\nTry access file From PDB_DI\
R: local_pdb_file\");\n    if ($pdb_dir && -e $loc\
al_pdb_file && &is_pdb_file ($local_pdb_file))\n{\\
n	&debug_print ( \"\\n\\tIs in Local PDB DIR\");\n\
	$tmp_pdb_file=vtmpnam();\n	`cp $local_pdb_file $t\
mp_pdb_file`;\n	return $tmp_pdb_file;\n}\n\n    $l\
ocal_pdb_file=\"$pdb_dir$pdb_file\";\n    $local_p\
db_file=&check_pdb_file4compression ( $local_pdb_f\
ile);\n    &debug_print (\"\\nTry access file From\
 PDB_DIR: $local_pdb_file\");\n    if ($pdb_dir &&\
 -e $local_pdb_file && &is_pdb_file ($local_pdb_fi\
le))\n{\n	&debug_print ( \"\\n\\tIs in Local PDB D\
IR\");\n	$tmp_pdb_file=vtmpnam();\n	`cp $local_pdb\
_file $tmp_pdb_file`;\n	return $tmp_pdb_file;\n}\n\
    else\n{&debug_print ( \"\\n\\tNot In Local Pdb\
 Dir\");}\n\n    if ($cache ne \"NO\" && $cache ne\
 \"no\")\n{\n\n	$local_pdb_file=\"$cache/$pdb_file\
\";\n	$local_pdb_file=&check_pdb_file4compression \
( $local_pdb_file);\n	&debug_print(\"\\nTry access\
 file From Cache: $local_pdb_file\");\n	if (-e $lo\
cal_pdb_file && &is_pdb_file ($local_pdb_file))\n{\
\n	    &debug_print ( \"\\n\\tIs in T-Coffee Cache\
\");\n	    $tmp_pdb_file=vtmpnam();\n	    `cp $loc\
al_pdb_file $tmp_pdb_file`;\n	    return $tmp_pdb_\
file;\n}\n	else{&debug_print ( \"\\n\\tNot in Cach\
e Dir\");}\n}\n\nif (!$no_remote_pdb_dir) \n  {\n \
   my $value=&is_released ($pdb_file);\n    my $re\
turn_value=\"\";\n    if ($value==1)\n      {\n	\n\
	&debug_print (\"\\n******************************\
***********************\\nTry Remote Access for $p\
db_file\");\n	$tmp_pdb_file=vtmpnam();\n	$netcomma\
nd=$netaddress;\n	$netcommand=~s/%%/$pdb_file/g;\n\
	&url2file(\"$netcommand\", \"$tmp_pdb_file.$netco\
mpression\");\n	&debug_print(\"\\nREMOTE: $netcomm\
and\\n\");\n	\n	$compressed_tmp_file_name=\"$tmp_p\
db_file.$netcompression\";\n	\n	if ($netcompressio\
n && -B $compressed_tmp_file_name && $attempt<5)\n\
	  {\n	    my $r;\n	    &debug_print (\"\\n\\tFile\
 Found Remotely\");\n	    if (($r=safe_system ( \"\
$netcompression_pg $compressed_tmp_file_name\")!=$\
EXIT_SUCCESS) && $attempts<5)\n	      {\n		&debug_\
print (\"\\n\\tProper Download Failed Try again\")\
;\n		unlink $compressed_tmp_file_name;\n		print \"\
\\nFailed to Download $compressed_tmp_file_name. N\
ew Attempt $attempt/5\\n\";\n		return &get_pdb_fil\
e0($pdb_file, $attempt+1);\n	      }\n	    elsif (\
$r== $EXIT_SUCCESS)\n	      {\n		&debug_print (\"\\
\n\\tProper Download Succeeded \");\n		$return_val\
ue=$tmp_pdb_file;\n	      }\n	    else\n	      {\n\
		&debug_print (\"\\n\\tProper Download Failed \")\
;\n		&debug_print (\"\\nFile Not Found Remotely\")\
;\n		unlink $compressed_tmp_file_name;\n	      }\n\
	  }\n	else\n	  {\n\n	    &debug_print (\"\\nFile \
Not Found Remotely\");\n	    unlink $compressed_tm\
p_file_name;\n	  }\n	#Update cache if required\n	i\
f ($cache ne \"no\" && $cache ne \"update\" && -e \
$return_value)\n	  {\n	    `cp $return_value $cach\
e/$pdb_file.pdb`;\n	    #`t_coffee -other_pg clean\
_cache.pl -file $pdb_file.pdb -dir $cache`;\n	  }\\
n      }\n    &debug_print (\"\\nRemote Download F\
inished\");\n    return $return_value;\n  }\nretur\
n \"\";\n}\n\nsub check_pdb_file4compression \n{\n\
    my $file=@_[0];\n    my $tmp;\n    my $r;\n   \
 \n    $tmp=&vtmpnam();\n    if (-e $tmp){unlink $\
tmp;}\n    \n    $file=~s/\\/\\//\\//g;\n    if   \
 (-B $file && ($file=~/\\.Z/)) {`cp $file $tmp.Z`;\
`rm $tmp`;`gunzip $tmp.Z $SILENT`;$r=$tmp;}\n    e\
lsif (-B $file && ($file=~/\\.gz/)){`cp $file $tmp\
.gz`;`gunzip $tmp.gz $SILENT`;return $r=$tmp;}\n  \
  elsif (-B $file ){`cp $file $tmp.gz`;`gunzip $tm\
p.gz $SILENT`;$r=$tmp;}\n    elsif ( -e $file ) {$\
r= $file;}\n    elsif ( -e \"$file.gz\" ){ `cp $fi\
le.gz $tmp.gz`;`gunzip     $tmp.gz $SILENT`;$r=$tm\
p;}    \n    elsif ( -e \"$file.Z\") {`cp $file.Z \
 $tmp.Z`; `gunzip $tmp.Z $SILENT`;$r=$tmp;}\n    e\
lse  {$r= $file;}\n\n    if ( -e \"$tmp.Z\"){unlin\
k \"$tmp.Z\";}\n    if ( -e \"$tmp.gz\"){unlink \"\
$tmp.gz\";}\n    \n    return $r;\n    \n}\n\n\n\n\
\n\n    \n\n\n\n\n\n\n\nsub vfopen \n{\n    my $fi\
le=@_[0];\n    my $mode=@_[1];\n    my $tmp;\n    \
my $F = new FileHandle;\n    \n    \n    $tmp=$fil\
e;\n	\n    \n    if ( $mode eq \"r\" && !-e $file)\
{ myexit(flush_error (\"Cannot open file $file\"))\
;}\n    elsif ($mode eq \"w\"){$tmp=\">$file\";}\n\
    elsif ($mode eq \"a\"){$tmp=\">>$file\";}\n   \
 \n    \n    open ($F,$tmp);\n    return $F;\n}\ns\
ub debug_print\n{\n    my $message =@_[0];\n    if\
 ($debug){print STDERR \"NO_REMOTE_PDB_DIR: $no_re\
mote_pdb_dir - $message [DEBUG:extract_from_pdb]\"\
;}\n    return;\n}\nsub is_aa \n{\n    my ($aa, $c\
hain) =@_;\n\n    my $one;\n    my $trhee;\n    \n\
    if ( $onelett{$molecule_type{$chain}}->{$aa} e\
q 'X' || !$onelett{$molecule_type{$chain}}->{$aa} \
){return '';}\n    else\n      {\n	$one=$onelett{$\
molecule_type{$chain}}->{$aa};\n\n	$three=$threele\
tt{$molecule_type{$chain}}->{$one};\n	\n\n	return \
$three;\n      }\n  }\n\n\n\n\n\nsub url2file\n{\n\
    my ($address, $out, $wget_arg, $curl_arg)=(@_)\
;\n    my ($pg, $flag, $r, $arg, $count);\n    \n \
   if (!$CONFIGURATION){&check_configuration (\"wg\
et\", \"INTERNET\", \"gzip\");$CONFIGURATION=1;}\n\
    \n    if (&pg_is_installed (\"wget\"))   {$pg=\
\"wget\"; $flag=\"-O\";$arg=$wget_arg;}\n    elsif\
 (&pg_is_installed (\"curl\")){$pg=\"curl\"; $flag\
=\"-o\";$arg=$curl_arg;}\n    return safe_system (\
\"$pg $flag$out $address >/dev/null 2>/dev/null\")\
;\n\n}\n\n\n\n\nsub pdbfile2chaintype\n  {\n    my\
 $file=@_[0];\n    my %ct;\n    my $F;\n    \n    \
$F=vfopen ($file, \"r\");\n    while (<$F>)\n     \
 {\n	my $line=$_;\n	if ($line =~/^ATOM/)\n	  {\n	 \
   my $C=substr($line,21,1);\n	    if (!$ct{$C})\n\
	      {	\n		my $r=substr($line,17,3);\n		$r=~s/\\\
s+//;\n		if (length ($r)==1){$ct{$C}=\"R\";}\n		el\
sif (length ($r)==2){$ct{$C}=\"D\";}\n		elsif (len\
gth ($r)==3){$ct{$C}=\"P\";}\n		else \n		  {\n		  \
  myexit(flush_error(\"ERROR: Could not read RES_I\
D field in file $file\"));\n		  }\n	      }\n	  }\\
n      }\n    close ($F);\n    return %ct;\n  }\n \
  \n    \n\n\n\nsub fill_threelett_RNA\n{\n\n	my %\
threelett=(\n	'A', '  A',\n	'T', '  T',\n	'U', '  \
U',\n	'C', '  C',\n	'G', '  G',\n	'I', '  I', #Ino\
sine\n	);\n	\n	return %threelett;\n\n}\n\n\nsub fi\
ll_onelett_RNA\n{\n	my   %onelett=(\n	'  A' => 'A'\
,\n	'  T' => 'T',\n	'  U' => 'U',\n	'  C' => 'C',\\
n	'  G' => 'G',\n	'CSL' => 'X',\n	'UMS' => 'X',\n	\
'  I' => 'I',\n	'A' => 'A',\n	'T' => 'T',\n	'U' =>\
 'U',\n	'C' => 'C',\n	'G' => 'G',\n	'I' => 'I',\n	\
);\n\n	return %onelett;\n\n}\n\n\nsub fill_onelett\
_DNA\n{\n	my   %onelett=(\n	' DA', 'A',\n	' DT', '\
T',\n	' DC', 'C',\n	' DG', 'G',\n	'DA', 'A',\n	'DT\
', 'T',\n	'DC', 'C',\n	'DG', 'G',\n	);\n\n	return \
%onelett;\n\n}\n\nsub fill_threelett_DNA\n{\n\n	my\
 %threelett=(\n	'A', ' DA',\n	'T', ' DT',\n	'C', '\
 DC',\n	'G', ' DG',\n	);\n\n	return %threelett;\n\\
n}\n\n\n\n\nsub fill_threelett_prot\n{  \n  my %th\
reelett;\n\n  %threelett=(\n'A', 'ALA',\n'C', 'CYS\
',\n'D', 'ASP',\n'E', 'GLU',\n'F', 'PHE',\n'G', 'G\
LY',\n'H', 'HIS',\n'I', 'ILE',\n'K', 'LYS',\n'L', \
'LEU',\n'N', 'ASN',\n'M', 'MET',\n'P', 'PRO',\n'Q'\
, 'GLN',\n'R', 'ARG',\n'S', 'SER',\n'T', 'THR',\n'\
V', 'VAL',\n'W', 'TRP',\n'Y', 'TYR',\n);\n\nreturn\
 %threelett;\n\n\n}\n\nsub fill_onelett_prot\n{\n \
   my %onelett;\n    \n    %onelett=(\n\n'10A', 'X\
',\n'11O', 'X',\n'12A', 'X',\n'13P', 'X',\n'13R', \
'X',\n'13S', 'X',\n'14W', 'X',\n'15P', 'X',\n'16A'\
, 'X',\n'16G', 'X',\n'1AN', 'X',\n'1AP', 'X',\n'1A\
R', 'X',\n'1BH', 'X',\n'1BO', 'X',\n'1C5', 'X',\n'\
1CU', 'X',\n'1DA', 'X',\n'1GL', 'X',\n'1GN', 'X',\\
n'1IN', 'X',\n'1LU', 'L',\n'1MA', 'X',\n'1MC', 'X'\
,\n'1MG', 'X',\n'1MZ', 'X',\n'1NA', 'X',\n'1NB', '\
X',\n'1NI', 'X',\n'1PA', 'A',\n'1PC', 'X',\n'1PE',\
 'X',\n'1PG', 'X',\n'1PI', 'A',\n'1PM', 'X',\n'1PN\
', 'X',\n'1PU', 'X',\n'1PY', 'X',\n'1UN', 'X',\n'2\
4T', 'X',\n'25T', 'X',\n'26P', 'X',\n'2AB', 'X',\n\
'2AM', 'X',\n'2AN', 'X',\n'2AP', 'X',\n'2AR', 'X',\
\n'2AS', 'D',\n'2BL', 'X',\n'2BM', 'X',\n'2CP', 'X\
',\n'2DA', 'X',\n'2DG', 'X',\n'2DP', 'X',\n'2DT', \
'X',\n'2EP', 'X',\n'2EZ', 'X',\n'2FG', 'X',\n'2FL'\
, 'X',\n'2FP', 'X',\n'2FU', 'X',\n'2GL', 'X',\n'2G\
P', 'X',\n'2HP', 'X',\n'2IB', 'X',\n'2IP', 'X',\n'\
2LU', 'L',\n'2MA', 'X',\n'2MD', 'X',\n'2ME', 'X',\\
n'2MG', 'X',\n'2ML', 'L',\n'2MO', 'X',\n'2MR', 'R'\
,\n'2MU', 'X',\n'2MZ', 'X',\n'2NO', 'X',\n'2NP', '\
X',\n'2OG', 'X',\n'2PA', 'X',\n'2PC', 'X',\n'2PE',\
 'X',\n'2PG', 'X',\n'2PH', 'X',\n'2PI', 'X',\n'2PL\
', 'X',\n'2PP', 'X',\n'2PU', 'X',\n'2SI', 'X',\n'2\
TB', 'X',\n'34C', 'X',\n'35G', 'X',\n'3AA', 'X',\n\
'3AD', 'X',\n'3AH', 'H',\n'3AN', 'X',\n'3AP', 'X',\
\n'3AT', 'X',\n'3BT', 'X',\n'3CH', 'X',\n'3CN', 'X\
',\n'3CO', 'X',\n'3CP', 'X',\n'3DR', 'X',\n'3EP', \
'X',\n'3FM', 'X',\n'3GA', 'X',\n'3GP', 'X',\n'3HB'\
, 'X',\n'3HC', 'X',\n'3HP', 'X',\n'3IB', 'X',\n'3I\
D', 'X',\n'3IN', 'X',\n'3MA', 'X',\n'3MB', 'X',\n'\
3MC', 'X',\n'3MD', 'D',\n'3MF', 'X',\n'3MP', 'X',\\
n'3MT', 'X',\n'3OL', 'X',\n'3PA', 'X',\n'3PG', 'X'\
,\n'3PO', 'X',\n'3PP', 'X',\n'3PY', 'X',\n'49A', '\
X',\n'4AB', 'X',\n'4AM', 'X',\n'4AN', 'X',\n'4AP',\
 'X',\n'4BA', 'X',\n'4BT', 'X',\n'4CA', 'X',\n'4CO\
', 'X',\n'4HP', 'X',\n'4IP', 'X',\n'4MO', 'X',\n'4\
MV', 'X',\n'4MZ', 'X',\n'4NC', 'X',\n'4NP', 'X',\n\
'4OX', 'X',\n'4PB', 'X',\n'4PN', 'X',\n'4PP', 'X',\
\n'4SC', 'X',\n'4SU', 'X',\n'4TB', 'X',\n'55C', 'X\
',\n'5AD', 'X',\n'5AN', 'X',\n'5AT', 'X',\n'5CM', \
'X',\n'5GP', 'X',\n'5HP', 'E',\n'5HT', 'X',\n'5IT'\
, 'X',\n'5IU', 'X',\n'5MB', 'X',\n'5MC', 'X',\n'5M\
D', 'X',\n'5MP', 'X',\n'5MU', 'X',\n'5NC', 'X',\n'\
5OB', 'X',\n'5PA', 'X',\n'5PV', 'X',\n'6AB', 'X',\\
n'6CT', 'X',\n'6HA', 'X',\n'6HC', 'X',\n'6HG', 'X'\
,\n'6HT', 'X',\n'6IN', 'X',\n'6MO', 'X',\n'6MP', '\
X',\n'6PG', 'X',\n'6WO', 'X',\n'70U', 'X',\n'7DG',\
 'X',\n'7HP', 'X',\n'7I2', 'X',\n'7MG', 'X',\n'7MQ\
', 'X',\n'7NI', 'X',\n'87Y', 'X',\n'8AD', 'X',\n'8\
BR', 'X',\n'8IG', 'X',\n'8IN', 'X',\n'8OG', 'X',\n\
'95A', 'X',\n'9AD', 'X',\n'9AM', 'X',\n'9AP', 'X',\
\n'9DG', 'X',\n'9DI', 'X',\n'9HX', 'X',\n'9OH', 'X\
',\n'9TA', 'X',\n'A12', 'X',\n'A15', 'X',\n'A23', \
'X',\n'A24', 'X',\n'A26', 'X',\n'A2G', 'X',\n'A2P'\
, 'X',\n'A32', 'X',\n'A3P', 'X',\n'A4P', 'X',\n'A5\
P', 'X',\n'A70', 'X',\n'A76', 'X',\n'A77', 'X',\n'\
A78', 'X',\n'A79', 'X',\n'A80', 'X',\n'A85', 'X',\\
n'A88', 'X',\n'A9A', 'X',\n'AA3', 'X',\n'AA4', 'X'\
,\n'AA6', 'X',\n'AAA', 'X',\n'AAB', 'X',\n'AAC', '\
X',\n'AAE', 'X',\n'AAG', 'R',\n'AAH', 'X',\n'AAM',\
 'X',\n'AAN', 'X',\n'AAP', 'X',\n'AAR', 'R',\n'AAS\
', 'X',\n'AAT', 'X',\n'ABA', 'X',\n'ABC', 'X',\n'A\
BD', 'X',\n'ABE', 'X',\n'ABH', 'X',\n'ABI', 'X',\n\
'ABK', 'X',\n'ABM', 'X',\n'ABN', 'X',\n'ABP', 'X',\
\n'ABR', 'X',\n'ABS', 'X',\n'ABU', 'X',\n'AC1', 'X\
',\n'AC2', 'X',\n'ACA', 'X',\n'ACB', 'D',\n'ACC', \
'C',\n'ACD', 'X',\n'ACE', 'X',\n'ACH', 'X',\n'ACI'\
, 'X',\n'ACL', 'R',\n'ACM', 'X',\n'ACN', 'X',\n'AC\
O', 'X',\n'ACP', 'X',\n'ACQ', 'X',\n'ACR', 'X',\n'\
ACS', 'X',\n'ACT', 'X',\n'ACV', 'V',\n'ACX', 'X',\\
n'ACY', 'X',\n'AD2', 'X',\n'AD3', 'X',\n'ADC', 'X'\
,\n'ADD', 'X',\n'ADE', 'X',\n'ADH', 'X',\n'ADI', '\
X',\n'ADM', 'X',\n'ADN', 'X',\n'ADP', 'X',\n'ADQ',\
 'X',\n'ADR', 'X',\n'ADS', 'X',\n'ADT', 'X',\n'ADU\
', 'X',\n'ADW', 'X',\n'ADX', 'X',\n'AE2', 'X',\n'A\
EA', 'X',\n'AEB', 'X',\n'AEI', 'D',\n'AEN', 'X',\n\
'AET', 'T',\n'AF1', 'X',\n'AF3', 'X',\n'AFA', 'D',\
\n'AFP', 'X',\n'AG7', 'X',\n'AGB', 'X',\n'AGF', 'X\
',\n'AGL', 'X',\n'AGM', 'R',\n'AGN', 'X',\n'AGP', \
'X',\n'AGS', 'X',\n'AGU', 'X',\n'AH0', 'X',\n'AH1'\
, 'X',\n'AHA', 'X',\n'AHB', 'D',\n'AHC', 'X',\n'AH\
F', 'X',\n'AHG', 'X',\n'AHH', 'X',\n'AHM', 'X',\n'\
AHO', 'X',\n'AHP', 'X',\n'AHS', 'X',\n'AHT', 'Y',\\
n'AHU', 'X',\n'AHX', 'X',\n'AI1', 'X',\n'AI2', 'X'\
,\n'AIB', 'X',\n'AIC', 'X',\n'AIM', 'X',\n'AIP', '\
X',\n'AIQ', 'X',\n'AIR', 'X',\n'AJ3', 'X',\n'AKB',\
 'X',\n'AKG', 'X',\n'AKR', 'X',\n'AL1', 'X',\n'AL2\
', 'X',\n'AL3', 'X',\n'AL4', 'X',\n'AL5', 'X',\n'A\
L6', 'X',\n'AL7', 'X',\n'AL8', 'X',\n'AL9', 'X',\n\
'ALA', 'A',\n'ALB', 'X',\n'ALC', 'X',\n'ALD', 'L',\
\n'ALE', 'X',\n'ALF', 'X',\n'ALG', 'X',\n'ALL', 'X\
',\n'ALM', 'A',\n'ALN', 'A',\n'ALO', 'T',\n'ALP', \
'X',\n'ALQ', 'X',\n'ALR', 'X',\n'ALS', 'X',\n'ALT'\
, 'A',\n'ALY', 'K',\n'ALZ', 'X',\n'AMA', 'X',\n'AM\
B', 'X',\n'AMC', 'X',\n'AMD', 'X',\n'AMG', 'X',\n'\
AMH', 'X',\n'AMI', 'X',\n'AML', 'X',\n'AMN', 'X',\\
n'AMO', 'X',\n'AMP', 'X',\n'AMQ', 'X',\n'AMR', 'X'\
,\n'AMS', 'X',\n'AMT', 'X',\n'AMU', 'X',\n'AMW', '\
X',\n'AMX', 'X',\n'AMY', 'X',\n'ANA', 'X',\n'ANB',\
 'X',\n'ANC', 'X',\n'AND', 'X',\n'ANE', 'X',\n'ANI\
', 'X',\n'ANL', 'X',\n'ANO', 'X',\n'ANP', 'X',\n'A\
NS', 'X',\n'ANT', 'X',\n'AOE', 'X',\n'AOP', 'X',\n\
'AP1', 'X',\n'AP2', 'X',\n'AP3', 'X',\n'AP4', 'X',\
\n'AP5', 'X',\n'AP6', 'X',\n'APA', 'X',\n'APB', 'X\
',\n'APC', 'X',\n'APE', 'F',\n'APF', 'X',\n'APG', \
'X',\n'APH', 'A',\n'API', 'X',\n'APL', 'X',\n'APM'\
, 'X',\n'APN', 'G',\n'APP', 'X',\n'APQ', 'X',\n'AP\
R', 'X',\n'APS', 'X',\n'APT', 'X',\n'APU', 'X',\n'\
APX', 'X',\n'APY', 'X',\n'APZ', 'X',\n'AQS', 'X',\\
n'AR1', 'X',\n'AR2', 'X',\n'ARA', 'X',\n'ARB', 'X'\
,\n'ARC', 'X',\n'ARD', 'X',\n'ARG', 'R',\n'ARH', '\
X',\n'ARI', 'X',\n'ARM', 'R',\n'ARN', 'X',\n'ARO',\
 'R',\n'ARP', 'X',\n'ARQ', 'X',\n'ARS', 'X',\n'AS1\
', 'R',\n'AS2', 'X',\n'ASA', 'D',\n'ASB', 'D',\n'A\
SC', 'X',\n'ASD', 'X',\n'ASE', 'X',\n'ASF', 'X',\n\
'ASI', 'X',\n'ASK', 'D',\n'ASL', 'X',\n'ASM', 'N',\
\n'ASO', 'X',\n'ASP', 'D',\n'ASQ', 'X',\n'ASU', 'X\
',\n'ATA', 'X',\n'ATC', 'X',\n'ATD', 'X',\n'ATF', \
'X',\n'ATG', 'X',\n'ATH', 'X',\n'ATM', 'X',\n'ATO'\
, 'X',\n'ATP', 'X',\n'ATQ', 'X',\n'ATR', 'X',\n'AT\
T', 'X',\n'ATY', 'X',\n'ATZ', 'X',\n'AUC', 'X',\n'\
AUR', 'X',\n'AVG', 'X',\n'AXP', 'X',\n'AYA', 'A',\\
n'AZ2', 'X',\n'AZA', 'X',\n'AZC', 'X',\n'AZD', 'X'\
,\n'AZE', 'X',\n'AZI', 'X',\n'AZL', 'X',\n'AZM', '\
X',\n'AZR', 'X',\n'AZT', 'X',\n'B12', 'X',\n'B1F',\
 'F',\n'B2A', 'A',\n'B2F', 'F',\n'B2I', 'I',\n'B2V\
', 'V',\n'B3I', 'X',\n'B3P', 'X',\n'B7G', 'X',\n'B\
96', 'X',\n'B9A', 'X',\n'BA1', 'X',\n'BAA', 'X',\n\
'BAB', 'X',\n'BAC', 'X',\n'BAF', 'X',\n'BAH', 'X',\
\n'BAI', 'X',\n'BAK', 'X',\n'BAL', 'A',\n'BAM', 'X\
',\n'BAO', 'X',\n'BAP', 'X',\n'BAR', 'X',\n'BAS', \
'X',\n'BAT', 'F',\n'BAY', 'X',\n'BAZ', 'X',\n'BB1'\
, 'X',\n'BB2', 'X',\n'BBA', 'X',\n'BBH', 'X',\n'BB\
S', 'X',\n'BBT', 'X',\n'BBZ', 'X',\n'BCA', 'X',\n'\
BCB', 'X',\n'BCC', 'X',\n'BCD', 'X',\n'BCL', 'X',\\
n'BCN', 'X',\n'BCR', 'X',\n'BCS', 'C',\n'BCT', 'X'\
,\n'BCY', 'X',\n'BCZ', 'X',\n'BDA', 'X',\n'BDG', '\
X',\n'BDK', 'X',\n'BDM', 'X',\n'BDN', 'X',\n'BDS',\
 'X',\n'BE1', 'X',\n'BE2', 'X',\n'BEA', 'X',\n'BEF\
', 'X',\n'BEN', 'X',\n'BEO', 'X',\n'BEP', 'X',\n'B\
ER', 'X',\n'BES', 'X',\n'BET', 'X',\n'BEZ', 'X',\n\
'BF2', 'X',\n'BFA', 'X',\n'BFD', 'X',\n'BFP', 'X',\
\n'BFS', 'X',\n'BFU', 'X',\n'BG6', 'X',\n'BGF', 'X\
',\n'BGG', 'X',\n'BGL', 'X',\n'BGN', 'X',\n'BGP', \
'X',\n'BGX', 'X',\n'BH4', 'X',\n'BHA', 'X',\n'BHC'\
, 'X',\n'BHD', 'D',\n'BHO', 'X',\n'BHS', 'X',\n'BI\
C', 'X',\n'BIN', 'X',\n'BIO', 'X',\n'BIP', 'X',\n'\
BIS', 'X',\n'BIZ', 'X',\n'BJH', 'X',\n'BJI', 'X',\\
n'BJP', 'X',\n'BLA', 'X',\n'BLB', 'X',\n'BLE', 'L'\
,\n'BLG', 'P',\n'BLI', 'X',\n'BLM', 'X',\n'BLV', '\
X',\n'BLY', 'K',\n'BM1', 'X',\n'BM2', 'X',\n'BM5',\
 'X',\n'BM9', 'X',\n'BMA', 'X',\n'BMD', 'X',\n'BME\
', 'X',\n'BMP', 'X',\n'BMQ', 'X',\n'BMS', 'X',\n'B\
MT', 'T',\n'BMU', 'X',\n'BMY', 'X',\n'BMZ', 'X',\n\
'BNA', 'X',\n'BNG', 'X',\n'BNI', 'X',\n'BNN', 'F',\
\n'BNO', 'L',\n'BNS', 'X',\n'BNZ', 'X',\n'BO3', 'X\
',\n'BO4', 'X',\n'BOC', 'X',\n'BOG', 'X',\n'BOM', \
'X',\n'BOT', 'X',\n'BOX', 'X',\n'BOZ', 'X',\n'BPA'\
, 'X',\n'BPB', 'X',\n'BPD', 'X',\n'BPG', 'X',\n'BP\
H', 'X',\n'BPI', 'X',\n'BPJ', 'X',\n'BPM', 'X',\n'\
BPN', 'X',\n'BPO', 'X',\n'BPP', 'X',\n'BPT', 'X',\\
n'BPY', 'X',\n'BRB', 'X',\n'BRC', 'X',\n'BRE', 'X'\
,\n'BRI', 'X',\n'BRL', 'X',\n'BRM', 'X',\n'BRN', '\
X',\n'BRO', 'X',\n'BRS', 'X',\n'BRU', 'X',\n'BRZ',\
 'X',\n'BSB', 'X',\n'BSI', 'X',\n'BSP', 'X',\n'BT1\
', 'X',\n'BT2', 'X',\n'BT3', 'X',\n'BTA', 'L',\n'B\
TB', 'X',\n'BTC', 'C',\n'BTD', 'X',\n'BTN', 'X',\n\
'BTP', 'X',\n'BTR', 'W',\n'BU1', 'X',\n'BUA', 'X',\
\n'BUB', 'X',\n'BUC', 'X',\n'BUG', 'X',\n'BUL', 'X\
',\n'BUM', 'X',\n'BUQ', 'X',\n'BUT', 'X',\n'BVD', \
'X',\n'BX3', 'X',\n'BYS', 'X',\n'BZ1', 'X',\n'BZA'\
, 'X',\n'BZB', 'X',\n'BZC', 'X',\n'BZD', 'X',\n'BZ\
F', 'X',\n'BZI', 'X',\n'BZM', 'X',\n'BZO', 'X',\n'\
BZP', 'X',\n'BZQ', 'X',\n'BZS', 'X',\n'BZT', 'X',\\
n'C02', 'X',\n'C11', 'X',\n'C1O', 'X',\n'C20', 'X'\
,\n'C24', 'X',\n'C2F', 'X',\n'C2O', 'X',\n'C2P', '\
X',\n'C3M', 'X',\n'C3P', 'X',\n'C3X', 'X',\n'C48',\
 'X',\n'C4M', 'X',\n'C4X', 'X',\n'C5C', 'X',\n'C5M\
', 'X',\n'C5P', 'X',\n'C5X', 'X',\n'C60', 'X',\n'C\
6C', 'X',\n'C6M', 'X',\n'C78', 'X',\n'C8E', 'X',\n\
'CA3', 'X',\n'CA5', 'X',\n'CAA', 'X',\n'CAB', 'X',\
\n'CAC', 'X',\n'CAD', 'X',\n'CAF', 'C',\n'CAG', 'X\
',\n'CAH', 'X',\n'CAL', 'X',\n'CAM', 'X',\n'CAN', \
'X',\n'CAO', 'X',\n'CAP', 'X',\n'CAQ', 'X',\n'CAR'\
, 'X',\n'CAS', 'C',\n'CAT', 'X',\n'CAV', 'X',\n'CA\
Y', 'C',\n'CAZ', 'X',\n'CB3', 'X',\n'CB4', 'X',\n'\
CBA', 'X',\n'CBD', 'X',\n'CBG', 'X',\n'CBI', 'X',\\
n'CBL', 'X',\n'CBM', 'X',\n'CBN', 'X',\n'CBO', 'X'\
,\n'CBP', 'X',\n'CBS', 'X',\n'CBX', 'X',\n'CBZ', '\
X',\n'CC0', 'X',\n'CC1', 'X',\n'CCC', 'X',\n'CCH',\
 'X',\n'CCI', 'X',\n'CCM', 'X',\n'CCN', 'X',\n'CCO\
', 'X',\n'CCP', 'X',\n'CCR', 'X',\n'CCS', 'C',\n'C\
CV', 'X',\n'CCY', 'X',\n'CD1', 'X',\n'CDC', 'X',\n\
'CDE', 'X',\n'CDF', 'X',\n'CDI', 'X',\n'CDL', 'X',\
\n'CDM', 'X',\n'CDP', 'X',\n'CDR', 'X',\n'CDU', 'X\
',\n'CE1', 'X',\n'CEA', 'C',\n'CEB', 'X',\n'CEC', \
'X',\n'CED', 'X',\n'CEF', 'X',\n'CEH', 'X',\n'CEM'\
, 'X',\n'CEO', 'X',\n'CEP', 'X',\n'CEQ', 'X',\n'CE\
R', 'X',\n'CES', 'G',\n'CET', 'X',\n'CFC', 'X',\n'\
CFF', 'X',\n'CFM', 'X',\n'CFO', 'X',\n'CFP', 'X',\\
n'CFS', 'X',\n'CFX', 'X',\n'CGN', 'X',\n'CGP', 'X'\
,\n'CGS', 'X',\n'CGU', 'E',\n'CH2', 'X',\n'CH3', '\
X',\n'CHA', 'X',\n'CHB', 'X',\n'CHD', 'X',\n'CHF',\
 'X',\n'CHG', 'G',\n'CHI', 'X',\n'CHN', 'X',\n'CHO\
', 'X',\n'CHP', 'G',\n'CHR', 'X',\n'CHS', 'F',\n'C\
HT', 'X',\n'CHX', 'X',\n'CIC', 'X',\n'CIN', 'X',\n\
'CIP', 'X',\n'CIR', 'X',\n'CIT', 'X',\n'CIU', 'X',\
\n'CKI', 'X',\n'CL1', 'X',\n'CL2', 'X',\n'CLA', 'X\
',\n'CLB', 'A',\n'CLC', 'S',\n'CLD', 'A',\n'CLE', \
'L',\n'CLF', 'X',\n'CLK', 'S',\n'CLL', 'X',\n'CLM'\
, 'X',\n'CLN', 'X',\n'CLO', 'X',\n'CLP', 'X',\n'CL\
Q', 'X',\n'CLR', 'X',\n'CLS', 'X',\n'CLT', 'X',\n'\
CLX', 'X',\n'CLY', 'X',\n'CMA', 'R',\n'CMC', 'X',\\
n'CMD', 'X',\n'CME', 'C',\n'CMG', 'X',\n'CMK', 'X'\
,\n'CMN', 'X',\n'CMO', 'X',\n'CMP', 'X',\n'CMR', '\
X',\n'CMS', 'X',\n'CMT', 'C',\n'CMX', 'X',\n'CNA',\
 'X',\n'CNC', 'X',\n'CND', 'X',\n'CNH', 'X',\n'CNM\
', 'X',\n'CNN', 'X',\n'CNO', 'X',\n'CNP', 'X',\n'C\
O2', 'X',\n'CO3', 'X',\n'CO5', 'X',\n'CO8', 'X',\n\
'COA', 'X',\n'COB', 'X',\n'COC', 'X',\n'COD', 'X',\
\n'COE', 'X',\n'COF', 'X',\n'COH', 'X',\n'COI', 'X\
',\n'COJ', 'X',\n'COL', 'X',\n'COM', 'X',\n'CON', \
'X',\n'COP', 'X',\n'COR', 'X',\n'COS', 'X',\n'COT'\
, 'X',\n'COY', 'X',\n'CP1', 'G',\n'CP2', 'X',\n'CP\
4', 'X',\n'CPA', 'X',\n'CPB', 'X',\n'CPC', 'X',\n'\
CPD', 'X',\n'CPG', 'X',\n'CPH', 'X',\n'CPI', 'X',\\
n'CPM', 'X',\n'CPN', 'G',\n'CPO', 'X',\n'CPP', 'X'\
,\n'CPQ', 'X',\n'CPR', 'X',\n'CPS', 'X',\n'CPT', '\
X',\n'CPU', 'X',\n'CPV', 'X',\n'CPY', 'X',\n'CR1',\
 'X',\n'CR6', 'X',\n'CRA', 'X',\n'CRB', 'X',\n'CRC\
', 'X',\n'CRG', 'X',\n'CRH', 'X',\n'CRO', 'T',\n'C\
RP', 'X',\n'CRQ', 'X',\n'CRS', 'X',\n'CRT', 'X',\n\
'CRY', 'X',\n'CSA', 'C',\n'CSB', 'X',\n'CSD', 'C',\
\n'CSE', 'C',\n'CSH', 'X',\n'CSI', 'X',\n'CSN', 'X\
',\n'CSO', 'C',\n'CSP', 'C',\n'CSR', 'C',\n'CSS', \
'C',\n'CST', 'X',\n'CSW', 'C',\n'CSX', 'C',\n'CSY'\
, 'X',\n'CSZ', 'C',\n'CT3', 'X',\n'CTA', 'X',\n'CT\
B', 'X',\n'CTC', 'X',\n'CTD', 'X',\n'CTH', 'T',\n'\
CTO', 'X',\n'CTP', 'X',\n'CTR', 'X',\n'CTS', 'X',\\
n'CTT', 'X',\n'CTY', 'X',\n'CTZ', 'X',\n'CU1', 'X'\
,\n'CUA', 'X',\n'CUC', 'X',\n'CUL', 'X',\n'CUO', '\
X',\n'CUZ', 'X',\n'CVI', 'X',\n'CXF', 'X',\n'CXL',\
 'X',\n'CXM', 'M',\n'CXN', 'X',\n'CXP', 'X',\n'CXS\
', 'X',\n'CY1', 'C',\n'CY3', 'X',\n'CYB', 'X',\n'C\
YC', 'X',\n'CYF', 'C',\n'CYG', 'C',\n'CYH', 'X',\n\
'CYL', 'X',\n'CYM', 'C',\n'CYN', 'X',\n'CYO', 'X',\
\n'CYP', 'X',\n'CYQ', 'C',\n'CYS', 'C',\n'CYU', 'X\
',\n'CYY', 'X',\n'CYZ', 'X',\n'CZH', 'X',\n'CZZ', \
'C',\n'D12', 'X',\n'D13', 'X',\n'D16', 'X',\n'D18'\
, 'X',\n'D19', 'X',\n'D1P', 'X',\n'D24', 'X',\n'D3\
4', 'X',\n'D35', 'X',\n'D4D', 'X',\n'D4T', 'X',\n'\
D6G', 'X',\n'DA2', 'R',\n'DA3', 'X',\n'DA6', 'X',\\
n'DA7', 'X',\n'DAA', 'X',\n'DAB', 'X',\n'DAC', 'X'\
,\n'DAD', 'X',\n'DAE', 'X',\n'DAF', 'X',\n'DAG', '\
X',\n'DAH', 'A',\n'DAJ', 'X',\n'DAK', 'X',\n'DAL',\
 'A',\n'DAM', 'A',\n'DAN', 'X',\n'DAO', 'X',\n'DAP\
', 'X',\n'DAQ', 'X',\n'DAR', 'R',\n'DAS', 'D',\n'D\
AT', 'X',\n'DAU', 'X',\n'DAV', 'X',\n'DBA', 'X',\n\
'DBD', 'X',\n'DBF', 'X',\n'DBG', 'X',\n'DBI', 'X',\
\n'DBV', 'X',\n'DBY', 'Y',\n'DCA', 'X',\n'DCB', 'X\
',\n'DCE', 'X',\n'DCF', 'X',\n'DCG', 'X',\n'DCH', \
'X',\n'DCI', 'I',\n'DCL', 'X',\n'DCM', 'X',\n'DCP'\
, 'X',\n'DCS', 'X',\n'DCT', 'X',\n'DCY', 'C',\n'DC\
Z', 'X',\n'DDA', 'X',\n'DDB', 'X',\n'DDC', 'X',\n'\
DDF', 'X',\n'DDG', 'X',\n'DDH', 'X',\n'DDL', 'X',\\
n'DDM', 'X',\n'DDO', 'L',\n'DDP', 'X',\n'DDQ', 'X'\
,\n'DDT', 'Y',\n'DDU', 'X',\n'DEA', 'X',\n'DEB', '\
X',\n'DEC', 'X',\n'DEF', 'X',\n'DEL', 'X',\n'DEM',\
 'X',\n'DEN', 'X',\n'DEP', 'X',\n'DEQ', 'X',\n'DES\
', 'X',\n'DET', 'X',\n'DFC', 'X',\n'DFG', 'X',\n'D\
FI', 'X',\n'DFL', 'X',\n'DFO', 'X',\n'DFP', 'X',\n\
'DFR', 'X',\n'DFT', 'X',\n'DFV', 'X',\n'DFX', 'X',\
\n'DG2', 'X',\n'DG3', 'X',\n'DG6', 'X',\n'DGA', 'X\
',\n'DGD', 'X',\n'DGG', 'X',\n'DGL', 'E',\n'DGN', \
'Q',\n'DGP', 'X',\n'DGT', 'X',\n'DGX', 'X',\n'DH2'\
, 'X',\n'DHA', 'A',\n'DHB', 'X',\n'DHC', 'X',\n'DH\
D', 'X',\n'DHE', 'X',\n'DHF', 'X',\n'DHG', 'X',\n'\
DHI', 'H',\n'DHL', 'X',\n'DHM', 'X',\n'DHN', 'V',\\
n'DHP', 'X',\n'DHQ', 'X',\n'DHR', 'X',\n'DHS', 'X'\
,\n'DHT', 'X',\n'DHU', 'X',\n'DHY', 'X',\n'DHZ', '\
X',\n'DI2', 'X',\n'DI3', 'G',\n'DI4', 'X',\n'DI5',\
 'X',\n'DIA', 'X',\n'DIC', 'X',\n'DIF', 'X',\n'DIG\
', 'X',\n'DII', 'X',\n'DIL', 'I',\n'DIM', 'X',\n'D\
IO', 'X',\n'DIP', 'X',\n'DIQ', 'X',\n'DIS', 'X',\n\
'DIT', 'X',\n'DIV', 'V',\n'DIX', 'X',\n'DIY', 'X',\
\n'DKA', 'X',\n'DLA', 'X',\n'DLE', 'L',\n'DLF', 'X\
',\n'DLS', 'K',\n'DLY', 'K',\n'DM1', 'X',\n'DM2', \
'X',\n'DM3', 'X',\n'DM4', 'X',\n'DM5', 'X',\n'DM6'\
, 'X',\n'DM7', 'X',\n'DM8', 'X',\n'DM9', 'X',\n'DM\
A', 'X',\n'DMB', 'X',\n'DMC', 'X',\n'DMD', 'X',\n'\
DME', 'X',\n'DMF', 'X',\n'DMG', 'G',\n'DMH', 'N',\\
n'DMI', 'X',\n'DMJ', 'X',\n'DML', 'X',\n'DMM', 'X'\
,\n'DMN', 'X',\n'DMO', 'X',\n'DMP', 'X',\n'DMQ', '\
X',\n'DMR', 'X',\n'DMS', 'X',\n'DMT', 'X',\n'DMV',\
 'X',\n'DMY', 'X',\n'DNC', 'X',\n'DND', 'X',\n'DNH\
', 'X',\n'DNJ', 'X',\n'DNN', 'X',\n'DNP', 'X',\n'D\
NQ', 'X',\n'DNR', 'X',\n'DO2', 'X',\n'DO3', 'X',\n\
'DOA', 'X',\n'DOB', 'X',\n'DOC', 'X',\n'DOH', 'D',\
\n'DOM', 'X',\n'DOS', 'X',\n'DOX', 'X',\n'DP5', 'X\
',\n'DP7', 'X',\n'DPA', 'X',\n'DPC', 'X',\n'DPD', \
'X',\n'DPE', 'X',\n'DPG', 'X',\n'DPH', 'F',\n'DPM'\
, 'X',\n'DPN', 'F',\n'DPO', 'X',\n'DPP', 'X',\n'DP\
R', 'P',\n'DPS', 'X',\n'DPT', 'X',\n'DPX', 'X',\n'\
DPY', 'X',\n'DPZ', 'X',\n'DQH', 'X',\n'DQN', 'X',\\
n'DR1', 'X',\n'DRB', 'X',\n'DRC', 'X',\n'DRI', 'X'\
,\n'DRP', 'X',\n'DRT', 'X',\n'DRU', 'X',\n'DSA', '\
X',\n'DSB', 'X',\n'DSC', 'X',\n'DSD', 'X',\n'DSE',\
 'S',\n'DSI', 'X',\n'DSN', 'S',\n'DSP', 'D',\n'DSR\
', 'X',\n'DSS', 'X',\n'DSX', 'X',\n'DSY', 'X',\n'D\
TB', 'X',\n'DTD', 'X',\n'DTH', 'T',\n'DTN', 'X',\n\
'DTO', 'X',\n'DTP', 'X',\n'DTQ', 'X',\n'DTR', 'W',\
\n'DTT', 'X',\n'DTY', 'Y',\n'DUD', 'X',\n'DUO', 'X\
',\n'DUR', 'X',\n'DUT', 'X',\n'DVA', 'V',\n'DVR', \
'X',\n'DX9', 'X',\n'DXA', 'X',\n'DXB', 'X',\n'DXC'\
, 'X',\n'DXG', 'X',\n'DXX', 'X',\n'DZF', 'X',\n'E0\
9', 'X',\n'E20', 'X',\n'E2P', 'X',\n'E3G', 'X',\n'\
E4N', 'X',\n'E4P', 'X',\n'E64', 'X',\n'E6C', 'X',\\
n'E96', 'X',\n'E97', 'X',\n'EA2', 'X',\n'EAA', 'X'\
,\n'EAP', 'X',\n'EBP', 'X',\n'EBW', 'X',\n'ECO', '\
X',\n'EDA', 'X',\n'EDC', 'X',\n'EDE', 'X',\n'EDO',\
 'X',\n'EDR', 'X',\n'EEB', 'X',\n'EEE', 'X',\n'EFC\
', 'X',\n'EFZ', 'X',\n'EG1', 'X',\n'EG2', 'X',\n'E\
G3', 'X',\n'EGC', 'X',\n'EGL', 'X',\n'EHP', 'A',\n\
'EIC', 'X',\n'EJT', 'X',\n'ELA', 'X',\n'EMB', 'X',\
\n'EMC', 'X',\n'EMD', 'X',\n'EMM', 'X',\n'EMO', 'X\
',\n'EMP', 'X',\n'EMR', 'X',\n'ENA', 'X',\n'ENC', \
'X',\n'ENH', 'X',\n'ENO', 'X',\n'ENP', 'X',\n'EOA'\
, 'X',\n'EOH', 'X',\n'EOT', 'X',\n'EOX', 'X',\n'EP\
A', 'X',\n'EPE', 'X',\n'EPH', 'X',\n'EPI', 'X',\n'\
EPN', 'X',\n'EPO', 'X',\n'EPT', 'X',\n'EPU', 'X',\\
n'EPX', 'X',\n'EPY', 'X',\n'EQI', 'X',\n'EQP', 'X'\
,\n'EQU', 'X',\n'ERG', 'X',\n'ERI', 'X',\n'ERY', '\
X',\n'ESC', 'X',\n'ESD', 'X',\n'ESI', 'X',\n'ESO',\
 'X',\n'ESP', 'X',\n'EST', 'X',\n'ESX', 'X',\n'ETA\
', 'X',\n'ETC', 'X',\n'ETD', 'X',\n'ETF', 'X',\n'E\
TH', 'X',\n'ETI', 'X',\n'ETN', 'X',\n'ETO', 'X',\n\
'ETP', 'X',\n'ETR', 'X',\n'ETS', 'X',\n'ETY', 'X',\
\n'EU3', 'X',\n'EUG', 'X',\n'EYS', 'C',\n'F09', 'X\
',\n'F2B', 'X',\n'F3S', 'X',\n'F42', 'X',\n'F43', \
'X',\n'F4S', 'X',\n'F6B', 'X',\n'F6P', 'X',\n'F89'\
, 'X',\n'FA1', 'X',\n'FA5', 'F',\n'FAA', 'X',\n'FA\
B', 'X',\n'FAC', 'X',\n'FAD', 'X',\n'FAF', 'X',\n'\
FAG', 'X',\n'FAM', 'X',\n'FAR', 'X',\n'FAS', 'X',\\
n'FAT', 'X',\n'FBA', 'X',\n'FBE', 'X',\n'FBI', 'X'\
,\n'FBP', 'X',\n'FBQ', 'X',\n'FBS', 'X',\n'FBT', '\
X',\n'FBU', 'X',\n'FCA', 'X',\n'FCB', 'X',\n'FCI',\
 'X',\n'FCN', 'X',\n'FCO', 'X',\n'FCR', 'X',\n'FCT\
', 'X',\n'FCX', 'X',\n'FCY', 'C',\n'FD1', 'F',\n'F\
D2', 'F',\n'FD3', 'F',\n'FD4', 'F',\n'FDA', 'X',\n\
'FDC', 'X',\n'FDI', 'X',\n'FDP', 'X',\n'FDS', 'X',\
\n'FE2', 'X',\n'FEA', 'X',\n'FEL', 'X',\n'FEM', 'X\
',\n'FEN', 'X',\n'FEO', 'X',\n'FEP', 'X',\n'FER', \
'X',\n'FES', 'X',\n'FFB', 'X',\n'FFC', 'X',\n'FFF'\
, 'X',\n'FFO', 'X',\n'FGL', 'G',\n'FHB', 'X',\n'FH\
C', 'X',\n'FHP', 'X',\n'FHU', 'X',\n'FID', 'X',\n'\
FII', 'X',\n'FIP', 'X',\n'FK5', 'X',\n'FKA', 'X',\\
n'FKI', 'X',\n'FKP', 'X',\n'FL2', 'X',\n'FL9', 'X'\
,\n'FLA', 'A',\n'FLC', 'X',\n'FLD', 'X',\n'FLE', '\
L',\n'FLF', 'X',\n'FLO', 'X',\n'FLP', 'X',\n'FLT',\
 'Y',\n'FLU', 'X',\n'FLX', 'X',\n'FM1', 'X',\n'FM2\
', 'X',\n'FMA', 'X',\n'FMB', 'X',\n'FMC', 'X',\n'F\
ME', 'M',\n'FMN', 'X',\n'FMP', 'X',\n'FMR', 'X',\n\
'FMS', 'X',\n'FMT', 'X',\n'FNE', 'X',\n'FNP', 'X',\
\n'FNS', 'X',\n'FOC', 'X',\n'FOE', 'X',\n'FOG', 'F\
',\n'FOH', 'X',\n'FOK', 'X',\n'FOL', 'X',\n'FON', \
'X',\n'FOP', 'X',\n'FOR', 'X',\n'FOS', 'X',\n'FPA'\
, 'X',\n'FPC', 'X',\n'FPI', 'X',\n'FPO', 'X',\n'FP\
P', 'X',\n'FPT', 'X',\n'FQP', 'X',\n'FRA', 'X',\n'\
FRD', 'F',\n'FRU', 'X',\n'FS3', 'X',\n'FS4', 'X',\\
n'FSB', 'X',\n'FSO', 'X',\n'FSX', 'X',\n'FTC', 'X'\
,\n'FTP', 'X',\n'FTR', 'W',\n'FTT', 'X',\n'FTY', '\
Y',\n'FUA', 'X',\n'FUC', 'X',\n'FUM', 'X',\n'FUP',\
 'X',\n'FVF', 'X',\n'FXP', 'X',\n'FXV', 'X',\n'FYA\
', 'F',\n'G16', 'X',\n'G1P', 'X',\n'G20', 'X',\n'G\
21', 'X',\n'G23', 'X',\n'G26', 'X',\n'G28', 'X',\n\
'G2F', 'X',\n'G37', 'X',\n'G39', 'X',\n'G3H', 'X',\
\n'G3P', 'X',\n'G4D', 'X',\n'G6D', 'X',\n'G6P', 'X\
',\n'G6Q', 'X',\n'G7M', 'X',\n'GA2', 'X',\n'GAA', \
'X',\n'GAB', 'X',\n'GAC', 'X',\n'GAI', 'X',\n'GAL'\
, 'X',\n'GAM', 'X',\n'GAN', 'X',\n'GAO', 'X',\n'GA\
P', 'X',\n'GAR', 'G',\n'GAS', 'X',\n'GAT', 'X',\n'\
GBC', 'X',\n'GBI', 'X',\n'GBP', 'X',\n'GBS', 'X',\\
n'GBX', 'X',\n'GC4', 'X',\n'GCA', 'X',\n'GCD', 'X'\
,\n'GCG', 'G',\n'GCH', 'G',\n'GCK', 'X',\n'GCL', '\
X',\n'GCM', 'X',\n'GCN', 'X',\n'GCO', 'X',\n'GCP',\
 'X',\n'GCR', 'X',\n'GCS', 'X',\n'GCU', 'X',\n'GD3\
', 'X',\n'GDB', 'X',\n'GDM', 'X',\n'GDN', 'X',\n'G\
DP', 'X',\n'GDS', 'X',\n'GDU', 'X',\n'GE1', 'X',\n\
'GE2', 'X',\n'GE3', 'X',\n'GEA', 'X',\n'GEL', 'X',\
\n'GEM', 'X',\n'GEN', 'X',\n'GEP', 'X',\n'GER', 'X\
',\n'GFP', 'X',\n'GGB', 'X',\n'GGL', 'E',\n'GGP', \
'X',\n'GHP', 'G',\n'GIP', 'X',\n'GIS', 'X',\n'GKR'\
, 'X',\n'GL2', 'X',\n'GL3', 'G',\n'GL4', 'X',\n'GL\
5', 'X',\n'GL7', 'X',\n'GL9', 'X',\n'GLA', 'X',\n'\
GLB', 'X',\n'GLC', 'X',\n'GLD', 'X',\n'GLE', 'X',\\
n'GLF', 'X',\n'GLG', 'X',\n'GLH', 'Q',\n'GLI', 'X'\
,\n'GLL', 'X',\n'GLM', 'G',\n'GLN', 'Q',\n'GLO', '\
X',\n'GLP', 'X',\n'GLR', 'X',\n'GLS', 'X',\n'GLT',\
 'X',\n'GLU', 'E',\n'GLV', 'X',\n'GLW', 'X',\n'GLY\
', 'G',\n'GLZ', 'X',\n'GM1', 'X',\n'GMA', 'X',\n'G\
MC', 'X',\n'GMH', 'X',\n'GMP', 'X',\n'GMY', 'X',\n\
'GN7', 'X',\n'GNA', 'X',\n'GNB', 'X',\n'GNH', 'X',\
\n'GNP', 'X',\n'GNT', 'X',\n'GOA', 'X',\n'GOL', 'X\
',\n'GOX', 'X',\n'GP1', 'X',\n'GP3', 'X',\n'GP4', \
'X',\n'GP6', 'X',\n'GP8', 'X',\n'GPB', 'E',\n'GPC'\
, 'X',\n'GPE', 'X',\n'GPG', 'X',\n'GPI', 'X',\n'GP\
J', 'X',\n'GPL', 'K',\n'GPM', 'X',\n'GPN', 'G',\n'\
GPP', 'X',\n'GPR', 'X',\n'GPS', 'X',\n'GPX', 'X',\\
n'GR1', 'X',\n'GR3', 'X',\n'GR4', 'X',\n'GSA', 'X'\
,\n'GSB', 'X',\n'GSC', 'G',\n'GSE', 'S',\n'GSH', '\
X',\n'GSP', 'X',\n'GSR', 'X',\n'GSS', 'X',\n'GT9',\
 'C',\n'GTA', 'X',\n'GTB', 'X',\n'GTD', 'X',\n'GTE\
', 'X',\n'GTH', 'T',\n'GTN', 'X',\n'GTO', 'X',\n'G\
TP', 'X',\n'GTR', 'X',\n'GTS', 'X',\n'GTT', 'X',\n\
'GTX', 'X',\n'GTZ', 'X',\n'GU7', 'X',\n'GUA', 'X',\
\n'GUD', 'X',\n'GUM', 'X',\n'GUN', 'X',\n'GUP', 'X\
',\n'GUR', 'X',\n'GW3', 'X',\n'GZZ', 'X',\n'H2B', \
'X',\n'H2P', 'H',\n'H2S', 'X',\n'H2U', 'X',\n'H4B'\
, 'X',\n'H5M', 'P',\n'H5P', 'X',\n'HAA', 'X',\n'HA\
B', 'X',\n'HAC', 'A',\n'HAD', 'X',\n'HAE', 'X',\n'\
HAG', 'X',\n'HAI', 'X',\n'HAM', 'X',\n'HAP', 'X',\\
n'HAQ', 'X',\n'HAR', 'R',\n'HAS', 'X',\n'HAV', 'V'\
,\n'HAX', 'X',\n'HAZ', 'X',\n'HBA', 'X',\n'HBC', '\
X',\n'HBD', 'X',\n'HBI', 'X',\n'HBO', 'X',\n'HBU',\
 'X',\n'HBY', 'X',\n'HC0', 'X',\n'HC1', 'X',\n'HC4\
', 'X',\n'HCA', 'X',\n'HCC', 'X',\n'HCI', 'X',\n'H\
CS', 'X',\n'HDA', 'X',\n'HDD', 'X',\n'HDF', 'X',\n\
'HDN', 'X',\n'HDS', 'X',\n'HDZ', 'X',\n'HE1', 'X',\
\n'HE6', 'X',\n'HEA', 'X',\n'HEB', 'X',\n'HEC', 'X\
',\n'HED', 'X',\n'HEE', 'X',\n'HEF', 'X',\n'HEG', \
'X',\n'HEM', 'X',\n'HEN', 'X',\n'HEO', 'X',\n'HEP'\
, 'X',\n'HEU', 'X',\n'HEV', 'X',\n'HEX', 'X',\n'HE\
Z', 'X',\n'HF1', 'X',\n'HFA', 'X',\n'HFP', 'X',\n'\
HGA', 'Q',\n'HGB', 'X',\n'HGC', 'X',\n'HGI', 'X',\\
n'HGU', 'X',\n'HHO', 'X',\n'HHP', 'X',\n'HIB', 'X'\
,\n'HIC', 'H',\n'HII', 'X',\n'HIN', 'X',\n'HIO', '\
X',\n'HIP', 'H',\n'HIS', 'H',\n'HLE', 'X',\n'HLT',\
 'X',\n'HMA', 'A',\n'HMB', 'X',\n'HMC', 'X',\n'HMD\
', 'X',\n'HMF', 'A',\n'HMG', 'X',\n'HMH', 'X',\n'H\
MI', 'L',\n'HMM', 'X',\n'HMN', 'X',\n'HMO', 'X',\n\
'HMP', 'X',\n'HMR', 'R',\n'HNI', 'X',\n'HNP', 'X',\
\n'HOA', 'X',\n'HOE', 'X',\n'HOH', 'X',\n'HOM', 'X\
',\n'HOP', 'X',\n'HOQ', 'X',\n'HP1', 'A',\n'HP2', \
'A',\n'HP3', 'X',\n'HPA', 'X',\n'HPB', 'X',\n'HPC'\
, 'X',\n'HPD', 'X',\n'HPE', 'A',\n'HPG', 'X',\n'HP\
H', 'F',\n'HPP', 'X',\n'HPQ', 'F',\n'HPR', 'X',\n'\
HPT', 'X',\n'HPY', 'X',\n'HQO', 'X',\n'HQQ', 'X',\\
n'HQU', 'X',\n'HRG', 'R',\n'HRI', 'X',\n'HSA', 'X'\
,\n'HSE', 'S',\n'HSF', 'X',\n'HSM', 'X',\n'HSO', '\
H',\n'HSP', 'X',\n'HT1', 'X',\n'HT2', 'X',\n'HTA',\
 'X',\n'HTL', 'X',\n'HTO', 'X',\n'HTP', 'X',\n'HTR\
', 'W',\n'HUP', 'X',\n'HUX', 'X',\n'HV5', 'A',\n'H\
V7', 'X',\n'HV8', 'X',\n'HXA', 'X',\n'HXC', 'X',\n\
'HXP', 'X',\n'HY1', 'X',\n'HYA', 'X',\n'HYB', 'X',\
\n'HYD', 'X',\n'HYG', 'X',\n'HYP', 'P',\n'I06', 'X\
',\n'I10', 'X',\n'I11', 'X',\n'I17', 'X',\n'I2P', \
'X',\n'I3N', 'X',\n'I3P', 'X',\n'I40', 'X',\n'I48'\
, 'X',\n'I4B', 'X',\n'I52', 'X',\n'I5P', 'X',\n'I8\
4', 'G',\n'IAG', 'G',\n'IAS', 'X',\n'IB2', 'X',\n'\
IBB', 'X',\n'IBP', 'X',\n'IBR', 'X',\n'IBS', 'X',\\
n'IBZ', 'X',\n'IC1', 'X',\n'ICA', 'X',\n'ICI', 'X'\
,\n'ICL', 'X',\n'ICP', 'X',\n'ICT', 'X',\n'ICU', '\
X',\n'ID2', 'X',\n'IDC', 'X',\n'IDG', 'X',\n'IDH',\
 'X',\n'IDM', 'X',\n'IDO', 'X',\n'IDP', 'X',\n'IDR\
', 'X',\n'IDS', 'X',\n'IDT', 'X',\n'IDU', 'X',\n'I\
FG', 'X',\n'IFP', 'X',\n'IGL', 'X',\n'IGN', 'X',\n\
'IGP', 'X',\n'IGU', 'X',\n'IH1', 'X',\n'IH2', 'X',\
\n'IH3', 'X',\n'IHB', 'X',\n'IHN', 'X',\n'IHP', 'X\
',\n'IIC', 'X',\n'IIL', 'I',\n'IIP', 'X',\n'IK2', \
'X',\n'IKT', 'X',\n'ILA', 'I',\n'ILE', 'I',\n'ILG'\
, 'X',\n'ILO', 'X',\n'ILX', 'I',\n'IM1', 'X',\n'IM\
2', 'X',\n'IMC', 'X',\n'IMD', 'X',\n'IME', 'X',\n'\
IMF', 'X',\n'IMG', 'X',\n'IMH', 'X',\n'IMI', 'X',\\
n'IML', 'I',\n'IMM', 'X',\n'IMN', 'X',\n'IMO', 'X'\
,\n'IMP', 'X',\n'IMR', 'X',\n'IMU', 'X',\n'IN0', '\
D',\n'IN1', 'R',\n'IN2', 'K',\n'IN3', 'L',\n'IN4',\
 'X',\n'IN5', 'A',\n'IN6', 'L',\n'IN7', 'X',\n'IN8\
', 'X',\n'IN9', 'X',\n'INA', 'L',\n'INB', 'X',\n'I\
NC', 'X',\n'IND', 'X',\n'INE', 'X',\n'INF', 'F',\n\
'ING', 'F',\n'INH', 'R',\n'INI', 'X',\n'INJ', 'X',\
\n'INK', 'X',\n'INL', 'X',\n'INM', 'X',\n'INN', 'A\
',\n'INO', 'X',\n'INP', 'X',\n'INQ', 'X',\n'INR', \
'X',\n'INS', 'X',\n'INT', 'V',\n'INU', 'X',\n'INV'\
, 'X',\n'INW', 'X',\n'INX', 'X',\n'INY', 'X',\n'IN\
Z', 'X',\n'IOA', 'X',\n'IOB', 'X',\n'IOC', 'X',\n'\
IOD', 'X',\n'IOE', 'X',\n'IOF', 'X',\n'IOH', 'X',\\
n'IOL', 'X',\n'IOP', 'X',\n'IP1', 'X',\n'IP2', 'X'\
,\n'IP3', 'X',\n'IP4', 'X',\n'IPA', 'X',\n'IPB', '\
X',\n'IPD', 'X',\n'IPG', 'G',\n'IPH', 'X',\n'IPL',\
 'X',\n'IPM', 'X',\n'IPN', 'X',\n'IPO', 'F',\n'IPP\
', 'X',\n'IPS', 'X',\n'IPT', 'X',\n'IPU', 'X',\n'I\
PY', 'A',\n'IQB', 'X',\n'IQP', 'X',\n'IQS', 'X',\n\
'IR3', 'X',\n'IRI', 'X',\n'IRP', 'X',\n'ISA', 'X',\
\n'ISF', 'X',\n'ISO', 'X',\n'ISP', 'X',\n'ISQ', 'X\
',\n'ISU', 'X',\n'ITM', 'X',\n'ITP', 'X',\n'ITR', \
'W',\n'ITS', 'X',\n'ITU', 'X',\n'IU5', 'X',\n'IUM'\
, 'X',\n'IUR', 'X',\n'IVA', 'X',\n'IYG', 'G',\n'IY\
R', 'Y',\n'J77', 'X',\n'J78', 'X',\n'J80', 'X',\n'\
JE2', 'X',\n'JEN', 'X',\n'JST', 'X',\n'K21', 'X',\\
n'KAH', 'X',\n'KAI', 'X',\n'KAM', 'X',\n'KAN', 'X'\
,\n'KAP', 'X',\n'KCP', 'X',\n'KCX', 'K',\n'KDO', '\
X',\n'KEF', 'X',\n'KET', 'X',\n'KGR', 'X',\n'KH1',\
 'X',\n'KIF', 'X',\n'KIV', 'V',\n'KNI', 'X',\n'KPH\
', 'K',\n'KTH', 'X',\n'KTN', 'X',\n'KTP', 'X',\n'K\
WT', 'X',\n'L04', 'X',\n'L1P', 'X',\n'L24', 'E',\n\
'L2P', 'X',\n'L34', 'E',\n'L37', 'E',\n'L3P', 'X',\
\n'L4P', 'X',\n'L75', 'X',\n'LAC', 'X',\n'LAD', 'X\
',\n'LAK', 'X',\n'LAM', 'X',\n'LAR', 'X',\n'LAT', \
'X',\n'LAX', 'X',\n'LCO', 'X',\n'LCP', 'X',\n'LCS'\
, 'X',\n'LDA', 'X',\n'LDO', 'L',\n'LDP', 'X',\n'LE\
A', 'X',\n'LEO', 'X',\n'LEU', 'L',\n'LG2', 'X',\n'\
LG6', 'X',\n'LGC', 'X',\n'LGP', 'X',\n'LHG', 'X',\\
n'LHY', 'F',\n'LI1', 'X',\n'LIG', 'X',\n'LIL', 'X'\
,\n'LIM', 'X',\n'LIN', 'X',\n'LIO', 'X',\n'LIP', '\
X',\n'LLA', 'X',\n'LLP', 'K',\n'LLY', 'K',\n'LMG',\
 'X',\n'LML', 'X',\n'LMT', 'X',\n'LMU', 'X',\n'LMZ\
', 'X',\n'LNK', 'X',\n'LNL', 'X',\n'LNO', 'X',\n'L\
OF', 'X',\n'LOL', 'L',\n'LOM', 'X',\n'LOR', 'X',\n\
'LOS', 'X',\n'LOV', 'L',\n'LOX', 'X',\n'LP1', 'X',\
\n'LP2', 'R',\n'LPA', 'X',\n'LPC', 'X',\n'LPF', 'X\
',\n'LPL', 'X',\n'LPM', 'X',\n'LPP', 'X',\n'LRB', \
'X',\n'LRU', 'X',\n'LS1', 'X',\n'LS2', 'X',\n'LS3'\
, 'X',\n'LS4', 'X',\n'LS5', 'X',\n'LTA', 'X',\n'LT\
L', 'X',\n'LTR', 'W',\n'LUM', 'X',\n'LVS', 'L',\n'\
LXC', 'X',\n'LY2', 'X',\n'LY3', 'X',\n'LYA', 'X',\\
n'LYB', 'X',\n'LYC', 'X',\n'LYD', 'X',\n'LYM', 'K'\
,\n'LYN', 'X',\n'LYS', 'K',\n'LYT', 'X',\n'LYW', '\
X',\n'LYZ', 'K',\n'M1A', 'X',\n'M1G', 'X',\n'M2G',\
 'X',\n'M3L', 'K',\n'M6P', 'X',\n'M6T', 'X',\n'M7G\
', 'X',\n'MA1', 'X',\n'MA2', 'X',\n'MA3', 'X',\n'M\
A4', 'X',\n'MA6', 'X',\n'MAA', 'A',\n'MAB', 'X',\n\
'MAC', 'X',\n'MAE', 'X',\n'MAG', 'X',\n'MAH', 'X',\
\n'MAI', 'R',\n'MAK', 'X',\n'MAL', 'X',\n'MAM', 'X\
',\n'MAN', 'X',\n'MAO', 'X',\n'MAP', 'X',\n'MAR', \
'X',\n'MAS', 'X',\n'MAT', 'X',\n'MAU', 'X',\n'MAZ'\
, 'X',\n'MBA', 'X',\n'MBD', 'X',\n'MBG', 'X',\n'MB\
H', 'X',\n'MBN', 'X',\n'MBO', 'X',\n'MBR', 'X',\n'\
MBS', 'X',\n'MBV', 'X',\n'MBZ', 'X',\n'MCA', 'X',\\
n'MCD', 'X',\n'MCE', 'X',\n'MCG', 'G',\n'MCI', 'X'\
,\n'MCN', 'X',\n'MCP', 'X',\n'MCT', 'X',\n'MCY', '\
X',\n'MD2', 'X',\n'MDA', 'X',\n'MDC', 'X',\n'MDG',\
 'X',\n'MDH', 'X',\n'MDL', 'X',\n'MDM', 'X',\n'MDN\
', 'X',\n'MDP', 'X',\n'ME6', 'X',\n'MEB', 'X',\n'M\
EC', 'X',\n'MEL', 'X',\n'MEN', 'N',\n'MEP', 'X',\n\
'MER', 'X',\n'MES', 'X',\n'MET', 'M',\n'MEV', 'X',\
\n'MF2', 'X',\n'MF3', 'M',\n'MFB', 'X',\n'MFD', 'X\
',\n'MFU', 'X',\n'MG7', 'X',\n'MGA', 'X',\n'MGB', \
'X',\n'MGD', 'X',\n'MGG', 'R',\n'MGL', 'X',\n'MGN'\
, 'Q',\n'MGO', 'X',\n'MGP', 'X',\n'MGR', 'X',\n'MG\
S', 'X',\n'MGT', 'X',\n'MGU', 'X',\n'MGY', 'G',\n'\
MHB', 'X',\n'MHF', 'X',\n'MHL', 'L',\n'MHM', 'X',\\
n'MHO', 'M',\n'MHS', 'H',\n'MHZ', 'X',\n'MIA', 'X'\
,\n'MIC', 'X',\n'MID', 'X',\n'MIL', 'X',\n'MIM', '\
X',\n'MIN', 'G',\n'MIP', 'X',\n'MIS', 'S',\n'MIT',\
 'X',\n'MJI', 'X',\n'MK1', 'X',\n'MKC', 'X',\n'MLA\
', 'X',\n'MLC', 'X',\n'MLE', 'L',\n'MLN', 'X',\n'M\
LT', 'X',\n'MLY', 'K',\n'MLZ', 'K',\n'MM3', 'X',\n\
'MM4', 'X',\n'MMA', 'X',\n'MMC', 'X',\n'MME', 'M',\
\n'MMO', 'R',\n'MMP', 'X',\n'MMQ', 'X',\n'MMT', 'X\
',\n'MN1', 'X',\n'MN2', 'X',\n'MN3', 'X',\n'MN5', \
'X',\n'MN7', 'X',\n'MN8', 'X',\n'MNA', 'X',\n'MNB'\
, 'X',\n'MNC', 'X',\n'MNG', 'X',\n'MNL', 'L',\n'MN\
O', 'X',\n'MNP', 'X',\n'MNQ', 'X',\n'MNS', 'X',\n'\
MNT', 'X',\n'MNV', 'V',\n'MO1', 'X',\n'MO2', 'X',\\
n'MO3', 'X',\n'MO4', 'X',\n'MO5', 'X',\n'MO6', 'X'\
,\n'MOA', 'X',\n'MOB', 'X',\n'MOC', 'X',\n'MOE', '\
X',\n'MOG', 'X',\n'MOH', 'X',\n'MOL', 'X',\n'MOO',\
 'X',\n'MOP', 'X',\n'MOR', 'X',\n'MOS', 'X',\n'MOT\
', 'X',\n'MOX', 'X',\n'MP1', 'X',\n'MP3', 'X',\n'M\
PA', 'X',\n'MPB', 'X',\n'MPC', 'X',\n'MPD', 'X',\n\
'MPG', 'X',\n'MPH', 'M',\n'MPI', 'X',\n'MPJ', 'M',\
\n'MPL', 'X',\n'MPN', 'X',\n'MPO', 'X',\n'MPP', 'X\
',\n'MPQ', 'G',\n'MPR', 'X',\n'MPS', 'X',\n'MQ0', \
'X',\n'MQ7', 'X',\n'MQ8', 'X',\n'MQ9', 'X',\n'MQI'\
, 'X',\n'MR2', 'X',\n'MRC', 'X',\n'MRM', 'X',\n'MR\
P', 'X',\n'MS2', 'X',\n'MSA', 'X',\n'MSB', 'X',\n'\
MSD', 'X',\n'MSE', 'M',\n'MSF', 'X',\n'MSI', 'X',\\
n'MSO', 'M',\n'MSQ', 'X',\n'MST', 'X',\n'MSU', 'X'\
,\n'MTA', 'X',\n'MTB', 'X',\n'MTC', 'X',\n'MTD', '\
X',\n'MTE', 'X',\n'MTF', 'X',\n'MTG', 'X',\n'MTO',\
 'X',\n'MTS', 'X',\n'MTT', 'X',\n'MTX', 'X',\n'MTY\
', 'Y',\n'MUG', 'X',\n'MUP', 'X',\n'MUR', 'X',\n'M\
VA', 'V',\n'MW1', 'X',\n'MW2', 'X',\n'MXA', 'X',\n\
'MXY', 'X',\n'MYA', 'X',\n'MYC', 'X',\n'MYG', 'X',\
\n'MYR', 'X',\n'MYS', 'X',\n'MYT', 'X',\n'MZM', 'X\
',\n'N1T', 'X',\n'N25', 'X',\n'N2B', 'X',\n'N3T', \
'X',\n'N4B', 'X',\n'NA2', 'X',\n'NA5', 'X',\n'NA6'\
, 'X',\n'NAA', 'X',\n'NAB', 'X',\n'NAC', 'X',\n'NA\
D', 'X',\n'NAE', 'X',\n'NAF', 'X',\n'NAG', 'X',\n'\
NAH', 'X',\n'NAI', 'X',\n'NAL', 'A',\n'NAM', 'A',\\
n'NAN', 'X',\n'NAO', 'X',\n'NAP', 'X',\n'NAQ', 'X'\
,\n'NAR', 'X',\n'NAS', 'X',\n'NAU', 'X',\n'NAV', '\
X',\n'NAW', 'X',\n'NAX', 'X',\n'NAY', 'X',\n'NBA',\
 'X',\n'NBD', 'X',\n'NBE', 'X',\n'NBG', 'X',\n'NBN\
', 'X',\n'NBP', 'X',\n'NBS', 'X',\n'NBU', 'X',\n'N\
CA', 'X',\n'NCB', 'A',\n'NCD', 'X',\n'NCH', 'X',\n\
'NCM', 'X',\n'NCN', 'X',\n'NCO', 'X',\n'NCR', 'X',\
\n'NCS', 'X',\n'ND4', 'X',\n'NDA', 'X',\n'NDC', 'X\
',\n'NDD', 'X',\n'NDO', 'X',\n'NDP', 'X',\n'NDT', \
'X',\n'NEA', 'X',\n'NEB', 'X',\n'NED', 'X',\n'NEM'\
, 'H',\n'NEN', 'X',\n'NEO', 'X',\n'NEP', 'H',\n'NE\
Q', 'X',\n'NES', 'X',\n'NET', 'X',\n'NEV', 'X',\n'\
NFA', 'F',\n'NFE', 'X',\n'NFG', 'X',\n'NFP', 'X',\\
n'NFS', 'X',\n'NG6', 'X',\n'NGA', 'X',\n'NGL', 'X'\
,\n'NGM', 'X',\n'NGO', 'X',\n'NGP', 'X',\n'NGT', '\
X',\n'NGU', 'X',\n'NH2', 'X',\n'NH3', 'X',\n'NH4',\
 'X',\n'NHD', 'X',\n'NHE', 'X',\n'NHM', 'X',\n'NHP\
', 'X',\n'NHR', 'X',\n'NHS', 'X',\n'NI1', 'X',\n'N\
I2', 'X',\n'NIC', 'X',\n'NID', 'X',\n'NIK', 'X',\n\
'NIO', 'X',\n'NIP', 'X',\n'NIT', 'X',\n'NIU', 'X',\
\n'NIY', 'Y',\n'NLA', 'X',\n'NLE', 'L',\n'NLG', 'X\
',\n'NLN', 'L',\n'NLP', 'L',\n'NM1', 'X',\n'NMA', \
'A',\n'NMB', 'X',\n'NMC', 'G',\n'NMD', 'X',\n'NME'\
, 'X',\n'NMN', 'X',\n'NMO', 'X',\n'NMQ', 'X',\n'NM\
X', 'X',\n'NMY', 'X',\n'NNH', 'R',\n'NNO', 'X',\n'\
NO2', 'X',\n'NO3', 'X',\n'NOA', 'X',\n'NOD', 'X',\\
n'NOJ', 'X',\n'NON', 'X',\n'NOP', 'X',\n'NOR', 'X'\
,\n'NOS', 'X',\n'NOV', 'X',\n'NOX', 'X',\n'NP3', '\
X',\n'NPA', 'X',\n'NPC', 'X',\n'NPD', 'X',\n'NPE',\
 'X',\n'NPF', 'X',\n'NPH', 'C',\n'NPI', 'X',\n'NPL\
', 'X',\n'NPN', 'X',\n'NPO', 'X',\n'NPP', 'X',\n'N\
PT', 'X',\n'NPY', 'X',\n'NRG', 'R',\n'NRI', 'X',\n\
'NS1', 'X',\n'NS5', 'X',\n'NSP', 'X',\n'NTA', 'X',\
\n'NTB', 'X',\n'NTC', 'X',\n'NTH', 'X',\n'NTM', 'X\
',\n'NTP', 'X',\n'NTS', 'X',\n'NTU', 'X',\n'NTZ', \
'X',\n'NU1', 'X',\n'NVA', 'V',\n'NVI', 'X',\n'NVP'\
, 'X',\n'NW1', 'X',\n'NYP', 'X',\n'O4M', 'X',\n'OA\
A', 'X',\n'OAI', 'X',\n'OAP', 'X',\n'OAR', 'X',\n'\
OAS', 'S',\n'OBA', 'X',\n'OBN', 'X',\n'OC1', 'X',\\
n'OC2', 'X',\n'OC3', 'X',\n'OC4', 'X',\n'OC5', 'X'\
,\n'OC6', 'X',\n'OC7', 'X',\n'OCL', 'X',\n'OCM', '\
X',\n'OCN', 'X',\n'OCO', 'X',\n'OCP', 'X',\n'OCS',\
 'C',\n'OCT', 'X',\n'OCV', 'K',\n'OCY', 'C',\n'ODA\
', 'X',\n'ODS', 'X',\n'OES', 'X',\n'OET', 'X',\n'O\
F1', 'X',\n'OF2', 'X',\n'OF3', 'X',\n'OFL', 'X',\n\
'OFO', 'X',\n'OHE', 'X',\n'OHO', 'X',\n'OHT', 'X',\
\n'OIC', 'X',\n'OIP', 'X',\n'OKA', 'X',\n'OLA', 'X\
',\n'OLE', 'X',\n'OLI', 'X',\n'OLO', 'X',\n'OMB', \
'X',\n'OMC', 'X',\n'OMD', 'X',\n'OME', 'X',\n'OMG'\
, 'X',\n'OMP', 'X',\n'OMT', 'M',\n'OMU', 'X',\n'ON\
E', 'X',\n'ONL', 'L',\n'ONP', 'X',\n'OPA', 'X',\n'\
OPD', 'X',\n'OPE', 'X',\n'OPG', 'X',\n'OPH', 'X',\\
n'OPN', 'X',\n'OPP', 'X',\n'OPR', 'R',\n'ORN', 'X'\
,\n'ORO', 'X',\n'ORP', 'X',\n'OSB', 'X',\n'OSS', '\
X',\n'OTA', 'X',\n'OTB', 'X',\n'OTE', 'X',\n'OTG',\
 'X',\n'OUT', 'X',\n'OVA', 'X',\n'OWQ', 'X',\n'OXA\
', 'X',\n'OXE', 'X',\n'OXI', 'X',\n'OXL', 'X',\n'O\
XM', 'X',\n'OXN', 'X',\n'OXO', 'X',\n'OXP', 'X',\n\
'OXS', 'X',\n'OXY', 'X',\n'P11', 'A',\n'P24', 'X',\
\n'P28', 'X',\n'P2P', 'X',\n'P2U', 'X',\n'P3M', 'X\
',\n'P4C', 'X',\n'P4P', 'X',\n'P5P', 'X',\n'P6G', \
'X',\n'PA1', 'X',\n'PA2', 'X',\n'PA3', 'X',\n'PA4'\
, 'X',\n'PA5', 'X',\n'PAA', 'X',\n'PAB', 'X',\n'PA\
C', 'X',\n'PAD', 'X',\n'PAE', 'X',\n'PAG', 'X',\n'\
PAH', 'X',\n'PAI', 'X',\n'PAL', 'D',\n'PAM', 'X',\\
n'PAN', 'X',\n'PAO', 'X',\n'PAP', 'A',\n'PAQ', 'F'\
,\n'PAR', 'X',\n'PAS', 'X',\n'PAT', 'W',\n'PBA', '\
X',\n'PBB', 'X',\n'PBC', 'X',\n'PBF', 'F',\n'PBG',\
 'X',\n'PBI', 'X',\n'PBM', 'X',\n'PBN', 'X',\n'PBP\
', 'X',\n'PBR', 'X',\n'PBZ', 'X',\n'PC2', 'X',\n'P\
CA', 'E',\n'PCB', 'X',\n'PCD', 'X',\n'PCE', 'X',\n\
'PCG', 'X',\n'PCH', 'X',\n'PCL', 'X',\n'PCM', 'X',\
\n'PCP', 'X',\n'PCR', 'X',\n'PCS', 'X',\n'PCU', 'X\
',\n'PCV', 'X',\n'PCY', 'X',\n'PD1', 'X',\n'PDA', \
'X',\n'PDC', 'X',\n'PDD', 'A',\n'PDE', 'A',\n'PDI'\
, 'X',\n'PDL', 'A',\n'PDN', 'X',\n'PDO', 'X',\n'PD\
P', 'X',\n'PDT', 'X',\n'PDU', 'X',\n'PE2', 'X',\n'\
PE6', 'X',\n'PEA', 'X',\n'PEB', 'X',\n'PEC', 'X',\\
n'PED', 'X',\n'PEE', 'X',\n'PEF', 'X',\n'PEG', 'X'\
,\n'PEL', 'X',\n'PEO', 'X',\n'PEP', 'X',\n'PEQ', '\
X',\n'PER', 'X',\n'PET', 'X',\n'PFB', 'X',\n'PFC',\
 'X',\n'PFG', 'X',\n'PFL', 'X',\n'PFM', 'X',\n'PFZ\
', 'X',\n'PG4', 'X',\n'PG5', 'X',\n'PG6', 'X',\n'P\
GA', 'X',\n'PGC', 'X',\n'PGD', 'X',\n'PGE', 'X',\n\
'PGG', 'G',\n'PGH', 'X',\n'PGL', 'X',\n'PGO', 'X',\
\n'PGP', 'X',\n'PGQ', 'X',\n'PGR', 'X',\n'PGS', 'X\
',\n'PGU', 'X',\n'PGX', 'X',\n'PGY', 'G',\n'PH1', \
'X',\n'PH2', 'X',\n'PH3', 'X',\n'PHA', 'F',\n'PHB'\
, 'X',\n'PHC', 'X',\n'PHD', 'X',\n'PHE', 'F',\n'PH\
G', 'X',\n'PHH', 'X',\n'PHI', 'F',\n'PHL', 'F',\n'\
PHM', 'X',\n'PHN', 'X',\n'PHO', 'X',\n'PHP', 'X',\\
n'PHQ', 'X',\n'PHS', 'H',\n'PHT', 'X',\n'PHW', 'P'\
,\n'PHY', 'X',\n'PI1', 'X',\n'PI2', 'X',\n'PI3', '\
X',\n'PI4', 'X',\n'PI5', 'X',\n'PI6', 'X',\n'PI7',\
 'X',\n'PI8', 'X',\n'PI9', 'X',\n'PIA', 'X',\n'PIB\
', 'X',\n'PIC', 'X',\n'PID', 'X',\n'PIG', 'X',\n'P\
IH', 'X',\n'PIM', 'X',\n'PIN', 'X',\n'PIO', 'X',\n\
'PIP', 'X',\n'PIQ', 'X',\n'PIR', 'X',\n'PIV', 'X',\
\n'PKF', 'X',\n'PL1', 'X',\n'PL9', 'X',\n'PLA', 'D\
',\n'PLC', 'X',\n'PLE', 'L',\n'PLG', 'G',\n'PLH', \
'X',\n'PLM', 'X',\n'PLP', 'X',\n'PLS', 'S',\n'PLT'\
, 'W',\n'PLU', 'L',\n'PLY', 'X',\n'PMA', 'X',\n'PM\
B', 'X',\n'PMC', 'X',\n'PME', 'F',\n'PML', 'X',\n'\
PMM', 'X',\n'PMO', 'X',\n'PMP', 'X',\n'PMS', 'X',\\
n'PMY', 'X',\n'PN2', 'X',\n'PNA', 'X',\n'PNB', 'X'\
,\n'PNC', 'G',\n'PND', 'X',\n'PNE', 'A',\n'PNF', '\
X',\n'PNG', 'X',\n'PNI', 'X',\n'PNL', 'X',\n'PNM',\
 'X',\n'PNN', 'X',\n'PNO', 'X',\n'PNP', 'X',\n'PNQ\
', 'X',\n'PNS', 'X',\n'PNT', 'X',\n'PNU', 'X',\n'P\
O2', 'X',\n'PO4', 'X',\n'POB', 'X',\n'POC', 'X',\n\
'POL', 'X',\n'POM', 'P',\n'PON', 'X',\n'POP', 'X',\
\n'POR', 'X',\n'POS', 'X',\n'PP1', 'X',\n'PP2', 'X\
',\n'PP3', 'A',\n'PP4', 'X',\n'PP5', 'X',\n'PP6', \
'X',\n'PP7', 'X',\n'PP8', 'N',\n'PP9', 'X',\n'PPB'\
, 'X',\n'PPC', 'X',\n'PPD', 'X',\n'PPE', 'E',\n'PP\
G', 'X',\n'PPH', 'F',\n'PPI', 'X',\n'PPJ', 'V',\n'\
PPL', 'X',\n'PPM', 'X',\n'PPN', 'A',\n'PPO', 'X',\\
n'PPP', 'X',\n'PPQ', 'X',\n'PPR', 'X',\n'PPS', 'X'\
,\n'PPT', 'X',\n'PPU', 'X',\n'PPX', 'F',\n'PPY', '\
X',\n'PPZ', 'X',\n'PQ0', 'X',\n'PQN', 'X',\n'PQQ',\
 'X',\n'PR1', 'X',\n'PR2', 'X',\n'PR3', 'X',\n'PRA\
', 'X',\n'PRB', 'X',\n'PRC', 'X',\n'PRD', 'X',\n'P\
RE', 'X',\n'PRF', 'X',\n'PRH', 'X',\n'PRI', 'P',\n\
'PRL', 'X',\n'PRN', 'X',\n'PRO', 'P',\n'PRP', 'X',\
\n'PRR', 'A',\n'PRS', 'P',\n'PRZ', 'X',\n'PS0', 'X\
',\n'PSA', 'X',\n'PSD', 'X',\n'PSE', 'X',\n'PSF', \
'S',\n'PSG', 'X',\n'PSI', 'X',\n'PSO', 'X',\n'PSQ'\
, 'X',\n'PSS', 'X',\n'PST', 'X',\n'PSU', 'X',\n'PT\
1', 'X',\n'PT3', 'X',\n'PTA', 'X',\n'PTC', 'X',\n'\
PTD', 'X',\n'PTE', 'X',\n'PTH', 'Y',\n'PTL', 'X',\\
n'PTM', 'Y',\n'PTN', 'X',\n'PTO', 'X',\n'PTP', 'X'\
,\n'PTR', 'Y',\n'PTS', 'X',\n'PTT', 'X',\n'PTU', '\
X',\n'PTY', 'X',\n'PUA', 'X',\n'PUB', 'X',\n'PUR',\
 'X',\n'PUT', 'X',\n'PVA', 'X',\n'PVB', 'X',\n'PVH\
', 'H',\n'PVL', 'X',\n'PXA', 'X',\n'PXF', 'X',\n'P\
XG', 'X',\n'PXP', 'X',\n'PXY', 'X',\n'PXZ', 'X',\n\
'PY2', 'X',\n'PY4', 'X',\n'PY5', 'X',\n'PY6', 'X',\
\n'PYA', 'A',\n'PYC', 'X',\n'PYD', 'X',\n'PYE', 'X\
',\n'PYL', 'X',\n'PYM', 'X',\n'PYO', 'X',\n'PYP', \
'X',\n'PYQ', 'X',\n'PYR', 'X',\n'PYS', 'X',\n'PYT'\
, 'X',\n'PYX', 'X',\n'PYY', 'X',\n'PYZ', 'X',\n'PZ\
Q', 'X',\n'Q82', 'X',\n'QNC', 'X',\n'QND', 'X',\n'\
QSI', 'Q',\n'QTR', 'X',\n'QUA', 'X',\n'QUE', 'X',\\
n'QUI', 'X',\n'QUO', 'X',\n'R11', 'X',\n'R12', 'X'\
,\n'R13', 'X',\n'R18', 'X',\n'R1P', 'X',\n'R56', '\
X',\n'R5P', 'X',\n'RA2', 'X',\n'RAD', 'X',\n'RAI',\
 'X',\n'RAL', 'X',\n'RAM', 'X',\n'RAN', 'X',\n'RAP\
', 'X',\n'RBF', 'X',\n'RBU', 'X',\n'RCA', 'X',\n'R\
CL', 'X',\n'RCO', 'X',\n'RDC', 'X',\n'RDF', 'W',\n\
'RE9', 'X',\n'REA', 'X',\n'RED', 'K',\n'REO', 'X',\
\n'REP', 'X',\n'RET', 'X',\n'RFA', 'X',\n'RFB', 'X\
',\n'RFL', 'X',\n'RFP', 'X',\n'RG1', 'X',\n'RGS', \
'X',\n'RH1', 'X',\n'RHA', 'X',\n'RHC', 'X',\n'RHD'\
, 'X',\n'RHM', 'X',\n'RHO', 'X',\n'RHQ', 'X',\n'RH\
S', 'X',\n'RIA', 'X',\n'RIB', 'X',\n'RIC', 'X',\n'\
RIF', 'X',\n'RIN', 'X',\n'RIP', 'X',\n'RIT', 'X',\\
n'RMB', 'X',\n'RMN', 'X',\n'RMP', 'X',\n'RNG', 'X'\
,\n'RNS', 'X',\n'RNT', 'X',\n'RO2', 'X',\n'RO4', '\
X',\n'ROC', 'N',\n'ROI', 'X',\n'ROM', 'X',\n'RON',\
 'V',\n'ROP', 'X',\n'ROS', 'X',\n'ROX', 'X',\n'RPA\
', 'X',\n'RPD', 'X',\n'RPH', 'X',\n'RPL', 'X',\n'R\
PP', 'X',\n'RPR', 'X',\n'RPX', 'X',\n'RQ3', 'X',\n\
'RR1', 'X',\n'RR6', 'X',\n'RRS', 'X',\n'RS1', 'X',\
\n'RS2', 'X',\n'RS7', 'X',\n'RSS', 'X',\n'RTA', 'X\
',\n'RTB', 'X',\n'RTC', 'X',\n'RTL', 'X',\n'RUB', \
'X',\n'RUN', 'X',\n'RWJ', 'X',\n'RXP', 'X',\n'S02'\
, 'X',\n'S11', 'X',\n'S1H', 'S',\n'S27', 'X',\n'S2\
C', 'C',\n'S3P', 'X',\n'S4U', 'X',\n'S57', 'X',\n'\
S58', 'X',\n'S5H', 'X',\n'S6G', 'X',\n'S80', 'X',\\
n'SAA', 'X',\n'SAB', 'X',\n'SAC', 'S',\n'SAD', 'X'\
,\n'SAE', 'X',\n'SAF', 'X',\n'SAH', 'C',\n'SAI', '\
C',\n'SAL', 'X',\n'SAM', 'M',\n'SAN', 'X',\n'SAP',\
 'X',\n'SAR', 'X',\n'SAS', 'X',\n'SB1', 'X',\n'SB2\
', 'X',\n'SB3', 'X',\n'SB4', 'X',\n'SB5', 'X',\n'S\
B6', 'X',\n'SBA', 'L',\n'SBB', 'X',\n'SBD', 'A',\n\
'SBI', 'X',\n'SBL', 'A',\n'SBN', 'X',\n'SBO', 'X',\
\n'SBR', 'X',\n'SBS', 'X',\n'SBT', 'X',\n'SBU', 'X\
',\n'SBX', 'X',\n'SC4', 'X',\n'SCA', 'X',\n'SCC', \
'X',\n'SCD', 'X',\n'SCH', 'C',\n'SCI', 'X',\n'SCL'\
, 'X',\n'SCM', 'X',\n'SCN', 'X',\n'SCO', 'X',\n'SC\
P', 'S',\n'SCR', 'X',\n'SCS', 'X',\n'SCV', 'C',\n'\
SCY', 'C',\n'SD8', 'X',\n'SDK', 'X',\n'SDZ', 'X',\\
n'SE4', 'X',\n'SEA', 'X',\n'SEB', 'S',\n'SEC', 'X'\
,\n'SEG', 'A',\n'SEI', 'X',\n'SEL', 'S',\n'SEM', '\
X',\n'SEO', 'X',\n'SEP', 'S',\n'SER', 'S',\n'SES',\
 'X',\n'SET', 'S',\n'SEU', 'X',\n'SF4', 'X',\n'SFG\
', 'X',\n'SFN', 'X',\n'SFO', 'X',\n'SGA', 'X',\n'S\
GC', 'X',\n'SGL', 'X',\n'SGM', 'X',\n'SGN', 'X',\n\
'SGP', 'X',\n'SHA', 'X',\n'SHC', 'X',\n'SHF', 'X',\
\n'SHH', 'X',\n'SHP', 'G',\n'SHR', 'E',\n'SHT', 'T\
',\n'SHU', 'X',\n'SI2', 'X',\n'SIA', 'X',\n'SIF', \
'X',\n'SIG', 'X',\n'SIH', 'X',\n'SIM', 'X',\n'SIN'\
, 'X',\n'SKD', 'X',\n'SKF', 'X',\n'SLB', 'X',\n'SL\
E', 'X',\n'SLZ', 'K',\n'SMA', 'X',\n'SMC', 'C',\n'\
SME', 'M',\n'SML', 'X',\n'SMM', 'M',\n'SMN', 'X',\\
n'SMP', 'X',\n'SMS', 'X',\n'SN1', 'X',\n'SN6', 'X'\
,\n'SN7', 'X',\n'SNC', 'C',\n'SNN', 'X',\n'SNP', '\
X',\n'SO1', 'X',\n'SO2', 'X',\n'SO3', 'X',\n'SO4',\
 'X',\n'SOA', 'X',\n'SOC', 'C',\n'SOM', 'X',\n'SOR\
', 'X',\n'SOT', 'X',\n'SOX', 'X',\n'SPA', 'X',\n'S\
PB', 'X',\n'SPC', 'X',\n'SPD', 'X',\n'SPE', 'X',\n\
'SPG', 'X',\n'SPH', 'X',\n'SPI', 'X',\n'SPK', 'X',\
\n'SPM', 'X',\n'SPN', 'X',\n'SPO', 'X',\n'SPP', 'X\
',\n'SPS', 'X',\n'SPY', 'X',\n'SQU', 'X',\n'SRA', \
'X',\n'SRB', 'X',\n'SRD', 'X',\n'SRL', 'X',\n'SRM'\
, 'X',\n'SRS', 'X',\n'SRY', 'X',\n'SSA', 'X',\n'SS\
B', 'X',\n'SSG', 'X',\n'SSP', 'X',\n'ST1', 'X',\n'\
ST2', 'X',\n'ST3', 'X',\n'ST4', 'X',\n'ST5', 'X',\\
n'ST6', 'X',\n'STA', 'X',\n'STB', 'X',\n'STE', 'X'\
,\n'STG', 'X',\n'STI', 'X',\n'STL', 'X',\n'STN', '\
X',\n'STO', 'X',\n'STP', 'X',\n'STR', 'X',\n'STU',\
 'X',\n'STY', 'Y',\n'SU1', 'X',\n'SU2', 'X',\n'SUC\
', 'X',\n'SUI', 'X',\n'SUL', 'X',\n'SUR', 'X',\n'S\
VA', 'S',\n'SWA', 'X',\n'T16', 'X',\n'T19', 'X',\n\
'T23', 'X',\n'T29', 'X',\n'T33', 'X',\n'T3P', 'X',\
\n'T42', 'A',\n'T44', 'X',\n'T5A', 'X',\n'T6A', 'T\
',\n'T6P', 'X',\n'T80', 'X',\n'T87', 'X',\n'TA1', \
'X',\n'TAA', 'X',\n'TAB', 'X',\n'TAC', 'X',\n'TAD'\
, 'X',\n'TAF', 'X',\n'TAM', 'X',\n'TAP', 'X',\n'TA\
R', 'X',\n'TAS', 'X',\n'TAU', 'X',\n'TAX', 'X',\n'\
TAZ', 'X',\n'TB9', 'X',\n'TBA', 'X',\n'TBD', 'X',\\
n'TBG', 'G',\n'TBH', 'X',\n'TBM', 'T',\n'TBO', 'X'\
,\n'TBP', 'X',\n'TBR', 'X',\n'TBS', 'X',\n'TBT', '\
X',\n'TBU', 'X',\n'TBZ', 'X',\n'TC4', 'X',\n'TCA',\
 'X',\n'TCB', 'X',\n'TCH', 'X',\n'TCK', 'X',\n'TCL\
', 'X',\n'TCM', 'X',\n'TCN', 'X',\n'TCP', 'X',\n'T\
CR', 'W',\n'TCS', 'X',\n'TCZ', 'X',\n'TDA', 'X',\n\
'TDB', 'X',\n'TDG', 'X',\n'TDP', 'X',\n'TDR', 'X',\
\n'TDX', 'X',\n'TEA', 'X',\n'TEM', 'X',\n'TEN', 'X\
',\n'TEO', 'X',\n'TEP', 'X',\n'TER', 'X',\n'TES', \
'X',\n'TET', 'X',\n'TFA', 'X',\n'TFB', 'X',\n'TFH'\
, 'X',\n'TFI', 'X',\n'TFK', 'X',\n'TFP', 'X',\n'TH\
A', 'X',\n'THB', 'X',\n'THC', 'T',\n'THD', 'X',\n'\
THE', 'X',\n'THF', 'X',\n'THJ', 'X',\n'THK', 'X',\\
n'THM', 'X',\n'THN', 'X',\n'THO', 'T',\n'THP', 'X'\
,\n'THQ', 'X',\n'THR', 'T',\n'THS', 'X',\n'THT', '\
X',\n'THU', 'X',\n'THX', 'X',\n'THZ', 'X',\n'TI1',\
 'X',\n'TI2', 'X',\n'TI3', 'P',\n'TIA', 'X',\n'TIH\
', 'A',\n'TK4', 'X',\n'TLA', 'X',\n'TLC', 'X',\n'T\
LM', 'X',\n'TLN', 'X',\n'TLX', 'X',\n'TM5', 'X',\n\
'TM6', 'X',\n'TMA', 'X',\n'TMB', 'T',\n'TMC', 'X',\
\n'TMD', 'T',\n'TME', 'X',\n'TMF', 'X',\n'TML', 'K\
',\n'TMM', 'X',\n'TMN', 'X',\n'TMP', 'X',\n'TMQ', \
'X',\n'TMR', 'X',\n'TMT', 'X',\n'TMZ', 'X',\n'TNB'\
, 'C',\n'TND', 'X',\n'TNK', 'X',\n'TNP', 'X',\n'TN\
T', 'X',\n'TOA', 'X',\n'TOB', 'X',\n'TOC', 'X',\n'\
TOL', 'X',\n'TOP', 'X',\n'TOS', 'X',\n'TOT', 'X',\\
n'TP1', 'G',\n'TP2', 'P',\n'TP3', 'E',\n'TP4', 'E'\
,\n'TP7', 'T',\n'TPA', 'X',\n'TPE', 'X',\n'TPF', '\
X',\n'TPI', 'X',\n'TPL', 'W',\n'TPM', 'X',\n'TPN',\
 'G',\n'TPO', 'T',\n'TPP', 'X',\n'TPQ', 'A',\n'TPR\
', 'P',\n'TPS', 'X',\n'TPT', 'X',\n'TPV', 'X',\n'T\
PX', 'X',\n'TPY', 'X',\n'TQ3', 'X',\n'TQ4', 'X',\n\
'TQ5', 'X',\n'TQ6', 'X',\n'TR1', 'X',\n'TRA', 'X',\
\n'TRB', 'X',\n'TRC', 'X',\n'TRD', 'X',\n'TRE', 'X\
',\n'TRF', 'W',\n'TRG', 'K',\n'TRH', 'X',\n'TRI', \
'X',\n'TRJ', 'X',\n'TRM', 'X',\n'TRN', 'W',\n'TRO'\
, 'W',\n'TRP', 'W',\n'TRQ', 'X',\n'TRS', 'X',\n'TR\
X', 'W',\n'TRZ', 'X',\n'TS2', 'X',\n'TS3', 'X',\n'\
TS4', 'X',\n'TS5', 'X',\n'TSA', 'X',\n'TSB', 'X',\\
n'TSI', 'X',\n'TSM', 'X',\n'TSN', 'X',\n'TSP', 'X'\
,\n'TSU', 'X',\n'TTA', 'X',\n'TTE', 'X',\n'TTN', '\
X',\n'TTO', 'X',\n'TTP', 'X',\n'TTX', 'X',\n'TXL',\
 'X',\n'TYA', 'Y',\n'TYB', 'Y',\n'TYD', 'X',\n'TYI\
', 'Y',\n'TYL', 'X',\n'TYM', 'W',\n'TYN', 'Y',\n'T\
YQ', 'Y',\n'TYR', 'Y',\n'TYS', 'Y',\n'TYV', 'X',\n\
'TYY', 'A',\n'TZB', 'X',\n'TZC', 'X',\n'TZE', 'X',\
\n'TZL', 'X',\n'TZO', 'X',\n'TZP', 'X',\n'U01', 'X\
',\n'U02', 'X',\n'U03', 'X',\n'U04', 'X',\n'U05', \
'X',\n'U0E', 'X',\n'U10', 'X',\n'U18', 'X',\n'U2G'\
, 'X',\n'U3P', 'X',\n'U49', 'X',\n'U55', 'X',\n'U5\
P', 'X',\n'U66', 'X',\n'U89', 'X',\n'U8U', 'X',\n'\
UAA', 'X',\n'UAG', 'A',\n'UAP', 'X',\n'UAR', 'X',\\
n'UC1', 'X',\n'UC2', 'X',\n'UC3', 'X',\n'UC4', 'X'\
,\n'UD1', 'X',\n'UD2', 'X',\n'UDP', 'X',\n'UDX', '\
X',\n'UFG', 'X',\n'UFM', 'X',\n'UFP', 'X',\n'UGA',\
 'X',\n'UIN', 'X',\n'UKP', 'A',\n'UM3', 'X',\n'UMA\
', 'A',\n'UMG', 'X',\n'UMP', 'X',\n'UNA', 'X',\n'U\
ND', 'X',\n'UNI', 'X',\n'UNK', 'X',\n'UNN', 'X',\n\
'UNX', 'X',\n'UP5', 'X',\n'UP6', 'X',\n'UPA', 'X',\
\n'UPF', 'X',\n'UPG', 'X',\n'UPP', 'X',\n'UQ1', 'X\
',\n'UQ2', 'X',\n'UQ6', 'X',\n'UR2', 'X',\n'URA', \
'X',\n'URE', 'X',\n'URF', 'X',\n'URI', 'X',\n'URS'\
, 'X',\n'UTP', 'X',\n'UVC', 'X',\n'UVW', 'X',\n'V3\
5', 'X',\n'V36', 'X',\n'V4O', 'X',\n'V7O', 'X',\n'\
VAA', 'V',\n'VAC', 'X',\n'VAD', 'V',\n'VAF', 'V',\\
n'VAG', 'X',\n'VAL', 'V',\n'VAN', 'X',\n'VAS', 'X'\
,\n'VAX', 'X',\n'VDX', 'X',\n'VDY', 'X',\n'VG1', '\
X',\n'VIB', 'X',\n'VIR', 'X',\n'VIT', 'X',\n'VK3',\
 'X',\n'VO3', 'X',\n'VO4', 'X',\n'VS1', 'F',\n'VS2\
', 'F',\n'VS3', 'F',\n'VS4', 'F',\n'VXA', 'X',\n'W\
01', 'X',\n'W02', 'X',\n'W03', 'X',\n'W11', 'X',\n\
'W33', 'X',\n'W35', 'X',\n'W42', 'X',\n'W43', 'X',\
\n'W54', 'X',\n'W56', 'X',\n'W59', 'X',\n'W71', 'X\
',\n'W84', 'X',\n'W8R', 'X',\n'W91', 'X',\n'WAY', \
'X',\n'WCC', 'X',\n'WO2', 'X',\n'WO4', 'X',\n'WRB'\
, 'X',\n'WRR', 'X',\n'WRS', 'X',\n'WW7', 'X',\n'X2\
F', 'X',\n'X7O', 'X',\n'XAA', 'X',\n'XAN', 'X',\n'\
XAO', 'X',\n'XBB', 'X',\n'XBP', 'X',\n'XDN', 'X',\\
n'XDP', 'X',\n'XIF', 'X',\n'XIM', 'X',\n'XK2', 'X'\
,\n'XL1', 'X',\n'XLS', 'X',\n'XMP', 'X',\n'XN1', '\
X',\n'XN2', 'X',\n'XN3', 'X',\n'XUL', 'X',\n'XV6',\
 'X',\n'XYD', 'X',\n'XYH', 'X',\n'XYL', 'X',\n'XYP\
', 'X',\n'XYS', 'X',\n'YOF', 'Y',\n'YRR', 'X',\n'Y\
T3', 'X',\n'YZ9', 'X',\n'Z34', 'G',\n'Z5A', 'X',\n\
'ZAF', 'X',\n'ZAP', 'X',\n'ZEB', 'X',\n'ZEN', 'X',\
\n'ZES', 'X',\n'ZID', 'X',\n'ZMR', 'X',\n'ZN3', 'X\
',\n'ZNH', 'X',\n'ZNO', 'X',\n'ZO3', 'X',\n'ZPR', \
'P',\n'ZRA', 'A',\n'ZST', 'X',\n'ZYA', 'A',\n\n\n'\
ASN','N');\n} \n\n\nsub file2head\n      {\n	my $f\
ile = shift;\n	my $size = shift;\n	my $f= new File\
Handle;\n	my $line;\n	open ($f,$file);\n	read ($f,\
$line, $size);\n	close ($f);\n	return $line;\n    \
  }\nsub file2tail\n      {\n	my $file = shift;\n	\
my $size = shift;\n	my $f= new FileHandle;\n	my $l\
ine;\n	\n	open ($f,$file);\n	seek ($f,$size*-1, 2)\
;\n	read ($f,$line, $size);\n	close ($f);\n	return\
 $line;\n      }\n\n\nsub vtmpnam\n      {\n	my $r\
=rand(100000);\n	my $f=\"file.$r.$$\";\n	while (-e\
 $f)\n	  {\n	    $f=vtmpnam();\n	  }\n	push (@TMPF\
ILE_LIST, $f);\n	return $f;\n      }\n\nsub myexit\
\n  {\n    my $code=@_[0];\n    if ($CLEAN_EXIT_ST\
ARTED==1){return;}\n    else {$CLEAN_EXIT_STARTED=\
1;}\n    ### ONLY BARE EXIT\n    exit ($code);\n  \
}\nsub set_error_lock\n    {\n      my $name = shi\
ft;\n      my $pid=$$;\n\n      \n      &lock4tc (\
$$,\"LERROR\", \"LSET\", \"$$ -- ERROR: $name $PRO\
GRAM\\n\");\n      return;\n    }\nsub set_lock\n \
 {\n    my $pid=shift;\n    my $msg= shift;\n    m\
y $p=getppid();\n    &lock4tc ($pid,\"LLOCK\",\"LR\
ESET\",\"$p$msg\\n\");\n  }\nsub unset_lock\n   {\\
n     \n    my $pid=shift;\n    &lock4tc ($pid,\"L\
LOCK\",\"LRELEASE\",\"\");\n  }\nsub shift_lock\n \
 {\n    my $from=shift;\n    my $to=shift;\n    my\
 $from_type=shift;\n    my $to_type=shift;\n    my\
 $action=shift;\n    my $msg;\n    \n    if (!&loc\
k4tc($from, $from_type, \"LCHECK\", \"\")){return \
0;}\n    $msg=&lock4tc ($from, $from_type, \"LREAD\
\", \"\");\n    &lock4tc ($from, $from_type,\"LREL\
EASE\", $msg);\n    &lock4tc ($to, $to_type, $acti\
on, $msg);\n    return;\n  }\nsub isshellpid\n  {\\
n    my $p=shift;\n    if (!lock4tc ($p, \"LLOCK\"\
, \"LCHECK\")){return 0;}\n    else\n      {\n	my \
$c=lock4tc($p, \"LLOCK\", \"LREAD\");\n	if ( $c=~/\
-SHELL-/){return 1;}\n      }\n    return 0;\n  }\\
nsub isrootpid\n  {\n    if(lock4tc (getppid(), \"\
LLOCK\", \"LCHECK\")){return 0;}\n    else {return\
 1;}\n  }\nsub lock4tc\n	{\n	  my ($pid,$type,$act\
ion,$value)=@_;\n	  my $fname;\n	  my $host=hostna\
me;\n	  \n	  if ($type eq \"LLOCK\"){$fname=\"$LOC\
KDIR/.$pid.$host.lock4tcoffee\";}\n	  elsif ( $typ\
e eq \"LERROR\"){ $fname=\"$LOCKDIR/.$pid.$host.er\
ror4tcoffee\";}\n	  elsif ( $type eq \"LWARNING\")\
{ $fname=\"$LOCKDIR/.$pid.$host.warning4tcoffee\";\
}\n	  \n	  if ($debug_lock)\n	    {\n	      print \
STDERR \"\\n\\t---lock4tc(tcg): $action => $fname \
=>$value (RD: $LOCKDIR)\\n\";\n	    }\n\n	  if    \
($action eq \"LCHECK\") {return -e $fname;}\n	  el\
sif ($action eq \"LREAD\"){return file2string($fna\
me);}\n	  elsif ($action eq \"LSET\") {return stri\
ng2file ($value, $fname, \">>\");}\n	  elsif ($act\
ion eq \"LRESET\") {return string2file ($value, $f\
name, \">\");}\n	  elsif ($action eq \"LRELEASE\")\
 \n	    {\n	      if ( $debug_lock)\n		{\n		  my $\
g=new FileHandle;\n		  open ($g, \">>$fname\");\n	\
	  print $g \"\\nDestroyed by $$\\n\";\n		  close \
($g);\n		  safe_system (\"mv $fname $fname.old\");\
\n		}\n	      else\n		{\n		  unlink ($fname);\n		}\
\n	    }\n	  return \"\";\n	}\n	\nsub file2string\\
n	{\n	  my $file=@_[0];\n	  my $f=new FileHandle;\\
n	  my $r;\n	  open ($f, \"$file\");\n	  while (<$\
f>){$r.=$_;}\n	  close ($f);\n	  return $r;\n	}\ns\
ub string2file \n    {\n    my ($s,$file,$mode)=@_\
;\n    my $f=new FileHandle;\n    \n    open ($f, \
\"$mode$file\");\n    print $f  \"$s\";\n    close\
 ($f);\n  }\n\nBEGIN\n    {\n      srand;\n    \n \
     $SIG{'SIGUP'}='signal_cleanup';\n      $SIG{'\
SIGINT'}='signal_cleanup';\n      $SIG{'SIGQUIT'}=\
'signal_cleanup';\n      $SIG{'SIGILL'}='signal_cl\
eanup';\n      $SIG{'SIGTRAP'}='signal_cleanup';\n\
      $SIG{'SIGABRT'}='signal_cleanup';\n      $SI\
G{'SIGEMT'}='signal_cleanup';\n      $SIG{'SIGFPE'\
}='signal_cleanup';\n      \n      $SIG{'SIGKILL'}\
='signal_cleanup';\n      $SIG{'SIGPIPE'}='signal_\
cleanup';\n      $SIG{'SIGSTOP'}='signal_cleanup';\
\n      $SIG{'SIGTTIN'}='signal_cleanup';\n      $\
SIG{'SIGXFSZ'}='signal_cleanup';\n      $SIG{'SIGI\
NFO'}='signal_cleanup';\n      \n      $SIG{'SIGBU\
S'}='signal_cleanup';\n      $SIG{'SIGALRM'}='sign\
al_cleanup';\n      $SIG{'SIGTSTP'}='signal_cleanu\
p';\n      $SIG{'SIGTTOU'}='signal_cleanup';\n    \
  $SIG{'SIGVTALRM'}='signal_cleanup';\n      $SIG{\
'SIGUSR1'}='signal_cleanup';\n\n\n      $SIG{'SIGS\
EGV'}='signal_cleanup';\n      $SIG{'SIGTERM'}='si\
gnal_cleanup';\n      $SIG{'SIGCONT'}='signal_clea\
nup';\n      $SIG{'SIGIO'}='signal_cleanup';\n    \
  $SIG{'SIGPROF'}='signal_cleanup';\n      $SIG{'S\
IGUSR2'}='signal_cleanup';\n\n      $SIG{'SIGSYS'}\
='signal_cleanup';\n      $SIG{'SIGURG'}='signal_c\
leanup';\n      $SIG{'SIGCHLD'}='signal_cleanup';\\
n      $SIG{'SIGXCPU'}='signal_cleanup';\n      $S\
IG{'SIGWINCH'}='signal_cleanup';\n      \n      $S\
IG{'INT'}='signal_cleanup';\n      $SIG{'TERM'}='s\
ignal_cleanup';\n      $SIG{'KILL'}='signal_cleanu\
p';\n      $SIG{'QUIT'}='signal_cleanup';\n      \\
n      our $debug_lock=$ENV{\"DEBUG_LOCK\"};\n    \
  \n      \n      \n      \n      foreach my $a (@\
ARGV){$CL.=\" $a\";}\n      if ( $debug_lock ){pri\
nt STDERR \"\\n\\n\\n********** START PG: $PROGRAM\
 *************\\n\";}\n      if ( $debug_lock ){pr\
int STDERR \"\\n\\n\\n**********(tcg) LOCKDIR: $LO\
CKDIR $$ *************\\n\";}\n      if ( $debug_l\
ock ){print STDERR \"\\n --- $$ -- $CL\\n\";}\n   \
   \n	     \n      \n      \n    }\nsub flush_erro\
r\n  {\n    my $msg=shift;\n    return add_error (\
$EXIT_FAILURE,$$, $$,getppid(), $msg, $CL);\n  }\n\
sub add_error \n  {\n    my $code=shift;\n    my $\
rpid=shift;\n    my $pid=shift;\n    my $ppid=shif\
t;\n    my $type=shift;\n    my $com=shift;\n    \\
n    $ERROR_DONE=1;\n    lock4tc ($rpid, \"LERROR\\
",\"LSET\",\"$pid -- ERROR: $type\\n\");\n    lock\
4tc ($$, \"LERROR\",\"LSET\", \"$pid -- COM: $com\\
\n\");\n    lock4tc ($$, \"LERROR\",\"LSET\", \"$p\
id -- STACK: $ppid -> $pid\\n\");\n   \n    return\
 $code;\n  }\nsub add_warning \n  {\n    my $rpid=\
shift;\n    my $pid =shift;\n    my $command=shift\
;\n    my $msg=\"$$ -- WARNING: $command\\n\";\n  \
  print STDERR \"$msg\";\n    lock4tc ($$, \"LWARN\
ING\", \"LSET\", $msg);\n  }\n\nsub signal_cleanup\
\n  {\n    print dtderr \"\\n**** $$ (tcg) was kil\
led\\n\";\n    &cleanup;\n    exit ($EXIT_FAILURE)\
;\n  }\nsub clean_dir\n  {\n    my $dir=@_[0];\n  \
  if ( !-d $dir){return ;}\n    elsif (!($dir=~/tm\
p/)){return ;}#safety check 1\n    elsif (($dir=~/\
\\*/)){return ;}#safety check 2\n    else\n      {\
\n	`rm -rf $dir`;\n      }\n    return;\n  }\nsub \
cleanup\n  {\n    #print stderr \"\\n----tc: $$ Ki\
lls $PIDCHILD\\n\";\n    #kill (SIGTERM,$PIDCHILD)\
;\n    my $p=getppid();\n    $CLEAN_EXIT_STARTED=1\
;\n    \n    \n    \n    if (&lock4tc($$,\"LERROR\\
", \"LCHECK\", \"\"))\n      {\n	my $ppid=getppid(\
);\n	if (!$ERROR_DONE) \n	  {\n	    &lock4tc($$,\"\
LERROR\", \"LSET\", \"$$ -- STACK: $p -> $$\\n\");\
\n	    &lock4tc($$,\"LERROR\", \"LSET\", \"$$ -- C\
OM: $CL\\n\");\n	  }\n      }\n    my $warning=&lo\
ck4tc($$, \"LWARNING\", \"LREAD\", \"\");\n    my \
$error=&lock4tc($$,  \"LERROR\", \"LREAD\", \"\");\
\n    #release error and warning lock if root\n   \
 \n    if (isrootpid() && ($warning || $error) )\n\
      {\n	\n	print STDERR \"**************** Summa\
ry *************\\n$error\\n$warning\\n\";\n\n	&lo\
ck4tc($$,\"LERROR\",\"RELEASE\",\"\");\n	&lock4tc(\
$$,\"LWARNING\",\"RELEASE\",\"\");\n      } \n    \
\n    \n    foreach my $f (@TMPFILE_LIST)\n      {\
\n	if (-e $f){unlink ($f);} \n      }\n    foreach\
 my $d (@TMPDIR_LIST)\n      {\n	clean_dir ($d);\n\
      }\n    #No More Lock Release\n    #&lock4tc(\
$$,\"LLOCK\",\"LRELEASE\",\"\"); #release lock \n\\
n    if ( $debug_lock ){print STDERR \"\\n\\n\\n**\
******** END PG: $PROGRAM ($$) *************\\n\";\
}\n    if ( $debug_lock ){print STDERR \"\\n\\n\\n\
**********(tcg) LOCKDIR: $LOCKDIR $$ *************\
\\n\";}\n  }\nEND \n  {\n    \n    &cleanup();\n  \
}\n   \n\nsub safe_system \n{\n  my $com=shift;\n \
 my $ntry=shift;\n  my $ctry=shift;\n  my $pid;\n \
 my $status;\n  my $ppid=getppid();\n  if ($com eq\
 \"\"){return 1;}\n  \n  \n\n  if (($pid = fork ()\
) < 0){return (-1);}\n  if ($pid == 0)\n    {\n   \
   set_lock($$, \" -SHELL- $com (tcg)\");\n      e\
xec ($com);\n    }\n  else\n    {\n      lock4tc (\
$$, \"LLOCK\", \"LSET\", \"$pid\\n\");#update pare\
nt\n      $PIDCHILD=$pid;\n    }\n  if ($debug_loc\
k){printf STDERR \"\\n\\t .... safe_system (fasta_\
seq2hmm)  p: $$ c: $pid COM: $com\\n\";}\n\n  wait\
pid ($pid,WTERMSIG);\n\n  shift_lock ($pid,$$, \"L\
WARNING\",\"LWARNING\", \"LSET\");\n\n  if ($? == \
$EXIT_FAILURE || lock4tc($pid, \"LERROR\", \"LCHEC\
K\", \"\"))\n    {\n      if ($ntry && $ctry <$ntr\
y)\n	{\n	  add_warning ($$,$$,\"$com failed [retry\
: $ctry]\");\n	  lock4tc ($pid, \"LRELEASE\", \"LE\
RROR\", \"\");\n	  return safe_system ($com, $ntry\
, ++$ctry);\n	}\n      elsif ($ntry == -1)\n	{\n	 \
 if (!shift_lock ($pid, $$, \"LERROR\", \"LWARNING\
\", \"LSET\"))\n	    {\n	      add_warning ($$,$$,\
\"$com failed\");\n	    }\n	  else\n	    {\n	     \
 lock4tc ($pid, \"LRELEASE\", \"LERROR\", \"\");\n\
	    }\n	  return $?;}\n      else\n	{\n	  if (!sh\
ift_lock ($pid,$$, \"LERROR\",\"LERROR\", \"LSET\"\
))\n	    {\n	      myexit(add_error ($EXIT_FAILURE\
,$$,$pid,getppid(), \"UNSPECIFIED system\", $com))\
;\n	    }\n	}\n    }\n  return $?;\n}\n\nsub check\
_configuration \n    {\n      my @l=@_;\n      my \
$v;\n      foreach my $p (@l)\n	{\n	  \n	  if   ( \
$p eq \"EMAIL\")\n	    { \n	      if ( !($EMAIL=~/\
@/))\n		{\n		add_warning($$,$$,\"Could Not Use EMA\
IL\");\n		myexit(add_error ($EXIT_FAILURE,$$,$$,ge\
tppid(),\"EMAIL\",\"$CL\"));\n	      }\n	    }\n	 \
 elsif( $p eq \"INTERNET\")\n	    {\n	      if ( !\
&check_internet_connection())\n		{\n		  myexit(add\
_error ($EXIT_FAILURE,$$,$$,getppid(),\"INTERNET\"\
,\"$CL\"));\n		}\n	    }\n	  elsif( $p eq \"wget\"\
)\n	    {\n	      if (!&pg_is_installed (\"wget\")\
 && !&pg_is_installed (\"curl\"))\n		{\n		  myexit\
(add_error ($EXIT_FAILURE,$$,$$,getppid(),\"PG_NOT\
_INSTALLED:wget\",\"$CL\"));\n		}\n	    }\n	  elsi\
f( !(&pg_is_installed ($p)))\n	    {\n	      myexi\
t(add_error ($EXIT_FAILURE,$$,$$,getppid(),\"PG_NO\
T_INSTALLED:$p\",\"$CL\"));\n	    }\n	}\n      ret\
urn 1;\n    }\nsub pg_is_installed\n  {\n    my @m\
l=@_;\n    my $r, $p, $m;\n    my $supported=0;\n \
   \n    my $p=shift (@ml);\n    if ($p=~/::/)\n  \
    {\n	if (safe_system (\"perl -M$p -e 1\")==$EXI\
T_SUCCESS){return 1;}\n	else {return 0;}\n      }\\
n    else\n      {\n	$r=`which $p 2>/dev/null`;\n	\
if ($r eq \"\"){return 0;}\n	else {return 1;}\n   \
   }\n  }\n\n\n\nsub check_internet_connection\n  \
{\n    my $internet;\n    my $tmp;\n    &check_con\
figuration ( \"wget\"); \n    \n    $tmp=&vtmpnam \
();\n    \n    if     (&pg_is_installed    (\"wget\
\")){`wget www.google.com -O$tmp >/dev/null 2>/dev\
/null`;}\n    elsif  (&pg_is_installed    (\"curl\\
")){`curl www.google.com -o$tmp >/dev/null 2>/dev/\
null`;}\n    \n    if ( !-e $tmp || -s $tmp < 10){\
$internet=0;}\n    else {$internet=1;}\n    if (-e\
 $tmp){unlink $tmp;}\n\n    return $internet;\n  }\
\nsub check_pg_is_installed\n  {\n    my @ml=@_;\n\
    my $r=&pg_is_installed (@ml);\n    if (!$r && \
$p=~/::/)\n      {\n	print STDERR \"\\nYou Must In\
stall the perl package $p on your system.\\nRUN:\\\
n\\tsudo perl -MCPAN -e 'install $pg'\\n\";\n     \
 }\n    elsif (!$r)\n      {\n	myexit(flush_error(\
\"\\nProgram $p Supported but Not Installed on you\
r system\"));\n      }\n    else\n      {\n	return\
 1;\n      }\n  }\n\n\nsub remote_is_pdb_name_depr\
ecated\n{\n    my $in=@_[0];\n    my ($ref_file, $\
pdb);\n    my ($value,$value1,$value2);\n    my $m\
ax=2;\n    \n    \n    \n    $ref_file=\"$cache/pd\
b_entry_type.txt\";\n    \n    if ( $in=~/[^\\w\\d\
\\:\\_]/){return 0;}\n    elsif ($no_remote_pdb_di\
r==1)\n      {\n	my $pdbdir=$ENV{'PDB_DIR'};\n	\n	\
my $r1=\"$pdbdir/derived_data/pdb_entry_type.txt\"\
;\n	my $r2=$ref_file;\n	if    (-e $r1){$ref_file=$\
r1;}\n	elsif (-e $r2){$ref_file=$r2;}\n	else\n	  {\
\n	    my $p=substr ($in,0, 4);\n	    add_warning \
($$, $$, \"Cannot find pdb_entry_type.txt;  $p is \
assumed to be valid; add ftp://ftp.wwpdb.org/pub/p\
db/derived_data/pdb_entry_type.txt in $cache to ch\
eck name status\");\n	  }\n      }\n    elsif ( !-\
e $ref_file || (-M $ref_file)>$max || -z $ref_file\
)\n      {\n	&url2file(\"ftp://ftp.wwpdb.org/pub/p\
db/derived_data/pdb_entry_type.txt\", $ref_file);\\
n      }\n    $pdb=substr ($in,0, 4);\n    chomp((\
$value1=`grep -c $pdb $ref_file`));\n    $pdb=lc($\
pdb);\n    chomp(($value2=`grep -c $pdb $ref_file`\
));\n    $value=($value1 || $value2)?1:0;\n    $va\
lue=($value>0)?1:0;\n    \n    return $value;\n  }\
\n","use Cwd;\nuse Env;\nuse File::Path;\nuse File\
Handle;\nuse strict;\n\n\nour (%MODE, %PG, %ENV_SE\
T, %SUPPORTED_OS);\n\nour $VERSION=\"0\"; #_#UPDAT\
E_VERSION\n\nour $EXIT_SUCCESS=0;\nour $EXIT_FAILU\
RE=1;\nour $INTERNET=0;\n\nour $CP=\"cp \"; #was c\
ausing a crash on MacOSX\nour $SILENT=\">/dev/null\
 2>/dev/null\";\nour $WEB_BASE=\"http://www.tcoffe\
e.org\";\nour $TCLINKDB_ADDRESS=\"$WEB_BASE/Resour\
ces/tclinkdb.txt\";\nour $OS=get_os();\nour $ROOT=\
&get_root();\nour $CD=cwd();\nour $CDIR=$CD;\nour \
$HOME=$ENV{'HOME'};\n\nour $OSNAME=$ENV{'OSNAME'};\
\nour $OSARCH=$ENV{'OSARCH'};\nour $REPO_ROOT=\"\"\
;\n\nour $TCDIR;\nour $TCCACHE;\nour $TCTMP;\nour \
$TCM;\nour $TCMETHODS;\nour $TCPLUGINS;\nour $PLUG\
INS_DIR=\"\";\nour $INSTALL_DIR=\"\";\nour $email;\
\nour $recompile;\n\nour $CXX=\"g++\";\nour $CXXFL\
AGS=\"\";\n\nour $CPP=\"g++\";\nour $CPPFLAGS=\"\"\
;\n\nour $CC=\"gcc\";\nour $CFLAGS=$ENV{'CFLAGS'};\
\n\nour $FC=\"f77\";\nour $FFLAGS=\"\";\n\nmy $ins\
tall=\"all\";\nmy $default_update_action=\"no_upda\
te\";\nmy @required_applications=(\"wget_OR_curl\"\
);\nmy @smode=(\"all\", \"clean\", \"install\");\n\
\n&initialize_PG();\nmy $cl=join( \" \", @ARGV);\n\
if ($#ARGV==-1 || ($cl=~/-h/) ||($cl=~/-H/) )\n  {\
\n     print \"\\n!!!!!!! ./install  t_coffee     \
        --> installs t_coffee only\";\n     print \
\"\\n!!!!!!! ./install  all                  --> i\
nstalls all the modes [mcoffee, expresso, psicoffe\
e,rcoffee..]\";\n     print \"\\n!!!!!!! ./install\
  [mcoffee|rcoffee|..] --> installs the specified \
mode\";\n     print \"\\n!!!!!!! ./install  -h    \
               --> print usage\\n\\n\";\n     if (\
 $#ARGV==-1){exit ($EXIT_FAILURE);}\n   }\n     \n\
if (($cl=~/-h/) ||($cl=~/-H/) )\n  {\n    my $m;\n\
    print \"\\n\\n!!!!!!! advanced mode\\n\";\n   \
 foreach $m ((keys (%MODE)),@smode)\n      {\n	pri\
nt \"!!!!!!!       ./install $m\\n\";\n      }\n  \
  \n    print \"!!!!!!! ./install [target:package|\
mode|] [-update|-force|-exec=dir|-dis=dir|-root|-t\
clinkdb=file|-] [CC=|FCC=|CXX=|CFLAGS=|CXXFLAGS=]\\
\n\";\n    print \"!!!!!!! ./install clean    [rem\
oves all executables]\\n\";\n    print \"!!!!!!! .\
/install [optional:target] -update               [\
updates package already installed]\\n\";\n    prin\
t \"!!!!!!! ./install [optional:target] -recompile\
            [forces the recompilation of T-Coffee]\
\\n\";\n\n    print \"!!!!!!! ./install [optional:\
target] -force                [Forces recompilatio\
n over everything]\\n\";\n    \n    print \"!!!!!!\
! ./install [optional:target] -root               \
  [You are running as root]\\n\";\n    print \"!!!\
!!!! ./install [optional:target] -exec=/foo/bar/  \
     [address for the T-Coffee executable]\\n\";\n\
    print \"!!!!!!! ./install [optional:target] -d\
is=/foo/bar/        [Address where distributions s\
hould be stored]\\n\";\n    print \"!!!!!!! ./inst\
all [optional:target] -tclinkdb=foo|update  [file \
containing all the packages to be installed]\\n\";\
\n    print \"!!!!!!! ./install [optional:target] \
-clean                [clean everything]\\n\";\n  \
  print \"!!!!!!! ./install [optional:target] -plu\
gins              [plugins directory]\\n\";\n    p\
rint \"!!!!!!! ./install [optional:target] -tcdir=\
/foor/bar      [base path where T-Coffee will be i\
nstalled - default ~/.t_coffee]\\n\";\n    print \\
"!!!!!!! ./install [optional:target] -repo=/path/t\
o/repo   [binaries repository root directory]\\n\"\
;\n    print \"!!!!!!! ./install [optional:target]\
 -email=<your email>   [needed for remote BLAST]\\\
n\";\n    print \"!!!!!!! ./install [optional:targ\
et] -proxy=<proxy>   [may be needed to access remo\
te services]\\n\";\n    \n    print \"!!!!!!! mode\
:\";\n    foreach $m (keys(%MODE)){print \"$m \";}\
\n    print \"\\n\";\n    print \"!!!!!!! Packages\
:\";\n    foreach $m (keys (%PG)){print \"$m \";}\\
n    print \"\\n\";\n    \n    print \"\\n\\n\";\n\
    exit ($EXIT_FAILURE);\n  }\n\n\n\nmy (@argl)=(\
$cl=~/(\\S+=[^=]+)\\s\\w+=/g);\npush (@argl, ($cl=\
~/(\\S+=[^=]+\\S)\\s*$/g));\n\nforeach $a (@argl)\\
n  {\n    if ( ($cl=~/CXX=(.*)/)){$CXX=$1;}\n    i\
f ( ($cl=~/-CC=(.*)/    )){$CC=$1;}\n    if ( ($cl\
=~/-FC=(.*)/    )){$FC=$1;}\n    if ( ($cl=~/-CFLA\
GS=(.*)/)){$CFLAGS=$1;}\n    if ( ($cl=~/-CXXFLAGS\
=(.*)/)){$CXXFLAGS=$1;}\n  }\nour ($ROOT_INSTALL, \
$NO_QUESTION, $default_update_action,$BINARIES_ONL\
Y,$force, $default_update_action, $INSTALL_DIR, $P\
LUGINS_DIR, $DISTRIBUTIONS,$tclinkdb, $proxy, $cle\
an);\nif ( ($cl=~/-root/)){$ROOT_INSTALL=1;}\nif (\
 ($cl=~/-no_question/)){$NO_QUESTION=1;}\nif ( ($c\
l=~/-update/)){$default_update_action=\"update\";}\
\nif ( ($cl=~/-recompile/)){$recompile=1;}\n\n\n$B\
INARIES_ONLY=1;\n\nif ( ($cl=~/-nobinaries/)){$BIN\
ARIES_ONLY=0;}\nif ( ($cl=~/-force/)){$force=1;$de\
fault_update_action=\"update\"}\nif ( ($cl=~/-exec\
=\\s*(\\S+)/)){$INSTALL_DIR=$1;}\nif ( ($cl=~/-plu\
gins=\\s*(\\S+)/)){$PLUGINS_DIR=$1;}\nif ( ($cl=~/\
-dis=\\s*(\\S+)/)){$DISTRIBUTIONS=$1;}\n\nif ( ($c\
l=~/-tclinkdb=\\s*(\\S+)/)){$tclinkdb=$1;}\nif ( (\
$cl=~/-proxy=\\s*(\\S+)/)){$proxy=$1;}\nif ( ($cl=\
~/-clean/)){$clean=1;}\nif ( ($cl=~/-repo=\\s*(\\S\
+)/)){ $REPO_ROOT=$1; }\nif ( ($cl=~/-tcdir=\\s*(\\
\S+)/)){ $TCDIR=$1; }\n\nif ( ($cl=~/-email=\\s*(\\
\S+)/)){$email=$1;}\n\n\nif ($tclinkdb){&update_tc\
linkdb ($tclinkdb);}\n\n\nif( $REPO_ROOT ne \"\" )\
 {\n	if( $OSNAME eq \"\" ) { print \"You have spec\
ified the repository folder but the required \\\"O\
SNAME\\\" enviroment variable is missing. \\n\"; e\
xit 1; } \n	if( $OSARCH eq \"\" ) { print \"You ha\
ve specified the repository folder but the require\
d \\\"OSARCH\\\" enviroment variable is missing. \\
\n\"; exit 1; } \n}\n\n\nif(!$TCDIR) { $TCDIR=\"$H\
OME/.t_coffee\"; }\n&add_dir ($TCDIR);\n&add_dir (\
$TCCACHE=\"$TCDIR/cache\");\n&add_dir ($TCTMP=\"$C\
DIR/tmp\");\n&add_dir ($TCM=\"$TCDIR/mcoffee\");\n\
&add_dir ($TCMETHODS=\"$TCDIR/methods\");\n&add_di\
r ($TCPLUGINS=\"$TCDIR/plugins/$OS\");\n\n\nour $B\
ASE=\"$CD/bin\";\nour $BIN=\"$BASE/cache/binaries/\
$OS\";\nour $DOWNLOAD_DIR=\"$BASE/cache/download\"\
;\nour $DOWNLOAD_FILE=\"$DOWNLOAD_DIR/files\";\nou\
r $TMP=\"$BASE/cache/tmp\";\n\n&add_dir($BASE);\n&\
add_dir($BIN);\n&add_dir($DOWNLOAD_DIR);\n&add_dir\
($DOWNLOAD_FILE);\nif (!$DISTRIBUTIONS){$DISTRIBUT\
IONS=\"$DOWNLOAD_DIR/distributions\";}\n&add_dir (\
$DISTRIBUTIONS);\n&add_dir ($TMP);\n\n\nif    (!$P\
LUGINS_DIR && !$ROOT_INSTALL){$PLUGINS_DIR=$TCPLUG\
INS;}\nelsif (!$PLUGINS_DIR &&  $ROOT_INSTALL){$PL\
UGINS_DIR=\"/usr/local/bin/\";}\n\nif    (!$INSTAL\
L_DIR && !$ROOT_INSTALL){$INSTALL_DIR=\"$TCDIR/bin\
/$OS\";mkpath ($INSTALL_DIR);}\nelsif (!$INSTALL_D\
IR &&  $ROOT_INSTALL){$INSTALL_DIR=\"/usr/local/bi\
n/\";}\n\nif (-d \"mcoffee\"){`cp mcoffee/* $TCM`;\
}\n\n\nour $ENV_FILE=\"$TCDIR/.t_coffee_env\";\nun\
link ($ENV_FILE);\n&add2env_file ($ENV_FILE,\"EMAI\
L_4_TCOFFEE\", $email);\n&add2env_file ($ENV_FILE,\
\"http_proxy_4_TCOFFEE\", $proxy);\n&env_file2pute\
nv ($ENV_FILE);\n&set_proxy($proxy);\n\n\n\nmy ($t\
arget, $p, $r);\n$target=$p;\n\nforeach $p (  ((ke\
ys (%PG)),(keys(%MODE)),(@smode)) )\n  {\n    if (\
$ARGV[0] eq $p && $target eq \"\"){$target=$p;}\n \
 }\nif ($target eq \"\"){exit ($EXIT_FAILURE);}\n\\
n\nforeach $r (@required_applications)\n  {\n    m\
y @app_list;\n    my $i;\n    $i=0;\n    \n    @ap\
p_list=split (/_OR_/, $r);\n    foreach my $pg (@a\
pp_list)\n      {\n	$i+=&pg_is_installed ($pg);\n \
     }\n    if ($i==0)\n      {\n      print \"One\
 of the following packages must be installed to pr\
oceed: \";\n      foreach my $pg (@app_list)\n	{\n\
	  print (\"$pg \");\n	}\n      die;\n    }\n  }\n\
\n\n\n\n\n\n&sign_license_ni();\n\n\n$PG{C}{compil\
er}=get_C_compiler($CC);\n$PG{Fortran}{compiler}=g\
et_F_compiler($FC);\n$PG{CXX}{compiler}=$PG{CPP}{c\
ompiler}=$PG{GPP}{compiler}=get_CXX_compiler($CXX)\
;\nif ($CXXFLAGS){$PG{CPP}{options}=$PG{GPP}{optio\
ns}=$PG{CXX}{options}=$CXXFLAGS;}\nif ($CFLAGS ne \
\"\" ){$PG{C}{options}=$CFLAGS;}\nforeach my $c (k\
eys(%PG))\n  {\n    my $arguments;\n    if ($PG{$c\
}{compiler})\n      {\n	$arguments=\"$PG{$c}{compi\
ler_flag}=$PG{$c}{compiler} \";\n	if ($PG{$c}{opti\
ons})\n	  {\n	    $arguments.=\"$PG{$c}{options_fl\
ag}='\" . $PG{$c}{options} . \"' \";\n	  }\n	$PG{$\
c}{arguments}=$arguments;\n      }\n  }\n\nif ($PG\
{$target}){$PG{$target}{install}=1;}\nelse\n  {\n \
   foreach my $pg (keys(%PG))\n      {\n	if ( $tar\
get eq \"all\" || ($PG{$pg}{mode}=~/$target/))\n	 \
 {\n	    $PG{$pg} {install}=1;\n	  }\n      }\n  }\
\n\nforeach my $pg (keys(%PG))\n  {\n    if (!$PG{\
$pg}{update_action}){$PG{$pg}{update_action}=$defa\
ult_update_action;}\n    elsif ($PG{$pg}{update_ac\
tion} eq \"never\"){$PG{$pg}{install}=0;}\n    if \
( $force && $PG{$pg}{install})\n      {\n	`rm $BIN\
/$pg $BIN/$pg.exe $SILENT`;\n      }\n    if ($PG{\
$pg}{update_action} eq \"update\" && $PG{$pg}{inst\
all}){$PG{$pg}{update}=1;}\n  }\n\nif (($target=~/\
clean/))\n  {\n    print \"------- cleaning execut\
ables -----\\n\";\n    `rm bin/* $SILENT`;\n    ex\
it ($EXIT_SUCCESS);\n  }\n\nif ( !$PG{$target}){pr\
int \"------- Installing T-Coffee Modes\\n\";}\n\n\
foreach my $m (keys(%MODE))\n  {\n    if ( $target\
 eq \"all\" || $target eq $m)\n      {\n	print \"\\
\n------- The installer will now install the $m co\
mponents $MODE{$m}{description}\\n\";\n	foreach my\
 $pg (keys(%PG))\n	  {\n	    if ( $PG{$pg}{mode} =\
~/$m/ && $PG{$pg}{install})\n	      {\n		if ($PG{$\
pg}{touched}){print \"------- $PG{$pg}{dname}: alr\
eady processed\\n\";}\n		else {$PG{$pg}{success}=&\
install_pg($pg);$PG{$pg}{touched}=1;}\n	      }\n	\
  }\n      }\n  }\n\nif ( $PG{$target}){print \"--\
----- Installing Individual Package\\n\";}\nforeac\
h my $pg (keys (%PG))\n  {\n    \n    if ( $PG{$pg\
}{install} && !$PG{$pg}{touched})\n      {\n	print\
 \"\\n------- Install $pg\\n\";\n	$PG{$pg}{success\
}=&install_pg($pg);$PG{$pg}{touched}=1;\n      }\n\
  }\nprint \"------- Finishing The installation\\n\
\";\nmy $final_report=&install ($INSTALL_DIR);\n\n\
print \"\\n\";\nprint \"**************************\
*******************************************\\n\";\\
nprint \"********              INSTALLATION SUMMAR\
Y          *****************\\n\";\nprint \"******\
**************************************************\
*************\\n\";\nprint \"------- SUMMARY packa\
ge Installation:\\n\";\nprint \"-------   Executab\
le Installed in: $PLUGINS_DIR\\n\";\n\nforeach my \
$pg (keys(%PG))\n  {\n    if ( $PG{$pg}{install})\\
n      {\n	my $bin_status=($PG{$pg}{from_binary} &\
& $PG{$pg}{success})?\"[from binary]\":\"\";\n	if \
    ( $PG{$pg}{new} && !$PG{$pg}{old})            \
         {print \"*------        $PG{$pg}{dname}: \
installed $bin_status\\n\"; $PG{$pg}{status}=1;}\n\
	elsif  ( $PG{$pg}{new} &&  $PG{$pg}{old})        \
             {print \"*------        $PG{$pg}{dnam\
e}: updated $bin_status\\n\"  ; $PG{$pg}{status}=1\
;} \n	elsif  (!$PG{$pg}{new} &&  $PG{$pg}{old} && \
!$PG{$pg}{update}){print \"*------        $PG{$pg}\
{dname}: previous\\n\" ; $PG{$pg}{status}=1;}\n	el\
sif  (!$PG{$pg}{new} &&  $PG{$pg}{old} &&  $PG{$pg\
}{update}){print \"*------        $PG{$pg}{dname}:\
 failed update (previous installation available)\\\
n\";$PG{$pg}{status}=0;}\n	else                   \
                                       {print \"*-\
-----        $PG{$pg}{dname}: failed installation\\
\n\";$PG{$pg}{status}=0;}\n      }\n  }\nmy $failu\
re;\n\nif ( !$PG{$target}){print \"*------ SUMMARY\
 mode Installation:\\n\";}\nforeach my $m (keys(%M\
ODE))\n  {\n  \n    if ( $target eq \"all\" || $ta\
rget eq $m)\n      {\n	my $succesful=1;\n	foreach \
my $pg (keys(%PG))\n	  {\n	    if (($PG{$pg}{mode}\
=~/$m/) && $PG{$pg}{install} && $PG{$pg}{status}==\
0)\n	      {\n		$succesful=0;\n		print \"*!!!!!!  \
     $PG{$pg}{dname}: Missing\\n\";\n	      }\n	  \
}\n	if ( $succesful)\n	  {\n	    $MODE{$m}{status}\
=1;\n	    print \"*------       MODE $MODE{$m}{dna\
me} SUCCESSFULLY installed\\n\";\n	  }\n	else\n	  \
{\n	    $failure++;\n	    $MODE{$m}{status}=0;\n	 \
   print \"*!!!!!!       MODE $MODE{$m}{dname} UNS\
UCCESSFULLY installed\\n\";\n	  }\n      }\n  }\n\\
n    \n      \nif ($clean==1 && ($BASE=~/install4t\
coffee/) ){print \"*------ Clean Installation Dire\
ctory: $BASE\\n\";`rm -rf $BASE`;}\nforeach my $pg\
 (keys(%PG)){if ($PG{$pg}{install} && $PG{$pg}{sta\
tus}==0){exit ($EXIT_FAILURE);}}\n\nif ($failure)\\
n  {\n    print \"********************************\
*************************************\\n\";\n    p\
rint \"********     SOME PACKAGES FAILED TO INSTAL\
L        *****************\\n\";\n    print \"****\
**************************************************\
***************\\n\";\n    print \"\\nSome of the \
reported failures may be due to connectivity probl\
ems\";\n    print \"\\nRerun the installation and \
the installer will specifically try to install the\
 missing packages\";\n    print \"\\nIf this Fails\
, go to the original website and install the packa\
ge manually\";\n  }\n\nprint \"*******************\
**************************************************\
\\n\";\nprint \"********              FINALIZE YOU\
R INSTALLATION    *****************\\n\";\nprint \\
"*************************************************\
********************\\n\";\nprint \"------- Your t\
hird party executables are in:\\n\"; \nprint \"---\
----       $PLUGINS_DIR:\\n\";\nprint \"------- Yo\
ur t_coffee exccutable is in\\n\";\nprint \"------\
-       $INSTALL_DIR:\\n\";\nprint \"------- In or\
der to make your installation permanent add these \
two lines\\n\";\nprint \"-------       export PATH\
=$INSTALL_DIR:\\$PATH\\n\";\nprint \"-------      \
 export PLUGINS_4_TCOFFEE=$PLUGINS_DIR:\\n\";\nif \
($OS eq \"linux\")\n  {\n    print \"-------      \
 to the file: $HOME/.bashrc\\n\";\n  }\nelse \n  {\
\n    print \"-------       to the file: $HOME/.pr\
ofile\\n\";\n  }\nexit ($EXIT_SUCCESS);  \n  \nsub\
 get_CXX_compiler\n  {\n    my $c=@_[0];\n    my (\
@clist)=(\"g++\");\n    \n    return get_compil ($\
c, @clist);\n }\nsub get_C_compiler\n  {\n    my $\
c=@_[0];\n    my (@clist)=(\"gcc\", \"cc\", \"icc\\
");\n    \n    return get_compil ($c, @clist);\n }\
\n\nsub get_F_compiler\n  {\n    my ($c)=@_[0];\n \
   my @clist=(\"f77\", \"g77\",\"g95\", \"gfortran\
\", \"ifort\");\n    return get_compil ($c, @clist\
);\n  } \n       \nsub get_compil\n  {\n    my ($f\
av,@clist)=(@_);\n    \n    #return the first comp\
iler found installed in the system. Check first th\
e favorite\n    foreach my $c ($fav,@clist)\n     \
 {\n	if  (&pg_is_installed ($c)){return $c;}\n    \
  }\n    return \"\";\n  }\nsub exit_if_pg_not_ins\
talled\n  {\n    my (@arg)=(@_);\n    \n    foreac\
h my $p (@arg)\n      {\n	if ( !&pg_is_installed (\
$p))\n	  {\n	    print \"!!!!!!!! The $p utility m\
ust be installed for this installation to proceed \
[FATAL]\\n\";\n	    die;\n	  }\n      }\n    retur\
n 1;\n  }\nsub set_proxy\n  {\n    my ($proxy)=(@_\
);\n    my (@list,$p);\n    \n    @list= (\"HTTP_p\
roxy\", \"http_proxy\", \"HTTP_PROXY\", \"ALL_prox\
y\", \"all_proxy\",\"HTTP_proxy_4_TCOFFEE\",\"http\
_proxy_4_TCOFFEE\");\n    \n    if (!$proxy)\n    \
  {\n	foreach my $p (@list)\n	  {\n	    if ( ($ENV\
_SET{$p}) || $ENV{$p}){$proxy=$ENV{$p};}\n	  }\n  \
    }\n    foreach my $p(@list){$ENV{$p}=$proxy;}\\
n  }\n	\nsub check_internet_connection\n  {\n    m\
y $internet;\n    \n    if ( -e \"x\"){unlink (\"x\
\");}\n    if     (&pg_is_installed    (\"wget\"))\
{`wget www.google.com -Ox >/dev/null 2>/dev/null`;\
}\n    elsif  (&pg_is_installed    (\"curl\")){`cu\
rl www.google.com -ox >/dev/null 2>/dev/null`;}\n \
   else\n      {\n	printf stderr \"\\nERROR: No pg\
 for remote file fetching [wget or curl][FATAL]\\n\
\";\n	exit ($EXIT_FAILURE);\n      }\n    \n    if\
 ( !-e \"x\" || -s \"x\" < 10){$internet=0;}\n    \
else {$internet=1;}\n    if (-e \"x\"){unlink \"x\\
";}\n    return $internet;\n  }\nsub url2file\n  {\
\n    my ($cmd, $file,$wget_arg, $curl_arg)=(@_);\\
n    my ($exit,$flag, $pg, $arg);\n    \n    if ($\
INTERNET || check_internet_connection ()){$INTERNE\
T=1;}\n    else\n      {\n	print STDERR \"ERROR: N\
o Internet Connection [FATAL:install.pl]\\n\";\n	e\
xit ($EXIT_FAILURE);\n      }\n    \n    if     (&\
pg_is_installed    (\"wget\")){$pg=\"wget\"; $flag\
=\"-O\";$arg=\"--tries=2 --connect-timeout=10 --no\
-check-certificate $wget_arg\";}\n    elsif  (&pg_\
is_installed    (\"curl\")){$pg=\"curl\"; $flag=\"\
-o\";$arg=$curl_arg;}\n    else\n      {\n	printf \
stderr \"\\nERROR: No pg for remote file fetching \
[wget or curl][FATAL]\\n\";\n	exit ($EXIT_FAILURE)\
;\n      }\n    \n    \n    if (-e $file){unlink($\
file);}\n    $exit=system \"$pg $cmd $flag$file $a\
rg\";\n    return $exit;\n  }\n\nsub pg_is_install\
ed\n  {\n    my ($p, $dir)=(@_);\n    my ($r,$m, $\
ret);\n    my ($supported, $language, $compil);\n \
   \n  \n    if ( $PG{$p})\n      {\n	$language=$P\
G{$p}{language2};\n	$compil=$PG{$language}{compile\
r};\n      }\n    \n    if ( $compil eq \"CPAN\")\\
n      {\n	if ( system (\"perl -M$p -e 1\")==$EXIT\
_SUCCESS){$ret=1;}\n	else {$ret=0;}\n      }\n    \
elsif ($dir)\n      {\n	if (-e \"$dir/$p\" || -e \\
"$dir/$p\\.exe\"){$ret=1;}\n	else {$ret=0;}\n     \
 }\n    elsif (-e \"$PLUGINS_DIR/$p\" || -e \"$PLU\
GINS_DIR/$p.exe\"){$ret=1;}\n    else\n      {\n	$\
r=`which $p 2>/dev/null`;\n	if ($r eq \"\"){$ret=0\
;}\n	else {$ret=1;}\n      }\n   \n    return $ret\
;\n  }\nsub install\n  {\n    my ($new_bin)=(@_);\\
n    my ($copied, $report);\n\n    \n    if (!$ROO\
T_INSTALL)\n      {\n	`$CP $BIN/* $PLUGINS_DIR`;\n\
	if (-e \"$BIN/t_coffee\")\n	  {\n	    `$CP $BIN/t\
_coffee $INSTALL_DIR`;\n	      unlink(\"$PLUGINS_D\
IR/t_coffee\");\n	  }\n	$copied=1;\n      }\n    e\
lse\n      {\n	$copied=&root_run (\"You must be ro\
ot to finalize the installation\", \"$CP $BIN/* $P\
LUGINS_DIR $SILENT\");\n	if (-e \"$BIN/t_coffee\")\
\n	  {\n	    &root_run (\"You must be root to fina\
lize the installation\", \"$CP $BIN/t_coffee $INST\
ALL_DIR\");\n	    &root_run (\"You must be root to\
 finalize the installation\", \"rm  $PLUGINS_DIR/t\
_coffee\");\n	  }\n      }\n    \n     \n  if ( !$\
copied)\n    {\n      $report=\"*!!!!!! Installati\
on unsuccesful. The executables have been left in \
$BASE/bin\\n\";\n    }\n  elsif ( $copied && $ROOT\
)\n    {\n      $report=\"*------ Installation suc\
cesful. Your executables have been copied in $new_\
bin and are on your PATH\\n\";\n    }\n  elsif ( $\
copied && !$ROOT)\n    {\n      $report= \"*!!!!!!\
 T-Coffee has been installed in $INSTALL_DIR\\n\";\
\n      $report= \"*!!!!!! T-Coffee and associated\
 packages have been copied in: $PLUGINS_DIR\\n\";\\
n      $report.=\"*!!!!!! This T-Coffee location i\
s NOT on your PATH sytem variable\\n\";\n      if \
( $OS eq \"linux\")\n	{\n	  $report.=\"*!!!!!! You\
 can do so by adding the following line in your ~/\
.bashrc file:\\n\";\n	}\n      else\n	{\n	  $repor\
t.=\"*!!!!!! You can do so by adding the following\
 line in your ~/.profile file:\\n\";\n	}\n      $r\
eport.=\"*!!!!!! export PATH=$INSTALL_DIR:\\$PATH\\
\n\";\n    }\n  return $report;\n}\n\nsub sign_lic\
ense_ni\n  {\n    my $F=new FileHandle;\n    open \
($F, \"license.txt\");\n    while (<$F>)\n      {\\
n	print \"$_\";\n      }\n    close ($F);\n    \n \
   return;\n  }\n\nsub install_pg\n  {\n    my ($p\
g)=(@_);\n    my ($report, $previous, $language, $\
compiler, $return);\n    \n    if (!$PG{$pg}{insta\
ll}){return 1;}\n    \n    $previous=&pg_is_instal\
led ($pg);\n    \n    if ($PG{$pg}{update_action} \
eq \"no_update\" && $previous)\n      {\n	$PG{$pg}\
{old}=1;\n	$PG{$pg}{new}=0;\n	$return=1;\n      }\\
n    else\n      {\n	$PG{$pg}{old}=$previous;\n	\n\
	if ($PG{$pg} {language2} eq \"Perl\"){&install_pe\
rl_package ($pg);}\n	elsif ($BINARIES_ONLY && &ins\
tall_binary_package ($pg)){$PG{$pg}{from_binary}=1\
;}\n	elsif (&install_source_package ($pg)){;}\n	el\
se \n	  {\n	    \n	    if (!&supported_os($OS))\n	\
      {\n		print \"!!!!!!!! $pg compilation failed\
, binary unsupported for $OS\\n\"; \n	      }\n	  \
  elsif (!($PG{$pg}{from_binary}=&install_binary_p\
ackage ($pg)))\n	      {\n		print \"!!!!!!!! $pg c\
ompilation and  binary installation failed\\n\";\n\
	      }\n	  }\n	$PG{$pg}{new}=$return=&pg_is_inst\
alled ($pg,$BIN);\n      }\n\n    \n    return $re\
turn;\n  }\nsub install_perl_package\n  {\n    my \
($pg)=(@_);\n    my ($report, $language, $compiler\
);\n    \n    $language=$PG{$pg} {language2};\n   \
 $compiler=$PG{$language}{compiler};\n    \n    if\
 (!&pg_is_installed ($pg))\n      {\n	if ( $OS eq \
\"windows\"){`perl -M$compiler -e 'install $pg'`;}\
\n	elsif ( $ROOT eq \"sudo\"){system (\"sudo perl \
-M$compiler -e 'install $pg'\");}\n	else {system (\
\"su root -c perl -M$compiler -e 'install $pg'\");\
}\n      }\n    return &pg_is_installed ($pg);\n  \
}\n\n\n\nsub install_source_package\n  {\n    my (\
$pg)=(@_);\n    my ($report, $download, $arguments\
, $language, $address, $name, $ext, $main_dir, $di\
strib);\n    my $wget_tmp=\"$TMP/wget.tmp\";\n    \
my (@fl);\n    if ( $default_update_action ne \"up\
date\" && (-e \"$BIN/$pg\" || -e \"$BIN/$pg.exe\" \
)  ){return 1;}\n    \n    #\n    # check if the m\
odule exists in the repository cache \n    #\n	if(\
 repo_load($pg) ) {\n		return 1;\n	}\n    \n    if\
 ($pg eq \"t_coffee\")  {return   &install_t_coffe\
e_source ($pg);}\n    elsif ($pg eq \"TMalign\"){r\
eturn   &install_TMalign ($pg);}\n    \n    chdir \
$DISTRIBUTIONS;\n    \n    $download=$PG{$pg}{sour\
ce};\n    \n    if (($download =~/tgz/))\n      {\\
n	($address,$name,$ext)=($download=~/(.+\\/)([^\\/\
]+)(\\.tgz).*/);\n      }\n    elsif (($download=~\
/tar\\.gz/))\n      {\n	($address,$name,$ext)=($do\
wnload=~/(.+\\/)([^\\/]+)(\\.tar\\.gz).*/);\n     \
 }\n    elsif (($download=~/tar/))\n      {\n	($ad\
dress,$name,$ext)=($download=~/(.+\\/)([^\\/]+)(\\\
.tar).*/);\n      }\n    else\n      {\n	($address\
,$name)=($download=~/(.+\\/)([^\\/]+)/);\n	$ext=\"\
\";\n      }\n    $distrib=\"$name$ext\";\n    \n \
   if ( !-d $pg){mkdir $pg;}\n    chdir $pg;\n   \\
n    #get the distribution if available\n    if ( \
-e \"$DOWNLOAD_DIR/$distrib\")\n      {\n	`$CP $DO\
WNLOAD_DIR/$distrib .`;\n      }\n    #UNTAR and P\
repare everything\n    if (!-e \"$name.tar\" && !-\
e \"$name\")\n      {\n	&check_rm ($wget_tmp);\n	p\
rint \"\\n------- Downloading/Installing $pg\\n\";\
\n	\n	if (!-e $distrib && &url2file (\"$download\"\
, \"$wget_tmp\")==$EXIT_SUCCESS)\n	  {\n	    \n	  \
  `mv $wget_tmp $distrib`;\n	    `$CP $distrib $DO\
WNLOAD_DIR/`;\n	  }\n\n	if (!-e $distrib)\n	  {\n	\
    print \"!!!!!!! Download of $pg distribution f\
ailed\\n\";\n	    print \"!!!!!!! Check Address: $\
PG{$pg}{source}\\n\";\n	    return 0;\n	  }\n	prin\
t \"\\n------- unzipping/untaring $name\\n\";\n	if\
 (($ext =~/z/))\n	  { \n	    &flush_command (\"gun\
zip -f $name$ext\");\n	    \n	  }\n	if (($ext =~/t\
ar/) || ($ext =~/tgz/))\n	  {\n	    &flush_command\
(\"tar -xvf $name.tar\");\n	  }\n      }\n    #Gue\
ss and enter the distribution directory\n    @fl=l\
s($p);\n    foreach my $f (@fl)\n      {\n	if (-d \
$f)\n	  {\n	    $main_dir=$f;\n	  }\n      }\n    \
if (-d $main_dir)\n	  \n      {\n	chdir $main_dir;\
}\n    else\n      {\n	print \"Error: $main_dir do\
es not exist\";\n      }\n    print \"\\n------- C\
ompiling/Installing $pg\\n\";\n    `make clean $SI\
LENT`;\n    \n    \n    #\n    # SAP module\n    #\
\n    if ($pg eq \"sap\")\n      {\n	if (-e \"./co\
nfigure\")\n	  {\n	    #new sap distribution\n	   \
 \n	    &flush_command (\"./configure\");\n	    &f\
lush_command (\"make clean\");\n	    &flush_comman\
d (\"make\");\n	    &check_cp (\"./src/$pg\", \"$B\
IN\");\n	    repo_store(\"./src/$pg\");\n	  }\n	el\
se\n	  {\n	    #old style distribution\n	    `rm *\
.o sap  sap.exe ./util/aa/*.o  ./util/wt/.o $SILEN\
T`;\n	    &flush_command (\"make $arguments sap\")\
;\n	    &check_cp ($pg, \"$BIN\");\n	    repo_stor\
e($pg);\n	  }\n      }\n    \n    #\n    # CLUSTAL\
W2 module\n    #\n    elsif ($pg eq \"clustalw2\")\
\n      {\n	&flush_command(\"./configure\");\n	&fl\
ush_command(\"make $arguments\");\n	&check_cp (\".\
/src/$pg\", \"$BIN\");\n	repo_store(\"./src/$pg\")\
;\n      }\n\n    #\n    # CLUSTAL-OMEGA module\n \
   #\n    elsif ($pg eq \"clustalo\")\n      {\n	&\
flush_command(\"./configure\");\n	&flush_command(\\
"make $arguments\");\n	&check_cp (\"./src/$pg\", \\
"$BIN\");\n	repo_store(\"./src/$pg\");\n      }\n\\
n    #\n    # STRIKE module\n    #\n    elsif ($pg\
 eq \"strike\")\n      {\n	&flush_command(\"make $\
arguments\");\n	&check_cp (\"./bin/$pg\", \"$BIN\"\
);\n	repo_store(\"./bin/$pg\");\n      }\n    \n  \
  #\n    # FSA module\n    # \n    elsif ($pg eq \\
"fsa\")\n      {\n	&flush_command(\"./configure --\
prefix=$BIN\");\n	&flush_command(\"make $arguments\
\");\n	&flush_command (\"make install\");\n\n	repo\
_store(\"fsa\", \"$BIN/bin\");\n	`mv $BIN/bin/* $B\
IN`;\n	`rmdir $BIN/bin`;\n      }\n    \n    #\n  \
  # CLUSTALW module\n    #\n    elsif ($pg eq \"cl\
ustalw\")\n      {\n	&flush_command(\"make $argume\
nts clustalw\");\n	`$CP $pg $BIN $SILENT`;\n	repo_\
store($pg);\n      }\n    \n    #\n    # MAFFT mod\
ule\n    #\n    elsif ($pg eq \"mafft\")\n      {\\
n	my $base=cwd();\n	my $c;\n	\n	#compile core\n	mk\
path (\"./mafft/bin\");\n	mkpath (\"./mafft/lib\")\
;\n	chdir \"$base/core\";\n	`make clean $SILENT`;\\
n	&flush_command (\"make $arguments\");\n	&flush_c\
ommand (\"make install LIBDIR=../mafft/lib BINDIR=\
../mafft/bin\");\n	\n	#compile extension\n	chdir \\
"$base/extensions\";\n	`make clean $SILENT`;\n	&fl\
ush_command (\"make $arguments\");\n	&flush_comman\
d (\"make install LIBDIR=../mafft/lib BINDIR=../ma\
fft/bin\");\n	\n	#put everything in mafft and copy\
 the compiled stuff in bin\n	chdir \"$base\";\n	if\
 ($ROOT_INSTALL)\n	  {\n	    &root_run (\"You Must\
 be Root to Install MAFFT\\n\", \"mkdir /usr/local\
/mafft/;$CP mafft/lib/* /usr/local/mafft;$CP mafft\
/lib/mafft* /usr/local/bin ;$CP mafft/bin/mafft /u\
sr/local/bin/; \");\n	  }\n	else\n	  {\n	    `$CP \
mafft/lib/*  $BIN`;\n	    `$CP mafft/bin/mafft  $B\
IN`;\n	  }\n	`tar -cvf mafft.tar mafft`;\n	`gzip m\
afft.tar`;\n	`mv mafft.tar.gz $BIN`;\n	\n	repo_sto\
re(\"mafft/bin/mafft\", \"mafft/lib/\", \"$BIN/maf\
ft.tar.gz\");\n      }\n      \n    #\n    # DIALI\
GN-TX module\n    #\n    elsif ( $pg eq \"dialign-\
tx\" )\n      {\n	my $f;\n	my $base=cwd();\n\n	chd\
ir \"./source\";\n	if ($OS eq \"macosx\"){&flush_c\
ommand (\"cp makefile.MAC_OS makefile\");}\n\n	&fl\
ush_command (\" make CPPFLAGS='-O3 -funroll-loops'\
 all\");\n	\n	chdir \"..\";\n	&check_cp (\"./sourc\
e/$pg\", \"$BIN\");\n	repo_store(\"./source/$pg\")\
;\n      }\n      \n    #\n    # DIALIGN-T module \
\n    # (is the same as dialign-tx, but it is mant\
ained for backward name compatibility with tcoffee\
)\n    #\n    elsif ( $pg eq \"dialign-t\" )\n    \
  {\n	my $f;\n	my $base=cwd();\n\n	chdir \"./sourc\
e\";\n	if ($OS eq \"macosx\"){&flush_command (\"cp\
 makefile.MAC_OS makefile\");}\n\n	&flush_command \
(\" make CPPFLAGS='-O3 -funroll-loops' all\");\n	\\
n	chdir \"..\";\n	&check_cp (\"./source/dialign-tx\
\", \"$BIN/dialign-t\");\n	repo_store(\"$BIN/diali\
gn-t\");	\n      }      \n      \n    #\n    # POA\
 module\n    #\n    elsif ($pg eq \"poa\")\n      \
{\n	&flush_command (\"make $arguments poa\");\n	&c\
heck_cp (\"$pg\", \"$BIN\");\n	repo_store(\"$pg\")\
;\n      }\n     \n     \n    #\n    # PROBCONS mo\
dule\n    #\n    elsif ( $pg eq \"probcons\")\n   \
   {\n	&add_C_libraries(\"./ProbabilisticModel.h\"\
, \"list\", \"cstring\");\n	\n	`rm *.exe $SILENT`;\
\n	&flush_command (\"make $arguments probcons\");\\
n	&check_cp(\"$pg\", \"$BIN/$pg\");\n	repo_store(\\
"$pg\");\n      }\n      \n    #\n    # PROBCONS R\
NA module\n    #\n    elsif ( $pg eq \"probconsRNA\
\")\n      {\n	&add_C_libraries(\"./ProbabilisticM\
odel.h\", \"list\", \"cstring\");\n	&add_C_librari\
es(\"./Main.cc\", \"iomanip\", \"cstring\",\"climi\
ts\");\n	`rm *.exe $SILENT`;\n	&flush_command (\"m\
ake $arguments probcons\");\n	&check_cp(\"probcons\
\", \"$BIN/$pg\");\n	repo_store(\"$BIN/$pg\");\n  \
    }\n\n	#\n	# MUSCLE module\n	#\n    elsif (  $p\
g eq \"muscle\")\n      {	\n	`rm *.o muscle muscle\
.exe $SILENT`;\n	if ($OS eq \"macosx\" || $OS eq \\
"linux\")\n	  {\n	    &replace_line_in_file (\"./M\
akefile\", \"LDLIBS = -lm -static\",  \"LDLIBS = -\
lm\");\n	  }\n	elsif ($OS eq \"windows\")\n	  {\n	\
    &replace_line_in_file (\"./intmath.cpp\",  \"d\
ouble log2e\",      \"double cedric_log\");\n	    \
&replace_line_in_file (\"./intmath.cpp\",  \"doubl\
e log2\",       \"double log_notuse\");\n	    &rep\
lace_line_in_file (\"./intmath.cpp\",  \"double ce\
dric_log\", \"double log2e\");\n	  }\n	&flush_comm\
and (\"make $arguments all\");\n	&check_cp(\"$pg\"\
, \"$BIN\");\n	repo_store(\"$pg\");	\n      }\n   \
   \n     #\n     # MUS4 module\n     #\n     elsi\
f (  $pg eq \"mus4\")\n      {\n	`rm *.o muscle mu\
scle.exe $SILENT`;\n	&flush_command (\"./mk\");\n	\
&check_cp(\"$pg\", \"$BIN\");\n	repo_store(\"$pg\"\
);	\n      }\n      \n    #\n    # PCMA module\n  \
  #\n    elsif ( $pg eq \"pcma\")\n      {\n	if ($\
OS eq \"macosx\")\n	  {\n	    &replace_line_in_fil\
e (\"./alcomp2.c\", \"malloc.h\",  \"\");\n	  }\n	\
&flush_command (\"make $arguments pcma\");\n	&chec\
k_cp(\"$pg\", \"$BIN\");\n	repo_store(\"$pg\");	\n\
      }\n      \n    #\n    # KALIGN module\n    #\
\n    elsif ($pg eq \"kalign\")\n      {\n	&flush_\
command (\"./configure\");\n	&flush_command(\"make\
 $arguments\");\n	&check_cp (\"$pg\",$BIN);\n	repo\
_store(\"$pg\");	\n      }\n      \n    #\n    # A\
MAP module\n    #\n    elsif ( $pg eq \"amap\")\n \
     {\n	&add_C_libraries(\"./Amap.cc\", \"iomanip\
\", \"cstring\",\"climits\");	\n	`make clean $SILE\
NT`;\n	&flush_command (\"make $arguments all\");\n\
	&check_cp (\"$pg\", $BIN);\n	repo_store(\"$pg\");\
	\n      }\n      \n    #\n    # PRODA module\n   \
 #\n    elsif ( $pg eq \"proda\")\n      {\n	`sed \
-i '' 's/int errno = 0;/int errno; errno = 0;/' Ma\
in.cc`;\n	&add_C_libraries(\"AlignedFragment.h\", \
\"vector\", \"iostream\", \"cstring\",\"cstdlib\")\
;\n	&add_C_libraries(\"Main.cc\", \"vector\", \"cl\
imits\");	\n	&add_C_libraries(\"Sequence.cc\", \"s\
tdlib.h\", \"cstdio\");	\n	&flush_command (\"make \
$arguments all\");\n	&check_cp (\"$pg\", $BIN);\n	\
repo_store(\"$pg\");	\n      }\n      \n    #\n   \
 # PRANK module\n    #\n    elsif ( $pg eq \"prank\
\")\n      {\n	&flush_command (\"make $arguments a\
ll\");\n	&check_cp (\"$pg\", $BIN);\n	repo_store(\\
"$pg\");	\n      }\n      \n    #\n    # !!!! MUST\
ANG module\n    #\n     elsif ( $pg eq \"mustang\"\
)\n      {\n	&flush_command (\"rm ./bin/*\");\n	&f\
lush_command (\"make $arguments all\");\n\n	if ( $\
OS=~/windows/){&flush_command(\"cp ./bin/* $BIN/mu\
stang.exe\");}\n	else {&flush_command(\"cp ./bin/*\
 $BIN/mustang\");}\n	\n	repo_store(\"$BIN/mustang\\
");\n      }\n\n	#\n	# RNAplfold module\n	#\n    e\
lsif ( $pg eq \"RNAplfold\")\n      {\n	&flush_com\
mand(\"./configure\");\n	&flush_command (\"make $a\
rguments all\");\n	&check_cp(\"./Progs/RNAplfold\"\
, \"$BIN\");\n	&check_cp(\"./Progs/RNAalifold\", \\
"$BIN\");\n	&check_cp(\"./Progs/RNAfold\", \"$BIN\\
");\n	\n	repo_store(\"./Progs/RNAplfold\", \"./Pro\
gs/RNAalifold\", \"./Progs/RNAfold\");\n      }\n \
     \n    #\n    # !!! RETREE module\n    #\n    \
elsif ( $pg eq \"retree\")\n      {\n	chdir \"src\\
";\n	&flush_command (\"cp Makefile.unx Makefile\")\
;\n	&flush_command (\"make $arguments all\");\n	&f\
lush_command (\"make put\");\n	system \"cp ../exe/\
* $BIN\";\n	\n	repo_store(\"retree\", \"../exe\");\
\n      }\n	\n    chdir $CDIR;\n    return &pg_is_\
installed ($pg, $BIN);\n  }\n\nsub install_t_coffe\
e_source\n  {\n    my ($pg)=(@_);\n    my ($report\
,$cflags, $arguments, $language, $compiler) ;\n\n \
   #1-Install T-Coffee\n    chdir \"t_coffee_sourc\
e\";\n    &flush_command (\"make clean\");\n    pr\
int \"\\n------- Compiling T-Coffee\\n\";\n    $la\
nguage=$PG{$pg} {language2};\n    $arguments=$PG{$\
language}{arguments};\n    \n    if ( $CC ne \"\")\
\n      {\n	print \"make -i $arguments t_coffee \\\
n\";\n	&flush_command (\"make -i $arguments t_coff\
ee\");\n      }\n    &check_cp ($pg, $BIN);\n    \\
n    chdir $CDIR;\n    return &pg_is_installed ($p\
g, $BIN);\n  }\nsub install_TMalign\n  {\n    my (\
$pg)=(@_);\n    my $report;\n    chdir \"t_coffee_\
source\";\n    print \"\\n------- Compiling TMalig\
n\\n\";\n    `rm TMalign TMalign.exe $SILENT`;\n  \
  if ( $FC ne \"\"){&flush_command (\"make -i $PG{\
Fortran}{arguments} TMalign\");}\n    &check_cp ($\
pg, $BIN);\n    repo_store($pg);\n\n    if ( !-e \\
"$BIN/$pg\" && pg_has_binary_distrib ($pg))\n     \
 {\n	print \"!!!!!!! Compilation of $pg impossible\
. Will try to install from binary\\n\";\n	return &\
install_binary_package ($pg);\n      }\n    chdir \
$CDIR;\n    return &pg_is_installed ($pg, $BIN);\n\
  }\n\nsub pg_has_binary_distrib\n  {\n    my ($pg\
)=(@_);\n    if ($PG{$pg}{windows}){return 1;}\n  \
  elsif ($PG{$pg}{osx}){return 1;}\n    elsif ($PG\
{$pg}{macosx}){return 1;}\n\n    elsif ($PG{$pg}{l\
inux}){return 1;}\n    return 0;\n  }\nsub install\
_binary_package\n  {\n    my ($pg)=(@_);\n    my (\
$base,$report,$name, $download, $arguments, $langu\
age, $dir);\n    my $isdir;\n    &input_os();\n   \
 \n    #\n    # - paolodt - Check if the module ex\
ists in the repository cache \n    #\n	if( repo_lo\
ad($pg) ) {\n	    $PG{$pg}{from_binary}=1;\n		retu\
rn 1;\n	}\n    # - paolodt - end \n    \n    if (!\
&supported_os($OS)){return 0;}\n    if ( $PG{$pg}{\
binary}){$name=$PG{$pg}{binary};}\n    else {$name\
=$pg;}\n    if ($name eq \"t_coffee\")\n      {\n	\
#check if local bin is there\n	if (-e \"./bin/$OS/\
t_coffee\")\n	  {\n	    print \"\\n------- Install\
ing  T-Coffee from Pre-Compiled/Pre-Downloaded $OS\
 binary\\n\";\n	    print \"\\n------- If you want\
 to trigger a fresh compilation use -recompile\\n\\
";\n	    &check_cp (\"./bin/$OS/t_coffee\", $BIN);\
\n	    return &pg_is_installed ($pg, $BIN);\n	  }\\
n	#try to get precompiled binary -- available from\
 MAC is distribution from MAC\n	else\n	  {\n	    $\
download=\"$WEB_BASE/Packages/Binaries/tcoffee/$OS\
/$name.$VERSION\";\n	  }\n      }\n    else\n     \
 {\n	$download=\"$WEB_BASE/Packages/Binaries/plugi\
ns/$OS/$name\";\n      }\n    \n    $base=cwd();\n\
    chdir $TMP;\n    \n    if (!-e $name)\n      {\
\n	`rm x $SILENT`;\n	if ( url2file(\"$download\",\\
"x\")==$EXIT_SUCCESS)\n	  {\n	    `mv x $name`;\n	\
  }\n      }\n    \n    if (!-e $name)\n      {\n	\
print \"!!!!!!! $PG{$pg}{dname}: Download of $pg b\
inary failed\\n\";\n	print \"!!!!!!! $PG{$pg}{dnam\
e}: Check Address: $download\\n\";\n	chdir $base;\\
n	return 0;\n      }\n    print \"\\n------- Insta\
lling $pg\\n\";\n    \n    if ($name =~/tar\\.gz/)\
\n      {\n	`gunzip  -f $name`;\n	`tar -xvf $pg.ta\
r`;\n	chdir $pg;\n	`chmod u+x *`;\n 	`mv * $BIN`;\\
n	#if (!($pg=~/\\*/)){`rm -rf $pg`;}\n      }\n   \
 else\n      {\n	&check_cp (\"$pg\", \"$BIN\");\n	\
`chmod u+x $BIN/$pg`; \n	unlink ($pg);\n      }\n \
   chdir $base;\n    $PG{$pg}{from_binary}=1;\n\n \
   return &pg_is_installed ($pg, $BIN);\n  }\n\n	\\
nsub add_dir\n  {\n    my $dir=@_[0];\n    \n    i\
f (!-e $dir && !-d $dir)\n      {\n	my @l;\n	umask\
 (0000);\n	@l=mkpath ($dir,{mode => 0777});\n	\n  \
    }\n    else\n      {\n	return 0;\n      }\n  }\
\nsub check_rm \n  {\n    my ($file)=(@_);\n    \n\
    if ( -e $file)\n      {\n	return unlink($file)\
;\n      }\n    return 0;\n  }\nsub check_cp\n  {\\
n    my ($from, $to)=(@_);\n    if ( !-e $from && \
-e \"$from\\.exe\"){$from=\"$from\\.exe\";}\n    i\
f ( !-e $from){return 0;}\n        \n    `$CP $fro\
m $to`;\n    return 1;\n  }\n\nsub repo_store \n{\\
n   # check that all required data are available\n\
   if( $REPO_ROOT eq \"\" ) { return; }\n\n\n    #\
 extract the package name from the specified path\\
n    my $pg =`basename $_[0]`;\n    chomp($pg);\n	\
\n    my $VER = $PG{$pg}{version};\n    my $CACHE \
= \"$REPO_ROOT/$pg/$VER/$OSNAME-$OSARCH\"; \n    \\
n    print \"-------- Storing package: \\\"$pg\\\"\
 to path: $CACHE\\n\";\n    \n    # clean the cach\
e path if exists and create it again\n    `rm -rf \
$CACHE`;\n    `mkdir -p $CACHE`;\n    \n 	for my $\
path (@_) {\n\n	    # check if it is a single file\
 \n	 	if( -f $path ) {\n	    	`cp $path $CACHE`;\n\
		}\n		# .. or a directory, in this case copy all \
the content \n		elsif( -d $path ) {\n			opendir(IM\
D, $path);\n			my @thefiles= readdir(IMD);\n			clo\
sedir(IMD);\n			\n			for my $_file (@thefiles) {\n\
				if( $_file ne \".\" && $_file ne \"..\") {\n	 \
   			`cp $path/$_file $CACHE`;\n				}\n			}\n		} \
\n	}	   \n    \n	\n}   \n\nsub repo_load \n{\n    \
my ($pg)=(@_);\n\n    #Bypass the Repository Cache\
\n    return 0;\n    # check that all required dat\
a are available\n    if( $REPO_ROOT eq \"\" ) { re\
turn 0; }\n\n    my $VER = $PG{$pg}{version};\n   \
 my $CACHE = \"$REPO_ROOT/$pg/$VER/$OSNAME-$OSARCH\
\"; \n    if( !-e \"$CACHE/$pg\" ) {\n   	 	print \
\"-------- Module \\\"$pg\\\" NOT found on reposit\
ory cache.\\n\";\n    	return 0;\n    }\n    \n   \
 print \"-------- Module \\\"$pg\\\" found on repo\
sitory cache. Using copy on path: $CACHE\\n\";\n  \
  `cp $CACHE/* $BIN`;\n    return 1;\n}\n\nsub che\
ck_file_list_exists \n  {\n    my ($base, @flist)=\
(@_);\n    my $f;\n\n    foreach $f (@flist)\n    \
  {\n	if ( !-e \"$base/$f\"){return 0;}\n      }\n\
    return 1;\n  }\nsub ls\n  {\n    my $f=@_[0];\\
n    my @fl;\n    chomp(@fl=`ls -1 $f`);\n    retu\
rn @fl;\n  }\nsub flush_command\n  {\n    my $comm\
and=@_[0];\n    my $F=new FileHandle;\n    open ($\
F, \"$command|\");\n    while (<$F>){print \"    -\
-- $_\";}\n    close ($F);\n  }    \n\nsub input_i\
nstallation_directory\n  {\n    my $dir=@_[0];\n  \
  my $new;\n    \n    print \"------- The current \
installation directory is: [$dir]\\n\";\n    print\
 \"??????? Return to keep the default or new value\
:\";\n   \n    if ($NO_QUESTION==0)\n      {\n	cho\
mp ($new=<stdin>);\n	while ( $new ne \"\" && !inpu\
t_yes (\"You have entered $new. Is this correct? (\
[y]/n):\"))\n	  {\n	    print \"???????New install\
ation directory:\";\n	    chomp ($new=<stdin>);\n	\
  }\n	$dir=($new eq \"\")?$dir:$new;\n	$dir=~s/\\/\
$//;\n      }\n    \n    if ( -d $dir){return $dir\
;}\n    elsif (&root_run (\"You must be root to cr\
eate $dir\",\"mkdir $dir\")==$EXIT_SUCCESS){return\
 $dir;}\n    else\n      {\n	print \"!!!!!!! $dir \
could not be created\\n\";\n	if ( $NO_QUESTION)\n	\
  {\n	    return \"\";\n	  }\n	elsif ( &input_yes \
(\"??????? Do you want to provide a new directory(\
[y]/n)?:\"))\n	  {\n	    return input_installation\
_directory ($dir);\n	  }\n	else\n	  {\n	    return\
 \"\";\n	  }\n      }\n    \n  }\nsub input_yes\n \
 {\n    my $question =@_[0];\n    my $answer;\n\n \
   if ($NO_QUESTION==1){return 1;}\n    \n    if (\
$question eq \"\"){$question=\"??????? Do you wish\
 to proceed ([y]/n)?:\";}\n    print $question;\n \
   chomp($answer=lc(<STDIN>));\n    if (($answer=~\
/^y/) || $answer eq \"\"){return 1;}\n    elsif ( \
($answer=~/^n/)){return 0;}\n    else\n      {\n	r\
eturn input_yes($question);\n      }\n  }\nsub roo\
t_run\n  {\n    my ($txt, $cmd)=(@_);\n    \n    i\
f ( system ($cmd)==$EXIT_SUCCESS){return $EXIT_SUC\
CESS;}\n    else \n      {\n	print \"------- $txt\\
\n\";\n	if ( $ROOT eq \"sudo\"){return system (\"s\
udo $cmd\");}\n	else {return system (\"su root -c \
\\\"$cmd\\\"\");}\n      }\n  }\nsub get_root\n  {\
\n    if (&pg_is_installed (\"sudo\")){return \"su\
do\";}\n    else {return \"su\";}\n  }\n\nsub get_\
os\n  {\n    my $raw_os=`uname`;\n    my $os;\n\n \
   $raw_os=lc ($raw_os);\n    \n    if ($raw_os =~\
/cygwin/){$os=\"windows\";}\n    elsif ($raw_os =~\
/linux/){$os=\"linux\";}\n    elsif ($raw_os =~/os\
x/){$os=\"macosx\";}\n    elsif ($raw_os =~/darwin\
/){$os=\"macosx\";}\n    else\n      {\n	$os=$raw_\
os;\n      }\n    return $os;\n  }\nsub input_os\n\
  {\n    my $answer;\n    if ($OS) {return $OS;}\n\
    \n    print \"??????? which os do you use: [w]\
indows, [l]inux, [m]acosx:?\";\n    $answer=lc(<ST\
DIN>);\n\n    if (($answer=~/^m/)){$OS=\"macosx\";\
}\n    elsif ( ($answer=~/^w/)){$OS=\"windows\";}\\
n    elsif ( ($answer=~/^linux/)){$OS=\"linux\";}\\
n    \n    else\n      {\n	return &input_os();\n  \
    }\n    return $OS;\n  }\n\nsub supported_os\n \
 {\n    my ($os)=(@_[0]);\n    return $SUPPORTED_O\
S{$os};\n  }\n\nsub add2env_file\n  {\n    my ($en\
v, $var, $value)=(@_);\n    my $F = new FileHandle\
;\n    my $t;\n    if (!$value){return;}\n    #mak\
e sure new variables do not get duplicated\n    if\
 ( -e $env)\n      {\n	open ($F, \"$env\");\n	whil\
e (<$F>)\n	  {\n	    my $line=$_;\n	    if (!($lin\
e=~/$var/)){$t.=$line;}\n	  }\n	close ($F);\n     \
 }\n    $t.=\"$var=$value\\n\";\n    open ($F, \">\
$env\");\n    print $F \"$t\";\n    $ENV{$var}=$va\
lue;\n    close ($F);\n  }    \n    \n\n\nsub upda\
te_tclinkdb \n  {\n    my $file =@_[0];\n    my $n\
ame;\n    my $F=new FileHandle;\n    my ($download\
, $address, $name, $l, $db);\n    \n    if ( $file\
 eq \"update\"){$file=$TCLINKDB_ADDRESS;}\n    \n \
   if ( $file =~/http:\\/\\// || $file =~/ftp:\\/\\
\//)\n      {\n	($address, $name)=($download=~/(.*\
)\\/([^\\/]+)$/);\n	`rm x $SILENT`;\n	if (&url2fil\
e ($file,\"x\")==$EXIT_SUCCESS)\n	  {\n	    print \
\"------- Susscessful upload of $name\";\n	    `mv\
 x $name`;\n	    $file=$name;\n	  }\n      }\n    \
open ($F, \"$file\");\n    while (<$F>)\n      {\n\
	my $l=$_;\n	if (($l =~/^\\/\\//) || ($db=~/^#/)){\
;}\n	elsif ( !($l =~/\\w/)){;}\n	else\n	  {\n	    \
my @v=split (/\\s+/, $l);\n	    if ( $l=~/^MODE/)\\
n	      {\n		$MODE{$v[1]}{$v[2]}=$v[3];\n	      }\\
n	    elsif ($l=~/^PG/)\n	      {\n		$PG{$v[1]}{$v\
[2]}=$v[3];\n	      }\n	  }\n      }\n    close ($\
F);\n    &post_process_PG();\n    return;\n  }\n\n\
\n\nsub initialize_PG\n  {\n\n$PG{\"t_coffee\"}{\"\
4_TCOFFEE\"}=\"TCOFFEE\";\n$PG{\"t_coffee\"}{\"typ\
e\"}=\"sequence_multiple_aligner\";\n$PG{\"t_coffe\
e\"}{\"ADDRESS\"}=\"http://www.tcoffee.org\";\n$PG\
{\"t_coffee\"}{\"language\"}=\"C++\";\n$PG{\"t_cof\
fee\"}{\"language2\"}=\"CXX\";\n$PG{\"t_coffee\"}{\
\"source\"}=\"http://www.tcoffee.org/Packages/sour\
ces/tcoffee/stable/T-COFFEE_distribution.tar.gz\";\
\n$PG{\"t_coffee\"}{\"update_action\"}=\"always\";\
\n$PG{\"t_coffee\"}{\"binary\"}=\"t_coffee\";\n$PG\
{\"t_coffee\"}{\"mode\"}=\"tcoffee,mcoffee,rcoffee\
,expresso,3dcoffee\";\n$PG{\"clustalo\"}{\"4_TCOFF\
EE\"}=\"CLUSTALO\";\n$PG{\"clustalo\"}{\"type\"}=\\
"sequence_multiple_aligner\";\n$PG{\"clustalo\"}{\\
"ADDRESS\"}=\"http://www.clustal.org/omega/\";\n$P\
G{\"clustalo\"}{\"language\"}=\"C++\";\n$PG{\"clus\
talo\"}{\"language2\"}=\"C++\";\n$PG{\"clustalo\"}\
{\"source\"}=\"http://www.clustal.org/omega/clusta\
l-omega-1.2.4.tar.gz\";\n$PG{\"clustalo\"}{\"mode\\
"}=\"mcoffee\";\n$PG{\"clustalo\"}{\"binary\"}=\"c\
lustalo\";\n$PG{\"clustalo\"}{\"version\"}=\"1.2.4\
\";\n$PG{\"strike\"}{\"4_TCOFFEE\"}=\"STRIKE\";\n$\
PG{\"strike\"}{\"type\"}=\"sequence_alignment_scor\
ing\";\n$PG{\"strike\"}{\"ADDRESS\"}=\"http://www.\
tcoffee.org/Projects/strike/index.html\";\n$PG{\"s\
trike\"}{\"language\"}=\"C++\";\n$PG{\"strike\"}{\\
"language2\"}=\"CXX\";\n$PG{\"strike\"}{\"source\"\
}=\"http://www.tcoffee.org/Projects/strike/strike_\
v1.2.tar.bz2\";\n$PG{\"strike\"}{\"mode\"}=\"tcoff\
ee,expresso\";\n$PG{\"strike\"}{\"version\"}=\"1.2\
\";\n$PG{\"strike\"}{\"binary\"}=\"strike\";\n$PG{\
\"clustalw2\"}{\"4_TCOFFEE\"}=\"CLUSTALW2\";\n$PG{\
\"clustalw2\"}{\"type\"}=\"sequence_multiple_align\
er\";\n$PG{\"clustalw2\"}{\"ADDRESS\"}=\"http://ww\
w.clustal.org\";\n$PG{\"clustalw2\"}{\"language\"}\
=\"C++\";\n$PG{\"clustalw2\"}{\"language2\"}=\"CXX\
\";\n$PG{\"clustalw2\"}{\"source\"}=\"http://www.c\
lustal.org/download/2.0.10/clustalw-2.0.10-src.tar\
.gz\";\n$PG{\"clustalw2\"}{\"mode\"}=\"mcoffee,rco\
ffee\";\n$PG{\"clustalw2\"}{\"binary\"}=\"clustalw\
2\";\n$PG{\"clustalw2\"}{\"version\"}=\"2.0.10\";\\
n$PG{\"clustalw\"}{\"4_TCOFFEE\"}=\"CLUSTALW\";\n$\
PG{\"clustalw\"}{\"type\"}=\"sequence_multiple_ali\
gner\";\n$PG{\"clustalw\"}{\"ADDRESS\"}=\"http://w\
ww.clustal.org\";\n$PG{\"clustalw\"}{\"language\"}\
=\"C\";\n$PG{\"clustalw\"}{\"language2\"}=\"C\";\n\
$PG{\"clustalw\"}{\"source\"}=\"http://www.clustal\
.org/download/1.X/ftp-igbmc.u-strasbg.fr/pub/Clust\
alW/clustalw1.82.UNIX.tar.gz\";\n$PG{\"clustalw\"}\
{\"mode\"}=\"mcoffee,rcoffee\";\n$PG{\"clustalw\"}\
{\"version\"}=\"1.82\";\n$PG{\"clustalw\"}{\"binar\
y\"}=\"clustalw\";\n$PG{\"dialign-t\"}{\"4_TCOFFEE\
\"}=\"DIALIGNT\";\n$PG{\"dialign-t\"}{\"type\"}=\"\
sequence_multiple_aligner\";\n$PG{\"dialign-t\"}{\\
"ADDRESS\"}=\"http://dialign-tx.gobics.de/\";\n$PG\
{\"dialign-t\"}{\"DIR\"}=\"/usr/share/dialign-tx/\\
";\n$PG{\"dialign-t\"}{\"language\"}=\"C\";\n$PG{\\
"dialign-t\"}{\"language2\"}=\"C\";\n$PG{\"dialign\
-t\"}{\"source\"}=\"http://dialign-tx.gobics.de/DI\
ALIGN-TX_1.0.2.tar.gz\";\n$PG{\"dialign-t\"}{\"mod\
e\"}=\"mcoffee\";\n$PG{\"dialign-t\"}{\"binary\"}=\
\"dialign-t\";\n$PG{\"dialign-t\"}{\"version\"}=\"\
1.0.2\";\n$PG{\"dialign-tx\"}{\"4_TCOFFEE\"}=\"DIA\
LIGNTX\";\n$PG{\"dialign-tx\"}{\"type\"}=\"sequenc\
e_multiple_aligner\";\n$PG{\"dialign-tx\"}{\"ADDRE\
SS\"}=\"http://dialign-tx.gobics.de/\";\n$PG{\"dia\
lign-tx\"}{\"DIR\"}=\"/usr/share/dialign-tx/\";\n$\
PG{\"dialign-tx\"}{\"language\"}=\"C\";\n$PG{\"dia\
lign-tx\"}{\"language2\"}=\"C\";\n$PG{\"dialign-tx\
\"}{\"source\"}=\"http://dialign-tx.gobics.de/DIAL\
IGN-TX_1.0.2.tar.gz\";\n$PG{\"dialign-tx\"}{\"mode\
\"}=\"mcoffee\";\n$PG{\"dialign-tx\"}{\"binary\"}=\
\"dialign-tx\";\n$PG{\"dialign-tx\"}{\"version\"}=\
\"1.0.2\";\n$PG{\"poa\"}{\"4_TCOFFEE\"}=\"POA\";\n\
$PG{\"poa\"}{\"type\"}=\"sequence_multiple_aligner\
\";\n$PG{\"poa\"}{\"ADDRESS\"}=\"http://www.bioinf\
ormatics.ucla.edu/poa/\";\n$PG{\"poa\"}{\"language\
\"}=\"C\";\n$PG{\"poa\"}{\"language2\"}=\"C\";\n$P\
G{\"poa\"}{\"source\"}=\"http://downloads.sourcefo\
rge.net/poamsa/poaV2.tar.gz\";\n$PG{\"poa\"}{\"DIR\
\"}=\"/usr/share/\";\n$PG{\"poa\"}{\"FILE1\"}=\"bl\
osum80.mat\";\n$PG{\"poa\"}{\"mode\"}=\"mcoffee\";\
\n$PG{\"poa\"}{\"binary\"}=\"poa\";\n$PG{\"poa\"}{\
\"version\"}=\"2.0\";\n$PG{\"probcons\"}{\"4_TCOFF\
EE\"}=\"PROBCONS\";\n$PG{\"probcons\"}{\"type\"}=\\
"sequence_multiple_aligner\";\n$PG{\"probcons\"}{\\
"ADDRESS\"}=\"http://probcons.stanford.edu/\";\n$P\
G{\"probcons\"}{\"language2\"}=\"CXX\";\n$PG{\"pro\
bcons\"}{\"language\"}=\"C++\";\n$PG{\"probcons\"}\
{\"source\"}=\"http://probcons.stanford.edu/probco\
ns_v1_12.tar.gz\";\n$PG{\"probcons\"}{\"mode\"}=\"\
mcoffee\";\n$PG{\"probcons\"}{\"binary\"}=\"probco\
ns\";\n$PG{\"probcons\"}{\"version\"}=\"1.12\";\n$\
PG{\"msaprobs\"}{\"4_TCOFFEE\"}=\"MSAPROBS\";\n$PG\
{\"msaprobs\"}{\"type\"}=\"sequence_multiple_align\
er\";\n$PG{\"msaprobs\"}{\"ADDRESS\"}=\"http://msa\
probs.sourceforge.net/homepage.htm#latest\";\n$PG{\
\"msaprobs\"}{\"language2\"}=\"CXX\";\n$PG{\"msapr\
obs\"}{\"language\"}=\"C++\";\n$PG{\"msaprobs\"}{\\
"source\"}=\"https://sourceforge.net/projects/msap\
robs/files/MSAProbs-MPI/MSAProbs-MPI_rel1.0.5.tar.\
gz\";\n$PG{\"msaprobs\"}{\"mode\"}=\"mcoffee\";\n$\
PG{\"msaprobs\"}{\"binary\"}=\"msaprobs\";\n$PG{\"\
msaprobs\"}{\"version\"}=\"1.05\";\n$PG{\"msaprobs\
\"}{\"update_action\"}=\"never\";\n$PG{\"upp\"}{\"\
4_TCOFFEE\"}=\"UPP\";\n$PG{\"upp\"}{\"type\"}=\"se\
quence_multiple_aligner\";\n$PG{\"upp\"}{\"ADDRESS\
\"}=\"http://www.cs.utexas.edu/users/phylo/softwar\
e/upp/\";\n$PG{\"upp\"}{\"language2\"}=\"CXX\";\n$\
PG{\"upp\"}{\"language\"}=\"C++\";\n$PG{\"upp\"}{\\
"source\"}=\"https://github.com/smirarab/pasta/arc\
hive/upp.zip\";\n$PG{\"upp\"}{\"mode\"}=\"mcoffee\\
";\n$PG{\"upp\"}{\"binary\"}=\"upp\";\n$PG{\"upp\"\
}{\"version\"}=\"1\";\n$PG{\"upp\"}{\"update_actio\
n\"}=\"never\";\n$PG{\"mafft\"}{\"4_TCOFFEE\"}=\"M\
AFFT\";\n$PG{\"mafft\"}{\"type\"}=\"sequence_multi\
ple_aligner\";\n$PG{\"mafft\"}{\"ADDRESS\"}=\"http\
://align.bmr.kyushu-u.ac.jp/mafft/online/server/\"\
;\n$PG{\"mafft\"}{\"language\"}=\"C\";\n$PG{\"maff\
t\"}{\"language\"}=\"C\";\n$PG{\"mafft\"}{\"source\
\"}=\"http://mafft.cbrc.jp/alignment/software/maff\
t-7.310-with-extensions-src.tgz\";\n$PG{\"mafft\"}\
{\"mode\"}=\"mcoffee,rcoffee\";\n$PG{\"mafft\"}{\"\
binary\"}=\"mafft.tar.gz\";\n$PG{\"mafft\"}{\"vers\
ion\"}=\"7.310\";\n$PG{\"msa\"}{\"4_TCOFFEE\"}=\"M\
SA\";\n$PG{\"msa\"}{\"type\"}=\"sequence_multiple_\
aligner\";\n$PG{\"msa\"}{\"ADDRESS\"}=\"https://ww\
w.ncbi.nlm.nih.gov/CBBresearch/Schaffer/msa.html\"\
;\n$PG{\"msa\"}{\"language\"}=\"C\";\n$PG{\"msa\"}\
{\"language\"}=\"C\";\n$PG{\"msa\"}{\"source\"}=\"\
ftp://ftp.ncbi.nih.gov/pub/msa/msa.tar.Z\";\n$PG{\\
"msa\"}{\"mode\"}=\"mcoffee\";\n$PG{\"msa\"}{\"bin\
ary\"}=\"msa.pl\";\n$PG{\"msa\"}{\"version\"}=\"1.\
0\";\n$PG{\"msa\"}{\"update_action\"}=\"never\";\n\
$PG{\"dca\"}{\"4_TCOFFEE\"}=\"DCA\";\n$PG{\"dca\"}\
{\"type\"}=\"sequence_multiple_aligner\";\n$PG{\"d\
ca\"}{\"ADDRESS\"}=\"https://bibiserv2.cebitec.uni\
-bielefeld.de/dca\";\n$PG{\"dca\"}{\"language\"}=\\
"C\";\n$PG{\"dca\"}{\"language\"}=\"C\";\n$PG{\"dc\
a\"}{\"source\"}=\"https://bibiserv2.cebitec.uni-b\
ielefeld.de/applications/dca/resources/downloads/d\
ca-1.1-src.tar.gz\";\n$PG{\"dca\"}{\"mode\"}=\"mco\
ffee\";\n$PG{\"dca\"}{\"binary\"}=\"dca.pl\";\n$PG\
{\"dca\"}{\"version\"}=\"1.1\";\n$PG{\"dca\"}{\"up\
date_action\"}=\"never\";\n$PG{\"muscle\"}{\"4_TCO\
FFEE\"}=\"MUSCLE\";\n$PG{\"muscle\"}{\"type\"}=\"s\
equence_multiple_aligner\";\n$PG{\"muscle\"}{\"ADD\
RESS\"}=\"http://www.drive5.com/muscle/\";\n$PG{\"\
muscle\"}{\"language\"}=\"C++\";\n$PG{\"muscle\"}{\
\"language2\"}=\"GPP\";\n$PG{\"muscle\"}{\"source\\
"}=\"http://www.drive5.com/muscle/downloads3.7/mus\
cle3.7_src.tar.gz\";\n$PG{\"muscle\"}{\"windows\"}\
=\"http://www.drive5.com/muscle/downloads3.7/muscl\
e3.7_win32.zip\";\n$PG{\"muscle\"}{\"linux\"}=\"ht\
tp://www.drive5.com/muscle/downloads3.7/muscle3.7_\
linux_ia32.tar.gz\";\n$PG{\"muscle\"}{\"mode\"}=\"\
mcoffee,rcoffee\";\n$PG{\"muscle\"}{\"version\"}=\\
"3.7\";\n$PG{\"pcma\"}{\"4_TCOFFEE\"}=\"PCMA\";\n$\
PG{\"pcma\"}{\"type\"}=\"sequence_multiple_aligner\
\";\n$PG{\"pcma\"}{\"ADDRESS\"}=\"http://prodata.s\
wmed.edu/pcma/pcma.php\";\n$PG{\"pcma\"}{\"languag\
e\"}=\"C\";\n$PG{\"pcma\"}{\"language2\"}=\"C\";\n\
$PG{\"pcma\"}{\"source\"}=\"http://prodata.swmed.e\
du/download/pub/PCMA/pcma.tar.gz\";\n$PG{\"pcma\"}\
{\"mode\"}=\"mcoffee\";\n$PG{\"pcma\"}{\"version\"\
}=\"1.0\";\n$PG{\"kalign\"}{\"4_TCOFFEE\"}=\"KALIG\
N\";\n$PG{\"kalign\"}{\"type\"}=\"sequence_multipl\
e_aligner\";\n$PG{\"kalign\"}{\"ADDRESS\"}=\"http:\
//msa.cgb.ki.se\";\n$PG{\"kalign\"}{\"language\"}=\
\"C\";\n$PG{\"kalign\"}{\"language2\"}=\"C\";\n$PG\
{\"kalign\"}{\"source\"}=\"http://msa.cgb.ki.se/do\
wnloads/kalign/current.tar.gz\";\n$PG{\"kalign\"}{\
\"mode\"}=\"mcoffee\";\n$PG{\"kalign\"}{\"version\\
"}=\"1.0\";\n$PG{\"amap\"}{\"4_TCOFFEE\"}=\"AMAP\"\
;\n$PG{\"amap\"}{\"type\"}=\"sequence_multiple_ali\
gner\";\n$PG{\"amap\"}{\"ADDRESS\"}=\"http://bio.m\
ath.berkeley.edu/amap/\";\n$PG{\"amap\"}{\"languag\
e\"}=\"C++\";\n$PG{\"amap\"}{\"language2\"}=\"CXX\\
";\n$PG{\"amap\"}{\"source\"}=\"https://github.com\
/mes5k/amap-align/archive/amap.zip\";\n$PG{\"amap\\
"}{\"mode\"}=\"mcoffee\";\n$PG{\"amap\"}{\"version\
\"}=\"2.0\";\n$PG{\"amap\"}{\"update_action\"}=\"n\
ever\";\n$PG{\"proda\"}{\"4_TCOFFEE\"}=\"PRODA\";\\
n$PG{\"proda\"}{\"type\"}=\"sequence_multiple_alig\
ner\";\n$PG{\"proda\"}{\"ADDRESS\"}=\"http://proda\
.stanford.edu\";\n$PG{\"proda\"}{\"language\"}=\"C\
++\";\n$PG{\"proda\"}{\"language2\"}=\"CXX\";\n$PG\
{\"proda\"}{\"source\"}=\"http://proda.stanford.ed\
u/proda_1_0.tar.gz\";\n$PG{\"proda\"}{\"mode\"}=\"\
mcoffee\";\n$PG{\"proda\"}{\"version\"}=\"1.0\";\n\
$PG{\"prank\"}{\"4_TCOFFEE\"}=\"PRANK\";\n$PG{\"pr\
ank\"}{\"type\"}=\"sequence_multiple_aligner\";\n$\
PG{\"prank\"}{\"ADDRESS\"}=\"http://www.ebi.ac.uk/\
goldman-srv/prank/\";\n$PG{\"prank\"}{\"language\"\
}=\"C++\";\n$PG{\"prank\"}{\"language2\"}=\"CXX\";\
\n$PG{\"prank\"}{\"source\"}=\"http://www.ebi.ac.u\
k/goldman-srv/prank/src/prank/prank.src.100802.tgz\
\";\n$PG{\"prank\"}{\"mode\"}=\"mcoffee\";\n$PG{\"\
prank\"}{\"version\"}=\"100303\";\n$PG{\"sap\"}{\"\
4_TCOFFEE\"}=\"SAP\";\n$PG{\"sap\"}{\"type\"}=\"st\
ructure_pairwise_aligner\";\n$PG{\"sap\"}{\"ADDRES\
S\"}=\"https://mathbio.crick.ac.uk/wiki/Software#S\
AP\";\n$PG{\"sap\"}{\"language\"}=\"C\";\n$PG{\"sa\
p\"}{\"language2\"}=\"C\";\n$PG{\"sap\"}{\"source\\
"}=\"https://github.com/jkleinj/SAP/archive/v.1.1.\
3.tar.gz\";\n$PG{\"sap\"}{\"mode\"}=\"expresso,3dc\
offee\";\n$PG{\"sap\"}{\"version\"}=\"1.1.3\";\n$P\
G{\"sap\"}{\"binary\"}=\"sap\";\n$PG{\"TMalign\"}{\
\"4_TCOFFEE\"}=\"TMALIGN\";\n$PG{\"TMalign\"}{\"ty\
pe\"}=\"structure_pairwise_aligner\";\n$PG{\"TMali\
gn\"}{\"ADDRESS\"}=\"http://zhanglab.ccmb.med.umic\
h.edu/TM-align/TMalign.f\";\n$PG{\"TMalign\"}{\"la\
nguage\"}=\"Fortran\";\n$PG{\"TMalign\"}{\"languag\
e2\"}=\"Fortran\";\n$PG{\"TMalign\"}{\"source\"}=\\
"http://zhanglab.ccmb.med.umich.edu/TM-align/TMali\
gn.f\";\n$PG{\"TMalign\"}{\"linux\"}=\"http://zhan\
glab.ccmb.med.umich.edu/TM-align/TMalign_32.gz\";\\
n$PG{\"TMalign\"}{\"mode\"}=\"expresso,3dcoffee\";\
\n$PG{\"TMalign\"}{\"version\"}=\"2013.05.11\";\n$\
PG{\"mustang\"}{\"4_TCOFFEE\"}=\"MUSTANG\";\n$PG{\\
"mustang\"}{\"type\"}=\"structure_pairwise_aligner\
\";\n$PG{\"mustang\"}{\"ADDRESS\"}=\"http://lcb.in\
fotech.monash.edu.au/mustang/\";\n$PG{\"mustang\"}\
{\"language\"}=\"C++\";\n$PG{\"mustang\"}{\"langua\
ge2\"}=\"CXX\";\n$PG{\"mustang\"}{\"source\"}=\"ht\
tp://lcb.infotech.monash.edu.au/mustang/mustang_v3\
.2.3.tgz\";\n$PG{\"mustang\"}{\"mode\"}=\"expresso\
,3dcoffee\";\n$PG{\"mustang\"}{\"version\"}=\"3.2.\
3\";\n$PG{\"lsqman\"}{\"4_TCOFFEE\"}=\"LSQMAN\";\n\
$PG{\"lsqman\"}{\"type\"}=\"structure_pairwise_ali\
gner\";\n$PG{\"lsqman\"}{\"ADDRESS\"}=\"empty\";\n\
$PG{\"lsqman\"}{\"language\"}=\"empty\";\n$PG{\"ls\
qman\"}{\"language2\"}=\"empty\";\n$PG{\"lsqman\"}\
{\"source\"}=\"empty\";\n$PG{\"lsqman\"}{\"update_\
action\"}=\"never\";\n$PG{\"lsqman\"}{\"mode\"}=\"\
expresso,3dcoffee\";\n$PG{\"align_pdb\"}{\"4_TCOFF\
EE\"}=\"ALIGN_PDB\";\n$PG{\"align_pdb\"}{\"type\"}\
=\"structure_pairwise_aligner\";\n$PG{\"align_pdb\\
"}{\"ADDRESS\"}=\"empty\";\n$PG{\"align_pdb\"}{\"l\
anguage\"}=\"empty\";\n$PG{\"align_pdb\"}{\"langua\
ge2\"}=\"empty\";\n$PG{\"align_pdb\"}{\"source\"}=\
\"empty\";\n$PG{\"align_pdb\"}{\"update_action\"}=\
\"never\";\n$PG{\"align_pdb\"}{\"mode\"}=\"express\
o,3dcoffee\";\n$PG{\"fugueali\"}{\"4_TCOFFEE\"}=\"\
FUGUE\";\n$PG{\"fugueali\"}{\"type\"}=\"structure_\
pairwise_aligner\";\n$PG{\"fugueali\"}{\"ADDRESS\"\
}=\"http://mizuguchilab.org/fugue/\";\n$PG{\"fugue\
ali\"}{\"language\"}=\"empty\";\n$PG{\"fugueali\"}\
{\"language2\"}=\"empty\";\n$PG{\"fugueali\"}{\"so\
urce\"}=\"empty\";\n$PG{\"fugueali\"}{\"update_act\
ion\"}=\"never\";\n$PG{\"fugueali\"}{\"mode\"}=\"e\
xpresso,3dcoffee\";\n$PG{\"dalilite.pl\"}{\"4_TCOF\
FEE\"}=\"DALILITEc\";\n$PG{\"dalilite.pl\"}{\"type\
\"}=\"structure_pairwise_aligner\";\n$PG{\"dalilit\
e.pl\"}{\"ADDRESS\"}=\"built_in\";\n$PG{\"dalilite\
.pl\"}{\"ADDRESS2\"}=\"http://www.ebi.ac.uk/Tools/\
webservices/services/dalilite\";\n$PG{\"dalilite.p\
l\"}{\"language\"}=\"Perl\";\n$PG{\"dalilite.pl\"}\
{\"language2\"}=\"Perl\";\n$PG{\"dalilite.pl\"}{\"\
source\"}=\"empty\";\n$PG{\"dalilite.pl\"}{\"updat\
e_action\"}=\"never\";\n$PG{\"dalilite.pl\"}{\"mod\
e\"}=\"expresso,3dcoffee\";\n$PG{\"probconsRNA\"}{\
\"4_TCOFFEE\"}=\"PROBCONSRNA\";\n$PG{\"probconsRNA\
\"}{\"type\"}=\"RNA_multiple_aligner\";\n$PG{\"pro\
bconsRNA\"}{\"ADDRESS\"}=\"http://probcons.stanfor\
d.edu/\";\n$PG{\"probconsRNA\"}{\"language\"}=\"C+\
+\";\n$PG{\"probconsRNA\"}{\"language2\"}=\"CXX\";\
\n$PG{\"probconsRNA\"}{\"source\"}=\"http://probco\
ns.stanford.edu/probconsRNA.tar.gz\";\n$PG{\"probc\
onsRNA\"}{\"mode\"}=\"mcoffee,rcoffee\";\n$PG{\"pr\
obconsRNA\"}{\"version\"}=\"1.0\";\n$PG{\"sfold\"}\
{\"4_TCOFFEE\"}=\"CONSAN\";\n$PG{\"sfold\"}{\"type\
\"}=\"RNA_pairwise_aligner\";\n$PG{\"sfold\"}{\"AD\
DRESS\"}=\"http://selab.janelia.org/software/consa\
n/\";\n$PG{\"sfold\"}{\"language\"}=\"empty\";\n$P\
G{\"sfold\"}{\"language2\"}=\"empty\";\n$PG{\"sfol\
d\"}{\"source\"}=\"empty\";\n$PG{\"sfold\"}{\"upda\
te_action\"}=\"never\";\n$PG{\"sfold\"}{\"mode\"}=\
\"rcoffee\";\n$PG{\"RNAplfold\"}{\"4_TCOFFEE\"}=\"\
RNAPLFOLD\";\n$PG{\"RNAplfold\"}{\"type\"}=\"RNA_s\
econdarystructure_predictor\";\n$PG{\"RNAplfold\"}\
{\"ADDRESS\"}=\"http://www.tbi.univie.ac.at/RNA/\"\
;\n$PG{\"RNAplfold\"}{\"language\"}=\"C\";\n$PG{\"\
RNAplfold\"}{\"language2\"}=\"C\";\n$PG{\"RNAplfol\
d\"}{\"source\"}=\"http://www.tbi.univie.ac.at/RNA\
/packages/source/ViennaRNA-2.1.9.tar.gz\";\n$PG{\"\
RNAplfold\"}{\"mode\"}=\"rcoffee,\";\n$PG{\"RNAplf\
old\"}{\"binary\"}=\"RNAplfold.tar.gz\";\n$PG{\"RN\
Aplfold\"}{\"version\"}=\"2.1.9\";\n$PG{\"retree\"\
}{\"4_TCOFFEE\"}=\"PHYLIP\";\n$PG{\"retree\"}{\"ty\
pe\"}=\"Phylogeny\";\n$PG{\"retree\"}{\"ADDRESS\"}\
=\"http://evolution.gs.washington.edu/phylip/\";\n\
$PG{\"retree\"}{\"language\"}=\"C\";\n$PG{\"retree\
\"}{\"language2\"}=\"C\";\n$PG{\"retree\"}{\"sourc\
e\"}=\"http://www.tcoffee.org/Packages/mirrors/sou\
rce/phylip-3.66.tar.gz\";\n$PG{\"retree\"}{\"mode\\
"}=\"trmsd,\";\n$PG{\"retree\"}{\"binary\"}=\"retr\
ee.tar.gz\";\n$PG{\"retree\"}{\"version\"}=\"3.66\\
";\n$PG{\"hmmtop\"}{\"4_TCOFFEE\"}=\"HMMTOP\";\n$P\
G{\"hmmtop\"}{\"type\"}=\"protein_secondarystructu\
re_predictor\";\n$PG{\"hmmtop\"}{\"ADDRESS\"}=\"ww\
w.enzim.hu/hmmtop/\";\n$PG{\"hmmtop\"}{\"language\\
"}=\"C\";\n$PG{\"hmmtop\"}{\"language2\"}=\"C\";\n\
$PG{\"hmmtop\"}{\"source\"}=\"http://www.tcoffee.o\
rg/Packages/mirrors/hmmtop2.1.tgz\";\n$PG{\"hmmtop\
\"}{\"binary\"}=\"hmmtop\";\n$PG{\"hmmtop\"}{\"upd\
ate_action\"}=\"never\";\n$PG{\"hmmtop\"}{\"mode\"\
}=\"psicoffee\";\n$PG{\"hmmtop\"}{\"version\"}=\"2\
.1\";\n$PG{\"gorIV\"}{\"4_TCOFFEE\"}=\"GOR4\";\n$P\
G{\"gorIV\"}{\"type\"}=\"protein_secondarystructur\
e_predictor\";\n$PG{\"gorIV\"}{\"ADDRESS\"}=\"http\
://mig.jouy.inra.fr/logiciels/gorIV/\";\n$PG{\"gor\
IV\"}{\"language\"}=\"C\";\n$PG{\"gorIV\"}{\"langu\
age2\"}=\"C\";\n$PG{\"gorIV\"}{\"source\"}=\"http:\
//www.tcoffee.org/Packages/mirrors/GOR_IV.tar.gz\"\
;\n$PG{\"gorIV\"}{\"update_action\"}=\"never\";\n$\
PG{\"gorIV\"}{\"mode\"}=\"tcoffee\";\n$PG{\"wublas\
t.pl\"}{\"4_TCOFFEE\"}=\"EBIWUBLASTc\";\n$PG{\"wub\
last.pl\"}{\"type\"}=\"protein_homology_predictor\\
";\n$PG{\"wublast.pl\"}{\"ADDRESS\"}=\"built_in\";\
\n$PG{\"wublast.pl\"}{\"ADDRESS2\"}=\"http://www.e\
bi.ac.uk/Tools/webservices/services/wublast\";\n$P\
G{\"wublast.pl\"}{\"language\"}=\"Perl\";\n$PG{\"w\
ublast.pl\"}{\"language2\"}=\"Perl\";\n$PG{\"wubla\
st.pl\"}{\"source\"}=\"empty\";\n$PG{\"wublast.pl\\
"}{\"update_action\"}=\"never\";\n$PG{\"wublast.pl\
\"}{\"mode\"}=\"psicoffee,expresso,accurate\";\n$P\
G{\"blastpgp.pl\"}{\"4_TCOFFEE\"}=\"EBIBLASTPGPc\"\
;\n$PG{\"blastpgp.pl\"}{\"type\"}=\"protein_homolo\
gy_predictor\";\n$PG{\"blastpgp.pl\"}{\"ADDRESS\"}\
=\"built_in\";\n$PG{\"blastpgp.pl\"}{\"ADDRESS2\"}\
=\"http://www.ebi.ac.uk/Tools/webservices/services\
/blastpgp\";\n$PG{\"blastpgp.pl\"}{\"language\"}=\\
"Perl\";\n$PG{\"blastpgp.pl\"}{\"language2\"}=\"Pe\
rl\";\n$PG{\"blastpgp.pl\"}{\"source\"}=\"empty\";\
\n$PG{\"blastpgp.pl\"}{\"update_action\"}=\"never\\
";\n$PG{\"blastpgp.pl\"}{\"mode\"}=\"psicoffee,exp\
resso,accurate\";\n$PG{\"blastall\"}{\"4_TCOFFEE\"\
}=\"blastall\";\n$PG{\"blastall\"}{\"type\"}=\"pro\
tein_homology_predictor\";\n$PG{\"blastall\"}{\"AD\
DRESS\"}=\"ftp://ftp.ncbi.nih.gov/blast/executable\
s/LATEST\";\n$PG{\"blastall\"}{\"language\"}=\"C\"\
;\n$PG{\"blastall\"}{\"language2\"}=\"C\";\n$PG{\"\
blastall\"}{\"source\"}=\"ftp://ftp.ncbi.nlm.nih.g\
ov/blast/executables/blast+/2.6.0/ncbi-blast-2.6.0\
+-src.tar.gz\";\n$PG{\"blastall\"}{\"update_action\
\"}=\"never\";\n$PG{\"blastall\"}{\"mode\"}=\"psic\
offee,expresso,3dcoffee\";\n$PG{\"legacy_blast.pl\\
"}{\"4_TCOFFEE\"}=\"NCBIBLAST\";\n$PG{\"legacy_bla\
st.pl\"}{\"type\"}=\"protein_homology_predictor\";\
\n$PG{\"legacy_blast.pl\"}{\"ADDRESS\"}=\"ftp://ft\
p.ncbi.nih.gov/blast/executables/LATEST\";\n$PG{\"\
legacy_blast.pl\"}{\"language\"}=\"C\";\n$PG{\"leg\
acy_blast.pl\"}{\"language2\"}=\"C\";\n$PG{\"legac\
y_blast.pl\"}{\"source\"}=\"ftp://ftp.ncbi.nlm.nih\
.gov/blast/executables/blast+/2.6.0/ncbi-blast-2.6\
.0+-src.tar.gz\";\n$PG{\"legacy_blast.pl\"}{\"upda\
te_action\"}=\"never\";\n$PG{\"legacy_blast.pl\"}{\
\"mode\"}=\"psicoffee,expresso,3dcoffee\";\n$PG{\"\
SOAP::Lite\"}{\"4_TCOFFEE\"}=\"SOAPLITE\";\n$PG{\"\
SOAP::Lite\"}{\"type\"}=\"library\";\n$PG{\"SOAP::\
Lite\"}{\"ADDRESS\"}=\"http://cpansearch.perl.org/\
src/MKUTTER/SOAP-Lite-0.710.08/Makefile.PL\";\n$PG\
{\"SOAP::Lite\"}{\"language\"}=\"Perl\";\n$PG{\"SO\
AP::Lite\"}{\"language2\"}=\"Perl\";\n$PG{\"SOAP::\
Lite\"}{\"source\"}=\"empty\";\n$PG{\"SOAP::Lite\"\
}{\"update_action\"}=\"never\";\n$PG{\"SOAP::Lite\\
"}{\"mode\"}=\"none\";\n$PG{\"XML::Simple\"}{\"4_T\
COFFEE\"}=\"XMLSIMPLE\";\n$PG{\"XML::Simple\"}{\"t\
ype\"}=\"library\";\n$PG{\"XML::Simple\"}{\"ADDRES\
S\"}=\"http://search.cpan.org/~grantm/XML-Simple-2\
.18/lib/XML/Simple.pm\";\n$PG{\"XML::Simple\"}{\"l\
anguage\"}=\"Perl\";\n$PG{\"XML::Simple\"}{\"langu\
age2\"}=\"Perl\";\n$PG{\"XML::Simple\"}{\"source\"\
}=\"empty\";\n$PG{\"XML::Simple\"}{\"mode\"}=\"psi\
coffee,expresso,accurate\";\n$PG{\"x3dna\"}{\"4_TC\
OFFEE\"}=\"x3dna\";\n$PG{\"x3dna\"}{\"type\"}=\"RN\
A_secondarystructure_predictor\";\n$PG{\"x3dna\"}{\
\"ADDRESS\"}=\"http://x3dna.bio.columbia.edu/\";\n\
$PG{\"x3dna\"}{\"source\"}=\"http://www.tcoffee.or\
g/Packages/mirrors/source/x3dna-v2.3-linux-64bit.t\
ar.gz\";\n$PG{\"x3dna\"}{\"mode\"}=\"saracoffee\";\
\n$PG{\"x3dna\"}{\"update_action\"}=\"never\";\n$P\
G{\"fsa\"}{\"4_TCOFFEE\"}=\"FSA\";\n$PG{\"fsa\"}{\\
"type\"}=\"sequence_multiple_aligner\";\n$PG{\"fsa\
\"}{\"ADDRESS\"}=\"http://fsa.sourceforge.net/\";\\
n$PG{\"fsa\"}{\"language\"}=\"C++\";\n$PG{\"fsa\"}\
{\"language2\"}=\"CXX\";\n$PG{\"fsa\"}{\"source\"}\
=\"http://sourceforge.net/projects/fsa/files/fsa-1\
.15.3.tar.gz/download/\";\n$PG{\"fsa\"}{\"mode\"}=\
\"mcoffee\";\n$PG{\"fsa\"}{\"version\"}=\"1.15.3\"\
;\n$PG{\"fsa\"}{\"update_action\"}=\"never\";\n$PG\
{\"mus4\"}{\"4_TCOFFEE\"}=\"MUS4\";\n$PG{\"mus4\"}\
{\"type\"}=\"sequence_multiple_aligner\";\n$PG{\"m\
us4\"}{\"ADDRESS\"}=\"http://www.drive5.com/muscle\
/\";\n$PG{\"mus4\"}{\"language\"}=\"C++\";\n$PG{\"\
mus4\"}{\"language2\"}=\"GPP\";\n$PG{\"mus4\"}{\"s\
ource\"}=\"http://www.drive5.com/muscle/muscle4.0_\
src.tar.gz\";\n$PG{\"mus4\"}{\"mode\"}=\"mcoffee,r\
coffee\";\n$PG{\"mus4\"}{\"version\"}=\"4.0\";\n$P\
G{\"mus4\"}{\"update_action\"}=\"never\";\n$MODE{\\
"tcoffee\"}{\"name\"}=\"tcoffee\";\n$MODE{\"rcoffe\
e\"}{\"name\"}=\"rcoffee\";\n$MODE{\"3dcoffee\"}{\\
"name\"}=\"3dcoffee\";\n$MODE{\"mcoffee\"}{\"name\\
"}=\"mcoffee\";\n$MODE{\"expresso\"}{\"name\"}=\"e\
xpresso\";\n$MODE{\"trmsd\"}{\"name\"}=\"trmsd\";\\
n$MODE{\"accurate\"}{\"name\"}=\"accurate\";\n$MOD\
E{\"seq_reformat\"}{\"name\"}=\"seq_reformat\";\n\\
n\n$PG{C}{compiler}=\"gcc\";\n$PG{C}{compiler_flag\
}=\"CC\";\n$PG{C}{options}=\"\";\n$PG{C}{options_f\
lag}=\"CFLAGS\";\n$PG{C}{type}=\"compiler\";\n\n$P\
G{\"CXX\"}{compiler}=\"g++\";\n$PG{\"CXX\"}{compil\
er_flag}=\"CXX\";\n$PG{\"CXX\"}{options}=\"\";\n$P\
G{\"CXX\"}{options_flag}=\"CXXFLAGS\";\n$PG{CXX}{t\
ype}=\"compiler\";\n\n$PG{\"CPP\"}{compiler}=\"g++\
\";\n$PG{\"CPP\"}{compiler_flag}=\"CPP\";\n$PG{\"C\
PP\"}{options}=\"\";\n$PG{\"CPP\"}{options_flag}=\\
"CPPFLAGS\";\n$PG{CPP}{type}=\"compiler\";\n\n$PG{\
\"GPP\"}{compiler}=\"g++\";\n$PG{\"GPP\"}{compiler\
_flag}=\"GPP\";\n$PG{\"GPP\"}{options}=\"\";\n$PG{\
\"GPP\"}{options_flag}=\"CFLAGS\";\n$PG{GPP}{type}\
=\"compiler\";\n\n$PG{Fortran}{compiler}=\"g77\";\\
n$PG{Fortran}{compiler_flag}=\"FCC\";\n$PG{Fortran\
}{type}=\"compiler\";\n\n$PG{Perl}{compiler}=\"CPA\
N\";\n$PG{Perl}{type}=\"compiler\";\n\n$SUPPORTED_\
OS{macosx}=\"Macintosh\";\n$SUPPORTED_OS{linux}=\"\
Linux\";\n$SUPPORTED_OS{windows}=\"Cygwin\";\n\n\n\
\n$MODE{t_coffee}{description}=\" for regular mult\
iple sequence alignments\";\n$MODE{rcoffee} {descr\
iption}=\" for RNA multiple sequence alignments\";\
\n\n$MODE{psicoffee} {description}=\" for Homology\
 Extended multiple sequence alignments\";\n$MODE{e\
xpresso}{description}=\" for very accurate structu\
re based multiple sequence alignments\";\n$MODE{\"\
3dcoffee\"}{description}=\" for multiple structure\
 alignments\";\n$MODE{mcoffee} {description}=\" fo\
r combining alternative multiple sequence alignmen\
t packages\\n------- into a unique meta-package. T\
he installer will upload several MSA packages and \
compile them\\n\n\";\n\n\n&post_process_PG();\nret\
urn;\n}\n\nsub post_process_PG\n  {\n    my $p;\n \
   \n    %PG=&name2dname (%PG);\n    %MODE=&name2d\
name(%MODE);\n    foreach $p (keys(%PG)){if ( $PG{\
$p}{type} eq \"compiler\"){$PG{$p}{update_action}=\
\"never\";}}\n    \n  }\n\nsub name2dname\n  {\n  \
  my (%L)=(@_);\n    my ($l, $ml);\n    \n    fore\
ach my $pg (keys(%L))\n      {\n	$l=length ($pg);\\
n	if ( $l>$ml){$ml=$l;}\n      }\n    $ml+=1;\n   \
 foreach my $pg (keys(%L))\n      {\n	my $name;\n	\
$l=$ml-length ($pg);\n	$name=$pg;\n	for ( $b=0; $b\
<$l; $b++)\n	  {\n	    $name .=\" \";\n	  }\n	$L{$\
pg}{dname}=$name;\n      }\n    return %L;\n  }\n\\
nsub env_file2putenv\n  {\n    my $f=@_[0];\n    m\
y $F=new FileHandle;\n    my $n;\n    \n    open (\
$F, \"$f\");\n    while (<$F>)\n      {\n	my $line\
=$_;\n	my($var, $value)=($_=~/(\\S+)\\=(\\S*)/);\n\
	$ENV{$var}=$value;\n	$ENV_SET{$var}=1;\n	$n++;\n \
     }\n    close ($F);\n    return $n;\n  }\n\nsu\
b replace_line_in_file\n  {\n    my ($file, $wordi\
n, $wordout)=@_;\n    my $O=new FileHandle;\n    m\
y $I=new FileHandle;\n    my $l;\n    if (!-e $fil\
e){return;}\n    \n    system (\"mv $file $file.ol\
d\");\n    open ($O, \">$file\");\n    open ($I, \\
"$file.old\");\n    while (<$I>)\n      {\n	$l=$_;\
\n	if (!($l=~/$wordin/)){print $O \"$l\";}\n	elsif\
 ( $wordout ne \"\"){$l=~s/$wordin/$wordout/g;prin\
t $O \"$l\";}\n      }\n    close ($O);\n    close\
 ($I);\n    return;\n  }\n\nsub add_C_libraries\n \
 {\n   my ($file,$first,@list)=@_;\n   \n    my $O\
=new FileHandle;\n    my $I=new FileHandle;\n    m\
y ($l,$anchor);\n    if (!-e $file){return;}\n   \\
n    $anchor=\"#include <$first>\";\n	 \n    syste\
m (\"mv $file $file.old\");\n    open ($O, \">$fil\
e\");\n    open ($I, \"$file.old\");\n    while (<\
$I>)\n      {\n	$l=$_;\n	print $O \"$l\";\n	if (!(\
$l=~/$anchor/))\n	   {\n	    \n	    foreach my $li\
b (@list)\n	       {\n                  print $O \\
"#include <$lib>\\n\";\n	       }\n           }\n \
     }\n    close ($O);\n    close ($I);\n    retu\
rn;\n    }\n","use Env;\nuse Cwd;\n@suffix=(\"tmp\\
", \"temp\", \"cache\", \"t_coffee\", \"core\", \"\
tcoffee\");\n\nif ($#ARGV==-1)\n  {\n    print \"c\
lean_cache.pl -file <file to add in -dir> -dir=<di\
r> -size=<value in Mb>\\n0: unlimited -1 always.\\\
nWill only clean directories matching:[\";\n    fo\
reach $k(@suffix){print \"*$k* \";}\n    print \"]\
\\n\";\n    exit (EXIT_FAILURE);\n  }\n\n$cl=join \
(\" \",@ARGV);\nif (($cl=~/\\-no_action/))\n  {\n \
   exit (EXIT_SUCCESS);\n  }\n\nif (($cl=~/\\-debu\
g/))\n  {\n    $DEBUG=1;\n  }\nelse\n  {\n    $DEB\
UG=0;\n  }\n\nif (($cl=~/\\-dir=(\\S+)/))\n  {\n  \
  $dir=$1;\n  }\nelse\n  {\n    $dir=\"./\";\n  }\\
n\nif ($cl=~/\\-file=(\\S+)/)\n  {\n    $file=$1;\\
n  }\nelse\n  {\n    $file=0;\n  }\n\nif ($cl=~/\\\
-size=(\\S+)/)\n  {\n    $max_size=$1;\n  }\nelse\\
n  {\n    $max_size=0;#unlimited\n  }\nif ($cl=~/\\
\-force/)\n  {\n    $force=1;\n  }\nelse\n  {\n   \
 $force=0;\n  }\n\nif ($cl=~/\\-age=(\\S+)/)\n  {\\
n    $max_age=$1;\n  }\nelse\n  {\n    $max_age=0;\
#unlimited\n  }\n\n$max_size*=1000000;\nif ( ! -d \
$dir)\n  {\n    print STDERR \"\\nCannot process $\
dir: does not exist \\n\";\n    exit (EXIT_FAILURE\
);\n  }\n\nif ( !($dir=~/^\\//))\n  {\n    $base=c\
wd();\n    $dir=\"$base/$dir\";\n  }\n\n$proceed=0\
;\nforeach $s (@suffix)\n  {\n    \n    if (($dir=\
~/$s/)){$proceed=1;}\n    $s=uc ($s);\n    if (($d\
ir=~/$s/)){$proceed=1;}\n  }\nif ( $proceed==0)\n \
 {\n    print STDERR \"Clean_cache.pl can only cle\
an directories whose absolute path name contains t\
he following strings:\";\n    foreach $w (@suffix)\
 {print STDERR \"$w \";$w=lc($w); print STDERR \"$\
w \";}\n    print STDERR \"\\nCannot process $dir\\
\n\";\n    exit (EXIT_FAILURE);\n  }\n\n$name_file\
=\"$dir/name_file.txt\";\n$size_file=\"$dir/size_f\
ile.txt\";\nif ( $force){&create_ref_file ($dir,$n\
ame_file,$size_file);}\nif ($file){&add_file ($dir\
, $name_file, $size_file, $file);}\n&clean_dir ($d\
ir, $name_file, $size_file, $max_size,$max_age);\n\
exit (EXIT_SUCCESS);\n\nsub clean_dir \n  {\n    m\
y ($dir, $name_file, $size_file, $max_size, $max_a\
ge)=@_;\n    my ($tot_size, $size, $f, $s);\n\n  \\
n    $tot_size=&get_tot_size ($dir, $name_file, $s\
ize_file);\n\n    if ( $tot_size<=$max_size){retur\
n ;}\n    else {$max_size/=2;}\n    \n    #recreat\
e the name file in case some temprary files have n\
ot been properly registered\n    &create_ref_file \
($dir, $name_file, $size_file, $max_age);\n  \n   \
 $new_name_file=&vtmpnam();\n    open (R, \"$name_\
file\");\n    open (W, \">$new_name_file\");\n    \
while (<R>)\n      {\n	my $line=$_;\n	\n	($f, $s)=\
($line=~/(\\S+) (\\S+)/);\n	if ( !($f=~/\\S/)){nex\
t;}\n	\n	elsif ($max_size && $tot_size>=$max_size \
&& !($f=~/name_file/))\n	  {\n	    remove ( \"$dir\
/$f\");\n	    $tot_size-=$s;\n	  }\n	elsif ( $max_\
age && -M(\"$dir/$f\")>=$max_age)\n	  {\n	    remo\
ve ( \"$dir/$f\");\n	    $tot_size-=$s;\n	  }\n	el\
se\n	  {\n	    print W \"$f $s\\n\";\n	  }\n      \
}\n    close (R);\n    close (W);\n    open (F, \"\
>$size_file\");\n    print F \"$tot_size\";\n    i\
f ( -e $new_name_file){`mv $new_name_file $name_fi\
le`;}\n    close (F);\n  }\nsub get_tot_size\n  {\\
n    my ($dir, $name_file, $size_file)=@_;\n    my\
 $size;\n    \n    if ( !-d $dir){return 0;}\n    \
if ( !-e $name_file)\n      {\n	\n	&create_ref_fil\
e ($dir, $name_file, $size_file);\n      }\n    op\
en (F, \"$size_file\");\n    $size=<F>;\n    close\
 (F);\n    chomp ($size);\n    return $size;\n  }\\
nsub size \n  {\n    my $f=@_[0];\n\n    if ( !-d \
$f){return -s($f);}\n    else {return &dir2size($f\
);}\n  }\nsub dir2size\n  {\n    my $d=@_[0];\n   \
 my ($s, $f);\n    \n    if ( !-d $d) {return 0;}\\
n    \n    foreach $f (&dir2list ($d))\n      {\n	\
if ( -d $f){$s+=&dir2size (\"$d/$f\");}\n	else {$s\
+= -s \"$dir/$f\";}\n      }\n    return $s;\n  }\\
n\nsub remove \n  {\n    my $file=@_[0];\n    my (\
$f);\n    \n    debug_print( \"--- $file ---\\n\")\
;\n    if (($file eq \".\") || ($file eq \"..\") |\
| ($file=~/\\*/)){return EXIT_FAILURE;}\n    elsif\
 ( !-d $file)\n      {\n	debug_print (\"unlink $fi\
le\\n\");\n	if (-e $file){unlink ($file);}\n      \
}\n    elsif ( -d $file)\n      {\n	debug_print (\\
"++++++++ $file +++++++\\n\");\n	foreach $f (&dir2\
list($file))\n	  {\n	    &remove (\"$file/$f\");\n\
	  }\n	debug_print (\"rmdir $file\\n\");\n	rmdir $\
file;\n      }\n    else\n      {\n	debug_print (\\
"????????? $file ????????\\n\");\n      }\n    ret\
urn EXIT_SUCCESS;\n  }\n\nsub dir2list\n  {\n    m\
y $dir=@_[0];\n    my (@list1, @list2,@list3, $l);\
\n\n    opendir (DIR,$dir);\n    @list1=readdir (D\
IR);\n    closedir (DIR);\n    \n    foreach $l (@\
list1)\n      {\n	if ( $l ne \".\" && $l ne \"..\"\
){@list2=(@list2, $l);}\n      }\n    @list3 = sor\
t { (-M \"$dir/$list2[$b]\") <=> (-M \"$dir/$list2\
[$a]\")} @list2;\n    return @list3;\n    \n  }\n\\
nsub debug_print\n  {\n    \n    if ($DEBUG==1){pr\
int @_;}\n    \n  }\nsub create_ref_file\n  {\n   \
 my ($dir,$name_file,$size_file)=@_;\n    my ($f, \
$s, $tot_size, @l);\n    \n    if ( !-d $dir){retu\
rn;}\n    \n    @l=&dir2list ($dir);\n    open (F,\
 \">$name_file\");\n    foreach $f (@l)\n      {\n\
	$s=&size(\"$dir/$f\");\n	$tot_size+=$s;\n	print F\
 \"$f $s\\n\";\n      }\n    &myecho ($tot_size, \\
">$size_file\");\n    close (F);\n  }\nsub add_fil\
e \n  {\n    my ($dir,$name_file,$size_file,$file)\
=@_;\n    my ($s, $tot_size);\n    \n    if ( !-d \
$dir)   {return;}\n    if ( !-e \"$dir/$file\" ) {\
return;}\n    if ( !-e $name_file){&create_ref_fil\
e ($dir,$name_file,$size_file);}\n					    \n    $\
s=&size(\"$dir/$file\");\n    open (F, \">>$name_f\
ile\");\n    print F \"$file\\n\";\n    close (F);\
\n\n    $tot_size=&get_tot_size ($dir,$name_file,$\
size_file);\n    $tot_size+=$s;\n    &myecho ($tot\
_size, \">$size_file\");\n    \n  }\n	\nsub myecho\
\n  {\n    my ($string, $file)=@_;\n    open (ECHO\
, $file) || die;\n    print ECHO \"$string\";\n   \
 close (ECHO);\n  }\n    \n		\n	\nsub vtmpnam\n  {\
\n    my $tmp_file_name;\n    $tmp_name_counter++;\
\n    $tmp_file_name=\"tmp_file_for_clean_cache_pd\
b$$.$tmp_name_counter\";\n    $tmp_file_list[$ntmp\
_file++]=$tmp_file_name;\n    if ( -e $tmp_file_na\
me) {return &vtmpnam ();}\n    else {return $tmp_f\
ile_name;}\n  }\n","\nmy $address=\"http://www.tco\
ffee.org/Data/Datasets/NatureProtocolsDataset.tar.\
gz\";\nmy $out=\"NatureProtocolsDataset.tar.gz\";\\
n&url2file ($address,$out);\n\nif ( -e $out)\n  {\\
n    \n    system (\"gunzip NatureProtocolsDataset\
.tar.gz\");\n    system (\"tar -xvf NatureProtocol\
sDataset.tar\");\n  	system (\"rm -rf NatureProtoc\
olsDataset.tar\");  \n    print \"Your Data Set is\
 in the Folder 'NatureProtocolsDataset'\\n\";\n  }\
\nelse \n  {\n    print \"Could not Download Datas\
et --- Web site may be down -- Try again later\\n\\
";\n  }\n\n\n\n\nsub url2file\n{\n    my ($address\
, $out, $wget_arg, $curl_arg)=(@_);\n    my ($pg, \
$flag, $r, $arg, $count);\n    \n    if (!$CONFIGU\
RATION){&check_configuration (\"wget\", \"INTERNET\
\", \"gzip\");$CONFIGURATION=1;}\n    \n    if (&p\
g_is_installed (\"wget\"))   {$pg=\"wget\"; $flag=\
\"-O\";$arg=$wget_arg;}\n    elsif (&pg_is_install\
ed (\"curl\")){$pg=\"curl\"; $flag=\"-o\";$arg=$cu\
rl_arg;}\n    return system (\"$pg $address $flag \
$out>/dev/null 2>/dev/null\");\n\n}\n\nsub pg_is_i\
nstalled\n  {\n    my @ml=@_;\n    my $r, $p, $m;\\
n    my $supported=0;\n    \n    my $p=shift (@ml)\
;\n    if ($p=~/::/)\n      {\n	if (system (\"perl\
 -M$p -e 1\")==$EXIT_SUCCESS){return 1;}\n	else {r\
eturn 0;}\n      }\n    else\n      {\n	$r=`which \
$p 2>/dev/null`;\n	if ($r eq \"\"){return 0;}\n	el\
se {return 1;}\n      }\n  }\nsub check_configurat\
ion \n    {\n      my @l=@_;\n      my $v;\n      \
foreach my $p (@l)\n	{\n	  \n	  if   ( $p eq \"EMA\
IL\")\n	    { \n	      if ( !($EMAIL=~/@/))\n		{\n\
		  exit (EXIT_FAILURE);\n		}\n	    }\n	  elsif( $\
p eq \"INTERNET\")\n	    {\n	      if ( !&check_in\
ternet_connection())\n		{\n		  exit (EXIT_FAILURE)\
;\n		}\n	    }\n	  elsif( $p eq \"wget\")\n	    {\\
n	      if (!&pg_is_installed (\"wget\") && !&pg_i\
s_installed (\"curl\"))\n		{\n		  exit (EXIT_FAILU\
RE);\n		}\n	    }\n	  elsif( !(&pg_is_installed ($\
p)))\n	    {\n	      exit (EXIT_FAILURE);\n	    }\\
n	}\n      return 1;\n    }\nsub check_internet_co\
nnection\n  {\n    my $internet;\n    my $tmp;\n  \
  &check_configuration ( \"wget\"); \n    \n    $t\
mp=&vtmpnam ();\n    \n    if     (&pg_is_installe\
d    (\"wget\")){`wget www.google.com -O$tmp >/dev\
/null 2>/dev/null`;}\n    elsif  (&pg_is_installed\
    (\"curl\")){`curl www.google.com -o$tmp >/dev/\
null 2>/dev/null`;}\n    \n    if ( !-e $tmp || -s\
 $tmp < 10){$internet=0;}\n    else {$internet=1;}\
\n    if (-e $tmp){unlink $tmp;}\n\n    return $in\
ternet;\n  }\n\nsub vtmpnam\n      {\n	my $r=rand(\
100000);\n	my $f=\"file.$r.$$\";\n	while (-e $f)\n\
	  {\n	    $f=vtmpnam();\n	  }\n	push (@TMPFILE_LI\
ST, $f);\n	return $f;\n      }\n\n","\n$t_coffee=\\
"t_coffee\";\n\nforeach $value ( @ARGV)\n  {\n    \
$seq_file=$seq_file.\" \".$value;\n  }\n\n$name=$A\
RGV[0];\n$name=~s/\\.[^\\.]*$//;\n$lib_name=\"$nam\
e.mocca_lib\";\n$type=`t_coffee $seq_file -get_typ\
e -quiet`;\nchop ($type);\n\nif ( $type eq \"PROTE\
IN\"){$lib_mode=\"lalign_rs_s_pair -lalign_n_top 2\
0\";}\nelsif ( $type eq\"DNA\"){$lib_mode=\"lalign\
_rs_s_dna_pair -lalign_n_top 40\";}\n\nif ( !(-e $\
lib_name))\n  {\n	  \n  $command=\"$t_coffee -mocc\
a -seq_weight=no -cosmetic_penalty=0 -mocca_intera\
ctive -in $lib_mode -out_lib $lib_name -infile $se\
q_file\";\n  \n  }\nelsif ( (-e $lib_name))\n  {\n\
  $command=\"$t_coffee -mocca -seq_weight=no -cosm\
etic_penalty=0 -mocca_interactive -in $lib_name -i\
nfile $seq_file\";\n  \n  }\n\nsystem ($command);\\
n\nexit;\n\n","my $WSDL = 'http://www.ebi.ac.uk/To\
ols/webservices/wsdl/WSDaliLite.wsdl';\n\nuse SOAP\
::Lite;\nuse Data::Dumper;\nuse Getopt::Long qw(:c\
onfig no_ignore_case bundling);\nuse File::Basenam\
e;\n\nmy $checkInterval = 5;\n\nmy %params=(\n	   \
 'async' => '1', # Use async mode and simulate syn\
c mode in client\n	    );\nGetOptions(\n    'pdb1=\
s'     => \\$params{'sequence1'},\n    'chainid1=s\
' => \\$params{'chainid1'},\n    'pdb2=s'     => \\
\$params{'sequence2'},\n    'chainid2=s' => \\$par\
ams{'chainid2'},\n    \"help|h\"	 => \\$help, # Us\
age info\n    \"async|a\"	 => \\$async, # Asynchro\
nous submission\n    \"polljob\"	 => \\$polljob, #\
 Get results\n    \"status\"	 => \\$status, # Get \
status\n    \"jobid|j=s\"  => \\$jobid, # JobId\n \
   \"email|S=s\"  => \\$params{email}, # E-mail ad\
dress\n    \"trace\"      => \\$trace, # SOAP mess\
ages\n    \"sequence=s\" => \\$sequence, # Input P\
DB\n    );\n\nmy $scriptName = basename($0, ());\n\
if($help) {\n    &usage();\n    exit(0);\n}\n\nif(\
$trace) {\n    print \"Tracing active\\n\";\n    S\
OAP::Lite->import(+trace => 'debug');\n}\n\nmy $so\
ap = SOAP::Lite\n    ->service($WSDL)\n    ->on_fa\
ult(sub {\n        my $soap = shift;\n        my $\
res = shift;\n        # Throw an exception for all\
 faults\n        if(ref($res) eq '') {\n          \
  die($res);\n        } else {\n            die($r\
es->faultstring);\n        }\n        return new S\
OAP::SOM;\n    }\n               );\n\nif( !($poll\
job || $status) &&\n    !( defined($params{'sequen\
ce1'}) && defined($params{'sequence2'}) )\n    ) {\
\n    print STDERR 'Error: bad option combination'\
, \"\\n\";\n    &usage();\n    exit(1);\n}\nelsif(\
$polljob && defined($jobid)) {\n    print \"Gettin\
g results for job $jobid\\n\";\n    getResults($jo\
bid);\n}\nelsif($status && defined($jobid)) {\n   \
 print STDERR \"Getting status for job $jobid\\n\"\
;\n    my $result = $soap->checkStatus($jobid);\n \
   print STDOUT \"$result\", \"\\n\";\n    if($res\
ult eq 'DONE') {\n	print STDERR \"To get results: \
$scriptName --polljob --jobid $jobid\\n\";\n    }\\
n}\nelse {\n    if(-f $params{'sequence1'}) {\n	$p\
arams{'sequence1'} = read_file($params{'sequence1'\
});\n    }\n    if(-f $params{'sequence2'}) {\n	$p\
arams{'sequence2'} = read_file($params{'sequence2'\
});\n    }\n\n    my $jobid;\n    my $paramsData =\
 SOAP::Data->name('params')->type(map=>\\%params);\
\n    # For SOAP::Lite 0.60 and earlier parameters\
 are passed directly\n    if($SOAP::Lite::VERSION \
eq '0.60' || $SOAP::Lite::VERSION =~ /0\\.[1-5]/) \
{\n        $jobid = $soap->runDaliLite($paramsData\
);\n    }\n    # For SOAP::Lite 0.69 and later par\
ameter handling is different, so pass\n    # undef\
's for templated params, and then pass the formatt\
ed args.\n    else {\n        $jobid = $soap->runD\
aliLite(undef,\n				     $paramsData);\n    }\n\n \
   if (defined($async)) {\n	print STDOUT $jobid, \\
"\\n\";\n        print STDERR \"To check status: $\
scriptName --status --jobid $jobid\\n\";\n    } el\
se { # Synchronous mode\n        print STDERR \"Jo\
bId: $jobid\\n\";\n        sleep 1;\n        getRe\
sults($jobid);\n    }\n}\n\nsub clientPoll($) {\n \
   my $jobid = shift;\n    my $result = 'PENDING';\
\n    # Check status and wait if not finished\n   \
 #print STDERR \"Checking status: $jobid\\n\";\n  \
  while($result eq 'RUNNING' || $result eq 'PENDIN\
G') {\n        $result = $soap->checkStatus($jobid\
);\n        print STDERR \"$result\\n\";\n        \
if($result eq 'RUNNING' || $result eq 'PENDING') {\
\n            # Wait before polling again.\n      \
      sleep $checkInterval;\n        }\n    }\n}\n\
\nsub getResults($) {\n    $jobid = shift;\n    # \
Check status, and wait if not finished\n    client\
Poll($jobid);\n    # Use JobId if output file name\
 is not defined\n    unless(defined($outfile)) {\n\
        $outfile=$jobid;\n    }\n    # Get list of\
 data types\n    my $resultTypes = $soap->getResul\
ts($jobid);\n    # Get the data and write it to a \
file\n    if(defined($outformat)) { # Specified da\
ta type\n        my $selResultType;\n        forea\
ch my $resultType (@$resultTypes) {\n            i\
f($resultType->{type} eq $outformat) {\n          \
      $selResultType = $resultType;\n            }\
\n        }\n        $res=$soap->poll($jobid, $sel\
ResultType->{type});\n        write_file($outfile.\
'.'.$selResultType->{ext}, $res);\n    } else { # \
Data types available\n        # Write a file for e\
ach output type\n        for my $resultType (@$res\
ultTypes){\n            #print \"Getting $resultTy\
pe->{type}\\n\";\n            $res=$soap->poll($jo\
bid, $resultType->{type});\n            write_file\
($outfile.'.'.$resultType->{ext}, $res);\n        \
}\n    }\n}\n\nsub read_file($) {\n    my $filenam\
e = shift;\n    open(FILE, $filename);\n    my $co\
ntent;\n    my $buffer;\n    while(sysread(FILE, $\
buffer, 1024)) {\n	$content.= $buffer;\n    }\n   \
 close(FILE);\n    return $content;\n}\n\nsub writ\
e_file($$) {\n    my ($tmp,$entity) = @_;\n    pri\
nt STDERR \"Creating result file: \".$tmp.\"\\n\";\
\n    unless(open (FILE, \">$tmp\")) {\n	return 0;\
\n    }\n    syswrite(FILE, $entity);\n    close (\
FILE);\n    return 1;\n}\n\nsub usage {\n    print\
 STDERR <<EOF\nDaliLite\n========\n\nPairwise comp\
arison of protein structures\n\n[Required]\n\n  --\
pdb1                : str  : PDB ID for structure \
1\n  --pdb2                : str  : PDB ID for str\
ucture 2\n\n[Optional]\n\n  --chain1              \
: str  : Chain identifer in structure 1\n  --chain\
2              : str  : Chain identifer in structu\
re 2\n\n[General]\n\n  -h, --help            :    \
  : prints this help text\n  -S, --email          \
 : str  : user email address\n  -a, --async       \
    :      : asynchronous submission\n      --stat\
us          :      : poll for the status of a job\\
n      --polljob         :      : poll for the res\
ults of a job\n  -j, --jobid           : str  : jo\
bid for an asynchronous job\n  -O, --outfile      \
   : str  : file name for results (default is jobi\
d)\n      --trace	        :      : show SOAP messa\
ges being interchanged \n\nSynchronous job:\n\n  T\
he results/errors are returned as soon as the job \
is finished.\n  Usage: $scriptName --email <your\\\
@email> [options] pdbFile [--outfile string]\n  Re\
turns: saves the results to disk\n\nAsynchronous j\
ob:\n\n  Use this if you want to retrieve the resu\
lts at a later time. The results \n  are stored fo\
r up to 24 hours. \n  The asynchronous submission \
mode is recommended when users are submitting \n  \
batch jobs or large database searches	\n  Usage: $\
scriptName --email <your\\@email> --async [options\
] pdbFile\n  Returns: jobid\n\n  Use the jobid to \
query for the status of the job. \n  Usage: $scrip\
tName --status --jobid <jobId>\n  Returns: string \
indicating the status of the job:\n    DONE - job \
has finished\n    RUNNING - job is running\n    NO\
T_FOUND - job cannot be found\n    ERROR - the job\
s has encountered an error\n\n  When done, use the\
 jobid to retrieve the status of the job. \n  Usag\
e: $scriptName --polljob --jobid <jobId> [--outfil\
e string]\n\n[Help]\n\n  For more detailed help in\
formation refer to\n  http://www.ebi.ac.uk/DaliLit\
e/\nEOF\n;\n}\n","my $WSDL = 'http://www.ebi.ac.uk\
/Tools/webservices/wsdl/WSWUBlast.wsdl';\n\nuse st\
rict;\nuse SOAP::Lite;\nuse Getopt::Long qw(:confi\
g no_ignore_case bundling);\nuse File::Basename;\n\
\nmy $checkInterval = 15;\n\nmy $numOpts = scalar(\
@ARGV);\nmy ($outfile, $outformat, $help, $async, \
$polljob, $status, $ids, $jobid, $trace, $sequence\
);\nmy %params= ( # Defaults\n	      'async' => 1,\
 # Force into async mode\n	      'exp' => 10.0, # \
E-value threshold\n	      'numal' => 50, # Maximum\
 number of alignments\n	      'scores' => 100, # M\
aximum number of scores\n            );\nGetOption\
s( # Map the options into variables\n    \"program\
|p=s\"     => \\$params{program}, # BLAST program\\
n    \"database|D=s\"    => \\$params{database}, #\
 Search database\n    \"matrix|m=s\"      => \\$pa\
rams{matrix}, # Scoring matrix\n    \"exp|E=f\"   \
      => \\$params{exp}, # E-value threshold\n    \
\"echofilter|e\"    => \\$params{echofilter}, # Di\
splay filtered sequence\n    \"filter|f=s\"      =\
> \\$params{filter}, # Low complexity filter name\\
n    \"alignments|b=i\"  => \\$params{numal}, # Nu\
mber of alignments\n    \"scores|s=i\"      => \\$\
params{scores}, # Number of scores\n    \"sensitiv\
ity|S=s\" => \\$params{sensitivity}, # Search sens\
itivity\n    \"sort|t=s\"	      => \\$params{sort}\
, # Sort hits by...\n    \"stats|T=s\"       => \\\
$params{stats}, # Scoring statistic to use\n    \"\
strand|d=s\"      => \\$params{strand}, # Strand t\
o use in DNA vs. DNA search\n    \"topcombon|c=i\"\
   => \\$params{topcombon}, # Consistent sets of H\
SPs\n    \"outfile=s\"       => \\$outfile, # Outp\
ut file\n    \"outformat|o=s\"   => \\$outformat, \
# Output format\n    \"help|h\"	      => \\$help, \
# Usage info\n    \"async|a\"	      => \\$async, #\
 Asynchronous mode\n    \"polljob\"	      => \\$po\
lljob, # Get results\n    \"status\"	      => \\$s\
tatus, # Get job status\n    \"ids\"             =\
> \\$ids, # Get ids from result\n    \"jobid|j=s\"\
       => \\$jobid, # JobId\n    \"email=s\"      \
   => \\$params{email}, # E-mail address\n    \"tr\
ace\"           => \\$trace, # SOAP trace\n    \"s\
equence=s\"      => \\$sequence, # Query sequence\\
n    );\n\nmy $scriptName = basename($0, ());\nif(\
$help || $numOpts == 0) {\n    &usage();\n    exit\
(0);\n}\n\nif($trace){\n    print STDERR \"Tracing\
 active\\n\";\n    SOAP::Lite->import(+trace => 'd\
ebug');\n}\n\nmy $soap = SOAP::Lite\n    ->service\
($WSDL)\n    ->proxy('http://localhost/',\n    #pr\
oxy => ['http' => 'http://your.proxy.server/'], # \
HTTP proxy\n    timeout => 600, # HTTP connection \
timeout\n    )\n    ->on_fault(sub { # SOAP fault \
handler\n        my $soap = shift;\n        my $re\
s = shift;\n        # Throw an exception for all f\
aults\n        if(ref($res) eq '') {\n            \
die($res);\n        } else {\n            die($res\
->faultstring);\n        }\n        return new SOA\
P::SOM;\n    }\n               );\n\nif( !($polljo\
b || $status || $ids) &&\n    !( defined($ARGV[0])\
 || defined($sequence) )\n    ) {\n    print STDER\
R 'Error: bad option combination', \"\\n\";\n    &\
usage();\n    exit(1);\n}\nelsif($polljob && defin\
ed($jobid)) {\n    print \"Getting results for job\
 $jobid\\n\";\n    getResults($jobid);\n}\nelsif($\
status && defined($jobid)) {\n    print STDERR \"G\
etting status for job $jobid\\n\";\n    my $result\
 = $soap->checkStatus($jobid);\n    print STDOUT \\
"$result\\n\";\n    if($result eq 'DONE') {\n	prin\
t STDERR \"To get results: $scriptName --polljob -\
-jobid $jobid\\n\";\n    }\n}  \nelsif($ids && def\
ined($jobid)) {\n    print STDERR \"Getting ids fr\
om job $jobid\\n\";\n    getIds($jobid);\n}\nelse \
{\n    # Prepare input data\n    my $content;\n   \
 my (@contents) = ();\n    if(-f $ARGV[0] || $ARGV\
[0] eq '-') {	\n	$content={type=>'sequence',conten\
t=>read_file($ARGV[0])};	\n    }\n    if($sequence\
) {	\n	if(-f $sequence || $sequence eq '-') {	\n	 \
   $content={type=>'sequence',content=>read_file($\
ARGV[0])};	\n	} else {\n	    $content={type=>'sequ\
ence',content=>$sequence};\n	}\n    }\n    push @c\
ontents, $content;\n\n    # Submit the job\n    my\
 $paramsData = SOAP::Data->name('params')->type(ma\
p=>\\%params);\n    my $contentData = SOAP::Data->\
name('content')->value(\\@contents);\n    # For SO\
AP::Lite 0.60 and earlier parameters are passed di\
rectly\n    if($SOAP::Lite::VERSION eq '0.60' || $\
SOAP::Lite::VERSION =~ /0\\.[1-5]/) {\n        $jo\
bid = $soap->runWUBlast($paramsData, $contentData)\
;\n    }\n    # For SOAP::Lite 0.69 and later para\
meter handling is different, so pass\n    # undef'\
s for templated params, and then pass the formatte\
d args.\n    else {\n        $jobid = $soap->runWU\
Blast(undef, undef,\n				   $paramsData, $contentD\
ata);\n    }\n\n    # Asynchronous mode: output jo\
bid and exit.\n    if (defined($async)) {\n	print \
STDOUT $jobid, \"\\n\";\n        print STDERR \"To\
 check status: $scriptName --status --jobid $jobid\
\\n\";\n    }\n    # Synchronous mode: try to get \
results\n    else {\n        print STDERR \"JobId:\
 $jobid\\n\";\n        sleep 1;\n        getResult\
s($jobid);\n    }\n}\n\nsub getIds($) {\n    my $j\
obid = shift;\n    my $results = $soap->getIds($jo\
bid);\n    for my $result (@$results){\n	print \"$\
result\\n\";\n    }\n}\n\nsub clientPoll($) {\n   \
 my $jobid = shift;\n    my $result = 'PENDING';\n\
    # Check status and wait if not finished\n    w\
hile($result eq 'RUNNING' || $result eq 'PENDING')\
 {\n        $result = $soap->checkStatus($jobid);\\
n        print STDERR \"$result\\n\";\n        if(\
$result eq 'RUNNING' || $result eq 'PENDING') {\n \
           # Wait before polling again.\n         \
   sleep $checkInterval;\n        }\n    }\n}\n\ns\
ub getResults($) {\n    my $jobid = shift;\n    my\
 $res;\n    # Check status, and wait if not finish\
ed\n    clientPoll($jobid);\n    # Use JobId if ou\
tput file name is not defined\n    unless(defined(\
$outfile)) {\n        $outfile=$jobid;\n    }\n   \
 # Get list of data types\n    my $resultTypes = $\
soap->getResults($jobid);\n    # Get the data and \
write it to a file\n    if(defined($outformat)) { \
# Specified data type\n	if($outformat eq 'xml') {$\
outformat = 'toolxml';}\n	if($outformat eq 'txt') \
{$outformat = 'tooloutput';}\n        my $selResul\
tType;\n        foreach my $resultType (@$resultTy\
pes) {\n            if($resultType->{type} eq $out\
format) {\n                $selResultType = $resul\
tType;\n            }\n        }\n        $res=$so\
ap->poll($jobid, $selResultType->{type});\n	if($ou\
tfile eq '-') {\n	     write_file($outfile, $res);\
\n	} else {\n	    write_file($outfile.'.'.$selResu\
ltType->{ext}, $res);\n	}\n    } else { # Data typ\
es available\n        # Write a file for each outp\
ut type\n        for my $resultType (@$resultTypes\
){\n            #print STDERR \"Getting $resultTyp\
e->{type}\\n\";\n            $res=$soap->poll($job\
id, $resultType->{type});\n	    if($outfile eq '-'\
) {\n		write_file($outfile, $res);\n	    } else {\\
n		write_file($outfile.'.'.$resultType->{ext}, $re\
s);\n	    }\n        }\n    }\n}\n\nsub read_file(\
$) {\n    my $filename = shift;\n    my ($content,\
 $buffer);\n    if($filename eq '-') {\n	while(sys\
read(STDIN, $buffer, 1024)) {\n	    $content .= $b\
uffer;\n	}\n    }\n    else { # File\n	open(FILE, \
$filename) or die \"Error: unable to open input fi\
le\";\n	while(sysread(FILE, $buffer, 1024)) {\n	  \
  $content .= $buffer;\n	}\n	close(FILE);\n    }\n\
    return $content;\n}\n\nsub write_file($$) {\n \
   my ($filename, $data) = @_;\n    print STDERR '\
Creating result file: ' . $filename . \"\\n\";\n  \
  if($filename eq '-') {\n	print STDOUT $data;\n  \
  }\n    else {\n	open(FILE, \">$filename\") or di\
e \"Error: unable to open output file\";\n	syswrit\
e(FILE, $data);\n	close(FILE);\n    }\n}\n\nsub us\
age {\n    print STDERR <<EOF\nWU-BLAST\n========\\
n\nRapid sequence database search programs utilizi\
ng the BLAST algorithm.\n   \n[Required]\n\n      \
--email       : str  : user email address \n  -p, \
--program	    : str  : BLAST program to use: blast\
n, blastp, blastx, \n                             \
tblastn or tblastx\n  -D, --database    : str  : d\
atabase to search\n  seqFile           : file : qu\
ery sequence data file (\"-\" for STDIN)\n\n[Optio\
nal]\n\n  -m, --matrix	    : str  : scoring matrix\
\n  -E, --exp	    : real : 0<E<= 1000. Statistical\
 significance threshold\n                         \
    for reporting database sequence matches.\n  -e\
, --echofilter  :      : display the filtered quer\
y sequence in the output\n  -f, --filter	    : str\
  : activates filtering of the query sequence\n  -\
b, --alignments  : int  : number of alignments to \
be reported\n  -s, --scores	    : int  : number of\
 scores to be reported\n  -S, --sensitivity : str \
 :\n  -t, --sort	    : str  :\n  -T, --stats      \
 : str  :\n  -d, --strand      : str  : DNA strand\
 to search with in DNA vs. DNA searches \n  -c, --\
topcombon   :      :\n\n[General]	\n\n  -h, --help\
       :      : prints this help text\n  -a, --asy\
nc      :      : forces to make an asynchronous qu\
ery\n      --status     :      : poll for the stat\
us of a job\n      --polljob    :      : poll for \
the results of a job\n  -j, --jobid      : str  : \
jobid that was returned when an asynchronous job \\
n                            was submitted.\n  -O,\
 --outfile    : str  : name of the file results sh\
ould be written to \n                            (\
default is based on the jobid; \"-\" for STDOUT)\n\
  -o, --outformat  : str  : txt or xml output (no \
file is written)\n      --trace	   :      : show S\
OAP messages being interchanged \n\nSynchronous jo\
b:\n\n  The results/errors are returned as soon as\
 the job is finished.\n  Usage: $scriptName --emai\
l <your\\@email> [options...] seqFile\n  Returns: \
saves the results to disk\n\nAsynchronous job:\n\n\
  Use this if you want to retrieve the results at \
a later time. The results \n  are stored for up to\
 24 hours. \n  The asynchronous submission mode is\
 recommended when users are submitting \n  batch j\
obs or large database searches	\n  Usage: $scriptN\
ame --async --email <your\\@email> [options...] se\
qFile\n  Returns : jobid\n\n  Use the jobid to que\
ry for the status of the job. \n  Usage: $scriptNa\
me --status --jobid <jobId>\n  Returns : string in\
dicating the status of the job:\n    DONE - job ha\
s finished\n    RUNNING - job is running\n    NOT_\
FOUND - job cannot be found\n    ERROR - the jobs \
has encountered an error\n\n  When done, use the j\
obid to retrieve the status of the job. \n  Usage:\
 $scriptName --polljob --jobid <jobId> [--outfile \
string]\n  Returns: saves the results to disk\n\n[\
Help]\n\nFor more detailed help information refer \
to \nhttp://www.ebi.ac.uk/blast2/WU-Blast2_Help_fr\
ame.html\n \nEOF\n;\n}\n","\nmy $WSDL = 'http://ww\
w.ebi.ac.uk/Tools/webservices/wsdl/WSBlastpgp.wsdl\
';\n\nuse SOAP::Lite;\nuse Getopt::Long qw(:config\
 no_ignore_case bundling);\nuse File::Basename;\n\\
nmy $checkInterval = 15;\n\nmy %params=(\n	    'as\
ync' => '1', # Use async mode and simulate sync mo\
de in client\n	    );\nGetOptions(\n    \"mode=s\"\
           => \\$params{mode}, # Search mode: PSI-\
Blast or PHI-Blast\n    \"database|d=s\"     => \\\
$params{database}, # Database to search\n    \"mat\
rix|M=s\"       => \\$params{matrix},# Scoring max\
trix\n    \"exp|e=f\"          => \\$params{exp}, \
# E-value\n    \"expmulti|h=f\"     => \\$params{e\
xpmulti}, # E-value\n    \"filter|F=s\"       => \\
\$params{filter}, # Low complexity filter\n    \"d\
ropoff|X=i\"      => \\$params{dropoff}, # Dropoff\
 score\n    \"finaldropoff|Z=i\" => \\$params{fina\
ldropoff}, # Final dropoff score\n    \"scores|v=i\
\"       => \\$params{scores}, # Max number of sco\
res\n    \"align=i\"          => \\$params{align},\
 # Alignment view\n    \"startregion|S=i\"  => \\$\
params{startregion}, # Start of region in query\n \
   \"endregion|H=i\"    => \\$params{endregion}, #\
 End of region in query\n    \"maxpasses|j=i\"    \
=> \\$params{maxpasses}, # Number of PSI iteration\
s\n    \"opengap|G=i\"      => \\$params{opengap},\
 # Gap open penalty\n    \"extendgap|E=i\"    => \\
\$params{extendgap}, # Gap extension penalty\n    \
\"pattern=s\"        => \\$params{pattern}, # PHI-\
BLAST pattern\n    \"usagemode|p=s\"    => \\$para\
ms{usagemode}, # PHI-BLAST program\n    \"appxml=s\
\"         => \\$params{appxml}, # Application XML\
\n    \"sequence=s\"       => \\$sequence, # Query\
 sequence\n    \"help\"	       => \\$help, # Usage\
 info\n    \"polljob\"	       => \\$polljob, # Get\
 results\n    \"status\"	       => \\$status, # Ge\
t status\n    \"ids\"      	       => \\$ids, # Ge\
t ids from result\n    \"jobid=s\"          => \\$\
jobid, # JobId\n    \"outfile=s\"        => \\$out\
file, # Output filename\n    \"outformat|o=s\"    \
=> \\$outformat, # Output file format\n    \"async\
|a\"	       => \\$async, # Async submission\n    \\
"email=s\"          => \\$params{email}, # User e-\
mail address\n    \"trace\"            => \\$trace\
, # Show SOAP messages\n    );\n\nmy $scriptName =\
 basename($0, ());\nif($help) {\n    &usage();\n  \
  exit(0);\n}\n\nif ($trace){\n    print \"Tracing\
 active\\n\";\n    SOAP::Lite->import(+trace => 'd\
ebug');\n}\n\nmy $soap = SOAP::Lite\n    ->service\
($WSDL)\n    ->on_fault(sub {\n        my $soap = \
shift;\n        my $res = shift;\n        # Throw \
an exception for all faults\n        if(ref($res) \
eq '') {\n            die($res);\n        } else {\
\n            die($res->faultstring);\n        }\n\
        return new SOAP::SOM;\n    }\n            \
   );\n\nif( !($polljob || $status || $ids) &&\n  \
  !( (defined($ARGV[0]) && -f $ARGV[0]) || defined\
($sequence) )\n    ) {\n    print STDERR 'Error: b\
ad option combination', \"\\n\";\n    &usage();\n \
   exit(1);\n}\nelsif($polljob && defined($jobid))\
 {\n    print \"Getting results for job $jobid\\n\\
";\n    getResults($jobid);\n}\nelsif($status && d\
efined($jobid)) {\n    print STDERR \"Getting stat\
us for job $jobid\\n\";\n    my $result = $soap->c\
heckStatus($jobid);\n    print STDOUT $result, \"\\
\n\";\n    if($result eq 'DONE') {\n	print STDERR \
\"To get results: $scriptName --polljob --jobid $j\
obid\\n\";\n    }\n}  \nelsif($ids && defined($job\
id)) {\n    print STDERR \"Getting ids from job $j\
obid\\n\";\n    getIds($jobid);\n}\nelse {\n    if\
(-f $ARGV[0]) {	\n	$content={type=>'sequence', con\
tent=>read_file($ARGV[0])};	\n    }\n    if($seque\
nce) {	\n	if(-f $sequence) {\n	    $content={type=\
>'sequence', content=>read_file($sequence)};	\n	} \
else {\n	    $content={type=>'sequence', content=>\
$sequence};\n	}\n    }\n    push @content, $conten\
t;\n\n    my $jobid;\n    my $paramsData = SOAP::D\
ata->name('params')->type(map=>\\%params);\n    my\
 $contentData = SOAP::Data->name('content')->value\
(\\@content);\n    # For SOAP::Lite 0.60 and earli\
er parameters are passed directly\n    if($SOAP::L\
ite::VERSION eq '0.60' || $SOAP::Lite::VERSION =~ \
/0\\.[1-5]/) {\n        $jobid = $soap->runBlastpg\
p($paramsData, $contentData);\n    }\n    # For SO\
AP::Lite 0.69 and later parameter handling is diff\
erent, so pass\n    # undef's for templated params\
, and then pass the formatted args.\n    else {\n \
       $jobid = $soap->runBlastpgp(undef, undef,\n\
				    $paramsData, $contentData);\n    }\n\n    \
if (defined($async)) {\n	print STDOUT $jobid, \"\\\
n\";\n        print STDERR \"To check status: $scr\
iptName --status --jobid $jobid\\n\";\n    } else \
{ # Synchronous mode\n        print STDERR \"JobId\
: $jobid\\n\";\n        sleep 1;\n        getResul\
ts($jobid);\n    }\n}\n\nsub getIds($) {\n    $job\
id = shift;\n    my $results = $soap->getIds($jobi\
d);\n    for $result (@$results){\n	print \"$resul\
t\\n\";\n    }\n}\n\nsub clientPoll($) {\n    my $\
jobid = shift;\n    my $result = 'PENDING';\n    #\
 Check status and wait if not finished\n    #print\
 STDERR \"Checking status: $jobid\\n\";\n    while\
($result eq 'RUNNING' || $result eq 'PENDING') {\n\
        $result = $soap->checkStatus($jobid);\n   \
     print STDERR \"$result\\n\";\n        if($res\
ult eq 'RUNNING' || $result eq 'PENDING') {\n     \
       # Wait before polling again.\n            s\
leep $checkInterval;\n        }\n    }\n}\n\nsub g\
etResults($) {\n    $jobid = shift;\n    # Check s\
tatus, and wait if not finished\n    clientPoll($j\
obid);\n    # Use JobId if output file name is not\
 defined\n    unless(defined($outfile)) {\n       \
 $outfile=$jobid;\n    }\n    # Get list of data t\
ypes\n    my $resultTypes = $soap->getResults($job\
id);\n    # Get the data and write it to a file\n \
   if(defined($outformat)) { # Specified data type\
\n        my $selResultType;\n        foreach my $\
resultType (@$resultTypes) {\n            if($resu\
ltType->{type} eq $outformat) {\n                $\
selResultType = $resultType;\n            }\n     \
   }\n        $res=$soap->poll($jobid, $selResultT\
ype->{type});\n        write_file($outfile.'.'.$se\
lResultType->{ext}, $res);\n    } else { # Data ty\
pes available\n        # Write a file for each out\
put type\n        for my $resultType (@$resultType\
s){\n            #print \"Getting $resultType->{ty\
pe}\\n\";\n            $res=$soap->poll($jobid, $r\
esultType->{type});\n            write_file($outfi\
le.'.'.$resultType->{ext}, $res);\n        }\n    \
}\n}\n\nsub read_file($) {\n    my $filename = shi\
ft;\n    open(FILE, $filename);\n    my $content;\\
n    my $buffer;\n    while(sysread(FILE, $buffer,\
 1024)) {\n	$content.= $buffer;\n    }\n    close(\
FILE);  \n    return $content;\n}\n\nsub write_fil\
e($$) {\n    my ($tmp,$entity) = @_;\n    print ST\
DERR \"Creating result file: \".$tmp.\"\\n\";\n   \
 unless(open (FILE, \">$tmp\")) {\n	return 0;\n   \
 }\n    syswrite(FILE, $entity);\n    close (FILE)\
;\n    return 1;\n}\n\nsub usage {\n    print STDE\
RR <<EOF\nBlastpgp\n========\n   \nThe blastpgp pr\
ogram implements the PSI-BLAST and PHI-BLAST varia\
tions\nof NCBI BLAST.\n\nFor more detailed help in\
formation refer to\nhttp://www.ebi.ac.uk/blastpgp/\
blastpsi_help_frame.html\n \nBlastpgp specific opt\
ions:\n\n[Required]\n\n      --mode            : s\
tr  : search mode to use: PSI-Blast or PHI-Blast\n\
  -d, --database        : str  : protein database \
to search\n  seqFile               : file : query \
sequence\n\n[Optional]\n\n  -M, --matrix          \
: str  : scoring matrix\n  -e, --exp             :\
 real : Expectation value\n  -h, --expmulti       \
 : real : threshold (multipass model)\n  -F, --fil\
ter          : str  : filter query sequence with S\
EG [T,F]\n  -m, --align           : int  : alignme\
nt view option:\n                                 \
0 - pairwise, 1 - M/S identities,\n               \
                  2 - M/S non-identities, 3 - Flat\
 identities,\n                                 4 -\
 Flat non-identities\n  -G, --opengap         : in\
t  : cost to open a gap\n  -E, --extendgap       :\
 int  : cost to extend a gap\n  -g, --gapalign    \
    : str  : Gapped [T,F]\n  -v, --scores         \
 : int  : number of scores to be reported\n  -j, -\
-maxpasses       : int  : number of iterations\n  \
-X, --dropoff         : int  : Dropoff score\n  -Z\
, --finaldropoff    : int  : Dropoff for final ali\
gnment\n  -S, --startregion     : int  : Start of \
required region in query\n  -H, --endregion       \
: int  : End of required region in query\n  -k, --\
pattern         : str  : Hit File (PHI-BLAST only)\
\n  -p, --usagemode       : str  : Program option \
(PHI-BLAST only):\n                               \
  blastpgp, patseedp, seedp\n\n[General]\n\n      \
--help            :      : prints this help text\n\
  -a, --async           :      : forces to make an\
 asynchronous query\n      --status          :    \
  : poll for the status of a job\n      --polljob \
        :      : poll for the results of a job\n  \
    --jobid           : str  : jobid of an asynchr\
onous job\n      --ids             :      : get hi\
t identifiers for result \n  -O, --outfile        \
 : str  : name of the file results should be writt\
en to\n                                 (default i\
s based on the jobid)\n  -o, --outformat       : s\
tr  : txt or xml output (no file is written)\n    \
  --trace           :      : show SOAP messages be\
ing interchanged\n\nSynchronous job:\n\n  The resu\
lts/errors are returned as soon as the job is fini\
shed.\n  Usage: blastpgp.pl --email <your@email> [\
options...] seqfile\n  Returns: saves the results \
to disk\n\nAsynchronous job:\n\n  Use this if you \
want to retrieve the results at a later time. The \
results\n  are stored for up to 24 hours.\n  The a\
synchronous submission mode is recommended when us\
ers are submitting\n  batch jobs or large database\
 searches\n  Usage: blastpgp.pl --email <your@emai\
l> --async [options...] seqFile\n  Returns: jobid\\
n\n  Use the jobid to query for the status of the \
job.\n  Usage: blastpgp.pl --status --jobid <jobId\
>\n  Returns: string indicating the status of the \
job\n    DONE - job has finished\n    RUNNING - jo\
b is running\n    NOT_FOUND - job cannot be found\\
n    ERROR - the jobs has encountered an error\n\n\
  When done, use the jobid to retrieve the results\
 of the job.\n  Usage: blastpgp.pl --polljob --job\
id <jobId> [--outfile <fileName>]\n  Returns: save\
s the results to disk\nEOF\n;\n}\n","\n=head1 NAME\
\n\nncbiblast_lwp.pl\n\n=head1 DESCRIPTION\n\nNCBI\
 BLAST (REST) web service Perl client using L<LWP>\
.\n\nTested with:\n\n=over\n\n=item *\nL<LWP> 5.79\
, L<XML::Simple> 2.12 and Perl 5.8.3\n\n=item *\nL\
<LWP> 5.808, L<XML::Simple> 2.18 and Perl 5.8.8 (U\
buntu 8.04 LTS)\n\n=item *\nL<LWP> 5.834, L<XML::S\
imple> 2.18 and Perl 5.10.1 (Ubuntu 10.04 LTS)\n\n\
=item *\nL<LWP> 6.03, L<XML::Simple> 2.18 and Perl\
 5.14.2 (Ubuntu 12.04 LTS)\n\n=back\n\nFor further\
 information see:\n\n=over\n\n=item *\nL<http://ww\
w.ebi.ac.uk/Tools/webservices/services/sss/ncbi_bl\
ast_rest>\n\n=item *\nL<http://www.ebi.ac.uk/Tools\
/webservices/tutorials/perl>\n\n=back\n\n=head1 LI\
CENSE\n\nCopyright 2012-2013 EMBL - European Bioin\
formatics Institute\n\nLicensed under the Apache L\
icense, Version 2.0 (the \"License\");\nyou may no\
t use this file except in compliance with the Lice\
nse.\nYou may obtain a copy of the License at\n\n \
   http://www.apache.org/licenses/LICENSE-2.0\n\nU\
nless required by applicable law or agreed to in w\
riting, software\ndistributed under the License is\
 distributed on an \"AS IS\" BASIS,\nWITHOUT WARRA\
NTIES OR CONDITIONS OF ANY KIND, either express or\
 implied.\nSee the License for the specific langua\
ge governing permissions and\nlimitations under th\
e License.\n\n=head1 VERSION\n\n$Id: ncbiblast_lwp\
.pl 2560 2013-03-20 12:56:31Z hpm $\n\n=cut\n\nuse\
 strict;\nuse warnings;\n\nuse English;\nuse LWP;\\
nuse XML::Simple;\nuse Getopt::Long qw(:config no_\
ignore_case bundling);\nuse File::Basename;\nuse D\
ata::Dumper;\n\nmy $baseUrl = 'http://www.ebi.ac.u\
k/Tools/services/rest/ncbiblast';\n\nmy $checkInte\
rval = 3;\n\nmy $outputLevel = 1;\n\nmy $numOpts =\
 scalar(@ARGV);\nmy %params = ( 'debugLevel' => 0 \
);\n\nmy %tool_params = ();\nGetOptions(\n\n	# Too\
l specific options\n	'program|p=s'  => \\$tool_par\
ams{'program'},   # blastp, blastn, blastx, etc.\n\
	'database|D=s' => \\$params{'database'},       # \
Database(s) to search\n	'matrix|m=s'   => \\$tool_\
params{'matrix'},    # Scoring martix to use\n	'ex\
p|E=f'      => \\$tool_params{'exp'},       # E-va\
lue threshold\n	'filter|f=s'   => \\$tool_params{'\
filter'},    # Low complexity filter\n	'align|A=i'\
    => \\$tool_params{'align'},     # Pairwise ali\
gnment format\n	'scores|s=i'   => \\$tool_params{'\
scores'},    # Number of scores\n	'alignments|n=i'\
 => \\$tool_params{'alignments'},   # Number of al\
ignments\n	'dropoff|d=i'    => \\$tool_params{'dro\
poff'},      # Dropoff score\n	'match_scores=s' =>\
 \\$tool_params{'match_scores'}, # Match/missmatch\
 scores\n	'match|u=i'      => \\$params{'match'}, \
            # Match score\n	'mismatch|v=i'   => \\\
$params{'mismatch'},          # Mismatch score\n	'\
gapopen|o=i'    => \\$tool_params{'gapopen'},     \
 # Open gap penalty\n	'gapext|x=i'     => \\$tool_\
params{'gapext'},       # Gap extension penality\n\
	'gapalign|g'     => \\$tool_params{'gapalign'},  \
   # Optimise gap alignments\n	'stype=s' => \\$too\
l_params{'stype'},    # Sequence type\n	'seqrange=\
s' => \\$tool_params{'seqrange'},    # Query subse\
quence\n	'sequence=s' => \\$params{'sequence'},   \
      # Query sequence\n	'multifasta' => \\$params\
{'multifasta'},       # Multiple fasta input\n\n	#\
 Compatability options, old command-line\n	'numal|\
n=i'     => \\$params{'numal'},        # Number of\
 alignments\n	'opengap|o=i'   => \\$params{'openga\
p'},      # Open gap penalty\n	'extendgap|x=i' => \
\\$params{'extendgap'},    # Gap extension penalit\
y\n	\n	# Generic options\n	'email=s'       => \\$p\
arams{'email'},          # User e-mail address\n	'\
title=s'       => \\$params{'title'},          # J\
ob title\n	'outfile=s'     => \\$params{'outfile'}\
,        # Output file name\n	'outformat=s'   => \\
\$params{'outformat'},      # Output file type\n	'\
jobid=s'       => \\$params{'jobid'},          # J\
obId\n	'help|h'        => \\$params{'help'},      \
     # Usage help\n	'async'         => \\$params{'\
async'},          # Asynchronous submission\n	'pol\
ljob'       => \\$params{'polljob'},        # Get \
results\n	'resultTypes'   => \\$params{'resultType\
s'},    # Get result types\n	'status'        => \\\
$params{'status'},         # Get status\n	'params'\
        => \\$params{'params'},         # List inp\
ut parameters\n	'paramDetail=s' => \\$params{'para\
mDetail'},    # Get details for parameter\n	'quiet\
'         => \\$params{'quiet'},          # Decrea\
se output level\n	'verbose'       => \\$params{'ve\
rbose'},        # Increase output level\n	'debugLe\
vel=i'  => \\$params{'debugLevel'},     # Debug ou\
tput level\n	'baseUrl=s'     => \\$baseUrl,       \
           # Base URL for service.\n);\nif ( $para\
ms{'verbose'} ) { $outputLevel++ }\nif ( $params{'\
quiet'} )  { $outputLevel-- }\n\n&print_debug_mess\
age( 'MAIN', 'LWP::VERSION: ' . $LWP::VERSION,\n	1\
 );\n\n&print_debug_message( 'MAIN', \"params:\\n\\
" . Dumper( \\%params ),           11 );\n&print_d\
ebug_message( 'MAIN', \"tool_params:\\n\" . Dumper\
( \\%tool_params ), 11 );\n\nmy $ua;\n\nmy $script\
Name = basename( $0, () );\n\nif ( $params{'help'}\
 || $numOpts == 0 ) {\n	&usage();\n	exit(0);\n}\n\\
n&print_debug_message( 'MAIN', 'baseUrl: ' . $base\
Url, 1 );\n\nif (\n	!(\n		   $params{'polljob'}\n	\
	|| $params{'resultTypes'}\n		|| $params{'status'}\
\n		|| $params{'params'}\n		|| $params{'paramDetai\
l'}\n	)\n	&& !( defined( $ARGV[0] ) || defined( $p\
arams{'sequence'} ) )\n  )\n{\n\n	# Bad argument c\
ombination, so print error message and usage\n	pri\
nt STDERR 'Error: bad option combination', \"\\n\"\
;\n	&usage();\n	exit(1);\n}\n\nelsif ( $params{'pa\
rams'} ) {\n	&print_tool_params();\n}\n\nelsif ( $\
params{'paramDetail'} ) {\n	&print_param_details( \
$params{'paramDetail'} );\n}\n\nelsif ( $params{'s\
tatus'} && defined( $params{'jobid'} ) ) {\n	&prin\
t_job_status( $params{'jobid'} );\n}\n\nelsif ( $p\
arams{'resultTypes'} && defined( $params{'jobid'} \
) ) {\n	&print_result_types( $params{'jobid'} );\n\
}\n\nelsif ( $params{'polljob'} && defined( $param\
s{'jobid'} ) ) {\n	&get_results( $params{'jobid'} \
);\n}\n\nelse {\n\n	# Multiple input sequence mode\
, assume fasta format.\n	if ( $params{'multifasta'\
} ) {\n		&multi_submit_job();\n	}\n\n	# Entry iden\
tifier list file.\n	elsif (( defined( $params{'seq\
uence'} ) && $params{'sequence'} =~ m/^\\@/ )\n		|\
| ( defined( $ARGV[0] ) && $ARGV[0] =~ m/^\\@/ ) )\
\n	{\n		my $list_filename = $params{'sequence'} ||\
 $ARGV[0];\n		$list_filename =~ s/^\\@//;\n		&list\
_file_submit_job($list_filename);\n	}\n\n	# Defaul\
t: single sequence/identifier.\n	else {\n\n		# Loa\
d the sequence data and submit.\n		&submit_job( &l\
oad_data() );\n	}\n}\n\n=head1 FUNCTIONS\n\n=cut\n\
\n\n=head2 rest_user_agent()\n\nGet a LWP UserAgen\
t to use to perform REST requests.\n\n  my $ua = &\
rest_user_agent();\n\n=cut\n\nsub rest_user_agent(\
) {\n	print_debug_message( 'rest_user_agent', 'Beg\
in', 21 );\n	# Create an LWP UserAgent for making \
HTTP calls.\n	my $ua = LWP::UserAgent->new();\n	# \
Set 'User-Agent' HTTP header to identifiy the clie\
nt.\n	'$Revision: 2560 $' =~ m/(\\d+)/;\n	$ua->age\
nt(\"EBI-Sample-Client/$1 ($scriptName; $OSNAME) \\
" . $ua->agent());\n	# Configure HTTP proxy suppor\
t from environment.\n	$ua->env_proxy;\n	print_debu\
g_message( 'rest_user_agent', 'End', 21 );\n	retur\
n $ua;\n}\n\n=head2 rest_error()\n\nCheck a REST r\
esponse for an error condition. An error is mapped\
 to a die.\n\n  &rest_error($response, $content_da\
ta);\n\n=cut\n\nsub rest_error() {\n	print_debug_m\
essage( 'rest_error', 'Begin', 21 );\n	my $respons\
e = shift;\n	my $contentdata;\n	if(scalar(@_) > 0)\
 {\n		$contentdata = shift;\n	}\n	if(!defined($con\
tentdata) || $contentdata eq '') {\n		$contentdata\
 = $response->content();\n	}\n	# Check for HTTP er\
ror codes\n	if ( $response->is_error ) {\n		my $er\
ror_message = '';\n		# HTML response.\n		if(	$cont\
entdata =~ m/<h1>([^<]+)<\\/h1>/ ) {\n			$error_me\
ssage = $1;\n		}\n		#  XML response.\n		elsif($con\
tentdata =~ m/<description>([^<]+)<\\/description>\
/) {\n			$error_message = $1;\n		}\n		die 'http st\
atus: ' . $response->code . ' ' . $response->messa\
ge . '  ' . $error_message;\n	}\n	print_debug_mess\
age( 'rest_error', 'End', 21 );\n}\n\n=head2 rest_\
request()\n\nPerform a REST request (HTTP GET).\n\\
n  my $response_str = &rest_request($url);\n\n=cut\
\n\nsub rest_request {\n	print_debug_message( 'res\
t_request', 'Begin', 11 );\n	my $requestUrl = shif\
t;\n	print_debug_message( 'rest_request', 'URL: ' \
. $requestUrl, 11 );\n\n	# Get an LWP UserAgent.\n\
	$ua = &rest_user_agent() unless defined($ua);\n	#\
 Available HTTP compression methods.\n	my $can_acc\
ept;\n	eval {\n	    $can_accept = HTTP::Message::d\
ecodable();\n	};\n	$can_accept = '' unless defined\
($can_accept);\n	# Perform the request\n	my $respo\
nse = $ua->get($requestUrl,\n		'Accept-Encoding' =\
> $can_accept, # HTTP compression.\n	);\n	print_de\
bug_message( 'rest_request', 'HTTP status: ' . $re\
sponse->code,\n		11 );\n	print_debug_message( 'res\
t_request',\n		'response length: ' . length($respo\
nse->content()), 11 );\n	print_debug_message( 'res\
t_request',\n		'request:' .\"\\n\" . $response->re\
quest()->as_string(), 32 );\n	print_debug_message(\
 'rest_request',\n		'response: ' . \"\\n\" . $resp\
onse->as_string(), 32 );\n	# Unpack possibly compr\
essed response.\n	my $retVal;\n	if ( defined($can_\
accept) && $can_accept ne '') {\n	    $retVal = $r\
esponse->decoded_content();\n	}\n	# If unable to d\
ecode use orginal content.\n	$retVal = $response->\
content() unless defined($retVal);\n	# Check for a\
n error.\n	&rest_error($response, $retVal);\n	prin\
t_debug_message( 'rest_request', 'retVal: ' . $ret\
Val, 12 );\n	print_debug_message( 'rest_request', \
'End', 11 );\n\n	# Return the response data\n	retu\
rn $retVal;\n}\n\n=head2 rest_get_parameters()\n\n\
Get list of tool parameter names.\n\n  my (@param_\
list) = &rest_get_parameters();\n\n=cut\n\nsub res\
t_get_parameters {\n	print_debug_message( 'rest_ge\
t_parameters', 'Begin', 1 );\n	my $url            \
    = $baseUrl . '/parameters/';\n	my $param_list_\
xml_str = rest_request($url);\n	my $param_list_xml\
     = XMLin($param_list_xml_str);\n	my (@param_li\
st)       = @{ $param_list_xml->{'id'} };\n	print_\
debug_message( 'rest_get_parameters', 'End', 1 );\\
n	return (@param_list);\n}\n\n=head2 rest_get_para\
meter_details()\n\nGet details of a tool parameter\
.\n\n  my $paramDetail = &rest_get_parameter_detai\
ls($param_name);\n\n=cut\n\nsub rest_get_parameter\
_details {\n	print_debug_message( 'rest_get_parame\
ter_details', 'Begin', 1 );\n	my $parameterId = sh\
ift;\n	print_debug_message( 'rest_get_parameter_de\
tails',\n		'parameterId: ' . $parameterId, 1 );\n	\
my $url                  = $baseUrl . '/parameterd\
etails/' . $parameterId;\n	my $param_detail_xml_st\
r = rest_request($url);\n	my $param_detail_xml    \
 = XMLin($param_detail_xml_str);\n	print_debug_mes\
sage( 'rest_get_parameter_details', 'End', 1 );\n	\
return ($param_detail_xml);\n}\n\n=head2 rest_run(\
)\n\nSubmit a job.\n\n  my $job_id = &rest_run($em\
ail, $title, \\%params );\n\n=cut\n\nsub rest_run \
{\n	print_debug_message( 'rest_run', 'Begin', 1 );\
\n	my $email  = shift;\n	my $title  = shift;\n	my \
$params = shift;\n	print_debug_message( 'rest_run'\
, 'email: ' . $email, 1 );\n	if ( defined($title) \
) {\n		print_debug_message( 'rest_run', 'title: ' \
. $title, 1 );\n	}\n	print_debug_message( 'rest_ru\
n', 'params: ' . Dumper($params), 1 );\n\n	# Get a\
n LWP UserAgent.\n	$ua = &rest_user_agent() unless\
 defined($ua);\n\n	# Clean up parameters\n	my (%tm\
p_params) = %{$params};\n	$tmp_params{'email'} = $\
email;\n	$tmp_params{'title'} = $title;\n	foreach \
my $param_name ( keys(%tmp_params) ) {\n		if ( !de\
fined( $tmp_params{$param_name} ) ) {\n			delete $\
tmp_params{$param_name};\n		}\n	}\n\n	# Submit the\
 job as a POST\n	my $url = $baseUrl . '/run';\n	my\
 $response = $ua->post( $url, \\%tmp_params );\n	p\
rint_debug_message( 'rest_run', 'HTTP status: ' . \
$response->code, 11 );\n	print_debug_message( 'res\
t_run',\n		'request:' .\"\\n\" . $response->reques\
t()->as_string(), 11 );\n	print_debug_message( 're\
st_run',\n		'response: ' . length($response->as_st\
ring()) . \"\\n\" . $response->as_string(), 11 );\\
n\n	# Check for an error.\n	&rest_error($response)\
;\n\n	# The job id is returned\n	my $job_id = $res\
ponse->content();\n	print_debug_message( 'rest_run\
', 'End', 1 );\n	return $job_id;\n}\n\n=head2 rest\
_get_status()\n\nCheck the status of a job.\n\n  m\
y $status = &rest_get_status($job_id);\n\n=cut\n\n\
sub rest_get_status {\n	print_debug_message( 'rest\
_get_status', 'Begin', 1 );\n	my $job_id = shift;\\
n	print_debug_message( 'rest_get_status', 'jobid: \
' . $job_id, 2 );\n	my $status_str = 'UNKNOWN';\n	\
my $url        = $baseUrl . '/status/' . $job_id;\\
n	$status_str = &rest_request($url);\n	print_debug\
_message( 'rest_get_status', 'status_str: ' . $sta\
tus_str, 2 );\n	print_debug_message( 'rest_get_sta\
tus', 'End', 1 );\n	return $status_str;\n}\n\n=hea\
d2 rest_get_result_types()\n\nGet list of result t\
ypes for finished job.\n\n  my (@result_types) = &\
rest_get_result_types($job_id);\n\n=cut\n\nsub res\
t_get_result_types {\n	print_debug_message( 'rest_\
get_result_types', 'Begin', 1 );\n	my $job_id = sh\
ift;\n	print_debug_message( 'rest_get_result_types\
', 'jobid: ' . $job_id, 2 );\n	my (@resultTypes);\\
n	my $url                      = $baseUrl . '/resu\
lttypes/' . $job_id;\n	my $result_type_list_xml_st\
r = &rest_request($url);\n	my $result_type_list_xm\
l     = XMLin($result_type_list_xml_str);\n	(@resu\
ltTypes) = @{ $result_type_list_xml->{'type'} };\n\
	print_debug_message( 'rest_get_result_types',\n		\
scalar(@resultTypes) . ' result types', 2 );\n	pri\
nt_debug_message( 'rest_get_result_types', 'End', \
1 );\n	return (@resultTypes);\n}\n\n=head2 rest_ge\
t_result()\n\nGet result data of a specified type \
for a finished job.\n\n  my $result = rest_get_res\
ult($job_id, $result_type);\n\n=cut\n\nsub rest_ge\
t_result {\n	print_debug_message( 'rest_get_result\
', 'Begin', 1 );\n	my $job_id = shift;\n	my $type \
  = shift;\n	print_debug_message( 'rest_get_result\
', 'jobid: ' . $job_id, 1 );\n	print_debug_message\
( 'rest_get_result', 'type: ' . $type,    1 );\n	m\
y $url    = $baseUrl . '/result/' . $job_id . '/' \
. $type;\n	my $result = &rest_request($url);\n	pri\
nt_debug_message( 'rest_get_result', length($resul\
t) . ' characters',\n		1 );\n	print_debug_message(\
 'rest_get_result', 'End', 1 );\n	return $result;\\
n}\n\n\n=head2 print_debug_message()\n\nPrint debu\
g message at specified debug level.\n\n  &print_de\
bug_message($method_name, $message, $level);\n\n=c\
ut\n\nsub print_debug_message {\n	my $function_nam\
e = shift;\n	my $message       = shift;\n	my $leve\
l         = shift;\n	if ( $level <= $params{'debug\
Level'} ) {\n		print STDERR '[', $function_name, '\
()] ', $message, \"\\n\";\n	}\n}\n\n=head2 print_t\
ool_params()\n\nPrint list of tool parameters.\n\n\
  &print_tool_params();\n\n=cut\n\nsub print_tool_\
params {\n	print_debug_message( 'print_tool_params\
', 'Begin', 1 );\n	my (@param_list) = &rest_get_pa\
rameters();\n	foreach my $param ( sort(@param_list\
) ) {\n		print $param, \"\\n\";\n	}\n	print_debug_\
message( 'print_tool_params', 'End', 1 );\n}\n\n=h\
ead2 print_param_details()\n\nPrint details of a t\
ool parameter.\n\n  &print_param_details($param_na\
me);\n\n=cut\n\nsub print_param_details {\n	print_\
debug_message( 'print_param_details', 'Begin', 1 )\
;\n	my $paramName = shift;\n	print_debug_message( \
'print_param_details', 'paramName: ' . $paramName,\
 2 );\n	my $paramDetail = &rest_get_parameter_deta\
ils($paramName);\n	print $paramDetail->{'name'}, \\
"\\t\", $paramDetail->{'type'}, \"\\n\";\n	print $\
paramDetail->{'description'}, \"\\n\";\n	if(define\
d($paramDetail->{'values'}->{'value'})) {\n		if(re\
f($paramDetail->{'values'}->{'value'}) eq 'ARRAY')\
 {\n			foreach my $value ( @{ $paramDetail->{'valu\
es'}->{'value'} } ) {\n				&print_param_value($val\
ue);\n			}\n		}\n		else {\n				&print_param_value(\
$paramDetail->{'values'}->{'value'});\n		}\n	}\n	p\
rint_debug_message( 'print_param_details', 'End', \
1 );\n}\n\n=head2 print_param_value()\n\nPrint det\
ails of a tool parameter value.\n\n  &print_param_\
details($param_value);\n\nUsed by print_param_deta\
ils() to handle both singluar and array values.\n\\
n=cut\n\nsub print_param_value {\n	my $value = shi\
ft;\n	print $value->{'value'};\n	if ( $value->{'de\
faultValue'} eq 'true' ) {\n		print \"\\t\", 'defa\
ult';\n	}\n	print \"\\n\";\n	print \"\\t\", $value\
->{'label'}, \"\\n\";\n	if ( defined( $value->{'pr\
operties'} ) ) {\n		foreach\n		  my $key ( sort( k\
eys( %{ $value->{'properties'}{'property'} } ) ) )\
\n		{\n			if ( ref( $value->{'properties'}{'proper\
ty'}{$key} ) eq 'HASH'\n				&& defined( $value->{'\
properties'}{'property'}{$key}{'value'} )\n			  )\\
n			{\n				print \"\\t\", $key, \"\\t\",\n				  $v\
alue->{'properties'}{'property'}{$key}{'value'}, \\
"\\n\";\n			}\n			else {\n				print \"\\t\", $valu\
e->{'properties'}{'property'}{'key'},\n				  \"\\t\
\", $value->{'properties'}{'property'}{'value'}, \\
"\\n\";\n				last;\n			}\n		}\n	}\n}\n\n=head2 pri\
nt_job_status()\n\nPrint status of a job.\n\n  &pr\
int_job_status($job_id);\n\n=cut\n\nsub print_job_\
status {\n	print_debug_message( 'print_job_status'\
, 'Begin', 1 );\n	my $jobid = shift;\n	print_debug\
_message( 'print_job_status', 'jobid: ' . $jobid, \
1 );\n	if ( $outputLevel > 0 ) {\n		print STDERR '\
Getting status for job ', $jobid, \"\\n\";\n	}\n	m\
y $result = &rest_get_status($jobid);\n	print \"$r\
esult\\n\";\n	if ( $result eq 'FINISHED' && $outpu\
tLevel > 0 ) {\n		print STDERR \"To get results: $\
scriptName --polljob --jobid \" . $jobid\n		  . \"\
\\n\";\n	}\n	print_debug_message( 'print_job_statu\
s', 'End', 1 );\n}\n\n=head2 print_result_types()\\
n\nPrint available result types for a job.\n\n  &p\
rint_result_types($job_id);\n\n=cut\n\nsub print_r\
esult_types {\n	print_debug_message( 'result_types\
', 'Begin', 1 );\n	my $jobid = shift;\n	print_debu\
g_message( 'result_types', 'jobid: ' . $jobid, 1 )\
;\n	if ( $outputLevel > 0 ) {\n		print STDERR 'Get\
ting result types for job ', $jobid, \"\\n\";\n	}\\
n	my $status = &rest_get_status($jobid);\n	if ( $s\
tatus eq 'PENDING' || $status eq 'RUNNING' ) {\n		\
print STDERR 'Error: Job status is ', $status,\n		\
  '. To get result types the job must be finished.\
', \"\\n\";\n	}\n	else {\n		my (@resultTypes) = &r\
est_get_result_types($jobid);\n		if ( $outputLevel\
 > 0 ) {\n			print STDOUT 'Available result types:\
', \"\\n\";\n		}\n		foreach my $resultType (@resul\
tTypes) {\n			print STDOUT $resultType->{'identifi\
er'}, \"\\n\";\n			if ( defined( $resultType->{'la\
bel'} ) ) {\n				print STDOUT \"\\t\", $resultType\
->{'label'}, \"\\n\";\n			}\n			if ( defined( $res\
ultType->{'description'} ) ) {\n				print STDOUT \\
"\\t\", $resultType->{'description'}, \"\\n\";\n		\
	}\n			if ( defined( $resultType->{'mediaType'} ) \
) {\n				print STDOUT \"\\t\", $resultType->{'medi\
aType'}, \"\\n\";\n			}\n			if ( defined( $resultT\
ype->{'fileSuffix'} ) ) {\n				print STDOUT \"\\t\\
", $resultType->{'fileSuffix'}, \"\\n\";\n			}\n		\
}\n		if ( $status eq 'FINISHED' && $outputLevel > \
0 ) {\n			print STDERR \"\\n\", 'To get results:',\
 \"\\n\",\n			  \"  $scriptName --polljob --jobid \
\" . $params{'jobid'} . \"\\n\",\n			  \"  $script\
Name --polljob --outformat <type> --jobid \"\n			 \
 . $params{'jobid'} . \"\\n\";\n		}\n	}\n	print_de\
bug_message( 'result_types', 'End', 1 );\n}\n\n=he\
ad2 submit_job()\n\nSubmit a job to the service.\n\
\n  &submit_job($seq);\n\n=cut\n\nsub submit_job {\
\n	print_debug_message( 'submit_job', 'Begin', 1 )\
;\n\n	# Set input sequence\n	$tool_params{'sequenc\
e'} = shift;\n\n	# Load parameters\n	&load_params(\
);\n\n	# Submit the job\n	my $jobid = &rest_run( $\
params{'email'}, $params{'title'}, \\%tool_params \
);\n\n	# Simulate sync/async mode\n	if ( defined( \
$params{'async'} ) ) {\n		print STDOUT $jobid, \"\\
\n\";\n		if ( $outputLevel > 0 ) {\n			print STDER\
R\n			  \"To check status: $scriptName --status --\
jobid $jobid\\n\";\n		}\n	}\n	else {\n		if ( $outp\
utLevel > 0 ) {\n			print STDERR \"JobId: $jobid\\\
n\";\n		}\n		sleep 1;\n		&get_results($jobid);\n	}\
\n	print_debug_message( 'submit_job', 'End', 1 );\\
n}\n\n=head2 multi_submit_job()\n\nSubmit multiple\
 jobs assuming input is a collection of fasta form\
atted sequences.\n\n  &multi_submit_job();\n\n=cut\
\n\nsub multi_submit_job {\n	print_debug_message( \
'multi_submit_job', 'Begin', 1 );\n	my $jobIdForFi\
lename = 1;\n	$jobIdForFilename = 0 if ( defined( \
$params{'outfile'} ) );\n	my (@filename_list) = ()\
;\n\n	# Query sequence\n	if ( defined( $ARGV[0] ) \
) {    # Bare option\n		if ( -f $ARGV[0] || $ARGV[\
0] eq '-' ) {    # File\n			push( @filename_list, \
$ARGV[0] );\n		}\n		else {\n			warn 'Warning: Inpu\
t file \"' . $ARGV[0] . '\" does not exist'\n		}\n\
	}\n	if ( $params{'sequence'} ) {                 \
  # Via --sequence\n		if ( -f $params{'sequence'} \
|| $params{'sequence'} eq '-' ) {    # File\n			pu\
sh( @filename_list, $params{'sequence'} );\n		}\n	\
	else {\n			warn 'Warning: Input file \"' . $param\
s{'sequence'} . '\" does not exist'\n		}\n	}\n\n	$\
/ = '>';\n	foreach my $filename (@filename_list) {\
\n		my $INFILE;\n		if($filename eq '-') { # STDIN.\
\n			open( $INFILE, '<-' )\n			  or die 'Error: un\
able to STDIN (' . $! . ')';\n		} else { # File.\n\
			open( $INFILE, '<', $filename )\n			  or die 'E\
rror: unable to open file ' . $filename . ' (' . $\
! . ')';\n		}\n		while (<$INFILE>) {\n			my $seq =\
 $_;\n			$seq =~ s/>$//;\n			if ( $seq =~ m/(\\S+)\
/ ) {\n				print STDERR \"Submitting job for: $1\\\
n\"\n				  if ( $outputLevel > 0 );\n				$seq = '>\
' . $seq;\n				&print_debug_message( 'multi_submit\
_job', $seq, 11 );\n				&submit_job($seq);\n				$p\
arams{'outfile'} = undef if ( $jobIdForFilename ==\
 1 );\n			}\n		}\n		close $INFILE;\n	}\n	print_deb\
ug_message( 'multi_submit_job', 'End', 1 );\n}\n\n\
=head2 list_file_submit_job()\n\nSubmit multiple j\
obs using a file containing a list of entry identi\
fiers as \ninput.\n\n  &list_file_submit_job($list\
_filename)\n\n=cut\n\nsub list_file_submit_job {\n\
	my $filename         = shift;\n	my $jobIdForFilen\
ame = 1;\n	$jobIdForFilename = 0 if ( defined( $pa\
rams{'outfile'} ) );\n\n	# Iterate over identifier\
s, submitting each job\n	my $LISTFILE;\n	if($filen\
ame eq '-') { # STDIN.\n		open( $LISTFILE, '<-' )\\
n		  or die 'Error: unable to STDIN (' . $! . ')';\
\n	} else { # File.\n		open( $LISTFILE, '<', $file\
name )\n		  or die 'Error: unable to open file ' .\
 $filename . ' (' . $! . ')';\n	}\n	while (<$LISTF\
ILE>) {\n		my $line = $_;\n		chomp($line);\n		if (\
 $line ne '' ) {\n			&print_debug_message( 'list_f\
ile_submit_job', 'line: ' . $line, 2 );\n			if ( $\
line =~ m/\\w:\\w/ ) {    # Check this is an ident\
ifier\n				print STDERR \"Submitting job for: $lin\
e\\n\"\n				  if ( $outputLevel > 0 );\n				&submi\
t_job($line);\n			}\n			else {\n				print STDERR\n\
\"Warning: line \\\"$line\\\" is not recognised as\
 an identifier\\n\";\n			}\n		}\n		$params{'outfil\
e'} = undef if ( $jobIdForFilename == 1 );\n	}\n	c\
lose $LISTFILE;\n}\n\n=head2 load_data()\n\nLoad s\
equence data from file or option specified on the \
command-line.\n\n  &load_data();\n\n=cut\n\nsub lo\
ad_data {\n	print_debug_message( 'load_data', 'Beg\
in', 1 );\n	my $retSeq;\n\n	# Query sequence\n	if \
( defined( $ARGV[0] ) ) {    # Bare option\n		if (\
 -f $ARGV[0] || $ARGV[0] eq '-' ) {    # File\n			\
$retSeq = &read_file( $ARGV[0] );\n		}\n		else {  \
                                   # DB:ID or sequ\
ence\n			$retSeq = $ARGV[0];\n		}\n	}\n	if ( $para\
ms{'sequence'} ) {                   # Via --seque\
nce\n		if ( -f $params{'sequence'} || $params{'seq\
uence'} eq '-' ) {    # File\n			$retSeq = &read_f\
ile( $params{'sequence'} );\n		}\n		else {    # DB\
:ID or sequence\n			$retSeq = $params{'sequence'};\
\n		}\n	}\n	print_debug_message( 'load_data', 'End\
', 1 );\n	return $retSeq;\n}\n\n=head2 load_params\
()\n\nLoad job parameters from command-line option\
s.\n\n  &load_params();\n\n=cut\n\nsub load_params\
 {\n	print_debug_message( 'load_params', 'Begin', \
1 );\n\n	# Database(s) to search\n	my (@dbList) = \
split /[ ,]/, $params{'database'};\n	$tool_params{\
'database'} = \\@dbList;\n\n	# Match/missmatch\n	i\
f ( $params{'match'} && $params{'missmatch'} ) {\n\
		$tool_params{'match_scores'} =\n		  $params{'mat\
ch'} . ',' . $params{'missmatch'};\n	}\n	\n	# Comp\
atability options, old command-line\n	if(!$tool_pa\
rams{'alignments'} && $params{'numal'}) {\n		$tool\
_params{'alignments'} = $params{'numal'};\n	}\n	if\
(!$tool_params{'gapopen'} && $params{'opengap'}) {\
\n		$tool_params{'gapopen'} = $params{'opengap'};\\
n	}\n	if(!$tool_params{'gapext'} && $params{'exten\
dgap'}) {\n		$tool_params{'gapext'} = $params{'ext\
endgap'};\n	}\n\n	print_debug_message( 'load_param\
s', 'End', 1 );\n}\n\n=head2 client_poll()\n\nClie\
nt-side job polling.\n\n  &client_poll($job_id);\n\
\n=cut\n\nsub client_poll {\n	print_debug_message(\
 'client_poll', 'Begin', 1 );\n	my $jobid  = shift\
;\n	my $status = 'PENDING';\n\n	my $errorCount = 0\
;\n	while ($status eq 'RUNNING'\n		|| $status eq '\
PENDING'\n		|| ( $status eq 'ERROR' && $errorCount\
 < 2 ) )\n	{\n		$status = rest_get_status($jobid);\
\n		print STDERR \"$status\\n\" if ( $outputLevel \
> 0 );\n		if ( $status eq 'ERROR' ) {\n			$errorCo\
unt++;\n		}\n		elsif ( $errorCount > 0 ) {\n			$er\
rorCount--;\n		}\n		if (   $status eq 'RUNNING'\n	\
		|| $status eq 'PENDING'\n			|| $status eq 'ERROR\
' )\n		{\n\n			# Wait before polling again.\n			sl\
eep $checkInterval;\n		}\n	}\n	print_debug_message\
( 'client_poll', 'End', 1 );\n	return $status;\n}\\
n\n=head2 get_results()\n\nGet the results for a j\
ob identifier.\n\n  &get_results($job_id);\n\n=cut\
\n\nsub get_results {\n	print_debug_message( 'get_\
results', 'Begin', 1 );\n	my $jobid = shift;\n	pri\
nt_debug_message( 'get_results', 'jobid: ' . $jobi\
d, 1 );\n\n	# Verbose\n	if ( $outputLevel > 1 ) {\\
n		print 'Getting results for job ', $jobid, \"\\n\
\";\n	}\n\n	# Check status, and wait if not finish\
ed\n	client_poll($jobid);\n\n	# Use JobId if outpu\
t file name is not defined\n	unless ( defined( $pa\
rams{'outfile'} ) ) {\n		$params{'outfile'} = $job\
id;\n	}\n\n	# Get list of data types\n	my (@result\
Types) = rest_get_result_types($jobid);\n\n	# Get \
the data and write it to a file\n	if ( defined( $p\
arams{'outformat'} ) ) {    # Specified data type\\
n		my $selResultType;\n		foreach my $resultType (@\
resultTypes) {\n			if ( $resultType->{'identifier'\
} eq $params{'outformat'} ) {\n				$selResultType \
= $resultType;\n			}\n		}\n		if ( defined($selResu\
ltType) ) {\n			my $result =\n			  rest_get_result\
( $jobid, $selResultType->{'identifier'} );\n			if\
 ( $params{'outfile'} eq '-' ) {\n				write_file( \
$params{'outfile'}, $result );\n			}\n			else {\n	\
			write_file(\n					$params{'outfile'} . '.'\n			\
		  . $selResultType->{'identifier'} . '.'\n					 \
 . $selResultType->{'fileSuffix'},\n					$result\n\
				);\n			}\n		}\n		else {\n			die 'Error: unknow\
n result format \"' . $params{'outformat'} . '\"';\
\n		}\n	}\n	else {    # Data types available\n		  \
    # Write a file for each output type\n		for my \
$resultType (@resultTypes) {\n			if ( $outputLevel\
 > 1 ) {\n				print STDERR 'Getting ', $resultType\
->{'identifier'}, \"\\n\";\n			}\n			my $result = \
rest_get_result( $jobid, $resultType->{'identifier\
'} );\n			if ( $params{'outfile'} eq '-' ) {\n				\
write_file( $params{'outfile'}, $result );\n			}\n\
			else {\n				write_file(\n					$params{'outfile'\
} . '.'\n					  . $resultType->{'identifier'} . '.\
'\n					  . $resultType->{'fileSuffix'},\n					$re\
sult\n				);\n			}\n		}\n	}\n	print_debug_message(\
 'get_results', 'End', 1 );\n}\n\n=head2 read_file\
()\n\nRead a file into a scalar. The special filen\
ame '-' can be used to read from \nstandard input \
(STDIN).\n\n  my $data = &read_file($filename);\n\\
n=cut\n\nsub read_file {\n	print_debug_message( 'r\
ead_file', 'Begin', 1 );\n	my $filename = shift;\n\
	print_debug_message( 'read_file', 'filename: ' . \
$filename, 2 );\n	my ( $content, $buffer );\n	if (\
 $filename eq '-' ) {\n		while ( sysread( STDIN, $\
buffer, 1024 ) ) {\n			$content .= $buffer;\n		}\n\
	}\n	else {    # File\n		open( my $FILE, '<', $fil\
ename )\n		  or die \"Error: unable to open input \
file $filename ($!)\";\n		while ( sysread( $FILE, \
$buffer, 1024 ) ) {\n			$content .= $buffer;\n		}\\
n		close($FILE);\n	}\n	print_debug_message( 'read_\
file', 'End', 1 );\n	return $content;\n}\n\n=head2\
 write_file()\n\nWrite data to a file. The special\
 filename '-' can be used to write to \nstandard o\
utput (STDOUT).\n\n  &write_file($filename, $data)\
;\n\n=cut\n\nsub write_file {\n	print_debug_messag\
e( 'write_file', 'Begin', 1 );\n	my ( $filename, $\
data ) = @_;\n	print_debug_message( 'write_file', \
'filename: ' . $filename, 2 );\n	if ( $outputLevel\
 > 0 ) {\n		print STDERR 'Creating result file: ' \
. $filename . \"\\n\";\n	}\n	if ( $filename eq '-'\
 ) {\n		print STDOUT $data;\n	}\n	else {\n		open( \
my $FILE, '>', $filename )\n		  or die \"Error: un\
able to open output file $filename ($!)\";\n		sysw\
rite( $FILE, $data );\n		close($FILE);\n	}\n	print\
_debug_message( 'write_file', 'End', 1 );\n}\n\n=h\
ead2 usage()\n\nPrint program usage message.\n\n  \
&usage();\n\n=cut\n\nsub usage {\n	print STDERR <<\
EOF\nNCBI BLAST\n==========\n   \nRapid sequence d\
atabase search programs utilizing the BLAST algori\
thm\n    \n[Required]\n\n  -p, --program      : st\
r  : BLAST program to use, see --paramDetail progr\
am\n  -D, --database     : str  : database(s) to s\
earch, space separated. See\n                     \
         --paramDetail database\n      --stype    \
    : str  : query sequence type, see --paramDetai\
l stype\n  seqFile            : file : query seque\
nce (\"-\" for STDIN, \\@filename for\n           \
                   identifier list file)\n\n[Optio\
nal]\n\n  -m, --matrix       : str  : scoring matr\
ix, see --paramDetail matrix\n  -e, --exp         \
 : real : 0<E<= 1000. Statistical significance thr\
eshold \n                              for reporti\
ng database sequence matches.\n  -f, --filter     \
  :      : filter the query sequence for low compl\
exity \n                              regions, see\
 --paramDetail filter\n  -A, --align        : int \
 : pairwise alignment format, see --paramDetail al\
ign\n  -s, --scores       : int  : number of score\
s to be reported\n  -n, --alignments   : int  : nu\
mber of alignments to report\n  -u, --match       \
 : int  : Match score (BLASTN only)\n  -v, --misma\
tch     : int  : Mismatch score (BLASTN only)\n  -\
o, --gapopen      : int  : Gap open penalty\n  -x,\
 --gapext       : int  : Gap extension penalty\n  \
-d, --dropoff      : int  : Drop-off\n  -g, --gapa\
lign     :      : Optimise gapped alignments\n    \
  --seqrange     : str  : region within input to u\
se as query\n      --multifasta   :      : treat i\
nput as a set of fasta formatted sequences\n\n[Gen\
eral]\n\n  -h, --help         :      : prints this\
 help text\n      --async        :      : forces t\
o make an asynchronous query\n      --email       \
 : str  : e-mail address\n      --title        : s\
tr  : title for job\n      --status       :      :\
 get job status\n      --resultTypes  :      : get\
 available result types for job\n      --polljob  \
    :      : poll for the status of a job\n      -\
-jobid        : str  : jobid that was returned whe\
n an asynchronous job \n                          \
    was submitted.\n      --outfile      : str  : \
file name for results (default is jobid;\n        \
                      \"-\" for STDOUT)\n      --o\
utformat    : str  : result format to retrieve\n  \
    --params       :      : list input parameters\\
n      --paramDetail  : str  : display details for\
 input parameter\n      --quiet        :      : de\
crease output\n      --verbose      :      : incre\
ase output\n   \nSynchronous job:\n\n  The results\
/errors are returned as soon as the job is finishe\
d.\n  Usage: $scriptName --email <your\\@email> [o\
ptions...] seqFile\n  Returns: results as an attac\
hment\n\nAsynchronous job:\n\n  Use this if you wa\
nt to retrieve the results at a later time. The re\
sults \n  are stored for up to 24 hours. 	\n  Usag\
e: $scriptName --async --email <your\\@email> [opt\
ions...] seqFile\n  Returns: jobid\n\n  Use the jo\
bid to query for the status of the job. If the job\
 is finished, \n  it also returns the results/erro\
rs.\n  Usage: $scriptName --polljob --jobid <jobId\
> [--outfile string]\n  Returns: string indicating\
 the status of the job and if applicable, results \
\n  as an attachment.\n\nFurther information:\n\n \
 http://www.ebi.ac.uk/Tools/webservices/services/s\
ss/ncbi_blast_rest\n  http://www.ebi.ac.uk/Tools/w\
ebservices/tutorials/perl\n\nSupport/Feedback:\n\n\
  http://www.ebi.ac.uk/support/\nEOF\n}\n\n=head1 \
FEEDBACK/SUPPORT\n\nPlease contact us at L<http://\
www.ebi.ac.uk/support/> if you have any \nfeedback\
, suggestions or issues with the service or this c\
lient.\n\n=cut\n","\n=head1 NAME\n\nwublast_lwp.pl\
\n\n=head1 DESCRIPTION\n\nWU-BLAST (REST) web serv\
ice Perl client using L<LWP>.\n\nTested with:\n\n=\
over\n\n=item *\nL<LWP> 5.79, L<XML::Simple> 2.12 \
and Perl 5.8.3\n\n=item *\nL<LWP> 5.808, L<XML::Si\
mple> 2.18 and Perl 5.8.8 (Ubuntu 8.04 LTS)\n\n=it\
em *\nL<LWP> 5.834, L<XML::Simple> 2.18 and Perl 5\
.10.1 (Ubuntu 10.04 LTS)\n\n=item *\nL<LWP> 6.03, \
L<XML::Simple> 2.18 and Perl 5.14.2 (Ubuntu 12.04 \
LTS)\n\n=back\n\nFor further information see:\n\n=\
over\n\n=item *\nL<http://www.ebi.ac.uk/Tools/webs\
ervices/services/sss/wu_blast_rest>\n\n=item *\nL<\
http://www.ebi.ac.uk/Tools/webservices/tutorials/p\
erl>\n\n=back\n\n=head1 LICENSE\n\nCopyright 2012-\
2013 EMBL - European Bioinformatics Institute\n\nL\
icensed under the Apache License, Version 2.0 (the\
 \"License\");\nyou may not use this file except i\
n compliance with the License.\nYou may obtain a c\
opy of the License at\n\n    http://www.apache.org\
/licenses/LICENSE-2.0\n\nUnless required by applic\
able law or agreed to in writing, software\ndistri\
buted under the License is distributed on an \"AS \
IS\" BASIS,\nWITHOUT WARRANTIES OR CONDITIONS OF A\
NY KIND, either express or implied.\nSee the Licen\
se for the specific language governing permissions\
 and\nlimitations under the License.\n\n=head1 VER\
SION\n\n$Id: wublast_lwp.pl 2560 2013-03-20 12:56:\
31Z hpm $\n\n=cut\n\nuse strict;\nuse warnings;\n\\
nuse English;\nuse LWP;\nuse XML::Simple;\nuse Get\
opt::Long qw(:config no_ignore_case bundling);\nus\
e File::Basename;\nuse Data::Dumper;\n\nmy $baseUr\
l = 'http://www.ebi.ac.uk/Tools/services/rest/wubl\
ast';\n\nmy $checkInterval = 3;\n\nmy $outputLevel\
 = 1;\n\nmy $numOpts = scalar(@ARGV);\nmy %params \
= ( 'debugLevel' => 0 );\n\nmy %tool_params = ();\\
nGetOptions(\n\n	# Tool specific options\n	'progra\
m|p=s'     => \\$tool_params{'program'},      # BL\
AST program\n	'database|D=s'    => \\$params{'data\
base'},     # Search database\n	'matrix|m=s'      \
=> \\$tool_params{'matrix'},       # Scoring matri\
x\n	'exp|E=f'         => \\$tool_params{'exp'},   \
       # E-value threshold\n	'viewfilter|e'    => \
\\$tool_params{'viewfilter'},   # Display filtered\
 sequence\n	'filter|f=s'      => \\$tool_params{'f\
ilter'},       # Low complexity filter name\n	'ali\
gnments|n=i'  => \\$tool_params{'alignments'},   #\
 Number of alignments\n	'scores|s=i'      => \\$to\
ol_params{'scores'},       # Number of scores\n	's\
ensitivity|S=s' => \\$tool_params{'sensitivity'}, \
 # Search sensitivity\n	'sort|t=s'        => \\$to\
ol_params{'sort'},         # Sort hits by...\n	'st\
ats|T=s'       => \\$tool_params{'stats'},        \
# Scoring statistic to use\n	'strand|d=s'      => \
\\$tool_params{'strand'},       # Strand to use\n	\
'topcombon|c=i'   => \\$tool_params{'topcombon'}, \
   # Consistent sets of HSPs\n	'align|A=i'       =\
> \\$tool_params{'align'},   # Pairwise alignment \
format\n	'stype=s' => \\$tool_params{'stype'},    \
# Sequence type 'protein' or 'dna'\n	'sequence=s' \
=> \\$params{'sequence'},         # Query sequence\
 file or DB:ID\n	'multifasta' => \\$params{'multif\
asta'},       # Multiple fasta input\n\n	# Compata\
bility options, old command-line.\n	'echofilter|e'\
    => \\$params{'echofilter'},   # Display filter\
ed sequence\n	'b=i'  => \\$params{'numal'},       \
 # Number of alignments\n	'appxml=s'        => \\$\
params{'appxml'},       # Application XML\n\n	# Ge\
neric options\n	'email=s'       => \\$params{'emai\
l'},          # User e-mail address\n	'title=s'   \
    => \\$params{'title'},          # Job title\n	\
'outfile=s'     => \\$params{'outfile'},        # \
Output file name\n	'outformat=s'   => \\$params{'o\
utformat'},      # Output file type\n	'jobid=s'   \
    => \\$params{'jobid'},          # JobId\n	'hel\
p|h'        => \\$params{'help'},           # Usag\
e help\n	'async'         => \\$params{'async'},   \
       # Asynchronous submission\n	'polljob'      \
 => \\$params{'polljob'},        # Get results\n	'\
resultTypes'   => \\$params{'resultTypes'},    # G\
et result types\n	'status'        => \\$params{'st\
atus'},         # Get status\n	'params'        => \
\\$params{'params'},         # List input paramete\
rs\n	'paramDetail=s' => \\$params{'paramDetail'}, \
   # Get details for parameter\n	'quiet'         =\
> \\$params{'quiet'},          # Decrease output l\
evel\n	'verbose'       => \\$params{'verbose'},   \
     # Increase output level\n	'debugLevel=i'  => \
\\$params{'debugLevel'},     # Debug output level\\
n	'baseUrl=s'     => \\$baseUrl,                  \
# Base URL for service.\n);\nif ( $params{'verbose\
'} ) { $outputLevel++ }\nif ( $params{'quiet'} )  \
{ $outputLevel-- }\n\n&print_debug_message( 'MAIN'\
, 'LWP::VERSION: ' . $LWP::VERSION,\n	1 );\n\n&pri\
nt_debug_message( 'MAIN', \"params:\\n\" . Dumper(\
 \\%params ),           11 );\n&print_debug_messag\
e( 'MAIN', \"tool_params:\\n\" . Dumper( \\%tool_p\
arams ), 11 );\n\nmy $ua;\n\nmy $scriptName = base\
name( $0, () );\n\nif ( $params{'help'} || $numOpt\
s == 0 ) {\n	&usage();\n	exit(0);\n}\n\n&print_deb\
ug_message( 'MAIN', 'baseUrl: ' . $baseUrl, 1 );\n\
\nif (\n	!(\n		   $params{'polljob'}\n		|| $params\
{'resultTypes'}\n		|| $params{'status'}\n		|| $par\
ams{'params'}\n		|| $params{'paramDetail'}\n	)\n	&\
& !( defined( $ARGV[0] ) || defined( $params{'sequ\
ence'} ) )\n  )\n{\n\n	# Bad argument combination,\
 so print error message and usage\n	print STDERR '\
Error: bad option combination', \"\\n\";\n	&usage(\
);\n	exit(1);\n}\n\nelsif ( $params{'params'} ) {\\
n	&print_tool_params();\n}\n\nelsif ( $params{'par\
amDetail'} ) {\n	&print_param_details( $params{'pa\
ramDetail'} );\n}\n\nelsif ( $params{'status'} && \
defined( $params{'jobid'} ) ) {\n	&print_job_statu\
s( $params{'jobid'} );\n}\n\nelsif ( $params{'resu\
ltTypes'} && defined( $params{'jobid'} ) ) {\n	&pr\
int_result_types( $params{'jobid'} );\n}\n\nelsif \
( $params{'polljob'} && defined( $params{'jobid'} \
) ) {\n	&get_results( $params{'jobid'} );\n}\n\nel\
se {\n\n	# Multiple input sequence mode, assume fa\
sta format.\n	if ( $params{'multifasta'} ) {\n		&m\
ulti_submit_job();\n	}\n\n	# Entry identifier list\
 file.\n	elsif (( defined( $params{'sequence'} ) &\
& $params{'sequence'} =~ m/^\\@/ )\n		|| ( defined\
( $ARGV[0] ) && $ARGV[0] =~ m/^\\@/ ) )\n	{\n		my \
$list_filename = $params{'sequence'} || $ARGV[0];\\
n		$list_filename =~ s/^\\@//;\n		&list_file_submi\
t_job($list_filename);\n	}\n\n	# Default: single s\
equence/identifier.\n	else {\n\n		# Load the seque\
nce data and submit.\n		&submit_job( &load_data() \
);\n	}\n}\n\n=head1 FUNCTIONS\n\n=cut\n\n\n=head2 \
rest_user_agent()\n\nGet a LWP UserAgent to use to\
 perform REST requests.\n\n  my $ua = &rest_user_a\
gent();\n\n=cut\n\nsub rest_user_agent() {\n	print\
_debug_message( 'rest_user_agent', 'Begin', 21 );\\
n	# Create an LWP UserAgent for making HTTP calls.\
\n	my $ua = LWP::UserAgent->new();\n	# Set 'User-A\
gent' HTTP header to identifiy the client.\n	'$Rev\
ision: 2560 $' =~ m/(\\d+)/;\n	$ua->agent(\"EBI-Sa\
mple-Client/$1 ($scriptName; $OSNAME) \" . $ua->ag\
ent());\n	# Configure HTTP proxy support from envi\
ronment.\n	$ua->env_proxy;\n	print_debug_message( \
'rest_user_agent', 'End', 21 );\n	return $ua;\n}\n\
\n=head2 rest_error()\n\nCheck a REST response for\
 an error condition. An error is mapped to a die.\\
n\n  &rest_error($response, $content_data);\n\n=cu\
t\n\nsub rest_error() {\n	print_debug_message( 're\
st_error', 'Begin', 21 );\n	my $response = shift;\\
n	my $contentdata;\n	if(scalar(@_) > 0) {\n		$cont\
entdata = shift;\n	}\n	if(!defined($contentdata) |\
| $contentdata eq '') {\n		$contentdata = $respons\
e->content();\n	}\n	# Check for HTTP error codes\n\
	if ( $response->is_error ) {\n		my $error_message\
 = '';\n		# HTML response.\n		if(	$contentdata =~ \
m/<h1>([^<]+)<\\/h1>/ ) {\n			$error_message = $1;\
\n		}\n		#  XML response.\n		elsif($contentdata =~\
 m/<description>([^<]+)<\\/description>/) {\n			$e\
rror_message = $1;\n		}\n		die 'http status: ' . $\
response->code . ' ' . $response->message . '  ' .\
 $error_message;\n	}\n	print_debug_message( 'rest_\
error', 'End', 21 );\n}\n\n=head2 rest_request()\n\
\nPerform a REST request (HTTP GET).\n\n  my $resp\
onse_str = &rest_request($url);\n\n=cut\n\nsub res\
t_request {\n	print_debug_message( 'rest_request',\
 'Begin', 11 );\n	my $requestUrl = shift;\n	print_\
debug_message( 'rest_request', 'URL: ' . $requestU\
rl, 11 );\n\n	# Get an LWP UserAgent.\n	$ua = &res\
t_user_agent() unless defined($ua);\n	# Available \
HTTP compression methods.\n	my $can_accept;\n	eval\
 {\n	    $can_accept = HTTP::Message::decodable();\
\n	};\n	$can_accept = '' unless defined($can_accep\
t);\n	# Perform the request\n	my $response = $ua->\
get($requestUrl,\n		'Accept-Encoding' => $can_acce\
pt, # HTTP compression.\n	);\n	print_debug_message\
( 'rest_request', 'HTTP status: ' . $response->cod\
e,\n		11 );\n	print_debug_message( 'rest_request',\
\n		'response length: ' . length($response->conten\
t()), 11 );\n	print_debug_message( 'rest_request',\
\n		'request:' .\"\\n\" . $response->request()->as\
_string(), 32 );\n	print_debug_message( 'rest_requ\
est',\n		'response: ' . \"\\n\" . $response->as_st\
ring(), 32 );\n	# Unpack possibly compressed respo\
nse.\n	my $retVal;\n	if ( defined($can_accept) && \
$can_accept ne '') {\n	    $retVal = $response->de\
coded_content();\n	}\n	# If unable to decode use o\
rginal content.\n	$retVal = $response->content() u\
nless defined($retVal);\n	# Check for an error.\n	\
&rest_error($response, $retVal);\n	print_debug_mes\
sage( 'rest_request', 'retVal: ' . $retVal, 12 );\\
n	print_debug_message( 'rest_request', 'End', 11 )\
;\n\n	# Return the response data\n	return $retVal;\
\n}\n\n=head2 rest_get_parameters()\n\nGet list of\
 tool parameter names.\n\n  my (@param_list) = &re\
st_get_parameters();\n\n=cut\n\nsub rest_get_param\
eters {\n	print_debug_message( 'rest_get_parameter\
s', 'Begin', 1 );\n	my $url                = $base\
Url . '/parameters/';\n	my $param_list_xml_str = r\
est_request($url);\n	my $param_list_xml     = XMLi\
n($param_list_xml_str);\n	my (@param_list)       =\
 @{ $param_list_xml->{'id'} };\n	print_debug_messa\
ge( 'rest_get_parameters', 'End', 1 );\n	return (@\
param_list);\n}\n\n=head2 rest_get_parameter_detai\
ls()\n\nGet details of a tool parameter.\n\n  my $\
paramDetail = &rest_get_parameter_details($param_n\
ame);\n\n=cut\n\nsub rest_get_parameter_details {\\
n	print_debug_message( 'rest_get_parameter_details\
', 'Begin', 1 );\n	my $parameterId = shift;\n	prin\
t_debug_message( 'rest_get_parameter_details',\n		\
'parameterId: ' . $parameterId, 1 );\n	my $url    \
              = $baseUrl . '/parameterdetails/' . \
$parameterId;\n	my $param_detail_xml_str = rest_re\
quest($url);\n	my $param_detail_xml     = XMLin($p\
aram_detail_xml_str);\n	print_debug_message( 'rest\
_get_parameter_details', 'End', 1 );\n	return ($pa\
ram_detail_xml);\n}\n\n=head2 rest_run()\n\nSubmit\
 a job.\n\n  my $job_id = &rest_run($email, $title\
, \\%params );\n\n=cut\n\nsub rest_run {\n	print_d\
ebug_message( 'rest_run', 'Begin', 1 );\n	my $emai\
l  = shift;\n	my $title  = shift;\n	my $params = s\
hift;\n	print_debug_message( 'rest_run', 'email: '\
 . $email, 1 );\n	if ( defined($title) ) {\n		prin\
t_debug_message( 'rest_run', 'title: ' . $title, 1\
 );\n	}\n	print_debug_message( 'rest_run', 'params\
: ' . Dumper($params), 1 );\n\n	# Get an LWP UserA\
gent.\n	$ua = &rest_user_agent() unless defined($u\
a);\n\n	# Clean up parameters\n	my (%tmp_params) =\
 %{$params};\n	$tmp_params{'email'} = $email;\n	$t\
mp_params{'title'} = $title;\n	foreach my $param_n\
ame ( keys(%tmp_params) ) {\n		if ( !defined( $tmp\
_params{$param_name} ) ) {\n			delete $tmp_params{\
$param_name};\n		}\n	}\n\n	# Submit the job as a P\
OST\n	my $url = $baseUrl . '/run';\n	my $response \
= $ua->post( $url, \\%tmp_params );\n	print_debug_\
message( 'rest_run', 'HTTP status: ' . $response->\
code, 11 );\n	print_debug_message( 'rest_run',\n		\
'request:' .\"\\n\" . $response->request()->as_str\
ing(), 11 );\n	print_debug_message( 'rest_run',\n	\
	'response: ' . length($response->as_string()) . \\
"\\n\" . $response->as_string(), 11 );\n\n	# Check\
 for an error.\n	&rest_error($response);\n\n	# The\
 job id is returned\n	my $job_id = $response->cont\
ent();\n	print_debug_message( 'rest_run', 'End', 1\
 );\n	return $job_id;\n}\n\n=head2 rest_get_status\
()\n\nCheck the status of a job.\n\n  my $status =\
 &rest_get_status($job_id);\n\n=cut\n\nsub rest_ge\
t_status {\n	print_debug_message( 'rest_get_status\
', 'Begin', 1 );\n	my $job_id = shift;\n	print_deb\
ug_message( 'rest_get_status', 'jobid: ' . $job_id\
, 2 );\n	my $status_str = 'UNKNOWN';\n	my $url    \
    = $baseUrl . '/status/' . $job_id;\n	$status_s\
tr = &rest_request($url);\n	print_debug_message( '\
rest_get_status', 'status_str: ' . $status_str, 2 \
);\n	print_debug_message( 'rest_get_status', 'End'\
, 1 );\n	return $status_str;\n}\n\n=head2 rest_get\
_result_types()\n\nGet list of result types for fi\
nished job.\n\n  my (@result_types) = &rest_get_re\
sult_types($job_id);\n\n=cut\n\nsub rest_get_resul\
t_types {\n	print_debug_message( 'rest_get_result_\
types', 'Begin', 1 );\n	my $job_id = shift;\n	prin\
t_debug_message( 'rest_get_result_types', 'jobid: \
' . $job_id, 2 );\n	my (@resultTypes);\n	my $url  \
                    = $baseUrl . '/resulttypes/' .\
 $job_id;\n	my $result_type_list_xml_str = &rest_r\
equest($url);\n	my $result_type_list_xml     = XML\
in($result_type_list_xml_str);\n	(@resultTypes) = \
@{ $result_type_list_xml->{'type'} };\n	print_debu\
g_message( 'rest_get_result_types',\n		scalar(@res\
ultTypes) . ' result types', 2 );\n	print_debug_me\
ssage( 'rest_get_result_types', 'End', 1 );\n	retu\
rn (@resultTypes);\n}\n\n=head2 rest_get_result()\\
n\nGet result data of a specified type for a finis\
hed job.\n\n  my $result = rest_get_result($job_id\
, $result_type);\n\n=cut\n\nsub rest_get_result {\\
n	print_debug_message( 'rest_get_result', 'Begin',\
 1 );\n	my $job_id = shift;\n	my $type   = shift;\\
n	print_debug_message( 'rest_get_result', 'jobid: \
' . $job_id, 1 );\n	print_debug_message( 'rest_get\
_result', 'type: ' . $type,    1 );\n	my $url    =\
 $baseUrl . '/result/' . $job_id . '/' . $type;\n	\
my $result = &rest_request($url);\n	print_debug_me\
ssage( 'rest_get_result', length($result) . ' char\
acters',\n		1 );\n	print_debug_message( 'rest_get_\
result', 'End', 1 );\n	return $result;\n}\n\n\n=he\
ad2 print_debug_message()\n\nPrint debug message a\
t specified debug level.\n\n  &print_debug_message\
($method_name, $message, $level);\n\n=cut\n\nsub p\
rint_debug_message {\n	my $function_name = shift;\\
n	my $message       = shift;\n	my $level         =\
 shift;\n	if ( $level <= $params{'debugLevel'} ) {\
\n		print STDERR '[', $function_name, '()] ', $mes\
sage, \"\\n\";\n	}\n}\n\n=head2 print_tool_params(\
)\n\nPrint list of tool parameters.\n\n  &print_to\
ol_params();\n\n=cut\n\nsub print_tool_params {\n	\
print_debug_message( 'print_tool_params', 'Begin',\
 1 );\n	my (@param_list) = &rest_get_parameters();\
\n	foreach my $param ( sort(@param_list) ) {\n		pr\
int $param, \"\\n\";\n	}\n	print_debug_message( 'p\
rint_tool_params', 'End', 1 );\n}\n\n=head2 print_\
param_details()\n\nPrint details of a tool paramet\
er.\n\n  &print_param_details($param_name);\n\n=cu\
t\n\nsub print_param_details {\n	print_debug_messa\
ge( 'print_param_details', 'Begin', 1 );\n	my $par\
amName = shift;\n	print_debug_message( 'print_para\
m_details', 'paramName: ' . $paramName, 2 );\n	my \
$paramDetail = &rest_get_parameter_details($paramN\
ame);\n	print $paramDetail->{'name'}, \"\\t\", $pa\
ramDetail->{'type'}, \"\\n\";\n	print $paramDetail\
->{'description'}, \"\\n\";\n	if(defined($paramDet\
ail->{'values'}->{'value'})) {\n		if(ref($paramDet\
ail->{'values'}->{'value'}) eq 'ARRAY') {\n			fore\
ach my $value ( @{ $paramDetail->{'values'}->{'val\
ue'} } ) {\n				&print_param_value($value);\n			}\\
n		}\n		else {\n				&print_param_value($paramDetai\
l->{'values'}->{'value'});\n		}\n	}\n	print_debug_\
message( 'print_param_details', 'End', 1 );\n}\n\n\
=head2 print_param_value()\n\nPrint details of a t\
ool parameter value.\n\n  &print_param_details($pa\
ram_value);\n\nUsed by print_param_details() to ha\
ndle both singluar and array values.\n\n=cut\n\nsu\
b print_param_value {\n	my $value = shift;\n	print\
 $value->{'value'};\n	if ( $value->{'defaultValue'\
} eq 'true' ) {\n		print \"\\t\", 'default';\n	}\n\
	print \"\\n\";\n	print \"\\t\", $value->{'label'}\
, \"\\n\";\n	if ( defined( $value->{'properties'} \
) ) {\n		foreach\n		  my $key ( sort( keys( %{ $va\
lue->{'properties'}{'property'} } ) ) )\n		{\n			i\
f ( ref( $value->{'properties'}{'property'}{$key} \
) eq 'HASH'\n				&& defined( $value->{'properties'\
}{'property'}{$key}{'value'} )\n			  )\n			{\n				\
print \"\\t\", $key, \"\\t\",\n				  $value->{'pro\
perties'}{'property'}{$key}{'value'}, \"\\n\";\n		\
	}\n			else {\n				print \"\\t\", $value->{'proper\
ties'}{'property'}{'key'},\n				  \"\\t\", $value-\
>{'properties'}{'property'}{'value'}, \"\\n\";\n		\
		last;\n			}\n		}\n	}\n}\n\n=head2 print_job_stat\
us()\n\nPrint status of a job.\n\n  &print_job_sta\
tus($job_id);\n\n=cut\n\nsub print_job_status {\n	\
print_debug_message( 'print_job_status', 'Begin', \
1 );\n	my $jobid = shift;\n	print_debug_message( '\
print_job_status', 'jobid: ' . $jobid, 1 );\n	if (\
 $outputLevel > 0 ) {\n		print STDERR 'Getting sta\
tus for job ', $jobid, \"\\n\";\n	}\n	my $result =\
 &rest_get_status($jobid);\n	print \"$result\\n\";\
\n	if ( $result eq 'FINISHED' && $outputLevel > 0 \
) {\n		print STDERR \"To get results: $scriptName \
--polljob --jobid \" . $jobid\n		  . \"\\n\";\n	}\\
n	print_debug_message( 'print_job_status', 'End', \
1 );\n}\n\n=head2 print_result_types()\n\nPrint av\
ailable result types for a job.\n\n  &print_result\
_types($job_id);\n\n=cut\n\nsub print_result_types\
 {\n	print_debug_message( 'result_types', 'Begin',\
 1 );\n	my $jobid = shift;\n	print_debug_message( \
'result_types', 'jobid: ' . $jobid, 1 );\n	if ( $o\
utputLevel > 0 ) {\n		print STDERR 'Getting result\
 types for job ', $jobid, \"\\n\";\n	}\n	my $statu\
s = &rest_get_status($jobid);\n	if ( $status eq 'P\
ENDING' || $status eq 'RUNNING' ) {\n		print STDER\
R 'Error: Job status is ', $status,\n		  '. To get\
 result types the job must be finished.', \"\\n\";\
\n	}\n	else {\n		my (@resultTypes) = &rest_get_res\
ult_types($jobid);\n		if ( $outputLevel > 0 ) {\n	\
		print STDOUT 'Available result types:', \"\\n\";\
\n		}\n		foreach my $resultType (@resultTypes) {\n\
			print STDOUT $resultType->{'identifier'}, \"\\n\
\";\n			if ( defined( $resultType->{'label'} ) ) {\
\n				print STDOUT \"\\t\", $resultType->{'label'}\
, \"\\n\";\n			}\n			if ( defined( $resultType->{'\
description'} ) ) {\n				print STDOUT \"\\t\", $re\
sultType->{'description'}, \"\\n\";\n			}\n			if (\
 defined( $resultType->{'mediaType'} ) ) {\n				pr\
int STDOUT \"\\t\", $resultType->{'mediaType'}, \"\
\\n\";\n			}\n			if ( defined( $resultType->{'file\
Suffix'} ) ) {\n				print STDOUT \"\\t\", $resultT\
ype->{'fileSuffix'}, \"\\n\";\n			}\n		}\n		if ( $\
status eq 'FINISHED' && $outputLevel > 0 ) {\n			p\
rint STDERR \"\\n\", 'To get results:', \"\\n\",\n\
			  \"  $scriptName --polljob --jobid \" . $param\
s{'jobid'} . \"\\n\",\n			  \"  $scriptName --poll\
job --outformat <type> --jobid \"\n			  . $params{\
'jobid'} . \"\\n\";\n		}\n	}\n	print_debug_message\
( 'result_types', 'End', 1 );\n}\n\n=head2 submit_\
job()\n\nSubmit a job to the service.\n\n  &submit\
_job($seq);\n\n=cut\n\nsub submit_job {\n	print_de\
bug_message( 'submit_job', 'Begin', 1 );\n\n	# Set\
 input sequence\n	$tool_params{'sequence'} = shift\
;\n\n	# Load parameters\n	&load_params();\n\n	# Su\
bmit the job\n	my $jobid = &rest_run( $params{'ema\
il'}, $params{'title'}, \\%tool_params );\n\n	# Si\
mulate sync/async mode\n	if ( defined( $params{'as\
ync'} ) ) {\n		print STDOUT $jobid, \"\\n\";\n		if\
 ( $outputLevel > 0 ) {\n			print STDERR\n			  \"T\
o check status: $scriptName --status --jobid $jobi\
d\\n\";\n		}\n	}\n	else {\n		if ( $outputLevel > 0\
 ) {\n			print STDERR \"JobId: $jobid\\n\";\n		}\n\
		sleep 1;\n		&get_results($jobid);\n	}\n	print_de\
bug_message( 'submit_job', 'End', 1 );\n}\n\n=head\
2 multi_submit_job()\n\nSubmit multiple jobs assum\
ing input is a collection of fasta formatted seque\
nces.\n\n  &multi_submit_job();\n\n=cut\n\nsub mul\
ti_submit_job {\n	print_debug_message( 'multi_subm\
it_job', 'Begin', 1 );\n	my $jobIdForFilename = 1;\
\n	$jobIdForFilename = 0 if ( defined( $params{'ou\
tfile'} ) );\n	my (@filename_list) = ();\n\n	# Que\
ry sequence\n	if ( defined( $ARGV[0] ) ) {    # Ba\
re option\n		if ( -f $ARGV[0] || $ARGV[0] eq '-' )\
 {    # File\n			push( @filename_list, $ARGV[0] );\
\n		}\n		else {\n			warn 'Warning: Input file \"' \
. $ARGV[0] . '\" does not exist'\n		}\n	}\n	if ( $\
params{'sequence'} ) {                   # Via --s\
equence\n		if ( -f $params{'sequence'} || $params{\
'sequence'} eq '-' ) {    # File\n			push( @filena\
me_list, $params{'sequence'} );\n		}\n		else {\n		\
	warn 'Warning: Input file \"' . $params{'sequence\
'} . '\" does not exist'\n		}\n	}\n\n	$/ = '>';\n	\
foreach my $filename (@filename_list) {\n		my $INF\
ILE;\n		if($filename eq '-') { # STDIN.\n			open( \
$INFILE, '<-' )\n			  or die 'Error: unable to STD\
IN (' . $! . ')';\n		} else { # File.\n			open( $I\
NFILE, '<', $filename )\n			  or die 'Error: unabl\
e to open file ' . $filename . ' (' . $! . ')';\n	\
	}\n		while (<$INFILE>) {\n			my $seq = $_;\n			$s\
eq =~ s/>$//;\n			if ( $seq =~ m/(\\S+)/ ) {\n				\
print STDERR \"Submitting job for: $1\\n\"\n				  \
if ( $outputLevel > 0 );\n				$seq = '>' . $seq;\n\
				&print_debug_message( 'multi_submit_job', $seq\
, 11 );\n				&submit_job($seq);\n				$params{'outf\
ile'} = undef if ( $jobIdForFilename == 1 );\n			}\
\n		}\n		close $INFILE;\n	}\n	print_debug_message(\
 'multi_submit_job', 'End', 1 );\n}\n\n=head2 list\
_file_submit_job()\n\nSubmit multiple jobs using a\
 file containing a list of entry identifiers as \n\
input.\n\n  &list_file_submit_job($list_filename)\\
n\n=cut\n\nsub list_file_submit_job {\n	print_debu\
g_message( 'list_file_submit_job', 'Begin', 11 );\\
n	my $filename         = shift;\n	my $jobIdForFile\
name = 1;\n	$jobIdForFilename = 0 if ( defined( $p\
arams{'outfile'} ) );\n\n	# Iterate over identifie\
rs, submitting each job\n	my $LISTFILE;\n	if($file\
name eq '-') { # STDIN.\n		open( $LISTFILE, '<-' )\
\n		  or die 'Error: unable to STDIN (' . $! . ')'\
;\n	} else { # File.\n		open( $LISTFILE, '<', $fil\
ename )\n		  or die 'Error: unable to open file ' \
. $filename . ' (' . $! . ')';\n	}\n	while (<$LIST\
FILE>) {\n		my $line = $_;\n		chomp($line);\n		if \
( $line ne '' ) {\n			&print_debug_message( 'list_\
file_submit_job', 'line: ' . $line, 2 );\n			if ( \
$line =~ m/\\w:\\w/ ) {    # Check this is an iden\
tifier\n				print STDERR \"Submitting job for: $li\
ne\\n\"\n				  if ( $outputLevel > 0 );\n				&subm\
it_job($line);\n			}\n			else {\n				print STDERR\\
n\"Warning: line \\\"$line\\\" is not recognised a\
s an identifier\\n\";\n			}\n		}\n		$params{'outfi\
le'} = undef if ( $jobIdForFilename == 1 );\n	}\n	\
close $LISTFILE;\n	print_debug_message( 'list_file\
_submit_job', 'End', 11 );\n}\n\n=head2 load_data(\
)\n\nLoad sequence data from file or option specif\
ied on the command-line.\n\n  &load_data();\n\n=cu\
t\n\nsub load_data {\n	print_debug_message( 'load_\
data', 'Begin', 1 );\n	my $retSeq;\n\n	# Query seq\
uence\n	if ( defined( $ARGV[0] ) ) {    # Bare opt\
ion\n		if ( -f $ARGV[0] || $ARGV[0] eq '-' ) {    \
# File\n			$retSeq = &read_file( $ARGV[0] );\n		}\\
n		else {                                     # DB\
:ID or sequence\n			$retSeq = $ARGV[0];\n		}\n	}\n\
	if ( $params{'sequence'} ) {                   # \
Via --sequence\n		if ( -f $params{'sequence'} || $\
params{'sequence'} eq '-' ) {    # File\n			$retSe\
q = &read_file( $params{'sequence'} );\n		}\n		els\
e {    # DB:ID or sequence\n			$retSeq = $params{'\
sequence'};\n		}\n	}\n	print_debug_message( 'load_\
data', 'End', 1 );\n	return $retSeq;\n}\n\n=head2 \
load_params()\n\nLoad job parameters from command-\
line options.\n\n  &load_params();\n\n=cut\n\nsub \
load_params {\n	print_debug_message( 'load_params'\
, 'Begin', 1 );\n\n	# Database(s) to search\n	my (\
@dbList) = split /[ ,]/, $params{'database'};\n	$t\
ool_params{'database'} = \\@dbList;\n\n	# Compatab\
ility options, old command-line.\n	if(!$tool_param\
s{'viewfilter'} && $params{'echofilter'}) {\n		$to\
ol_params{'viewfilter'} = 'true';\n	}\n	if(!$tool_\
params{'alignments'} && $params{'numal'}) {\n		$to\
ol_params{'alignments'} = $params{'numal'};\n	}\n	\
# TODO: set alignment format option to get NCBI BL\
AST XML.\n	if($params{'appxml'}) {\n		$tool_params\
{'align'} = '';\n	}\n\n	print_debug_message( 'load\
_params', 'End', 1 );\n}\n\n=head2 client_poll()\n\
\nClient-side job polling.\n\n  &client_poll($job_\
id);\n\n=cut\n\nsub client_poll {\n	print_debug_me\
ssage( 'client_poll', 'Begin', 1 );\n	my $jobid  =\
 shift;\n	my $status = 'PENDING';\n\n	my $errorCou\
nt = 0;\n	while ($status eq 'RUNNING'\n		|| $statu\
s eq 'PENDING'\n		|| ( $status eq 'ERROR' && $erro\
rCount < 2 ) )\n	{\n		$status = rest_get_status($j\
obid);\n		print STDERR \"$status\\n\" if ( $output\
Level > 0 );\n		if ( $status eq 'ERROR' ) {\n			$e\
rrorCount++;\n		}\n		elsif ( $errorCount > 0 ) {\n\
			$errorCount--;\n		}\n		if (   $status eq 'RUNNI\
NG'\n			|| $status eq 'PENDING'\n			|| $status eq \
'ERROR' )\n		{\n\n			# Wait before polling again.\\
n			sleep $checkInterval;\n		}\n	}\n	print_debug_m\
essage( 'client_poll', 'End', 1 );\n	return $statu\
s;\n}\n\n=head2 get_results()\n\nGet the results f\
or a job identifier.\n\n  &get_results($job_id);\n\
\n=cut\n\nsub get_results {\n	print_debug_message(\
 'get_results', 'Begin', 1 );\n	my $jobid = shift;\
\n	print_debug_message( 'get_results', 'jobid: ' .\
 $jobid, 1 );\n\n	# Verbose\n	if ( $outputLevel > \
1 ) {\n		print 'Getting results for job ', $jobid,\
 \"\\n\";\n	}\n\n	# Check status, and wait if not \
finished\n	client_poll($jobid);\n\n	# Use JobId if\
 output file name is not defined\n	unless ( define\
d( $params{'outfile'} ) ) {\n		$params{'outfile'} \
= $jobid;\n	}\n\n	# Get list of data types\n	my (@\
resultTypes) = rest_get_result_types($jobid);\n\n	\
# Get the data and write it to a file\n	if ( defin\
ed( $params{'outformat'} ) ) {    # Specified data\
 type\n		my $selResultType;\n		foreach my $resultT\
ype (@resultTypes) {\n			if ( $resultType->{'ident\
ifier'} eq $params{'outformat'} ) {\n				$selResul\
tType = $resultType;\n			}\n		}\n		if ( defined($s\
elResultType) ) {\n			my $result =\n			  rest_get_\
result( $jobid, $selResultType->{'identifier'} );\\
n			if ( $params{'outfile'} eq '-' ) {\n				write_\
file( $params{'outfile'}, $result );\n			}\n			els\
e {\n				write_file(\n					$params{'outfile'} . '.\
'\n					  . $selResultType->{'identifier'} . '.'\n\
					  . $selResultType->{'fileSuffix'},\n					$re\
sult\n				);\n			}\n		}\n		else {\n			die 'Error: \
unknown result format \"' . $params{'outformat'} .\
 '\"';\n		}\n	}\n	else {    # Data types available\
\n		      # Write a file for each output type\n		f\
or my $resultType (@resultTypes) {\n			if ( $outpu\
tLevel > 1 ) {\n				print STDERR 'Getting ', $resu\
ltType->{'identifier'}, \"\\n\";\n			}\n			my $res\
ult = rest_get_result( $jobid, $resultType->{'iden\
tifier'} );\n			if ( $params{'outfile'} eq '-' ) {\
\n				write_file( $params{'outfile'}, $result );\n\
			}\n			else {\n				write_file(\n					$params{'ou\
tfile'} . '.'\n					  . $resultType->{'identifier'\
} . '.'\n					  . $resultType->{'fileSuffix'},\n		\
			$result\n				);\n			}\n		}\n	}\n	print_debug_me\
ssage( 'get_results', 'End', 1 );\n}\n\n=head2 rea\
d_file()\n\nRead a file into a scalar. The special\
 filename '-' can be used to read from \nstandard \
input (STDIN).\n\n  my $data = &read_file($filenam\
e);\n\n=cut\n\nsub read_file {\n	print_debug_messa\
ge( 'read_file', 'Begin', 1 );\n	my $filename = sh\
ift;\n	print_debug_message( 'read_file', 'filename\
: ' . $filename, 2 );\n	my ( $content, $buffer );\\
n	if ( $filename eq '-' ) {\n		while ( sysread( ST\
DIN, $buffer, 1024 ) ) {\n			$content .= $buffer;\\
n		}\n	}\n	else {    # File\n		open( my $FILE, '<'\
, $filename )\n		  or die \"Error: unable to open \
input file $filename ($!)\";\n		while ( sysread( $\
FILE, $buffer, 1024 ) ) {\n			$content .= $buffer;\
\n		}\n		close($FILE);\n	}\n	print_debug_message( \
'read_file', 'End', 1 );\n	return $content;\n}\n\n\
=head2 write_file()\n\nWrite data to a file. The s\
pecial filename '-' can be used to write to \nstan\
dard output (STDOUT).\n\n  &write_file($filename, \
$data);\n\n=cut\n\nsub write_file {\n	print_debug_\
message( 'write_file', 'Begin', 1 );\n	my ( $filen\
ame, $data ) = @_;\n	print_debug_message( 'write_f\
ile', 'filename: ' . $filename, 2 );\n	if ( $outpu\
tLevel > 0 ) {\n		print STDERR 'Creating result fi\
le: ' . $filename . \"\\n\";\n	}\n	if ( $filename \
eq '-' ) {\n		print STDOUT $data;\n	}\n	else {\n		\
open( my $FILE, '>', $filename )\n		  or die \"Err\
or: unable to open output file $filename ($!)\";\n\
		syswrite( $FILE, $data );\n		close($FILE);\n	}\n\
	print_debug_message( 'write_file', 'End', 1 );\n}\
\n\n=head2 usage()\n\nPrint program usage message.\
\n\n  &usage();\n\n=cut\n\nsub usage {\n	print STD\
ERR <<EOF\nWU-BLAST\n========\n   \nRapid sequence\
 database search programs utilizing the BLAST algo\
rithm\n    \n[Required]\n\n  -p, --program      : \
str  : BLAST program to use, see --paramDetail pro\
gram\n  -D, --database     : str  : database(s) to\
 search, space separated. See\n                   \
           --paramDetail database\n      --stype  \
      : str  : query sequence type, see --paramDet\
ail stype\n  seqFile            : file : query seq\
uence (\"-\" for STDIN, \\@filename for\n         \
                     identifier list file)\n\n[Opt\
ional]\n\n  -m, --matrix       : str  : scoring ma\
trix, see --paramDetail matrix\n  -e, --exp       \
   : real : 0<E<= 1000. Statistical significance t\
hreshold \n                              for repor\
ting database sequence matches.\n  -e, --viewfilte\
r   :      : display the filtered query sequence\n\
  -f, --filter       : str  : filter the query seq\
uence for low complexity \n                       \
       regions, see --paramDetail filter\n  -A, --\
align        : int  : pairwise alignment format, s\
ee --paramDetail align\n  -s, --scores       : int\
  : number of scores to be reported\n  -b, --align\
ments   : int  : number of alignments to report\n \
 -S, --sensitivity  : str  : sensitivity of the se\
arch, \n                              see --paramD\
etail sensitivity\n  -t, --sort	     : str  : sort\
 order for hits, see --paramDetail sort\n  -T, --s\
tats        : str  : statistical model, see --para\
mDetail stats\n  -d, --strand       : str  : DNA s\
trand to search with,\n                           \
   see --paramDetail strand\n  -c, --topcombon    \
: str  : consistent sets of HSPs\n      --multifas\
ta   :      : treat input as a set of fasta format\
ted sequences\n\n[General]\n\n  -h, --help        \
 :      : prints this help text\n      --async    \
    :      : forces to make an asynchronous query\\
n      --email        : str  : e-mail address\n   \
   --title        : str  : title for job\n      --\
status       :      : get job status\n      --resu\
ltTypes  :      : get available result types for j\
ob\n      --polljob      :      : poll for the sta\
tus of a job\n      --jobid        : str  : jobid \
that was returned when an asynchronous job \n     \
                         was submitted.\n      --o\
utfile      : str  : file name for results (defaul\
t is jobid;\n                              \"-\" f\
or STDOUT)\n      --outformat    : str  : result f\
ormat to retrieve\n      --params       :      : l\
ist input parameters\n      --paramDetail  : str  \
: display details for input parameter\n      --qui\
et        :      : decrease output\n      --verbos\
e      :      : increase output\n   \nSynchronous \
job:\n\n  The results/errors are returned as soon \
as the job is finished.\n  Usage: $scriptName --em\
ail <your\\@email> [options...] seqFile\n  Returns\
: results as an attachment\n\nAsynchronous job:\n\\
n  Use this if you want to retrieve the results at\
 a later time. The results \n  are stored for up t\
o 24 hours. 	\n  Usage: $scriptName --async --emai\
l <your\\@email> [options...] seqFile\n  Returns: \
jobid\n\n  Use the jobid to query for the status o\
f the job. If the job is finished, \n  it also ret\
urns the results/errors.\n  Usage: $scriptName --p\
olljob --jobid <jobId> [--outfile string]\n  Retur\
ns: string indicating the status of the job and if\
 applicable, results \n  as an attachment.\n\nFurt\
her information:\n\n  http://www.ebi.ac.uk/Tools/w\
ebservices/services/sss/wu_blast_rest\n  http://ww\
w.ebi.ac.uk/Tools/webservices/tutorials/perl\n\nSu\
pport/Feedback:\n\n  http://www.ebi.ac.uk/support/\
\nEOF\n}\n\n=head1 FEEDBACK/SUPPORT\n\nPlease cont\
act us at L<http://www.ebi.ac.uk/support/> if you \
have any \nfeedback, suggestions or issues with th\
e service or this client.\n\n=cut\n","\n\n\nmy $PR\
OBTRESH = 0.3;# base pairs below this prob thresho\
ld will be ignored\nmy $WEIGHT = 100.0; # float!!\\
nmy $NUCALPH = \"ACGTUNRYMKSWHBVD\";\nuse vars qw(\
$NUCALPH $WEIGHT);\n\nmy $myname = basename($0);\n\
\nuse strict;\nuse warnings;\n\nuse File::Basename\
;\nuse Getopt::Long;\nuse File::Glob ':glob';\nuse\
 File::Spec;\nuse File::Temp qw/ tempfile tempdir \
/;\n\n\n\n\nsub tcoffeelib_header($;$)\n{\n    my \
($nseq, $fd) = @_;\n    if (! defined($fd)) {\n   \
     $fd = *STDOUT;\n    }\n    printf $fd \"! TC_\
LIB_FORMAT_01\\n\";\n    printf $fd \"%d\\n\", $ns\
eq;\n}\n\n\nsub tcoffeelib_header_addseq($$;$)\n{\\
n    my ($id, $seq, $fd) = @_;\n    if (! defined(\
$fd)) {\n        $fd = *STDOUT;\n    }\n    printf\
 $fd \"%s %d %s\\n\", $id, length($seq), $seq;\n}\\
n\n\nsub tcoffeelib_comment($;$)\n{\n    my ($comm\
ent, $fd) = @_;\n    if (! defined($fd)) {\n      \
  $fd = *STDOUT;\n    }\n    printf $fd \"!\" . $c\
omment . \"\\n\";\n}\n\n\nsub tcoffeelib_struct($$\
$;$)\n{\n    my ($nseq, $len, $bpm, $fd) = @_;\n\n\
    if (! defined($fd)) {\n        $fd = *STDOUT;\\
n    }\n\n    # output basepair indices with fixed\
 weight\n    printf $fd \"#%d %d\\n\", $nseq, $nse\
q;\n    # output basepairs (only once) and with un\
it-offset\n    for (my $i=0; $i<$len; $i++) {\n   \
     for (my $j=$i+1; $j<$len; $j++) {\n          \
  if (! defined($bpm->[$i][$j])) {\n              \
  print STDERR \"ERROR: \\$bpm->[$i][$j] undefined\
\\n\";\n            }\n            if ($bpm->[$i][\
$j]>0) {\n                print $fd $i+1;\n       \
         print $fd \" \";\n                print $\
fd $j+1;\n                print $fd \" \" . $bpm->\
[$i][$j] . \"\\n\";\n            }\n        }\n   \
 }\n}\n\n\nsub tcoffeelib_footer(;$)\n{\n    my ($\
fd) = @_;\n    if (! defined($fd)) {\n        $fd \
= *STDOUT;\n    }\n    print $fd \"! SEQ_1_TO_N\\n\
\";\n}\n\n\n    \nsub plfold($$$)\n{    \n    my (\
$id, $seq, $probtresh) = @_;\n    my (@struct);# r\
eturn\n    my ($templ, $fhtmp, $fnametmp, $cmd, $c\
tr, $window_size);\n    our $ntemp++;\n    \n    $\
templ = $myname . \".pid-\" . $$ .$ntemp .\".XXXXX\
X\";\n    ($fhtmp, $fnametmp) = tempfile($templ, U\
NLINK => 1); \n    print $fhtmp \">$id\\n$seq\\n\"\
;\n\n    # --- init basepair array\n    #\n    for\
 (my $i=0; $i<length($seq); $i++) {\n        for (\
my $j=$i+1; $j<length($seq); $j++) {\n            \
$struct[$i][$j]=0;\n        }\n    }\n\n\n    # --\
- call rnaplfold and drop a readme\n    #\n    $wi\
ndow_size=(length($seq)<70)?length($seq):70;\n    \
$cmd = \"RNAplfold -W $window_size < $fnametmp >/d\
ev/null\";\n    system($cmd);\n    \n    if ($? !=\
 0) {\n        printf STDERR \"ERROR: RNAplfold ($\
cmd) exited with error status %d\\n\", $? >> 8;\n \
       return;\n    }\n    #unlink($fnametmp);\n  \
  my $fps = sprintf(\"%s_dp.ps\", $id); # check lo\
ng name\n    \n    if (! -s $fps) {\n      {\n\n	$\
fps = sprintf(\"%s_dp.ps\", substr($id,0,12)); # c\
heck short name\n 	if (! -s $fps)\n	  {\n	    die(\
\"couldn't find expected file $fps\\n\");\n	    re\
turn;\n	  }\n      }\n    }\n\n    \n    # --- rea\
d base pairs from created postscript\n    #\n    o\
pen(FH, $fps);\n    while (my $line = <FH>) {\n   \
     my ($nti, $ntj, $prob);\n        chomp($line)\
;        \n        # line: bp bp sqrt-prob ubox\n \
       my @match = ($line =~ m/^([0-9]+) +([0-9]+)\
 +([0-9\\.]+) +ubox$/);\n        if (scalar(@match\
)) {\n            $nti=$1;\n            $ntj=$2;\n\
            $prob=$3*$3;# prob stored as square ro\
ot\n\n            if ($prob>$probtresh) {\n       \
         #printf STDERR \"\\$struct[$nti][$ntj] sq\
rtprob=$3 prob=$prob > $probtresh\\n\";\n         \
       $struct[$nti-1][$ntj-1] = $WEIGHT\n        \
    }\n            # store with zero-offset\n     \
   }\n    }\n    close(FH);\n\n    # remove or gzi\
 postscript\n    #\n    unlink($fps);\n    #\n    \
# or gzip\n    #$cmd = \"gzip -qf $fps\";\n    #sy\
stem($cmd);\n    #if ($? != 0) {\n    #    printf \
STDERR \"ERROR: gzip ($cmd) exited with error stat\
us %d\\n\", $? >> 8;\n    #}\n\n    return \\@stru\
ct;\n}\n\n\n\n\n\nsub rnaseqfmt($)\n{\n    my ($se\
q) = @_;\n    # remove gaps\n    $seq =~ s/-//g;\n\
    # uppercase RNA\n    $seq = uc($seq);\n    # T\
 -> U\n    $seq =~ s/T/U/g;\n    # check for inval\
id charaters\n    $_ = $seq;\n    s/[^$NUCALPH]//g\
;\n    return $_;\n}\n\n\n\n\nsub usage(;$)\n{    \
\n    my ($errmsg) = @_;\n    if ($errmsg) {\n    \
    print STDERR \"ERROR: $errmsg\\n\";\n    }\n  \
  print STDERR << \"EOF\";\n$myname:\n Creates a T\
-Coffee RNA structure library from RNAplfold predi\
ction.\n See FIXME:citation\nUsage:\n $myname -in \
seq_file -out tcoffee_lib\nEOF\n    exit(1);\n}\n\\
nsub read_fasta_seq \n  {\n    my $f=$_[0];\n    m\
y %hseq;\n    my (@seq, @com, @name);\n    my ($a,\
 $s,$nseq);\n\n    open (F, $f);\n    while (<F>)\\
n      {\n	$s.=$_;\n      }\n    close (F);\n\n   \
 \n    @name=($s=~/>(\\S*).*\\n[^>]*/g);\n    \n  \
  @seq =($s=~/>.*.*\\n([^>]*)/g);\n    @com =($s=~\
/>(\\S*)(.*)\\n([^>]*)/g);\n\n\n    $nseq=$#name+1\
;\n  \n    for ($a=0; $a<$nseq; $a++)\n      {\n	m\
y $n=$name[$a];\n	my $s;\n	$hseq{$n}{name}=$n;\n	$\
s=$seq[$a];$s=~s/\\s//g;\n	\n	$hseq{$n}{seq}=$s;\n\
	$hseq{$n}{com}=$com[$a];\n      }\n    return %hs\
eq;\n  }\n\n\n\n\n\n\n\nmy $fmsq = \"\";\nmy $flib\
 = \"\";\nmy %OPTS;\nmy %seq;\nmy ($id, $nseq, $i)\
;\nmy @nl;\n\nGetOptions(\"in=s\" => \\$fmsq, \"ou\
t=s\" => \\$flib);\n\nif (! -s $fmsq) {\n    usage\
(\"empty or non-existant file \\\"$fmsq\\\"\")\n}\\
nif (length($flib)==0) {\n    usage(\"empty out-fi\
lename\")\n}\n\n\n\n\n\n\n%seq=read_fasta_seq($fms\
q);\n\n\n@nl=keys(%seq);\n\n$nseq=$#nl+1;\nopen FD\
_LIB, \">$flib\" or die \"can't open $flib!\";\ntc\
offeelib_header($nseq, *FD_LIB);\nforeach $id (key\
s (%seq))\n  {\n    my ($seq, $fmtseq);\n    \n   \
 $seq = $seq{$id}{seq};\n    \n    $fmtseq = rnase\
qfmt($seq);# check here, formatting for folding im\
portant later\n    if (length($seq)!=length($fmtse\
q)) {\n        print STDERR \"ERROR: invalid seque\
nce $id is not an RNA sequence. read seq is: $seq\\
\n\";\n        exit\n      }\n   \n    tcoffeelib_\
header_addseq($id, uc($seq), *FD_LIB);\n  }\ntcoff\
eelib_comment(\"generated by $myname on \" . local\
time(), *FD_LIB);\n\n\n\n$i=0;\nforeach $id (keys \
(%seq))\n  {\n    my ($cleanid, $seq, $bpm);\n    \
$seq=$seq{$id}{seq};\n    $cleanid = $id;\n    $cl\
eanid =~ s,[/ ],_,g;# needed for rnaplfold\n    $s\
eq = rnaseqfmt($seq);\n    \n    $bpm = plfold($cl\
eanid, rnaseqfmt($seq), $PROBTRESH);       \n    \\
n    tcoffeelib_struct($i+1, length($seq), $bpm, *\
FD_LIB);\n    $i++;\n}\n\n\ntcoffeelib_footer(*FD_\
LIB);\nclose FD_LIB;\nexit (0);\n\n","\n\n\n\n\n$c\
md=join ' ', @ARGV;\nif ($cmd=~/-infile=(\\S+)/){ \
$seqfile=$1;}\nif ($cmd=~/-outfile=(\\S+)/){ $libf\
ile=$1;}\n\n\n\n%s=read_fasta_seq ($seqfile);\n\no\
pen (F, \">$libfile\");\nforeach $name (keys (%s))\
\n  {\n    my $tclib=\"$name.RNAplfold_tclib\";\n \
   print (F \">$name _F_ $tclib\\n\");\n    seq2RN\
Aplfold2tclib ($name, $s{$name}{seq}, $tclib);\n  \
}\nclose (F);\nexit (EXIT_SUCCESS);\n\nsub seq2RNA\
plfold2tclib\n  {\n    my ($name, $seq, $tclib)=@_\
;\n    my ($tmp);\n    $n++;\n    $tmp=\"tmp4seq2R\
NAplfold_tclib.$$.$n.pep\";\n    open (RF, \">$tmp\
\");\n    print (RF \">$name\\n$seq\\n\");\n    cl\
ose (RF);\n    \n    system \"t_coffee -other_pg R\
NAplfold2tclib.pl -in=$tmp -out=$tclib\";\n    \n \
   unlink ($tmp);\n    return $tclib;\n  }\n    \n\
    \nsub read_fasta_seq \n  {\n    my $f=@_[0];\n\
    my %hseq;\n    my (@seq, @com, @name);\n    my\
 ($a, $s,$nseq);\n\n    open (F, $f);\n    while (\
<F>)\n      {\n	$s.=$_;\n      }\n    close (F);\n\
\n    \n    @name=($s=~/>(\\S*).*\\n[^>]*/g);\n   \
 \n    @seq =($s=~/>.*.*\\n([^>]*)/g);\n    @com =\
($s=~/>\\S*(.*)\\n([^>]*)/g);\n\n    \n    $nseq=$\
#name+1;\n    \n    for ($a=0; $a<$nseq; $a++)\n  \
    {\n	my $n=$name[$a];\n	$hseq{$n}{name}=$n;\n	$\
hseq{$n}{seq}=$seq[$a];\n	$hseq{$n}{com}=$com[$a];\
\n      }\n    return %hseq;\n  }\n","use Getopt::\
Long;\nuse File::Path;\nuse Env;\nuse FileHandle;\\
nuse Cwd;\nuse Sys::Hostname;\nour $PIDCHILD;\nour\
 $ERROR_DONE;\nour @TMPFILE_LIST;\nour $EXIT_FAILU\
RE=1;\nour $EXIT_SUCCESS=0;\n\nour $REFDIR=getcwd;\
\nour $EXIT_SUCCESS=0;\nour $EXIT_FAILURE=1;\n\nou\
r $PROGRAM=\"tc_generic_method.pl\";\nour $CL=$PRO\
GRAM;\n\nour $CLEAN_EXIT_STARTED;\nour $debug_lock\
=$ENV{\"DEBUG_LOCK\"};\nour $LOCKDIR=$ENV{\"LOCKDI\
R_4_TCOFFEE\"};\nif (!$LOCKDIR){$LOCKDIR=getcwd();\
}\nour $ERRORDIR=$ENV{\"ERRORDIR_4_TCOFFEE\"};\nou\
r $ERRORFILE=$ENV{\"ERRORFILE_4_TCOFFEE\"};\n&set_\
lock ($$);\nif (isshellpid(getppid())){lock4tc(get\
ppid(), \"LLOCK\", \"LSET\", \"$$\\n\");}\n      \\
nour $print;\nmy ($fmsq1, $fmsq2, $output, $outfil\
e, $arch, $psv, $hmmtop_home, $trim, $cov, $sample\
, $mode, $gor_home, $gor_seq, $gor_obs);\n\nGetOpt\
ions(\"-in=s\" => \\$fmsq1,\"-output=s\" =>\\$outp\
ut ,\"-out=s\" => \\$outfile, \"-arch=s\" => \\$ar\
ch,\"-psv=s\" => \\$psv, \"-hmmtop_home=s\", \\$hm\
mtop_home,\"-trim=s\" =>\\$trim ,\"-print=s\" =>\\\
$print,\"-cov=s\" =>\\$cov , \"-sample=s\" =>\\$sa\
mple, \"-mode=s\" =>\\$mode, \"-gor_home=s\"=>\\$g\
or_home, \"-gor_seq=s\"=>\\$gor_seq,\"-gor_obs=s\"\
=>\\$gor_obs);\n\n\nif (!$mode){$mode = \"hmmtop\"\
}\nelsif ($mode eq \"hmmtop\"){;}\nelsif ($mode eq\
 \"gor\"){;}\nelse {myexit(flush_error (\"-mode=$m\
ode is unknown\"));}\n\n\nour $HOME=$ENV{\"HOME\"}\
;\nour $MCOFFEE=($ENV{\"MCOFFEE_4_TCOFFEE\"})?$ENV\
{\"MCOFFEE_4_TCOFFEE\"}:\"$HOME/.t_coffee/mcoffee\\
";\n\nif ($mode eq \"hmmtop\")\n  {\n    \n    che\
ck_configuration (\"hmmtop\");\n    if (-e $arch){\
$ENV{'HMMTOP_ARCH'}=$arch;}\n    elsif (-e $ENV{HM\
MTOP_ARCH}){$arch=$ENV{HMMTOP_ARCH};}\n    elsif (\
-e \"$MCOFFEE/hmmtop.arch\"){$arch=$ENV{'HMMTOP_AR\
CH'}=\"$MCOFFEE/hmmtop.arch\";}\n    elsif (-e \"$\
hmmtop_home/hmmtop.arch\"){$arch=$ENV{'HMMTOP_ARCH\
'}=\"$hmmtop_home/hmmtop.arch\";}\n    else {myexi\
t(flush_error ( \"Could not find ARCH file for hmm\
top\"));}\n    \n    \n    if (-e $psv){$ENV{'HMMT\
OP_PSV'}=$psv;}\n    elsif (-e $ENV{HMMTOP_PSV}){$\
psv=$ENV{HMMTOP_PSV};}\n    elsif (-e \"$MCOFFEE/h\
mmtop.psv\"){$psv=$ENV{'HMMTOP_PSV'}=\"$MCOFFEE/hm\
mtop.psv\";}\n    elsif (-e \"$hmmtop_home/hmmtop.\
psv\"){$psv=$ENV{'HMMTOP_PSV'}=\"$hmmtop_home/hmmt\
op.psv\";}\n    else {myexit(flush_error ( \"Could\
 not find PSV file for hmmtop\"));}\n\n  }\nelsif \
($mode eq \"gor\")\n  {\n    our $GOR_SEQ;\n    ou\
r $GOR_OBS;\n    \n    check_configuration (\"gorI\
V\");\n    if (-e $gor_seq){$GOR_SEQ=$gor_seq;}\n \
   elsif (-e $ENV{GOR_SEQ}){$GOR_SEQ=$ENV{GOR_SEQ}\
;}\n    elsif (-e \"$MCOFFEE/New_KS.267.seq\"){$GO\
R_SEQ=\"$MCOFFEE/New_KS.267.seq\";}\n    elsif (-e\
 \"$gor_home/New_KS.267.seq\"){$GOR_SEQ=\"$gor_hom\
e/New_KS.267.seq\";}\n    else {myexit(flush_error\
 ( \"Could not find SEQ file for gor\"));}\n\n    \
if (-e $gor_obs){$GOR_OBS=$gor_obs;}\n    elsif (-\
e $ENV{GOR_OBS}){$GOR_OBS=$ENV{GOR_OBS};}\n    els\
if (-e \"$MCOFFEE/New_KS.267.obs\"){$GOR_OBS=\"$MC\
OFFEE/New_KS.267.obs\";}\n    elsif (-e \"$gor_hom\
e/New_KS.267.obs\"){$GOR_OBS=\"$gor_home/New_KS.26\
7.obs\";}\n    else {myexit(flush_error ( \"Could \
not find OBS file for gor\"));}\n  }\n\n\nif ( ! -\
e $fmsq1){myexit(flush_error (\"Could Not Read Inp\
ut file $fmsq1\"));}\n\n\nmy $fmsq2=vtmpnam();\nmy\
 $fmsq3=vtmpnam();\nmy $tmpfile=vtmpnam();\nmy $pr\
edfile=vtmpnam();\n\nif ($trim){$trim_action=\" +t\
rim _aln_%%$trim\\_K1 \";}\nif ($cov) {$cov_action\
= \" +sim_filter _aln_c$cov \";}\n&safe_system(\"t\
_coffee -other_pg seq_reformat -in $fmsq1 -action \
+convert 'BOUJXZ-' $cov_action $trim_action -outpu\
t fasta_aln -out $fmsq2\");\nmy (%pred, %seq, %pre\
dA);\n\n\n%seq=read_fasta_seq($fmsq2);\n%seq=fasta\
2sample(\\%seq, $sample);\n\nif (1==2 &&$mode eq \\
"hmmtop\" && $output eq \"cons\")\n  {\n    fasta2\
hmmtop_cons($outfile,\\%seq);\n  }\nelse\n  {\n   \
\n    %pred=fasta2pred(\\%seq, $mode);\n    %predA\
=pred2aln (\\%pred, \\%seq);\n    \n    \n    if (\
!$output || $output eq \"prediction\"){output_fast\
a_seq (\\%predA, $outfile);}\n    elsif ($output e\
q \"color_html\"){pred2color (\\%pred,\\%seq, $out\
file);}\n    elsif ($output eq \"cons\"){pred2cons\
($outfile,\\%predA);}\n    else {flush_error (\"$o\
utput is an unknown output mode\");}\n  }\n\nsub f\
asta2sample\n  {\n    my $SR=shift;\n    my $it=sh\
ift;\n    my %S=%$SR;\n    \n    my $seq=index2seq\
_name (\\%S, 1);\n    my $l=length($S{$seq}{seq});\
\n    my @sl=keys(%S);\n    my $nseq=$#sl+1;\n    \
my $index=$nseq;\n  \n    if (!$sample) {return %S\
;}\n    for (my $a=0; $a<$it; $a++)\n      {\n	my \
$newseq=\"\";\n	my $nname=\"$seq\\_sampled_$index\\
";\n	for (my $p=0; $p<$l; $p++)\n	  {\n	    my $i=\
int(rand($nseq));\n	    \n	    my $name = $sl[$i];\
\n	    my $seq=$S{$name}{seq};\n	    my $r=substr \
($seq, $p, 1);\n	    $newseq.=$r;\n	  }\n	$S{$nnam\
e}{name}=$nname;\n	$S{$nname}{seq}=$newseq;\n	$S{$\
nname}{com}=\"sampled\";\n	$S{$nname}{index}=++$in\
dex;\n      }\n    return %S;\n  }\n	      \nsub f\
asta2pred\n  {\n    my $s=shift;\n    my $mode=shi\
ft;\n\n    if ( $mode eq \"hmmtop\"){return fasta2\
hmmtop_pred($s);}\n    elsif ($mode eq \"gor\"){re\
turn fasta2gor_pred ($s);}\n  }\nsub fasta2hmmtop_\
cons\n  {\n    my $outfile=shift;\n    my $SR=shif\
t;\n    \n    my $o = new FileHandle;\n    my $i =\
 new FileHandle;\n    my $tmp_in =vtmpnam();\n    \
my $tmp_out=vtmpnam();\n    my %seq=%$SR;\n    my \
%pred;\n    my $N=keys(%seq);\n    \n    output_fa\
sta_seq (\\%seq,$tmp_in, \"seq\");\n    `hmmtop -p\
i=mpred -if=$tmp_in -sf=FAS -pl 2>/dev/null >$tmp_\
out`;\n    open ($o, \">$outfile\");\n    open ($i\
, \"$tmp_out\");\n    while (<$i>)\n      {\n	my $\
l=$_;\n	if (($l=~/>HP\\:\\s+(\\d+)\\s+(.*)/)){my $\
line=\">$2 NSEQ: $N\\n\";print $o \"$line\";}\n	el\
sif ( ($l=~/.*pred(.*)/))  {my $line=\"$1\\n\";pri\
nt $o \"$line\";}\n      }\n    close ($o);\n    c\
lose ($i);\n    return read_fasta_seq($tmp);\n  }\\
nsub fasta2hmmtop_pred\n  {\n    my $SR=shift;\n  \
  my $o = new FileHandle;\n    my $i = new FileHan\
dle;\n    my $tmp    =vtmpnam();\n    my $tmp_in =\
vtmpnam();\n    my $tmp_out=vtmpnam();\n    my %se\
q=%$SR;\n    my %pred;\n    \n\n    output_fasta_s\
eq (\\%seq,$tmp_in, \"seq\");\n\n    \n    `hmmtop\
 -if=$tmp_in -sf=FAS -pl 2>/dev/null >$tmp_out`;\n\
    \n\n    \n    \n    open ($o, \">$tmp\");\n   \
 open ($i, \"$tmp_out\");\n    while (<$i>)\n     \
 {\n	my $l=$_;\n	if (($l=~/>HP\\:\\s+(\\d+)\\s+(.*\
)/)){my $line=\">$2\\n\";print $o \"$line\";}\n	el\
sif ( ($l=~/.*pred(.*)/))  {my $line=\"$1\\n\";pri\
nt $o \"$line\";}\n      }\n    close ($o);\n    c\
lose ($i);\n    return read_fasta_seq($tmp);\n  }\\
n    \n	\n	\n	    \n	\n	\n\n	\nsub fasta2gor_pred\\
n  {\n    my $SR=shift;\n    my $o = new FileHandl\
e;\n    my $i = new FileHandle;\n    my $tmp    =v\
tmpnam();\n    my $tmp_in =vtmpnam();\n    my $tmp\
_out=vtmpnam();\n    my %seq=%$SR;\n    my %pred;\\
n    \n\n    output_fasta_seq (\\%seq,$tmp_in, \"s\
eq\");\n    `gorIV -prd $tmp_in -seq $GOR_SEQ -obs\
 $GOR_OBS >$tmp_out`;\n    open ($o, \">$tmp\");\n\
    open ($i, \"$tmp_out\");\n    while (<$i>)\n  \
    {\n	my $l=$_;\n\n	\n	if ( $l=~/>/){print $o \"\
$l\";}\n	elsif ( $l=~/Predicted Sec. Struct./){$l=\
~s/Predicted Sec. Struct\\.//;print $o \"$l\";}\n \
     }\n    close ($o);\n    close ($i);\n    retu\
rn read_fasta_seq($tmp);\n  }\n			\n			     \nsub \
index2seq_name\n  {\n    \n    my $SR=shift;\n    \
my $index=shift;\n    \n    \n    my %S=%$SR;\n   \
 \n    foreach my $s (%S)\n      {\n	if ( $S{$s}{i\
ndex}==$index){return $s;}\n      }\n    return \"\
\";\n  }\n\nsub pred2cons\n  {\n    my $outfile=sh\
ift;\n    my $predR=shift;\n    my $seq=shift;\n  \
  my %P=%$predR;\n    my %C;\n    my ($s,@r,$nseq)\
;\n    my $f= new FileHandle;\n\n    open ($f, \">\
$outfile\");\n\n    if (!$seq){$seq=index2seq_name\
(\\%P,1);}\n    foreach my $s (keys(%P))\n      {\\
n	$nseq++;\n	$string= $P{$s}{seq};\n	$string = uc \
$string;\n	my @r=split (//,$string);\n	for (my $a=\
0; $a<=$#r; $a++)\n	  {\n	    if (($r[$a]=~/[OHICE\
]/)){$C{$a}{$r[$a]}++;}\n	  }\n      }\n    @l=key\
s(%C);\n    \n    \n    $s=$P{$seq}{seq};\n    pri\
nt $f \">$seq pred based on $nseq\\n\";\n    @r=sp\
lit (//,$s);\n    \n    for (my $x=0; $x<=$#r; $x+\
+)\n      {\n	if ($r[$x] ne \"-\")\n	  {\n	    my \
$h=$C{$x}{H};\n	    my $i=$C{$x}{I};\n	    my $o=$\
C{$x}{O};\n	    my $c=$C{$x}{C};\n	    my $e=$C{$x\
}{E};\n	    my $l=$i+$o;\n	    \n	    if ($h>=$i &\
& $h>=$o && $h>=$c && $h>=$e){$r[$x]='H';}\n	    e\
lsif ($i>=$o && $i>=$c && $i>=$e){$r[$x]='I';}\n	 \
   elsif ($o>=$c && $o>=$e){$r[$x]='O';}\n	    els\
if ($c>=$e){$r[$x]='C';}\n	    else {$r[$x]='E';}\\
n	  }\n      }\n    $j=join ('', @r);\n    print $\
f \"$j\\n\";\n    close ($f);\n    return $j;\n  }\
\n\nsub pred2aln\n  {\n    my $PR=shift;\n    my $\
AR=shift;\n    \n    my $f=new FileHandle;\n    my\
 %P=%$PR;\n    my %A=%$AR;\n    my %PA;\n    my $t\
mp=vtmpnam();\n    my $f= new FileHandle;\n    \n \
   open ($f, \">$tmp\");\n    foreach my $s (sort{\
$A{$a}{index}<=>$A{$b}{index}}(keys (%A)))\n      \
{\n	my (@list, $seq, @plist, @pseq, $L, $PL, $c, $\
w);\n	my $seq;\n	my $seq=$A{$s}{seq};\n	my $pred=$\
P{$s}{seq};\n	$seq=pred2alnS($P{$s}{seq},$A{$s}{se\
q});\n	print $f \">$s\\n$seq\\n\";\n      }\n    c\
lose ($f);\n    return read_fasta_seq ($tmp);\n  }\
\nsub pred2alnS\n  {\n    my $pred=shift;\n    my \
$aln= shift;\n    my ($j,$a,$b);\n    my @P=split \
(//, $pred);\n    my @A=split (//, $aln);\n    for\
 ($a=$b=0;$a<=$#A; $a++)\n      {\n	if ($A[$a] ne \
\"-\"){$A[$a]=$P[$b++];}\n      }\n    if ($b!= ($\
#P+1)){add_warning (\"Could not thread sequence: $\
b $#P\");}\n    \n    $j= join ('', @A);\n    retu\
rn $j;\n  }\nsub pred2color\n  {\n    my $predP=sh\
ift;\n    my $alnP=shift;\n    my $out=shift;\n   \
 my $F=new FileHandle;\n    my $struc=vtmpnam();\n\
    my $aln=vtmpnam();\n    \n\n    output_fasta_s\
eq ($alnP, $aln);\n    my %p=%$predP;\n    \n    o\
pen ($F, \">$struc\");\n    \n    \n    foreach my\
 $s (keys(%p))\n      {\n	\n	print $F \">$s\\n\";\\
n	my $s=uc($p{$s}{seq});\n	\n	$s=~s/[Oo]/0/g;\n	$s\
=~s/[Ee]/0/g;\n	\n	$s=~s/[Ii]/5/g;\n	$s=~s/[Cc]/5/\
g;\n	\n	$s=~s/[Hh]/9/g;\n	\n	print $F \"$s\\n\";\n\
      }\n    close ($F);\n    \n    \n    \n    sa\
fe_system ( \"t_coffee -other_pg seq_reformat -in \
$aln -struc_in $struc -struc_in_f number_fasta -ou\
tput color_html -out $out\");\n    return;\n  }\n	\
  \n    \nsub display_fasta_seq\n  {\n    my $SR=s\
hift;\n    my %S=%$SR;\n    \n    foreach my $s (s\
ort{$S{$a}{index}<=>$S{$b}{index}}(keys (%S)))\n  \
    {\n	print STDERR \">$s\\n$S{$s}{seq}\\n\";\n  \
    }\n    close ($f);\n  }\nsub output_fasta_seq\\
n  {\n    my $SR=shift;\n    my $outfile=shift;\n \
   my $mode =shift;\n    my $f= new FileHandle;\n \
   my %S=%$SR;\n    \n    \n    open ($f, \">$outf\
ile\");\n    foreach my $s (sort{$S{$a}{index}<=>$\
S{$b}{index}}(keys (%S)))\n      {\n	my $seq=$S{$s\
}{seq};\n	if ( $mode eq \"seq\"){$seq=~s/\\-//g;}\\
n	print $f \">$s\\n$seq\\n\";\n      }\n    close \
($f);\n  }\n      \nsub read_fasta_seq \n  {\n    \
my $f=$_[0];\n    my %hseq;\n    my (@seq, @com, @\
name);\n    my ($a, $s,$nseq);\n    my $index;\n  \
  open (F, $f);\n    while (<F>)\n      {\n	$s.=$_\
;\n      }\n    close (F);\n\n    \n    @name=($s=\
~/>(\\S*).*\\n[^>]*/g);\n    \n    @seq =($s=~/>.*\
.*\\n([^>]*)/g);\n    @com =($s=~/>.*(.*)\\n([^>]*\
)/g);\n\n\n    $nseq=$#name+1;\n    \n  \n    for \
($a=0; $a<$nseq; $a++)\n      {\n	my $n=$name[$a];\
\n	my $s;\n	$hseq{$n}{name}=$n;\n	$s=$seq[$a];$s=~\
s/\\s//g;\n	$hseq{$n}{index}=++$index;\n	$hseq{$n}\
{seq}=$s;\n	$hseq{$n}{com}=$com[$a];\n      }\n   \
 return %hseq;\n  }\n\n\nsub file2head\n      {\n	\
my $file = shift;\n	my $size = shift;\n	my $f= new\
 FileHandle;\n	my $line;\n	open ($f,$file);\n	read\
 ($f,$line, $size);\n	close ($f);\n	return $line;\\
n      }\nsub file2tail\n      {\n	my $file = shif\
t;\n	my $size = shift;\n	my $f= new FileHandle;\n	\
my $line;\n	\n	open ($f,$file);\n	seek ($f,$size*-\
1, 2);\n	read ($f,$line, $size);\n	close ($f);\n	r\
eturn $line;\n      }\n\n\nsub vtmpnam\n      {\n	\
my $r=rand(100000);\n	my $f=\"file.$r.$$\";\n	whil\
e (-e $f)\n	  {\n	    $f=vtmpnam();\n	  }\n	push (\
@TMPFILE_LIST, $f);\n	return $f;\n      }\n\nsub m\
yexit\n  {\n    my $code=@_[0];\n    if ($CLEAN_EX\
IT_STARTED==1){return;}\n    else {$CLEAN_EXIT_STA\
RTED=1;}\n    ### ONLY BARE EXIT\n    exit ($code)\
;\n  }\nsub set_error_lock\n    {\n      my $name \
= shift;\n      my $pid=$$;\n\n      \n      &lock\
4tc ($$,\"LERROR\", \"LSET\", \"$$ -- ERROR: $name\
 $PROGRAM\\n\");\n      return;\n    }\nsub set_lo\
ck\n  {\n    my $pid=shift;\n    my $msg= shift;\n\
    my $p=getppid();\n    &lock4tc ($pid,\"LLOCK\"\
,\"LRESET\",\"$p$msg\\n\");\n  }\nsub unset_lock\n\
   {\n     \n    my $pid=shift;\n    &lock4tc ($pi\
d,\"LLOCK\",\"LRELEASE\",\"\");\n  }\nsub shift_lo\
ck\n  {\n    my $from=shift;\n    my $to=shift;\n \
   my $from_type=shift;\n    my $to_type=shift;\n \
   my $action=shift;\n    my $msg;\n    \n    if (\
!&lock4tc($from, $from_type, \"LCHECK\", \"\")){re\
turn 0;}\n    $msg=&lock4tc ($from, $from_type, \"\
LREAD\", \"\");\n    &lock4tc ($from, $from_type,\\
"LRELEASE\", $msg);\n    &lock4tc ($to, $to_type, \
$action, $msg);\n    return;\n  }\nsub isshellpid\\
n  {\n    my $p=shift;\n    if (!lock4tc ($p, \"LL\
OCK\", \"LCHECK\")){return 0;}\n    else\n      {\\
n	my $c=lock4tc($p, \"LLOCK\", \"LREAD\");\n	if ( \
$c=~/-SHELL-/){return 1;}\n      }\n    return 0;\\
n  }\nsub isrootpid\n  {\n    if(lock4tc (getppid(\
), \"LLOCK\", \"LCHECK\")){return 0;}\n    else {r\
eturn 1;}\n  }\nsub lock4tc\n	{\n	  my ($pid,$type\
,$action,$value)=@_;\n	  my $fname;\n	  my $host=h\
ostname;\n	  \n	  if ($type eq \"LLOCK\"){$fname=\\
"$LOCKDIR/.$pid.$host.lock4tcoffee\";}\n	  elsif (\
 $type eq \"LERROR\"){ $fname=\"$LOCKDIR/.$pid.$ho\
st.error4tcoffee\";}\n	  elsif ( $type eq \"LWARNI\
NG\"){ $fname=\"$LOCKDIR/.$pid.$host.warning4tcoff\
ee\";}\n	  \n	  if ($debug_lock)\n	    {\n	      p\
rint STDERR \"\\n\\t---lock4tc(tcg): $action => $f\
name =>$value (RD: $LOCKDIR)\\n\";\n	    }\n\n	  i\
f    ($action eq \"LCHECK\") {return -e $fname;}\n\
	  elsif ($action eq \"LREAD\"){return file2string\
($fname);}\n	  elsif ($action eq \"LSET\") {return\
 string2file ($value, $fname, \">>\");}\n	  elsif \
($action eq \"LRESET\") {return string2file ($valu\
e, $fname, \">\");}\n	  elsif ($action eq \"LRELEA\
SE\") \n	    {\n	      if ( $debug_lock)\n		{\n		 \
 my $g=new FileHandle;\n		  open ($g, \">>$fname\"\
);\n		  print $g \"\\nDestroyed by $$\\n\";\n		  c\
lose ($g);\n		  safe_system (\"mv $fname $fname.ol\
d\");\n		}\n	      else\n		{\n		  unlink ($fname);\
\n		}\n	    }\n	  return \"\";\n	}\n	\nsub file2st\
ring\n	{\n	  my $file=@_[0];\n	  my $f=new FileHan\
dle;\n	  my $r;\n	  open ($f, \"$file\");\n	  whil\
e (<$f>){$r.=$_;}\n	  close ($f);\n	  return $r;\n\
	}\nsub string2file \n    {\n    my ($s,$file,$mod\
e)=@_;\n    my $f=new FileHandle;\n    \n    open \
($f, \"$mode$file\");\n    print $f  \"$s\";\n    \
close ($f);\n  }\n\nBEGIN\n    {\n      srand;\n  \
  \n      $SIG{'SIGUP'}='signal_cleanup';\n      $\
SIG{'SIGINT'}='signal_cleanup';\n      $SIG{'SIGQU\
IT'}='signal_cleanup';\n      $SIG{'SIGILL'}='sign\
al_cleanup';\n      $SIG{'SIGTRAP'}='signal_cleanu\
p';\n      $SIG{'SIGABRT'}='signal_cleanup';\n    \
  $SIG{'SIGEMT'}='signal_cleanup';\n      $SIG{'SI\
GFPE'}='signal_cleanup';\n      \n      $SIG{'SIGK\
ILL'}='signal_cleanup';\n      $SIG{'SIGPIPE'}='si\
gnal_cleanup';\n      $SIG{'SIGSTOP'}='signal_clea\
nup';\n      $SIG{'SIGTTIN'}='signal_cleanup';\n  \
    $SIG{'SIGXFSZ'}='signal_cleanup';\n      $SIG{\
'SIGINFO'}='signal_cleanup';\n      \n      $SIG{'\
SIGBUS'}='signal_cleanup';\n      $SIG{'SIGALRM'}=\
'signal_cleanup';\n      $SIG{'SIGTSTP'}='signal_c\
leanup';\n      $SIG{'SIGTTOU'}='signal_cleanup';\\
n      $SIG{'SIGVTALRM'}='signal_cleanup';\n      \
$SIG{'SIGUSR1'}='signal_cleanup';\n\n\n      $SIG{\
'SIGSEGV'}='signal_cleanup';\n      $SIG{'SIGTERM'\
}='signal_cleanup';\n      $SIG{'SIGCONT'}='signal\
_cleanup';\n      $SIG{'SIGIO'}='signal_cleanup';\\
n      $SIG{'SIGPROF'}='signal_cleanup';\n      $S\
IG{'SIGUSR2'}='signal_cleanup';\n\n      $SIG{'SIG\
SYS'}='signal_cleanup';\n      $SIG{'SIGURG'}='sig\
nal_cleanup';\n      $SIG{'SIGCHLD'}='signal_clean\
up';\n      $SIG{'SIGXCPU'}='signal_cleanup';\n   \
   $SIG{'SIGWINCH'}='signal_cleanup';\n      \n   \
   $SIG{'INT'}='signal_cleanup';\n      $SIG{'TERM\
'}='signal_cleanup';\n      $SIG{'KILL'}='signal_c\
leanup';\n      $SIG{'QUIT'}='signal_cleanup';\n  \
    \n      our $debug_lock=$ENV{\"DEBUG_LOCK\"};\\
n      \n      \n      \n      \n      foreach my \
$a (@ARGV){$CL.=\" $a\";}\n      if ( $debug_lock \
){print STDERR \"\\n\\n\\n********** START PG: $PR\
OGRAM *************\\n\";}\n      if ( $debug_lock\
 ){print STDERR \"\\n\\n\\n**********(tcg) LOCKDIR\
: $LOCKDIR $$ *************\\n\";}\n      if ( $de\
bug_lock ){print STDERR \"\\n --- $$ -- $CL\\n\";}\
\n      \n	     \n      \n      \n    }\nsub flush\
_error\n  {\n    my $msg=shift;\n    return add_er\
ror ($EXIT_FAILURE,$$, $$,getppid(), $msg, $CL);\n\
  }\nsub add_error \n  {\n    my $code=shift;\n   \
 my $rpid=shift;\n    my $pid=shift;\n    my $ppid\
=shift;\n    my $type=shift;\n    my $com=shift;\n\
    \n    $ERROR_DONE=1;\n    lock4tc ($rpid, \"LE\
RROR\",\"LSET\",\"$pid -- ERROR: $type\\n\");\n   \
 lock4tc ($$, \"LERROR\",\"LSET\", \"$pid -- COM: \
$com\\n\");\n    lock4tc ($$, \"LERROR\",\"LSET\",\
 \"$pid -- STACK: $ppid -> $pid\\n\");\n   \n    r\
eturn $code;\n  }\nsub add_warning \n  {\n    my $\
rpid=shift;\n    my $pid =shift;\n    my $command=\
shift;\n    my $msg=\"$$ -- WARNING: $command\\n\"\
;\n    print STDERR \"$msg\";\n    lock4tc ($$, \"\
LWARNING\", \"LSET\", $msg);\n  }\n\nsub signal_cl\
eanup\n  {\n    print dtderr \"\\n**** $$ (tcg) wa\
s killed\\n\";\n    &cleanup;\n    exit ($EXIT_FAI\
LURE);\n  }\nsub clean_dir\n  {\n    my $dir=@_[0]\
;\n    if ( !-d $dir){return ;}\n    elsif (!($dir\
=~/tmp/)){return ;}#safety check 1\n    elsif (($d\
ir=~/\\*/)){return ;}#safety check 2\n    else\n  \
    {\n	`rm -rf $dir`;\n      }\n    return;\n  }\\
nsub cleanup\n  {\n    #print stderr \"\\n----tc: \
$$ Kills $PIDCHILD\\n\";\n    #kill (SIGTERM,$PIDC\
HILD);\n    my $p=getppid();\n    $CLEAN_EXIT_STAR\
TED=1;\n    \n    \n    \n    if (&lock4tc($$,\"LE\
RROR\", \"LCHECK\", \"\"))\n      {\n	my $ppid=get\
ppid();\n	if (!$ERROR_DONE) \n	  {\n	    &lock4tc(\
$$,\"LERROR\", \"LSET\", \"$$ -- STACK: $p -> $$\\\
n\");\n	    &lock4tc($$,\"LERROR\", \"LSET\", \"$$\
 -- COM: $CL\\n\");\n	  }\n      }\n    my $warnin\
g=&lock4tc($$, \"LWARNING\", \"LREAD\", \"\");\n  \
  my $error=&lock4tc($$,  \"LERROR\", \"LREAD\", \\
"\");\n    #release error and warning lock if root\
\n    \n    if (isrootpid() && ($warning || $error\
) )\n      {\n	\n	print STDERR \"**************** \
Summary *************\\n$error\\n$warning\\n\";\n\\
n	&lock4tc($$,\"LERROR\",\"RELEASE\",\"\");\n	&loc\
k4tc($$,\"LWARNING\",\"RELEASE\",\"\");\n      } \\
n    \n    \n    foreach my $f (@TMPFILE_LIST)\n  \
    {\n	if (-e $f){unlink ($f);} \n      }\n    fo\
reach my $d (@TMPDIR_LIST)\n      {\n	clean_dir ($\
d);\n      }\n    #No More Lock Release\n    #&loc\
k4tc($$,\"LLOCK\",\"LRELEASE\",\"\"); #release loc\
k \n\n    if ( $debug_lock ){print STDERR \"\\n\\n\
\\n********** END PG: $PROGRAM ($$) *************\\
\n\";}\n    if ( $debug_lock ){print STDERR \"\\n\\
\n\\n**********(tcg) LOCKDIR: $LOCKDIR $$ ********\
*****\\n\";}\n  }\nEND \n  {\n    \n    &cleanup()\
;\n  }\n   \n\nsub safe_system \n{\n  my $com=shif\
t;\n  my $ntry=shift;\n  my $ctry=shift;\n  my $pi\
d;\n  my $status;\n  my $ppid=getppid();\n  if ($c\
om eq \"\"){return 1;}\n  \n  \n\n  if (($pid = fo\
rk ()) < 0){return (-1);}\n  if ($pid == 0)\n    {\
\n      set_lock($$, \" -SHELL- $com (tcg)\");\n  \
    exec ($com);\n    }\n  else\n    {\n      lock\
4tc ($$, \"LLOCK\", \"LSET\", \"$pid\\n\");#update\
 parent\n      $PIDCHILD=$pid;\n    }\n  if ($debu\
g_lock){printf STDERR \"\\n\\t .... safe_system (f\
asta_seq2hmm)  p: $$ c: $pid COM: $com\\n\";}\n\n \
 waitpid ($pid,WTERMSIG);\n\n  shift_lock ($pid,$$\
, \"LWARNING\",\"LWARNING\", \"LSET\");\n\n  if ($\
? == $EXIT_FAILURE || lock4tc($pid, \"LERROR\", \"\
LCHECK\", \"\"))\n    {\n      if ($ntry && $ctry \
<$ntry)\n	{\n	  add_warning ($$,$$,\"$com failed [\
retry: $ctry]\");\n	  lock4tc ($pid, \"LRELEASE\",\
 \"LERROR\", \"\");\n	  return safe_system ($com, \
$ntry, ++$ctry);\n	}\n      elsif ($ntry == -1)\n	\
{\n	  if (!shift_lock ($pid, $$, \"LERROR\", \"LWA\
RNING\", \"LSET\"))\n	    {\n	      add_warning ($\
$,$$,\"$com failed\");\n	    }\n	  else\n	    {\n	\
      lock4tc ($pid, \"LRELEASE\", \"LERROR\", \"\\
");\n	    }\n	  return $?;}\n      else\n	{\n	  if\
 (!shift_lock ($pid,$$, \"LERROR\",\"LERROR\", \"L\
SET\"))\n	    {\n	      myexit(add_error ($EXIT_FA\
ILURE,$$,$pid,getppid(), \"UNSPECIFIED system\", $\
com));\n	    }\n	}\n    }\n  return $?;\n}\n\nsub \
check_configuration \n    {\n      my @l=@_;\n    \
  my $v;\n      foreach my $p (@l)\n	{\n	  \n	  if\
   ( $p eq \"EMAIL\")\n	    { \n	      if ( !($EMA\
IL=~/@/))\n		{\n		add_warning($$,$$,\"Could Not Us\
e EMAIL\");\n		myexit(add_error ($EXIT_FAILURE,$$,\
$$,getppid(),\"EMAIL\",\"$CL\"));\n	      }\n	    \
}\n	  elsif( $p eq \"INTERNET\")\n	    {\n	      i\
f ( !&check_internet_connection())\n		{\n		  myexi\
t(add_error ($EXIT_FAILURE,$$,$$,getppid(),\"INTER\
NET\",\"$CL\"));\n		}\n	    }\n	  elsif( $p eq \"w\
get\")\n	    {\n	      if (!&pg_is_installed (\"wg\
et\") && !&pg_is_installed (\"curl\"))\n		{\n		  m\
yexit(add_error ($EXIT_FAILURE,$$,$$,getppid(),\"P\
G_NOT_INSTALLED:wget\",\"$CL\"));\n		}\n	    }\n	 \
 elsif( !(&pg_is_installed ($p)))\n	    {\n	      \
myexit(add_error ($EXIT_FAILURE,$$,$$,getppid(),\"\
PG_NOT_INSTALLED:$p\",\"$CL\"));\n	    }\n	}\n    \
  return 1;\n    }\nsub pg_is_installed\n  {\n    \
my @ml=@_;\n    my $r, $p, $m;\n    my $supported=\
0;\n    \n    my $p=shift (@ml);\n    if ($p=~/::/\
)\n      {\n	if (safe_system (\"perl -M$p -e 1\")=\
=$EXIT_SUCCESS){return 1;}\n	else {return 0;}\n   \
   }\n    else\n      {\n	$r=`which $p 2>/dev/null\
`;\n	if ($r eq \"\"){return 0;}\n	else {return 1;}\
\n      }\n  }\n\n\n\nsub check_internet_connectio\
n\n  {\n    my $internet;\n    my $tmp;\n    &chec\
k_configuration ( \"wget\"); \n    \n    $tmp=&vtm\
pnam ();\n    \n    if     (&pg_is_installed    (\\
"wget\")){`wget www.google.com -O$tmp >/dev/null 2\
>/dev/null`;}\n    elsif  (&pg_is_installed    (\"\
curl\")){`curl www.google.com -o$tmp >/dev/null 2>\
/dev/null`;}\n    \n    if ( !-e $tmp || -s $tmp <\
 10){$internet=0;}\n    else {$internet=1;}\n    i\
f (-e $tmp){unlink $tmp;}\n\n    return $internet;\
\n  }\nsub check_pg_is_installed\n  {\n    my @ml=\
@_;\n    my $r=&pg_is_installed (@ml);\n    if (!$\
r && $p=~/::/)\n      {\n	print STDERR \"\\nYou Mu\
st Install the perl package $p on your system.\\nR\
UN:\\n\\tsudo perl -MCPAN -e 'install $pg'\\n\";\n\
      }\n    elsif (!$r)\n      {\n	myexit(flush_e\
rror(\"\\nProgram $p Supported but Not Installed o\
n your system\"));\n      }\n    else\n      {\n	r\
eturn 1;\n      }\n  }\n\n\n\n","\n\n\n\n\nmy $FMO\
DEL =\"\"; \nmy $TMPDIR = \"/tmp\";\n\n\n\n\nmy $N\
UCALPH = \"ACGTUNRYMKSWHBVD\";\nmy $PRIMNUCALPH = \
\"ACGTUN\";\nuse vars qw($NUCALPH $PRIMNUCALPH $TM\
PDIR);\n\n\nmy $errmsg;\nuse vars qw($errmsg);\n\n\
\n\nuse Getopt::Long;\nuse Cwd;\nuse File::Basenam\
e;\nuse File::Temp qw/ tempfile tempdir /;\nuse Fi\
le::Copy;\nuse File::Path;\n\n\n\nsub usage(;$)\n{\
\n    my ($errmsg) = @_;\n    my $myname = basenam\
e($0);\n\n    if ($errmsg) {\n        print STDERR\
 \"ERROR: $errmsg\\n\";\n    }\n\n    print STDERR\
 << \"EOF\";\n    \n$myname: align two sequences b\
y means of consan\\'s sfold\nUsage:\n $myname -i f\
ile -o file -d path\nOptions:\n -i|--in : pairwise\
 input sequence file\n -o|--out: output alignment\\
n -d|--directory containing data\n\nEOF\n}\n\nsub \
read_stk_aln \n  {\n    my $f=$_[0];\n    my ($seq\
, $id);\n    \n    my %hseq;\n\n    open (STK, \"$\
f\");\n    while (<STK>)\n      {\n	if ( /^#/ || /\
^\\/\\// || /^\\s*$/){;}\n	else\n	  {\n	    ($id,$\
seq)=/(\\S+)\\s+(\\S+)/;\n	    $hseq{$id}{'seq'}.=\
$seq;\n	  }\n      }\n    close (STK);\n    return\
 %hseq;\n  }\nsub read_fasta_seq \n  {\n    my $f=\
$_[0];\n    my %hseq;\n    my (@seq, @com, @name);\
\n    my ($a, $s,$nseq);\n\n    open (F, $f);\n   \
 while (<F>)\n      {\n	$s.=$_;\n      }\n    clos\
e (F);\n\n    \n    @name=($s=~/>(.*).*\\n[^>]*/g)\
;\n    \n    @seq =($s=~/>.*.*\\n([^>]*)/g);\n    \
@com =($s=~/>.*(.*)\\n([^>]*)/g);\n\n    \n    $ns\
eq=$#name+1;\n    \n    for ($a=0; $a<$nseq; $a++)\
\n      {\n	my $n=$name[$a];\n	$hseq{$n}{name}=$n;\
\n	$hseq{$n}{seq}=$seq[$a];\n	$hseq{$n}{com}=$com[\
$a];\n      }\n    return %hseq;\n  }\n\n\n\nsub s\
fold_parseoutput($$)\n{\n    my ($frawout, $foutfa\
) = @_;\n    my %haln;\n    my ($fstk, $cmd, $id);\
\n    open FOUTFA, \">$foutfa\";\n    \n    $fstk \
= $frawout . \".stk\";\n    \n    # first line of \
raw out contains info\n    # remaining stuff is st\
ockholm formatted\n    $cmd = \"sed -e '1d' $frawo\
ut\";\n    system(\"$cmd > $fstk\");\n    if ($? !\
= 0) {\n        $errmsg = \"command failed with ex\
it status $?.\";\n        $errmsg .=  \"Command wa\
s \\\"$cmd\\\"\";\n        return -1;\n    }\n\n  \
  # this gives an error message. just ignore it...\
\n    %haln=read_stk_aln ( $fstk);\n    foreach $i\
 (keys (%haln))\n      {\n	my $s;\n	$s=$haln{$i}{'\
seq'};\n	$s =~ s/\\./-/g;\n	print FOUTFA \">$i\\n$\
s\\n\";\n      }\n    close FOUTFA;\n    return 0;\
\n}\n\n\n\n\nsub sfold_wrapper($$$$)\n{\n    \n   \
 my ($fs1, $fs2, $fmodel, $foutfa) = @_;\n    \n\n\
    my ($cmd, $frawout, $ferrlog, $freadme, $ftime\
log, $fstk);\n\n    # add  basename($fmsqin) (unkn\
own here!)\n    $frawout = \"sfold.log\";\n    $fe\
rrlog = \"sfold.err\";\n    $ftimelog = \"sfold.ti\
me\";\n    $freadme =  \"sfold.README\";\n    $fst\
k = \"sfold.stk\";\n    \n    # prepare execution.\
..\n    #\n    # ./tmp is essential for dswpalign\\
n    # otherwise you'll get a segfault\n    mkdir \
\"./tmp\";\n    \n    $cmd = \"sfold -m $fmodel $f\
s1 $fs2\";\n    open(FREADME,\">$freadme\");\n    \
print FREADME \"$cmd\\n\"; \n    close(FREADME);\n\
\n    # and go\n    #\n    system(\"/usr/bin/time \
-p -o $ftimelog $cmd >$frawout 2>$ferrlog\");\n   \
 if ($? != 0) {\n        $errmsg = \"command faile\
d with exit status $?\";\n        $errmsg .= \"com\
mand was \\\"$cmd\\\". See \" . getcwd . \"\\n\";\\
n        return -1;\n    }\n\n    return sfold_par\
seoutput($frawout, $foutfa);\n}\n\n\n\n\n\n\n\nmy \
($help, $fmsqin, $fmsaout);\nGetOptions(\"help\"  \
=> \\$help,\n           \"in=s\" => \\$fmsqin,\n  \
         \"out=s\" => \\$fmsaout,\n	   \"data=s\" \
=> \\$ref_dir);\n\n\n\nif ($help) {\n    usage();\\
n    exit(0);\n}\nif (! defined($fmsqin)) {\n    u\
sage('missing input filename');\n    exit(1);\n}\n\
if (! defined($fmsaout)) {\n    usage('missing out\
put filename');\n    exit(1);\n\n}\nif (scalar(@AR\
GV)) {\n    usage('Unknown remaining args');\n    \
exit(1);\n}\n\n$FMODEL = \"$ref_dir/mix80.mod\";\n\
if (! -e \"$FMODEL\") {\n    die(\"couldn't find s\
fold grammar model file. Expected $FMODEL\\n\");\n\
}\n\n\nmy %hseq=read_fasta_seq ($fmsqin);\nmy $id;\
\n\nforeach $id (keys(%hseq))\n  {\n    push(@seq_\
array, $hseq{$id});\n  }\n\nif ( scalar(@seq_array\
) != 2 ) {\n    die(\"Need *exactly* two sequences\
 as input (pairwise alignment!).\")\n}\n\n\n\nmy (\
$sec, $min, $hour, $mday, $mon, $year, $wday, $yda\
y, $isdst) = localtime(time);\nmy $datei = sprintf\
(\"%4d-%02d-%02d\", $year+1900, $mon+1, $mday);\nm\
y $templ = basename($0) . \".\" . $datei . \".pid-\
\" . $$ . \".XXXXXX\";\nmy $wd = tempdir ( $templ,\
 DIR => $TMPDIR);\n\ncopy($fmsqin, \"$wd/\" . base\
name($fmsqin) . \".org\"); # for reproduction\ncop\
y($FMODEL, \"$wd\");\nmy $fmodel = basename($FMODE\
L);\nmy $orgwd = getcwd;\nchdir $wd;\n\n\n\nmy @se\
pseqfiles;\nforeach $id (keys(%hseq)) {\n    my ($\
seq, $orgseq, $fname, $sout);\n    $seq=$hseq{$id}\
{'seq'};\n    \n    $fname = basename($fmsqin) . \\
"_$id.fa\";\n    # replace funnies in file/id name\
 (e.g. \"/\" \" \" etc)\n    $fname =~ s,[/ ],_,g;\
\n    open (PF, \">$fname\");\n    print (PF \">$i\
d\\n$seq\\n\");\n    close (PF);\n\n    push(@seps\
eqfiles, $fname);\n}\n\nmy ($f1, $f2, $fout);\n$f1\
 = $sepseqfiles[0];\n$f2 = $sepseqfiles[1];\n$fout\
 = $wd . basename($fmsqin) . \".out.fa\";\nif (sfo\
ld_wrapper($f1, $f2, $fmodel, \"$fout\") != 0) {\n\
    printf STDERR \"ERROR: See logs in $wd\\n\";\n\
    exit(1);\n} else {\n    chdir $orgwd;\n    cop\
y($fout, $fmsaout);\n    rmtree($wd);\n   exit(0);\
\n}\n","\nuse Env qw(HOST);\nuse Env qw(HOME);\nus\
e Env qw(USER);\n\n\n$tmp=clean_cr ($ARGV[0]);\nop\
en (F, $tmp);\n\nwhile ( <F>)\n  {\n    my $l=$_;\\
n    if ( $l=~/^# STOCKHOLM/){$stockholm=1;}\n    \
elsif ( $stockholm && $l=~/^#/)\n      {\n	$l=~/^#\
(\\S+)\\s+(\\S+)\\s+(\\S*)/g;\n	$l=\"_stockholmhas\
ch_$1\\_stockholmspace_$2 $3\\n\";\n      }\n    $\
file.=$l;\n  }\nclose (F);\nunlink($tmp);\n$file1=\
$file;\n\n$file=~s/\\#/_hash_symbol_/g;\n$file=~s/\
\\@/_arobase_symbol_/g;\n\n\n$file=~s/\\n[\\.:*\\s\
]+\\n/\\n\\n/g;\n\n$file=~s/\\n[ \\t\\r\\f]+(\\b)/\
\\n\\1/g;\n\n\n$file=~s/(\\n\\S+)(\\s+)(\\S)/\\1_b\
lank_\\3/g;\n\n$file=~s/[ ]//g;\n$file=~s/_blank_/\
 /g;\n\n\n\n$file =~s/\\n\\s*\\n/#/g;\n\n$file.=\"\
#\";\n$file =~s/\\n/@/g;\n\n\n\n\n@blocks=split /\\
\#/, $file;\nshift (@blocks);\n@s=split /\\@/, $bl\
ocks[0];\n$nseq=$#s+1;\n\n\n\n$file=join '@', @blo\
cks;\n@lines=split /\\@/,$file;\n\n$c=0;\n\nforeac\
h $l (@lines)\n  {\n    if (!($l=~/\\S/)){next;}\n\
    elsif ($stockholm && ($l=~/^\\/\\// || $l=~/ST\
OCKHOLM/)){next;}#get read of STOCHOLM Terminator\\
n   \n    $l=~/(\\S+)\\s+(\\S*)/g;\n    $n=$1; $s=\
$2;\n    \n    $seq[$c].=$s;\n    $name[$c]=$n;\n \
   $c++;\n    \n    if ( $c==$nseq){$c=0;}\n    \n\
  } \n\nif ( $c!=0)\n      {\n	print STDERR \"ERRO\
R: $ARGV[0] is NOT an MSA in Clustalw format: make\
 sure there is no blank line within a block [ERROR\
]\\n\";\n	exit (EXIT_FAILURE);\n      }\n\nfor ($a\
=0; $a< $nseq; $a++)\n  {\n    $name[$a]=cleanstri\
ng ($name[$a]);\n    $seq[$a]=cleanstring ($seq[$a\
]);\n    $seq[$a]=breakstring($seq[$a], 60);\n    \
\n    $line=\">$name[$a]\\n$seq[$a]\\n\";\n    \n \
   print \"$line\";\n  }\nexit (EXIT_SUCCESS);\n\n\
sub cleanstring\n  {\n    my $s=@_[0];\n    $s=~s/\
_hash_symbol_/\\#/g;\n    $s=~s/_arobase_symbol_/\\
\@/g;\n    $s=~s/[ \\t]//g;\n    return $s;\n  }\n\
sub breakstring\n  {\n    my $s=@_[0];\n    my $si\
ze=@_[1];\n    my @list;\n    my $n,$ns, $symbol;\\
n    \n    @list=split //,$s;\n    $n=0;$ns=\"\";\\
n    foreach $symbol (@list)\n      {\n	if ( $n==$\
size)\n	  {\n	    $ns.=\"\\n\";\n	    $n=0;\n	  }\\
n	$ns.=$symbol;\n	$n++;\n      }\n    return $ns;\\
n    }\n\nsub clean_cr\n  {\n    my $f=@_[0];\n   \
 my $file;\n    \n    $tmp=\"f$.$$\";\n    \n    \\
n    open (IN, $f);\n    open (OUT, \">$tmp\");\n \
   \n    while ( <IN>)\n      {\n	$file=$_;\n	$fil\
e=~s/\\r\\n/\\n/g;\n	$file=~s/\\n\\r/\\n/g;\n	$fil\
e=~s/\\r\\r/\\n/g;\n	$file=~s/\\r/\\n/g;\n	print O\
UT \"$file\";\n      }\n    \n    close (IN);\n   \
 close (OUT);\n    return $tmp;\n  }\n","use stric\
t;\nuse FileHandle;\nuse Env qw(HOST);\nuse Env qw\
(HOME);\nuse Env qw(USER);\n\nmy $format=file2form\
at ($ARGV[0]);\nif    ($format eq \"clustalw\"){cl\
ustalw2name_seq($ARGV[0]);}\nelsif ($format eq \"f\
asta\")   {fasta2name_seq($ARGV[0]);}\nelsif ($for\
mat eq \"msf\")   {msf2name_seq($ARGV[0]);}\nelsif\
 ($format eq \"phylip\")   {phylip2name_seq($ARGV[\
0]);}\nelsif ($format eq \"nameseq\") {display_fil\
e ($ARGV[0]);}\n \nexit (0);\n\nsub file2format\n \
 {\n    my $f=shift;\n    \n    my $l=file2n_lines\
($f,2);\n    \n    if ( $l=~/^CLUSTAL/){return \"c\
lustalw\";}\n    elsif ($l=~/^SAGA/){return \"clus\
talw\";}\n    elsif ($l=~/^>/){return \"fasta\";}\\
n    elsif ($l=~/^PileUp/){return \"msf\";}\n    e\
lsif ($l=~/\\s+\\d+\\s+\\d+\\s/){return \"phylip\"\
;}\n    elsif ($l=~/\\#NAMESEQ_01/){return \"names\
eq\";}\n    else \n      {\n	print STDERR \"ERROR:\
 $f FILE is NOT a supported format [ERROR]\\n\";\n\
	exit (1);\n      }\n  }\nsub display_file\n    {\\
n       my $file=shift;\n       my $F= new FileHan\
dle;\n       open ($F, $file);\n       while (<$F>\
){print \"$_\";}\n       close ($F);\n     }\nsub \
phylip2name_seq\n    {\n      my $file=shift;\n   \
   my $F= new FileHandle;\n      my ($seq, $name,$\
seq);\n      my $query_start=-1;\n      my $query_\
end=-1;\n      my $in_aln=0;\n      my %list;\n   \
   my ($first,$seq,$name, $cn, $nseq, $l,%len);\n \
     \n      open ($F, $file);\n      <$F>;\n     \
 $l=$_;\n      $l=~/\\s*(\\d+)\\s*(\\d+)/;\n      \
$first=1;\n      $cn=0;\n      while (<$F>)\n	{\n	\
  my $l=$_;\n	  if (!($l=~/\\S/))\n	    {\n	      \
$cn=0;\n	      $first=0;\n	    }\n	  elsif ($first\
==1)\n	    {\n	      $l=~/\\s*(\\S+)(.*)/;\n	     \
 my $name=$1;\n	      my $seq=$2;\n	      chomp ($\
seq);\n	      $seq=~s/\\s//g;\n	      $list{$cn}{'\
name'}=$name;\n	      $list{$cn}{'seq'}.=$seq;\n	 \
     $cn++;\n	      $nseq++;\n	    }\n	  else\n	  \
  {\n	      chomp ($l);\n	      $l=~s/\\s//g;\n	  \
    $list{$cn}{'seq'}.=$l;\n	      $cn++;\n	    }\\
n	}\n      close ($F);\n      \n      print \"#NAM\
ESEQ_01\\n\";\n      print \"# $nseq\\n\";\n      \
for (my $a=0; $a<$nseq; $a++)\n	{\n	  my $nl=lengt\
h ($list{$a}{'name'});\n	  my $sl=length ($list{$a\
}{'seq'});\n	  print \">$nl $sl $list{$a}{'name'} \
$list{$a}{'seq'}\\n\";\n	}\n    }\n      \nsub msf\
2name_seq\n    {\n      my $file=shift;\n      my \
$F= new FileHandle;\n      my ($seq, $name,$seq);\\
n      my $query_start=-1;\n      my $query_end=-1\
;\n      my $in_aln=0;\n      my %list;\n      my \
($seq,$name, $n, $nseq, $l,%len);\n      \n      o\
pen ($F, $file);\n      while (<$F>)\n	{\n	  if ( \
/\\/\\//){$in_aln=1;}\n	  elsif ( $in_aln && /(\\S\
+)\\s+(.*)/)\n	    {\n	      $name=$1;\n	      $se\
q=$2;\n	      $seq=~s/\\s//g;\n	      $seq=~s/\\~/\
\\-/g;\n	      $seq=~s/\\./\\-/g;\n	      if ( $li\
st{$n}{'name'} && $list{$n}{'name'} ne $name)\n		{\
\n		  print \"$list{$n}{'name'} Vs $name\";\n		  \\
n		  exit (1);\n		}\n	      else\n		{\n		  $list{$\
n}{'name'}= $name;\n		}\n	      \n	      $list{$n}\
{'seq'}=$list{$n}{'seq'}.$seq;\n	      \n	      $n\
seq=++$n;\n	      \n	    }\n	  else\n	    {$n=0;}\\
n	}\n      close ($F);\n      print \"#NAMESEQ_01\\
\n\";\n      print \"# $nseq\\n\";\n      for (my \
$a=0; $a<$nseq; $a++)\n	{\n	  my $nl=length ($list\
{$a}{'name'});\n	  my $sl=length ($list{$a}{'seq'}\
);\n	  print \">$nl $sl $list{$a}{'name'} $list{$a\
}{'seq'}\\n\";\n	}\n    }\n    \nsub fasta2name_se\
q\n    {\n      my $file=shift;\n      my $F= new \
FileHandle;\n      my ($seq, $name,$n,$l,%len);\n \
     \n      open ($F, $file);\n      while (<$F>)\
\n	{\n	  if ( /^>(\\S+)/){$n++;$seq=\"\";$name=$1;\
}\n	  else\n	    {\n	      $l=$_;\n	      chomp ($\
l);\n	      $seq.=$l;\n	      $len{$name}=length($\
seq);\n	    }\n	}\n      close ($F);\n      print \
\"#NAMESEQ_01\\n\";\n      print \"# $n\";\n      \
\n      open ($F, $file);\n      while (<$F>)\n	{\\
n	  if ( /^>(\\S+)(.*)\\n/)\n	    {\n	      my $na\
me=$1;\n	      my $comment=$2;\n	      my $nl=leng\
th ($name);\n	      my $sl=$len{$name};\n	      if\
 ($comment)\n		{\n		  $comment=~s/^\\s+//g;\n		  m\
y $cl=length ($comment);\n		  print \"\\n#$cl $com\
ment\\n\";\n		}\n	      print \"\\n>$nl $sl $name \
\";\n	    }\n	  else\n	    {\n	      $l=$_;\n	    \
  chomp ($l);\n	      print \"$l\";\n	    }\n	}\n \
     print \"\\n\";\n      close ($F);\n    }\nsub\
 clustalw2name_seq\n  {\n    my $fname=shift;\n   \
 my ($file1, $file);\n    my (@blocks, @lines,@s, \
$n,$nseq, $c);\n    my (@name, @seq);\n    my $F= \
new FileHandle;\n    my $stockholm;\n    \n    ope\
n ($F, $fname);\n    \n    while ( <$F>)\n      {\\
n	my $l=$_;\n	$l=clean_cr($l);\n	if ( $l=~/^# STOC\
KHOLM/){$stockholm=1;}\n	elsif ( $stockholm && $l=\
~/^#/)\n	  {\n	    $l=~/^#(\\S+)\\s+(\\S+)\\s+(\\S\
*)/g;\n	    $l=\"_stockholmhasch_$1\\_stockholmspa\
ce_$2 $3\\n\";\n	  }\n	$file.=$l;\n      }\n    cl\
ose ($F);\n        \n    #Protect # and @\n    $fi\
le=~s/\\#/_hash_symbol_/g;\n    $file=~s/\\@/_arob\
ase_symbol_/g;\n    \n    \n    #Remove annotation\
\n    $file=~s/\\n[\\.:*\\s]+\\n/\\n\\n/g;\n    \n\
    #Remove White spaces before the sequence name\\
n    $file=~s/\\n[ \\t\\r\\f]+(\\b)/\\n\\1/g;\n   \
 \n    \n    #Remove Internal Blanks\n    $file=~s\
/(\\n\\S+)(\\s+)(\\S)/\\1_blank_\\3/g;\n    \n    \
$file=~s/[ ]//g;\n    $file=~s/_blank_/ /g;\n    \\
n    \n    #Identify Double Blank lines\n    \n   \
 $file =~s/\\n\\s*\\n/#/g;\n    \n    $file.=\"#\"\
;\n    $file =~s/\\n/@/g;\n    \n    \n    \n    \\
n    #count nseq\n    @blocks=split /\\#/, $file;\\
n    shift (@blocks);\n    @s=split /\\@/, $blocks\
[0];\n    $nseq=$#s+1;\n    \n    #Merge all the s\
equences and split every Nseq\n    \n    \n    $fi\
le=join '@', @blocks;\n    @lines=split /\\@/,$fil\
e;\n    \n    $c=0;\n    \n    foreach my $l (@lin\
es)\n      {\n	my ($n, $s);\n	\n	if (!($l=~/\\S/))\
{next;}\n	elsif ($stockholm && ($l=~/^\\/\\// || $\
l=~/STOCKHOLM/)){next;}#get read of STOCHOLM Termi\
nator\n	\n	$l=~/(\\S+)\\s+(\\S*)/g;\n	$n=$1; $s=$2\
;\n	\n	$seq[$c].=$s;\n	$name[$c]=$n;\n	$c++;\n	\n	\
if ( $c==$nseq){$c=0;}\n	\n      } \n    \n    if \
( $c!=0)\n      {\n	print STDERR \"ERROR: $fname i\
s NOT an MSA in Clustalw format: make sure there i\
s no blank line within a block [ERROR]\\n\";\n	exi\
t (1);\n      }\n    print \"#NAMESEQ_01\\n\";\n  \
  print \"# $nseq\\n\";\n    for (my $a=0; $a< $ns\
eq; $a++)\n      {\n	$name[$a]=cleanstring ($name[\
$a]);\n	$seq[$a]=cleanstring ($seq[$a]);\n	my $ln=\
length ($name[$a]);\n	my $ls=length ($seq[$a]);\n	\
print \">$ln $ls $name[$a] $seq[$a]\\n\";\n      }\
\n  }\nsub cleanstring\n    {\n      my $s=@_[0];\\
n      $s=~s/_hash_symbol_/\\#/g;\n      $s=~s/_ar\
obase_symbol_/\\@/g;\n      $s=~s/[ \\t]//g;\n    \
  return $s;\n    }\n\nsub clean_cr\n  {\n    my $\
f=shift;\n    $f=~s/\\r\\n/\\n/g;\n    $f=~s/\\n\\\
r/\\n/g;\n    $f=~s/\\r\\r/\\n/g;\n    $f=~s/\\r/\\
\n/g;\n    return $f;\n  }\n\nsub file2n_lines\n  \
  {\n      my $file=shift;\n      my $nl=shift;\n \
     my $ret;\n      my $F=new FileHandle;\n      \
my $n=0;\n      open ($F, $file);\n\n      while (\
<$F>)\n	{\n	  $ret.=$_;\n	  $n++;\n	  \n	  if ($n>\
=$n){close ($F); return $ret;}\n	}\n      close ($\
F);\n      return $ret;\n    }\n","use strict;\nus\
e FileHandle;\nuse Env qw(HOST);\nuse Env qw(HOME)\
;\nuse Env qw(USER);\nmy %name;\nmy $nseq;\nmy $fa\
sta;\nif ($ARGV[2] eq \"-fasta\"){$fasta=1;}\nmy $\
F= new FileHandle;\n\nopen ($F, $ARGV[1]);\nwhile(\
<$F>)\n  {\n    my $l=$_;\n    if ($l=~/^#/){;}\n \
   elsif (($l=~/\\d+\\s+\\d+\\s+(\\S+)\\s+(\\S+)/)\
)\n      {\n	my $n=$1;\n	$name{$1}++;\n      }\n  \
}\nclose ($F);\n\nopen ($F, $ARGV[0]);\nwhile(<$F>\
)\n  {\n    my $l=$_;\n    if ($l=~/^#/){;}\n    e\
lsif ($l=~/\\d+\\s+\\d+\\s+(\\S+)\\s+(\\S+)/)\n   \
   {\n	my $n=$1;\n	$name{$n}++;\n	if ($name{$n}==2\
){$nseq++;}\n      }\n  }\nclose ($F);\n\nif (!$fa\
sta && $nseq>0)\n  {\n    print \"#NAMESEQ_01\\n\"\
;\n    print \"# $nseq\\n\";\n  }\nopen ($F, $ARGV\
[0]);\nwhile(<$F>)\n  {\n    my $l=$_;\n    if ($l\
=~/^#/){;}\n    elsif ($l=~/.\\d+\\s+\\d+\\s+(\\S+\
)\\s+(\\S+)/)\n      {\n	my $n=$1;\n	my $s=$2;\n	i\
f ($name{$n}==2)\n	  {\n	    if ($fasta)\n	      {\
\n		print \">$n\\n$s\\n\";\n	      }\n	    else\n	\
      {\n		print \"$l\";\n	      }\n	  }\n      }\\
n  }\nclose ($F);\nexit (0);\n\n\n","use Env qw(HO\
ST);\nuse Env qw(HOME);\nuse Env qw(USER);\n\n\n$q\
uery_start=-1;\n$query_end=-1;\n\nwhile (<>)\n  {\\
n    if ( /\\/\\//){$in_aln=1;}\n    elsif ( $in_a\
ln && /(\\S+)\\s+(.*)/)\n      {\n\n\n	$name=$1;\n\
	\n\n	$seq=$2;\n	$seq=~s/\\s//g;\n        $seq=~s/\
\\~/\\-/g;\n	$seq=~s/\\./\\-/g;\n	if ( $list{$n}{'\
name'} && $list{$n}{'name'} ne $name)\n	  {\n	    \
print \"$list{$n}{'name'} Vs $name\";\n	    \n	   \
 exit (EXIT_FAILURE);\n	  }\n	else\n	  {\n	    $li\
st{$n}{'name'}= $name;\n	  }\n\n	$list{$n}{'seq'}=\
$list{$n}{'seq'}.$seq;\n	\n	$nseq=++$n;\n	\n      \
}\n    else\n      {$n=0;}\n  }\n\n\nfor ($a=0; $a\
<$nseq; $a++)\n  {\n    print \">$list{$a}{'name'}\
\\n$list{$a}{'seq'}\\n\";\n  }\n      \n","$run_an\
yway=2;\nmy $msaf=\"msa.in.tmp.$$\";\nmy $msaoutf=\
\"msa.out.tmp.$$\";\nmy $err=\"msa.out.err.$$\";\n\
open  (F, $ARGV[0]);\nopen  (OUT, \">$msaf\");\n$n\
seq=0;\nwhile (<F>)\n  {\n    $l=$_;\n    if ( $l=\
~/^>(\\S+)/)\n      {\n	$s=$seqname{$nseq++}=$1;\n\
	print OUT \"$l\";\n	\n      }\n    else \n      {\
\n	$l=uc($l);\n	print OUT \"$l\";\n      }\n  }\n\\
nclose (F);\nclose(OUT);\n\nsystem (\"msa $msaf > \
$msaoutf 2>$err\");\nopen (F, \"$msaoutf\");\n$rea\
d=0;\n$cn=0;\nwhile (<F>)\n  {\n    $l=$_;\n    if\
 ($read)\n      {\n	if ($l=~/End gaps not penalize\
d/){$read=0;}\n	elsif (!($l=~/\\S/))\n	  {\n	    $\
cn=0;\n	  }\n	else\n	  {\n	    \n	    chomp ($l);\\
n	    $seqal{$cn++}.=$l;\n	    $tot++;\n	  }\n    \
  }\n    elsif ($l=~/Optimal Multiple Alignment/)\\
n      {\n	$read=1;\n      }\n  }\nclose (F);\n\ni\
f ($tot<1 && $run_anyway==1)\n  {\n    print STDER\
R \"\\nWarning: MSA returned a NULL file -- Use T-\
Coffee instead\\n\";\n    open (F,$err);\n    whil\
e (<F>){print \"$_\";}\n      \n    system (\"t_co\
ffee -seq $msaf -outfile $ARGV[1]  -quiet\");\n  }\
\nelsif ($tot<1 && $run_anyway==2)\n  {\n    \n   \
 \n    $nseq/=2;\n    $nseq=int ($nseq);\n    if (\
$nseq<2){$nseq=2;}\n    print \"RUN MSA with NSeq=\
$nseq\\n\";\n    #print (\"t_coffee -dpa -dpa_nseq\
 $nseq -seq $ARGV[0] -dpa_tree codnd -outfile $ARG\
V[1] -dpa_method msa_msa\");\n    system (\"t_coff\
ee -dpa -dpa_nseq $nseq -seq $ARGV[0] -dpa_tree co\
dnd -outfile $ARGV[1] -dpa_method msa_msa>/dev/nul\
l\");\n\n  }\nelsif ($tot<1)\n  {\n    exit (EXIT_\
FAILURE);\n  }\nelse\n  {\n    open (OUT, \">$ARGV\
[1]\");\n    for ($a=0; $a<$nseq;$a++)\n      {\n	\
print OUT \">$seqname{$a}\\n$seqal{$a}\\n\";\n    \
  }\n    close (OUT);\n  }\n\n\n\nunlink ($msaf);\\
nunlink ($msaoutf);\nunlink ($err);\n","use strict\
;\nuse Cwd;\nuse File::Basename;\nmy $test=0;\n\nm\
y $tmpdir=\"/tmp/tco/aligners/upp/\";\nmymkdir ($t\
mpdir);\n\n\n\nif ($ARGV[0] eq \"one\")\n  {\n    \
seq2msa ($ARGV[1], $ARGV[2]);\n  }\nelsif ($ARGV[0\
] eq \"all\")\n  {\n    listseq2listmsa ($ARGV[1])\
;\n  }\n\nsub listseq2listmsa\n  {\n    my $list=s\
hift;\n    my $cdir = getcwd;\n    my $dir=random_\
string(10);\n    $dir=\"$tmpdir/$dir/\";\n    my %\
h;\n    my $n;\n    mkdir  ($dir);\n\n    open (F,\
 $list);\n    while (<F>)\n      {\n        my $l=\
$_;\n\n        chomp($l);\n        my @f=split (/\\
\s+/, $l);\n	if ( -e $f[0])\n          {\n        \
    $h{$n}{in}=$f[0];\n            ($h{$n}{name},$\
h{$n}{path})=fileparse ($f[0]);\n            $h{$n\
}{NFin}= \"$dir/$h{$n}{name}.seq\";\n	    \n      \
      $h{$n}{NFout}=\"$dir/$h{$n}{name}.aln\";\n\n\
            $h{$n}{out}=$f[1];\n\n            fast\
a2fastaupp ($h{$n}{in}, $h{$n}{NFin});\n          \
  $n++;\n          }\n      }\n    close (F);\n   \
 chdir ($dir);\n    \n    if (!$test)\n      {\n	s\
ystem (\"fbname=\\$(basename `ls *.seq` .seq); \\\\
n             run_upp.py -s \\${fbname}.seq -m ami\
no --cpu 1 -d outdir -o \\${fbname}.aln; \\\n     \
        mv outdir/\\${fbname}.aln_alignment.fasta \
\\${fbname}.aln;\");\n      }\n    \n    foreach m\
y $n (keys (%h))\n      {\n	if ($test)\n	  {\n	   \
 system (\"cp $h{$n}{NFin} $h{$n}{NFout}\");\n	   \
 print \"$h{$n}{NFin} $h{$n}{NFout} $h{$n}{out}\\n\
\";\n	  }\n        fastaupp2fasta ($h{$n}{NFout},$\
h{$n}{out});\n      }\n    chdir ($cdir);\n  }\n\n\
sub seq2msa\n    {\n      my ($in, $out)=@_;\n    \
  my $cdir=getcwd;\n      \n      \n      if (!($i\
n=~/\\//)){$in=$cdir.\"/\".$in;}\n      if (!($out\
=~/\\//)){$out=$cdir.\"/\".$out;}\n      \n      m\
y $file=random_string(10);\n      $file=\"$tmpdir/\
$file\";\n      open (F, \">$file\");\n      print\
 F \"$in $out\\n\";\n      close (F);\n      \n   \
   return listseq2listmsa ($file);\n    }\n	\nsub \
fasta2fastaupp\n  {\n    my ($in, $out)=@_;\n    m\
y ($name, $seq, $n);\n    \n    if (!-e $in){retur\
n;}\n    \n    open (IN, \"$in\");\n    open (OUT,\
 \">$out\");\n    local $/ = \"\\n>\";  # read by \
FASTA record\n    \n    while (<IN>)\n      {\n	my\
 $l=$_;\n	$l=~s/>//g;\n	$l=\">\".$l;\n	\n	$l=~/^>(\
.*)/;\n	$name=$1;\n	\n	$l=~s/^>*.+\\n//;\n	$l=~s/\\
\n//g;\n	$seq=$l;\n	\n	$seq=~s/u/x/g;\n	$seq=~s/U/\
X/g;\n	print OUT \">$name\\n$seq\\n\";\n	$n++;\n  \
    }\n    if ($n==2)\n      {\n	print OUT \">fake\
_seq4upp\\n$seq\\n\";\n      }\n    close (IN);\n \
   close (OUT);\n    local $/=\"\\n\";\n  }\n\nsub\
 fastaupp2fasta\n  {\n    my ($in, $out)=@_;\n    \
my ($name, $seq, $n);\n    \n    if (!-e $in){retu\
rn;}\n    \n    open (IN, \"$in\");\n    open (OUT\
, \">$out\");\n    local $/ = \"\\n>\";  # read by\
 FASTA record\n    \n    while (<IN>)\n      {\n	m\
y $l=$_;\n	$l=~s/>//g;\n	$l=\">\".$l;\n	\n	$l=~/^>\
(.*)/;\n	$name=$1;\n	\n	$l=~s/^>*.+\\n//;\n	$l=~s/\
\\n//g;\n	$seq=$l;\n	\n	$seq=~s/x/u/g;\n	$seq=~s/X\
/U/g;\n	\n	if (!($name=~/fake_seq4upp/))\n	  {\n	 \
   print OUT \">$name\\n$seq\\n\";\n	  }\n      }\\
n    close (IN);\n    close (OUT);\n    local $/=\\
"\\n\";\n  }\n\nsub random_string\n    {\n      my\
 $len=shift;\n      my @chars = (\"A\"..\"Z\", \"a\
\"..\"z\");\n      my $string;\n      $string .= $\
chars[rand @chars] for 1..$len;\n      return $str\
ing;\n    }\n\nsub mymkdir\n      {\n	my $d=shift;\
\n	my $cd='/';\n	\n	foreach my $e (split (/\\//, $\
d))\n	  {\n	    $cd.=\"$e/\";\n	    if ( !-d $cd){\
mkdir ($cd);}\n	  }\n	return;\n      }\n      \n		\
	  \n      \n","use strict;\nuse Cwd;\nuse File::B\
asename;\n\n\nmy $tmpdir=\"/tmp/tco/aligners/clust\
alo/\";\nmymkdir ($tmpdir);\n\n\n\nif ($ARGV[0] eq\
 \"one\")\n  {\n    seq2msa ($ARGV[1], $ARGV[2]);\\
n  }\nelsif ($ARGV[0] eq \"all\")\n  {\n    listse\
q2listmsa ($ARGV[1]);\n  }\n\n\n\nsub listseq2list\
msa\n  {\n    my $list=shift;\n    my $cdir = getc\
wd;\n    my $dir=random_string(10);\n    $dir=\"$t\
mpdir/$dir/\";\n    my %h;\n    my $n;\n    mkdir \
 ($dir);\n    \n    open (F, $list);\n    while (<\
F>)\n      {\n	my $l=$_;\n\n	chomp($l);\n	my @f=sp\
lit (/\\s+/, $l);\n	#print \"$l: 0:$f[0], 1:$f[1]\\
\n\";\n	if ( -e $f[0])\n	  {\n	    $h{$n}{in}=$f[0\
];\n	    ($h{$n}{name},$h{$n}{path})=fileparse ($f\
[0]);\n	    $h{$n}{NFin}= \"$dir/$h{$n}{name}.seq4\
nf\";\n	    $h{$n}{NFout}=\"$dir/$h{$n}{name}.aln\\
";\n	    \n	    $h{$n}{out}=$f[1];\n	    \n	    tr\
anslate_fasta_seq (\"uU\", \"X\",$h{$n}{in}, $h{$n\
}{NFin});\n	    $n++;\n	  }\n      }\n    close (F\
);\n    \n    \n    chdir ($dir);\n    dump_nf (\"\
nf\");\n    dump_config ();\n   \n    #system (\"n\
extflow run nf  --name \\'*.seq4nf\\' >/dev/null 2\
>/dev/null\");\n    system (\"nextflow run nf  --n\
ame \\'*.seq4nf\\'\");\n    foreach my $n (keys (%\
h))\n      {\n	translate_fasta_seq (\"uU\", \"X\",\
$h{$n}{NFout},$h{$n}{out});\n      }\n    chdir ($\
cdir);\n  }\nsub seq2msa\n    {\n      my ($in, $o\
ut)=@_;\n      my $cdir=getcwd;\n      \n      \n \
     if (!($in=~/\\//)){$in=$cdir.\"/\".$in;}\n   \
   if (!($out=~/\\//)){$out=$cdir.\"/\".$out;}\n  \
    \n      my $file=random_string(10);\n      $fi\
le=\"$tmpdir/$file\";\n      open (F, \">$file\");\
\n      print F \"$in $out\\n\";\n      close (F);\
\n      \n      return listseq2listmsa ($file);\n \
   }\n	\nsub seq2msa_old\n  {\n    my ($in, $out)=\
@_;\n    my $cdir = getcwd;\n    my $dir=random_st\
ring(10);\n    $dir=\"/tmp/upp.nf4tcoffee/$dir\";\\
n    my $seq=random_string(10);\n    $seq.=\".fa\"\
;\n    my $aln=$seq;\n    $aln.=\".aln\";\n    \n \
   mkdir ($dir);\n    translate_fasta_seq (\"uU\",\
 \"X\",$in, \"$dir/$seq\");\n    chdir ($dir);\n  \
  \n    dump_nf (\"nf\");\n    dump_config ();\n  \
  print \"IN: $in OUT: $cdir/$out\\nDIR: $dir\\nne\
xtflow run nf  --name \\'*.fa\\' \\n\";\n    syste\
m (\"nextflow run nf  --name \\'*.fa\\' \");\n    \
print \"$dir/$aln $cdir/$out\\n\";\n    translate_\
fasta_seq (\"xX\", \"U\",$aln, \"$cdir/$out\");\n \
   chdir ($cdir);\n   } \nsub translate_fasta_seq\\
n  {\n    my ($from, $to, $in, $out)=@_;\n    my $\
n;\n    my $skip;\n    my $l;\n    my $cseq;\n    \
if (!-e $in){return;}\n    \n    open (IN, \"$in\"\
);\n    open (OUT, \">$out\");\n   \n    while (<I\
N>)\n      {\n	$l=$_;\n	if ($l=~\">\"){$n++;$cseq=\
\"\";}\n	else { $l=~s/[$from]/$to/;$cseq.=$l;}\n\n\
	if ($skip){$skip=0;}\n	elsif ($l=~/>fake_seq/){$s\
kip=1;}\n	else\n	  {\n	    print OUT \"$l\";\n	  }\
\n      }\n    if ($n==2 && $from eq \"uU\")\n    \
  {\n	print OUT \">fake_seq\\n$cseq\\n\";\n      }\
\n    close (IN);\n    close (OUT);\n  }\n\nsub du\
mp_config\n    {\n      open (F, \">nextflow.confi\
g\");\n\n      print F \"docker.enabled = true\\n\\
";\n      print F \"process.container = \\'cbcrg/b\
enchfam_large_scale\\'\\n\";\n      close (F);\n  \
  }\n\nsub dump_nf\n  {\n    my $nff=shift;\n    o\
pen (F,\">$nff\");\n    print F \"#!/usr/bin/env n\
extflow\\n\";\n    print F \"params.base_dir=\\\".\
/\\\"\\n\";\n    print F \"params.out_dir=\\\"./\\\
\"\\n\";\n    print F \"Channel.fromPath(params.na\
me)\\n\";\n    print F \"\\t.map{ tuple(it.baseNam\
e, it) }\\n\";\n    \n    print F \"\\t.set{ file_\
names_1 }\\n\";\n    print F \"process clustalo_al\
ign{\\n\";\n    print F \"\\tpublishDir params.out\
_dir, mode: \\\"copy\\\"\\n\";\n    print F \"tag \
\\\"\\${name}\\\"\";\n    print F \"\\n\";\n    pr\
int F \"\\tinput:\\n\";\n    print F \"\\tset name\
, file(seq_file) from file_names_1\\n\";\n    prin\
t F \"\\toutput:\\n\";\n    print F \"\\tfile \\\"\
\\${name}.aln\\\"\\n\";\n    print F \"\\n\";\n   \
 print F \" \\\"\\\"\\\"\\n\";\n    print F \" clu\
stalo -i \\$seq_file -o \\${name}.aln\\n\";\n    p\
rint F \"\\\"\\\"\\\"\\n\\n\";\n    print F \"}\\n\
\";\n    close (F);\n  }\n\nsub random_string\n   \
 {\n      my $len=shift;\n      my @chars = (\"A\"\
..\"Z\", \"a\"..\"z\");\n      my $string;\n      \
$string .= $chars[rand @chars] for 1..$len;\n     \
 return $string;\n    }\n\nsub mymkdir\n      {\n	\
my $d=shift;\n	my $cd='/';\n	\n	foreach my $e (spl\
it (/\\//, $d))\n	  {\n	    $cd.=\"$e/\";\n	    if\
 ( !-d $cd){mkdir ($cd);}\n	  }\n	return;\n      }\
\n      \n			  \n      \n","\nmy $msaf=\"msa.in.tm\
p.$$\";\nmy $msaoutf=\"msa.out.tmp.$$\";\nmy $cost\
=\"blosum62.tmp.$$\";\n\nopen  (F, $ARGV[0]);\nope\
n  (OUT, \">$msaf\");\n$nseq=0;\nwhile (<F>)\n  {\\
n    $l=$_;\n    if ( $l=~/^>(\\S+)/)\n      {\n	m\
y $simple=\"Seq$nseq\";\n	$s=$seqname{$nseq++}=$1;\
\n	$translate{$simple}=$s;\n	\n	print OUT \">$simp\
le\\n\";\n	\n      }\n    else\n      {\n	$l=uc($l\
);\n	print OUT \"$l\";\n      }\n  }\nclose (F);\n\
close(OUT);\n\ndump_blosum ($cost);\nsystem (\"dca\
 -c $cost -q $msaf> $msaoutf 2>/dev/null\");\nopen\
 (F, \"$msaoutf\");\nopen (OUT, \">$ARGV[1]\");\n\\
n$read=0;\nwhile (<F>)\n  {\n    $l=$_;\n    if ($\
l=~/^>(\\S+)/)\n      {\n	$read=1;\n	$name=$transl\
ate{$1};\n	print OUT \">$name\\n\";\n      }\n    \
elsif ($read && ($l=~/\\S/))\n      {\n	print OUT \
\"$l\";\n      }\n    else\n      {\n	$read=0;\n  \
    }\n  }\nclose (F);\n\nunlink ($cost);\nunlink \
($msaf);\nunlink ($msaoutf);\n\nsub dump_blosum\n \
 {\n    my $f=shift;\n    open (F, \">$f\");\n\n  \
  print F \"6\\n\";\n    print F \"- -   0\\n\";\n\
    print F \"W W   0\\n\";\n    print F \"Y Y   4\
\\n\";\n    print F \"F F   5\\n\";\n    print F \\
"V V   7\\n\";\n    print F \"L L   7\\n\";\n    p\
rint F \"I I   7\\n\";\n    print F \"M M   6\\n\"\
;\n    print F \"K K   6\\n\";\nprint F \"R R   6\\
\n\";\n    print F \"H H   3\\n\";\n    print F \"\
Q Q   6\\n\";\n    print F \"E E   6\\n\";\n    pr\
int F \"D D   5\\n\";\n    print F \"N N   5\\n\";\
\n    print F \"G G   5\\n\";\n    print F \"A A  \
 7\\n\";\n    print F \"P P   4\\n\";\n    print F\
 \"T T   6\\n\";\n    print F \"S S   7\\n\";\n   \
 print F \"C C   2\\n\";\n    print F \"- C  10 \\\
n\";\n    print F \"- S  10\\n\";\n    print F \"-\
 T  10 \\n\";\n    print F \"- P  10\\n\";\n    pr\
int F \"- A  10 \\n\";\n    print F \"- G  10\\n\"\
;\n    print F \"- N  10 \\n\";\n    print F \"- D\
  10\\n\";\n    print F \"- E  10 \\n\";\n    prin\
t F \"- Q  10\\n\";\nprint F \"- H  10 \\n\";\n   \
 print F \"- R  10\\n\";\n    print F \"- K  10 \\\
n\";\n    print F \"- M  10\\n\";\n    print F \"-\
 I  10 \\n\";\n    print F \"- L  10\\n\";\n    pr\
int F \"- V  10 \\n\";\n    print F \"- F  10\\n\"\
;\n    print F \"- Y  10 \\n\";\n    print F \"- W\
  10\\n\";\n    print F \"W C  13 \\n\";\n    prin\
t F \"W S  14\\n\";\n    print F \"W T  13 \\n\";\\
n    print F \"W P  15\\n\";\n    print F \"W A  1\
4 \\n\";\n    print F \"W G  13\\n\";\n    print F\
 \"W N  15 \\n\";\n    print F \"W D  15\\n\";\n  \
  print F \"W E  14 \\n\";\n    print F \"W Q  13\\
\n\";\n    print F \"W H  13 \\n\";\n    print F \\
"W R  14\\n\";\n    print F \"W K  14 \\n\";\n    \
print F \"W M  12\\n\";\n    print F \"W I  14 \\n\
\";\n    print F \"W L  13\\n\";\n    print F \"W \
V  14 \\n\";\n    print F \"W F  10\\n\";\n    pri\
nt F \"W Y   9 \\n\";\n    print F \"Y C  13\\n\";\
\n    print F \"Y S  13 \\n\";\n    print F \"Y T \
 13\\n\";\n    print F \"Y P  14 \\n\";\n    print\
 F \"Y A  13\\n\";\n    print F \"Y G  14 \\n\";\n\
    print F \"Y N  13\\n\";\n    print F \"Y D  14\
 \\n\";\n    print F \"Y E  13\\n\";\n    print F \
\"Y Q  12 \\n\";\n    print F \"Y H   9\\n\";\n   \
 print F \"Y R  13 \\n\";\n    print F \"Y K  13\\\
n\";\n    print F \"Y M  12 \\n\";\n    print F \"\
Y I  12\\n\";\n    print F \"Y L  12 \\n\";\n    p\
rint F \"Y V  12\\n\";\n    print F \"Y F   8 \\n\\
";\n    print F \"F C  13\\n\";\nprint F \"F S  13\
 \\n\";\n    print F \"F T  13\\n\";\n    print F \
\"F P  15 \\n\";\n    print F \"F A  13\\n\";\n   \
 print F \"F G  14 \\n\";\n    print F \"F N  14\\\
n\";\n    print F \"F D  14 \\n\";\n    print F \"\
F E  14\\n\";\n    print F \"F Q  14 \\n\";\n    p\
rint F \"F H  12\\n\";\n    print F \"F R  14 \\n\\
";\n    print F \"F K  14\\n\";\n    print F \"F M\
  11 \\n\";\n    print F \"F I  11\\n\";\n    prin\
t F \"F L  11 \\n\";\n    print F \"F V  12\\n\";\\
n    print F \"V C  12 \\n\";\n    print F \"V S  \
13\\n\";\n    print F \"V T  11 \\n\";\n    print \
F \"V P  13\\n\";\n    print F \"V A  11 \\n\";\n \
   print F \"V G  14\\n\";\n    print F \"V N  14 \
\\n\";\n    print F \"V D  14\\n\";\nprint F \"V E\
  13 \\n\";\nprint F \"V Q  13\\n\";\nprint F \"V \
H  14 \\n\";\nprint F \"V R  14\\n\";\nprint F \"V\
 K  13 \\n\";\nprint F \"V M  10\\n\";\nprint F \"\
V I   8 \\n\";\nprint F \"V L  10\\n\";\nprint F \\
"L C  12 \\n\";\nprint F \"L S  13\\n\";\nprint F \
\"L T  12 \\n\";\nprint F \"L P  14\\n\";\nprint F\
 \"L A  12 \\n\";\nprint F \"L G  15\\n\";\nprint \
F \"L N  14 \\n\";\nprint F \"L D  15\\n\";\nprint\
 F \"L E  14 \\n\";\nprint F \"L Q  13\\n\";\nprin\
t F \"L H  14 \\n\";\nprint F \"L R  13\\n\";\npri\
nt F \"L K  13 \\n\";\nprint F \"L M   9\\n\";\npr\
int F \"L I   9 \\n\";\nprint F \"I C  12\\n\";\np\
rint F \"I S  13 \\n\";\nprint F \"I T  12\\n\";\n\
print F \"I P  14 \\n\";\nprint F \"I A  12\\n\";\\
nprint F \"I G  15 \\n\";\nprint F \"I N  14\\n\";\
\nprint F \"I D  14 \\n\";\nprint F \"I E  14\\n\"\
;\nprint F \"I Q  14 \\n\";\nprint F \"I H  14\\n\\
";\nprint F \"I R  14 \\n\";\nprint F \"I K  14\\n\
\";\nprint F \"I M  10 \\n\";\nprint F \"M C  12\\\
n\";\nprint F \"M S  12 \\n\";\nprint F \"M T  12\\
\n\";\nprint F \"M P  13 \\n\";\nprint F \"M A  12\
\\n\";\nprint F \"M G  14 \\n\";\nprint F \"M N  1\
3\\n\";\nprint F \"M D  14 \\n\";\nprint F \"M E  \
13\\n\";\nprint F \"M Q  11 \\n\";\nprint F \"M H \
 13\\n\";\nprint F \"M R  12 \\n\";\nprint F \"M K\
  12\\n\";\nprint F \"K C  14 \\n\";\nprint F \"K \
S  11\\n\";\nprint F \"K T  12 \\n\";\nprint F \"K\
 P  12\\n\";\nprint F \"K A  12 \\n\";\nprint F \"\
K G  13\\n\";\nprint F \"K N  11 \\n\";\nprint F \\
"K D  12\\n\";\nprint F \"K E  10 \\n\";\nprint F \
\"K Q  10\\n\";\nprint F \"K H  12 \\n\";\nprint F\
 \"K R   9\\n\";\nprint F \"R C  14 \\n\";\nprint \
F \"R S  12\\n\";\nprint F \"R T  12 \\n\";\nprint\
 F \"R P  13\\n\";\nprint F \"R A  12 \\n\";\nprin\
t F \"R G  13\\n\";\nprint F \"R N  11 \\n\";\npri\
nt F \"R D  13\\n\";\nprint F \"R E  11 \\n\";\npr\
int F \"R Q  10\\n\";\nprint F \"R H  11 \\n\";\np\
rint F \"H C  14\\n\";\nprint F \"H S  12 \\n\";\n\
print F \"H T  13\\n\";\nprint F \"H P  13 \\n\";\\
nprint F \"H A  13\\n\";\nprint F \"H G  13 \\n\";\
\nprint F \"H N  10\\n\";\nprint F \"H D  12 \\n\"\
;\nprint F \"H E  11\\n\";\nprint F \"H Q  11 \\n\\
";\nprint F \"Q C  14\\n\";\nprint F \"Q S  11 \\n\
\";\nprint F \"Q T  12\\n\";\nprint F \"Q P  12 \\\
n\";\nprint F \"Q A  12\\n\";\nprint F \"Q G  13 \\
\n\";\nprint F \"Q N  11\\n\";\nprint F \"Q D  11 \
\\n\";\nprint F \"Q E   9\\n\";\nprint F \"E C  15\
 \\n\";\nprint F \"E S  11\\n\";\nprint F \"E T  1\
2 \\n\";\nprint F \"E P  12\\n\";\nprint F \"E A  \
12 \\n\";\nprint F \"E G  13\\n\";\nprint F \"E N \
 11 \\n\";\nprint F \"E D   9\\n\";\nprint F \"D C\
  14 \\n\";\nprint F \"D S  11\\n\";\nprint F \"D \
T  12 \\n\";\nprint F \"D P  12\\n\";\nprint F \"D\
 A  13 \\n\";\nprint F \"D G  12\\n\";\nprint F \"\
D N  10 \\n\";\nprint F \"N C  14\\n\";\nprint F \\
"N S  10 \\n\";\nprint F \"N T  11\\n\";\nprint F \
\"N P  13 \\n\";\nprint F \"N A  13\\n\";\nprint F\
 \"N G  11 \\n\";\nprint F \"G C  14\\n\";\nprint \
F \"G S  11 \\n\";\nprint F \"G T  13\\n\";\nprint\
 F \"G P  13 \\n\";\nprint F \"G A  11\\n\";\nprin\
t F \"A C  11 \\n\";\nprint F \"A S  10\\n\";\npri\
nt F \"A T  11 \\n\";\nprint F \"A P  12\\n\";\npr\
int F \"P C  14 \\n\";\nprint F \"P S  12\\n\";\np\
rint F \"P T  12 \\n\";\nprint F \"T C  12\\n\";\n\
print F \"T S  10 \\n\";\nprint F \"S C  12\\n\";\\
nclose (F);\n    return;\n  }\n    \n","\nuse Env \
qw(HOST);\nuse Env qw(HOME);\nuse Env qw(USER);\n\\
n                                                 \
       \nuse strict;                              \
               \nuse warnings;\nuse diagnostics;\n\
\nmy $in_hit_list, my $in_aln=0, my(%name_list)=()\
,my (%list)=(),my $n_seq=0; my $test=0;\nmy($j)=0,\
 my $n=0, my $nom, my $lg_query, my %vu=();\n\nope\
n (F, \">tmp\");\n\n$/=\"\\n\";\nwhile (<>)\n{\n  \
  print F $_;\n    if($_ =~ /Query=\\s*(.+?)\\s/i)\
 { $nom=$1;}\n\n    if ( /Sequences producing sign\
ificant alignments/){$in_hit_list=1;}\n    \n    i\
f ($_=~ /^pdb\\|/i) { $_=~ s/pdb\\|//g; }\n    if \
($_=~ /^(1_\\d+)\\s+\\d+/) { $_=~ s/$1/QUERY/;}\n \
     \n    if ( /^(\\S+).+?\\s+[\\d.]+\\s+([\\de.-\
]+)\\s+$/ && $in_hit_list)	\n    {\n	my($id)=$1; #\
 \n	$id=~ s/\\|/_/g; #\n	if ($id =~ /.+_$/) { chop\
($id) }; #\n	$name_list{$n_seq++}=$id;\n	$name_lis\
t{$n_seq-1}=~ s/.*\\|//g;     \n    }\n  \n    if \
(/query/i) {$in_aln=1;}\n    if ( /^(\\S+)\\s+(\\d\
+)\\s+([a-zA-Z-]+)\\s+(\\d+)/ || /^(\\S+)(\\s+)(\\\
-+)(\\s+)/ && ($in_aln == 1))\n    {\n	my $name=$1\
;\n	my $start=$2;\n	my $seq=$3;\n	my $end=$4;\n		\\
n	if ($name =~ /QUERY/i) { $lg_query=length($seq);\
 }\n\n	unless ($test > $n) #m\n	{\n	    my(@seqq)=\
 split('',$seq);\n	    my($gap_missing)= scalar(@s\
eqq);\n	    \n	    while ($gap_missing != $lg_quer\
y)  { unshift (@seqq,\"-\"); $gap_missing= scalar(\
@seqq); }\n	    $seq=join('',@seqq);  #m\n	}\n	\n	\
if ($name =~ /QUERY/i)\n	{\n	    $n=0; %vu=(); $j=\
0;\n	    $list{$n}{'real_name'}=\"$nom\";\n	}	\n	e\
lse\n	{\n	    unless (exists $vu{$name}) { ++$j;}	\
\n	    $list{$n}{'real_name'}=$name_list{$j-1};\n	\
}\n		\n	$list{$n}{'name'}=$name;\n\n	$seq=~tr/a-z/\
A-Z/;\n	$list{$n}{'seq'}=$list{$n}{'seq'};\n	$list\
{$n}{'seq'}.=$seq;\n\n	$n++;\n	$vu{$name}++;\n	$te\
st++;\n   } \n    \n}\n\nmy @numero=();\n\nfor (my\
 $a=0; $a<$n; $a++) #m\n{\n    my $long=length($li\
st{0}{'seq'});  \n    my $long1= length($list{$a}{\
'seq'});\n  \n    while ($long1 ne $long)\n    {\n\
	$list{$a}{'seq'}.=\"-\";\n	$long1= length ($list{\
$a}{'seq'});\n    } \n \n    push (@numero,\"$list\
{$a}{'name'} $list{$a}{'real_name'}\\n\");\n}\n\nm\
y %dejavu=();\n\n\nfor (my $i=0; $i<=$#numero; $i+\
+)\n{\n    my $s=\">$list{$i}{'real_name'}\\n$list\
{$i}{'seq'}\\n\";\n    my $k=0;\n    \n    if (exi\
sts $dejavu{$numero[$i]}) {next;}\n    else\n    {\
	\n	for ($j=0; $j<$n ; $j++)\n	{\n	    if (\"$nume\
ro[$i]\" eq \"$numero[$j]\" && $j != $i )\n	    {\\
n		++$k;\n		$s .=\">$list{$j}{'real_name'}\\n$list\
{$j}{'seq'}\\n\";\n	    }\n	}	\n    }\n    \n    i\
f ($k>0) \n    {\n	my $cons;\n	open (SOR,\">tempo_\
aln2cons\"); print SOR $s;  close SOR ;\n	open (CO\
M,\"t_coffee -other_pg seq_reformat -in tempo_aln2\
cons -action +aln2cons +upper |\") ; \n     	while\
 (<COM>)\n	{	\n	    if (/^>/) { $cons =\">$list{$i\
}{'real_name'}\\n\"; next;}\n	    $_=~ s/\\n//g;\n\
	    $cons .=$_;\n	}\n	close COM; unlink (\"tempo_\
aln2cons\");\n	print $cons,\"\\n\"; print F $cons,\
\"\\n\";\n    }	\n    else  { print $s;  print F $\
s; }\n    \n    $dejavu{$numero[$i]}++;\n} #m\n\ne\
xit;\n\n\n\n\n\n\n\n\n\n\n\n","use Env;\n\n\n$tmp_\
dir=\"\";\n$init_dir=\"\";\n$program=\"tc_generic_\
method.pl\";\n\n$blast=@ARGV[0];\n\n$name=\"query\\
";$seq=\"\";\n%p=blast_xml2profile($name,$seq,100,\
 0, 0, $blast);\n&output_profile (%p);\n\n\nsub ou\
tput_profile\n  {\n    my (%profile)=(@_);\n    my\
 ($a);\n    for ($a=0; $a<$profile{n}; $a++)\n    \
  {\n	\n	print \">$profile{$a}{name} $profile{$a}{\
comment}\\n$profile{$a}{seq}\\n\";\n      }\n    r\
eturn;\n  }\nsub file_contains \n  {\n    my ($fil\
e, $tag, $max)=(@_);\n    my ($n);\n    $n=0;\n   \
 \n    if ( !-e $file && ($file =~/$tag/)) {return\
 1;}\n    elsif ( !-e $file){return 0;}\n    else \
\n      {\n	open (FC, \"$file\");\n	while ( <FC>)\\
n	  {\n	    if ( ($_=~/$tag/))\n	      {\n		close \
(FC);\n		return 1;\n	      }\n	    elsif ($max && \
$n>$max)\n	      {\n		close (FC);\n		return 0;\n	 \
     }\n	    $n++;\n	  }\n      }\n    close (FC);\
\n    return 0;\n  }\n	    \n	  \nsub file2string\\
n  {\n    my $f=@_[0];\n    my $string, $l;\n    o\
pen (F,\"$f\");\n    while (<F>)\n      {\n\n	$l=$\
_;\n	#chomp ($l);\n	$string.=$l;\n      }\n    clo\
se (F);\n    $string=~s/\\r\\n//g;\n    $string=~s\
/\\n//g;\n    return $string;\n  }\n\n\n\nsub tag2\
value \n  {\n    \n    my $tag=(@_[0]);\n    my $w\
ord=(@_[1]);\n    my $return;\n    \n    $tag=~/$w\
ord=\"([^\"]+)\"/;\n    $return=$1;\n    return $r\
eturn;\n  }\n      \nsub hit_tag2pdbid\n  {\n    m\
y $tag=(@_[0]);\n    my $pdbid;\n       \n    $tag\
=~/id=\"(\\S+)\"/;\n    $pdbid=$1;\n    $pdbid=~s/\
_//;\n    return $pdbid;\n  }\nsub id2pdbid \n  {\\
n    my $id=@_[0];\n  \n    if ($id =~/pdb/)\n    \
  {\n	$id=~/pdb(.*)/;\n	$id=$1;\n      }\n    $id=\
~s/[|�_]//g;\n    return $id;\n  }\nsub set_blast_\
type \n  {\n    my $file =@_[0];\n    if (&file_co\
ntains ($file,\"EBIApplicationResult\",100)){$BLAS\
T_TYPE=\"EBI\";}\n    elsif (&file_contains ($file\
,\"NCBI_BlastOutput\",100)) {$BLAST_TYPE=\"NCBI\";\
}\n    else\n      {\n	$BLAST_TYPE=\"\";\n      }\\
n    return $BLAST_TYPE;\n  }\nsub blast_xml2profi\
le \n  {\n    my ($name,$seq,$maxid, $minid, $minc\
ov, $file)=(@_);\n    my (%p, $a, $string, $n);\n \
   \n\n\n    if ($BLAST_TYPE eq \"EBI\" || &file_c\
ontains ($file,\"EBIApplicationResult\",100)){%p=e\
bi_blast_xml2profile(@_);}\n    elsif ($BLAST_TYPE\
 eq \"NCBI\" || &file_contains ($file,\"NCBI_Blast\
Output\",100)){%p=ncbi_blast_xml2profile(@_);}\n  \
  else \n      {\n	print \"************ ERROR: Bla\
st Returned an unknown XML Format ****************\
******\";\n	die;\n      }\n    for ($a=0; $a<$p{n}\
; $a++)\n      {\n	my $name=$p{$a}{name};\n	$p{$na\
me}{seq}=$p{$a}{seq};\n      }\n    return %p;\n  \
}\nsub ncbi_blast_xml2profile \n  {\n    my ($name\
,$seq,$maxid, $minid, $mincov, $string)=(@_);\n   \
 my ($L,$l, $a,$b,$c,$d,$nhits,@identifyerL);\n   \
 \n    \n    $seq=~s/[^a-zA-Z]//g;\n    $L=length \
($seq);\n    \n    %hit=&xml2tag_list ($string, \"\
Hit\");\n    \n    \n    for ($nhits=0,$a=0; $a<$h\
it{n}; $a++)\n      {\n	my ($ldb,$id, $identity, $\
expectation, $start, $end, $coverage, $r);\n	my (%\
ID,%DE,%HSP);\n	\n	$ldb=\"\";\n\n	%ID=&xml2tag_lis\
t ($hit{$a}{body}, \"Hit_id\");\n	$identifyer=$ID{\
0}{body};\n	\n	%DE=&xml2tag_list ($hit{$a}{body}, \
\"Hit_def\");\n	$definition=$DE{0}{body};\n	\n	%HS\
P=&xml2tag_list ($hit{$a}{body}, \"Hsp\");\n	for (\
$b=0; $b<$HSP{n}; $b++)\n	  {\n	    my (%START,%EN\
D,%E,%I,%Q,%M);\n\n	 \n	    %START=&xml2tag_list (\
$HSP{$b}{body}, \"Hsp_query-from\");\n	    %HSTART\
=&xml2tag_list ($HSP{$b}{body}, \"Hsp_hit-from\");\
\n	    \n	    %LEN=  &xml2tag_list ($HSP{$b}{body}\
, \"Hsp_align-len\");\n	    %END=  &xml2tag_list (\
$HSP{$b}{body}, \"Hsp_query-to\");\n	    %HEND=  &\
xml2tag_list ($HSP{$b}{body}, \"Hsp_hit-to\");\n	 \
   %E=&xml2tag_list     ($HSP{$b}{body}, \"Hsp_eva\
lue\");\n	    %I=&xml2tag_list     ($HSP{$b}{body}\
, \"Hsp_identity\");\n	    %Q=&xml2tag_list     ($\
HSP{$b}{body}, \"Hsp_qseq\");\n	    %M=&xml2tag_li\
st     ($HSP{$b}{body}, \"Hsp_hseq\");\n	    \n	  \
  for ($e=0; $e<$Q{n}; $e++)\n\n	      {\n		$qs=$Q\
{$e}{body};\n		$ms=$M{$e}{body};\n		if ($seq eq\"\\
"){$seq=$qs;$L=length($seq);}\n		\n		$expectation=\
$E{$e}{body};\n		$identity=($LEN{$e}{body}==0)?0:$\
I{$e}{body}/$LEN{$e}{body}*100;\n		$start=$START{$\
e}{body};\n		$end=$END{$e}{body};\n		$Hstart=$HSTA\
RT{$e}{body};\n		$Hend=$HEND{$e}{body};\n	\n		$cov\
erage=(($end-$start)*100)/$L;\n\n	\n		if ($identit\
y>$maxid || $identity<$minid || $coverage<$mincov)\
{next;}\n		@lr1=(split (//,$qs));\n		@lr2=(split (\
//,$ms));\n		$l=$#lr1+1;\n		for ($c=0;$c<$L;$c++){\
$p[$nhits][$c]=\"-\";}\n		for ($d=0,$c=0; $c<$l; $\
c++)\n		  {\n		    $r=$lr1[$c];\n		    if ( $r=~/[\
A-Za-z]/)\n		      {\n			\n			$p[$nhits][$d + $sta\
rt-1]=$lr2[$c];\n			$d++;\n		      }\n		  }\n		$Qs\
eq[$nhits]=$qs;\n		$Hseq[$nhits]=$ms;\n		$QstartL[\
$nhits]=$start;\n		$HstartL[$nhits]=$Hstart;\n		$i\
dentityL[$nhits]=$identity;\n		$endL[$nhits]=$end;\
\n		$definitionL[$nhits]=$definition;\n		$identify\
erL[$nhits]=$identifyer;\n		$comment[$nhits]=\"$ld\
b|$identifyer [Eval=$expectation][id=$identity%][s\
tart=$Hstart end=$Hend]\";\n		$nhits++;\n	      }\\
n	  }\n      }\n    \n    $profile{n}=0;\n    $pro\
file{$profile{n}}{name}=$name;\n    $profile{$prof\
ile{n}}{seq}=$seq;\n    $profile {n}++;\n    \n   \
 for ($a=0; $a<$nhits; $a++)\n      {\n	$n=$a+1;\n\
	\n	$profile{$n}{name}=\"$name\\_$a\";\n	$profile{\
$n}{seq}=\"\";\n	$profile{$n}{Qseq}=$Qseq[$a];\n	$\
profile{$n}{Hseq}=$Hseq[$a];\n	$profile{$n}{Qstart\
}=$QstartL[$a];\n	$profile{$n}{Hstart}=$HstartL[$a\
];\n	$profile{$n}{identity}=$identityL[$a];\n	$pro\
file{$n}{definition}=$definitionL[$a];\n	$profile{\
$n}{identifyer}=$identifyerL[$a];\n	$profile{$n}{c\
omment}=$comment[$a];\n	for ($b=0; $b<$L; $b++)\n	\
  {\n	    if ($p[$a][$b])\n	      {\n		$profile{$n\
}{seq}.=$p[$a][$b];\n	      }\n	    else\n	      {\
\n		$profile{$n}{seq}.=\"-\";\n	      }\n	  }\n   \
   }\n    \n    $profile{n}=$nhits+1;\n    return \
%profile;\n  }\nsub ebi_blast_xml2profile \n  {\n \
   my ($name,$seq,$maxid, $minid, $mincov, $string\
)=(@_);\n    my ($L,$l, $a,$b,$c,$d,$nhits,@identi\
fyerL,$identifyer);\n    \n\n    \n    $seq=~s/[^a\
-zA-Z]//g;\n    $L=length ($seq);\n    %hit=&xml2t\
ag_list ($string, \"hit\");\n    \n    for ($nhits\
=0,$a=0; $a<$hit{n}; $a++)\n      {\n	my ($ldb,$id\
, $identity, $expectation, $start, $end, $coverage\
, $r);\n	my (%Q,%M,%E,%I);\n	\n	$ldb=&tag2value ($\
hit{$a}{open}, \"database\");\n	$identifyer=&tag2v\
alue ($hit{$a}{open}, \"id\");\n\n	$description=&t\
ag2value ($hit{$a}{open}, \"description\");\n	\n	%\
Q=&xml2tag_list ($hit{$a}{body}, \"querySeq\");\n	\
%M=&xml2tag_list ($hit{$a}{body}, \"matchSeq\");\n\
	%E=&xml2tag_list ($hit{$a}{body}, \"expectation\"\
);\n	%I=&xml2tag_list ($hit{$a}{body}, \"identity\\
");\n	\n\n	for ($b=0; $b<$Q{n}; $b++)\n	  {\n	    \
\n	    \n	    $qs=$Q{$b}{body};\n	    $ms=$M{$b}{b\
ody};\n	    if ($seq eq\"\"){$seq=$qs;$L=length($s\
eq);}\n\n	    $expectation=$E{$b}{body};\n	    $id\
entity=$I{$b}{body};\n	    \n	    	    \n	    $sta\
rt=&tag2value ($Q{$b}{open}, \"start\");\n	    $en\
d=&tag2value ($Q{$b}{open}, \"end\");\n	    $start\
M=&tag2value ($M{$b}{open}, \"start\");\n	    $end\
M=&tag2value ($M{$b}{open}, \"end\");\n	    $cover\
age=(($end-$start)*100)/$L;\n	    \n	   # print \"\
$id: ID: $identity COV: $coverage [$start $end]\\n\
\";\n	    \n	    \n	    if ($identity>$maxid || $i\
dentity<$minid || $coverage<$mincov){next;}\n	    \
# print \"KEEP\\n\";\n\n	    \n	    @lr1=(split (/\
/,$qs));\n	    @lr2=(split (//,$ms));\n	    $l=$#l\
r1+1;\n	    for ($c=0;$c<$L;$c++){$p[$nhits][$c]=\\
"-\";}\n	    for ($d=0,$c=0; $c<$l; $c++)\n	      \
{\n		$r=$lr1[$c];\n		if ( $r=~/[A-Za-z]/)\n		  {\n\
		    \n		    $p[$nhits][$d + $start-1]=$lr2[$c];\\
n		    $d++;\n		  }\n	      }\n	  \n	    \n	    $i\
dentifyerL[$nhits]=$identifyer;\n	    $comment[$nh\
its]=\"$ldb|$identifyer [Eval=$expectation][id=$id\
entity%][start=$startM end=$endM]\";\n	    $nhits+\
+;\n	  }\n      }\n    \n    $profile{n}=0;\n    $\
profile{$profile{n}}{name}=$name;\n    $profile{$p\
rofile{n}}{seq}=$seq;\n    $profile {n}++;\n    \n\
    for ($a=0; $a<$nhits; $a++)\n      {\n	$n=$a+1\
;\n	$profile{$n}{name}=\"$name\\_$a\";\n	$profile{\
$n}{seq}=\"\";\n	$profile{$n}{identifyer}=$identif\
yerL[$a];\n	\n	$profile{$n}{comment}=$comment[$a];\
\n	for ($b=0; $b<$L; $b++)\n	  {\n	    if ($p[$a][\
$b])\n	      {\n		$profile{$n}{seq}.=$p[$a][$b];\n\
	      }\n	    else\n	      {\n		$profile{$n}{seq}\
.=\"-\";\n	      }\n	  }\n      }\n    $profile{n}\
=$nhits+1;\n    \n    return %profile;\n  }\n\nsub\
 blast_xml2hit_list\n  {\n    my $string=(@_[0]);\\
n    return &xml2tag_list ($string, \"hit\");\n  }\
\nsub xml2tag_list  \n  {\n    my ($string_in,$tag\
)=@_;\n    my $tag_in, $tag_out;\n    my %tag;\n  \
  \n    if (-e $string_in)\n      {\n	$string=&fil\
e2string ($string_in);\n      }\n    else\n      {\
\n	$string=$string_in;\n      }\n    $tag_in1=\"<$\
tag \";\n    $tag_in2=\"<$tag>\";\n    $tag_out=\"\
/$tag>\";\n    $string=~s/>/>##1/g;\n    $string=~\
s/</##2</g;\n    $string=~s/##1/<#/g;\n    $string\
=~s/##2/#>/g;\n    @l=($string=~/(\\<[^>]+\\>)/g);\
\n    $tag{n}=0;\n    $in=0;$n=-1;\n  \n \n\n    f\
oreach $t (@l)\n      {\n\n	$t=~s/<#//;\n	$t=~s/#>\
//;\n	\n	if ( $t=~/$tag_in1/ || $t=~/$tag_in2/)\n	\
  {\n	 \n	    $in=1;\n	    $tag{$tag{n}}{open}=$t;\
\n	    $n++;\n	    \n	  }\n	elsif ($t=~/$tag_out/)\
\n	  {\n	    \n\n	    $tag{$tag{n}}{close}=$t;\n	 \
   $tag{n}++;\n	    $in=0;\n	  }\n	elsif ($in)\n	 \
 {\n	   \n	    $tag{$tag{n}}{body}.=$t;\n	  }\n   \
   }\n  \n    return %tag;\n  }\n\n\n\n\n","use En\
v qw(HOST);\nuse Env qw(HOME);\nuse Env qw(USER);\\
nwhile (<>)\n  {\n    if ( /^>(\\S+)/)\n      {\n	\
if ($list{$1})\n	  {\n	    print \">$1_$list{$1}\\\
n\";\n	    $list{$1}++;\n	  }\n	else\n	  {\n	    p\
rint $_;\n	    $list{$1}=1;\n	  }\n      }\n    el\
se\n      {\n	print $_;\n      }\n  }\n      \n","\
\n\n\nuse Env qw(HOST);\nuse Env qw(HOME);\nuse En\
v qw(USER);\n\n\nopen (F,$ARGV[0]);\nwhile ( <>)\n\
  {\n    @x=/([^:,;\\)\\(\\s]+):[^:,;\\)\\(]*/g;\n\
    @list=(@list,@x);\n  }\n$n=$#list+1;\nforeach \
$n(@list){print \">$n\\nsequence\\n\";}\n\n\nclose\
 (F);\n","\nopen (F, $ARGV[0]);\n\nwhile ( <F>)\n \
 {\n    @l=($_=~/(\\S+)/g);\n    \n    $name=shift\
 @l;\n    \n    print STDOUT \"\\n>$name\\n\";\n  \
  foreach $e (@l){$e=($e eq \"0\")?\"O\":\"I\";pri\
nt \"$e\";}\n  }\nclose (F);\n\n		       \n    \n"\
,"use strict;\nuse FileHandle;\nuse Env qw(HOST);\\
nuse Env qw(HOME);\nuse Env qw(USER);\nmy %name;\n\
my $nseq;\nmy $F= new FileHandle;\nopen ($F, $ARGV\
[0]);\nwhile(<$F>)\n  {\n    \n    my $l=$_;\n    \
if ($l=~/^#/){;}\n    elsif (($l=~/\\d+\\s+\\d+\\s\
+(\\S+)\\s+(\\S+)/))\n      {\n	my $name=$1;\n	my \
$seq=$2;\n	print \">$name\\n$seq\\n\";\n      }\n \
 }\nclose ($F);\nexit (0);\n\n\n","use Env qw(HOST\
);\nuse Env qw(HOME);\nuse Env qw(USER);\n\n$tmp=\\
"$ARGV[0].$$\";\nopen (IN, $ARGV[0]);\nopen (OUT, \
\">$tmp\");\n\nwhile ( <IN>)\n  {\n    $file=$_;\n\
    $file=~s/\\r\\n/\\n/g;\n    $file=~s/\\n\\r/\\\
n/g;\n    $file=~s/\\r\\r/\\n/g;\n    $file=~s/\\r\
/\\n/g;\n    print OUT \"$file\";\n  }\nclose (IN)\
;\nclose (OUT);\n\nopen (OUT, \">$ARGV[0]\");\nope\
n (IN, \"$tmp\");\n\nwhile ( <IN>)\n{\n  print OUT\
 \"$_\";\n}\nclose (IN);\nclose (OUT);\nunlink ($t\
mp);\n\n"};
