import requests
from login import *

s = requests.Session()

def getCaptcha(text):
    i = text.find("value=")
    return text[i+7:i+17]

# Login webhacking.kr
s.post("https://webhacking.kr/login.php?login", data={"id":webhacking_id, "pw":webhacking_pw})
r1 = s.get("https://webhacking.kr/challenge/code-4/")
c = getCaptcha(r1.text)
r2 = s.post("https://webhacking.kr/challenge/code-4/", data={"id":'w', "cmt":'w', "captcha":c})
s.close()
print(r2.text)