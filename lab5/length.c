int length(char *s) {
	char *t = s;
	while(*t) ++t;
	return t-s;
}
