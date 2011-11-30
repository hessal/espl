int length(char *s) {
	char *t = s;
	while(*t) ++t;
	size=t-s;
	return t-s;
}
