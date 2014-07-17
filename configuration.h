

#ifndef BUFSIZ
#define BUFSIZ				(1<<16)
#endif

// don't do to much rules, it will degrade performance
#define MAXRULES			(1<<8)

// there's no need in more than 256 arguments while running action-script, IMHO :)
#define MAXARGUMENTS			(1<<8)

// clsync should be used, if there's more than 5-10 nodes. So the limit in 255 is quite enough. :)
#define MAXNODES			((1<<8)-1)

#define MAXSIGNALNUM			(1<<9)

// max user/group lengths
#define USER_LEN			(1<<8)
#define GROUP_LEN			USER_LEN

// control socket listen backlog (man 2 listen)
#define SOCKET_BACKLOG			2

// control socket connections limit in clsync
#define SOCKET_MAX_CLSYNC		8

// control socket connections limit in libclsync
#define SOCKET_MAX_LIBCLSYNC		(1<<16)

// children count limit
#define MAXCHILDREN			(1<<8)

#define MAXMOUNTPOINTS			(1<<8)
#define MAXPERMITTEDHOOKFILES		(1<<8)

#ifdef __CLSYNC_COMMON_H
#	if INOTIFY_SUPPORT
#		define DEFAULT_NOTIFYENGINE	NE_INOTIFY
#	elif KQUEUE_SUPPORT
#		define DEFAULT_NOTIFYENGINE	NE_KQUEUE
#		warning There is no inotify support, defaulting to kqueue (that is not well tested)
#	else
#		error No inotify/kqueue support, cannot compile working clsync
#	endif
#endif
#define DEFAULT_RULES_PERM		RA_ALL
#define DEFAULT_COLLECTDELAY		30
#define DEFAULT_SYNCDELAY		(DEFAULT_COLLECTDELAY)
#define DEFAULT_BFILETHRESHOLD		(128 * 1024 * 1024)
#define DEFAULT_BFILECOLLECTDELAY	1800
#define DEFAULT_LABEL			"nolabel"
#define DEFAULT_RSYNCINCLUDELINESLIMIT	20000
#define DEFAULT_SYNCTIMEOUT		(3600 * 24)
#define DEFAULT_CLUSTERTIMEOUT		1000
#define DEFAULT_CLUSTERIPADDR		"227.108.115.121"
#define DEFAULT_CLUSTERIPPORT		40079
#define DEFAULT_CLUSTERHDLMIN		1
#define DEFAULT_CLUSTERHDLMAX		16
#define DEFAULT_CLUSTERSDLMAX		32
#define DEFAULT_CONFIG_BLOCK		"default"
#define DEFAULT_RETRIES			1
#define DEFAULT_VERBOSE			3
#define DEFAULT_DUMPDIR			"/tmp/clsync-dump-%label%"

#define FANOTIFY_FLAGS			(FAN_CLOEXEC|FAN_UNLIMITED_QUEUE|FAN_UNLIMITED_MARKS)
#define FANOTIFY_EVFLAGS		(O_LARGEFILE|O_RDONLY|O_CLOEXEC)

#define FANOTIFY_MARKMASK		(FAN_OPEN|FAN_MODIFY|FAN_CLOSE|FAN_ONDIR|FAN_EVENT_ON_CHILD)

#define INOTIFY_FLAGS			0
					//(FD_CLOEXEC)

#define INOTIFY_MARKMASK		(IN_ATTRIB|IN_CLOSE_WRITE|IN_CREATE|IN_DELETE|IN_DELETE_SELF|IN_MOVE_SELF|IN_MOVED_FROM|IN_MOVED_TO|IN_MODIFY|IN_DONT_FOLLOW)

#define COUNTER_LIMIT			(1<<10)

#define SLEEP_SECONDS			1

#define KILL_TIMEOUT			60

#define ALLOC_PORTION			(1<<10) /* 1  KiX */
#define CLUSTER_WINDOW_BUFSIZE_PORTION	(1<<20) /* 1  MiB */
#define CLUSTER_PACKET_MAXSIZE		(1<<24) /* 16 MiB */

#define CONFIG_PATHS 			{ ".clsync.conf", "/etc/clsync/clsync.conf", NULL } /* "~/.clsync.conf" and "/etc/clsync/clsync.conf" */

