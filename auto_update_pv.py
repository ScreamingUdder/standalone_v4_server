import calendar
import time
from subprocess import call
import datetime

while True:
    now = datetime.datetime.now()
    call(["pvput", "mytestDouble", "%d" % now.second])
    time.sleep(5)