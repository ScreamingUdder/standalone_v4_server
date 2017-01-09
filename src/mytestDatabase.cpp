#include <cstddef>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <cstdio>
#include <memory>
#include <vector>
#include <iostream>

#include <pv/standardField.h>
#include <pv/standardPVField.h>

#define epicsExportSharedSymbols

#include <pv/channelProviderLocal.h>
#include <pv/traceRecord.h>

#include <mytestDatabase.h>

using namespace std;
using std::tr1::static_pointer_cast;
using namespace epics::pvData;
using namespace epics::pvAccess;
using namespace epics::pvDatabase;
using namespace epics::myTest;

static void createRecord(
    PVDatabasePtr const &master,
    ScalarType scalarType,
    string const &recordNamePrefix,
    string const &properties)
{
    StandardPVFieldPtr standardPVField = getStandardPVField();
    string recordName = recordNamePrefix;
    PVStructurePtr pvStructure = standardPVField->scalar(scalarType,properties);
    PVRecordPtr pvRecord = PVRecord::create(recordName,pvStructure);
    bool result = master->addRecord(pvRecord);
    if(!result) cout<< "record " << recordName << " not added" << endl;
    recordName += "Array";
    pvStructure = standardPVField->scalarArray(scalarType,properties);
    pvRecord = PVRecord::create(recordName,pvStructure);
    result = master->addRecord(pvRecord);
}

void MyTestDatabase::create()
{
    std::cout << "Create called" << std::endl;
    
    PVDatabasePtr master = PVDatabase::getMaster();

    string properties;
    properties = "alarm,timeStamp";
    
    createRecord(master, pvDouble, "mytestDouble", properties);
}
