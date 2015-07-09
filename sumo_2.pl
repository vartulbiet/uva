#!/usr/local/bin/perl
my $mydir = $ARGV[0];
opendir(DIR, $mydir) or die $!;
use Time::Local;
my $var = timelocal(0, 0, 0, 1, 0, 14);

while(my $file = readdir(DIR)) {
    if(-f $file) {
        open(DATA, "<$file");
        my $modtime = (stat(DATA))[9];
        my $size = (stat(DATA))[7];
        if($modtime > $var || $size > 5248000) {
            print "Delete Candidate: This file is either not modified since 1 Jan 2014 or is greater than 5MB: $file\n";           
        }
         
    }
}       