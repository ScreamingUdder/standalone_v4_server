#ifndef MYTESTDATABASE_H
#define MYTESTDATABASE_H

#ifdef epicsExportSharedSymbols
#   define mytestDatabaseEpicsExportSharedSymbols
#   undef epicsExportSharedSymbols
#endif

#include <pv/pvDatabase.h>

#ifdef MYTESTDATABASEEpicsExportSharedSymbols
#   define epicsExportSharedSymbols
#	undef mytestDatabaseEpicsExportSharedSymbols
#endif

#include <shareLib.h>

namespace epics { namespace myTest { 

class epicsShareClass  MyTestDatabase{
public:
    static void create();
};


}}

#endif  /* MYTESTDATABASE_H */