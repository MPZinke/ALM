

typedef int Word;


class Memory
{
	public:
		Memory();

		Word operator[](int index);

	private:
		Word _words[256];
};
