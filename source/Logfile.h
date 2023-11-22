#ifndef LOGFILE_H__
#define LOGFILE_H__

#include <string>

class Logfile {
    public:
        Logfile(const std::string& filename);
        void const write(const std::string& msg);

    private:
        std::string filename_;
};



#endif
