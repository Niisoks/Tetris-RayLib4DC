#include <kos.h>
#include <stdint.h>
#include <sys/cdefs.h>
#include <stdint.h>
#include <dc/syscalls.h>
#include <sys/types.h>

class cd{
private:
public:
    cd();
    ~cd();
    void checkStatus();
    int * status = 0;
    int * discType = 0;
};

cd::cd(){
    cdrom_get_status(status, discType);
}

cd::~cd()
{
}

void cd::checkStatus(){
    syscall_system_bios_menu();
    if(*status == (
        CD_STATUS_OPEN|
        CD_STATUS_OPEN   |
        CD_STATUS_NO_DISC|
        CD_STATUS_RETRY  |
        CD_STATUS_ERROR  |
        CD_STATUS_FATAL 
    )) 
    {}
}
