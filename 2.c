#include<stdio.h>
#include<unistd.h>

int main(){
	while(1){
		printf("still running\n");
		sleep(7);
	}
	return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ gcc -o 2 2.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ ./2 &
[1] 4759
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ still running
still running
still running
still running
*/

/*
joelthomas@joelthomas-82EY:~$ cd /proc
joelthomas@joelthomas-82EY:/proc$ cd /4759
bash: cd: /4759: No such file or directory
joelthomas@joelthomas-82EY:/proc$ cd /proc/4759
joelthomas@joelthomas-82EY:/proc/4759$ cat cmdline
./2joelthomas@joelthomas-82EY:/proc/4759$ cat status
Name:	2
Umask:	0002
State:	S (sleeping)
Tgid:	4759
Ngid:	0
Pid:	4759
PPid:	4644
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 118 1000 
NStgid:	4759
NSpid:	4759
NSpgid:	4759
NSsid:	4644
VmPeak:	    2616 kB
VmSize:	    2616 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	    1152 kB
VmRSS:	    1152 kB
RssAnon:	       0 kB
RssFile:	    1152 kB
RssShmem:	       0 kB
VmData:	     224 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1672 kB
VmPTE:	      44 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	1
SigQ:	0/28819
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ffff
Cpus_allowed_list:	0-15
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	26
nonvoluntary_ctxt_switches:	0
joelthomas@joelthomas-82EY:/proc/4759$ cat stat
4759 (2) S 4644 4759 4644 34816 4644 4194304 113 0 0 0 0 0 0 0 20 0 1 0 1297714 2678784 288 18446744073709551615 94173716307968 94173716308381 140727397895856 0 0 0 0 0 0 1 0 0 17 13 0 0 0 0 0 94173716319664 94173716320272 94173735854080 140727397896900 140727397896904 140727397896904 140727397900276 0
joelthomas@joelthomas-82EY:/proc/4759$ cat statm
654 288 288 1 0 89 0
joelthomas@joelthomas-82EY:/proc/4759$ ls -l fd
total 0
lrwx------ 1 joelthomas joelthomas 64 Aug 29 19:09 0 -> /dev/pts/0
lrwx------ 1 joelthomas joelthomas 64 Aug 29 19:09 1 -> /dev/pts/0
lrwx------ 1 joelthomas joelthomas 64 Aug 29 19:09 2 -> /dev/pts/0
joelthomas@joelthomas-82EY:/proc/4759$ cat environ
SHELL=/bin/bashSESSION_MANAGER=local/joelthomas-82EY:@/tmp/.ICE-unix/1918,unix/joelthomas-82EY:/tmp/.ICE-unix/1918QT_ACCESSIBILITY=1COLORTERM=truecolorXDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdgSSH_AGENT_LAUNCHER=opensshXDG_MENU_PREFIX=gnome-GNOME_DESKTOP_SESSION_ID=this-is-deprecatedGNOME_SHELL_SESSION_MODE=ubuntuSSH_AUTH_SOCK=/run/user/1000/keyring/sshXMODIFIERS=@im=ibusDESKTOP_SESSION=ubuntuGTK_MODULES=gail:atk-bridgeDBUS_STARTER_BUS_TYPE=sessionPWD=/home/joelthomas/Desktop/IIITB/SS/handsonlist1solutionsLOGNAME=joelthomasXDG_SESSION_DESKTOP=ubuntuXDG_SESSION_TYPE=x11GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1SYSTEMD_EXEC_PID=1918XAUTHORITY=/run/user/1000/gdm/XauthorityWINDOWPATH=2HOME=/home/joelthomasUSERNAME=joelthomasLANG=en_US.UTF-8LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=00:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.avif=01;35:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:*~=00;90:*#=00;90:*.bak=00;90:*.old=00;90:*.orig=00;90:*.part=00;90:*.rej=00;90:*.swp=00;90:*.tmp=00;90:*.dpkg-dist=00;90:*.dpkg-old=00;90:*.ucf-dist=00;90:*.ucf-new=00;90:*.ucf-old=00;90:*.rpmnew=00;90:*.rpmorig=00;90:*.rpmsave=00;90:XDG_CURRENT_DESKTOP=ubuntu:GNOMEVTE_VERSION=7200GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/069f17ac_4b4f_4363_88d8_afca39cd19f9LESSCLOSE=/usr/bin/lesspipe %s %sXDG_SESSION_CLASS=userTERM=xterm-256colorLESSOPEN=| /usr/bin/lesspipe %sUSER=joelthomasGNOME_TERMINAL_SERVICE=:1.122DISPLAY=:1SHLVL=0QT_IM_MODULE=ibusDBUS_STARTER_ADDRESS=unix:path=/run/user/1000/bus,guid=2cc6a0cb84597561d6c1e88866d04739XDG_RUNTIME_DIR=/run/user/1000DEBUGINFOD_URLS=https://debuginfod.ubuntu.com XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/usr/local/share/:/usr/share/:/var/lib/snapd/desktopPATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/binGDMSESSION=ubuntuDBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus,guid=2cc6a0cb84597561d6c1e88866d04739_=./2joelthomas@joelthomas-82EY:/proc/4759$ cat limits
Limit                     Soft Limit           Hard Limit           Units     
Max cpu time              unlimited            unlimited            seconds   
Max file size             unlimited            unlimited            bytes     
Max data size             unlimited            unlimited            bytes     
Max stack size            8388608              unlimited            bytes     
Max core file size        0                    unlimited            bytes     
Max resident set          unlimited            unlimited            bytes     
Max processes             28819                28819                processes 
Max open files            1024                 1048576              files     
Max locked memory         955109376            955109376            bytes     
Max address space         unlimited            unlimited            bytes     
Max file locks            unlimited            unlimited            locks     
Max pending signals       28819                28819                signals   
Max msgqueue size         819200               819200               bytes     
Max nice priority         0                    0                    
Max realtime priority     0                    0                    
Max realtime timeout      unlimited            unlimited            us        
joelthomas@joelthomas-82EY:/proc/4759$ 
*/
