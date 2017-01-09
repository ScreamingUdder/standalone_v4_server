#include <cstddef>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <cstdio>
#include <memory>

#include <cantProceed.h>
#include <epicsStdio.h>
#include <epicsMutex.h>
#include <epicsEvent.h>
#include <epicsThread.h>
#include <iocsh.h>

#include <pv/pvIntrospect.h>
#include <pv/pvData.h>
#include <pv/pvAccess.h>
#include <pv/pvDatabase.h>
#include <mytestDatabase.h>

#include <epicsExport.h>

using namespace epics::pvData;
using namespace epics::pvAccess;
using namespace epics::pvDatabase;
using namespace epics::myTest;

static const iocshArg testArg0 = { "prefix", iocshArgString };
static const iocshArg *testArgs[] = {
    &testArg0};

static const iocshFuncDef mytestDatabaseFuncDef = {
    "mytestDatabase", 1, testArgs};
static void mytestDatabaseCallFunc(const iocshArgBuf *args)
{
    MyTestDatabase::create();
}

static void mytestDatabaseRegister(void)
{
    static int firstTime = 1;
    if (firstTime) {
        firstTime = 0;
        iocshRegister(&mytestDatabaseFuncDef, mytestDatabaseCallFunc);
    }
}

extern "C" {
    epicsExportRegistrar(mytestDatabaseRegister);
}