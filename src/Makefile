TOP=..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

INC += mytestDatabase.h

LIBRARY += mytestDatabase
mytestDatabase_SRCS += mytestDatabaseRegister.cpp
mytestDatabase_SRCS += mytestDatabase.cpp
mytestDatabase_LIBS += pvDatabase
mytestDatabase_LIBS += pvAccess
mytestDatabase_LIBS += pvData
mytestDatabase_LIBS += Com
mytestDatabase_LIBS += $(EPICS_BASE_IOC_LIBS)

PROD_HOST += mytestDatabaseMain
mytestDatabaseMain_SRCS += mytestDatabaseMain.cpp
mytestDatabaseMain_LIBS += mytestDatabase
mytestDatabaseMain_LIBS += pvDatabase
mytestDatabaseMain_LIBS += pvAccess
mytestDatabaseMain_LIBS += pvData
mytestDatabaseMain_LIBS += Com

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE