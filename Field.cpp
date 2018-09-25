#include "Field.h"
#include <sstream>

Field::Field() {
    this->length = 0;
}

Field::Field(int length) {
    this->length = length;
}

std::string Field::render() {
    std::stringstream field;

    for (int i = 0; i < this->length; i++) {
        field << "_";
    }

    field << std::endl;
    return field.str();
}