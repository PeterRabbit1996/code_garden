#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define INET_ADDRSTRLEN		16

/*
struct hostent {
	char  *h_name;
	char **h_aliases;
	int    h_addrtype;
	int    h_length;
	char **h_addr_list;
}
*/


int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: ./exec_file <ip addr>");
		exit(1);
	}

	char *ptr, **pptr;
	char str[INET_ADDRSTRLEN];
	struct hostent *hptr;
	struct sockaddr_in addr;

	inet_pton(AF_INET, argv[1], &addr);
	if ((hptr = gethostbyaddr(argv[1], sizeof(argv[1]), AF_INET)) == NULL) {
		printf("gethostbyaddr error.\n");
		exit(1);
	}

	if (hptr->h_name != NULL)
		printf("official hostname: %s\n", hptr->h_name);

	for (pptr = hptr->h_aliases; *pptr != NULL; pptr++)
		printf("\talias: %s\n", *pptr);

	if (hptr->h_addrtype == NULL) {
		printf("hptr->h_addrtype NULL.\n");
		exit(1);
	}

	switch (hptr->h_addrtype) {
	case AF_INET:
		pptr = hptr->h_addr_list;
		for ( ; *pptr != NULL; pptr++) {
			char *str = inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str));
			printf("\taddress: %s\n", str);
		}
			break;

	default:
		printf("unknown address type");
		exit(1);
			break;
	}

	return 0;
}
