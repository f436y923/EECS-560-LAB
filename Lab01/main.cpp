#include "executive.h"

int main(int argc, char const *argv[])
{
    std::string filename = argv[1];
    executive exec(filename);
    return 0;
}