#define API_PREFIX			"clsyncapi_"

#define DUMP_DIRMODE			0750
#define DUMP_FILEMODE			0644

#define DEFAULT_CP_PATH			"cp"
#define	DEFAULT_RSYNC_PATH		"rsync"

// size of event chain size to be processes at a time
#define KQUEUE_EVENTLISTSIZE		256

#define AUDITPIPE_PATH "/dev/auditpipe"
#define AUDIT_CONTROL_PATH "/etc/security/audit_control"
#define AUDIT_CONTROL_INITSCRIPT "/etc/rc.d/auditd"
#define AUDIT_CONTROL_HEADER "#clsync\n"
#define AUDIT_CONTROL_CONTENT "\n\
dir:/var/audit\n\
flags:fc,fd,fw,fm,cl\n\
minfree:0\n\
naflags:fc,fd,fw,fm,cl\n\
policy:cnt\n\
filesz:1M\n\
"

#define DTRACE_PATH			"dtrace"

#define PIVOT_AUTO_DIR			"/dev/shm/clsync-rootfs"
#define	TMPDIR_TEMPLATE			"/tmp/clsync-XXXXXX"

#define SYSLOG_BUFSIZ			(1<<16)
#define SYSLOG_FLAGS			(LOG_PID|LOG_CONS)
#define SYSLOG_FACILITY			LOG_DAEMON

#define CLSYNCSOCK_WINDOW		(1<<8)

#define DEFAULT_SYNCHANDLER_ARGS_SIMPLE		"sync \%label\% \%EVENT-MASK\% \%INCLUDE-LIST\%"
#define DEFAULT_SYNCHANDLER_ARGS_DIRECT		"\%INCLUDE-LIST\% \%destination-dir\%/"
#define DEFAULT_SYNCHANDLER_ARGS_SHELL_NR	"synclist \%label\% \%INCLUDE-LIST-PATH\%"
#define DEFAULT_SYNCHANDLER_ARGS_SHELL_R	"initialsync \%label\% \%INCLUDE-LIST\%"
#define DEFAULT_SYNCHANDLER_ARGS_RDIRECT_E	"-aH --delete --exclude-from \%EXCLUDE-LIST-PATH\% --include-from \%INCLUDE-LIST-PATH\% --exclude=* \%watch-dir\%/ \%destination-dir\%/"
#define DEFAULT_SYNCHANDLER_ARGS_RDIRECT_I	"-aH --delete --include-from \%INCLUDE-LIST-PATH\% --exclude=* \%watch-dir\%/ \%destination-dir\%/"
#define DEFAULT_SYNCHANDLER_ARGS_RSHELL_E	"rsynclist \%label% \%INCLUDE-LIST-PATH\% %EXCLUDE-LIST-PATH%"
#define DEFAULT_SYNCHANDLER_ARGS_RSHELL_I	"rsynclist \%label% \%INCLUDE-LIST-PATH\%"

#define RSYNC_ARGS_E	{ 		\
		"-aH", 			\
		"--delete", 		\
		"--exclude-from",	\
		"\%EXCLUDE-LIST-PATH\%",\
		"--include-from",	\
		"\%INCLUDE-LIST-PATH\%",\
		"--exclude=*",		\
		NULL }

#define RSYNC_ARGS_I	{ 		\
		"-aH", 			\
		"--delete", 		\
		"--include-from",	\
		"\%INCLUDE-LIST-PATH\%",\
		"--exclude=*",		\
		NULL }

#define DEFAULT_PRESERVE_CAPABILITIES	( CAP_TO_MASK(CAP_DAC_READ_SEARCH) | CAP_TO_MASK(CAP_SETUID) | CAP_TO_MASK(CAP_SETGID) | CAP_TO_MASK(CAP_KILL) )

#define DEFAULT_USER			"nobody"
#define DEFAULT_GROUP			"nogroup"
#define DEFAULT_UID			65534
#define DEFAULT_GID			65534
#define DEFAULT_CAPS_INHERIT		CI_EMPTY
#define DEFAULT_PIVOT_MODE		(PW_OFF)

#define HL_LOCK_TRYES			(1<<13)

//#define READWRITE_SIGNALLING

