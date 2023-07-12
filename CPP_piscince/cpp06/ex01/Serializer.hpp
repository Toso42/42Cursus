#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "includes.hpp"
# include "classes.hpp"
# include <stdint.h>

typedef struct s_Data Data;

class Serializer {
private:
public:
	Serializer();
	Serializer(const Serializer& instance);
	Serializer &operator=(const Serializer& instance);
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

std::ostream &operator<<(std::ostream &output, const Serializer &instance);

#endif