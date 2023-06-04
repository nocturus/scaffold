#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string>
#include <fstream>

namespace file {
    bool create_folder(std::string f){
        if(!mkdir(f.c_str(), 0777)){
            return false;
        } else {
            return true;
        }
    }

    bool exists (const std::string& name) {
        return ( access( name.c_str(), F_OK ) != -1 );
    }

    bool create_file(std::string f){
        if (exists(f)){
            return false;
        } else {
            std::ofstream { f };
            return true;
        }
    }

    void add_text_to_file(std::string t, std::string a){
        std::ofstream o;
        o.open(t, std::ios_base::app);
        o << a;
    }

    void setup_git(std::string f){
        std::string c = "git init " + f;
        system(c.c_str());
    }
}
