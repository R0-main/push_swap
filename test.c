# include <unistd.h>

int main(int argc, char const *argv[])
{
	write(1, "pb\n", 3);
	write(1, "pb\n", 3);
	write(1, "pb\n", 3);
	return 0;
}
