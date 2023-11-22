#include "Logfile.h"

#include <fstream>


Logfile::Logfile(const std::string& filename)
    : filename_(filename) {
    std::ofstream ofs(filename_, std::ios_base::out | std::ios_base::trunc );
    ofs.close();
}


void const Logfile::write(const std::string& msg) {
    std::ofstream ofs(filename_, std::ios_base::out | std::ios_base::app );
    ofs << msg << std::endl;
    ofs.close();
}
