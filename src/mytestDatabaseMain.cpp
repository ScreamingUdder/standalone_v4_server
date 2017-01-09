#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include <pv/serverContext.h>

#include <epicsExport.h>

#include <pv/channelProviderLocal.h>
#include <mytestDatabase.h>

using namespace std;
using std::tr1::static_pointer_cast;
using namespace epics::pvData;
using namespace epics::pvAccess;
using namespace epics::pvDatabase;
using namespace epics::myTest;

int main(int argc,char *argv[])
{
    PVDatabasePtr master = PVDatabase::getMaster();
    ChannelProviderLocalPtr channelProvider = getChannelProviderLocal();
    
    MyTestDatabase::create();   // This is the only line that is not boiler plate
    
    ServerContext::shared_pointer ctx =
        startPVAServer(PVACCESS_ALL_PROVIDERS,0,true,true);
    PVStringArrayPtr pvNames = master->getRecordNames();
    cout << "recordNames" << endl << *pvNames << endl;
    string str;
    while(true) {
        cout << "Type exit to stop: \n";
        getline(cin,str);
        if(str.compare("exit")==0) break;

    }
    ctx->destroy();
    epicsThreadSleep(1.0);
    channelProvider->destroy();
    return 0; 
}