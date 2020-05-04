#ifndef __VERSION_H__
#define __VERSION_H__

struct version {
	char date[16];
	char time[16];
	char name[16];
	char cmpny[40];
	char project[16];
	char rel_ver[16];
	int valid;
};

#define BUILD_VERSION(author, proj, last_release) static struct version VERSION __attribute__((__used__, __section__(".version_data"))) = { __DATE__, __TIME__, author, "MY_COMPANY", proj, last_release, 1}

#endif
